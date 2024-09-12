#include <stdio.h>

int main() {
	for (int i = 1; i < 100;i++) {
		if (i % 12 == 0 || i % 7 == 0) {
			printf("%d ", i);
		}
	}
	return 0;
}