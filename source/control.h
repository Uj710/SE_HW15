/*
	파일 이름 : control.h
    내용 : control에 대한 파일입니다.
*/
// 헤더 선언은 여기에 위치합니다.
#pragma once

#include <iostream>
#include <cstring>
#include <vector>
#include <utility>
#include "boundary.h"
#include "entity.h"

CompanyMemberEntity companyMemberEntity;
ClientMemberEntity clientMemberEntity;
RecruitApplyEntity recruitApplyEntity;
string memberId = "";
string memberType = "0";

using namespace std;

class Control{
private:


public:
    void setMemberId(string id){
        memberId = std::move(id);
    };

    void setMemberType(string type){
        memberType = std::move(type);
    };

    string getMemberId(){
        return memberId;
    };

    string getMemberType(){
        return memberType;
    };
};

class CreateMember : public Control{
public:
    void createMember(FILE* in_fp, FILE* out_fp){
        if(getMemberType() == "0"){
            vector<string> inputValue = MemberInterface().createMemberInputUI(in_fp, out_fp);
            string name, SSN, ID, password;

            if(inputValue[0] == "1"){
                companyMemberEntity.createCompanyMember(inputValue[1], inputValue[2], inputValue[3], inputValue[4]);
            }
            else if(inputValue[0] == "2"){
                clientMemberEntity.createClientMember(inputValue[1], inputValue[2], inputValue[3], inputValue[4]);
            }

            MemberInterface().createMemberOutputUI(in_fp, out_fp, inputValue[1], inputValue[2], inputValue[3], inputValue[4]);

        }
    };
};

class DeleteMember : public Control{
public:
    void deleteMember(FILE* in_fp, FILE* out_fp){
        if(getMemberType() == "1" or getMemberType() == "2"){
            MemberInterface().deleteMemberInputUI(in_fp, out_fp);

            if(getMemberType() == "1"){
                companyMemberEntity.deleteMember(getMemberId());
                MemberInterface().deleteMemberOutputUI(in_fp, out_fp, getMemberId());
            }
            else if (getMemberType() == "2"){
                companyMemberEntity.deleteMember(getMemberId());
                MemberInterface().deleteMemberOutputUI(in_fp, out_fp, getMemberId());
            }

            setMemberId("");
            setMemberType("0");
        }
    };
};

class LoginMember : public Control{
public:
    void loginMember(FILE* in_fp, FILE* out_fp){
        if(getMemberType() == "0"){
            vector<string> inputValue = LogInterface().loginMemberInputUI(in_fp, out_fp);
            if(companyMemberEntity.loginMember(inputValue[0], inputValue[1])){
                setMemberId(inputValue[0]);
                setMemberType("1");
                LogInterface().loginMemberOutputUI(in_fp, out_fp, inputValue[0], inputValue[1]);
            } else if(clientMemberEntity.loginMember(inputValue[0], inputValue[1])){
                setMemberId(inputValue[0]);
                setMemberType("2");
                LogInterface().loginMemberOutputUI(in_fp, out_fp, inputValue[0], inputValue[1]);
            }
        }
    };
};

class LogoutMember : public Control{
public:
    void logoutMember(FILE* in_fp, FILE* out_fp){
        if(getMemberType() == "1" or getMemberType() == "2"){
            LogInterface().logoutMemberInputUI(in_fp, out_fp);

            if(companyMemberEntity.logoutMember(getMemberId()) == true or clientMemberEntity.logoutMember(getMemberId()) == true){
                LogInterface().logoutMemberOutputUI(in_fp, out_fp, getMemberId());
                setMemberType("0");
                setMemberId("");
            }
        }
    };
};

class CreateRecruit : public Control{
public:
    void createRecruit(FILE* in_fp, FILE* out_fp){
        if(getMemberType() == "1"){
            vector<string> inputValue = CompanyMemberInterface().createRecruitInputUI(in_fp, out_fp);
            vector<string> myInfo = companyMemberEntity.findMemberInfo(getMemberId());

            recruitApplyEntity.createRecruit(myInfo[0], myInfo[1], inputValue[0], inputValue[1], inputValue[2]);

            CompanyMemberInterface().createRecruitOutputUI(in_fp, out_fp, inputValue[0], inputValue[1], inputValue[2]);
        }
    };
};

