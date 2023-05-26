/*
	파일 이름 : entity.h
    내용 : entity에 대한 헤더 파일입니다.
*/
// 헤더 선언은 여기에 위치합니다.
#include <stdio.h>
#include <string>
#include <iostream>
#include <vector>

typedef struct {
    string recruitTask;
    int num = 0;
} myApply;

using namespace std;

class Member {
private:
    string memberId;        // member 아이디입니다.
    string memberPassword;  // member 비밀번호입니다.
public:
    Member(string memberId, string memberPassword) {
        this->memberId = memberId;
        this->memberPassword = memberPassword;
    };

    string getMemberId() {
        return memberId;
    };

    string getMemberPassword() {
        return memberPassword;
    };
};

class CompanyMember : public Member {
private:
    string companyMemberName;        // companyMember 사업자명입니다.
    string companyMemberId;  // companyMember 사업자번호입니다.
public:
    CompanyMember(string companyMemberName, string companyMemberId, string memberId, string memberPassword) : Member(memberId, memberPassword){
        this->companyMemberName = companyMemberName;
        this->companyMemberId = companyMemberId;
    };

    string getCompanyMemberName() {
        return companyMemberName;
    };

    string getCompanyMemberId(){
        return companyMemberId;
    };
};

class ClientMember : public Member {
private:
    string clientMemberName;  // clientMember 이름입니다.
    string clientMemberId;        // clientMember 주민번호입니다.
public:
    ClientMember(string clientMemberName, string clientMemberId, string memberId, string memberPassword) : Member(memberId, memberPassword) {
        this->clientMemberName = clientMemberName;
        this->clientMemberId = clientMemberId;
    }
    string getClientMemberName(){
        return clientMemberName;
    };

    string getClientMemberId(){
        return clientMemberId;
    };
};

class MemberEntity {
public:
    virtual string deleteMember(string memberId) { return ""; };
    virtual bool loginMember(string MemberId, string MemberPassword) { return 0; };
    virtual bool logoutMember(string memberId) { return 0; };
    virtual vector<string> findMemberInfo(string memberId) { vector<string> str;  return str; };
};

class ClientMemberEntity : public MemberEntity {
private:
    vector<ClientMember> clientMemberList;
public:
    void createClientMember(string clientMemberName, string clientMemberId, string memberId, string memberPassword){
        clientMemberList.push_back(ClientMember(clientMemberName, clientMemberId, memberId, memberPassword));
    };

    string deleteMember(string memberId){
        for(int i = 0; i < clientMemberList.size(); i++){
            if(memberId == clientMemberList[i].getMemberId()){
                clientMemberList.erase(clientMemberList.begin() + i);
                break;
            }
        }
        return memberId;
    }

    bool loginMember(string MemberId, string MemberPassword){
        for(int i = 0; i < clientMemberList.size(); i++){
            if(MemberId == clientMemberList[i].getMemberId() and MemberPassword == clientMemberList[i].getMemberPassword()){
                return true;
            }
        }
        return false;
    };

    bool logoutMember(string memberId){
        for(int i = 0; i < clientMemberList.size(); i++){
            if(memberId == clientMemberList[i].getMemberId()){
                return true;
            }
        }
        return false;
    };

    vector<string> findMemberInfo(string memberId) {
        vector<string> returnValue;

        for(int i = 0; i < clientMemberList.size(); i++){
            if(memberId == clientMemberList[i].getMemberId()){
                returnValue.push_back(clientMemberList[i].getClientMemberName());
                returnValue.push_back(clientMemberList[i].getClientMemberId());

                break;
            }
        }

        return returnValue;
    };
};

class CompanyMemberEntity : public MemberEntity {
private:
    vector<CompanyMember> companyMemberList;
public:
    void createCompanyMember(string companyMemberName, string companyMemberId, string memberId, string memberPassword){
        companyMemberList.push_back(CompanyMember(companyMemberName, companyMemberId, memberId, memberPassword));
    };

