#include <stdio.h>

int main() {

	int num = 0;

	printf("�� �� �Է� : ");
	scanf_s("%d", &num);

	printf("%d�� �Ƕ�̵�\n", num);
	// i = ����
	// r = ���� ����
	// y = ���� ��

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