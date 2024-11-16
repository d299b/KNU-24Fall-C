#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <stdlib.h>
#include <string.h>


struct Customer {
	char name[100];
	int point;
	struct Customer* link;
};

struct Customer* head = NULL;

int whatUp(int num1, int num2) {
	if (num1 < num2) {
		return 1;
	}
	else {
		return 0;
	}
}

struct Customer* create_node(char name[100], int data) {
	struct Customer* new_node = (struct Customer*)malloc(sizeof(struct Customer));
	strcpy(new_node->name, name);
	new_node->point = data;
	new_node->link = NULL;
	return new_node;
};

struct Customer* last_node() {
	struct Customer* cur = head;
	while (cur->link != NULL) {
		cur = cur->link;
	}
	return cur;
}

void insert_node(struct Customer* new_node) {
	struct Customer* last = head;
	while (last->link != NULL && whatUp(new_node->point, last->link->point) != 0) {
		last = last->link;
	}

	new_node->link = last->link;
	last->link = new_node;
}

void print_nodes() {
	struct Customer* cur = head->link;
	while (cur != NULL)
	{
		printf("%s : %d\n", cur->name, cur->point);
		cur = cur->link;
	}
}

struct Customer* find_node(int value)
{
	struct Customer* cur = head->link;
	while (cur != NULL) {
		if (cur->point == value) return cur;

		cur = cur->link;
	}
	return NULL;
}

int delete_node(int value)
{
	struct Customer* prev = head;
	struct Customer* cur = head->link;
	while (cur != NULL) {
		if (cur->point == value) {
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


	head = (struct Customer*)malloc(sizeof(struct Customer));
	head->link = NULL;


	while (1) {
		printf("----------------------------------------\n");
		printf("\n");
		printf("1. �л��� ���� �Է�\n");
		printf("2. �л� ���� ����\n");
		printf("3. ���α׷� ����\n");
		printf("��� ���� �Է� : ");
		scanf_s("%d", &inp);

		switch (inp)
		{
		case 1:
			printf("�л� �̸� : ");
			scanf_s("%s", name, sizeof(name));
			printf("%s�� ���� : ", name);
			scanf_s("%d", &score);

			insert_node(create_node(name, score));
			printf("----------------------------------------\n");
			print_nodes();
			break;

		case 2:
			printf("����� ���� �л��� ������ �Է��ϼ��� : ");
			scanf_s("%d", &delScore);


			if (delete_node(delScore)) {
				printf("�ش� �л��� ������ �����߽��ϴ�\n");
				printf("----------------------------------------\n");
				print_nodes();
			}
			else {
				printf("�ش� �л��� �������� �ʽ��ϴ�\n");
			}
			break;

		case 3:
			printf("���α׷��� �����մϴ�\n");
			break;

		default:
			printf("�߸��� �Է��Դϴ�\n");
			break;
		}

		if (inp == 3) {
			break;
		}
	}

	return 0;
}