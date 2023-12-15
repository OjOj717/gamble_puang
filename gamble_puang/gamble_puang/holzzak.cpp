#include "gamble_puang.h"

void HJ_yes();
void HJ_rule();
void HJ_yeonsoopmode();
void HJ_realmode();

int holzzak()
{
play:
	mainwhameon_clear();

	print_money();

	card(5, 0, 7, 20);
	card(5, 0, 7, 33);
	card(5, 0, 7, 46);

	dewhachang_clear();

	dewhachang("[홀짝 딜러]", "플레이 하시겠습니까?", "[y] 예   [n] 아니오 [r] 게임 규칙");

	button = _getch();

	switch (button)
	{
	case 'y':
	case 'Y':
		HJ_yes();
		goto play;
		break;

	case 'n':
	case 'N':
		return P_none;
		break;

	case 'r':
	case 'R':
		HJ_rule();
		goto play;
		break;

	default:
		dewhachang("[홀짝 딜러]", "다시 선택해 주세요.", " ");

		Sleep(300);
		goto play;

		break;
	}

	return P_none;
}

void HJ_yes()
{
yes:
	dewhachang("[홀짝 딜러]", "연습하실건가요?", "[y] 예   [n] 아니오 (실전)");

	switch (button = _getch())
	{
	case 'y':
	case 'Y':
		HJ_yeonsoopmode();
		break;

	case 'n':
	case 'N':
		HJ_realmode();
		break;

	default:
		dewhachang("[블랙잭 딜러]", "다시 선택해 주세요.", " ");

		Sleep(300);
		goto yes;

		break;
	}
}

void HJ_rule()
{
	mainwhameon_clear();

	for (int i = 1; i < 16; i++)
	{
		gotoxy(3, i);
		cout << t_holzzak_rule[i];
	}

	dewhachang("[홀짝 딜러]", "룰지를 보여드리겠습니다.", "아무 버튼이나 눌러주세요_");
	button = _getch();
}

