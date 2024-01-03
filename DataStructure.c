#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>

////////////////////////////////////////////////////////////////////////////_240101
/*
정수만 취급하도록
1. 배열 생성		240103
2. 스택 : 배열 타입
3. 큐 : 배열 타입
*/
////////////////////////////////////////////////////////////////////////////

//function 
//0. 정보 출력
void msgPrint(int);
//1. 배열
// createA, addA, delA, clearA
int* createA(int);
int addA(int);
void outA(void);
void clearA(int[]);



int main(void) {
	printf("정수만 취급합니다.\n");

	return 0;
}



//function
void msgPrint(int type) {

	if (1 <= type && 3 >= type) {	//	정해진 입력 정보에만 출력
		switch (type)
		{
		case 1:	// information
			printf("_!_Information : ");
			break;
		case 2:	// warning
			printf("_@_Warning : ");
			break;
		case 3:	// debug
			printf("_?_DEBUG : ");
			break;
		}
	}
	else
		printf("1~3 사이의 숫자를 입력하세요.\n");
}
int* createA(int member) {
	int* Array = (int*)malloc(sizeof(int) * member);
	msgPrint(1); printf("배열 생성\n");
	return Array;
}
int addA(int value) {

}
void outA(void) {

}
void clearA(int arr[]) {
	free(arr);
	msgPrint(1); printf("배열 해제\n");
}