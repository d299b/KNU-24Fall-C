#include <stdio.h>

int main() {

	int num = 0;

	printf("類 熱 殮溘 : ");
	scanf_s("%d", &num);

	printf("%d類 Я塭嘐萄\n", num);
	// i = 類熱
	// r = 滌曖 偃熱
	// y = 奢寥 熱

	for (int i = 1; i < num+1; i++) {

		for (int y = 1; y <= (num-i); y++) {
			printf(" ");
		}

		for (int r = 1; r <= i+(i-1); r++) {
			printf("*");
		}
		printf("\n");
	}

	return 0;
}