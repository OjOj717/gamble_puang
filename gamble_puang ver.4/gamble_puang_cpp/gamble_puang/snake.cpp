#include <iostream>
#include <conio.h>
#include <windows.h>
#include "gamble_puang.h"

using namespace std;

bool gameover;

const int width = 20;
const int height = 20;

int x, y;
int fruitX;
int fruitY;
int score;
int tailX[100], tailY[100];
int nTail;

enum eDirection { STOP = 0, LEFT_s, RIGHT_s, UP_s, DOWN_s };
eDirection dir;

HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

void setup(){

	gameover = false;
	dir = STOP;
	x = width / 2;
	y = height / 2;
	fruitX = rand() % width;
	fruitY = rand() % height;
	score = 0;
}

void draw(){

	system("cls");
	
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, FOREGROUND_BLUE | FOREGROUND_INTENSITY);

	for (int i = 0; i < width; i++){
		cout << "#";
	}
	cout << endl;
	for (int i = 0; i < height; i++){
		for (int j = 0; j < width; j++){
			if (j == 0){
				cout << "#";
			}
			if (i == y && j == x){
				HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
				SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY);
				cout << "0";
			}
			else if (i == fruitY && j == fruitX){
				HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
				SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
				
				cout << "@";
			}
			else{
				HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
				SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY);
				
				bool print = false;
				
				for (int k = 0; k < nTail; k++){

					if (tailX[k] == j && tailY[k] == i){
						cout << "o";
						print = true;
					}
				}
				if (!print){
					cout << " ";
				}

			}
			
			HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(h, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
			
			if (j == width - 1){
				cout << "#";
			}
		}
		cout << endl;
	}
	for (int i = 0; i < width + 2; i++){
		cout << "#";
	}
	cout << endl;
	cout << "점수 = " << score << endl; 
	cout << "조작법 : 방향키, 탈출 : X" << endl;
	cout << nTail;
}

void input(){

	if (_kbhit()){
		
		switch (_getch()){
		case LEFT:
			dir = LEFT_s;
			break;
		case RIGHT:
			dir = RIGHT_s;
			break;
		case UP:
			dir = UP_s;
			break;
		case DOWN:
			dir = DOWN_s;
			break;
		case 'x':
			gameover = true;
			break;
		}
	}

}

void logic(){

	int prevX = tailX[0];
	int prevY = tailY[0];
	int prev2X, prev2Y;
	tailX[0] = x;
	tailY[0] = y;
	
	for (int i = 1; i < nTail; i++){
		prev2X = tailX[i];
		prev2Y = tailY[i];
		tailX[i] = prevX;
		tailY[i] = prevY;
		prevX = prev2X;
		prevY = prev2Y;
	}

	switch (dir){
	case LEFT_s:
		x--;
		break;
	case RIGHT_s:
		x++;
		break;
	case UP_s:
		y--;
		break;
	case DOWN_s:
		y++;
		break;
	default:
		break;
	}

	if (x > width || x < 0 || y > height || y < 0){
		gameover = true;
		cout << "Game Ended !!!" << endl;
	}

	if (x == fruitX && y == fruitY){
		score += 10;
		money += 5;
		fruitX = rand() % width;
		fruitY = rand() % height;
		nTail++;
	}
}

void PlayGame() {
	setup();
	while (!gameover) {
		draw();
		input();
		logic();
		Sleep(100);
	}
	nTail = 0;
	cout << "다시?(y/n)";
}

int snake(){
	system("cls");
	gotoxy(0, 0);

	PlayGame();
	char op;
	while(true){
		op = _getch();
		if (op == 'y') {
			PlayGame();
		}
		else if (op == 'n') {
			break;
		}
	}
	
	return P_none;
}