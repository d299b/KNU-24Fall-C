#include <stdio.h>
#include <math.h>
#define _USE_MATH_DEFINES

int main() {

	double a;
	double b;
	double c;
	int count;
	double result1;
	double result2;

	printf("a를 입력하세요 : ");
	scanf_s("%lf", &a);
	printf("b를 입력하세요 : ");
	scanf_s("%lf", &b);
	printf("c를 입력하세요 : ");
	scanf_s("%lf", &c);

	if (pow(b, 2) - (4 * a * c) < 0) {
		count = 0;
	}
	else if (pow(b, 2) - (4 * a * c) == 0) {
		count = 1;
	}
	else
		count = 2;

	switch (count)
	{
	case 0:
		printf("근이 존재하지 않습니다");
		break;
	case 1:
		result1 = (-b) / 2.0 * a;
		printf("근은 %.2lf 입니다", result1);
		break;
	case 2:
		result1 = ((-b) + sqrt(pow(b, 2) - 4 * a * c)) / 2 * a;
		result2 = ((-b) - sqrt(pow(b, 2) - 4 * a * c)) / 2 * a;
		printf("근은 %.2lf, %.2lf 입니다", result1, result2);
		break;
	}

	return 0;
}