    string deleteMember(string memberId){
        for(int i = 0; i < companyMemberList.size(); i++){
            if(memberId == companyMemberList[i].getMemberId()){
                companyMemberList.erase(companyMemberList.begin() + i);

                break;
            }
        }
        return memberId;
    };

    bool loginMember(string MemberId, string MemberPassword){
        for(int i = 0; i < companyMemberList.size(); i++){
            if(MemberId == companyMemberList[i].getMemberId() and MemberPassword == companyMemberList[i].getMemberPassword()){
                return true;
            }
        }
        return false;
    };

    bool logoutMember(string memberId){
        for(int i = 0; i < companyMemberList.size(); i++){
            if(memberId == companyMemberList[i].getMemberId()){
                return true;
            }
        }
        return false;
    };

    vector<string> findMemberInfo(string memberId) {
        vector<string> returnValue;

        for(int i = 0; i < companyMemberList.size(); i++){
            if(memberId == companyMemberList[i].getMemberId()){
                returnValue.push_back(companyMemberList[i].getCompanyMemberName());
                returnValue.push_back(companyMemberList[i].getCompanyMemberId());

                break;
            }
        }

        return returnValue;
    };
};

class Recruit {
private:
    string companyName;
    string companyId;
    string recruitTask;
    string recruitNum;
    string recruitDeadline;
public:
    Recruit(string companyName, string companyId, string recuritTask, string recuritNum, string recruitDeadline){
        this->companyName = companyName;
        this->companyId = companyId;
        this->recruitTask = recuritTask;
        this->recruitNum = recuritNum;
        this->recruitDeadline = recruitDeadline;
    };

    string getCompanyName(){
        return companyName;
    };

    string getCompanyId(){
        return companyId;
    };

    string getRecruitTask(){
        return recruitTask;
    };

    string getRecruitNum(){
        return recruitNum;
    };

    string getRecruitDeadline(){
        return recruitDeadline;
    };
};

class Apply {
private:
    string clientId;
    string companyId;
    string recruitTask;
public:
    Apply(string clientId, string companyId, string recruitTask){
        this->clientId = clientId;
        this->companyId = companyId;
        this->recruitTask = recruitTask;
    };

    string getClientId(){
        return clientId;
    }

    string getCompanyId(){
        return companyId;
    }

    string getRecruitTask(){
        return recruitTask;
    }
};

class RecruitApplyEntity {
private:
    vector<Recruit> recruitList;
    vector<Apply> applyList;
public:
    vector<Recruit>& getRecruitList(){
        return recruitList;
    };

    vector<Apply>& getApplyList(){
        return applyList;
    };

    vector<string> createRecruit(string companyName, string companyId, string recruitTask, string recruitNum, string recruitDeadline) {
        vector<string> returnValue;

        recruitList.push_back(Recruit(companyName, companyId, recruitTask, recruitNum, recruitDeadline));

        returnValue.push_back(recruitList.back().getRecruitTask());
        returnValue.push_back(recruitList.back().getRecruitDeadline());
        returnValue.push_back(recruitList.back().getRecruitNum());

        return returnValue;
    };

    vector<string> searchRecruitListCompany(string companyMemberId){
        vector<string> returnValue;

        for(int i = 0; i < recruitList.size(); i++){
            if(companyMemberId == recruitList[i].getCompanyId()){
                returnValue.push_back(recruitList[i].getRecruitTask());
                returnValue.push_back(recruitList[i].getRecruitNum());
                returnValue.push_back(recruitList[i].getRecruitDeadline());
                returnValue.push_back("\n");
            }
        }

        return returnValue;
    };

