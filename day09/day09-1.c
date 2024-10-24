#include <stdio.h>

int resx, resy, resz = 0;

struct Vector
{
	int x;
	int y;
	int z;
};

void VecSum(struct Vector vec1, struct Vector vec2) {
	printf("��� �Է� : 1\n");
	resx = vec1.x + vec2.x;
	resy = vec1.y + vec2.y;
	resz = vec1.z + vec2.z;
	printf("������ ���� x:%d y:%d z:%d\n",resx, resy, resz);
}

void VecSub(struct Vector vec1, struct Vector vec2) {
	printf("��� �Է� : 2\n");
	resx = vec1.x - vec2.x;
	resy = vec1.y - vec2.y;
	resz = vec1.z - vec2.z;
	printf("������ ���� x:%d y:%d z:%d\n", resx, resy, resz);
}

void VecCro(struct Vector vec1, struct Vector vec2) {
	printf("��� �Է� : 3\n");
	resx = vec1.y * vec2.z - vec1.z * vec2.y;
	resy = vec1.z * vec2.x - vec1.x * vec2.z;
	resz = vec1.x * vec2.y - vec1.y * vec2.x;
	printf("������ ������ x:%d y:%d z:%d\n", resx, resy, resz);
}

void VecDot(struct Vector vec1, struct Vector vec2) {
	int res;
	printf("��� �Է� : 4\n");
	res = vec1.x * vec2.x + vec1.y * vec2.y + vec1.z * vec2.z;
	printf("������ ������ vec1��vec2 = %d\n", res);
}

int main() {
	struct Vector vec1;
	struct Vector vec2;
	int sel;

	printf("ù��° ���� x�Է� : ");
	scanf_s("%d", &vec1.x);
	printf("ù��° ���� y�Է� : ");
	scanf_s("%d", &vec1.y);
	printf("ù��° ���� z�Է� : ");
	scanf_s("%d", &vec1.z);
	printf("�ι�° ���� x�Է� : ");
	scanf_s("%d", &vec2.x);
	printf("�ι�° ���� y�Է� : ");
	scanf_s("%d", &vec2.y);
	printf("�ι�° ���� z�Է� : ");
	scanf_s("%d", &vec2.z);

	printf("ù��° ����(x,y,z) : %d %d %d\n", vec1.x, vec1.y, vec1.z);
	printf("�ι�° ����(x,y,z) : %d %d %d\n\n", vec2.x, vec2.y, vec2.z);

	while (1) {
		printf("-------------------------\n");
		printf("1. ������ ��\n");
		printf("2. ������ ��\n");
		printf("3. ������ ����\n");
		printf("4. ������ ����\n");
		printf("5. ����\n");
		printf("-------------------------\n");
		printf("��� �Է� : ");
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
			printf("���α׷��� �����մϴ�");
			break;

		default:
			printf("�Է��� �߸� �Ǿ����ϴ�\n");
			break;
		}
		printf("-------------------------\n");
		if (sel == 5) {
			break;
		}
	}
	return 0;
}