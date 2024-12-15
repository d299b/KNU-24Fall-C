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

// x, y 좌표를 감지하는 방식이 int값에서 구조체로 변경했기 때문에
//x, y 좌표를 감지하려면 (구조체 이름).x 같은 식으로 접근해야함
typedef struct {
	int x, y;
} Point;

Point snake[400]; // 뱀 몸 길이 최대 400

// Function to generate the fruit 
// within the boundary 
void setup()
{
	gameover = 0;
	lenght = 2; // 초기 몸 길이
	flag = 0; // 초기 방향

	// Stores height and width 
	snake[0].x = width / 2; // 초기 뱀 x위치
	snake[0].y = height / 2; // 초기 뱀 y위치

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
				int tri = 0; // 몸을 출력했는지 확인용 트리거

				for (int r = 0; r < lenght; r++) { // 몸 길이 만큼 반복해서 몸 길이 만큼 출력
					if (snake[r].x == i && snake[r].y == j) { // 뱀 좌표와 같다면 출력
						printf("0");
						tri = 1; // 몸을 출력했으니 트리거가 1이 됨
						break;
					}
				}
				
				if (tri == 0) { // 몸이 출력되지 않았을 때 다른 걸 출력함
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
			if (flag == 3) break; // 정반대 방향으로 이동하지 못 함
			flag = 1;
			break;
		case 's':
			if (flag == 4) break; // 정반대 방향으로 이동하지 못 함
			flag = 2;
			break;
		case 'd':
			if (flag == 1) break; // 정반대 방향으로 이동하지 못 함
			flag = 3;
			break;
		case 'w':
			if (flag == 2) break; // 정반대 방향으로 이동하지 못 함
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

	Point newHead = snake[0]; // 새로운 머리의 좌표를 구하기 위해 새로운 구조체를 선언함
	switch (flag) {
	case 1:
		newHead.y--; // 새로운 머리가 구조체니까 구조체로 접근함
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

	// 본인 몸에 박으면 게임오버
	if (flag != 0) { // 맨 처음 시작할 때 게임오버 되지 않게 하기 위함
		for (int i = 0; i < lenght; i++) { // 현재 몸 길이 만큼 반복
			if (snake[i].x == newHead.x && snake[i].y == newHead.y) { // 현재 뱀 위치(몸통)과 새로운 머리와 좌표가 같으면 게임오버
				gameover = 1;
				return;
			}
		}
	}

	//몸이 몸 길이 만큼 한 칸씩 뒤로 밀림
	for (int i = lenght; i > 0; i--) {
		snake[i] = snake[i - 1];
	}
	
	//머리는 새로 갱신된 머리로 바뀜
	snake[0] = newHead;

	// 각종 판정은 머리를 기준으로 하기 때문에 newHead를 기준으로 함
	// If the game is over 
	if (newHead.x < 0 || newHead.x > height
		|| newHead.y < 0 || newHead.y > width)
		gameover = 1;

	// If snake reaches the fruit 
	// then update the score 
	if (newHead.x == fruitx && newHead.y == fruity) {
		lenght += 1; // 과일을 먹으면 몸 길이가 길어짐
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
