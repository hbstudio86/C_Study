#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// 1. 학생 시험 점수 검색
typedef struct _student {
	char name[20];
	int score;
}Student;
int main(void) {
	int names_len = 5;
	int score_len = 5;
	char tmpname[][6] = { "lukas","james","levi","eli","max" };
	char** names;
	names = (char**)malloc(sizeof(char*) * names_len);
	for (int i=0; i < names_len; i++) {
		names[i] = (char*)malloc(sizeof(char) * 15);
		strcpy(names[i], tmpname[i]);
	}
	for (int i=0; i < 5; i++) {
		printf("%s\n", names[i]);
	}
	return 0;
}