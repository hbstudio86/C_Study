#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

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

	//Q4.����� �����ϴ� ��� ������ ���ʴ�� ȭ�鿡 ���

	return 0;
}