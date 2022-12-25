#pragma warning (disable:6031)
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <memory.h>

#define LOWLIMIT 5
#define UPLIMIT 30


//###함수 선언###
int _fCheck(int*);
void _fSelectSORT(int*, int*, int);	//선택 정렬

int main(void) {

	//변수 선언
	int _iArrSize;
	int _iCommand = 0;	//입력 command
	int* _iParr;
	int* _iParr2;	//옮겨 담은 배열
	srand(time(NULL));	//시드 

	//처리
	printf("SORT TEST Program\nArray의 Size를 정하세요..:___(%d~%d)\b\b\b\b\b\b\b\b\b",LOWLIMIT,UPLIMIT);
	scanf("%d", &_iArrSize);
	getchar();
	_iArrSize = _fCheck(&_iArrSize);
	_iParr = (int*)malloc(sizeof(int) * _iArrSize);	//입력한 크기 만큼 동적 배열 할당
	_iParr2 = (int*)malloc(sizeof(int) * _iArrSize);	//옮겨 담을 배열
	memset(_iParr2, 0, sizeof(int) * _iArrSize);			//0으로 초기화
	printf("%d\n", sizeof(int) * _iArrSize);
	//만약 malloc 함수가 실패한다면...
	if (NULL == _iParr) {
		free(_iParr);
		exit(EXIT_FAILURE);
	}
	////동적 할당한 배열에 값 넣기
	else {
		for (int i = 0; i < _iArrSize; i++) {
			_iParr[i] = rand();
			printf("[%02d] %06d | %06d\n", i, _iParr[i], _iParr2[i]);
		}
	}

	do {
		printf("\n======= SELECT of SORT Program =======\n");
		puts("1.Select SORT");
		puts("0.Program END");
		scanf("%d", &_iCommand);
		switch (_iCommand)
		{
		case 1:
			_fSelectSORT(_iParr, _iParr2, _iArrSize);
			break;
		default:
			break;
		}
	} while (_iCommand != 0);

	//출력
	free(_iParr);
	puts("종료");

	return 0;
}

//###함수 정의###
//입력 배열 크기 체크
int _fCheck(int* input) {
	while (*input < LOWLIMIT || *input > UPLIMIT)
	{
		printf("입력한 값%d이/가 %d에서 %d 범위를 벗어 났습니다.\n다시 입력하세요:___\b\b\b", *input, LOWLIMIT, UPLIMIT);
		scanf("%d", input);
	}
	return *input;
}
//선택정렬
void _fSelectSORT(int *ar1, int *ar2, int n) {
	puts("Select SORT Start");
	int Step = 0;		//스텝수
	int Comp = 0;		//비교
	int End = 0;		//완료
	int Min = 0;		//0으로 초기화
	int MinIdx = 0;		//가장 작은 배열의 index 번호를 저장
	for (int i = 0; i < n; i++) {
		Min = ar1[i];	//첫 배열의 값으로 최소 값을 초기화
		for (int j = End; j < n; j++) {
			if (ar1[j] < Min) {	//만약 현재 배열이 제일 작다면...
				MinIdx = j;		//제일 작은 배열값을 저장
				Min = ar1[j];	//min값을 갱신
			}
		}
		ar2[End] = ar1[MinIdx];
		End++;

	}
}