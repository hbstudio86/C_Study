#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>

//#define DEBUG 1

//231230 test text

static int _s_index = -1;	// stack �� index 

/*�迭 (�⺻)
1. �迭 ����
2. ������ ����
3. ������ ����

*/
int * arrCreate(int);	// �迭 ���� : ��������..
void arrAdd(int [], int*, int);		// ������ ����
void arrDel(int);		// ������ ����
/*�迭 (��)
1. �迭 ����	: ���� �Ҵ����� ����
2. ������ ���� : 
3. ������ ����
-> �̰��� �� ������� �߾���??
*/


/*�ڷ� ���� ����*/
//1. ���� ���� : ������ ũ��, �������� ����
int* stackCreate(int);
//2. ������ ����
int put();
//3. ������ ���� : ���� ��ȯ ��
int pop();
//4. ���� ���� Ȯ�� (�� �������� ������ �������� Ȯ�� ��)
int _s_isEmpty(int*);
int _s_isFull(int*);



// �� ��� �Լ�
void arrPrint(int[], int);
void infPrint(char*);
void debPrint(char*);	// 240101 : ���� ��� ���� 

int main(void) {

	// �迭
		//�Ϲ����� �迭��..
	int arr1[10] = { 0, };	// int �� �迭 10�� ����

	arrPrint(arr1, 10);

		//�迭�� ���Ӱ� ����
	int* pArray = NULL;
	int szElement;
	int _ifirst = -1;	// ���� �迭�� ��ġ
	
	printf(" ! Information : ������ �迭�� ���� ������ �Է��ϼ���:_____\b\b\b\b\b");
	scanf("%d", &szElement);

	pArray = arrCreate(szElement);

	if (pArray != NULL) {	// ���Ӱ� �迭�� �����Ǿ��ٸ�...
		free(pArray);
		printf(" ! Information : ������ �迭�� ���� �Ǿ����ϴ�.\n");
#ifdef DEBUG
		printf("_?_DEBUG_FREE_ARRAY_ADDRESS_0x%p\n", pArray);
#endif // DEBUG

	}
	else {	// �迭 ������ ���� �ʾҴٸ�...
		printf(" ! Information : Array is not Created.n");
	}

	while (1) {


	}


	// ���� ����Ʈ

	// ����

	// ť



	return 0;
}

int* arrCreate(int szArray) {	// �迭 ���� : ��������..	�迭 �ּ� ����
	if (szArray > 0) {	// 0�̻��� ������ �Է� �Ǿ��� ���� 
		int* pArr = (int*)malloc(sizeof(int) * szArray);	//�Է��� ����� �迭 ����
		printf(" ! Information : %d ũ���� �迭�� ���� �Ǿ����ϴ�.\n", szArray);
#ifdef DEBUG
		printf("_?_DEBUG_ARRAY_ADDRESS_0x%p\n", pArr);
#endif // DEBUG
		return pArr;	// �迭 �ּ� ����
	}
	else {
		printf(" ! Warning : �迭�� ũ��� 0�� ���� �� �� �����ϴ�.\n");
		return NULL;	// �ƹ��͵� ��ȯ ���� ����
	}

}
void arrAdd(int arr[], int * first, int sz_element) {		// ������ ���� : �迭�� �ּҿ� ���� ��ġ�� ����
#ifdef DEBUG
	printf("_?_DEBUG_ARRAY_ADDRESS_0x%p_FIRST_%d\n", arr, *first);
#endif // DEBUG
	// first�� � ������ ó�� �ؾ� �ϴ���...
	if (*first < sz_element - 1) {	// sz_element ������ �۾ƾ� ���� �� �� �ְ� �Ѵ�. 
		*first += 1;				// index�� �ϳ� �ű�
		printf(" ! Information : �迭�� ���� ���� �Է��ϼ���._____\b\b\b\b\b");
		scanf("%d", &arr[*first]);
#ifdef DEBUG
		printf("_?_DEBUG_INPUT_ARRAY_ADDRESS_0x%p_VALUE_%d\n", &arr[*first], arr[*first]);
#endif // DEBUG
	}
	else {
		printf(" ! Warning : �迭�� �������� �Դϴ�.\n");
	}

}
void arrDel(int n) {		// ������ ����

}

void arrPrint(int arr[], int n) {

	for (int i = 0; i < n; i++) {
		printf("Array value is %d _ index [%d] \n", arr[i],i);
	}

}

/*�ڷ� ���� ����*/
//1. ���� ���� : ������ ũ��, �������� ����
int* stackCreate(int n) {
	int* sArray = (int*)malloc(sizeof(int) * n);	// stack ũ�� ����
}
//2. ������ ����
int put() {

}
//3. ������ ���� : ���� ��ȯ ��
int pop() {

}
//4. ���� ���� Ȯ�� (�� �������� ������ �������� Ȯ�� ��)
int _s_isEmpty(int* stack) {
#ifdef DEBUG
	printf("_?_DEBUG_STACK_SIZE_%d_BYTE", sizeof(stack));
#endif // DEBUG
	
	if (_s_index != -1) {	// stack�� �ƹ� ���� �� ���� ����
		printf(" ! Information : Stack is Empty! \n");
	}


}
int _s_isFull(int* stack) {

}