#include <stdio.h>
#include <stdlib.h>

int main(void) {

	////Q1 명령행 전달인자 사용하지 않고 파일을 열어 
	////해당 파일 내 문자의 개수를 카운팅 하기
	//int ch;			//문자 변수
	//FILE* fp;	//파일 포인터
	//unsigned long count = 0;
	//char f_name[40];	//파일 이름을 저장하기 위한 배열
	//puts("파일 이름을 입력하세요");
	//scanf("%s", f_name);
	//if ((fp = fopen(f_name, "r")) == NULL) {
	//	puts("파일이 없습니다. 파일 이름이 잘 못 되었습니다.");
	//	exit(EXIT_FAILURE);
	//}
	//
	//while ((ch = getc(fp)) != EOF) {	//파일 끝에 도달 할때까지 문자를 읽음
	//	putc(ch, stdout);
	//	count++;
	//}
	//fclose(fp);
	//printf("%s의 파일에는 %ld개의 문자가 있습니다.\n종료\n", f_name, count);
	////기본적인 파일 입출력의 원리만 알면 쉬게 해결 할 수 있다.

	return 0;
}