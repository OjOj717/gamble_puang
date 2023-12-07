#include "gamble_puang.h"

void horse_yes(); //게임시작
void horse_yeonsoopmode(); //연습모드
void horse_realmode(); //실전모드
void horse_rule(); //게임룰
void draw_horse(int i, int r); //말 그리기

int horse()
{
play:
	mainwhameon_clear();

	print_money();

	gotoxy(3, 1);
	printf("= = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =");

	gotoxy(3, 5);
	printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -");

	gotoxy(3, 9);
	printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -");

	gotoxy(3, 13);
	printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -");

	gotoxy(3, 17);
	printf("= = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =");

	draw_horse(1, 1);
	draw_horse(1, 5);
	draw_horse(1, 9);
	draw_horse(1, 13);

	textcolor(6);
	gotoxy(3, 3);
	printf("1");

	gotoxy(3, 7);
	printf("2");

	gotoxy(3, 11);
	printf("3");

	gotoxy(3, 15);
	printf("4");

	textcolor(15);

	dewhachang("[경마 딜러]", "플레이 하시겠습니까?", "[y] 예   [n] 아니오 [r] 게임 규칙");

	button = _getch();

	switch (button)
	{
	case 'y':
	case 'Y':
		horse_yes();
		goto play;
		break;

	case 'n':
	case 'N':
		return P_none;
		break;

	case 'r':
	case 'R':
		horse_rule();
		goto play;
		break;

	default:
		dewhachang("[경마장 딜러]", "다시 선택해 주세요.", " ");

		Sleep(300);
		goto play;

		break;
	}

	return P_none;
}

void horse_yes()
{
yes:
	dewhachang("[경마장 딜러]", "연습하실건가요?", "[y] 예   [n] 아니오 (실전)");

	button = _getch();

	switch (button)
	{
	case 'y':
	case 'Y':
		horse_yeonsoopmode();
		break;

	case 'n':
	case 'N':
		horse_realmode();
		break;

	default:
		dewhachang("[경마장 딜러]", "다시 선택해 주세요.", " ");

		Sleep(300);
		goto yes;

		break;
	}
}

void horse_yeonsoopmode()
{
	char suntek;
	int	random, r;
	int i = 0, j = 0, k = 0, l = 0;

	dewhachang_clear();

	gotoxy(4, 20);
	printf("[경마장 딜러]");

	gotoxy(4, 22);
	printf("네마리의 말 중 우승할 한마리를 예측해 선택해 주세요.");

	gotoxy(60, 24);
	printf("예측해 주세요_");

	suntek = _getch();

	while (i <= 50 && j <= 50 && k <= 50 && l <= 50)
	{
		srand((unsigned)time(NULL) + rand());
		random = rand() % 4 + 1;

		switch (random)
		{
		case 1:
			i++;
			r = 1;
			draw_horse(i, r);
			break;

		case 2:
			j++;
			r = 5;
			draw_horse(j, r);
			break;

		case 3:
			k++;
			r = 9;
			draw_horse(k, r);
			break;

		case 4:
			l++;
			r = 13;
			draw_horse(l, r);
			break;

		default:
			break;
		}
	}

	if (i == 51 && suntek == '1')
	{
		dewhachang_clear();

		gotoxy(4, 20);
		printf("[경마장 딜러]");

		gotoxy(4, 22);
		printf("축하합니다! 1번마가 우승하였습니다!");

		gotoxy(60, 24);
		printf("아무 버튼이나 눌러주세요_");
	}

	else if (i == 51)
	{
		dewhachang_clear();

		gotoxy(4, 20);
		printf("[경마장 딜러]");

		gotoxy(4, 22);
		printf("아쉽습니다! 1번마가 우승하였습니다.");

		gotoxy(60, 24);
		printf("아무 버튼이나 눌러주세요_");
	}

	else if (j == 51 && suntek == '2')
	{
		dewhachang_clear();

		gotoxy(4, 20);
		printf("[경마장 딜러]");

		gotoxy(4, 22);
		printf("축하합니다! 2번마가 우승하였습니다!");

		gotoxy(60, 24);
		printf("아무 버튼이나 눌러주세요_");
	}

	else if (j == 51)
	{
		dewhachang_clear();

		gotoxy(4, 20);
		printf("[경마장 딜러]");

		gotoxy(4, 22);
		printf("아쉽습니다! 2번마가 우승하였습니다.");

		gotoxy(60, 24);
		printf("아무 버튼이나 눌러주세요_");
	}

	else if (k == 51 && suntek == '3')
	{
		dewhachang_clear();

		gotoxy(4, 20);
		printf("[경마장 딜러]");

		gotoxy(4, 22);
		printf("축하합니다! 3번마가 우승하였습니다!");

		gotoxy(60, 24);
		printf("아무 버튼이나 눌러주세요_");
	}

	else if (k == 51)
	{
		dewhachang_clear();

		gotoxy(4, 20);
		printf("[경마장 딜러]");

		gotoxy(4, 22);
		printf("아쉽습니다! 3번마가 우승하였습니다.");

		gotoxy(60, 24);
		printf("아무 버튼이나 눌러주세요_");
	}

	else if (l == 51 && suntek == '4')
	{
		dewhachang_clear();

		gotoxy(4, 20);
		printf("[경마장 딜러]");

		gotoxy(4, 22);
		printf("축하합니다! 4번마가 우승하였습니다!");

		gotoxy(60, 24);
		printf("아무 버튼이나 눌러주세요_");
	}

	else if (l == 51)
	{
		dewhachang_clear();

		gotoxy(4, 20);
		printf("[경마장 딜러]");

		gotoxy(4, 22);
		printf("아쉽습니다! 4번마가 우승하였습니다.");

		gotoxy(60, 24);
		printf("아무 버튼이나 눌러주세요_");
	}

	button = _getch();
}

