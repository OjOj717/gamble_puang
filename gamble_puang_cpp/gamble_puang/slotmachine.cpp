#include "gamble_puang.h"

void slot_yes();
void slot_rule();
void slot_yeonsoopmode();
void slot_realmode();
void slotslot(int a);

int slotmachine()
{
play:
	mainwhameon_clear();

	gotoxy(8, 4);
	printf("┌───────────────────────7─7─7───────────────────────┐");
	gotoxy(8, 5);
	printf("│                                                   │");
	gotoxy(8, 9);
	printf("│                                                   │");
	gotoxy(8, 10);
	printf("├───────────────────────────────────────────────────┤");
	gotoxy(8, 11);
	printf("│                                                   │");
	gotoxy(8, 12);
	printf("│                                                   │");
	gotoxy(8, 13);
	printf("└───────────────────────────────────────────────────┘");

	gotoxy(12, 15);
	printf(" ♠♠♠ * 1.0 / ◆◆◆ * 1.1 / ♥♥♥ * 1.2 / ♣♣♣ * 1.3 ");

	gotoxy(18, 17);
	printf("000 * 0.5 / ◑◑◑ * 2 / 777 * 3.0");

	gotoxy(61, 7);
	printf("━━┛");
	gotoxy(63, 6);
	printf("┃");
	gotoxy(63, 5);
	printf("○");

	textcolor(7);

	gotoxy(20, 6);
	printf("?");

	gotoxy(34, 6);
	printf("?");

	gotoxy(48, 6);
	printf("?");

	textcolor(13);

	gotoxy(20, 7);
	printf("?");

	gotoxy(34, 7);
	printf("?");

	gotoxy(48, 7);
	printf("?");

	textcolor(7);

	gotoxy(20, 8);
	printf("?");

	gotoxy(34, 8);
	printf("?");

	gotoxy(48, 8);
	printf("?");

	textcolor(15); //슬롯 머신 출력

	print_money();

	dewhachang("[슬롯머신 딜러]", "플레이 하시겠습니까?", "[y] 예   [n] 아니오 [r] 게임 규칙");

	button = _getch();

	switch (button)
	{
	case 'y':
	case 'Y':
		slot_yes();
		goto play;
		break;

	case 'n':
	case 'N':
		return P_none;
		break;

	case 'r':
	case 'R':
		slot_rule();
		goto play;
		break;

	default:
		dewhachang("[슬롯머신 딜러]", "다시 선택해 주세요.", " ");

		Sleep(300);
		goto play;
		break;
	}

	return P_none;
}

void slot_yes()
{
yes:
	dewhachang("[슬롯머신 딜러]", "연습하실건가요?", "[y] 예   [n] 아니오 (실전)");

	switch (button = _getch())
	{
	case 'y':
	case 'Y':
		slot_yeonsoopmode();
		break;

	case 'n':
	case 'N':
		slot_realmode();
		break;

	default:
		dewhachang("[슬롯머신 딜러]", "다시 선택해 주세요.", " ");

		Sleep(300);
		goto yes;
		break;
	}
}

void slot_rule()
{
	mainwhameon_clear();

	gotoxy(3, 1);
	printf("<< SLOT MACHINE >>");

	gotoxy(3, 2);
	printf(" 슬롯 머신이란 돌아가는 실린더를 멈춰 세개의 실린더에 같은 그림이");

	gotoxy(3, 3);
	printf(" 나오게 만들면 상금을 딸 수 있는 상자형 자동 도박기입니다.");

	gotoxy(3, 5);
	printf("- 게임 방법");

	gotoxy(3, 6);
	printf(" 1. 연습 모드와 배팅 모드를 선택합니다.");

	gotoxy(3, 7);
	printf(" 2. 배팅 모드라면 배팅 금액을 입력합니다.");

	gotoxy(3, 8);
	printf(" 3. Enter를 눌러 각각의 실린더를 멈춥니다.");

	gotoxy(3, 9);
	printf(" 4-1. 세개의 그림이 다르다면 패배로 배팅 금액을 돌려받지 못하고,");

	gotoxy(3, 10);
	printf(" 4-2. 세개의 그림이 같다면 승리로 배팅 금액에 맞춘 그림에 ");

	gotoxy(3, 11);
	printf("      해당하는 배율을 곱한만큼 돈을 지급 받습니다.");

	gotoxy(3, 13);
	printf("   ♠♠♠ => 1.0배 지급   /   000 => 0.5배 지급");

	gotoxy(3, 14);
	printf("   ◆◆◆ => 1.1배 지급   /   ◑◑◑ => 2.0배 지급");

	gotoxy(3, 15);
	printf("   ♥♥♥ => 1.2배 지급   /   777 => 3.0배 지급");

	gotoxy(3, 16);
	printf("   ♣♣♣ => 1.3배 지급");

	dewhachang_clear();

	gotoxy(4, 20);
	printf("[슬롯머신 딜러]");

	gotoxy(4, 22);
	printf("룰지를 보여드리겠습니다.");

	gotoxy(70, 24);
	printf("아무 버튼이나 눌러주세요_");

	button = _getch();
}

