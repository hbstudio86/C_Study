#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>

#define PAUSE system("pause")
#define CLEAR system("cls")
#define DELAY Sleep(1000)
#define FBLOCK "\u25a0"
#define EBLOCK "\u25a1"

/*
난이도 : normal 20 by 100 ?

*/
/*******************<Develop Note>********************
240106
	뼈대가 있어야 한다.시작 -> 실행 -> 보드 -> 시작 ...
	그리고 블럭은 배열의 형태로 구성해야 함
	0은 없음 1은 유동블럭 2는 고정블럭
	fx로 글자와 배경색을 지정해야 함
	블럭 별로 색깔을 넣어야 하는데... 결국 구조체 배열을 만들어어야 한다
	블럭의 정보(0,1,2)와 블럭의 타입(ㄱ,ㅡ,ㅏ,ㅁ,ㄹ별)별 색의 정보를 담아야 함



******************************************************/



void title(void);
void delay(int);	// 원하는 시간 만큼 Delay

int main() {

	//Main title 영역//
	title();
	DELAY;
	CLEAR;
	//Main title 영역//
	int j = 0;

	for (int i = 0; i < 255; i++) {
		j = i;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),j);
		printf("   \u2592 \u25a0 \u25a1 \t\t %X \t\t 왜 배경색이 바뀌지?\n", j);
		//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), j + (10 * i));
		//printf("   \u2592 \u25a0 \u25a1 \t\t %X \t\t 왜 배경색이 바뀌지?\n", j + (10 * i));
		//PAUSE;
		Sleep(1000);
	}
	//
	//while (0) {

	//}

	system("cls");

	//printf("\u25a0\u25a0\u25a0\n\u25a0\u25a0\u25a0\n\u25a0\u25a0\u25a0\n"); //3by3 area create..
	printf("%s%s%s\n%s%s%s\n%s%s%s\n", FBLOCK, FBLOCK, FBLOCK, FBLOCK, FBLOCK, FBLOCK, FBLOCK, FBLOCK, FBLOCK);
	DELAY; CLEAR;
	printf("\u25a0\u25a1\u25a0\n\u25a0\u25a0\u25a0\n\u25a0\u25a0\u25a0\n"); //3by3 area create..
	DELAY; CLEAR;
	printf("\u25a0\u25a0\u25a0\n\u25a0\u25a1\u25a0\n\u25a0\u25a0\u25a0\n"); //3by3 area create..
	DELAY; CLEAR;
	printf("\u25a0\u25a0\u25a0\n\u25a0\u25a0\u25a0\n\u25a0\u25a1\u25a0\n"); //3by3 area create..
	DELAY;

	printf("%zd", sizeof(FBLOCK));


	return 0;
}

// main title 화면
void title(void) {

	printf("\t\t\tTetris\n");
	printf("build : 202310001\n");
	printf("   \u2592 \u25a0 \u25a1 \t\t\n");
}
void delay(int timer) {
	Sleep(timer);
}