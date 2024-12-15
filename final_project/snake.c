// C program to build the complete 
// snake game 
#include <conio.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include <io.h> 
#include <Windows.h>

int i, j, height = 20, width = 20;
int gameover, score;
int fruitx, fruity, flag;
int lenght;

// x, y ��ǥ�� �����ϴ� ����� int������ ����ü�� �����߱� ������
//x, y ��ǥ�� �����Ϸ��� (����ü �̸�).x ���� ������ �����ؾ���
typedef struct {
	int x, y;
} Point;

Point snake[400]; // �� �� ���� �ִ� 400

// Function to generate the fruit 
// within the boundary 
void setup()
{
	gameover = 0;
	lenght = 2; // �ʱ� �� ����
	flag = 0; // �ʱ� ����

	// Stores height and width 
	snake[0].x = width / 2; // �ʱ� �� x��ġ
	snake[0].y = height / 2; // �ʱ� �� y��ġ

	fruitx = 0;
	while (fruitx == 0) {
		fruitx = rand() % 20;
	}

	fruity = 0;
	while (fruity == 0) {
		fruity = rand() % 20;
	}

	score = 0;
}


// Function to draw the boundaries 
void draw()
{
	system("cls");
	
	for (i = 0; i < height; i++) {
		for (j = 0; j < width; j++) {
			if (i == 0 || i == width - 1
				|| j == 0
				|| j == height - 1) {
				printf("#");
			}
			else {
				int tri = 0; // ���� ����ߴ��� Ȯ�ο� Ʈ����

				for (int r = 0; r < lenght; r++) { // �� ���� ��ŭ �ݺ��ؼ� �� ���� ��ŭ ���
					if (snake[r].x == i && snake[r].y == j) { // �� ��ǥ�� ���ٸ� ���
						printf("0");
						tri = 1; // ���� ��������� Ʈ���Ű� 1�� ��
						break;
					}
				}
				
				if (tri == 0) { // ���� ��µ��� �ʾ��� �� �ٸ� �� �����
					if (i == fruitx
						&& j == fruity)
						printf("*");
					else
						printf(" ");
				}
			}
		}
		printf("\n");
	}

	// Print the score after the 
	// game ends 
	printf("score = %d", score);
	printf("\n");
	printf("press X to quit the game");
	printf("\n");
}

// Function to take the input 
void input()
{
	// 
	if (_kbhit()) {
		switch (getch()) {
		case 'a':
			if (flag == 3) break; // ���ݴ� �������� �̵����� �� ��
			flag = 1;
			break;
		case 's':
			if (flag == 4) break; // ���ݴ� �������� �̵����� �� ��
			flag = 2;
			break;
		case 'd':
			if (flag == 1) break; // ���ݴ� �������� �̵����� �� ��
			flag = 3;
			break;
		case 'w':
			if (flag == 2) break; // ���ݴ� �������� �̵����� �� ��
			flag = 4;
			break;
		case 'x':
			gameover = 1;
			break;
		}
	}
}

// Function for the logic behind 
// each movement 
void logic()
{
	Sleep(200);

	Point newHead = snake[0]; // ���ο� �Ӹ��� ��ǥ�� ���ϱ� ���� ���ο� ����ü�� ������
	switch (flag) {
	case 1:
		newHead.y--; // ���ο� �Ӹ��� ����ü�ϱ� ����ü�� ������
		break;
	case 2:
		newHead.x++;
		break;
	case 3:
		newHead.y++;
		break;
	case 4:
		newHead.x--;
		break;
	default:
		break;
	}

	// ���� ���� ������ ���ӿ���
	if (flag != 0) { // �� ó�� ������ �� ���ӿ��� ���� �ʰ� �ϱ� ����
		for (int i = 0; i < lenght; i++) { // ���� �� ���� ��ŭ �ݺ�
			if (snake[i].x == newHead.x && snake[i].y == newHead.y) { // ���� �� ��ġ(����)�� ���ο� �Ӹ��� ��ǥ�� ������ ���ӿ���
				gameover = 1;
				return;
			}
		}
	}

	//���� �� ���� ��ŭ �� ĭ�� �ڷ� �и�
	for (int i = lenght; i > 0; i--) {
		snake[i] = snake[i - 1];
	}
	
	//�Ӹ��� ���� ���ŵ� �Ӹ��� �ٲ�
	snake[0] = newHead;

	// ���� ������ �Ӹ��� �������� �ϱ� ������ newHead�� �������� ��
	// If the game is over 
	if (newHead.x < 0 || newHead.x > height
		|| newHead.y < 0 || newHead.y > width)
		gameover = 1;

	// If snake reaches the fruit 
	// then update the score 
	if (newHead.x == fruitx && newHead.y == fruity) {
		lenght += 1; // ������ ������ �� ���̰� �����
		fruitx = 0;
		while (fruitx == 0) {
			fruitx = rand() % 20;
		}

		fruity = 0;
		while (fruity == 0) {
			fruity = rand() % 20;
		}

		score += 10;
	}
}

void main()
{
	int m, n;

	// Generate boundary 
	setup();

	// Until the game is over 
	while (!gameover) {

		// Function Call 
		draw();
		input();
		logic();
	}
}
