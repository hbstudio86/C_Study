#pragma warning(disable : 4996)

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define BUFSIZE 4096
#define SLEN 81
#define LEN 15

char* s_gets(char* st, int n);
void append(FILE* source, FILE* dest);
char* strEnd(char* str,int len);	//���ڿ� ���� �����߰�

int main(int argc, char *argv[]) {

	////Q1 ����� �������� ������� �ʰ� ������ ���� 
	////�ش� ���� �� ������ ������ ī���� �ϱ�
	//int ch;			//���� ����
	//FILE* fp;	//���� ������
	//unsigned long count = 0;
	//char f_name[40];	//���� �̸��� �����ϱ� ���� �迭
	//puts("���� �̸��� �Է��ϼ���");
	//scanf("%s", f_name);
	//if ((fp = fopen(f_name, "r")) == NULL) {
	//	puts("������ �����ϴ�. ���� �̸��� �� �� �Ǿ����ϴ�.");
	//	exit(EXIT_FAILURE);
	//}
	//
	//while ((ch = getc(fp)) != EOF) {	//���� ���� ���� �Ҷ����� ���ڸ� ����
	//	putc(ch, stdout);
	//	count++;
	//}
	//fclose(fp);
	//printf("%s�� ���Ͽ��� %ld���� ���ڰ� �ֽ��ϴ�.\n����\n", f_name, count);
	////�⺻���� ���� ������� ������ �˸� ���� �ذ� �� �� �ִ�.

	////Q2. �ҽ�����, Ÿ������ ��������� �޾� ���� ���� ���α׷� �ۼ�
	////argv[1]�� �ҽ�, argv[2]�� Ÿ�����Ϸ�
	////���̳ʸ� ����..
	//char ch;
	//FILE* fsrc, * ftrg;	//source����, target����
	//if (2 >= argc) { //������� ���ٸ�...
	//	puts("����� ���� ���ڰ� ���ų� �����մϴ�.");
	//	exit(EXIT_FAILURE);
	//}
	//if ((fsrc = fopen(argv[1], "rb")) == NULL) {
	//	puts("source ������ �����ϴ�.");
	//	exit(EXIT_FAILURE);
	//}
	//if ((ftrg = fopen(argv[2], "wb")) == NULL) {	//�ʿ� ������..
	//	puts("target ������ �����ϴ�.");
	//	exit(EXIT_FAILURE);
	//}
	//while (!feof(fsrc)) {		//eof�� �����ߴ��� Ȯ���ϴ� �Լ�
	//	//ch = getc(fsrc);
	//	ch = fgetc(fsrc);
	//	fputc(ch, ftrg);
	//}
	////fread(&ch, sizeof(char), 1, fsrc);	//1byte ������ �о�
	////fwrite(&ch, sizeof(char), 1, ftrg);	//1byte ������ ���
	//fclose(fsrc);
	//fclose(ftrg);

	////Q3. �ҽ������� �޾Ƽ� Ÿ�����Ͽ� ���� �� ��� �빮�ڷ� �־��
	//char ch;
	//char src[40];
	//char trg[40];
	//FILE* fsrc, * ftrg;
	//puts("source file�� �Է��ϼ���");
	//printf(">>");
	//scanf("%s", src);
	//while (getchar() != '\n')
	//	continue;
	//puts("target file�� �Է��ϼ���");
	//printf(">>");
	//scanf("%s", trg);
	//while (getchar() != '\n')
	//	continue;
	////scanf("%s %s",src,trg)�� �������� ������ �ִ�
	//if ((fsrc = fopen(src, "r")) == NULL) {
	//	puts("source ������ �����ϴ�.");
	//	exit(EXIT_FAILURE);
	//}
	//if ((ftrg = fopen(trg, "w")) == NULL) {
	//	puts("source ������ �����ϴ�.");
	//	exit(EXIT_FAILURE);
	//}
	//while (!feof(fsrc)) {
	//	ch = fgetc(fsrc);
	//	//toupper(ch);
	//	fputc(toupper(ch), ftrg);
	//}
	//fclose(fsrc);
	//fclose(ftrg);

	////Q4.����� �����ϴ� ��� ������ ���ʴ�� ȭ�鿡 ���
	//if (1 == argc) {	//����� �������ڰ� ���� ���ٸ�...
	//	puts("����� �������� �׸��� ��� �ֽ��ϴ�.");
	//	return 0;
	//}
	//else {
	//	FILE* fp;
	//	char fName[40];	//�����̸� ����
	//	int ch;
	//	for (int i = 1; i < argc; i++) {
	//		strcpy(fName, argv[i]);	//���� �̸��� ���� �Ѵ�.
	//		if ((fp = fopen(fName, "r")) == NULL) {	//���ٸ� ���ٰ� �˷��ش�.
	//			printf("%s ������ �����ϴ�.\n", argv[i]);
	//		}
	//		else {
	//			while (!(feof(fp))) {
	//				ch = fgetc(fp);
	//				putc(ch, stdout);
	//			}
	//			fclose(fp);	//���� ��Ʈ���� �ݴ´�.
	//		}
	//		putc('\n', stdout);
	//	}
	//}
	//puts("����");

	////Q5. 13.5�� ���α׷� ����/ ����� �Է� ���
	//FILE* fa, * fs;
	//char file_src[SLEN];
	//char file_app[SLEN];	//�ʿ� ����
	//int ch;
	//int files = 0;
	////����� ���� 2�� �Է� ������ ��ó��
	//if (argc == 1 || argc == 2) {
	//	puts("����� ���ڸ� ����� �Է����� �ʾҽ��ϴ�.");
	//	exit(EXIT_FAILURE);
	//}   
	//else {
	//	puts("���� ������ �̸��� �ԷµǾ����ϴ�.");
	//	printf("file name : %s\n", argv[1]);	//����� �Է����� ó��
	//	//�������� ���� ��
	//	if ((fa = fopen(argv[1], "a+")) == NULL) {
	//		fprintf(stderr, "������ ���� �����ϴ�.%s\n", argv[1]);
	//		exit(EXIT_FAILURE);
	//	}	
	//	//����� ���۸� ������
	//	if (setvbuf(fa, NULL, _IOFBF, BUFSIZE) != 0) {
	//		fputs("��� ���۸� ������ �� �����ϴ�.\n", stderr);
	//		exit(EXIT_FAILURE);
	//	}	
	//	//������ �̿��� �ҽ� ������ ���� �´�.
	//	for (int i = 2; i < argc; i++) {
	//		printf("%d��° �ҽ� ���� %s�� �ҷ� �ɴϴ�.\n", i - 1, argv[i]);
	//		if (strcmp(argv[1], argv[i]) == 0) {
	//			fputs("�ڱ� �ڽſ��Դ� ������ �� �����ϴ�.\n", stderr);
	//		}
	//		else if ((fs = fopen(argv[i], "r")) == NULL) {
	//			fprintf(stderr, "���� %s�� ���� �����ϴ�.\n", argv[i]);
	//		}
	//		else {
	//			if (setvbuf(fs, NULL, _IOFBF, BUFSIZE) != 0) {
	//				fputs("�Է� ���۸� ������ �� �����ϴ�.\n", stderr);
	//				continue;
	//			}
	//			append(fs, fa);
	//			if (ferror(fs) != 0)
	//				fprintf(stderr, "������ �д� �� ������ �߻��Ͽ����ϴ�.%s.\n", argv[i]);
	//			if (ferror(fa) != 0)
	//				fprintf(stderr, "������ ���� �� ������ �߻��Ͽ����ϴ�.%s.\n", argv[1]);
	//			fclose(fs);
	//			files++;
	//			printf("%s ������ ������ �� �ٿ����ϴ�.\n", argv[i]);
	//			puts("���� �ҽ� ������ �̸��� �Է��մϴ�.");
	//		}
	//	}
	//	printf("����. %d���� ������ ���ٿ����ϴ�.\n", files);
	//	rewind(fa);
	//	printf("%s ����:\n", argv[1]);
	//	while ((ch = getc(fa)) != EOF) {
	//		putchar(ch);
	//	}
	//	puts("���� ��Ÿ����.");
	//	fclose(fa);

	////q6 13.2 �ڵ带 ��ȭ�������� �����
	////q6 �켱 ���� �ڵ带 �����ϱ� ���� ���� �Ẹ��
	////������ 2/3���� �����Ѵ�??!!
	//FILE* in, * out;
	//int ch;
	//char inname[LEN];
	//char outname[LEN];
	//int count = 0;
	////����� �������ڸ� �˻��Ѵ�.
	//puts("������ ���� ���� ���α׷��Դϴ�.");
	//puts("���� �� ���ϸ��� �Է��ϼ���");
	//printf("File name>> ");
	//fgets(inname, 14, stdin);
	//for (int i = 0; i < LEN; i++) {
	//	if (inname[i] == '\n') {
	//		inname[i] = '\0';
	//		break;
	//	}
	//}
	//if ((in = fopen(inname, "r")) == NULL) {
	//	fprintf(stderr, "%s ������ �о� �� �� �����ϴ�.\n", inname);
	//	exit(EXIT_FAILURE);
	//}
	//strncpy(outname, inname, LEN - 5);	//Ȯ���ڱ��� ���ϸ����� �ϰڴٴ� ���ΰ�>
	////printf("%s", outname);
	//outname[LEN - 5] = '\0';
	//strcat(outname, ".red");	//Ȯ���ڸ� ���δ�.
	//if ((out = fopen(outname, "w")) == NULL) {	//���� ����
	//	fprintf(stderr, "%s ������ ������ �� �����ϴ�.\n", outname);
	//	exit(EXIT_FAILURE);
	//}
	//while ((ch = fgetc(in)) != EOF) {
	//	if ((count++ % 3) == 0) {
	//		putc(ch, out);
	//	}
	//}
	//if (fclose(in) != 0 || fclose(out) != 0) {
	//	fprintf(stderr, "������ �ݴµ� ������ �����\n");
	//	exit(EXIT_FAILURE);
	//}
	////�ı� : �������� �ؼ� �� �ð��� �ɷ�����, �׷��� ���� �ذ��� ����

	////q7. �� ���� ���� ���
	////argv[1]�� ù��° ����, argv[2] �ι�° ����
	//FILE* ff, * sf;	//ff = first file, sf = second file
	//char fFile[LEN];
	//char sFile[LEN];
	//char Strings[SLEN];
	//unsigned int str_lens;
	////int _iEOF ;
	//if (argc == 1) {	//���� ������� �Էµ��� �ʾҴٸ�... ����ڿ��Լ� �Է��� �޵��� �Ѵ�.
	//	puts("����� �������ڰ� �Էµ��� �ʾҽ��ϴ�.");
	//	puts("ù ��° �����̸��� �Է��ϼ���");
	//	s_gets(fFile, LEN);
	//	puts("�� ��° �����̸��� �Է��ϼ���");
	//	s_gets(sFile, LEN);
	//}
	//else {	//�Է��� �ϳ��� �޴°��� ���ٰ� �����Ѵ�.
	//}
	//if ((ff = fopen(fFile, "r")) == NULL) {
	//	puts("ù ��° File�� �����ϴ�.");
	//	exit(EXIT_FAILURE);
	//}
	//else if ((sf = fopen(sFile, "r")) == NULL) {
	//	puts("�� ��° File�� �����ϴ�.");
	//	exit(EXIT_FAILURE);
	//}
	//else {
	//	while (1) {
	//		//_iEOF = feof(ff);	//feof�� eof�� ������ 0�� �ƴ� ���� return �Ѵ�.
	//		//if (!feof(ff)) {
	//		//	//fputs(Strings, ff);
	//		//	fgets(Strings, SLEN - 1, ff);	//�о� �´�
	//		//	fprintf(stdout, "%s", Strings);
	//		//}
	//		//else if (!feof(sf)) {
	//		//	fgets(Strings, SLEN - 1, sf);
	//		//	fprintf(stdout, "%s", Strings);
	//		//}
	//		//�̺κ��� ������
	//		//if ((_iEOF = fgets(Strings, SLEN - 1, ff) != EOF)) {
	//		//	fprintf(stdout, "%s", Strings);
	//		//}
	//		//else {
	//		//	break;
	//		//}
	//		if (!feof(ff)) {
	//			fgets(Strings, SLEN - 1, ff);
	//			//s_gets(Strings, SLEN);
	//			//fprintf(stdout, "%s\n", Strings);
	//			str_lens = strlen(Strings);
	//			strEnd(Strings, str_lens);
	//			fputs(Strings, stdout);	//���������� ������ �ȵǳ�?
	//			memset(Strings, '\n', sizeof(char) * SLEN);
	//		}
	//		if (!feof(sf)) {
	//			fgets(Strings, SLEN - 1, sf);
	//			//s_gets(Strings, SLEN);
	//			//fprintf(stdout, "%s\n", Strings);
	//			str_lens = strlen(Strings);
	//			strEnd(Strings, str_lens);
	//			fputs(Strings, stdout);
	//			memset(Strings, '\n', sizeof(char) * SLEN);
	//		}
	//		if (feof(ff) && feof(sf)) {
	//			break;
	//		}
	//	}
	//}
	//fclose(ff);
	//fclose(sf);
	//�ı� : 

	// Q8. 
	// 1. �ϳ��� ���ڿ� ���� �̸����� �Է� �޴´�.
	// 2. ���� �̸��� �Էµ��� �ʴ´ٸ� ����ڿ��� �Է��� ���� �˷���� �Ѵ�.
	// 3. ���� �̸��� �ԷµǸ� �ش� ���Ͽ��� �Էµ� ���ڰ� �� �� ���Ǿ����� ���� �ؾ� �Ѵ�.
	// 4. ���� �̸�, ����, ���� Ƚ���� ���� ǥ�� �ǵ��� �Ѵ�.
	// 5. ���� ������ ������ ��Ȯ����, ���ϵ��� ����� ���ȴ��� �˷��ִ� ���� üŷ �ڵ带 ���� �� ��.
	// 6. ������ ���� ������, �� ����� ����ϰ� ���� ���Ϸ� �Ѿ� ����.
	// ����� �������ڷ� ���ڿ� �����̸��� ���޹ޱ�
	if (1 == argc) {	//���� ����� �������ڰ� �⺻(�����α׷�)�̶��...
		puts("����� �������ڰ� �����ϴ�.\n����� �Է��� �޽��ϴ�...");
	}

	return 0;
}


char* s_gets(char* st, int n) {
	char* ret_val;
	char* find;

	ret_val = fgets(st, n, stdin);
	if (ret_val) {
		find = strchr(st, '\n');
		if (find)
			*find = '\0';
		else
			while (getchar() != '\n')
				continue;
	}
	return ret_val;
}
void append(FILE* source, FILE* dest) {
	size_t bytes;
	static char temp[BUFSIZE];

	while ((bytes = fread(temp, sizeof(char), BUFSIZE, source)) > 0)
		fwrite(temp, sizeof(char), bytes, dest);
}

//���ڿ� ���� ���� �߰�
char* strEnd(char* str, int len) {

	//ó������ ������ �����°��� �ƴ϶� 
	//���������� ������ ������ �ٷ� ������ �������� ���θ� �Ǵ��ϸ� �ȴ�.
	if (str[len - 1] != '\n') {		//���� ������ �ƴ϶��...
		str[len] = '\n';			//���� �������� ���ְ�
		str[len + 1] = '\0';		//�� ������ �ι��ڷ� ���ش�.
	}

	return str;
}
