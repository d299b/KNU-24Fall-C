#include <stdio.h>

int main() {
	int inpNum;
	printf("�Ҽ����� Ȯ���� ���� �Է��ϼ��� : ");
	scanf_s("%d", &inpNum);

	if (prime(inpNum) == 1) {
		printf("�Ҽ��Դϴ�");
	}
	else {
		printf("�Ҽ��� �ƴմϴ�");
	}

	return 0;
}

int prime(int num1) {
	int count = 0;
	int res = 0;

	for (int i = 1; i <= num1; i++) {
		if (num1 % i == 0) {
			count++;
		}
		else {
			continue;
		}
	}
	if (count == 2) {
		res = 1;
	}
	else {
		res = 0;
	}

	return res;
}