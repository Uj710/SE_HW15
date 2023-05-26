// 헤더 선언은 여기에 위치합니다.
#define _CRT_SECURE_NO_WARNINGS

#include "control.h"
#include <cstdio>
#pragma once

// 전역 함수 선언은 여기에 위치합니다.
void doTask(FILE* in_fp, FILE* out_fp);

FILE* in_fp;
FILE* out_fp;

/*
	함수 이름 : main
	기능 : main 함수입니다.
	전달 인자 : 없음
	반환값 : 0
*/
int main() {
    // 파일 입출력을 위한 FILE 변수 선언 및 초기화를 합니다.
    FILE* in_fp = fopen("../input.txt", "r+");
    FILE* out_fp = fopen("../output.txt", "w+");

    // doTask 함수를 실행합니다.
    doTask(in_fp, out_fp);

    return 0;
}

void doTask(FILE* in_fp, FILE* out_fp){
    // 메뉴 파싱을 위한 level 구분을 위한 변수를 선언 및 초기화합니다.
    int menu_level_1 = 0, menu_level_2 = 0;
    int is_program_exit = 0;

    while (!is_program_exit) {
        // 입력 파일에서 메뉴 숫자 2개를 읽습니다.
        fscanf(in_fp, "%d %d ", &menu_level_1, &menu_level_2);
        //scanf("%d %d ", &menu_level_1, &menu_level_2);

        // 메뉴를 구분하고, 그에 해당되는 연산을 수행합니다.
        switch (menu_level_1) {
            case 1: {
                switch (menu_level_2) {
                    case 1: {
                        // 1.1 회원가입
                        CreateMember().createMember(in_fp, out_fp);
                        break;
                    }
                    case 2: {
                        // 1.2 회원탈퇴
                        DeleteMember().deleteMember(in_fp, out_fp);
                        break;
                    }
                }
                break;
            }
            case 2: {
                switch (menu_level_2) {
                    case 1: {
                        // 2.1 로그인
                        LoginMember().loginMember(in_fp, out_fp);
                        break;
                    }
                    case 2: {
                        // 2.2 로그아웃
                        LogoutMember().logoutMember(in_fp, out_fp);
                        break;
                    }
                }
                break;

            }
            case 3: {
                switch (menu_level_2) {
                    case 1: {
                        // 3.1 채용 정보 등록
                        CreateRecruit().createRecruit(in_fp, out_fp);
                        break;
                    }
                    case 2: {
                        // 3.2 등록된 채용 정보 조회
                        SearchRecruitListCompany().searchRecruitListCompany(in_fp, out_fp);
                        break;
                    }
                }
                break;

            }
            case 4: {
                switch (menu_level_2) {
                    case 1: {
                        // 4.1 채용 정보 검색
                        SearchRecruitListClient().searchRecruitListClient(in_fp, out_fp);
                        break;
                    }
                    case 2: {
                        // 4.2 채용 지원
                        CreateApply().createApply(in_fp, out_fp);
                        break;
                    }
                    case 3: {
                        // 4.3 지원 정보 조회
                        GetClientMemberApplyList().getClientMemberApplyList(in_fp, out_fp);
                        break;
                    }
                    case 4: {
                        // 4.2 지원 취소
                        DeleteApply().deleteApply(in_fp, out_fp);
                        break;
                    }
                }
                break;

            }
            case 5: {
                switch (menu_level_2) {
                    case 1: {
                        // 5.1 지원 정보 통계
                        Statistic().statistic(in_fp, out_fp);
                        break;
                    }
                }
                break;

            }
            case 6:
            default: {
                switch (menu_level_2) {
                    case 1: {
                        // 6.1 종료
                        QuitProgram().quitProgram(in_fp, out_fp);
                        is_program_exit = 1;
                        break;
                    }
                }
                break;
            }
        }
    }
    // 프로그램 종료를 위한 변수가 1이 되기 전까지 반복문을 돌립니다.
}