#include <stdio.h>

struct Product
{
	int id;
	char name[100];
	int price;
};

void printProduct(struct Product pro) {
		printf("��ǰ ID : %d\n", pro.id);
		printf("��ǰ�� : %s\n", pro.name);
		printf("���� : %d\n", pro.price);
		printf("\n");
}

int main() {
	struct Product arrpro[5];

	int count = 0;
	int i = 0;

	for (i; i < 5; i++)
	{
		printf("��ǰ ������ �Է��ϼ��� (�Է� �߰��� id�� 0 �Է�)\n");
		printf("��ǰ ID : ");
		scanf_s("%d", &arrpro[i].id);
		if (arrpro[i].id == 0) {
			break;
		}
		printf("��ǰ�� : ");
		scanf_s("%s", arrpro[i].name,sizeof(arrpro[i].name));

		printf("���� : ");
		scanf_s("%d", &arrpro[i].price);
		printf("\n");
		count++;
	}

	printf("\n");
	printf("<<�Էµ� ��ǰ ���>>\n");

	for (int i = 0; i < count; i++) {
	printProduct(arrpro[i]);
	}
	
	return 0;
}