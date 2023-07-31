#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>

#define PAUSE system("pause")


int main() {

	int j = 0;

	for (int i = 1; i < 16; i++) {
		j = 16 * i+8;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),j);
		printf("     ¡á¡á¡á¡á     \t\t %X\n", j);
		//PAUSE;
	}

	return 0;
}