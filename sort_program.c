#pragma warning (disable:6031)
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LOWLIMIT 5
#define UPLIMIT 30


//###�Լ� ����###
int _fCheck(int*);

int main(void) {

	//���� ����
	int _iArrSize;
	int* _iParr;
	srand(time(NULL));	//�õ� 

	//ó��
	printf("SORT TEST Program\nArray�� Size�� ���ϼ���..:___(%d~%d)\b\b\b\b\b\b\b\b\b",LOWLIMIT,UPLIMIT);
	scanf("%d", &_iArrSize);
	getchar();
	_iArrSize = _fCheck(&_iArrSize);
	_iParr = (int*)malloc(sizeof(int) * _iArrSize);	//�Է��� ũ�� ��ŭ ���� �迭 �Ҵ�
	//���� malloc �Լ��� �����Ѵٸ�...
	if (NULL == _iParr) {
		free(_iParr);
		exit(EXIT_FAILURE);
	}
	else {
		for (int i = 0; i < _iArrSize; i++) {
			_iParr[i] = rand();
			printf("[%02d] %06d\n", i, _iParr[i]);
		}
	}
	////���� �Ҵ��� �迭�� �� �ֱ�

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