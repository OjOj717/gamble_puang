#include "gamble_puang.h"

void BJ_yes();
void BJ_yeonsoopmode();
void BJ_realmode();
void BJ_rule();
int BJ_Agasheepililddehap(int card[][10], int num);
int BJ_hap(int card[][10], int num);

int blackjack()
{
play:
	mainwhameon_clear();

	print_money();

	gotoxy(4, 2);
	printf("DEALER >>");

	card(5, 0, 3, 5);
	card(5, 0, 3, 13);

	gotoxy(4, 10);
	printf("PLAYER >>");

	card(5, 0, 11, 5);
	card(5, 0, 11, 13);

	dewhachang("[블랙잭 딜러]", "플레이 하시겠습니까?", "[y] 예   [n] 아니오 [r] 게임 규칙");

	switch (button = _getch())
	{
	case 'y':
	case 'Y':
		BJ_yes();
		goto play;
		break;

	case 'n':
	case 'N':
		return P_none;
		break;

	case 'r':
	case 'R':
		BJ_rule();
		goto play;
		break;

	default:
		dewhachang("[블랙잭 딜러]", "다시 선택해 주세요.", " ");

		Sleep(300);
		goto play;
		break;
	}
}

void BJ_yes()
{
yes:
	dewhachang("[블랙잭 딜러]", "연습하실건가요?", "[y] 예   [n] 아니오 (실전)");

	switch (button = _getch())
	{
	case 'y':
	case 'Y':
		BJ_yeonsoopmode();
		break;

	case 'n':
	case 'N':
		BJ_realmode();
		break;

	default:
		dewhachang("[블랙잭 딜러]", "다시 선택해 주세요.", " ");

		Sleep(300);
		goto yes;
		break;
	}
}

void BJ_yeonsoopmode()
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
		dewhachang("[블랙잭 딜러]", "블랙잭으로 이기셨습니다!!", "아무 버튼이나 눌러주세요_");
	}

	else
	{
		dewhachang("[블랙잭 딜러]", "히트를 하실지 스텐드를 하실지 골라주세요.", "[h] 히트  [s] 스텐드");

		action = _getch(); //히트,스텐드 결정

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

				dewhachang("[블랙잭 딜러]", "히트를 하실지 스텐드를 하실지 골라주세요.", "[h] 히트  [s] 스텐드");

				action = _getch();
			}
		}

		if (BJ_hap(player, pnum) > 21) //21 넘으면 버스트로 패배
			dewhachang("[블랙잭 딜러]", "BURST 합이 21이 넘었습니다!", "아무 버튼이나 눌러주세요_");

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
				dewhachang("[블랙잭 딜러]", "PUSH 무승부 입니다!", "아무 버튼이나 눌러주세요_");

			else if (BJ_hap(dealer, dnum) > 21) //딜러가 21 넘으면 버스트로 승리
				dewhachang("[블랙잭 딜러]", "DEALER BURST 딜러의 합이 21이 넘었습니다!", "아무 버튼이나 눌러주세요_");

			else if (BJ_hap(dealer, dnum) > BJ_hap(player, pnum)) //딜러의 합이 더 크다면 패배
				dewhachang("[블랙잭 딜러]", "LOSE 딜러의 합이 21에 더 가깝습니다!", "아무 버튼이나 눌러주세요_");

			else //플레이어 승리
				dewhachang("[블랙잭 딜러]", "WIN 이겼습니다!", "아무 버튼이나 눌러주세요_");
		}

		button = _getch();
	}
}

void BJ_realmode()
{
	int dealer[10][10] = { 0 }, player[10][10] = { 0 }; //딜러와 플레이어의 카드
	int dnum = 0, pnum = 0; //현재 딜러와 플레이어의 카드 개수
	char action; //히트 or 스테이
	double betting = 0;//얼마를 배팅할까?

	dewhachang("[블랙잭 딜러]", "얼마를 배팅하시겠습니까?", "배팅 금액 : ");
	scanf_s("%lf", &betting);

	money -= betting;

	if (money < 0)
	{
		money += betting;

		dewhachang("[블랙잭 딜러]", "돈이 부족한것 같네요..", "아무 버튼이나 눌러주세요_");
		button = _getch();

		BJ_yes();
	}

	else
	{

		print_money();

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
			dewhachang("[블랙잭 딜러]", "블랙잭으로 이기셨습니다!! (배팅 금액 3배 지급)", "아무 버튼이나 눌러주세요_");

			betting *= 3;
		}

		else
		{
			dewhachang("[블랙잭 딜러]", "히트를 하실지 스텐드를 하실지 골라주세요.", "[h] 히트  [s] 스텐드");

			action = _getch(); //히트,스텐드 결정

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

					dewhachang("[블랙잭 딜러]", "히트를 하실지 스텐드를 하실지 골라주세요.", "[h] 히트  [s] 스텐드");

					action = _getch();
				}
			}

			if (BJ_hap(player, pnum) > 21) //21 넘으면 버스트로 패배
			{
				dewhachang("[블랙잭 딜러]", "BURST 합이 21이 넘었습니다! (배팅 금액 소멸)", "아무 버튼이나 눌러주세요_");
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
					dewhachang("[블랙잭 딜러]", "PUSH 무승부 입니다! (배팅 금액 그대로 지급)", "아무 버튼이나 눌러주세요_");
					betting *= 1;
				}

				else if (BJ_hap(dealer, dnum) > 21) //딜러가 21 넘으면 버스트로 승리
				{
					dewhachang("[블랙잭 딜러]", "DEALER BURST 딜러의 합이 21이 넘었습니다! (배팅 금액 2배 지급)", "아무 버튼이나 눌러주세요_");
					betting *= 2;
				}

				else if (BJ_hap(dealer, dnum) > BJ_hap(player, pnum)) //딜러의 합이 더 크다면 패배
				{
					dewhachang("[블랙잭 딜러]", "LOSE 딜러의 합이 21에 더 가깝습니다! (배팅 금액 소멸)", "아무 버튼이나 눌러주세요_");
					betting *= 0;
				}

				else //플레이어 승리
				{
					dewhachang("[블랙잭 딜러]", "WIN 이겼습니다! (배팅 금액 2배 지급)", "아무 버튼이나 눌러주세요_");
					betting *= 2;
				}
			}

			money += betting;
			button = _getch();
		}
	}
}

void BJ_rule()
{
	mainwhameon_clear();

	for (int i = 1; i < 17; i++)
	{
		gotoxy(3, i);
		cout << t_BJ_rule[i];
	}

	dewhachang("[블랙잭 딜러]", "룰지를 보여드리겠습니다.", "아무 버튼이나 눌러주세요_");
	button = _getch();
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
		if (card[1][i] == 1 && BJ_Agasheepililddehap(card, num) <= 21)
			hap += 11;
		else if (card[1][i] == 11 || card[1][i] == 12 || card[1][i] == 13)
			hap += 10;
		else
			hap += card[1][i];
	}
	return hap;
}