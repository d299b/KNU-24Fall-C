#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

void fillRandom(int array[SIZE][SIZE]);
void printArray(int array[SIZE][SIZE]);
void movePointer(void* array);


int main() {
	int array[SIZE][SIZE];
	
	fillRandom(array);
	printArray(array);
	movePointer(array);

	return 0;
}

void fillRandom(int array[SIZE][SIZE]) {
	int rand_num = 0;
	srand(time(NULL));

	for (int i = 0; i < 10; i++) {
		for (int r = 0; r < 10; r++) {
		rand_num = rand() % 20 + 1;
		array[i][r] = rand_num;
		}
	}
	return array;
}


void printArray(int array[SIZE][SIZE]) {
	for (int i = 0; i < 10; i++) {
		for (int r = 0; r < 10; r++) {
			printf("%2d ", array[i][r]);
		}
		printf("\n");
	}
	return array;
}

void movePointer(void* array) {
	
	int i = 0;
	int r = 0;
	int count = 0;
	int arrpit;

	while (1){
		arrpit = *(int*)array;
		printf("현재 위치 : (%d, %d), 배열의 값 : %d\n", i, r, arrpit);

		count = count + arrpit;
		if (count >= 100) {
			break;
		}

		i = count / 10;
		r = count % 10;

		array = (void*)((int*)array + arrpit);
	}
	printf("더 이상 이동할 수 없습니다.\n");
	printf("종료 위치 : (%d, %d), 배열의 값 : %d", i, r, arrpit);
}