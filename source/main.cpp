// 헤더 선언
#include "header.h"

int main() {
    // 파일 입출력을 위한 초기화

    FILE* in_fp = fopen(INPUT_FILE_NAME, "r+");
    FILE* out_fp = fopen(OUTPUT_FILE_NAME, "w+");

    doTask();

    return 0;
}

/*
	함수 이름 : do_task
	기능 :
	전달 인자 : 없음
	반환값 : 없음
*/
void doTask() {
    // 메뉴 파싱을 위한 level 구분을 위한 변수
    int menu_level_1 = 0, menu_level_2 = 0;
    int is_program_exit = 0;

    while (!is_program_exit) {
        // 입력파일에서 메뉴 숫자 2개를 읽기
        fscanf(in_fp, "%d %d ", &menu_level_1, &menu_level_2);

        // 메뉴 구분 및 해당 연산 수행
        switch(menu_level_1){
            case 1: {
                switch(menu_level_2){
                    case 1: {
                        // 1.1 회원가입

                        break;
                    }
                    case 2: {
                        // 1.2 회원탈퇴

                        break;
                    }
                }
            }
            case 2: {
                switch(menu_level_2){
                    case 1: {
                        // 2.1 로그인

                        break;
                    }
                    case 2: {
                        // 2.2 로그아웃

                        break;
                    }
                }
            }
            case 3: {
                switch(menu_level_2){
                    case 1: {
                        // 3.1 채용 정보 등록

                        break;
                    }
                    case 2: {
                        // 3.2 등록된 채용 정보 조회

                        break;
                    }
                }
            }
            case 4: {
                switch(menu_level_2){
                    case 1: {
                        // 4.1 채용 정보 검색

                        break;
                    }
                    case 2: {
                        // 4.2 채용 지원

                        break;
                    }
                    case 3: {
                        // 4.3 지원 정보 조회

                        break;
                    }
                    case 4: {
                        // 4.2 지원 취소

                        break;
                    }
                }
            }
            case 5: {
                switch(menu_level_2){
                    case 1: {
                        // 5.1 지원 정보 통계

                        break;
                    }
                }
            }
            case 6: {
                switch(menu_level_2){
                    case 1: {
                        // 6.1 종료
                        program_exit();
                        is_program_exit = 1;

                        break;
                    }
                }
            }
        }
    }
}

/*
	함수 이름 : program_exit
	기능 :
	전달 인자 : 없음
	반환값 : 없음
*/
void program_exit() {
    // "종료합니다" 메세지 출력
}