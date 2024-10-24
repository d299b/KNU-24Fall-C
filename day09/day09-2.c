#include <stdio.h>

struct Product
{
	int id;
	char name[100];
	int price;
};

void printProduct(struct Product pro) {
		printf("상품 ID : %d\n", pro.id);
		printf("상품명 : %s\n", pro.name);
		printf("가격 : %d\n", pro.price);
		printf("\n");
}

int main() {
	struct Product arrpro[5];

	int count = 0;
	int i = 0;

	for (i; i < 5; i++)
	{
		printf("상품 정보를 입력하세요 (입력 중간은 id에 0 입력)\n");
		printf("상품 ID : ");
		scanf_s("%d", &arrpro[i].id);
		if (arrpro[i].id == 0) {
			break;
		}
		printf("상품명 : ");
		scanf_s("%s", arrpro[i].name,sizeof(arrpro[i].name));

		printf("가격 : ");
		scanf_s("%d", &arrpro[i].price);
		printf("\n");
		count++;
	}

	printf("\n");
	printf("<<입력된 상품 목록>>\n");

	for (int i = 0; i < count; i++) {
	printProduct(arrpro[i]);
	}
	
	return 0;
}