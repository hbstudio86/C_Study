#pragma warning(disable:4996)
#pragma warning(disable:6031)
#include <stdio.h>
#include <stdlib.h>

#define DEBUG 1

////////////////////////////////////////////////////////////////////////////_240105
/*
정수만 취급하도록
1. 배열 생성		240103
2. 스택 : 배열 타입 240105
	문자를 받는 형태로 만들어야 함
3. 큐 : 배열 타입
*/
////////////////////////////////////////////////////////////////////////////
/////////////////////////////<해야 하는 작업 들>/////////////////////////////
/*
배열 타입의 배열 삽입 작업 : 사이즈와 배열을 받고 모든 값이 0이 아닌지 확인 후 값 입력 - 완료
스택을 배열 타입으로 다뤄야 하는데, 구조체 방식으로 할까? 아님 - comp
스택도 반복문 돌려서 값을 대입할 수 있게 만들어야 함
남은 함수 완성
*/
////////////////////////////////////////////////////////////////////////////
//function 
//0. 정보 출력
void msgPrint(int);
//1. 배열
// createA, addA, delA, clearA
int* createA(int);
int addA(int [],int);
void outA(int [],int);
void clearA(int[]);
//2. 스택
// createS StackIsFull, PushS, StackIsEmpty, PopS
typedef struct _stack {

	int top;	//스택의 위치
	char* data;	// 스택의 Data, create로 만들어진 배열을 지정함
	int size;	// 스택의 크기

}STACK;
STACK* createS(int);
int StackIsFull(STACK*);
STACK* PushS(STACK*, char);
int StackIsEmpty(STACK*);
STACK* PopS(STACK*, char);

int main(void) {
	printf("정수만 취급합니다.\n");
	//array
	int value;
	int* arr;
	printf("1. 배열 다루기\n생성할 배열의 크기를 입력하세요...");
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
	msgPrint(1); printf("0으로 초기화\n");
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
int addA(int arr[],int size) {	//배열에 값을 순차적으로 대입한다.
#ifdef DEBUG
	msgPrint(3); printf("addA_array size = %d\n", size);
#endif // DEBUG
	for (int i = 0; i < size; i++) {
		msgPrint(1); printf("arr[%d]원소의 값을 입력 : ",i);
		scanf("%d", &arr[i]);
	}
	//만원 상태
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
	STACK* stack = (STACK*)malloc(sizeof(STACK));	// 스택하나 생성
	stack->top = -1;	// under floor
	stack->size = size;
	stack->data = (char*)malloc(sizeof(char) * size);	// data를 담을 배열을 생성
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