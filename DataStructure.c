#pragma warning(disable:4996)
#pragma warning(disable:6031)
#include <stdio.h>
#include <stdlib.h>

#define DEBUG 1

////////////////////////////////////////////////////////////////////////////_240105
/*
������ ����ϵ���
1. �迭 ����		240103
2. ���� : �迭 Ÿ�� 240105
	���ڸ� �޴� ���·� ������ ��
3. ť : �迭 Ÿ��
*/
////////////////////////////////////////////////////////////////////////////
/////////////////////////////<�ؾ� �ϴ� �۾� ��>/////////////////////////////
/*
�迭 Ÿ���� �迭 ���� �۾� : ������� �迭�� �ް� ��� ���� 0�� �ƴ��� Ȯ�� �� �� �Է� - �Ϸ�
������ �迭 Ÿ������ �ٷ�� �ϴµ�, ����ü ������� �ұ�? �ƴ� - comp
���õ� �ݺ��� ������ ���� ������ �� �ְ� ������ ��
���� �Լ� �ϼ�
*/
////////////////////////////////////////////////////////////////////////////
//function 
//0. ���� ���
void msgPrint(int);
//1. �迭
// createA, addA, delA, clearA
int* createA(int);
int addA(int [],int);
void outA(int [],int);
void clearA(int[]);
//2. ����
// createS StackIsFull, PushS, StackIsEmpty, PopS
typedef struct _stack {

	int top;	//������ ��ġ
	char* data;	// ������ Data, create�� ������� �迭�� ������
	int size;	// ������ ũ��

}STACK;
STACK* createS(int);
int StackIsFull(STACK*);
STACK* PushS(STACK*, char);
int StackIsEmpty(STACK*);
STACK* PopS(STACK*, char);

int main(void) {
	printf("������ ����մϴ�.\n");
	//array
	int value;
	int* arr;
	printf("1. �迭 �ٷ��\n������ �迭�� ũ�⸦ �Է��ϼ���...");
	scanf("%d", &value);
	arr = createA(value);
	addA(arr,value);
	outA(arr, value);
	clearA(arr);

	//stack
	STACK* stack;
	stack = createS(10);
	PushS(stack, 'K');


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
	msgPrint(3); printf("createA_checking initialize value\n");
	for (int i = 0; i < member; i++) {
		printf("array[%d]: %d\n", i, Array[i]);
	}
	msgPrint(3); printf("createA_array address = %p\n", Array);
#endif // DEBUG
	return Array;
}
int addA(int arr[],int size) {	//�迭�� ���� ���������� �����Ѵ�.
#ifdef DEBUG
	msgPrint(3); printf("addA_array size = %d\n", size);
#endif // DEBUG
	for (int i = 0; i < size; i++) {
		msgPrint(1); printf("arr[%d]������ ���� �Է� : ",i);
		scanf("%d", &arr[i]);
	}
	//���� ����
}
void outA(int arr[],int size) {
#ifdef DEBUG
	msgPrint(3); printf("outA_array address : %p\n", arr);
#endif // DEBUG
	for (int i = 0; i < size; i++) {
		msgPrint(1); printf("Array[%d] value : %d\n", i, arr[i]);
	}
}
void clearA(int arr[]) {
#ifdef DEBUG
	msgPrint(3); printf("clearA_deleted array address : %p\n", arr);
#endif // DEBUG
	free(arr);
	msgPrint(1); printf("array is free.\n");

}

STACK* createS(int size){
	STACK* stack = (STACK*)malloc(sizeof(STACK));	// �����ϳ� ����
	stack->top = -1;	// under floor
	stack->size = size;
	stack->data = (char*)malloc(sizeof(char) * size);	// data�� ���� �迭�� ����
	msgPrint(1); printf("stack created complete (size : %d)\n", size);
#ifdef DEBUG
	msgPrint(3); printf("createS_stack address : %p, data array address : %p\n", stack, stack->data);
#endif // DEBUG
	return stack;
}
int StackIsFull(STACK* stack){
#ifdef DEBUG
		msgPrint(3); printf("StackIsFull_stack size = %d, stack top = %d\n", stack->size, stack->top);
#endif // DEBUG
	if (stack->size-1 <= stack->top) {
		msgPrint(1); printf("Stack is full.\n");
		return 1;
	}
	else {
		return 0;
	}
}
STACK* PushS(STACK* stack, char item){
	if (StackIsFull(stack) == 1) {
		msgPrint(1); printf("can't push item.(%c)\n", item);
	}
	else {
		//stack->top++;
		stack->data[++stack->top] = item;
#ifdef DEBUG
		msgPrint(3); printf("PushS_stack top = %d\n", stack->top);
#endif // DEBUG
		msgPrint(1); printf("item was pushed.(%c)\n", item);
#ifdef DEBUG
		msgPrint(3); printf("PushS_stack data[%d] = %c\n", stack->top, stack->data[stack->top]);
#endif // DEBUG
	}
}
int StackIsEmpty(STACK* stack){

}
STACK* PopS(STACK* stack, char item){

}