#pragma warning(disable:4996)
#pragma warning(disable:6031)
#include <stdio.h>
#include <stdlib.h>

#define DEBUG 1

////////////////////////////////////////////////////////////////////////////_240101
/*
������ ����ϵ���
1. �迭 ����		240103
2. ���� : �迭 Ÿ��
3. ť : �迭 Ÿ��
*/
////////////////////////////////////////////////////////////////////////////
/////////////////////////////<�ؾ� �ϴ� �۾� ��>/////////////////////////////
/*
�迭 Ÿ���� �迭 ���� �۾� : ������� �迭�� �ް� ��� ���� 0�� �ƴ��� Ȯ�� �� �� �Է�
*/
////////////////////////////////////////////////////////////////////////////
//function 
//0. ���� ���
void msgPrint(int);
//1. �迭
// createA, addA, delA, clearA
int* createA(int);
int addA(int arr[],int,int);
void outA(void);
void clearA(int[]);



int main(void) {
	printf("������ ����մϴ�.\n");
	//array
	int value;
	int* arr;
	printf("1. �迭 �ٷ��\n������ �迭�� ũ�⸦ �Է��ϼ���...");
	scanf("%d", &value);
	arr = createA(value);
	addA(arr, 1);
	clearA(arr);
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
	msgPrint(1); printf("0���� �ʱ�ȭ\n");
	for (int i = 0; i < member; i++) {
		Array[i] = 0;
	}
#ifdef DEBUG
	msgPrint(3); printf("�ʱⰪ Ȯ��\n");
	for (int i = 0; i < member; i++) {
		printf("array[%d]: %d\n", i, Array[i]);
	}
	msgPrint(3); printf("�迭 �ּ� : %p\n", Array);
#endif // DEBUG

	return Array;
}
int addA(int arr[],int size, int value) {	//�迭�� ���� �޾� 0�� �ƴ� ���� ���� �����Ѵ�.
#ifdef DEBUG
	msgPrint(3); printf("�迭�� ũ��� %d�Դϴ�.\n", size);
#endif // DEBUG

	//���� ����
}
void outA(void) {

}
void clearA(int arr[]) {
#ifdef DEBUG
	msgPrint(3); printf("�����Ǵ� �迭 �ּ� : %p\n", arr);
#endif // DEBUG
	free(arr);
	msgPrint(1); printf("�迭 ����\n");

}