#include <stdio.h>

int resx, resy, resz = 0;

struct Vector
{
	int x;
	int y;
	int z;
};

void VecSum(struct Vector vec1, struct Vector vec2) {
	printf("명령 입력 : 1\n");
	resx = vec1.x + vec2.x;
	resy = vec1.y + vec2.y;
	resz = vec1.z + vec2.z;
	printf("벡터의 합은 x:%d y:%d z:%d\n",resx, resy, resz);
}

void VecSub(struct Vector vec1, struct Vector vec2) {
	printf("명령 입력 : 2\n");
	resx = vec1.x - vec2.x;
	resy = vec1.y - vec2.y;
	resz = vec1.z - vec2.z;
	printf("벡터의 차는 x:%d y:%d z:%d\n", resx, resy, resz);
}

void VecCro(struct Vector vec1, struct Vector vec2) {
	printf("명령 입력 : 3\n");
	resx = vec1.y * vec2.z - vec1.z * vec2.y;
	resy = vec1.z * vec2.x - vec1.x * vec2.z;
	resz = vec1.x * vec2.y - vec1.y * vec2.x;
	printf("벡터의 외적은 x:%d y:%d z:%d\n", resx, resy, resz);
}

void VecDot(struct Vector vec1, struct Vector vec2) {
	int res;
	printf("명령 입력 : 4\n");
	res = vec1.x * vec2.x + vec1.y * vec2.y + vec1.z * vec2.z;
	printf("벡터의 내적은 vec1·vec2 = %d\n", res);
}

int main() {
	struct Vector vec1;
	struct Vector vec2;
	int sel;

	printf("첫번째 벡터 x입력 : ");
	scanf_s("%d", &vec1.x);
	printf("첫번째 벡터 y입력 : ");
	scanf_s("%d", &vec1.y);
	printf("첫번째 벡터 z입력 : ");
	scanf_s("%d", &vec1.z);
	printf("두번째 벡터 x입력 : ");
	scanf_s("%d", &vec2.x);
	printf("두번째 벡터 y입력 : ");
	scanf_s("%d", &vec2.y);
	printf("두번째 벡터 z입력 : ");
	scanf_s("%d", &vec2.z);

	printf("첫번째 벡터(x,y,z) : %d %d %d\n", vec1.x, vec1.y, vec1.z);
	printf("두번째 벡터(x,y,z) : %d %d %d\n\n", vec2.x, vec2.y, vec2.z);

	while (1) {
		printf("-------------------------\n");
		printf("1. 벡터의 합\n");
		printf("2. 벡터의 차\n");
		printf("3. 벡터의 외적\n");
		printf("4. 벡터의 내적\n");
		printf("5. 종료\n");
		printf("-------------------------\n");
		printf("명령 입력 : ");
		scanf_s("%d", &sel);
		printf("\n");
		printf("-------------------------\n");
		switch (sel)
		{
		case 1:
			VecSum(vec1, vec2);
			break;

		case 2:
			VecSub(vec1, vec2);
			break;

		case 3:
			VecCro(vec1, vec2);
			break;

		case 4:
			VecDot(vec1, vec2);
			break;

		case 5:
			printf("프로그램을 종료합니다");
			break;

		default:
			printf("입력이 잘못 되었습니다\n");
			break;
		}
		printf("-------------------------\n");
		if (sel == 5) {
			break;
		}
	}
	return 0;
}