void HJ_yeonsoopmode()
{
	int cards[3][3] = { 0 };
	char action;

here:

	dewhachang_clear();

	gotoxy(4, 20);
	printf("[홀짝 딜러]");

	gotoxy(4, 22);
	printf("1. 합이 홀수 2.합이 짝수 3.세개 모두 빨강 4.세개 모두 검정");

	gotoxy(60, 24);
	printf("예측해 주세요_");

	action = _getch();

	if (action != '1' && action != '2' && action != '3' && action != '4')
	{
		goto here;
	}

	else
	{
		srand((unsigned)time(NULL));
		cards[1][0] = rand() % 10 + 1;
		cards[0][0] = rand() % 4;
		card(cards[0][0], cards[1][0], 7, 20);

		Sleep(100);
		srand(rand());
		cards[1][1] = rand() % 10 + 1;
		cards[0][1] = rand() % 4;
		card(cards[0][1], cards[1][1], 7, 33);

		Sleep(100);
		srand((unsigned)time(NULL));
		cards[1][2] = rand() % 10 + 1;
		cards[0][2] = rand() % 4;
		card(cards[0][2], cards[1][2], 7, 46); //카드 랜덤 지정

		if (action == '1')
		{
			if ((cards[1][0] + cards[1][1] + cards[1][2]) % 2 == 0)
			{
				dewhachang_clear();

				gotoxy(4, 20);
				printf("[홀짝 딜러]");

				gotoxy(4, 22);
				printf("WIN 합이 홀수 입니다!");

				gotoxy(60, 24);
				printf("아무 버튼이나 눌러주세요_");

				button = _getch();
				holzzak();
			}
			else
			{
				dewhachang_clear();

				gotoxy(4, 20);
				printf("[홀짝 딜러]");

				gotoxy(4, 22);
				printf("LOSE 합이 홀수가 아닙니다!");

				gotoxy(60, 24);
				printf("아무 버튼이나 눌러주세요_");

				button = _getch();
				holzzak();
			}
		}

		else if (action == '2')
		{
			if ((cards[1][0] + cards[1][1] + cards[1][2]) % 2 == 1)
			{
				dewhachang_clear();

				gotoxy(4, 20);
				printf("[홀짝 딜러]");

				gotoxy(4, 22);
				printf("WIN 합이 짝수 입니다!");

				gotoxy(60, 24);
				printf("아무 버튼이나 눌러주세요_");

				button = _getch();
				holzzak();
			}
			else
			{
				dewhachang_clear();

				gotoxy(4, 20);
				printf("[홀짝 딜러]");

				gotoxy(4, 22);
				printf("LOSE 합이 짝수가 아닙니다!");

				gotoxy(60, 24);
				printf("아무 버튼이나 눌러주세요_");

				button = _getch();
				holzzak();
			}
		}

		else if (action == '3')
		{
			if (cards[0][0] % 2 == 0 && cards[0][1] % 2 == 0 && cards[0][2] % 2 == 0)
			{
				dewhachang_clear();

				gotoxy(4, 20);
				printf("[홀짝 딜러]");

				gotoxy(4, 22);
				printf("WIN 세 카드가 모두 빨간색 입니다!");

				gotoxy(60, 24);
				printf("아무 버튼이나 눌러주세요_");

				button = _getch();
				holzzak();
			}
			else if (cards[0][0] % 2 == 1 && cards[0][1] % 2 == 1 && cards[0][2] % 2 == 1)
			{
				dewhachang_clear();

				gotoxy(4, 20);
				printf("[홀짝 딜러]");

				gotoxy(4, 22);
				printf("LOSE 세 카드가 모두 검은색 입니다!");

				gotoxy(60, 24);
				printf("아무 버튼이나 눌러주세요_");

				button = _getch();
				holzzak();
			}
			else
			{
				dewhachang_clear();

				gotoxy(4, 20);
				printf("[홀짝 딜러]");

				gotoxy(4, 22);
				printf("LOSE 세 카드의 색이 다릅니다.");

				gotoxy(60, 24);
				printf("아무 버튼이나 눌러주세요_");

				button = _getch();
				holzzak();
			}
		}

		else if (action == '4')
		{
			if (cards[0][0] % 2 == 0 && cards[0][1] % 2 == 0 && cards[0][2] % 2 == 0)
			{
				dewhachang_clear();

				gotoxy(4, 20);
				printf("[홀짝 딜러]");

				gotoxy(4, 22);
				printf("LOSE 세 카드가 모두 빨간색 입니다!");

				gotoxy(60, 24);
				printf("아무 버튼이나 눌러주세요_");

				button = _getch();
				holzzak();
			}
			if (cards[0][0] % 2 == 1 && cards[0][1] % 2 == 1 && cards[0][2] % 2 == 1)
			{
				dewhachang_clear();

				gotoxy(4, 20);
				printf("[홀짝 딜러]");

				gotoxy(4, 22);
				printf("WIN 세 카드가 모두 검은색 입니다!");

				gotoxy(60, 24);
				printf("아무 버튼이나 눌러주세요_");

				button = _getch();
				holzzak();
			}
			else
			{
				dewhachang_clear();

				gotoxy(4, 20);
				printf("[홀짝 딜러]");

				gotoxy(4, 22);
				printf("LOSE 세 카드의 색이 다릅니다.");

				gotoxy(60, 24);
				printf("아무 버튼이나 눌러주세요_");

				button = _getch();
				holzzak();
			}
		}
	}
}

