#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>

extern double money;
extern int mmove;

int BJ_yes(); //���ӽ���
int BJ_rule(); //���ӷ�
int BJ_yeonsoopmode();
int BJ_realmode();
int BJ_Agasheepililddehap(int card[][10], int num); //A�� 11�϶� ��
int BJ_hap(int card[][10], int num); //���� ī����

int BJ_num = 0;

int blackjack()
{
	char sigakbutton;
	int banbok=0;

	mainwhameon_clear();

	gotoxy(73, 8);
	printf("������ : %11.f", money);

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
	printf("[���� ����]");

	gotoxy(4, 22);
	printf("�÷��� �Ͻðڽ��ϱ�?");

	gotoxy(60, 24);
	printf("[y] ��   [n] �ƴϿ� [r] ���� ��Ģ");

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
			printf("[��Ŀ ����]");
			gotoxy(4, 22);
			printf("�ٽ� ������ �ּ���.");
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
	printf("[���� ����]");

	gotoxy(4, 22);
	printf("�����Ͻǰǰ���?");

	gotoxy(70, 24);
	printf("[y] ��   [n] �ƴϿ� (����)");

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
		printf("�ٽ� ������ �ּ���.");
		break;
	}

	return 0;
}

int BJ_yeonsoopmode()
{
	int dealer[10][10] = { 0 }, player[10][10] = { 0 }; //������ �÷��̾��� ī��
	int dnum = 0, pnum = 0; //���� ������ �÷��̾��� ī�� ����
	char action; //��Ʈ or ������

	dewhachang_clear();

	srand((unsigned)time(NULL));
	dealer[1][0] = rand() % 13 + 1;
	dealer[0][0] = rand() % 4;
	dnum += 1;
	srand(rand());
	dealer[1][1] = rand() % 13 + 1;
	dealer[0][1] = rand() % 4;
	dnum += 1; //���� ī�� ���� �ޱ�

	card(dealer[0][0], dealer[1][0], 3, 5);

	srand((unsigned)time(NULL) + rand());
	player[1][0] = rand() % 13 + 1;
	player[0][0] = rand() % 4;
	pnum += 1;
	srand(rand());
	player[1][1] = rand() % 13 + 1;
	player[0][1] = rand() % 4;
	pnum += 1; //�÷��̾� ī�� ���� �ޱ�

	card(player[0][0], player[1][0], 11, 5);
	card(player[0][1], player[1][1], 11, 13);

	if (BJ_hap(player, pnum) == 21) //�÷��̾ ������ ��� �ٷ� �¸�
	{
		dewhachang_clear();

		gotoxy(4, 20);
		printf("[���� ����]");

		gotoxy(4, 22);
		printf("�������� �̱�̽��ϴ�!!");

		gotoxy(70, 24);
		printf("�ƹ� ��ư�̳� �����ּ���_");

		getch();
		blackjack();
	}

	else
	{
		dewhachang_clear();

		gotoxy(4, 20);
		printf("[���� ����]");

		gotoxy(4, 22);
		printf("��Ʈ�� �Ͻ��� ���ٵ带 �Ͻ��� ����ּ���.");

		gotoxy(70, 24);
		printf("[h] ��Ʈ  [s] ���ٵ�");

		action = getch(); //��Ʈ,���ٵ� ����

		while (action == 'h')
		{
			srand(rand());
			player[1][pnum] = rand() % 13 + 1;
			player[0][pnum] = rand() % 4;
			pnum += 1; //�÷��̾� ī�� ���� ��

			card(player[0][pnum - 1], player[1][pnum - 1], 11, 5 + (pnum - 1) * 8);

			if (BJ_hap(player, pnum) >= 21)
				action = 's'; //21�̻��̸� ��Ʈ �Ұ�

			else //��Ʈ,���ٵ� �ѹ��� ����
			{
				dewhachang_clear();

				gotoxy(4, 20);
				printf("[���� ����]");

				gotoxy(4, 22);
				printf("��Ʈ�� �Ͻ��� ���ٵ带 �Ͻ��� ����ּ���.");

				gotoxy(70, 24);
				printf("[h] ��Ʈ  [s] ���ٵ�");

				action = getch();
			}
		}

		if (BJ_hap(player, pnum) > 21) //21 ������ ����Ʈ�� �й�
		{
			dewhachang_clear();

			gotoxy(4, 20);
			printf("[���� ����]");

			gotoxy(4, 22);
			printf("BURST ���� 21�� �Ѿ����ϴ�!");

			gotoxy(70, 24);
			printf("�ƹ� ��ư�̳� �����ּ���_");

			getch();
			blackjack();
		}

		else
		{
			card(dealer[0][1], dealer[1][1], 3, 13);
			while (BJ_hap(dealer, dnum) < 16) //������ ���� 16 �̸��̶�� ī�� �� �ޱ�
			{
				srand(rand());
				dealer[1][dnum] = rand() % 13 + 1;
				dealer[0][dnum] = rand() % 4;
				dnum += 1;

				card(dealer[0][dnum - 1], dealer[1][dnum - 1], 3, 5 + (dnum - 1) * 8);
			}

			if (BJ_hap(dealer, dnum) == BJ_hap(player, pnum)) //���� ���ٸ� ���º�
			{
				dewhachang_clear();

				gotoxy(4, 20);
				printf("[���� ����]");

				gotoxy(4, 22);
				printf("PUSH ���º� �Դϴ�!");

				gotoxy(70, 24);
				printf("�ƹ� ��ư�̳� �����ּ���_");

				getch();
				blackjack();
			}

			else if (BJ_hap(dealer, dnum) > 21) //������ 21 ������ ����Ʈ�� �¸�
			{
				dewhachang_clear();

				gotoxy(4, 20);
				printf("[���� ����]");

				gotoxy(4, 22);
				printf("DEALER BURST ������ ���� 21�� �Ѿ����ϴ�!");

				gotoxy(70, 24);
				printf("�ƹ� ��ư�̳� �����ּ���_");

				getch();
				blackjack();
			}

			else if (BJ_hap(dealer, dnum) > BJ_hap(player, pnum)) //������ ���� �� ũ�ٸ� �й�
			{
				dewhachang_clear();

				gotoxy(4, 20);
				printf("[���� ����]");

				gotoxy(4, 22);
				printf("LOSE ������ ���� 21�� �� �������ϴ�!");

				gotoxy(70, 24);
				printf("�ƹ� ��ư�̳� �����ּ���_");

				getch();
				blackjack();
			}

			else //�÷��̾� �¸�
			{
				dewhachang_clear();

				gotoxy(4, 20);
				printf("[���� ����]");

				gotoxy(4, 22);
				printf("WIN �̰���ϴ�!");

				gotoxy(70, 24);
				printf("�ƹ� ��ư�̳� �����ּ���_");

				getch();
				blackjack();
			}
		}

	}

	return 0;
}

