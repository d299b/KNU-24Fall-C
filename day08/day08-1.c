#include <stdio.h>
#include <stdint.h>
#include <string.h>

int main() {

	char inpsen[100];
	char tmp;

	printf("���ڿ��� �Է��ϼ���(����) : "); 
	scanf_s("%s", &inpsen, 100);

	int n = 0;
	int len = strlen(inpsen) - 1;

	while (len >= strlen(inpsen)/2) {
		tmp = *(inpsen + len);
		*(inpsen + len) = *(inpsen + n);
		*(inpsen + n) = tmp;
		n++;
		len--;
	}

	printf("�������� ���ڿ� : ");

	n = 0;
	len = strlen(inpsen) - 1;
	while(len >= 0) {
		printf("%c", *(inpsen + n));
		len--;
		n++;
	}

	return 0;
}