void HJ_realmode()
{
	int cards[3][3] = { 0 };
	char action;
	double betting = 0;

	dewhachang_clear();

	gotoxy(4, 20);
	printf("[홀짝 딜러]");

	gotoxy(4, 22);
	printf("배팅해 주세요.");

	gotoxy(70, 24);
	printf("배팅 금액 : ");

	scanf_s("%lf", &betting);

	money -= betting;
	if (money < 0)
	{
		money += betting;

		dewhachang_clear();

		gotoxy(4, 20);
		printf("[홀짝 딜러]");

		gotoxy(4, 22);
		printf("돈이 부족한것 같네요..");

		gotoxy(70, 24);
		printf("아무 버튼이나 눌러주세요_");

		button = _getch();
		HJ_yes();
	}

	else
	{
		gotoxy(73, 8);
		printf("소지금 : %11.f", money);

	here:

		dewhachang_clear();

		gotoxy(4, 20);
		printf("[홀짝 딜러]");

		gotoxy(4, 22);
		printf("1. 합이 홀수 2.합이 짝수 3.세개 모두 빨강 4.세개 모두 검정");

		gotoxy(60, 24);
		printf("예측해 주세요_");

		action = _getch();

		if (action != '1' && action != '2' && action != '3' && action != '4')
		{
			goto here;
		}

		else
		{
			srand((unsigned)time(NULL));
			cards[1][0] = rand() % 10 + 1;
			cards[0][0] = rand() % 4;
			card(cards[0][0], cards[1][0], 7, 20);

			Sleep(100);
			srand(rand());
			cards[1][1] = rand() % 10 + 1;
			cards[0][1] = rand() % 4;
			card(cards[0][1], cards[1][1], 7, 33);

			Sleep(100);
			srand((unsigned)time(NULL) + rand());
			cards[1][2] = rand() % 10 + 1;
			cards[0][2] = rand() % 4;
			card(cards[0][2], cards[1][2], 7, 46);

			if (action == '1')
			{
				if ((cards[1][0] + cards[1][1] + cards[1][2]) % 2 == 1)
				{
					dewhachang_clear();

					gotoxy(4, 20);
					printf("[홀짝 딜러]");

					gotoxy(4, 22);
					printf("WIN 합이 홀수 입니다! (배팅 금액의 1.8배 지급)");

					gotoxy(60, 24);
					printf("아무 버튼이나 눌러주세요_");

					betting *= 1.8;
				}
				else
				{
					dewhachang_clear();

					gotoxy(4, 20);
					printf("[홀짝 딜러]");

					gotoxy(4, 22);
					printf("LOSE 합이 홀수가 아닙니다!");

					gotoxy(60, 24);
					printf("아무 버튼이나 눌러주세요_");

					betting *= 0;
				}
			}

			else if (action == '2')
			{
				if ((cards[1][0] + cards[1][1] + cards[1][2]) % 2 == 0)
				{
					dewhachang_clear();

					gotoxy(4, 20);
					printf("[홀짝 딜러]");

					gotoxy(4, 22);
					printf("WIN 합이 짝수 입니다! (배팅 금액의 1.9배 지급)");

					gotoxy(60, 24);
					printf("아무 버튼이나 눌러주세요_");

					betting *= 1.9;
				}
				else
				{
					dewhachang_clear();

					gotoxy(4, 20);
					printf("[홀짝 딜러]");

					gotoxy(4, 22);
					printf("LOSE 합이 짝수가 아닙니다!");

					gotoxy(60, 24);
					printf("아무 버튼이나 눌러주세요_");

					betting *= 0;
				}
			}

			else if (action == '3')
			{
				if (cards[0][0] % 2 == 0 && cards[0][1] % 2 == 0 && cards[0][2] % 2 == 0)
				{
					dewhachang_clear();

					gotoxy(4, 20);
					printf("[홀짝 딜러]");

					gotoxy(4, 22);
					printf("WIN 세 카드가 모두 빨간색 입니다! (배팅 금액의 3.2배 지급)");

					gotoxy(60, 24);
					printf("아무 버튼이나 눌러주세요_");

					betting *= 3.2;
				}
				else if (cards[0][0] % 2 == 1 && cards[0][1] % 2 == 1 && cards[0][2] % 2 == 1)
				{
					dewhachang_clear();

					gotoxy(4, 20);
					printf("[홀짝 딜러]");

					gotoxy(4, 22);
					printf("LOSE 세 카드가 모두 검은색 입니다!");

					gotoxy(60, 24);
					printf("아무 버튼이나 눌러주세요_");

					betting *= 0;
				}
				else
				{
					dewhachang_clear();

					gotoxy(4, 20);
					printf("[홀짝 딜러]");

					gotoxy(4, 22);
					printf("LOSE 세 카드의 색이 다릅니다.");

					gotoxy(60, 24);
					printf("아무 버튼이나 눌러주세요_");

					betting *= 0;
				}
			}

			else if (action == '4')
			{
				if (cards[0][0] % 2 == 0 && cards[0][1] % 2 == 0 && cards[0][2] % 2 == 0)
				{
					dewhachang_clear();

					gotoxy(4, 20);
					printf("[홀짝 딜러]");

					gotoxy(4, 22);
					printf("LOSE 세 카드가 모두 빨간색 입니다!");

					gotoxy(60, 24);
					printf("아무 버튼이나 눌러주세요_");

					betting *= 0;
				}
				if (cards[0][0] % 2 == 1 && cards[0][1] % 2 == 1 && cards[0][2] % 2 == 1)
				{
					dewhachang_clear();

					gotoxy(4, 20);
					printf("[홀짝 딜러]");

					gotoxy(4, 22);
					printf("WIN 세 카드가 모두 검은색 입니다! (배팅 금액의 3.3배 지급)");

					gotoxy(60, 24);
					printf("아무 버튼이나 눌러주세요_");

					betting *= 3.3;
				}
				else
				{
					dewhachang_clear();

					gotoxy(4, 20);
					printf("[홀짝 딜러]");

					gotoxy(4, 22);
					printf("LOSE 세 카드의 색이 다릅니다.");

					gotoxy(60, 24);
					printf("아무 버튼이나 눌러주세요_");

					betting *= 0;
				}
			}

		}

		money += betting;
		button = _getch();
	}
}