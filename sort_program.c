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
void _fSelectSORT(int[], int);	//���� ����
void _fBubbleSORT(int[], int);	//���� ����

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
		puts("0.Program END");
		scanf("%d", &_iCommand);
		//������ �����ϰ� ���纻���� �����մϴ�.
		switch (_iCommand)
		{
		case 1:
			_fSelectSORT(_iParr2, _iArrSize);
			break;
		case 2:
			_fBubbleSORT(_iParr2, _iArrSize);
			break;
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

//Ȯ�ο�:���� ��/�� ��
void _fResult(int bf[], int af[], int n) {
	for (int i = 0; i < n; i++) {
		printf("[%02d] %06d | %06d \n", i, bf[i], af[i]);
	}
}

//��������
void _fSelectSORT(int src[],  int n) {
	puts("Select SORT Start");
	int Step = 0, Comp = 0; //step���� �� Ƚ���� ǥ��
	//int MinVal = src[0];		//�ּҰ� ����, �迭 ù ����� ���� ��
	int MinVal;					//index ��ȣ�� ����
	int tmp = 0;	//�ӽ� ����, �ּҰ� ��ȯ�� ���� ���
	for (int i = 0; i < n; i++) {
		MinVal = i;	//index ��ȣ�� �ִ��� ����
		for (int j = 1 + i; j < n; j++) {
			if (src[MinVal] > src[j]) {
				MinVal = j;	//�ּҰ��̸� �װ��� index��ȣ�� ����
			}
			Comp++;
		}
		//1ȸ���� ������..��ȯ�� �̷�� ����.
		tmp = src[i];
		src[i] = src[MinVal];
		src[MinVal] = tmp;
	}
	printf("Select SORT Result: Compare_%d\n", Comp);
}

void _fBubbleSORT(int src[], int n) {

}