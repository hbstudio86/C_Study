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

void title(void);

int main() {

	//Main title 영역//
	title();
	DELAY;
	CLEAR;
	//Main title 영역//
	int j = 0;

	for (int i = 1; i < 16; i++) {
		j = 16 * i+8;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),j);
		printf("   \u2592 \u25a0 \u25a1 \t\t %X\n", j);
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