/*
	파일 이름 : boundary.h
    내용 : boundary에 대한 헤더 파일입니다.
*/
// 헤더 선언은 여기에 위치합니다.
#pragma once
#include "main.h"

class MemberInterface{
public:
    vector<string> createMemberInputUI(){
        char userType[MAX_STRING], name[MAX_STRING], SSN[MAX_STRING], ID[MAX_STRING], password[MAX_STRING];
        fscanf(in_fp, "%s %s %s %s", name, SSN, ID, password);

        vector<string> returnValue;
        returnValue.push_back(string(name));
        returnValue.push_back(SSN);
        returnValue.push_back(ID);
        returnValue.push_back(password);

        fprintf(out_fp, "1.1. 회원가입\n");

        return returnValue;
    }

    void createMemberOutputUI(string name, string SSN, string ID, string password){
        fprintf(out_fp, "%s %s %s %s\n", name.c_str(), SSN.c_str(), ID.c_str(), password.c_str());
    }

    void deleteMemberInputUI(){
        fprintf(out_fp, "1.2. 회원탈퇴");
    }

    void deleteMemberOutputUI(string ID){
        fprintf(out_fp, "%s\n", ID.c_str());
    }
};
extern MemberInterface memberInterface;

class LogInterface{
public:
    vector<string> loginMemberInputUI(){
        char ID[MAX_STRING], password[MAX_STRING];
        fscanf(in_fp, "%s %s", ID, password);

        vector<string> returnValue;
        returnValue.push_back(ID);
        returnValue.push_back(password);

        fprintf(out_fp, "2.1. 로그인\n");

        return returnValue;
    }

    void loginMemberOutputUI(string ID, string password){
        fprintf(out_fp, "%s %s\n", ID.c_str(), password.c_str());
    }

    void logoutMemberInputUI(){
        fprintf(out_fp, "2.2. 로그아웃\n");
    }

    void logoutMemberOutputUI(string ID){
        fprintf(out_fp, "%s\n", ID.c_str());
    }
};
extern LogInterface logInterface;

class CompanyMemberInterface{
public:
    vector<string> createRecruitInputUI(){
        char recruitTask[MAX_STRING], recruitNum[MAX_STRING], recruitDeadline[MAX_STRING];
        fscanf(in_fp, "%s %s %s", recruitTask, recruitNum, recruitDeadline);

        vector<string> returnValue;
        returnValue.push_back(recruitTask);
        returnValue.push_back(recruitNum);
        returnValue.push_back(recruitDeadline);

        fprintf(out_fp, "3.1. 채용 정보 등록\n");

        return returnValue;
    }

    void createRecruitOutputUI(string recruitTask, string recruitNum, string recruitDeadline){
        fprintf(out_fp, "%s %s %s\n", recruitTask.c_str(), recruitNum.c_str(), recruitDeadline.c_str());
    }

    void searchRecruitListCompanyInputUI(){
        fprintf(out_fp, "3.2. 등록된 채용 정보 조회\n");
    }

    void searchRecruitListCompanyOutputUI(vector<string> searchRecruitList){
        for(int i = 0; i < searchRecruitList.size(); i++){
            fprintf(out_fp, "%s ", searchRecruitList[i].c_str());
        }
        fprintf(out_fp, "\n");
    }
};
extern CompanyMemberInterface companyMemberInterface;

class ClientMemberInterface {
    string searchRecruitListClientInputUI(){
        char companyName[MAX_STRING];
        fscanf(in_fp, "%s", companyName);

        fprintf(out_fp, "4.1. 채용 정보 검색\n");

        return companyName;
    }

    void searchRecruitListClientOutputUI(vector<string> searchRecruitList){
        for(int i = 0; i < searchRecruitList.size(); i++){
            fprintf(out_fp, "%s ", searchRecruitList[i].c_str());
        }
        fprintf(out_fp, "\n");
    }

    string createApplyInputUI(){
        char companyID[MAX_STRING];
        fscanf(in_fp, "%s", companyID);

        fprintf(out_fp, "4.2. 채용 지원\n");

        return companyID;
    }

    void createApplyOutputUI(vector<string> apply){
        for(int i = 0; i < apply.size(); i++){
            fprintf(out_fp, "%s ", apply[i].c_str());
        }
        fprintf(out_fp, "\n");
    }

    void getClientMemberApplyListInputUI(){
        fprintf(out_fp, "4.3. 지원 정보 조회\n");

    }

    void getClientMemberApplyListOutputUI(vector<string> apply){
        for(int i = 0; i < apply.size(); i++){
            fprintf(out_fp, "%s ", apply[i].c_str());
        }
        fprintf(out_fp, "\n");
    }

    string deleteApplyInputUI(){
        char companyID[MAX_STRING];
        fscanf(in_fp, "%s", companyID);

        fprintf(out_fp, "4.4. 지원 취소\n");

        return companyID;
    }

    void deleteApplyOutputUI(vector<string> apply){
        for(int i = 0; i < apply.size(); i++){
            fprintf(out_fp, "%s ", apply[i].c_str());
        }
        fprintf(out_fp, "\n");
    }
};
extern ClientMemberInterface clientMemberInterface;

class StatisticInterface{
    void statisticInputUI(){
        fprintf(out_fp, "5.1. 지원 정보 통계\n");
    }

    void statisticOutputUI(vector<string> statistic){
        for(int i = 0; i < statistic.size(); i++){
            fprintf(out_fp, "%s ", statistic[i].c_str());
        }
        fprintf(out_fp, "\n");
    }
};
extern StatisticInterface statisticInterface;

class QuitProgramUI{
    void quitProgramUI(){
        fprintf(out_fp, "6.1. 종료\n");
    }
};
extern QuitProgramUI quitProgramUI;