void horse_realmode()
{
	char suntek;
	int	random, r, betting;
	int i = 0, j = 0, k = 0, l = 0;

	dewhachang_clear();

	gotoxy(4, 20);
	printf("[경마장 딜러]");

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

		button = _getch();
		horse_yes();
	}

	else
	{

		gotoxy(73, 8);
		printf("소지금 : %11.f", money);

		dewhachang_clear();

		gotoxy(4, 20);
		printf("[경마장 딜러]");

		gotoxy(4, 22);
		printf("네마리의 말 중 우승할 한마리를 예측해 선택해 주세요.");

		gotoxy(60, 24);
		printf("예측해 주세요_");

		suntek = _getch();

		while (i <= 50 && j <= 50 && k <= 50 && l <= 50)
		{
			srand((unsigned)time(NULL) + rand());
			random = rand() % 4 + 1;

			switch (random)
			{
			case 1:
				i++;
				r = 1;
				draw_horse(i, r);
				break;

			case 2:
				j++;
				r = 5;
				draw_horse(j, r);
				break;

			case 3:
				k++;
				r = 9;
				draw_horse(k, r);
				break;

			case 4:
				l++;
				r = 13;
				draw_horse(l, r);
				break;

			default:
				break;
			}
		}

		if (i == 51 && suntek == '1')
		{
			dewhachang_clear();

			gotoxy(4, 20);
			printf("[경마장 딜러]");

			gotoxy(4, 22);
			printf("축하합니다! 1번마가 우승하였습니다! (배팅금액 2배 지급)");

			gotoxy(60, 24);
			printf("아무 버튼이나 눌러주세요_");

			betting *= 2;
		}

		else if (i == 51)
		{
			dewhachang_clear();

			gotoxy(4, 20);
			printf("[경마장 딜러]");

			gotoxy(4, 22);
			printf("아쉽습니다! 1번마가 우승하였습니다.(배팅금액 소멸)");

			gotoxy(60, 24);
			printf("아무 버튼이나 눌러주세요_");
		}

		else if (j == 51 && suntek == '2')
		{
			dewhachang_clear();

			gotoxy(4, 20);
			printf("[경마장 딜러]");

			gotoxy(4, 22);
			printf("축하합니다! 2번마가 우승하였습니다!(배팅금액 2배 지급)");

			gotoxy(60, 24);
			printf("아무 버튼이나 눌러주세요_");

			betting *= 2;
		}

		else if (j == 51)
		{
			dewhachang_clear();

			gotoxy(4, 20);
			printf("[경마장 딜러]");

			gotoxy(4, 22);
			printf("아쉽습니다! 2번마가 우승하였습니다.(배팅금액 소멸)");

			gotoxy(60, 24);
			printf("아무 버튼이나 눌러주세요_");
		}

		else if (k == 51 && suntek == '3')
		{
			dewhachang_clear();

			gotoxy(4, 20);
			printf("[경마장 딜러]");

			gotoxy(4, 22);
			printf("축하합니다! 3번마가 우승하였습니다!(배팅금액 2배 지급)");

			gotoxy(60, 24);
			printf("아무 버튼이나 눌러주세요_");

			betting *= 2;
		}

		else if (k == 51)
		{
			dewhachang_clear();

			gotoxy(4, 20);
			printf("[경마장 딜러]");

			gotoxy(4, 22);
			printf("아쉽습니다! 3번마가 우승하였습니다.(배팅금액 소멸)");

			gotoxy(60, 24);
			printf("아무 버튼이나 눌러주세요_");
		}

		else if (l == 51 && suntek == '4')
		{
			dewhachang_clear();

			gotoxy(4, 20);
			printf("[경마장 딜러]");

			gotoxy(4, 22);
			printf("축하합니다! 4번마가 우승하였습니다!(배팅금액 2배 지급)");

			gotoxy(60, 24);
			printf("아무 버튼이나 눌러주세요_");

			betting *= 2;
		}

		else if (l == 51)
		{
			dewhachang_clear();

			gotoxy(4, 20);
			printf("[경마장 딜러]");

			gotoxy(4, 22);
			printf("아쉽습니다! 4번마가 우승하였습니다.(배팅금액 소멸)");

			gotoxy(60, 24);
			printf("아무 버튼이나 눌러주세요_");
		}

		money += betting;
		button = _getch();
	}
}

