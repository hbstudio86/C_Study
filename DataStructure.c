#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>

//#define DEBUG 1

//231230 test text

static int _s_index = -1;	// stack 용 index 

/*배열 (기본)
1. 배열 생성
2. 데이터 삽입
3. 데이터 삭제

*/
int * arrCreate(int);	// 배열 생성 : 동적으로..
void arrAdd(int [], int*, int);		// 데이터 삽입
void arrDel(int);		// 데이터 삭제
/*배열 (링)
1. 배열 생성	: 동적 할당으로 생성
2. 데이터 삽입 : 
3. 데이터 삭제
-> 이것을 왜 만들려고 했었지??
*/


/*자료 구조 스택*/
//1. 스택 생성 : 스택의 크기, 정수형만 저장
int* stackCreate(int);
//2. 데이터 삽입
int put();
//3. 데이터 삭제 : 값을 반환 함
int pop();
//4. 스택 상태 확인 (빈 상태인지 가득찬 상태인지 확인 함)
int _s_isEmpty(int*);
int _s_isFull(int*);



// 값 출력 함수
void arrPrint(int[], int);
void infPrint(char*);
void debPrint(char*);	// 240101 : 정보 출력 전용 

int main(void) {

	// 배열
		//일반적인 배열은..
	int arr1[10] = { 0, };	// int 형 배열 10개 생성

	arrPrint(arr1, 10);

		//배열을 새롭게 정의
	int* pArray = NULL;
	int szElement;
	int _ifirst = -1;	// 현재 배열의 위치
	
	printf(" ! Information : 생성할 배열의 원소 갯수를 입력하세요:_____\b\b\b\b\b");
	scanf("%d", &szElement);

	pArray = arrCreate(szElement);

	if (pArray != NULL) {	// 새롭게 배열이 생성되었다면...
		free(pArray);
		printf(" ! Information : 생성된 배열이 삭제 되었습니다.\n");
#ifdef DEBUG
		printf("_?_DEBUG_FREE_ARRAY_ADDRESS_0x%p\n", pArray);
#endif // DEBUG

	}
	else {	// 배열 생성이 되지 않았다면...
		printf(" ! Information : Array is not Created.n");
	}

	while (1) {


	}


	// 연결 리스트

	// 스택

	// 큐



	return 0;
}

int* arrCreate(int szArray) {	// 배열 생성 : 동적으로..	배열 주소 리턴
	if (szArray > 0) {	// 0이상의 갯수가 입력 되었을 때만 
		int* pArr = (int*)malloc(sizeof(int) * szArray);	//입력한 수대로 배열 생성
		printf(" ! Information : %d 크기의 배열이 생성 되었습니다.\n", szArray);
#ifdef DEBUG
		printf("_?_DEBUG_ARRAY_ADDRESS_0x%p\n", pArr);
#endif // DEBUG
		return pArr;	// 배열 주소 리턴
	}
	else {
		printf(" ! Warning : 배열의 크기는 0개 이하 일 수 없습니다.\n");
		return NULL;	// 아무것도 반환 하지 않음
	}

}
void arrAdd(int arr[], int * first, int sz_element) {		// 데이터 삽입 : 배열의 주소와 시작 위치를 받음
#ifdef DEBUG
	printf("_?_DEBUG_ARRAY_ADDRESS_0x%p_FIRST_%d\n", arr, *first);
#endif // DEBUG
	// first를 어떤 식으로 처리 해야 하는지...
	if (*first < sz_element - 1) {	// sz_element 수보다 작아야 삽입 할 수 있게 한다. 
		*first += 1;				// index를 하나 옮김
		printf(" ! Information : 배열에 넣을 값을 입력하세요._____\b\b\b\b\b");
		scanf("%d", &arr[*first]);
#ifdef DEBUG
		printf("_?_DEBUG_INPUT_ARRAY_ADDRESS_0x%p_VALUE_%d\n", &arr[*first], arr[*first]);
#endif // DEBUG
	}
	else {
		printf(" ! Warning : 배열이 만원상태 입니다.\n");
	}

}
void arrDel(int n) {		// 데이터 삭제

}

void arrPrint(int arr[], int n) {

	for (int i = 0; i < n; i++) {
		printf("Array value is %d _ index [%d] \n", arr[i],i);
	}

}

/*자료 구조 스택*/
//1. 스택 생성 : 스택의 크기, 정수형만 저장
int* stackCreate(int n) {
	int* sArray = (int*)malloc(sizeof(int) * n);	// stack 크기 생성
}
//2. 데이터 삽입
int put() {

}
//3. 데이터 삭제 : 값을 반환 함
int pop() {

}
//4. 스택 상태 확인 (빈 상태인지 가득찬 상태인지 확인 함)
int _s_isEmpty(int* stack) {
#ifdef DEBUG
	printf("_?_DEBUG_STACK_SIZE_%d_BYTE", sizeof(stack));
#endif // DEBUG
	
	if (_s_index != -1) {	// stack에 아무 값이 들어가 있지 않음
		printf(" ! Information : Stack is Empty! \n");
	}


}
int _s_isFull(int* stack) {

}