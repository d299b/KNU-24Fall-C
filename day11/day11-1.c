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

	printf("a�� �Է��ϼ��� : ");
	scanf_s("%lf", &a);
	printf("b�� �Է��ϼ��� : ");
	scanf_s("%lf", &b);
	printf("c�� �Է��ϼ��� : ");
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
		printf("���� �������� �ʽ��ϴ�");
		break;
	case 1:
		result1 = (-b) / 2.0 * a;
		printf("���� %.2lf �Դϴ�", result1);
		break;
	case 2:
		result1 = ((-b) + sqrt(pow(b, 2) - 4 * a * c)) / 2 * a;
		result2 = ((-b) - sqrt(pow(b, 2) - 4 * a * c)) / 2 * a;
		printf("���� %.2lf, %.2lf �Դϴ�", result1, result2);
		break;
	}

	return 0;
}