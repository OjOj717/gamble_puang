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

	dewhachang("[Ȧ¦ ����]", "�÷��� �Ͻðڽ��ϱ�?", "[y] ��   [n] �ƴϿ� [r] ���� ��Ģ");

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
		dewhachang("[Ȧ¦ ����]", "�ٽ� ������ �ּ���.", " ");

		Sleep(300);
		goto play;

		break;
	}

	return P_none;
}

void HJ_yes()
{
yes:
	dewhachang("[Ȧ¦ ����]", "�����Ͻǰǰ���?", "[y] ��   [n] �ƴϿ� (����)");

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
		dewhachang("[���� ����]", "�ٽ� ������ �ּ���.", " ");

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

	dewhachang("[Ȧ¦ ����]", "������ �����帮�ڽ��ϴ�.", "�ƹ� ��ư�̳� �����ּ���_");
	button = _getch();
}

void HJ_yeonsoopmode()
{
	int cards[3][3] = { 0 };
	char action;

here:

	dewhachang_clear();

	gotoxy(4, 20);
	printf("[Ȧ¦ ����]");

	gotoxy(4, 22);
	printf("1. ���� Ȧ�� 2.���� ¦�� 3.���� ��� ���� 4.���� ��� ����");

	gotoxy(60, 24);
	printf("������ �ּ���_");

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
		card(cards[0][2], cards[1][2], 7, 46); //ī�� ���� ����

		if (action == '1')
		{
			if ((cards[1][0] + cards[1][1] + cards[1][2]) % 2 == 0)
			{
				dewhachang_clear();

				gotoxy(4, 20);
				printf("[Ȧ¦ ����]");

				gotoxy(4, 22);
				printf("WIN ���� Ȧ�� �Դϴ�!");

				gotoxy(60, 24);
				printf("�ƹ� ��ư�̳� �����ּ���_");

				button = _getch();
				holzzak();
			}
			else
			{
				dewhachang_clear();

				gotoxy(4, 20);
				printf("[Ȧ¦ ����]");

				gotoxy(4, 22);
				printf("LOSE ���� Ȧ���� �ƴմϴ�!");

				gotoxy(60, 24);
				printf("�ƹ� ��ư�̳� �����ּ���_");

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
				printf("[Ȧ¦ ����]");

				gotoxy(4, 22);
				printf("WIN ���� ¦�� �Դϴ�!");

				gotoxy(60, 24);
				printf("�ƹ� ��ư�̳� �����ּ���_");

				button = _getch();
				holzzak();
			}
			else
			{
				dewhachang_clear();

				gotoxy(4, 20);
				printf("[Ȧ¦ ����]");

				gotoxy(4, 22);
				printf("LOSE ���� ¦���� �ƴմϴ�!");

				gotoxy(60, 24);
				printf("�ƹ� ��ư�̳� �����ּ���_");

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
				printf("[Ȧ¦ ����]");

				gotoxy(4, 22);
				printf("WIN �� ī�尡 ��� ������ �Դϴ�!");

				gotoxy(60, 24);
				printf("�ƹ� ��ư�̳� �����ּ���_");

				button = _getch();
				holzzak();
			}
			else if (cards[0][0] % 2 == 1 && cards[0][1] % 2 == 1 && cards[0][2] % 2 == 1)
			{
				dewhachang_clear();

				gotoxy(4, 20);
				printf("[Ȧ¦ ����]");

				gotoxy(4, 22);
				printf("LOSE �� ī�尡 ��� ������ �Դϴ�!");

				gotoxy(60, 24);
				printf("�ƹ� ��ư�̳� �����ּ���_");

				button = _getch();
				holzzak();
			}
			else
			{
				dewhachang_clear();

				gotoxy(4, 20);
				printf("[Ȧ¦ ����]");

				gotoxy(4, 22);
				printf("LOSE �� ī���� ���� �ٸ��ϴ�.");

				gotoxy(60, 24);
				printf("�ƹ� ��ư�̳� �����ּ���_");

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
				printf("[Ȧ¦ ����]");

				gotoxy(4, 22);
				printf("LOSE �� ī�尡 ��� ������ �Դϴ�!");

				gotoxy(60, 24);
				printf("�ƹ� ��ư�̳� �����ּ���_");

				button = _getch();
				holzzak();
			}
			if (cards[0][0] % 2 == 1 && cards[0][1] % 2 == 1 && cards[0][2] % 2 == 1)
			{
				dewhachang_clear();

				gotoxy(4, 20);
				printf("[Ȧ¦ ����]");

				gotoxy(4, 22);
				printf("WIN �� ī�尡 ��� ������ �Դϴ�!");

				gotoxy(60, 24);
				printf("�ƹ� ��ư�̳� �����ּ���_");

				button = _getch();
				holzzak();
			}
			else
			{
				dewhachang_clear();

				gotoxy(4, 20);
				printf("[Ȧ¦ ����]");

				gotoxy(4, 22);
				printf("LOSE �� ī���� ���� �ٸ��ϴ�.");

				gotoxy(60, 24);
				printf("�ƹ� ��ư�̳� �����ּ���_");

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
	printf("[Ȧ¦ ����]");

	gotoxy(4, 22);
	printf("������ �ּ���.");

	gotoxy(70, 24);
	printf("���� �ݾ� : ");

	scanf_s("%lf", &betting);

	money -= betting;
	if (money < 0)
	{
		money += betting;

		dewhachang_clear();

		gotoxy(4, 20);
		printf("[Ȧ¦ ����]");

		gotoxy(4, 22);
		printf("���� �����Ѱ� ���׿�..");

		gotoxy(70, 24);
		printf("�ƹ� ��ư�̳� �����ּ���_");

		button = _getch();
		HJ_yes();
	}

	else
	{
		gotoxy(73, 8);
		printf("������ : %11.f", money);

	here:

		dewhachang_clear();

		gotoxy(4, 20);
		printf("[Ȧ¦ ����]");

		gotoxy(4, 22);
		printf("1. ���� Ȧ�� 2.���� ¦�� 3.���� ��� ���� 4.���� ��� ����");

		gotoxy(60, 24);
		printf("������ �ּ���_");

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
					printf("[Ȧ¦ ����]");

					gotoxy(4, 22);
					printf("WIN ���� Ȧ�� �Դϴ�! (���� �ݾ��� 1.8�� ����)");

					gotoxy(60, 24);
					printf("�ƹ� ��ư�̳� �����ּ���_");

					betting *= 1.8;
				}
				else
				{
					dewhachang_clear();

					gotoxy(4, 20);
					printf("[Ȧ¦ ����]");

					gotoxy(4, 22);
					printf("LOSE ���� Ȧ���� �ƴմϴ�!");

					gotoxy(60, 24);
					printf("�ƹ� ��ư�̳� �����ּ���_");

					betting *= 0;
				}
			}

			else if (action == '2')
			{
				if ((cards[1][0] + cards[1][1] + cards[1][2]) % 2 == 0)
				{
					dewhachang_clear();

					gotoxy(4, 20);
					printf("[Ȧ¦ ����]");

					gotoxy(4, 22);
					printf("WIN ���� ¦�� �Դϴ�! (���� �ݾ��� 1.9�� ����)");

					gotoxy(60, 24);
					printf("�ƹ� ��ư�̳� �����ּ���_");

					betting *= 1.9;
				}
				else
				{
					dewhachang_clear();

					gotoxy(4, 20);
					printf("[Ȧ¦ ����]");

					gotoxy(4, 22);
					printf("LOSE ���� ¦���� �ƴմϴ�!");

					gotoxy(60, 24);
					printf("�ƹ� ��ư�̳� �����ּ���_");

					betting *= 0;
				}
			}

			else if (action == '3')
			{
				if (cards[0][0] % 2 == 0 && cards[0][1] % 2 == 0 && cards[0][2] % 2 == 0)
				{
					dewhachang_clear();

					gotoxy(4, 20);
					printf("[Ȧ¦ ����]");

					gotoxy(4, 22);
					printf("WIN �� ī�尡 ��� ������ �Դϴ�! (���� �ݾ��� 3.2�� ����)");

					gotoxy(60, 24);
					printf("�ƹ� ��ư�̳� �����ּ���_");

					betting *= 3.2;
				}
				else if (cards[0][0] % 2 == 1 && cards[0][1] % 2 == 1 && cards[0][2] % 2 == 1)
				{
					dewhachang_clear();

					gotoxy(4, 20);
					printf("[Ȧ¦ ����]");

					gotoxy(4, 22);
					printf("LOSE �� ī�尡 ��� ������ �Դϴ�!");

					gotoxy(60, 24);
					printf("�ƹ� ��ư�̳� �����ּ���_");

					betting *= 0;
				}
				else
				{
					dewhachang_clear();

					gotoxy(4, 20);
					printf("[Ȧ¦ ����]");

					gotoxy(4, 22);
					printf("LOSE �� ī���� ���� �ٸ��ϴ�.");

					gotoxy(60, 24);
					printf("�ƹ� ��ư�̳� �����ּ���_");

					betting *= 0;
				}
			}

			else if (action == '4')
			{
				if (cards[0][0] % 2 == 0 && cards[0][1] % 2 == 0 && cards[0][2] % 2 == 0)
				{
					dewhachang_clear();

					gotoxy(4, 20);
					printf("[Ȧ¦ ����]");

					gotoxy(4, 22);
					printf("LOSE �� ī�尡 ��� ������ �Դϴ�!");

					gotoxy(60, 24);
					printf("�ƹ� ��ư�̳� �����ּ���_");

					betting *= 0;
				}
				if (cards[0][0] % 2 == 1 && cards[0][1] % 2 == 1 && cards[0][2] % 2 == 1)
				{
					dewhachang_clear();

					gotoxy(4, 20);
					printf("[Ȧ¦ ����]");

					gotoxy(4, 22);
					printf("WIN �� ī�尡 ��� ������ �Դϴ�! (���� �ݾ��� 3.3�� ����)");

					gotoxy(60, 24);
					printf("�ƹ� ��ư�̳� �����ּ���_");

					betting *= 3.3;
				}
				else
				{
					dewhachang_clear();

					gotoxy(4, 20);
					printf("[Ȧ¦ ����]");

					gotoxy(4, 22);
					printf("LOSE �� ī���� ���� �ٸ��ϴ�.");

					gotoxy(60, 24);
					printf("�ƹ� ��ư�̳� �����ּ���_");

					betting *= 0;
				}
			}

		}

		money += betting;
		button = _getch();
	}
}