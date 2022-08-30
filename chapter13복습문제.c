#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char *argv[]) {

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

	////Q2. 소스파일, 타깃파일 명령행으로 받아 파일 복사 프로그램 작성
	////argv[1]이 소스, argv[2]가 타겟파일로
	////바이너리 모드로..
	//char ch;
	//FILE* fsrc, * ftrg;	//source파일, target파일
	//if (2 >= argc) { //명령행이 없다면...
	//	puts("명령행 전달 인자가 없거나 부족합니다.");
	//	exit(EXIT_FAILURE);
	//}
	//if ((fsrc = fopen(argv[1], "rb")) == NULL) {
	//	puts("source 파일이 없습니다.");
	//	exit(EXIT_FAILURE);
	//}
	//if ((ftrg = fopen(argv[2], "wb")) == NULL) {	//필요 없을듯..
	//	puts("target 파일이 없습니다.");
	//	exit(EXIT_FAILURE);
	//}
	//while (!feof(fsrc)) {		//eof에 도달했는지 확인하는 함수
	//	//ch = getc(fsrc);
	//	ch = fgetc(fsrc);
	//	fputc(ch, ftrg);
	//}
	////fread(&ch, sizeof(char), 1, fsrc);	//1byte 단위로 읽어
	////fwrite(&ch, sizeof(char), 1, ftrg);	//1byte 단위로 썼다
	//fclose(fsrc);
	//fclose(ftrg);

	////Q3. 소스파일을 받아서 타겟파일에 넣을 때 모두 대문자로 넣어라
	//char ch;
	//char src[40];
	//char trg[40];
	//FILE* fsrc, * ftrg;
	//puts("source file을 입력하세요");
	//printf(">>");
	//scanf("%s", src);
	//while (getchar() != '\n')
	//	continue;
	//puts("target file을 입력하세요");
	//printf(">>");
	//scanf("%s", trg);
	//while (getchar() != '\n')
	//	continue;
	////scanf("%s %s",src,trg)의 형식으로 쓸수도 있다
	//if ((fsrc = fopen(src, "r")) == NULL) {
	//	puts("source 파일이 없습니다.");
	//	exit(EXIT_FAILURE);
	//}
	//if ((ftrg = fopen(trg, "w")) == NULL) {
	//	puts("source 파일이 없습니다.");
	//	exit(EXIT_FAILURE);
	//}
	//while (!feof(fsrc)) {
	//	ch = fgetc(fsrc);
	//	//toupper(ch);
	//	fputc(toupper(ch), ftrg);
	//}
	//fclose(fsrc);
	//fclose(ftrg);

	//Q4.명령행 제시하는 모든 파일을 차례대로 화면에 출력

	return 0;
}