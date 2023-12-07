#include "gamble_puang.h"

int boonsu() //분수 이벤트
{
	srand(rand());

	int hwakrull = rand() % 100 + 1;

	if (hwakrull > 98) //2%확률로 500원 줍기
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