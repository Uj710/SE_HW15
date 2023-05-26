/*
	파일 이름 : boundary.h
    내용 : boundary에 대한 헤더 파일입니다.
*/
// 전역 상수 선언는 여기에 위치합니다.
#define MAX_STRING 32

// 전역 변수 선언은 여기에 위치합니다.
using namespace std;

class MemberInterface{
public:
    vector<string> createMemberInputUI(FILE* in_fp, FILE* out_fp){
        char type[MAX_STRING], name[MAX_STRING], SSN[MAX_STRING], ID[MAX_STRING], password[MAX_STRING];
        fscanf(in_fp, "%s %s %s %s %s", type, name, SSN, ID, password);
        //scanf("%s %s %s %s %s", type, name, SSN, ID, password);

        vector<string> returnValue;
        returnValue.push_back(type);
        returnValue.push_back(string(name));
        returnValue.push_back(SSN);
        returnValue.push_back(ID);
        returnValue.push_back(password);

        fprintf(out_fp, "1.1. 회원가입\n> ");
        //printf("1.1. 회원가입\n> ");


        return returnValue;
    }

    void createMemberOutputUI(FILE* in_fp, FILE* out_fp, string name, string SSN, string ID, string password){
        fprintf(out_fp, "%s %s %s %s\n", name.c_str(), SSN.c_str(), ID.c_str(), password.c_str());
        //printf("%s %s %s %s\n", name.c_str(), SSN.c_str(), ID.c_str(), password.c_str());

    }

    void deleteMemberInputUI(FILE* in_fp, FILE* out_fp){
        fprintf(out_fp, "1.2. 회원탈퇴\n> ");
        //printf("1.2. 회원탈퇴\n> ");
    }

    void deleteMemberOutputUI(FILE* in_fp, FILE* out_fp, string ID){
        fprintf(out_fp, "%s\n", ID.c_str());
        //printf("%s\n", ID.c_str());
    }
};

class LogInterface{
public:
    vector<string> loginMemberInputUI(FILE* in_fp, FILE* out_fp){
        char ID[MAX_STRING], password[MAX_STRING];
        fscanf(in_fp, "%s %s", ID, password);
        //scanf("%s %s", ID, password);

        vector<string> returnValue;
        returnValue.push_back(ID);
        returnValue.push_back(password);

        return returnValue;
    }

    void loginMemberOutputUI(FILE* in_fp, FILE* out_fp, string ID, string password){
        fprintf(out_fp, "2.1. 로그인\n> ");
        //printf("2.1. 로그인\n> ");

        fprintf(out_fp, "%s %s\n", ID.c_str(), password.c_str());
        //printf("%s %s\n", ID.c_str(), password.c_str());
    }

    void logoutMemberInputUI(FILE* in_fp, FILE* out_fp){
        fprintf(out_fp, "2.2. 로그아웃\n> ");
        //printf("2.2. 로그아웃\n> ");
    }

    void logoutMemberOutputUI(FILE* in_fp, FILE* out_fp, string ID){
        fprintf(out_fp, "%s\n", ID.c_str());
        //printf("%s\n", ID.c_str());
    }
};

class CompanyMemberInterface{
public:
    vector<string> createRecruitInputUI(FILE* in_fp, FILE* out_fp){
        char recruitTask[MAX_STRING], recruitNum[MAX_STRING], recruitDeadline[MAX_STRING];
        fscanf(in_fp, "%s %s %s", recruitTask, recruitNum, recruitDeadline);
        //scanf("%s %s %s", recruitTask, recruitNum, recruitDeadline);

        vector<string> returnValue;
        returnValue.push_back(recruitTask);
        returnValue.push_back(recruitNum);
        returnValue.push_back(recruitDeadline);

        fprintf(out_fp, "3.1. 채용 정보 등록\n> ");
        //printf("3.1. 채용 정보 등록\n> ");

        return returnValue;
    }

    void createRecruitOutputUI(FILE* in_fp, FILE* out_fp, string recruitTask, string recruitNum, string recruitDeadline){
        fprintf(out_fp, "%s %s %s\n", recruitTask.c_str(), recruitNum.c_str(), recruitDeadline.c_str());
        //printf("%s %s %s\n", recruitTask.c_str(), recruitNum.c_str(), recruitDeadline.c_str());
    }

