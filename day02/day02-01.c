#include<stdio.h>

int main() {
	
	double num1, num2;
	double result;
	int giho;

	printf("���ϴ� ����� �Է��Ͻÿ�.\n");
	printf("1.���ϱ� 2.���� 3.���ϱ� 4.������\n");
	printf("��� : ");
	scanf_s("%d", &giho);

	printf("���� 1�� �Է��ϼ��� : ");
	scanf_s("%lf", &num1);

	printf("���� 2�� �Է��ϼ��� : ");
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
		printf("��ȣ�� �߸� �Է��ϼ̽��ϴ�");

	return 0;
}