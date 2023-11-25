#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>

extern double money;
extern int mmove;

int BJ_yes(); //게임시작
int BJ_rule(); //게임룰
int BJ_yeonsoopmode();
int BJ_realmode();
int BJ_Agasheepililddehap(int card[][10], int num); //A가 11일때 합
int BJ_hap(int card[][10], int num); //최종 카드합

int BJ_num = 0;

int blackjack()
{
	char sigakbutton;
	int banbok=0;

	mainwhameon_clear();

	gotoxy(73, 8);
	printf("소지금 : %11.f", money);

	gotoxy(4, 2);
	printf("DEALER >>");

	card(5,0,3, 5);
	card(5,0,3, 13);

	gotoxy(4, 10);
	printf("PLAYER >>");

	card(5,0,11, 5);
	card(5,0,11, 13);

	dewhachang_clear();

	gotoxy(4, 20);
	printf("[블랙잭 딜러]");

	gotoxy(4, 22);
	printf("플레이 하시겠습니까?");

	gotoxy(60, 24);
	printf("[y] 예   [n] 아니오 [r] 게임 규칙");

	sigakbutton = getch();
	
		switch (sigakbutton)
		{
		case 'y':
		case 'Y':
			BJ_yes();
			break;
		case 'n':
		case 'N':
			mmove = 1;
			main();
			break;
		case 'r':
		case 'R':
			BJ_rule();
			break;
		default:
			dewhachang_clear();

			gotoxy(4, 20);
			printf("[포커 딜러]");
			gotoxy(4, 22);
			printf("다시 선택해 주세요.");
			Sleep(300);
			poker();

			break;
		}
	
	return 0;
}