    void searchRecruitListCompanyInputUI(FILE* in_fp, FILE* out_fp){
        fprintf(out_fp, "3.2. 등록된 채용 정보 조회\n> ");
        //printf("3.2. 등록된 채용 정보 조회\n> ");
    }

    void searchRecruitListCompanyOutputUI(FILE* in_fp, FILE* out_fp, vector<string> searchRecruitList){
        for(int i = 0; i < searchRecruitList.size(); i++){
            fprintf(out_fp, "%s ", searchRecruitList[i].c_str());
            //printf("%s ", searchRecruitList[i].c_str());
        }
        fprintf(out_fp, "\n");
        //printf("\n");
    }
};

class ClientMemberInterface {
public:
    string searchRecruitListClientInputUI(FILE* in_fp, FILE* out_fp){
        char companyName[MAX_STRING];
        fscanf(in_fp, "%s", companyName);
        //scanf("%s", companyName);

        fprintf(out_fp, "4.1. 채용 정보 검색\n>");
        //printf("4.1. 채용 정보 검색\n> ");

        return companyName;
    }

    void searchRecruitListClientOutputUI(FILE* in_fp, FILE* out_fp, vector<string> searchRecruitList){
        for(int i = 0; i < searchRecruitList.size(); i++){
            fprintf(out_fp, "%s ", searchRecruitList[i].c_str());
            //printf("%s ", searchRecruitList[i].c_str());
        }
        fprintf(out_fp, "\n");
        //printf("\n");
    }

    string createApplyInputUI(FILE* in_fp, FILE* out_fp){
        char companyID[MAX_STRING];
        fscanf(in_fp, "%s", companyID);
        //scanf("%s", companyID);

        fprintf(out_fp, "4.2. 채용 지원\n> ");
        //printf("4.2. 채용 지원\n> ");

        return companyID;
    }

    void createApplyOutputUI(FILE* in_fp, FILE* out_fp, vector<string> apply){
        for(int i = 0; i < apply.size(); i++){
            fprintf(out_fp, "%s ", apply[i].c_str());
            //printf("%s ", apply[i].c_str());
        }
        fprintf(out_fp, "\n");
        //printf("\n");
    }

    void getClientMemberApplyListInputUI(FILE* in_fp, FILE* out_fp){
        fprintf(out_fp, "4.3. 지원 정보 조회\n>");
        //printf("4.3. 지원 정보 조회\n> ");
    }

    void getClientMemberApplyListOutputUI(FILE* in_fp, FILE* out_fp, vector<string> apply){
        for(int i = 0; i < apply.size(); i++){
            fprintf(out_fp, "%s ", apply[i].c_str());
            //printf("%s ", apply[i].c_str());
        }
        fprintf(out_fp, "\n");
        //printf("\n");
    }

    string deleteApplyInputUI(FILE* in_fp, FILE* out_fp){
        char companyID[MAX_STRING];
        fscanf(in_fp, "%s", companyID);
        //scanf("%s", companyID);

        fprintf(out_fp, "4.4. 지원 취소\n> ");
        //printf("4.4. 지원 취소\n> ");

        return companyID;
    }

    void deleteApplyOutputUI(FILE* in_fp, FILE* out_fp, vector<string> apply){
        for(int i = 0; i < apply.size(); i++){
            fprintf(out_fp, "%s ", apply[i].c_str());
            //printf("%s ", apply[i].c_str());
        }
        fprintf(out_fp, "\n");
        //printf("\n");
    }
};

class StatisticInterface{
public:
    void statisticInputUI(FILE* in_fp, FILE* out_fp){
        fprintf(out_fp, "5.1. 지원 정보 통계\n> ");
        //printf("5.1. 지원 정보 통계\n> ");
    }

    void statisticOutputUI(FILE* in_fp, FILE* out_fp, vector<string> statistic){
        for(int i = 0; i < statistic.size(); i++){
            fprintf(out_fp, "%s ", statistic[i].c_str());
            //printf("%s ", statistic[i].c_str());
        }
        fprintf(out_fp, "\n");
        //printf("\n");
    }
};

class QuitProgramInterface{
public:
    void quitProgramUI(FILE* in_fp, FILE* out_fp){
        fprintf(out_fp, "6.1. 종료\n");
        //printf("6.1. 종료\n");
    }
};