class SearchRecruitListCompany : public Control{
public:
    void searchRecruitListCompany(FILE* in_fp, FILE* out_fp){
        if(getMemberType() == "1"){
            CompanyMemberInterface().searchRecruitListCompanyInputUI(in_fp, out_fp);
            vector<string> myInfo = companyMemberEntity.findMemberInfo(getMemberId());

            vector<string> recruitList = recruitApplyEntity.searchRecruitListCompany(myInfo[1]);

            CompanyMemberInterface().searchRecruitListCompanyOutputUI(in_fp, out_fp, recruitList);
        }
    };
};

class SearchRecruitListClient : public Control{
public:
    void searchRecruitListClient(FILE* in_fp, FILE* out_fp){
        if(getMemberType() == "2"){
            string inputValue = ClientMemberInterface().searchRecruitListClientInputUI(in_fp, out_fp);

            vector<string> recruitList = recruitApplyEntity.searchRecruitListClient(inputValue);

            ClientMemberInterface().searchRecruitListClientOutputUI(in_fp, out_fp, recruitList);
        }
    };
};

class CreateApply : public Control{
public:
    void createApply(FILE* in_fp, FILE* out_fp){
        if(getMemberType() == "2"){
            string inputValue = ClientMemberInterface().createApplyInputUI(in_fp, out_fp);
            vector<string> myInfo = clientMemberEntity.findMemberInfo(getMemberId());

            vector<string> apply = recruitApplyEntity.createApply(myInfo[1], inputValue);

            ClientMemberInterface().createApplyOutputUI(in_fp, out_fp, apply);
        }
    };
};

class GetClientMemberApplyList : public Control{
public:
    void getClientMemberApplyList(FILE* in_fp, FILE* out_fp){
        if(getMemberType() == "2"){
            ClientMemberInterface().getClientMemberApplyListInputUI(in_fp, out_fp);
            vector<string> myInfo = clientMemberEntity.findMemberInfo(getMemberId());

            vector<string> apply = recruitApplyEntity.getClientMemberApplyList(myInfo[1]);

            ClientMemberInterface().getClientMemberApplyListOutputUI(in_fp, out_fp, apply);
        }
    };
};

class DeleteApply : public Control{
public:
    void deleteApply(FILE* in_fp, FILE* out_fp){

        if(getMemberType() == "2"){
            string inputValue = ClientMemberInterface().deleteApplyInputUI(in_fp, out_fp);
            vector<string> myInfo = clientMemberEntity.findMemberInfo(getMemberId());

            vector<string> apply = recruitApplyEntity.deleteApply(myInfo[1], inputValue);

            ClientMemberInterface().deleteApplyOutputUI(in_fp, out_fp, apply);
        }
    };
};

class Statistic : public Control{
public:
    void statistic(FILE* in_fp, FILE* out_fp){
        if(getMemberType() == "1" or getMemberType() == "2"){
            StatisticInterface().statisticInputUI(in_fp, out_fp);
            vector<string> statistic;

            if(getMemberType() == "1"){
                vector<string> myInfo = companyMemberEntity.findMemberInfo(getMemberId());

                statistic = recruitApplyEntity.statisticCompanyMember(myInfo[1]);

            }
            else if(getMemberType() == "2"){
                vector<string> myInfo = clientMemberEntity.findMemberInfo(getMemberId());

                statistic = recruitApplyEntity.statisticClientMember(myInfo[1]);
            }

            StatisticInterface().statisticOutputUI(in_fp, out_fp, statistic);
        }
    };
};

class QuitProgram : public Control{
public:
    void quitProgram(FILE* in_fp, FILE* out_fp){
        QuitProgramInterface().quitProgramUI(in_fp, out_fp);
    };
};
