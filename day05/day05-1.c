#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
	int snum;
	char name[100];
	int score;
};


int main() {

	int n;
	struct Student person[2];

	person[0].snum = 1111;
	strcpy_s(person[0].name, 100, "ö��");
	person[0].score = 100;

	printf("%d %s %d\n", person[0].snum, person[0].name, person[0].score);
	
	/*
	int* snum;
	char** name;
	int* score;

	printf("�л��� �� ���ΰ� : ");
	scanf_s("%d", &n);

	snum = (int*)malloc(n * sizeof(int));
	score = (int*)malloc(n * sizeof(int));
	name = (char**)malloc(n * sizeof(char*));

	for (int i = 0; i < n; i++) {
		name[i] = (char*)malloc(100 * sizeof(char));
	}

	for (int i = 0; i < n; i++) {
		printf("�й� : ");
		scanf_s("%d", &snum[i]);
		printf("�̸� : ");
		scanf_s("%s", name[i], 100);
		printf("���� : ");
		scanf_s("%d", &score[i]);
	}
	
	for (int i = 0; i < n; i++) {
		printf("%d %s %d\n", snum[i], name[i], score[i]);
	}

	free(snum);
	free(score);
	for (int i = 0; i < n; i++) {
		free(name[i]);
	}
	*/
	return 0;
}