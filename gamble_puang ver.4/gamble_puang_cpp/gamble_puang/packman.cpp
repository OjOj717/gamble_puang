#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <string>
#include <vector>
#include "gamble_puang.h"

using namespace std;
char tmp_map[18][32];

char new_map[18][32] = {
	"+#############################+",
	"|                             |",
	"|                             |",
	"|## ########    ##   #########|",
	"|   |                         |",
	"| | |### |  |           |     |",
	"| |      |  | |###  |   |  |  |",
	"| | #####|  | |      ## |     |",
	"| |           |###  |      |  |",
	"| |##### ###         ##       |",
	"|          ######  ####### ###|",
	"|                             |",
	"|# ### ####      ###   #######|",
	"|                             |",
	"|                             |",
	"|                             |",
	"|                             |",
	"+#############################+"
};

char map[18][32] = {
	"+#############################+",
	"|                             |",
	"|                             |",
	"|## ########    ##   #########|",
	"|   |                         |",
	"| | |### |  |           |     |",
	"| |      |  | |###  |   |  |  |",
	"| | #####|  | |      ## |     |",
	"| |           |###  |      |  |",
	"| |##### ###         ##       |",
	"|          ######  ####### ###|",
	"|                             |",
	"|# ### ####      ###   #######|",
	"|                             |",
	"|                             |",
	"|                             |",
	"|                             |",
	"+#############################+"
	};

void ClearMap()
{
	copy(&new_map[0][0], &new_map[0][0] + 576, &map[0][0]);
}

void ShowMap()
{
	for(int i = 0; i < 18; i++) {
		printf("%s\n",map[i] );
	}
}

//void gotoxy( short x, short y )
//{
//    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE) ;
//    COORD position = { x, y } ;
//
//    SetConsoleCursorPosition( hStdout, position ) ;
//}

class entity {
public:
	entity( int x, int y ){
		this ->x = x;
		this ->y = y;
	}

	void move_x( int p ){
		if( map[y][x+p] == ' ' ) x += p;
	}

	void move_y( int p ){
		if( map[y+p][x] == ' ' ) y += p;
	}

	void move( int p, int q ){
		x += p;
		y += q;
	}

	int get_x(){ return x; }
	int get_y(){ return y; }

	void draw( char p ){
		map[x][y] = p;
		gotoxy( x, y ); printf( "%c", p );
	}

private:
	int x;
	int y;
};

struct walk {
	short walk_count;
	short x;
	short y;
	short back;
};

struct target {
	short x;
	short y;
};

vector<target> walk_queue;

vector<walk> BFSArray;

void AddArray( int x, int y, int wc , int back ){
	if( tmp_map[y][x] == ' ' || tmp_map[y][x] == '.' ){
		tmp_map[y][x] = '#';
		walk tmp;
		tmp.x = x;
		tmp.y = y;
		tmp.walk_count = wc;
		tmp.back = back;
		BFSArray.push_back( tmp );
	}
}

void FindPath( int sx, int sy, int x, int y ){
	memcpy( tmp_map, map, sizeof(map) );
	BFSArray.clear();
	walk tmp;
	tmp.x = sx;
	tmp.y = sy;
	tmp.walk_count = 0;
	tmp.back = -1;
	BFSArray.push_back( tmp );

	int i = 0;
	while( i < BFSArray.size() ){
		if( BFSArray[i].x == x && BFSArray[i].y == y ){
			walk_queue.clear();
			target tmp2;
			while( BFSArray[i].walk_count != 0 ){
				tmp2.x = BFSArray[i].x;
				tmp2.y = BFSArray[i].y;
				walk_queue.push_back( tmp2 );

				i = BFSArray[i].back;
			}

			break;
		}

		AddArray( BFSArray[i].x+1, BFSArray[i].y, BFSArray[i].walk_count+1, i );
		AddArray( BFSArray[i].x-1, BFSArray[i].y, BFSArray[i].walk_count+1, i );
		AddArray( BFSArray[i].x, BFSArray[i].y+1, BFSArray[i].walk_count+1, i );
		AddArray( BFSArray[i].x, BFSArray[i].y-1, BFSArray[i].walk_count+1, i );
		i++;
	}

	BFSArray.clear();
}

void PlayGames()
{
	bool running = true;
	int x = 15;
	int y = 16;
	int old_x;
	int old_y;

	int ex = 1;
	int ey = 1;


	int pts = 0;

	system("cls");
	gotoxy(0, 0);

	printf("설명:\n1. 키보드로 움직이세요.\n2. 점을 먹으세요.\n3. 적에게 가까이 가지 마세요.\n\n");
	printf("H -> 하드\nN -> 노멀\nE -> 이ㅣㅣㅣ지\n\nH 혹은 N 혹은 E를 눌러주세요.");

	char diffi;
	int speedmod = 3;

	diffi = _getch();

	if (diffi == 'N' || diffi == 'n') {
		speedmod = 2;
	}
	else if (diffi == 'H' || diffi =='h') {
		speedmod = 1;
	}

	system("cls");
	ClearMap();
	ShowMap();

	gotoxy(x, y); cout << "H";

	int frame = 0;

	FindPath(ex, ey, x, y);

	while (running) {
		gotoxy(x, y); cout << " ";

		old_x = x;
		old_y = y;

		if (GetAsyncKeyState(VK_UP)) {
			if (map[y - 1][x] == '.') { y--; pts++; }
			else
				if (map[y - 1][x] == ' ') y--;
		}
		if (GetAsyncKeyState(VK_DOWN)) {
			if (map[y + 1][x] == '.') { y++; pts++; }
			else
				if (map[y + 1][x] == ' ') y++;
		}
		if (GetAsyncKeyState(VK_LEFT)) {
			if (map[y][x - 1] == '.') { x--; pts++; }
			else
				if (map[y][x - 1] == ' ') x--;
		}
		if (GetAsyncKeyState(VK_RIGHT)) {
			if (map[y][x + 1] == '.') { x++; pts++; }
			else
				if (map[y][x + 1] == ' ') x++;
		}

		if (old_x != x || old_y != y) {
			FindPath(ex, ey, x, y);
		}

		gotoxy(x, y); cout << "H";

		map[ey][ex] = '.';
		gotoxy(ex, ey); cout << ".";

		if (frame % speedmod == 0 && walk_queue.size() != 0) {
			ex = walk_queue.back().x;
			ey = walk_queue.back().y;
			walk_queue.pop_back();
		}

		gotoxy(ex, ey); cout << "E";

		if (ex == x && ey == y) {
			break;
		}


		gotoxy(32, 18);
		gotoxy(32, 1); cout << pts;
		Sleep(100);
		frame++;
	}

	system("cls");
	gotoxy(0, 0);
	printf("졌다. 당신의 점수는? : %i", pts); money += (pts / 10);

	Sleep(300);
	cout << "\n\n다시?(y/n) ";
}

int packman()
{
	PlayGames();

	char op;
	while (true) {
		op = _getch();
		if (op == 'y') {
			PlayGames();
		}
		else if (op == 'n') {
			break;
		}
	}
	
	Sleep(300);

	return P_none;
}
