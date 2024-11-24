#include <stdio.h>
#include <math.h>
#define _USE_MATH_DEFINES

int main() {
	double StrX;
	double EndX;
	double x1;
	double x2;
	double y1;
	double y2;
	double base;
	double high;
	double result;
	double count;
	int repNum;

	result = 0.0;

	printf("적분할 시작 값을 입력하세요 : ");
	scanf_s("%lf", &StrX);
	printf("적분할 끝 값을 입력하세요 : ");
	scanf_s("%lf", &EndX);
	printf("시행할 최대 구간을 입력하세요(2^n) : ");
	scanf_s("%d", &repNum);

	for (int i = 0; i <= repNum; i++) {
		count = (EndX - StrX) / pow(2, i);
		result = 0.0;
		for (double r = StrX; r < EndX; r = r + count) {
			x1 = r;
			x2 = r + count;

			y1 = -(log10(1 / x1)) + sin(x1);
			y2 = -(log10(1 / x2)) + sin(x2);

			base = x2 - x1;

			if (y1 < y2)
				high = y1;
			else
				high = y2;

			result = result + (fabs(base) * fabs(high));
		}
		printf("구간 %10.0f 적분 결과 %f\n", pow(2, i), result);
		
	}

	return 0;
}