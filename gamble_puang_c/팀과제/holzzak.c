#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>

int HJ_yes();
int HJ_rule();
int HJ_yeonsoopmode();
int HJ_realmode();

extern double money;
extern int mmove;

int holzzak_num = 0;

int holzzak()
{
	char sigakbutton;
	int banbok = 0;

	mainwhameon_clear();

	gotoxy(73, 8);
	printf("소지금 : %11.f", money);

	card(5, 0, 7, 20);
	card(5, 0, 7, 33);
	card(5, 0, 7, 46);

	dewhachang_clear();

	gotoxy(4, 20);
	printf("[홀짝 딜러]");

	gotoxy(4, 22);
	printf("플레이 하시겠습니까?");

	gotoxy(60, 24);
	printf("[y] 예   [n] 아니오 [r] 게임 규칙");

	sigakbutton = getch();

	switch (sigakbutton)
	{
	case 'y':
	case 'Y':
		HJ_yes();
		break;
	case 'n':
	case 'N':
		mmove = 1;
		main();
		break;
	case 'r':
	case 'R':
		HJ_rule();
		break;
	default:
		dewhachang_clear();

		gotoxy(4, 20);
		printf("[포커 딜러]");
		gotoxy(4, 22);
		printf("다시 선택해 주세요.");
		Sleep(300);
		holzzak();

		break;
	}

	return 0;
}

int HJ_yes()
{
	char mode;
	holzzak_num += 1;

	dewhachang_clear();

	gotoxy(4, 20);
	printf("[홀짝 딜러]");

	gotoxy(4, 22);
	printf("연습하실건가요?");

	gotoxy(70, 24);
	printf("[y] 예   [n] 아니오 (실전)");

	mode = getch();

	switch (mode)
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
		gotoxy(4, 22);
		printf("                                   ");
		gotoxy(4, 22);
		printf("다시 선택해 주세요.");
		break;
	}

	return 0;
}

int HJ_rule()
{
	mainwhameon_clear();

	gotoxy(3, 1);
	printf("<< HOLL ZZAK >>");

	gotoxy(3, 2);
	printf(" 홀짝은 A부터 10까지 카드 세장을 뒤집어 ");

	gotoxy(3, 3);
	printf(" 세장의 카드합이 홀수인지 짝수인지, 모두 어떤 색인지 추측하는 게임입니다.");

	gotoxy(3, 5);
	printf("- 게임 방법");

	gotoxy(3, 6);
	printf(" 1. 연습 모드와 배팅 모드를 선택합니다.");

	gotoxy(3, 7);
	printf(" 2. 배팅 모드라면 배팅 금액을 입력합니다.");

	gotoxy(3, 8);
	printf(" 3. 세장의 카드합이 홀수인지 짝수인지, 모두 어떤 색인지 추측합니다.");

	gotoxy(3, 9);
	printf(" 4. 세장의 카드를 뒤집습니다.");

	gotoxy(3, 10);
	printf(" 5. 추측이 맞았다면 배율에 따라 상금을 얻습니다.");

	gotoxy(3, 12);
	printf(" 카드 합이 홀수 : 1.8배 지급");

	gotoxy(3, 13);
	printf(" 카드 합이 짝수 : 1.9배 지급");

	gotoxy(3, 14);
	printf("   카드 세장이 모두 빨강 : 3.2배 지급");

	gotoxy(3, 15);
	printf("  카드 세장이 모두 검정 : 3.3배 지급");

	dewhachang_clear();

	gotoxy(4, 20);
	printf("[홀짝 딜러]");

	gotoxy(4, 22);
	printf("룰지를 보여드리겠습니다.");

	gotoxy(70, 24);
	printf("아무 버튼이나 눌러주세요_");

	getch();
	holzzak();

	return 0;
}

int HJ_yeonsoopmode()
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

	action = getch();

	if (action != '1' && action != '2' && action != '3' && action != '3')
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

				getch();
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

				getch();
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

				getch();
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

				getch();
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

				getch();
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

				getch();
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

				getch();
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

				getch();
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

				getch();
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

				getch();
				holzzak();
			}
		}
	}

	return 0;
}

int HJ_realmode()
{
	int cards[3][3] = { 0 };
	char action;
	int betting = 0;

	dewhachang_clear();

	gotoxy(4, 20);
	printf("[홀짝 딜러]");

	gotoxy(4, 22);
	printf("배팅해 주세요.");

	gotoxy(70, 24);
	printf("배팅 금액 : ");

	scanf_s("%d", &betting);

	money -= betting;
	if (money < 0)
	{
		money += betting;

		dewhachang_clear();

		gotoxy(4, 20);
		printf("[블랙잭 딜러]");

		gotoxy(4, 22);
		printf("돈이 부족한것 같네요..");

		gotoxy(70, 24);
		printf("아무 버튼이나 눌러주세요_");

		getch();
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

		action = getch();

		if (action != '1' && action != '2' && action != '3' && action != '3')
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

					getch();
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

					betting *= 0;

					getch();
					holzzak();
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

					getch();
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

					betting *= 0;

					getch();
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
					printf("WIN 세 카드가 모두 빨간색 입니다! (배팅 금액의 3.2배 지급)");

					gotoxy(60, 24);
					printf("아무 버튼이나 눌러주세요_");

					betting *= 3.2;

					getch();
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

					betting *= 0;

					getch();
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

					betting *= 0;

					getch();
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

					betting *= 0;

					getch();
					holzzak();
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

					getch();
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

					betting *= 0;

					getch();
					holzzak();
				}
			}

		}

		money += betting;
	}

	return 0;
}