    vector<string> statisticCompanyMember(string companyMemberId){
        vector<string> returnValue;

        for(int i = 0; i < recruitList.size(); i++){
            if(companyMemberId == recruitList[i].getCompanyId()){
                string recruitTask = recruitList[i].getRecruitTask();
                int statisticValue = 0;

                for(int j = 0; j < applyList.size(); j++){
                    if(recruitTask == applyList[j].getRecruitTask()){
                        statisticValue += 1;
                    }
                }

                returnValue.push_back(recruitTask);
                returnValue.push_back(to_string(statisticValue));
                returnValue.push_back("\n");
            }
        }

        return returnValue;
    };

    vector<string> searchRecruitListClient(string companyName){
        vector<string> returnValue;

        for(int i = 0; i < recruitList.size(); i++){
            if(companyName == recruitList[i].getCompanyName()){
                returnValue.push_back(recruitList[i].getCompanyName());
                returnValue.push_back(recruitList[i].getCompanyId());
                returnValue.push_back(recruitList[i].getRecruitTask());
                returnValue.push_back(recruitList[i].getRecruitNum());
                returnValue.push_back(recruitList[i].getRecruitDeadline());
                returnValue.push_back("\n");
            }
        }

        return returnValue;
    };

    vector<string> createApply(string clientId, string companyId){
        vector<string> returnValue;

        for(int i = 0; i < recruitList.size(); i++){
            if(companyId == recruitList[i].getCompanyId()){
                applyList.push_back(Apply(clientId, recruitList[i].getCompanyId(), recruitList[i].getRecruitTask()));

                returnValue.push_back(recruitList[i].getCompanyName());
                returnValue.push_back(recruitList[i].getCompanyId());
                returnValue.push_back(recruitList[i].getRecruitTask());
                break;
            }
        }

        return returnValue;
    };

    vector<string> getClientMemberApplyList(string clientMemberId){
        vector<string> returnValue;

        for(int i = 0; i < applyList.size(); i++){
            if(clientMemberId == applyList[i].getClientId()){
                for(int j = 0; j < recruitList.size(); j++){
                    if(applyList[i].getCompanyId() == recruitList[j].getCompanyId()){
                        returnValue.push_back(recruitList[j].getCompanyName());
                        returnValue.push_back(recruitList[j].getCompanyId());
                        returnValue.push_back(recruitList[j].getRecruitTask());
                        returnValue.push_back(recruitList[j].getRecruitNum());
                        returnValue.push_back(recruitList[j].getRecruitDeadline());
                        returnValue.push_back("\n");
                    }
                }
            }
        }

        return returnValue;
    };

    vector<string> deleteApply(string clientId, string companyId){
        vector<string> returnValue;

        for(int i = 0; i < applyList.size(); i++){
            if(clientId == applyList[i].getClientId() and companyId == applyList[i].getCompanyId()){
                returnValue.push_back(recruitList[i].getCompanyName());
                returnValue.push_back(recruitList[i].getCompanyId());
                returnValue.push_back(recruitList[i].getRecruitTask());

                applyList.erase(applyList.begin() + i);

                break;
            }
        }

        return returnValue;
    };

    vector<string> statisticClientMember(string clientMemberId){
        vector<string> returnValue;

        vector<myApply> myApplyList;

        for(int i = 0; i < applyList.size(); i++){
            if(clientMemberId == applyList[i].getClientId()){
                int j = 0;

                for(; j < myApplyList.size(); j++){
                    if(myApplyList[j].recruitTask == applyList[i].getRecruitTask()){
                        myApplyList[j].num += 1;
                    }
                }

                if(j == myApplyList.size()){
                    myApply newApply;
                    newApply.recruitTask = applyList[i].getRecruitTask();
                    newApply.num = 0;

                    myApplyList.push_back(newApply);
                }
            }
        }

        for(int i = 0; i < myApplyList.size(); i++){
            returnValue.push_back(myApplyList[i].recruitTask);
            returnValue.push_back(to_string(myApplyList[i].num));
            returnValue.push_back("\n");
        }

        return returnValue;
    };
};