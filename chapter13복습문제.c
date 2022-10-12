#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define BUFSIZE 4096
#define SLEN 81
#define LEN 15

char* s_gets(char* st, int n);
void append(FILE* source, FILE* dest);

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

	////Q4.명령행 제시하는 모든 파일을 차례대로 화면에 출력
	//if (1 == argc) {	//명령행 전달인자가 전혀 없다면...
	//	puts("명령행 전달인자 항목이 비어 있습니다.");
	//	return 0;
	//}
	//else {
	//	FILE* fp;
	//	char fName[40];	//파일이름 저장
	//	int ch;
	//	for (int i = 1; i < argc; i++) {
	//		strcpy(fName, argv[i]);	//파일 이름을 복사 한다.
	//		if ((fp = fopen(fName, "r")) == NULL) {	//없다면 없다고 알려준다.
	//			printf("%s 파일은 없습니다.\n", argv[i]);
	//		}
	//		else {
	//			while (!(feof(fp))) {
	//				ch = fgetc(fp);
	//				putc(ch, stdout);
	//			}
	//			fclose(fp);	//파일 스트림을 닫는다.
	//		}
	//		putc('\n', stdout);
	//	}
	//}
	//puts("종료");

	////Q5. 13.5의 프로그램 수정/ 명령행 입력 방식
	//FILE* fa, * fs;
	//char file_src[SLEN];
	//char file_app[SLEN];	//필요 없음
	//int ch;
	//int files = 0;
	////명령행 인자 2개 입력 안했을 대처리
	//if (argc == 1 || argc == 2) {
	//	puts("명령행 인자를 제대로 입력하지 않았습니다.");
	//	exit(EXIT_FAILURE);
	//}   
	//else {
	//	puts("목적 파일의 이름이 입력되었습니다.");
	//	printf("file name : %s\n", argv[1]);	//명령행 입력으로 처리
	//	//목적파일 없을 때
	//	if ((fa = fopen(argv[1], "a+")) == NULL) {
	//		fprintf(stderr, "파일을 열수 없습니다.%s\n", argv[1]);
	//		exit(EXIT_FAILURE);
	//	}	
	//	//사용자 버퍼를 지정함
	//	if (setvbuf(fa, NULL, _IOFBF, BUFSIZE) != 0) {
	//		fputs("출력 버퍼를 생성할 수 없습니다.\n", stderr);
	//		exit(EXIT_FAILURE);
	//	}	
	//	//루프를 이용해 소스 파일을 가져 온다.
	//	for (int i = 2; i < argc; i++) {
	//		printf("%d번째 소스 파일 %s를 불러 옵니다.\n", i - 1, argv[i]);
	//		if (strcmp(argv[1], argv[i]) == 0) {
	//			fputs("자기 자신에게는 덧붙일 수 없습니다.\n", stderr);
	//		}
	//		else if ((fs = fopen(argv[i], "r")) == NULL) {
	//			fprintf(stderr, "파일 %s를 열수 없습니다.\n", argv[i]);
	//		}
	//		else {
	//			if (setvbuf(fs, NULL, _IOFBF, BUFSIZE) != 0) {
	//				fputs("입력 버퍼를 생성할 수 없습니다.\n", stderr);
	//				continue;
	//			}
	//			append(fs, fa);
	//			if (ferror(fs) != 0)
	//				fprintf(stderr, "파일을 읽는 데 에러가 발생하였습니다.%s.\n", argv[i]);
	//			if (ferror(fa) != 0)
	//				fprintf(stderr, "파일을 쓰는 데 에러가 발생하였습니다.%s.\n", argv[1]);
	//			fclose(fs);
	//			files++;
	//			printf("%s 파일의 내용을 덧 붙였습니다.\n", argv[i]);
	//			puts("다음 소스 파일의 이름을 입력합니다.");
	//		}
	//	}
	//	printf("종료. %d개의 파일을 덧붙였습니다.\n", files);
	//	rewind(fa);
	//	printf("%s 내용:\n", argv[1]);
	//	while ((ch = getc(fa)) != EOF) {
	//		putchar(ch);
	//	}
	//	puts("종료 나타내기.");
	//	fclose(fa);

	//q6 13.2 코드를 대화형식으로 만들기
	//q6 우선 원본 코드를 이해하기 위해 직접 써보자
	//파일을 2/3으로 압축한다??!!
	FILE* in, * out;
	int ch;
	char inname[LEN];
	char outname[LEN];
	int count = 0;
	//명령행 전달인자를 검사한다.
	puts("간단한 파일 압축 프로그램입니다.");
	puts("압축 할 파일명을 입력하세요");
	printf("File name>> ");
	fgets(inname, 14, stdin);
	for (int i = 0; i < LEN; i++) {
		if (inname[i] == '\n') {
			inname[i] = '\0';
			break;
		}
	}
	if ((in = fopen(inname, "r")) == NULL) {
		fprintf(stderr, "%s 파일을 읽어 올 수 없습니다.\n", inname);
		exit(EXIT_FAILURE);
	}
	strncpy(outname, inname, LEN - 5);	//확장자까지 파일명으로 하겠다는 것인가>
	//printf("%s", outname);
	outname[LEN - 5] = '\0';
	strcat(outname, ".red");	//확장자를 붙인다.
	if ((out = fopen(outname, "w")) == NULL) {	//파일 쓰기
		fprintf(stderr, "%s 파일을 생성할 수 없습니다.\n", outname);
		exit(EXIT_FAILURE);
	}
	while ((ch = fgetc(in)) != EOF) {
		if ((count++ % 3) == 0) {
			putc(ch, out);
		}
	}
	if (fclose(in) != 0 || fclose(out) != 0) {
		fprintf(stderr, "파일을 닫는데 문제가 생겼다\n");
		exit(EXIT_FAILURE);
	}
	//후기 : 오랜만에 해서 좀 시간이 걸렸지만, 그래도 문제 해결을 했음
	return 0;
}


char* s_gets(char* st, int n) {
	char* ret_val;
	char* find;

	ret_val = fgets(st, n, stdin);
	if (ret_val) {
		find = strchr(st, '\n');
		if (find)
			*find = '\0';
		else
			while (getchar() != '\n')
				continue;
	}
	return ret_val;
}
void append(FILE* source, FILE* dest) {
	size_t bytes;
	static char temp[BUFSIZE];

	while ((bytes = fread(temp, sizeof(char), BUFSIZE, source)) > 0)
		fwrite(temp, sizeof(char), bytes, dest);
}