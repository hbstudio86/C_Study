#pragma warning (disable:6031)
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <memory.h>

#define LOWLIMIT 5
#define UPLIMIT 30


//###�Լ� ����###
int _fCheck(int*);
void _fSelectSORT(int[], int[], int);	//���� ����

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
	memset(_iParr2, 0, sizeof(int) * _iArrSize);			//0���� �ʱ�ȭ
	printf("%d\n", sizeof(int) * _iArrSize);
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

	do {
		printf("\n======= SELECT of SORT Program =======\n");
		scanf("%d", &_iCommand);
		switch (_iCommand)
		{
		case 1:
			//_fSelectSORT();
			break;
		default:
			break;
		}
	} while (_iCommand != 0);

	//���
	free(_iParr);
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
//��������
void _fSelectSORT(int ar1[], int ar2[], int n) {

}