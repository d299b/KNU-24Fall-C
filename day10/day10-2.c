#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <stdlib.h>
#include <string.h>

enum Rank {
	브론즈 = 1, 실버, 골드, 플래티넘
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
		printf("%s : %d포인트, 주문수량 %d개, 고객 번호 %d번, %d 등급\n", cur->name, cur->point, cur->orderAmount, cur->num, cur->rank);
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
		printf("1. 고객 정보 추가\n");
		printf("2. 고객 정보 제거\n");
		printf("3. 고객 정보 수정\n");
		printf("4. 고객 리스트 출력\n");
		printf("5. 프로그램 종료\n");
		printf("명령 숫자 입력 : ");
		scanf_s("%d", &inp);

		switch (inp)
		{
		case 1:
			printf("고객 이름 : ");
			scanf_s("%s", name, sizeof(name));
			printf("%s의 고객 번호 : ", name);
			scanf_s("%d", &num);
			printf("%s의 포인트 : ", name);
			scanf_s("%d", &point);
			printf("%s의 물건 주문 수량 : ", name);
			scanf_s("%d", &order);
			printf("(플래티넘:1, 골드:2, 실버:3, 브론즈:4)\n%s의 랭크 : ", name);
			scanf_s("%d", &inpRank);
			rank = inpRank;
			switch (rank)
			{
			case 브론즈:
				rankC = 1;
				break;
			case 실버:
				rankC = 2;
				break;
			case 골드:
				rankC = 3;
				break;
			case 플래티넘:
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
			printf("지우고 싶은 고객의 고객 번호를 입력하세요 : ");
			scanf_s("%d", &delScore);

			if (delete_node(delScore)) {
				printf("해당 고객의 정보를 삭제했습니다\n");
				printf("----------------------------------------\n");
				print_nodes();
			}
			else {
				printf("해당 고객은 존재하지 않습니다\n");
			}
			break;

		case 3:
			printf("수정하고 싶은 고객의 고객 번호를 입력하세요 : ");
			scanf_s("%d", &delScore);
			if (delete_node(delScore)) {
				printf("바꿀 고객 이름 : ");
				scanf_s("%s", name, sizeof(name));
				printf("%s의 바꿀 고객 번호 : ", name);
				scanf_s("%d", &num);
				printf("%s의 바꿀 포인트 : ", name);
				scanf_s("%d", &point);
				printf("%s의 바꿀 물건 주문 수량 : ", name);
				scanf_s("%d", &order);
				printf("(플래티넘:1, 골드:2, 실버:3, 브론즈:4)\n%s의 랭크 : ", name);
				scanf_s("%d", &inpRank);
				rank = inpRank;
				switch (rank)
				{
				case 브론즈:
					rankC = 1;
					break;
				case 실버:
					rankC = 2;
					break;
				case 골드:
					rankC = 3;
					break;
				case 플래티넘:
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
				printf("해당 고객은 존재하지 않습니다\n");
			}
			break;

		case 4:
			printf("----------------------------------------\n");
			print_nodes();
			break;

		case 5:
			printf("프로그램을 종료합니다\n");
			break;

		default:
			printf("잘못된 입력입니다\n");
			break;
		}

		if (inp == 5) {
			break;
		}
	}

	return 0;
}