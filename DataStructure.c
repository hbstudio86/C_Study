#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>

////////////////////////////////////////////////////////////////////////////_240101
/*
������ ����ϵ���
1. �迭 ����		240103
2. ���� : �迭 Ÿ��
3. ť : �迭 Ÿ��
*/
////////////////////////////////////////////////////////////////////////////

//function 
//0. ���� ���
void msgPrint(int);
//1. �迭
// createA, addA, delA, clearA
int* createA(int);
int addA(int);
void outA(void);
void clearA(int[]);



int main(void) {
	printf("������ ����մϴ�.\n");

	return 0;
}



//function
void msgPrint(int type) {

	if (1 <= type && 3 >= type) {	//	������ �Է� �������� ���
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
		printf("1~3 ������ ���ڸ� �Է��ϼ���.\n");
}
int* createA(int member) {
	int* Array = (int*)malloc(sizeof(int) * member);
	msgPrint(1); printf("�迭 ����\n");
	return Array;
}
int addA(int value) {

}
void outA(void) {

}
void clearA(int arr[]) {
	free(arr);
	msgPrint(1); printf("�迭 ����\n");
}