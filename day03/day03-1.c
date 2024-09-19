#include <stdio.h>

int main() {
	int inpNum;
	printf("소수인지 확인할 수를 입력하세요 : ");
	scanf_s("%d", &inpNum);

	if (prime(inpNum) == 1) {
		printf("소수입니다");
	}
	else {
		printf("소수가 아닙니다");
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