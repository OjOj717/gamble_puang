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

	dewhachang("[���� ����]", "�÷��� �Ͻðڽ��ϱ�?", "[y] ��   [n] �ƴϿ� [r] ���� ��Ģ");

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
		dewhachang("[���� ����]", "�ٽ� ������ �ּ���.", " ");

		Sleep(300);
		goto play;
		break;
	}
}

void BJ_yes()
{
yes:
	dewhachang("[���� ����]", "�����Ͻǰǰ���?", "[y] ��   [n] �ƴϿ� (����)");

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
		dewhachang("[���� ����]", "�ٽ� ������ �ּ���.", " ");

		Sleep(300);
		goto yes;
		break;
	}
}

void BJ_yeonsoopmode()
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
		dewhachang("[���� ����]", "�������� �̱�̽��ϴ�!!", "�ƹ� ��ư�̳� �����ּ���_");
	}

	else
	{
		dewhachang("[���� ����]", "��Ʈ�� �Ͻ��� ���ٵ带 �Ͻ��� ����ּ���.", "[h] ��Ʈ  [s] ���ٵ�");

		action = _getch(); //��Ʈ,���ٵ� ����

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

				dewhachang("[���� ����]", "��Ʈ�� �Ͻ��� ���ٵ带 �Ͻ��� ����ּ���.", "[h] ��Ʈ  [s] ���ٵ�");

				action = _getch();
			}
		}

		if (BJ_hap(player, pnum) > 21) //21 ������ ����Ʈ�� �й�
			dewhachang("[���� ����]", "BURST ���� 21�� �Ѿ����ϴ�!", "�ƹ� ��ư�̳� �����ּ���_");

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
				dewhachang("[���� ����]", "PUSH ���º� �Դϴ�!", "�ƹ� ��ư�̳� �����ּ���_");

			else if (BJ_hap(dealer, dnum) > 21) //������ 21 ������ ����Ʈ�� �¸�
				dewhachang("[���� ����]", "DEALER BURST ������ ���� 21�� �Ѿ����ϴ�!", "�ƹ� ��ư�̳� �����ּ���_");

			else if (BJ_hap(dealer, dnum) > BJ_hap(player, pnum)) //������ ���� �� ũ�ٸ� �й�
				dewhachang("[���� ����]", "LOSE ������ ���� 21�� �� �������ϴ�!", "�ƹ� ��ư�̳� �����ּ���_");

			else //�÷��̾� �¸�
				dewhachang("[���� ����]", "WIN �̰���ϴ�!", "�ƹ� ��ư�̳� �����ּ���_");
		}

		button = _getch();
	}
}

void BJ_realmode()
{
	int dealer[10][10] = { 0 }, player[10][10] = { 0 }; //������ �÷��̾��� ī��
	int dnum = 0, pnum = 0; //���� ������ �÷��̾��� ī�� ����
	char action; //��Ʈ or ������
	double betting = 0;//�󸶸� �����ұ�?

	dewhachang("[���� ����]", "�󸶸� �����Ͻðڽ��ϱ�?", "���� �ݾ� : ");
	scanf_s("%lf", &betting);

	money -= betting;

	if (money < 0)
	{
		money += betting;

		dewhachang("[���� ����]", "���� �����Ѱ� ���׿�..", "�ƹ� ��ư�̳� �����ּ���_");
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
			dewhachang("[���� ����]", "�������� �̱�̽��ϴ�!! (���� �ݾ� 3�� ����)", "�ƹ� ��ư�̳� �����ּ���_");

			betting *= 3;
		}

		else
		{
			dewhachang("[���� ����]", "��Ʈ�� �Ͻ��� ���ٵ带 �Ͻ��� ����ּ���.", "[h] ��Ʈ  [s] ���ٵ�");

			action = _getch(); //��Ʈ,���ٵ� ����

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

					dewhachang("[���� ����]", "��Ʈ�� �Ͻ��� ���ٵ带 �Ͻ��� ����ּ���.", "[h] ��Ʈ  [s] ���ٵ�");

					action = _getch();
				}
			}

			if (BJ_hap(player, pnum) > 21) //21 ������ ����Ʈ�� �й�
			{
				dewhachang("[���� ����]", "BURST ���� 21�� �Ѿ����ϴ�! (���� �ݾ� �Ҹ�)", "�ƹ� ��ư�̳� �����ּ���_");
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
					dewhachang("[���� ����]", "PUSH ���º� �Դϴ�! (���� �ݾ� �״�� ����)", "�ƹ� ��ư�̳� �����ּ���_");
					betting *= 1;
				}

				else if (BJ_hap(dealer, dnum) > 21) //������ 21 ������ ����Ʈ�� �¸�
				{
					dewhachang("[���� ����]", "DEALER BURST ������ ���� 21�� �Ѿ����ϴ�! (���� �ݾ� 2�� ����)", "�ƹ� ��ư�̳� �����ּ���_");
					betting *= 2;
				}

				else if (BJ_hap(dealer, dnum) > BJ_hap(player, pnum)) //������ ���� �� ũ�ٸ� �й�
				{
					dewhachang("[���� ����]", "LOSE ������ ���� 21�� �� �������ϴ�! (���� �ݾ� �Ҹ�)", "�ƹ� ��ư�̳� �����ּ���_");
					betting *= 0;
				}

				else //�÷��̾� �¸�
				{
					dewhachang("[���� ����]", "WIN �̰���ϴ�! (���� �ݾ� 2�� ����)", "�ƹ� ��ư�̳� �����ּ���_");
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

	dewhachang("[���� ����]", "������ �����帮�ڽ��ϴ�.", "�ƹ� ��ư�̳� �����ּ���_");
	button = _getch();
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
		if (card[1][i] == 1 && BJ_Agasheepililddehap(card, num) <= 21)
			hap += 11;
		else if (card[1][i] == 11 || card[1][i] == 12 || card[1][i] == 13)
			hap += 10;
		else
			hap += card[1][i];
	}
	return hap;
}