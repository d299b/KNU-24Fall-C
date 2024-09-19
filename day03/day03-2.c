#include <stdio.h>

int main() {

	int inpNum;
	int result;
	
	printf("계산할 팩토리얼 : ");
	scanf_s("%d", &inpNum);

	result = fac(inpNum);
	printf("%d", result);
	return 0;
}

int fac(int num1) {
	int res = 0;
	if (num1 == 1) {
		return 1;
	}
	
	res = num1 * fac(num1 - 1);
	return res;
}