#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <stdlib.h>
#include <string.h>


struct NODE {
	char name[100];
	int data;
	struct NODE* link;
};

struct NODE* head = NULL;

int comp(int num1, int num2) {
	if (num1 < num2) {
		return 1;
	}
	else {
		return 0;
	}
}

struct NODE* create_node(char name[100], int data) {
	struct NODE* new_node = (struct NODE*)malloc(sizeof(struct NODE));
	strcpy(new_node->name, name);
	new_node->data = data;
	new_node->link = NULL;
	return new_node;
};

struct NODE* last_node() {
	struct NODE* cur = head;
	while (cur->link != NULL) {
		cur = cur->link;
	}
	return cur;
}

void insert_node(struct NODE* new_node) {
	struct NODE* last = head;
	while (last->link != NULL && comp(new_node->data, last->link->data) != 0) {
		last = last->link;
	}

	new_node->link = last->link;
	last->link = new_node;
}

void print_nodes() {
	struct NODE* cur = head->link;
	while (cur != NULL)
	{
		printf("%s : %d\n", cur->name, cur->data);
		cur = cur->link;
	}
}

struct NODE* find_node(int value)
{
	struct NODE* cur = head->link;
	while (cur != NULL) {
		if (cur->data == value) return cur;

		cur = cur->link;
	}
	return NULL;
}

int delete_node(int value)
{
	struct NODE* prev = head;
	struct NODE* cur = head->link;
	while (cur != NULL) {
		if (cur->data == value) {
			prev->link = cur->link;
			free(cur);
			return 1;
		}
		prev = cur;
		cur = cur->link;
	}
	return 0;
}


int main() {
	int inp;
	int score;
	char name[100];
	int delScore;


	head = (struct NODE*)malloc(sizeof(struct NODE));
	head->link = NULL;


	while (1) {
		printf("----------------------------------------\n");
		printf("\n");
		printf("1. 학생의 성적 입력\n");
		printf("2. 학생 성적 제거\n");
		printf("3. 프로그램 종료\n");
		printf("명령 숫자 입력 : ");
		scanf_s("%d", &inp);

		switch (inp)
		{
		case 1:
			printf("학생 이름 : ");
			scanf_s("%s", name, sizeof(name));
			printf("%s의 성적 : ", name);
			scanf_s("%d", &score);

			insert_node(create_node(name, score));
			printf("----------------------------------------\n");
			print_nodes();
			break;

		case 2:
			printf("지우고 싶은 학생의 점수를 입력하세요 : ");
			scanf_s("%d", &delScore);
			

			if (delete_node(delScore)) {
				printf("해당 학생의 정보를 삭제했습니다\n");
				printf("----------------------------------------\n");
				print_nodes();
			}
			else {
				printf("해당 학생은 존재하지 않습니다\n");
			}
			break;

		case 3:
			printf("프로그램을 종료합니다\n");
			break;

		default:
			printf("잘못된 입력입니다\n");
			break;
		}

		if (inp == 3) {
			break;
		}
	}

	return 0;
}