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
	printf("������ : %11.f", money);

	card(5, 0, 7, 20);
	card(5, 0, 7, 33);
	card(5, 0, 7, 46);

	dewhachang_clear();

	gotoxy(4, 20);
	printf("[Ȧ¦ ����]");

	gotoxy(4, 22);
	printf("�÷��� �Ͻðڽ��ϱ�?");

	gotoxy(60, 24);
	printf("[y] ��   [n] �ƴϿ� [r] ���� ��Ģ");

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
		printf("[��Ŀ ����]");
		gotoxy(4, 22);
		printf("�ٽ� ������ �ּ���.");
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
	printf("[Ȧ¦ ����]");

	gotoxy(4, 22);
	printf("�����Ͻǰǰ���?");

	gotoxy(70, 24);
	printf("[y] ��   [n] �ƴϿ� (����)");

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
		printf("�ٽ� ������ �ּ���.");
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
	printf(" Ȧ¦�� A���� 10���� ī�� ������ ������ ");

	gotoxy(3, 3);
	printf(" ������ ī������ Ȧ������ ¦������, ��� � ������ �����ϴ� �����Դϴ�.");

	gotoxy(3, 5);
	printf("- ���� ���");

	gotoxy(3, 6);
	printf(" 1. ���� ���� ���� ��带 �����մϴ�.");

	gotoxy(3, 7);
	printf(" 2. ���� ����� ���� �ݾ��� �Է��մϴ�.");

	gotoxy(3, 8);
	printf(" 3. ������ ī������ Ȧ������ ¦������, ��� � ������ �����մϴ�.");

	gotoxy(3, 9);
	printf(" 4. ������ ī�带 �������ϴ�.");

	gotoxy(3, 10);
	printf(" 5. ������ �¾Ҵٸ� ������ ���� ����� ����ϴ�.");

	gotoxy(3, 12);
	printf(" ī�� ���� Ȧ�� : 1.8�� ����");

	gotoxy(3, 13);
	printf(" ī�� ���� ¦�� : 1.9�� ����");

	gotoxy(3, 14);
	printf("   ī�� ������ ��� ���� : 3.2�� ����");

	gotoxy(3, 15);
	printf("  ī�� ������ ��� ���� : 3.3�� ����");

	dewhachang_clear();

	gotoxy(4, 20);
	printf("[Ȧ¦ ����]");

	gotoxy(4, 22);
	printf("������ �����帮�ڽ��ϴ�.");

	gotoxy(70, 24);
	printf("�ƹ� ��ư�̳� �����ּ���_");

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
	printf("[Ȧ¦ ����]");

	gotoxy(4, 22);
	printf("1. ���� Ȧ�� 2.���� ¦�� 3.���� ��� ���� 4.���� ��� ����");

	gotoxy(60, 24);
	printf("������ �ּ���_");

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

				getch();
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
				printf("[Ȧ¦ ����]");

				gotoxy(4, 22);
				printf("WIN ���� ¦�� �Դϴ�!");

				gotoxy(60, 24);
				printf("�ƹ� ��ư�̳� �����ּ���_");

				getch();
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
				printf("[Ȧ¦ ����]");

				gotoxy(4, 22);
				printf("WIN �� ī�尡 ��� ������ �Դϴ�!");

				gotoxy(60, 24);
				printf("�ƹ� ��ư�̳� �����ּ���_");

				getch();
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

				getch();
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
				printf("[Ȧ¦ ����]");

				gotoxy(4, 22);
				printf("LOSE �� ī�尡 ��� ������ �Դϴ�!");

				gotoxy(60, 24);
				printf("�ƹ� ��ư�̳� �����ּ���_");

				getch();
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

				getch();
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
	printf("[Ȧ¦ ����]");

	gotoxy(4, 22);
	printf("������ �ּ���.");

	gotoxy(70, 24);
	printf("���� �ݾ� : ");

	scanf_s("%d", &betting);

	money -= betting;
	if (money < 0)
	{
		money += betting;

		dewhachang_clear();

		gotoxy(4, 20);
		printf("[���� ����]");

		gotoxy(4, 22);
		printf("���� �����Ѱ� ���׿�..");

		gotoxy(70, 24);
		printf("�ƹ� ��ư�̳� �����ּ���_");

		getch();
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
					printf("[Ȧ¦ ����]");

					gotoxy(4, 22);
					printf("WIN ���� Ȧ�� �Դϴ�! (���� �ݾ��� 1.8�� ����)");

					gotoxy(60, 24);
					printf("�ƹ� ��ư�̳� �����ּ���_");

					betting *= 1.8;

					getch();
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
					printf("[Ȧ¦ ����]");

					gotoxy(4, 22);
					printf("WIN ���� ¦�� �Դϴ�! (���� �ݾ��� 1.9�� ����)");

					gotoxy(60, 24);
					printf("�ƹ� ��ư�̳� �����ּ���_");

					betting *= 1.9;

					getch();
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
					printf("[Ȧ¦ ����]");

					gotoxy(4, 22);
					printf("WIN �� ī�尡 ��� ������ �Դϴ�! (���� �ݾ��� 3.2�� ����)");

					gotoxy(60, 24);
					printf("�ƹ� ��ư�̳� �����ּ���_");

					betting *= 3.2;

					getch();
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

					betting *= 0;

					getch();
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
					printf("[Ȧ¦ ����]");

					gotoxy(4, 22);
					printf("LOSE �� ī�尡 ��� ������ �Դϴ�!");

					gotoxy(60, 24);
					printf("�ƹ� ��ư�̳� �����ּ���_");

					betting *= 0;

					getch();
					holzzak();
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

					getch();
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