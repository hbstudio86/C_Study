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
void _fResult2(int[], int);
void _fResult3(int[], int, int, int);	//확인용3
void _fSwap(int*, int*,int,int);			//SWAP
void _fOutComp(int);
void _fOutComp2(int);	//결과 출력용
void _fSelectSORT(int[], int);	//선택 정렬
void _fBubbleSORT(int[], int);	//버블 정렬
void _fInsertSORT(int[], int);	//삽입 정렬#1
void _fInsertSORT2(int[], int);	//삽입 정렬#2

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
		puts("3.Insert SORT");
		puts("0.Program END");
		scanf("%d", &_iCommand);
		//원본을 보존하고 복사본으로 정렬합니다.
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

//확인용1:정렬 전/후 비교
void _fResult(int bf[], int af[], int n) {
	for (int i = 0; i < n; i++) {
		printf("[%02d] %6d | %6d \n", i, bf[i], af[i]);
	}
}
//확인용2:배열 출력용
void _fResult2(int ar[], int n) {
	for (int i = 0; i < n; i++) {
		printf("[%02d] %6d \n", i, ar[i]);
	}
}
//확인용3:시각화
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

//교환용
void _fSwap(int* src1, int* src2,int bn, int an) {
	puts("!SWAP!");
	printf("[%d]<---->[%d]\n", bn, an);
	int tmp = *src2;
	*src2 = *src1;
	*src1 = tmp;
}

//내용 출력용: 교환된 내용을 출력 한다
void _fOutComp(int comp) {
	printf("Select SORT Result: Compare_%d\n", comp);
}

//내용 출력용2: 모든 결과를 출력 한다
void _fOutComp2(int comp) {
	puts("===== Result =====");
	printf("*Result: Total Swap = %d\n", comp);
	puts("=====  END   =====");
}
//선택정렬
void _fSelectSORT(int src[],  int n) {
	puts("Select SORT Start");
	int Step = 0, Comp = 0; //step수와 비교 횟수를 표시
	int MinVal;					//index 번호를 저장
	int tmp = 0;	//임시 변수, 최소값 교환을 위해 사용
	for (int i = 0; i < n; i++) {
		MinVal = i;	//index 번호는 최대한 갱신
		for (int j = 1 + i; j < n; j++) {
			if (src[MinVal] > src[j]) {
				MinVal = j;	//최소값이면 그값의 index번호를 저장
			}
		}
		//1회전이 끝나면..교환이 이루어 진다.
		if (src[i] != src[MinVal]) {	//교환이 이루어 졌을 때만 comp와 swap이 이루어 진다.
			_fSwap(&src[i], &src[MinVal], i, MinVal);
			Comp++;	//swap cnt를 따로 빼야 한다????? 왜냐 이건 비교 카운트라 그렇다
		}
		_fOutComp(Comp);
		_fResult3(src, n, i, MinVal);
	}
	_fOutComp2(Comp);	//총 결과값
}
//버블 정렬
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
//삽입 정렬(mode1)
void _fInsertSORT(int src[], int n) {
	puts("Insert SORT Start");
	int Step = 0, Comp = 0, tmp = 0;
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (src[i] < src[j]) {	//작으면 앞으로
				_fSwap(&src[i], &src[j], i, j);
				Comp++;
				_fOutComp(Comp);
				_fResult3(src, n, j, i);
			}
		}
	}
	_fOutComp2(Comp);
}
//삽입 정렬(mode2)
void _fInsertSORT2(int src[], int n) {
	//reverse loop
	puts("Insert SORT Start (MODE2)");
	int Step = 0, Comp = 0, tmp = 0;
	int trgIdx = 0;	//삽입해야 할 목표 index값
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (src[i] < src[j]) {
				trgIdx = j;
			}
		}
	}
}