int BJ_yes()
{
	char mode;
	BJ_num += 1;

	dewhachang_clear();

	gotoxy(4, 20);
	printf("[블랙잭 딜러]");

	gotoxy(4, 22);
	printf("연습하실건가요?");

	gotoxy(70, 24);
	printf("[y] 예   [n] 아니오 (실전)");

	mode = getch();

	switch (mode)
	{
	case 'y':
	case 'Y':
		BJ_yeonsoopmode();
		break;
	case 'n':
	case 'N':
		BJ_realmode(money);
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

int BJ_yeonsoopmode()
{
	int dealer[10][10] = { 0 }, player[10][10] = { 0 }; //딜러와 플레이어의 카드
	int dnum = 0, pnum = 0; //현재 딜러와 플레이어의 카드 개수
	char action; //히트 or 스테이

	dewhachang_clear();

	srand((unsigned)time(NULL));
	dealer[1][0] = rand() % 13 + 1;
	dealer[0][0] = rand() % 4;
	dnum += 1;
	srand(rand());
	dealer[1][1] = rand() % 13 + 1;
	dealer[0][1] = rand() % 4;
	dnum += 1; //딜러 카드 두장 받기

	card(dealer[0][0], dealer[1][0], 3, 5);

	srand((unsigned)time(NULL) + rand());
	player[1][0] = rand() % 13 + 1;
	player[0][0] = rand() % 4;
	pnum += 1;
	srand(rand());
	player[1][1] = rand() % 13 + 1;
	player[0][1] = rand() % 4;
	pnum += 1; //플레이어 카드 두장 받기

	card(player[0][0], player[1][0], 11, 5);
	card(player[0][1], player[1][1], 11, 13);

	if (BJ_hap(player, pnum) == 21) //플레이어가 블랙잭일 경우 바로 승리
	{
		dewhachang_clear();

		gotoxy(4, 20);
		printf("[블랙잭 딜러]");

		gotoxy(4, 22);
		printf("블랙잭으로 이기셨습니다!!");

		gotoxy(70, 24);
		printf("아무 버튼이나 눌러주세요_");

		getch();
		blackjack();
	}

	else
	{
		dewhachang_clear();

		gotoxy(4, 20);
		printf("[블랙잭 딜러]");

		gotoxy(4, 22);
		printf("히트를 하실지 스텐드를 하실지 골라주세요.");

		gotoxy(70, 24);
		printf("[h] 히트  [s] 스텐드");

		action = getch(); //히트,스텐드 결정

		while (action == 'h')
		{
			srand(rand());
			player[1][pnum] = rand() % 13 + 1;
			player[0][pnum] = rand() % 4;
			pnum += 1; //플레이어 카드 한장 더

			card(player[0][pnum - 1], player[1][pnum - 1], 11, 5 + (pnum - 1) * 8);

			if (BJ_hap(player, pnum) >= 21)
				action = 's'; //21이상이면 히트 불가

			else //히트,스텐드 한번더 묻기
			{
				dewhachang_clear();

				gotoxy(4, 20);
				printf("[블랙잭 딜러]");

				gotoxy(4, 22);
				printf("히트를 하실지 스텐드를 하실지 골라주세요.");

				gotoxy(70, 24);
				printf("[h] 히트  [s] 스텐드");

				action = getch();
			}
		}

		if (BJ_hap(player, pnum) > 21) //21 넘으면 버스트로 패배
		{
			dewhachang_clear();

			gotoxy(4, 20);
			printf("[블랙잭 딜러]");

			gotoxy(4, 22);
			printf("BURST 합이 21이 넘었습니다!");

			gotoxy(70, 24);
			printf("아무 버튼이나 눌러주세요_");

			getch();
			blackjack();
		}

		else
		{
			card(dealer[0][1], dealer[1][1], 3, 13);
			while (BJ_hap(dealer, dnum) < 16) //딜러의 합이 16 미만이라면 카드 더 받기
			{
				srand(rand());
				dealer[1][dnum] = rand() % 13 + 1;
				dealer[0][dnum] = rand() % 4;
				dnum += 1;

				card(dealer[0][dnum - 1], dealer[1][dnum - 1], 3, 5 + (dnum - 1) * 8);
			}

			if (BJ_hap(dealer, dnum) == BJ_hap(player, pnum)) //합이 같다면 무승부
			{
				dewhachang_clear();

				gotoxy(4, 20);
				printf("[블랙잭 딜러]");

				gotoxy(4, 22);
				printf("PUSH 무승부 입니다!");

				gotoxy(70, 24);
				printf("아무 버튼이나 눌러주세요_");

				getch();
				blackjack();
			}

			else if (BJ_hap(dealer, dnum) > 21) //딜러가 21 넘으면 버스트로 승리
			{
				dewhachang_clear();

				gotoxy(4, 20);
				printf("[블랙잭 딜러]");

				gotoxy(4, 22);
				printf("DEALER BURST 딜러의 합이 21이 넘었습니다!");

				gotoxy(70, 24);
				printf("아무 버튼이나 눌러주세요_");

				getch();
				blackjack();
			}

			else if (BJ_hap(dealer, dnum) > BJ_hap(player, pnum)) //딜러의 합이 더 크다면 패배
			{
				dewhachang_clear();

				gotoxy(4, 20);
				printf("[블랙잭 딜러]");

				gotoxy(4, 22);
				printf("LOSE 딜러의 합이 21에 더 가깝습니다!");

				gotoxy(70, 24);
				printf("아무 버튼이나 눌러주세요_");

				getch();
				blackjack();
			}

			else //플레이어 승리
			{
				dewhachang_clear();

				gotoxy(4, 20);
				printf("[블랙잭 딜러]");

				gotoxy(4, 22);
				printf("WIN 이겼습니다!");

				gotoxy(70, 24);
				printf("아무 버튼이나 눌러주세요_");

				getch();
				blackjack();
			}
		}

	}

	return 0;
}

int BJ_realmode()
{
	int dealer[10][10] = { 0 }, player[10][10] = { 0 }; //딜러와 플레이어의 카드
	int dnum = 0, pnum = 0; //현재 딜러와 플레이어의 카드 개수
	char action; //히트 or 스테이
	int betting = 0;//얼마를 배팅할까?

	dewhachang_clear();

	gotoxy(4, 20);
	printf("[블랙잭 딜러]");

	gotoxy(4, 22);
	printf("얼마를 배팅하시겠습니까?");

	gotoxy(60, 24);
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
		BJ_yes();
	}

	else
	{

		gotoxy(73, 8);
		printf("소지금 : %11.f", money);

		srand((unsigned)time(NULL));
		dealer[1][0] = rand() % 13 + 1;
		dealer[0][0] = rand() % 4;
		dnum += 1;
		srand(rand());
		dealer[1][1] = rand() % 13 + 1;
		dealer[0][1] = rand() % 4;
		dnum += 1; //딜러 카드 두장 받기

		card(dealer[0][0], dealer[1][0], 3, 5);

		srand((unsigned)time(NULL) + rand());
		player[1][0] = rand() % 13 + 1;
		player[0][0] = rand() % 4;
		pnum += 1;
		srand(rand());
		player[1][1] = rand() % 13 + 1;
		player[0][1] = rand() % 4;
		pnum += 1; //플레이어 카드 두장 받기

		card(player[0][0], player[1][0], 11, 5);
		card(player[0][1], player[1][1], 11, 13);

		if (BJ_hap(player, pnum) == 21) //플레이어가 블랙잭일 경우 바로 승리
		{
			dewhachang_clear();

			gotoxy(4, 20);
			printf("[블랙잭 딜러]");

			gotoxy(4, 22);
			printf("블랙잭으로 이기셨습니다!! (배팅 금액 3배 지급)");

			gotoxy(70, 24);
			printf("아무 버튼이나 눌러주세요_");

			betting *= 3;

			getch();
			blackjack();
		}

		else
		{
			dewhachang_clear();

			gotoxy(4, 20);
			printf("[블랙잭 딜러]");

			gotoxy(4, 22);
			printf("히트를 하실지 스텐드를 하실지 골라주세요.");

			gotoxy(70, 24);
			printf("[h] 히트  [s] 스텐드");

			action = getch(); //히트,스텐드 결정

			while (action == 'h')
			{
				srand(rand());
				player[1][pnum] = rand() % 13 + 1;
				player[0][pnum] = rand() % 4;
				pnum += 1; //플레이어 카드 한장 더

				card(player[0][pnum - 1], player[1][pnum - 1], 11, 5 + (pnum - 1) * 8);

				if (BJ_hap(player, pnum) >= 21)
					action = 's'; //21이상이면 히트 불가

				else //히트,스텐드 한번더 묻기
				{
					dewhachang_clear();

					gotoxy(4, 20);
					printf("[블랙잭 딜러]");

					gotoxy(4, 22);
					printf("히트를 하실지 스텐드를 하실지 골라주세요.");

					gotoxy(70, 24);
					printf("[h] 히트  [s] 스텐드");

					action = getch();
				}
			}

			if (BJ_hap(player, pnum) > 21) //21 넘으면 버스트로 패배
			{
				dewhachang_clear();

				gotoxy(4, 20);
				printf("[블랙잭 딜러]");

				gotoxy(4, 22);
				printf("BURST 합이 21이 넘었습니다! (배팅 금액 소멸)");

				gotoxy(70, 24);
				printf("아무 버튼이나 눌러주세요_");

				betting *= 0;
			}

			else
			{
				card(dealer[0][1], dealer[1][1], 3, 13);
				while (BJ_hap(dealer, dnum) < 16) //딜러의 합이 16 미만이라면 카드 더 받기
				{
					srand(rand());
					dealer[1][dnum] = rand() % 13 + 1;
					dealer[0][dnum] = rand() % 4;
					dnum += 1;

					card(dealer[0][dnum - 1], dealer[1][dnum - 1], 3, 5 + (dnum - 1) * 8);
				}

				if (BJ_hap(dealer, dnum) == BJ_hap(player, pnum)) //합이 같다면 무승부
				{
					dewhachang_clear();

					gotoxy(4, 20);
					printf("[블랙잭 딜러]");

					gotoxy(4, 22);
					printf("PUSH 무승부 입니다! (배팅 금액 그대로 지급)");

					gotoxy(70, 24);
					printf("아무 버튼이나 눌러주세요_");
				}

				else if (BJ_hap(dealer, dnum) > 21) //딜러가 21 넘으면 버스트로 승리
				{
					dewhachang_clear();

					gotoxy(4, 20);
					printf("[블랙잭 딜러]");

					gotoxy(4, 22);
					printf("DEALER BURST 딜러의 합이 21이 넘었습니다! (배팅 금액 2배 지급)");

					gotoxy(70, 24);
					printf("아무 버튼이나 눌러주세요_");

					betting *= 2;
				}

				else if (BJ_hap(dealer, dnum) > BJ_hap(player, pnum)) //딜러의 합이 더 크다면 패배
				{
					dewhachang_clear();

					gotoxy(4, 20);
					printf("[블랙잭 딜러]");

					gotoxy(4, 22);
					printf("LOSE 딜러의 합이 21에 더 가깝습니다! (배팅 금액 소멸)");

					gotoxy(70, 24);
					printf("아무 버튼이나 눌러주세요_");

					betting *= 0;
				}

				else //플레이어 승리
				{
					dewhachang_clear();

					gotoxy(4, 20);
					printf("[블랙잭 딜러]");

					gotoxy(4, 22);
					printf("WIN 이겼습니다! (배팅 금액 2배 지급)");

					gotoxy(70, 24);
					printf("아무 버튼이나 눌러주세요_");

					betting *= 2;
				}
			}
			money += betting;
			getch();
			blackjack();
		}
	}

	return 0;
}

int BJ_rule()
{
	mainwhameon_clear();

	gotoxy(3, 1);
	printf("<< BLACK JACK >>");

	gotoxy(3, 2);
	printf(" 블랙잭은 2장 이상의 카드를 꺼내어 그 합계를 21점에 가깝도록 ");

	gotoxy(3, 3);
	printf(" 만들어 딜러의 점수와 승부하는 카드게임입니다.");

	gotoxy(3, 5);
	printf("- 게임 방법");

	gotoxy(3, 6);
	printf(" 1. 연습 모드와 배팅 모드를 선택합니다.");

	gotoxy(3, 7);
	printf(" 2. 배팅 모드라면 배팅 금액을 입력합니다.");

	gotoxy(3, 8);
	printf(" 3. 딜러와 플레이어가 카드 두장을 각각 배분받습니다.");

	gotoxy(3, 9);
	printf(" 4-1. 플레이어의 카드 합이 21이라면 그 즉시 블랙잭으로 승리하고,");

	gotoxy(3, 10);
	printf(" 4-2. 아니라면 카드를 더 받을지 (히트) 그대로 승부할지(스텐드) 정합니다.");

	gotoxy(3, 11);
	printf(" 5. 딜러는 자신의 패가 16미만이면 카드를 더 받습니다.");

	gotoxy(3, 13);
	printf(" 6. 카드의 합이 21이 넘는 다면 버스트로 패배하고,");

	gotoxy(3, 14);
	printf("   둘다 넘지 않았다면 합이 더 큰 사람이 승리합니다.");

	gotoxy(3, 15);
	printf("  ※ A는 1과 11중 더 유리한 숫자로 계산하고,");

	gotoxy(3, 16);
	printf("     J, Q, K는 무조건 10으로 계산합니다.");

	dewhachang_clear();

	gotoxy(4, 20);
	printf("[블랙잭 딜러]");

	gotoxy(4, 22);
	printf("룰지를 보여드리겠습니다.");

	gotoxy(70, 24);
	printf("아무 버튼이나 눌러주세요_");

	getch();
	blackjack();

	return 0;
}

int BJ_Agasheepililddehap(int card[][10], int num) //a를 11로 가정하고 합 계산
{
	int hap = 0;

	for (int i = 0; i < num; i++)
	{
		if (card[1][i] == 1)
			hap += 11;
		else if (card[1][i] == 11 || card[1][i] == 12 || card[1][i] == 13)
			hap += 10;
		else
			hap += card[1][i];
	}
	return hap;
}

int BJ_hap(int card[][10], int num) //실질적으로 사용할 카드 합
{
	int hap = 0;

	for (int i = 0; i < num; i++)
	{
		if (card[1][i] == 1&& BJ_Agasheepililddehap(card, num)<=21)
			hap += 11;
		else if (card[1][i] == 11 || card[1][i] == 12 || card[1][i] == 13)
			hap += 10;
		else
			hap += card[1][i];
	}
	return hap;
}