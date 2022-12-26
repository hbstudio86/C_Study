#pragma warning (disable:6031)
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <memory.h>

#define LOWLIMIT 5
#define UPLIMIT 30


//###함수 선언###
int _fCheck(int*);
void _fResult(int[], int[], int);	//정렬후 값 출력용
void _fSelectSORT(int[], int);	//선택 정렬
void _fBubbleSORT(int[], int);	//버블 정렬

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
	if (_iParr2 != NULL) {		//메모리가 제대로 할당되었다면...	삭제해도 된다.
		memset(_iParr2, 0, sizeof(int) * _iArrSize);			//0으로 초기화
	}
	else {	//메모리 할당 실패시
		puts("메모리 할당에 실패하였습니다. 프로그램을 종료합니다.");
		free(_iParr2);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", sizeof(int) * _iArrSize);	//삭제 해도 된다.
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
	memcpy(_iParr2, _iParr, sizeof(int) * _iArrSize);	//원본을 저장하고 복사본을 만듭니다.

	do {
		printf("\n======= SELECT of SORT Program =======\n");
		puts("1.Select SORT");
		puts("2.Bubble SORT");
		puts("0.Program END");
		scanf("%d", &_iCommand);
		//원본을 보존하고 복사본으로 정렬합니다.
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
		memcpy(_iParr2, _iParr, sizeof(int) * _iArrSize);	//원본을 저장하고 복사본을 만듭니다.
	} while (_iCommand != 0);

	//출력
	free(_iParr);
	free(_iParr2);
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

//확인용:정렬 전/후 비교
void _fResult(int bf[], int af[], int n) {
	for (int i = 0; i < n; i++) {
		printf("[%02d] %06d | %06d \n", i, bf[i], af[i]);
	}
}

//선택정렬
void _fSelectSORT(int src[],  int n) {
	puts("Select SORT Start");
	int Step = 0, Comp = 0; //step수와 비교 횟수를 표시
	//int MinVal = src[0];		//최소값 저장, 배열 첫 멤버를 저장 함
	int MinVal;					//index 번호를 저장
	int tmp = 0;	//임시 변수, 최소값 교환을 위해 사용
	for (int i = 0; i < n; i++) {
		MinVal = i;	//index 번호는 최대한 갱신
		for (int j = 1 + i; j < n; j++) {
			if (src[MinVal] > src[j]) {
				MinVal = j;	//최소값이면 그값의 index번호를 저장
			}
			Comp++;
		}
		//1회전이 끝나면..교환이 이루어 진다.
		tmp = src[i];
		src[i] = src[MinVal];
		src[MinVal] = tmp;
	}
	printf("Select SORT Result: Compare_%d\n", Comp);
}

void _fBubbleSORT(int src[], int n) {

}