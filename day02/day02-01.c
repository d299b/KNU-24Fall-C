#include<stdio.h>

int main() {
	
	double num1, num2;
	double result;
	int giho;

	printf("원하는 기능을 입력하시오.\n");
	printf("1.더하기 2.빼기 3.곱하기 4.나누기\n");
	printf("기능 : ");
	scanf_s("%d", &giho);

	printf("숫자 1을 입력하세요 : ");
	scanf_s("%lf", &num1);

	printf("숫자 2을 입력하세요 : ");
	scanf_s("%lf", &num2);

	if (giho == 1) {
		result = num1 + num2;
		printf("%lf + %lf = %f\n", num1, num2, result);
	}
	else if (giho == 2) {
		result = num1 - num2;
		printf("%lf - %lf = %f\n", num1, num2, result);
	}
	else if (giho == 3) {
		result = num1 * num2;
		printf("%lf * %lf = %f\n", num1, num2, result);
	}
	else if (giho == 4) {
		result = num1 / num2;
		printf("%lf / %lf = %f\n", num1, num2, result);
	}
	else
		printf("기호를 잘못 입력하셨습니다");

	return 0;
}