void slot_yeonsoopmode()
{
	int first_slot = 0, second_slot = 0, third_slot = 0;
	int stop = 0;

	dewhachang_clear();

	gotoxy(4, 20);
	printf("[슬롯머신 딜러]");

	gotoxy(4, 22);
	printf("멈추려면 Enter를 눌러주세요.");

	gotoxy(80, 24);
	printf("[ Enter ]");

	gotoxy(20, 7); //첫번째 슬롯 돌리기
	textcolor(13);
	slotslot(first_slot);

	gotoxy(20, 6);
	textcolor(7);
	if (first_slot == 6)
	{
		slotslot(0);
	}
	else
	{
		slotslot(first_slot + 1);
	}

	gotoxy(20, 7);
	textcolor(13);
	slotslot(first_slot);

	while (stop == 0)
	{
		gotoxy(20, 8);
		textcolor(7);
		slotslot(first_slot);

		if (first_slot == 6)
		{
			first_slot = 0;
		}
		else
		{
			first_slot += 1;
		}

		gotoxy(20, 7);
		textcolor(13);
		slotslot(first_slot);

		gotoxy(20, 6);
		textcolor(7);
		if (first_slot == 6)
		{
			slotslot(0);
		}
		else
		{
			slotslot(first_slot + 1);
		}

		if (_kbhit() == 1)
		{
			if (_getch() == 13)
				stop = 1;
		}

	}

	stop = 0;

	gotoxy(34, 7); //두번째 슬롯 돌리기
	textcolor(13);
	slotslot(second_slot);

	gotoxy(34, 6);
	textcolor(7);
	if (second_slot == 6)
	{
		slotslot(0);
	}
	else
	{
		slotslot(second_slot + 1);
	}

	gotoxy(34, 7);
	textcolor(13);
	slotslot(second_slot);

	while (stop == 0)
	{
		gotoxy(34, 8);
		textcolor(7);
		slotslot(second_slot);

		if (second_slot == 6)
		{
			second_slot = 0;
		}
		else
		{
			second_slot += 1;
		}

		gotoxy(34, 7);
		textcolor(13);
		slotslot(second_slot);

		gotoxy(34, 6);
		textcolor(7);
		if (second_slot == 6)
		{
			slotslot(0);
		}
		else
		{
			slotslot(second_slot + 1);
		}

		if (_kbhit() == 1)
		{
			if (_getch() == 13)
				stop = 1;
		}

	}

	stop = 0;

	gotoxy(48, 7); //세번째 슬롯 돌리기
	textcolor(13);
	slotslot(third_slot);

	gotoxy(48, 6);
	textcolor(7);
	if (third_slot == 6)
	{
		slotslot(0);
	}
	else
	{
		slotslot(third_slot + 1);
	}

	gotoxy(48, 7);
	textcolor(13);
	slotslot(third_slot);

	while (stop == 0)
	{
		gotoxy(48, 8);
		textcolor(7);
		slotslot(third_slot);

		if (third_slot == 6)
		{
			third_slot = 0;
		}
		else
		{
			third_slot += 1;
		}

		gotoxy(48, 7);
		textcolor(13);
		slotslot(third_slot);

		gotoxy(48, 6);
		textcolor(7);
		if (third_slot == 6)
		{
			slotslot(0);
		}
		else
		{
			slotslot(third_slot + 1);
		}

		if (_kbhit() == 1)
		{
			if (_getch() == 13)
				stop = 1;
		}

	}

	if (first_slot == second_slot && second_slot == third_slot) //결과 출력
	{
		if (first_slot == 0)
		{
			dewhachang_clear();

			gotoxy(4, 20);
			printf("[슬롯머신 딜러]");

			gotoxy(4, 22);
			printf("♣세개를 맞췄습니다!");

			gotoxy(70, 24);
			printf("아무 버튼이나 눌러주세요_");

			button = _getch();
		}
		else if (first_slot == 1)
		{
			dewhachang_clear();

			gotoxy(4, 20);
			printf("[슬롯머신 딜러]");

			gotoxy(4, 22);
			printf("♥세개를 맞췄습니다!");

			gotoxy(70, 24);
			printf("아무 버튼이나 눌러주세요_");

			button = _getch();
		}
		else if (first_slot == 2)
		{
			dewhachang_clear();

			gotoxy(4, 20);
			printf("[슬롯머신 딜러]");

			gotoxy(4, 22);
			printf("◑세개를 맞췄습니다!");

			gotoxy(70, 24);
			printf("아무 버튼이나 눌러주세요_");

			button = _getch();
		}
		else if (first_slot == 3)
		{
			dewhachang_clear();

			gotoxy(4, 20);
			printf("[슬롯머신 딜러]");

			gotoxy(4, 22);
			printf("♠세개를 맞췄습니다!");

			gotoxy(70, 24);
			printf("아무 버튼이나 눌러주세요_");

			button = _getch();
		}
		else if (first_slot == 4)
		{
			dewhachang_clear();

			gotoxy(4, 20);
			printf("[슬롯머신 딜러]");

			gotoxy(4, 22);
			printf("0세개를 맞췄습니다!");

			gotoxy(70, 24);
			printf("아무 버튼이나 눌러주세요_");

			button = _getch();
		}
		else if (first_slot == 5)
		{
			dewhachang_clear();

			gotoxy(4, 20);
			printf("[슬롯머신 딜러]");

			gotoxy(4, 22);
			printf("◆세개를 맞췄습니다!");

			gotoxy(70, 24);
			printf("아무 버튼이나 눌러주세요_");

			button = _getch();
		}
		else if (first_slot == 6)
		{
			dewhachang_clear();

			gotoxy(4, 20);
			printf("[슬롯머신 딜러]");

			gotoxy(4, 22);
			printf("7세개를 맞췄습니다!");

			gotoxy(70, 24);
			printf("아무 버튼이나 눌러주세요_");

			button = _getch();
		}
	}
	else
	{
		dewhachang_clear();

		gotoxy(4, 20);
		printf("[슬롯머신 딜러]");

		gotoxy(4, 22);
		printf("실패했습니다!");

		gotoxy(60, 24);
		printf("아무 버튼이나 눌러주세요_");

		button = _getch();
	}
}

