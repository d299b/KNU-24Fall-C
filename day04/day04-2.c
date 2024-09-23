#include <stdio.h>

int main() {
	
	int num1 = 10, num2 = 20;
	int* pnum1;
	int* pnum2;
	pnum1 = &num1;
	pnum2 = &num2;

	printf("num1 = %d, num2 = %d\n", num1, num2);
	swap(&num1, &num2);
	printf("num1 = %d, num2 = %d\n", num1, num2);

	return 0;
}

int swap(int* pa, int* pb) {
	int save = *pa;
	*pa = *pb;
	*pb = save;
	return 0;
}