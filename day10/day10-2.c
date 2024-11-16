#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <stdlib.h>
#include <string.h>

enum Rank {
	����� = 1, �ǹ�, ���, �÷�Ƽ��
};

struct Customer {
	char name[100];
	int point;
	int num;
	int orderAmount;
	int rank;
	struct Customer* link;
};

struct Customer* head = NULL;

int whatUp(int num1, int num2) {
	if (num1 > num2) {
		return 1;
	}
	else {
		return 0;
	}
}

int whoWhatUp(int num1, int num2) {
	if (num1 >= num2) {
		return 1;
	}
	else {
		return 0;
	}
}

struct Customer* create_node(char name[100], int num, int point, int orderAmount, int rank) {
	struct Customer* new_node = (struct Customer*)malloc(sizeof(struct Customer));
	strcpy(new_node->name, name);
	new_node->point = point;
	new_node->orderAmount = orderAmount;
	new_node->link = NULL;
	new_node->num = num;
	new_node->rank = rank;
	return new_node;
};


void insert_node(struct Customer* new_node) {
	struct Customer* last = head;

	int count = 0;
	printf("%x\n", last);
	while (last->link != NULL && whatUp(new_node->rank, last->link->rank) != 0) {
		last = last->link;
		count++;
	}
	printf("%x\n", last);

	while (last->link != NULL && whatUp(last->link->orderAmount, new_node->orderAmount) != 0 && whoWhatUp(new_node->rank, last->link->rank) != 0) {
		last = last->link;
	}
	printf("%x\n", last);
	while (last->link != NULL && whatUp(last->link->point, new_node->point) != 0 && whoWhatUp(last->link->orderAmount, new_node->orderAmount) != 0 && whoWhatUp(new_node->rank, last->link->rank) != 0) {
		last = last->link;
	}
	printf("%x\n", last);
	new_node->link = last->link;
	last->link = new_node;
}

void print_nodes() {
	struct Customer* cur = head->link;

	while (cur != NULL)
	{
		printf("%s : %d����Ʈ, �ֹ����� %d��, �� ��ȣ %d��, %d ���\n", cur->name, cur->point, cur->orderAmount, cur->num, cur->rank);
		cur = cur->link;
	}
	printf("----------------------------------------\n");
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
		if (cur->num == value) {
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
	int order;
	int point;
	int num;
	int inpRank;
	int delScore;
	char rankC = "";
	char name[100];
	enum Rank rank;


	head = (struct Customer*)malloc(sizeof(struct Customer));
	head->link = NULL;


	while (1) {
		
		printf("\n");
		printf("1. �� ���� �߰�\n");
		printf("2. �� ���� ����\n");
		printf("3. �� ���� ����\n");
		printf("4. �� ����Ʈ ���\n");
		printf("5. ���α׷� ����\n");
		printf("��� ���� �Է� : ");
		scanf_s("%d", &inp);

		switch (inp)
		{
		case 1:
			printf("�� �̸� : ");
			scanf_s("%s", name, sizeof(name));
			printf("%s�� �� ��ȣ : ", name);
			scanf_s("%d", &num);
			printf("%s�� ����Ʈ : ", name);
			scanf_s("%d", &point);
			printf("%s�� ���� �ֹ� ���� : ", name);
			scanf_s("%d", &order);
			printf("(�÷�Ƽ��:1, ���:2, �ǹ�:3, �����:4)\n%s�� ��ũ : ", name);
			scanf_s("%d", &inpRank);
			rank = inpRank;
			switch (rank)
			{
			case �����:
				rankC = 1;
				break;
			case �ǹ�:
				rankC = 2;
				break;
			case ���:
				rankC = 3;
				break;
			case �÷�Ƽ��:
				rankC = 4;
				break;
			default:
				break;
			}

			insert_node(create_node(name, num, point, order, rankC));
			printf("----------------------------------------\n");
			print_nodes();
			break;

		case 2:
			printf("����� ���� ���� �� ��ȣ�� �Է��ϼ��� : ");
			scanf_s("%d", &delScore);

			if (delete_node(delScore)) {
				printf("�ش� ���� ������ �����߽��ϴ�\n");
				printf("----------------------------------------\n");
				print_nodes();
			}
			else {
				printf("�ش� ���� �������� �ʽ��ϴ�\n");
			}
			break;

		case 3:
			printf("�����ϰ� ���� ���� �� ��ȣ�� �Է��ϼ��� : ");
			scanf_s("%d", &delScore);
			if (delete_node(delScore)) {
				printf("�ٲ� �� �̸� : ");
				scanf_s("%s", name, sizeof(name));
				printf("%s�� �ٲ� �� ��ȣ : ", name);
				scanf_s("%d", &num);
				printf("%s�� �ٲ� ����Ʈ : ", name);
				scanf_s("%d", &point);
				printf("%s�� �ٲ� ���� �ֹ� ���� : ", name);
				scanf_s("%d", &order);
				printf("(�÷�Ƽ��:1, ���:2, �ǹ�:3, �����:4)\n%s�� ��ũ : ", name);
				scanf_s("%d", &inpRank);
				rank = inpRank;
				switch (rank)
				{
				case �����:
					rankC = 1;
					break;
				case �ǹ�:
					rankC = 2;
					break;
				case ���:
					rankC = 3;
					break;
				case �÷�Ƽ��:
					rankC = 4;
					break;
				default:
					break;
				}

				insert_node(create_node(name, num, point, order, rankC));
				printf("----------------------------------------\n");
				print_nodes();
				break;
			}
			else {
				printf("�ش� ���� �������� �ʽ��ϴ�\n");
			}
			break;

		case 4:
			printf("----------------------------------------\n");
			print_nodes();
			break;

		case 5:
			printf("���α׷��� �����մϴ�\n");
			break;

		default:
			printf("�߸��� �Է��Դϴ�\n");
			break;
		}

		if (inp == 5) {
			break;
		}
	}

	return 0;
}