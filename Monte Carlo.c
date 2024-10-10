#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>


int main() {

	double x = 0.0;
	double y = 0.0;
	double r = 1.0;
	double pie = 0.0;
	double result = 0.0;

	int total_count = 0;
	int circle_count = 0;
	int white = 0;
	int black = 20;

	srand(time(NULL));

	int count = 0;
	int progress = 0;

	
	while (count < 1000000000) {
		x = (double)rand() / (double)RAND_MAX;
		y = (double)rand() / (double)RAND_MAX;
		result = sqrt(pow(x, 2) + pow(y, 2));

		if (result < r) {
			circle_count++;
		}
		total_count++;
		
		pie = (double)4 * ((double)circle_count / (double)total_count);
		
		if (count % 10000000 == 0) {
			progress++;
			printf("%d%%진행.. 원주율 : %f ", progress, pie);
			if (progress % 5 == 0) {
				white++;
				black--;
			}
			for (int i = 0; i < white; i++) {
				printf("0");
			}
			for (int i = 0; i < black; i++) {
				printf("-");
			}
			printf("\n");
		}
		
		count++;
	}
	

	return 0;
}