int BJ_realmode()
{
	int dealer[10][10] = { 0 }, player[10][10] = { 0 }; //������ �÷��̾��� ī��
	int dnum = 0, pnum = 0; //���� ������ �÷��̾��� ī�� ����
	char action; //��Ʈ or ������
	int betting = 0;//�󸶸� �����ұ�?

	dewhachang_clear();

	gotoxy(4, 20);
	printf("[���� ����]");

	gotoxy(4, 22);
	printf("�󸶸� �����Ͻðڽ��ϱ�?");

	gotoxy(60, 24);
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
		BJ_yes();
	}

	else
	{

		gotoxy(73, 8);
		printf("������ : %11.f", money);

		srand((unsigned)time(NULL));
		dealer[1][0] = rand() % 13 + 1;
		dealer[0][0] = rand() % 4;
		dnum += 1;
		srand(rand());
		dealer[1][1] = rand() % 13 + 1;
		dealer[0][1] = rand() % 4;
		dnum += 1; //���� ī�� ���� �ޱ�

		card(dealer[0][0], dealer[1][0], 3, 5);

		srand((unsigned)time(NULL) + rand());
		player[1][0] = rand() % 13 + 1;
		player[0][0] = rand() % 4;
		pnum += 1;
		srand(rand());
		player[1][1] = rand() % 13 + 1;
		player[0][1] = rand() % 4;
		pnum += 1; //�÷��̾� ī�� ���� �ޱ�

		card(player[0][0], player[1][0], 11, 5);
		card(player[0][1], player[1][1], 11, 13);

		if (BJ_hap(player, pnum) == 21) //�÷��̾ ������ ��� �ٷ� �¸�
		{
			dewhachang_clear();

			gotoxy(4, 20);
			printf("[���� ����]");

			gotoxy(4, 22);
			printf("�������� �̱�̽��ϴ�!! (���� �ݾ� 3�� ����)");

			gotoxy(70, 24);
			printf("�ƹ� ��ư�̳� �����ּ���_");

			betting *= 3;

			getch();
			blackjack();
		}

		else
		{
			dewhachang_clear();

			gotoxy(4, 20);
			printf("[���� ����]");

			gotoxy(4, 22);
			printf("��Ʈ�� �Ͻ��� ���ٵ带 �Ͻ��� ����ּ���.");

			gotoxy(70, 24);
			printf("[h] ��Ʈ  [s] ���ٵ�");

			action = getch(); //��Ʈ,���ٵ� ����

			while (action == 'h')
			{
				srand(rand());
				player[1][pnum] = rand() % 13 + 1;
				player[0][pnum] = rand() % 4;
				pnum += 1; //�÷��̾� ī�� ���� ��

				card(player[0][pnum - 1], player[1][pnum - 1], 11, 5 + (pnum - 1) * 8);

				if (BJ_hap(player, pnum) >= 21)
					action = 's'; //21�̻��̸� ��Ʈ �Ұ�

				else //��Ʈ,���ٵ� �ѹ��� ����
				{
					dewhachang_clear();

					gotoxy(4, 20);
					printf("[���� ����]");

					gotoxy(4, 22);
					printf("��Ʈ�� �Ͻ��� ���ٵ带 �Ͻ��� ����ּ���.");

					gotoxy(70, 24);
					printf("[h] ��Ʈ  [s] ���ٵ�");

					action = getch();
				}
			}

			if (BJ_hap(player, pnum) > 21) //21 ������ ����Ʈ�� �й�
			{
				dewhachang_clear();

				gotoxy(4, 20);
				printf("[���� ����]");

				gotoxy(4, 22);
				printf("BURST ���� 21�� �Ѿ����ϴ�! (���� �ݾ� �Ҹ�)");

				gotoxy(70, 24);
				printf("�ƹ� ��ư�̳� �����ּ���_");

				betting *= 0;
			}

			else
			{
				card(dealer[0][1], dealer[1][1], 3, 13);
				while (BJ_hap(dealer, dnum) < 16) //������ ���� 16 �̸��̶�� ī�� �� �ޱ�
				{
					srand(rand());
					dealer[1][dnum] = rand() % 13 + 1;
					dealer[0][dnum] = rand() % 4;
					dnum += 1;

					card(dealer[0][dnum - 1], dealer[1][dnum - 1], 3, 5 + (dnum - 1) * 8);
				}

				if (BJ_hap(dealer, dnum) == BJ_hap(player, pnum)) //���� ���ٸ� ���º�
				{
					dewhachang_clear();

					gotoxy(4, 20);
					printf("[���� ����]");

					gotoxy(4, 22);
					printf("PUSH ���º� �Դϴ�! (���� �ݾ� �״�� ����)");

					gotoxy(70, 24);
					printf("�ƹ� ��ư�̳� �����ּ���_");
				}

				else if (BJ_hap(dealer, dnum) > 21) //������ 21 ������ ����Ʈ�� �¸�
				{
					dewhachang_clear();

					gotoxy(4, 20);
					printf("[���� ����]");

					gotoxy(4, 22);
					printf("DEALER BURST ������ ���� 21�� �Ѿ����ϴ�! (���� �ݾ� 2�� ����)");

					gotoxy(70, 24);
					printf("�ƹ� ��ư�̳� �����ּ���_");

					betting *= 2;
				}

				else if (BJ_hap(dealer, dnum) > BJ_hap(player, pnum)) //������ ���� �� ũ�ٸ� �й�
				{
					dewhachang_clear();

					gotoxy(4, 20);
					printf("[���� ����]");

					gotoxy(4, 22);
					printf("LOSE ������ ���� 21�� �� �������ϴ�! (���� �ݾ� �Ҹ�)");

					gotoxy(70, 24);
					printf("�ƹ� ��ư�̳� �����ּ���_");

					betting *= 0;
				}

				else //�÷��̾� �¸�
				{
					dewhachang_clear();

					gotoxy(4, 20);
					printf("[���� ����]");

					gotoxy(4, 22);
					printf("WIN �̰���ϴ�! (���� �ݾ� 2�� ����)");

					gotoxy(70, 24);
					printf("�ƹ� ��ư�̳� �����ּ���_");

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
	printf(" ������ 2�� �̻��� ī�带 ������ �� �հ踦 21���� �������� ");

	gotoxy(3, 3);
	printf(" ����� ������ ������ �º��ϴ� ī������Դϴ�.");

	gotoxy(3, 5);
	printf("- ���� ���");

	gotoxy(3, 6);
	printf(" 1. ���� ���� ���� ��带 �����մϴ�.");

	gotoxy(3, 7);
	printf(" 2. ���� ����� ���� �ݾ��� �Է��մϴ�.");

	gotoxy(3, 8);
	printf(" 3. ������ �÷��̾ ī�� ������ ���� ��й޽��ϴ�.");

	gotoxy(3, 9);
	printf(" 4-1. �÷��̾��� ī�� ���� 21�̶�� �� ��� �������� �¸��ϰ�,");

	gotoxy(3, 10);
	printf(" 4-2. �ƴ϶�� ī�带 �� ������ (��Ʈ) �״�� �º�����(���ٵ�) ���մϴ�.");

	gotoxy(3, 11);
	printf(" 5. ������ �ڽ��� �а� 16�̸��̸� ī�带 �� �޽��ϴ�.");

	gotoxy(3, 13);
	printf(" 6. ī���� ���� 21�� �Ѵ� �ٸ� ����Ʈ�� �й��ϰ�,");

	gotoxy(3, 14);
	printf("   �Ѵ� ���� �ʾҴٸ� ���� �� ū ����� �¸��մϴ�.");

	gotoxy(3, 15);
	printf("  �� A�� 1�� 11�� �� ������ ���ڷ� ����ϰ�,");

	gotoxy(3, 16);
	printf("     J, Q, K�� ������ 10���� ����մϴ�.");

	dewhachang_clear();

	gotoxy(4, 20);
	printf("[���� ����]");

	gotoxy(4, 22);
	printf("������ �����帮�ڽ��ϴ�.");

	gotoxy(70, 24);
	printf("�ƹ� ��ư�̳� �����ּ���_");

	getch();
	blackjack();

	return 0;
}

int BJ_Agasheepililddehap(int card[][10], int num) //a�� 11�� �����ϰ� �� ���
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

int BJ_hap(int card[][10], int num) //���������� ����� ī�� ��
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