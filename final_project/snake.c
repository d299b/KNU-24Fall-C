// C program to build the complete 
// snake game 
#include <conio.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include <io.h> 
#include <Windows.h>

int i, j, height = 20, width = 20;
int gameover, score;
int x, y, fruitx, fruity, flag;
int preX[400];
int preY[400];
int lenght;
int bodyX[400];
int bodyY[400];

// Function to generate the fruit 
// within the boundary 
void setup()
{
	gameover = 0;
	lenght = 1;

	// Stores height and width 
	x = height / 2;
	y = width / 2;
	bodyX[0] = x;
	bodyY[0] = y;

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
				for (int r = 0; r < lenght; r++) {
					if (i == bodyX[r] && j == bodyY[r]) {
						printf("0");
					}
				}
				if (i == fruitx
					&& j == fruity)
					printf("*");
				else
					printf(" ");
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
	printf("\n");
	for (int i = 0; i < lenght; i++) {
		printf("%d, %d", bodyX[i], bodyY[i]);
		printf("\n");
	}
}

// Function to take the input 
void input()
{
	if (_kbhit()) {
		switch (getch()) {
		case 'a':
			flag = 1;
			break;
		case 's':
			flag = 2;
			break;
		case 'd':
			flag = 3;
			break;
		case 'w':
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

	if (lenght >= 2) {
		for (int i = 0; i < lenght; i++) {
			preX[i] = bodyX[i];
			preY[i] = bodyY[i];
		}
	}

	switch (flag) {
	case 1:
		y--;
		break;
	case 2:
		x++;
		break;
	case 3:
		y++;
		break;
	case 4:
		x--;
		break;
	default:
		break;
	}

	 
	bodyX[0] = x;
	bodyY[0] = y;
	if (lenght >= 2) {
		for (int i = 1; i < lenght; i++) {
			bodyX[i] = preX[i-1];
			bodyY[i] = preY[i-1];
		}
	}
	

	// If the game is over 
	if (x < 0 || x > height
		|| y < 0 || y > width)
		gameover = 1;

	// If snake reaches the fruit 
	// then update the score 
	if (x == fruitx && y == fruity) {
		lenght++;
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