void slot_realmode()
{
	int first_slot = 0, second_slot = 0, third_slot = 0;
	int stop = 0;
	int betting = 0;//얼마를 배팅할까?

	dewhachang_clear();

	gotoxy(4, 20);
	printf("[슬롯머신 딜러]");

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
		printf("[슬롯머신 딜러]");

		gotoxy(4, 22);
		printf("돈이 부족한것 같네요..");

		gotoxy(70, 24);
		printf("아무 버튼이나 눌러주세요_");

		button = _getch();
		slot_yes();
	}

	else
	{
		gotoxy(73, 8);
		printf("소지금 : %11.f", money);

		dewhachang_clear();

		gotoxy(4, 20);
		printf("[슬롯머신 딜러]");

		gotoxy(4, 22);
		printf("멈추려면 Enter를 눌러주세요.");

		gotoxy(80, 24);
		printf("[ Enter ]");

		gotoxy(20, 7); //첫번째 슬롯 돌리기
		textcolor(13);
		slotslot(first_slot);

		gotoxy(20, 6);
		textcolor(7);
		if (first_slot == 6)
		{
			slotslot(0);
		}
		else
		{
			slotslot(first_slot + 1);
		}

		gotoxy(20, 7);
		textcolor(13);
		slotslot(first_slot);

		while (stop == 0)
		{
			gotoxy(20, 8);
			textcolor(7);
			slotslot(first_slot);

			if (first_slot == 6)
			{
				first_slot = 0;
			}
			else
			{
				first_slot += 1;
			}

			gotoxy(20, 7);
			textcolor(13);
			slotslot(first_slot);

			gotoxy(20, 6);
			textcolor(7);
			if (first_slot == 6)
			{
				slotslot(0);
			}
			else
			{
				slotslot(first_slot + 1);
			}

			if (_kbhit() == 1)
			{
				if (_getch() == 13)
					stop = 1;
			}

		}

		stop = 0;

		gotoxy(34, 7); //두번째 슬롯 돌리기
		textcolor(13);
		slotslot(second_slot);

		gotoxy(34, 6);
		textcolor(7);
		if (second_slot == 6)
		{
			slotslot(0);
		}
		else
		{
			slotslot(second_slot + 1);
		}

		gotoxy(34, 7);
		textcolor(13);
		slotslot(second_slot);

		while (stop == 0)
		{
			gotoxy(34, 8);
			textcolor(7);
			slotslot(second_slot);

			if (second_slot == 6)
			{
				second_slot = 0;
			}
			else
			{
				second_slot += 1;
			}

			gotoxy(34, 7);
			textcolor(13);
			slotslot(second_slot);

			gotoxy(34, 6);
			textcolor(7);
			if (second_slot == 6)
			{
				slotslot(0);
			}
			else
			{
				slotslot(second_slot + 1);
			}

			if (_kbhit() == 1)
			{
				if (_getch() == 13)
					stop = 1;
			}

		}

		stop = 0;

		gotoxy(48, 7); //세번째 슬롯 돌리기
		textcolor(13);
		slotslot(third_slot);

		gotoxy(48, 6);
		textcolor(7);
		if (third_slot == 6)
		{
			slotslot(0);
		}
		else
		{
			slotslot(third_slot + 1);
		}

		gotoxy(48, 7);
		textcolor(13);
		slotslot(third_slot);

		while (stop == 0)
		{
			gotoxy(48, 8);
			textcolor(7);
			slotslot(third_slot);

			if (third_slot == 6)
			{
				third_slot = 0;
			}
			else
			{
				third_slot += 1;
			}

			gotoxy(48, 7);
			textcolor(13);
			slotslot(third_slot);

			gotoxy(48, 6);
			textcolor(7);
			if (third_slot == 6)
			{
				slotslot(0);
			}
			else
			{
				slotslot(third_slot + 1);
			}

			if (_kbhit() == 1)
			{
				if (_getch() == 13)
					stop = 1;
			}

		}

		if (first_slot == second_slot && second_slot == third_slot)
		{
			if (first_slot == 0)
			{
				dewhachang_clear();

				gotoxy(4, 20);
				printf("[슬롯머신 딜러]");

				gotoxy(4, 22);
				printf("♣세개를 맞췄습니다! (배팅 금액의 2배 지급)");

				gotoxy(70, 24);
				printf("아무 버튼이나 눌러주세요");

				money += betting * 2;

				button = _getch();
			}
			else if (first_slot == 1)
			{
				dewhachang_clear();

				gotoxy(4, 20);
				printf("[슬롯머신 딜러]");

				gotoxy(4, 22);
				printf("♥세개를 맞췄습니다!");

				gotoxy(70, 24);
				printf("아무 버튼이나 눌러주세요");

				money += betting * 1.8;

				button = _getch();
			}
			else if (first_slot == 2)
			{
				dewhachang_clear();

				gotoxy(4, 20);
				printf("[슬롯머신 딜러]");

				gotoxy(4, 22);
				printf("◑세개를 맞췄습니다!");

				gotoxy(70, 24);
				printf("아무 버튼이나 눌러주세요");

				money += betting * 2;

				button = _getch();
			}
			else if (first_slot == 3)
			{
				dewhachang_clear();

				gotoxy(4, 20);
				printf("[슬롯머신 딜러]");

				gotoxy(4, 22);
				printf("♠세개를 맞췄습니다!");

				gotoxy(70, 24);
				printf("아무 버튼이나 눌러주세요");

				money += betting;

				button = _getch();
			}
			else if (first_slot == 4)
			{
				dewhachang_clear();

				gotoxy(4, 20);
				printf("[슬롯머신 딜러]");

				gotoxy(4, 22);
				printf("0세개를 맞췄습니다!");

				gotoxy(70, 24);
				printf("아무 버튼이나 눌러주세요");

				money += betting * 0.5;

				button = _getch();
			}
			else if (first_slot == 5)
			{
				dewhachang_clear();

				gotoxy(4, 20);
				printf("[슬롯머신 딜러]");

				gotoxy(4, 22);
				printf("◆세개를 맞췄습니다!");

				gotoxy(70, 24);
				printf("아무 버튼이나 눌러주세요");

				money += betting * 1.3;

				button = _getch();
			}
			else if (first_slot == 6)
			{
				dewhachang_clear();

				gotoxy(4, 20);
				printf("[슬롯머신 딜러]");

				gotoxy(4, 22);
				printf("7세개를 맞췄습니다!");

				gotoxy(70, 24);
				printf("아무 버튼이나 눌러주세요");

				money += betting * 3;

				button = _getch();
			}
		}
		else
		{
			dewhachang_clear();

			gotoxy(4, 20);
			printf("[슬롯머신 딜러]");

			gotoxy(4, 22);
			printf("실패했습니다!");

			gotoxy(60, 24);
			printf("아무 버튼이나 눌러주세요");

			button = _getch();
		}
	}
}

void slotslot(int a)
{
	switch (a)
	{
	case 0:
		printf("♣");
		Sleep(100);
		break;
	case 1:
		printf("♥");
		Sleep(120);
		break;
	case 2:
		printf("◑");
		Sleep(50);
		break;
	case 3:
		printf("♠");
		Sleep(160);
		break;
	case 4:
		printf("0");
		Sleep(200);
		break;
	case 5:
		printf("◆");
		Sleep(140);
		break;
	case 6:
		printf("7");
		Sleep(20);
		break;
	default:
		break;
	}
}