#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>

#define PAUSE system("pause")
#define CLEAR system("cls")
#define DELAY Sleep(1000)
#define FBLOCK "\u25a0"
#define EBLOCK "\u25a1"

/*
���̵� : normal 20 by 100 ?

*/
/*******************<Develop Note>********************
240106
	���밡 �־�� �Ѵ�.���� -> ���� -> ���� -> ���� ...
	�׸��� ���� �迭�� ���·� �����ؾ� ��
	0�� ���� 1�� ������ 2�� ������
	fx�� ���ڿ� ������ �����ؾ� ��
	�� ���� ������ �־�� �ϴµ�... �ᱹ ����ü �迭�� ������� �Ѵ�
	���� ����(0,1,2)�� ���� Ÿ��(��,��,��,��,����)�� ���� ������ ��ƾ� ��



******************************************************/



void title(void);
void delay(int);	// ���ϴ� �ð� ��ŭ Delay

int main() {

	//Main title ����//
	title();
	DELAY;
	CLEAR;
	//Main title ����//
	int j = 0;

	for (int i = 0; i < 255; i++) {
		j = i;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),j);
		printf("   \u2592 \u25a0 \u25a1 \t\t %X \t\t �� ������ �ٲ���?\n", j);
		//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), j + (10 * i));
		//printf("   \u2592 \u25a0 \u25a1 \t\t %X \t\t �� ������ �ٲ���?\n", j + (10 * i));
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

// main title ȭ��
void title(void) {

	printf("\t\t\tTetris\n");
	printf("build : 202310001\n");
	printf("   \u2592 \u25a0 \u25a1 \t\t\n");
}
void delay(int timer) {
	Sleep(timer);
}