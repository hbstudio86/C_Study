#include <stdio.h>

// �Ǻ���ġ ���� ����Լ��� ����

int fib(int);

int main(void) {

	int number;

	printf("�Ǻ���ġ ����, ���ڸ� �Է��ϼ���..");
	scanf("%d", &number);

	printf("%d�� �Ǻ���ġ ���� %d �Դϴ�.\n", number, fib(number));

	return 0;
}

int fib(int n) {
	if (0 == n || 1 == n) {
		return n;
	}
	return fib(n - 1) + fib(n - 2);
}