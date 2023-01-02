#pragma warning (disable:6031)
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <memory.h>

#define LOWLIMIT 5
#define UPLIMIT 30


//###�Լ� ����###
int _fCheck(int*);
void _fResult(int[], int[], int);	//������ �� ��¿�
void _fResult2(int[], int);
void _fResult3(int[], int, int, int);	//Ȯ�ο�3
void _fSwap(int*, int*,int,int);			//SWAP
void _fOutComp(int);
void _fOutComp2(int);	//��� ��¿�
void _fSelectSORT(int[], int);	//���� ����
void _fBubbleSORT(int[], int);	//���� ����
void _fInsertSORT(int[], int);	//���� ����#1
void _fInsertSORT2(int[], int);	//���� ����#2
void _fQuickSORT(int[], int, int);	//�� ����, �迭, ũ��, �����ġ

int main(void) {

	//���� ����
	int _iArrSize;
	int _iCommand = 0;	//�Է� command
	int* _iParr;
	int* _iParr2;	//�Ű� ���� �迭
	srand(time(NULL));	//�õ� 

	//ó��
	printf("SORT TEST Program\nArray�� Size�� ���ϼ���..:___(%d~%d)\b\b\b\b\b\b\b\b\b",LOWLIMIT,UPLIMIT);
	scanf("%d", &_iArrSize);
	getchar();
	_iArrSize = _fCheck(&_iArrSize);
	_iParr = (int*)malloc(sizeof(int) * _iArrSize);	//�Է��� ũ�� ��ŭ ���� �迭 �Ҵ�
	_iParr2 = (int*)malloc(sizeof(int) * _iArrSize);	//�Ű� ���� �迭
	if (_iParr2 != NULL) {		//�޸𸮰� ����� �Ҵ�Ǿ��ٸ�...	�����ص� �ȴ�.
		memset(_iParr2, 0, sizeof(int) * _iArrSize);			//0���� �ʱ�ȭ
	}
	else {	//�޸� �Ҵ� ���н�
		puts("�޸� �Ҵ翡 �����Ͽ����ϴ�. ���α׷��� �����մϴ�.");
		free(_iParr2);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", sizeof(int) * _iArrSize);	//���� �ص� �ȴ�.
	//���� malloc �Լ��� �����Ѵٸ�...
	if (NULL == _iParr) {
		free(_iParr);
		exit(EXIT_FAILURE);
	}
	////���� �Ҵ��� �迭�� �� �ֱ�
	else {
		for (int i = 0; i < _iArrSize; i++) {
			_iParr[i] = rand();
			printf("[%02d] %06d | %06d\n", i, _iParr[i], _iParr2[i]);
		}
	}
	memcpy(_iParr2, _iParr, sizeof(int) * _iArrSize);	//������ �����ϰ� ���纻�� ����ϴ�.

	do {
		printf("\n======= SELECT of SORT Program =======\n");
		puts("1.Select SORT");
		puts("2.Bubble SORT");
		puts("3.Insert SORT");
		puts("33.Insert SORT(2)");
		puts("4.Shell SORT");
		puts("0.Program END");
		scanf("%d", &_iCommand);
		//������ �����ϰ� ���纻���� �����մϴ�.
		switch (_iCommand)
		{
		case 1:
			puts("Before SORT");
			_fResult2(_iParr2, _iArrSize);
			_fSelectSORT(_iParr2, _iArrSize);
			break;
		case 2:
			_fResult2(_iParr2, _iArrSize);
			_fBubbleSORT(_iParr2, _iArrSize);
			break;
		case 3:
			_fResult2(_iParr2, _iArrSize);
			_fInsertSORT(_iParr2, _iArrSize);
			break;
		case 33:
			puts("NO Function");
		default:
			break;
		}
		_fResult(_iParr, _iParr2, _iArrSize);
		memcpy(_iParr2, _iParr, sizeof(int) * _iArrSize);	//������ �����ϰ� ���纻�� ����ϴ�.
	} while (_iCommand != 0);

	//���
	free(_iParr);
	free(_iParr2);
	puts("����");

	return 0;
}

//###�Լ� ����###
//�Է� �迭 ũ�� üũ
int _fCheck(int* input) {
	while (*input < LOWLIMIT || *input > UPLIMIT)
	{
		printf("�Է��� ��%d��/�� %d���� %d ������ ���� �����ϴ�.\n�ٽ� �Է��ϼ���:___\b\b\b", *input, LOWLIMIT, UPLIMIT);
		scanf("%d", input);
	}
	return *input;
}

//Ȯ�ο�1:���� ��/�� ��
void _fResult(int bf[], int af[], int n) {
	for (int i = 0; i < n; i++) {
		printf("[%02d] %6d | %6d \n", i, bf[i], af[i]);
	}
}
//Ȯ�ο�2:�迭 ��¿�
void _fResult2(int ar[], int n) {
	for (int i = 0; i < n; i++) {
		printf("[%02d] %6d \n", i, ar[i]);
	}
}
//Ȯ�ο�3:�ð�ȭ
void _fResult3(int ar[], int n, int pnt1, int pnt2) {
	char Edge = ' ';
	for (int i = 0; i < n; i++) {
		if (i == pnt1)
			Edge = '<';
		else if (i == pnt2)
			Edge = '>';
		else
			Edge = ' ';
		printf("[%02d] %6d %c \n", i, ar[i], Edge);
	}
}

//��ȯ��
void _fSwap(int* src1, int* src2,int bn, int an) {
	puts("!SWAP!");
	printf("[%d]<---->[%d]\n", bn, an);
	int tmp = *src2;
	*src2 = *src1;
	*src1 = tmp;
}

//���� ��¿�: ��ȯ�� ������ ��� �Ѵ�
void _fOutComp(int comp) {
	printf("Select SORT Result: Compare_%d\n", comp);
}

//���� ��¿�2: ��� ����� ��� �Ѵ�
void _fOutComp2(int comp) {
	puts("===== Result =====");
	printf("*Result: Total Swap = %d\n", comp);
	puts("=====  END   =====");
}
//��������
void _fSelectSORT(int src[],  int n) {
	puts("Select SORT Start");
	int Step = 0, Comp = 0; //step���� �� Ƚ���� ǥ��
	int MinVal;					//index ��ȣ�� ����
	int tmp = 0;	//�ӽ� ����, �ּҰ� ��ȯ�� ���� ���
	for (int i = 0; i < n; i++) {
		MinVal = i;	//index ��ȣ�� �ִ��� ����
		for (int j = 1 + i; j < n; j++) {
			if (src[MinVal] > src[j]) {
				MinVal = j;	//�ּҰ��̸� �װ��� index��ȣ�� ����
			}
		}
		//1ȸ���� ������..��ȯ�� �̷�� ����.
		if (src[i] != src[MinVal]) {	//��ȯ�� �̷�� ���� ���� comp�� swap�� �̷�� ����.
			_fSwap(&src[i], &src[MinVal], i, MinVal);
			Comp++;	//swap cnt�� ���� ���� �Ѵ�????? �ֳ� �̰� �� ī��Ʈ�� �׷���
		}
		_fOutComp(Comp);
		_fResult3(src, n, i, MinVal);
	}
	_fOutComp2(Comp);	//�� �����
}
//���� ����
void _fBubbleSORT(int src[], int n) {
	puts("Bubble SORT Start");
	int Step = 0, Comp = 0;
	int tmp = 0;
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < (n-i); j++) {
			if (src[j] > src[j + 1]) {
				_fSwap(&src[j], &src[j + 1], j, j + 1);
				Comp++;
				_fOutComp(Comp);
				_fResult3(src, n, j, j + 1);
			}
		}
	}
	_fOutComp2(Comp);
}
//���� ����(mode1)
void _fInsertSORT(int src[], int n) {
	puts("Insert SORT Start");
	int Step = 0, Comp = 0, tmp = 0;
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (src[i] < src[j]) {	//������ ������
				_fSwap(&src[i], &src[j], i, j);
				Comp++;
				_fOutComp(Comp);
				_fResult3(src, n, j, i);
			}
		}
	}
	_fOutComp2(Comp);
}
//���� ����(mode2)
void _fInsertSORT2(int src[], int n) {
	//reverse loop
	puts("Insert SORT Start (MODE2)");
	int Step = 0, Comp = 0, tmp = 0;
	int trgIdx = 0;	//�����ؾ� �� ��ǥ index��
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (src[i] < src[j]) {	//���⼭ loop�� ������ �����鼭 �ڸ��� �ٲ۴�
				trgIdx = j;
			}	//comp ī������ ���� �ʴ´�.
		}
	}
}
//�� ����
void _fQuickSORT(int src[], int n, int Pv) {
	//P <...L...> T <...R...>
	//P <L> T <R> P <L> T <R>
	//P -> P : ���� �� �ʿ䰡 ����
	//T -> P : �������� �޶�����.
	// P L R
	// 2 1 3
	// P R L
	// 1 2 3
	// �ѱ��̰� 3�̸� ��
	// 3 �̸��̸� �� �� �ڸ� ��ȯ
	puts("Quick SORT Start");
	int Step = 0, Comp = 0, tmp = 0;
	//����Լ�
	int PV = Pv;	//�ǹ�
	int Left = Pv+1, Right = n;	//L,R
	int CNT = 0;	//ī����
	int Ltg = 0, Rtg = 0;	//trigger

	if (n == 2) {	//����Լ��� ���� �� �ʿ䰡 ���� ���...
		//_fSwap(&src[PV], &src[Left], );	//�̷��� Ư�� index���ƴ� 1 <--> 2�̷� ���Ĺۿ� �ȵ�
	}
	else if (n = 1) {

	}
	else {	//��� �Լ� ����
		while (1)
		{
			if (src[Left] < src[PV] && Ltg == 0) {	//left�� pv���� �۰� trg�� ��Ȱ��ȭ�� ���� �迭�� Ȯ��
				Left++;
			}
			else {	//�ƴϸ� Ʈ���� Ȱ��ȭ
				Ltg = 1;
			}
			if (src[Right] > PV) {
				Right--;
			}
			if ((Ltg == 1 && Rtg == 1) && Left < Right) {	//L,R Ʈ���Ű� ��� Ȱ��ȭ���...
				_fSwap(&src[Left], &src[Right], Left, Right);	//����� �Ǿ� �ִٸ� ��ȯ�Ѵ�.
			}
			else if (Left > Right) {
				_fSwap(&src[PV], &src[Right], PV, Right);	//L,R�� ���� ��� �Ͽ��ٸ� pv�� right�� �ٲ۴�.
				_fQuickSORT(&src[PV], Right-1, PV);	//pv�� �ֺ����� ����?? �ƹ�ư L�� ��Ȱ
				_fQuickSORT(&src[Left], n - Right, Left);
			}
			CNT++;
			if (CNT >= n) { //loop�� ���Ѽ��� �����ϱ� ���� ��ġ
				break;
			}
		}
	}
}