void horse_rule()
{
	mainwhameon_clear();

	gotoxy(3, 1);
	printf("<< HORSE RACING >>");

	gotoxy(3, 2);
	printf(" 경마는 여러 마리의 말들을 동시에 출발시키고,  ");

	gotoxy(3, 3);
	printf(" 특정 거리를 달린 뒤 결승선을 통과하도록 경주를 시켜서 ");

	gotoxy(3, 4);
	printf(" 먼저 들어온 순서로 순위를 겨루는 스포츠입니다.");

	gotoxy(3, 6);
	printf("- 게임 방법");

	gotoxy(3, 7);
	printf(" 1. 연습 모드와 배팅 모드를 선택합니다.");

	gotoxy(3, 8);
	printf(" 2. 배팅 모드라면 배팅 금액을 입력합니다.");

	gotoxy(3, 9);
	printf(" 3. 1,2,3,4번마 중에서 우승할 것이라고 예상되는 말을 선택합니다.");

	gotoxy(3, 10);
	printf(" 4. 경주를 관람합니다.");

	gotoxy(3, 11);
	printf(" 5-1. 만약 선택한 말이 우승했다면 배팅금액의 두배를 돌려받고,");

	gotoxy(3, 12);
	printf(" 5-2. 우승하지 못했다면 배팅금을 잃습니다.");

	dewhachang_clear();

	gotoxy(4, 20);
	printf("[경마장 딜러]");

	gotoxy(4, 22);
	printf("룰지를 보여드리겠습니다.");

	gotoxy(70, 24);
	printf("아무 버튼이나 눌러주세요_");

	button = _getch();
}

void draw_horse(int i, int r)
{
	gotoxy(4 + i, 1 + r);
	printf("    _____,,;;`");

	gotoxy(4 + i, 2 + r);
	printf(" ,~(  )  )~\\|");

	gotoxy(4 + i, 3 + r);
	printf("   /     |   ");

	Sleep(30);
}