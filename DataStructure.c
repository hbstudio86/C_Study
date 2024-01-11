#pragma warning(disable:4996)
#pragma warning(disable:6031)
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DEBUG 1

////////////////////////////////////////////////////////////////////////////_240105
/*
������ ����ϵ���
1. �迭 ����		240103
2. ���� : �迭 Ÿ�� 240105
	���ڸ� �޴� ���·� ������ ��
3. ť : �迭 Ÿ�� 240110
*/
////////////////////////////////////////////////////////////////////////////
/////////////////////////////<�ؾ� �ϴ� �۾� ��>/////////////////////////////
/*
�迭 Ÿ���� �迭 ���� �۾� : ������� �迭�� �ް� ��� ���� 0�� �ƴ��� Ȯ�� �� �� �Է� - �Ϸ�
������ �迭 Ÿ������ �ٷ�� �ϴµ�, ����ü ������� �ұ�? �ƴ� - comp
���õ� �ݺ��� ������ ���� ������ �� �ְ� ������ �� - comp 
���� �Լ� �ϼ� -comp
main �Լ��� ���õ� �Է� �ϰ� ��� �� �� �ְ� �ݺ������� ���� �ϵ���
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
STACK* PopS(STACK*);

//3. ť
// createQ QueIsFull PutQ QueIsEmpty PopQ
typedef struct _que {
	int front, rear;
	int size;
	int* data;
}Que;
Que* createQ(int);
int QueIsFull(Que*);
void PushQ(Que*, int);
int QueIsEmpty(Que*);
void PopQ(Que*);

int main(void) {
	time_t t1 = time(NULL);
	struct tm* times = localtime(&t1);

	printf("���α׷� ���� �ð� : %d�� %d�� %d�� %d�� %d�� %d��\n", times->tm_year + 1900, times->tm_mon + 1, times->tm_mday, times->tm_hour, times->tm_min,times->tm_sec);


	printf("time = %llu\n", t1);

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
	char item;
	STACK* stack;
	printf("2. ���� ����ϱ�\n������ ������ ũ�⸦ �Է��ϼ���...");
	scanf("%d", &value);
	getchar();	// ���๮�� ó��
	stack = createS(value);
	for (int i = 0; i < value; i++) {
		printf("���ÿ� ���� ���� �Է��ϼ���...");
		scanf("%c", &item);
		getchar();
		PushS(stack, item);
	}
	//PushS(stack, 'K');
	PopS(stack);

	//que
	Que* que;
	printf("3. ť ����ϱ� \n������ ť�� ũ�⸦ �Է��ϼ���...");
	scanf("%d", &value);
	getchar();
	que = createQ(value);
	PushQ(que, 1);




/////////////////////////////////////////////////////////////////////////////////////
	time_t t2 = time(NULL);
	printf("time = %llu\n%llu\n%llu\n", t2,t1,t2-t1);
	times = localtime(&t2);
	time_t t3 = t2 - t1;
	printf("���α׷� ���� �ð� : %d�� %d�� %d�� %d�� %d�� %d��\n", times->tm_year + 1900, times->tm_mon + 1, times->tm_mday, times->tm_hour, times->tm_min, times->tm_sec);
	times = localtime(&t3);
	printf("���α׷� ���� �ð� : %d�� %d�� %d�� %d�� %d�� %d��\n", times->tm_year - 70, times->tm_mon, times->tm_mday -1, times->tm_hour -9, times->tm_min, times->tm_sec);
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
	if (stack->top == -1) {	// top�� -1�̸� ���� ������
		msgPrint(1); printf("stack is empty.");
#ifdef DEBUG
		msgPrint(3); printf("StackIsEmpty_stack top = %d\n", stack->top);
#endif // DEBUG
		return 1;
	}
	else {
		msgPrint(1); printf("stack is not empty.");
		return 0;
	}
}
STACK* PopS(STACK* stack){
	if (StackIsEmpty(stack) == 0) {	// stack�� ���� �ִٸ�
		msgPrint(1); printf("stack pop, value = %c\n", stack->data[stack->top]);
		stack->top--;	// stack top �� ����
	}
	else {
		msgPrint(1); printf("Please, pop data before push the data. \n");
	}
}
Que* createQ(int num) {
	Que* que = (Que*)malloc(sizeof(Que));
	int* datas = (int*)malloc(sizeof(int) * num);
	if (que != NULL) {
		que->front = -1;
		que->rear = -1;
		que->data = datas;
		que->size = num;
#ifdef DEBUG
	msgPrint(3); printf("createQ_que address = %p\n", que);
	msgPrint(3); printf("createQ_que datas address = %p\n", datas);
	msgPrint(3); printf("createQ_que front = %d\n", que->front);
	msgPrint(3); printf("createQ_que rear = %d\n", que->rear);
	msgPrint(3); printf("createQ_que size = %d\n", que->size);
#endif // DEBUG
	}
	msgPrint(1); printf("que is created.\n");
	return que;
}
int QueIsFull(Que* que) {
	if (que->rear >= que->size - 1) {
		msgPrint(1); printf("que is full");
		return 1;
	}
	else {
		return 0;
	}
}
void PushQ(Que* que, int num) {
	if (QueIsFull(que) != 1) {
		que->rear++;
#ifdef DEBUG
		msgPrint(3); printf("PushQ_que[%d] = %d (before)\n",que->rear, que->data[que->rear]);
#endif // DEBUG
		que->data[que->rear] = num;
		msgPrint(1); printf("%d is pushed to que.\n",num);
#ifdef DEBUG
		msgPrint(3); printf("PushQ_que[%d] = %d (after)\n", que->rear, que->data[que->rear]);
#endif // DEBUG

	}
}
int QueIsEmpty(Que* que) {

}
void PopQ(Que* que) {

}