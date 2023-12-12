#include "gamble_puang.h"

int boonsu() //분수 이벤트
{
	srand(rand());

	int hwakrull = rand() % 100 + 1;

	if (hwakrull >= 0) //5%확률로 게임기 줍기
	{
		dewhachang_clear();

		textcolor(9);
		gotoxy(4, 20);
		printf("[푸앙이]");
		textcolor(15);

		gotoxy(4, 22);
		printf("분수에서 게임기를 발견했다!");
		Sleep(500);

		//GMAE
	yes:
		dewhachang("[푸앙이]", "어떤 게임을 플레이하지?", "[p] packman [s] snakegame");
		button = _getch();

		switch (button)
		{
		case 'p':
		case 'P':
			return P_packman;
			break;

		case 's':
		case 'S':
			return P_snake;
			break;

		default:
			dewhachang("[푸앙이]", "다시 선택해 주세요.", " ");

			Sleep(300);
			goto yes;
			break;
		}

		gotoxy(73, 8);
		printf("소지금 : %11.f", money);
	}

	else if (hwakrull > 90) //5%확률로 500원 줍기
	{
		dewhachang_clear();

		textcolor(9);
		gotoxy(4, 20);
		printf("[푸앙이]");
		textcolor(15);

		gotoxy(4, 22);
		printf("분수에서 500원을 발견했다!");

		money += 500;

		gotoxy(73, 8);
		printf("소지금 : %11.f", money);
	}

	else if (hwakrull > 80) //18%확률로 100원 줍기
	{
		dewhachang_clear();

		textcolor(9);
		gotoxy(4, 20);
		printf("[푸앙이]");
		textcolor(15);

		gotoxy(4, 22);
		printf("분수에서 100원을 발견했다!");

		money += 100;

		gotoxy(73, 8);
		printf("소지금 : %11.f", money);
	}

	else //80%확률로 아무것도 못줍기
	{
		dewhachang_clear();

		textcolor(9);
		gotoxy(4, 20);
		printf("[푸앙이]");
		textcolor(15);

		gotoxy(4, 22);
		printf("분수에 떨어진 동전이 없네..");
	}

	Sleep(600);

	return P_none;
}