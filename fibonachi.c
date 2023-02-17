#include <stdio.h>

// 피보나치 수열 재귀함수로 구현

int fib(int);

int main(void) {

	int number;

	printf("피보나치 수열, 숫자를 입력하세요..");
	scanf("%d", &number);

	printf("%d의 피보나치 수는 %d 입니다.\n", number, fib(number));

	return 0;
}

int fib(int n) {
	if (0 == n || 1 == n) {
		return n;
	}
	return fib(n - 1) + fib(n - 2);
}