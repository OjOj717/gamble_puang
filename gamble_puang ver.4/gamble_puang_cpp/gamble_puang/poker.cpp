#include "gamble_puang.h"

void Poker_yes();
void Poker_yeounsoop_game();
void Poker_bone_game();
void Poker_rule();
int Poker_game_result(int num_score);

int poker()
{
play:
	mainwhameon_clear();

	print_money();

	card(5, 0, 7, 8);
	card(5, 0, 7, 20);
	card(5, 0, 7, 33);
	card(5, 0, 7, 46);
	card(5, 0, 7, 59); //ī�� �޸� ���

	dewhachang("[��Ŀ ����]", "�÷��� �Ͻðڽ��ϱ�?", "[y] ��   [n] �ƴϿ� [r] ���� ��Ģ");

	button = _getch();

	switch (button)
	{
	case 'y':
	case 'Y':
		Poker_yes();
		goto play;
		break;

	case 'n':
	case 'N':
		return P_none;
		break;

	case 'r':
	case 'R':
		Poker_rule();
		goto play;
		break;

	default:
		dewhachang("[��Ŀ ����]", "�ٽ� ������ �ּ���.", " ");

		Sleep(300);
		goto play;
		break;
	}
}

void Poker_yes()
{
yes:
	dewhachang("[��Ŀ ����]", "�����Ͻǰǰ���?", "[y] ��   [n] �ƴϿ� (����)");

	button = _getch();

	switch (button)
	{
	case 'y':
	case 'Y':
		Poker_yeounsoop_game();
		break;

	case 'n':
	case 'N':
		Poker_bone_game();
		break;

	default:
		dewhachang("[���� ����]", "�ٽ� ������ �ּ���.", " ");

		Sleep(300);
		goto yes;
		break;
	}
}

void Poker_yeounsoop_game()
{
	srand(static_cast<unsigned int>(time(NULL)));
	int cards[5] = { 0 }; //�÷��̾��� ī�带 �����ϴ� ��� / card[0] -> ������ / card[1] -> �÷��̾
	int a1, a2, a3, a4, a5; //��ȯ ���ù��� ĭ
	int boguan; //�������� �� �� ������ ĭ
	int num_score = 0, moyang_score = 0;
	//���Ƿ� ������ �÷��̾��� ī�� ����
	for (int j = 0; j <= 4; j++)
	{
		cards[j] = (rand() % 13 + 1) + (rand() % 4 + 1) * 100; //���� �ڸ� -> ��� ���� / ���� �ڸ��� -> ���� ����
	}

	//�÷��̾��� �ʱ� ī�� ���

	card(cards[0] / 100 - 1, cards[0] % 100, 7, 8);
	card(cards[1] / 100 - 1, cards[1] % 100, 7, 20);
	card(cards[2] / 100 - 1, cards[2] % 100, 7, 33);
	card(cards[3] / 100 - 1, cards[3] % 100, 7, 46);
	card(cards[4] / 100 - 1, cards[4] % 100, 7, 59);

	//�ٲ� �÷��̾� ī�� ����
	dewhachang("[��Ŀ ����]", "�ٲ� ī��� 1, �״�� �� ī��� 0�� �Է����ּ���.", "ex) 1 0 0 1 1 : ");
	scanf_s("%d %d %d %d %d", &a1, &a2, &a3, &a4, &a5);

	if (a1 == 1)
		cards[0] = (rand() % 13 + 1) + (rand() % 4 + 1) * 100;
	if (a2 == 1)
		cards[1] = (rand() % 13 + 1) + (rand() % 4 + 1) * 100;
	if (a3 == 1)
		cards[2] = (rand() % 13 + 1) + (rand() % 4 + 1) * 100;
	if (a4 == 1)
		cards[3] = (rand() % 13 + 1) + (rand() % 4 + 1) * 100;
	if (a5 == 1)
		cards[4] = (rand() % 13 + 1) + (rand() % 4 + 1) * 100;

	card(cards[0] / 100 - 1, cards[0] % 100, 7, 8);
	card(cards[1] / 100 - 1, cards[1] % 100, 7, 20);
	card(cards[2] / 100 - 1, cards[2] % 100, 7, 33);
	card(cards[3] / 100 - 1, cards[3] % 100, 7, 46);
	card(cards[4] / 100 - 1, cards[4] % 100, 7, 59);


	for (int j = 0; j <= 3; j++)
	{
		for (int k = 0; k <= 3 - j; k++)
		{
			if (cards[k] % 100 > cards[k + 1] % 100)
			{
				boguan = cards[k];
				cards[k] = cards[k + 1];
				cards[k] = boguan;
			}
			else if (cards[k] % 100 == cards[k + 1] % 100)
			{
				if (cards[k] > cards[k + 1])
				{
					boguan = cards[k];
					cards[k] = cards[k + 1];
					cards[k] = boguan;
				}
				else
				{
					continue;
				}
			}
			else
			{
				continue;
			}
		}
	}

	//��� ��� //�տ������� �������� ������ ������ 1�� ���ϴ� ��� (����, J, Q, K�� �ش�) (�� �ش��ϴ� �͸� ���)
	for (int j = 0; j <= 3; j++)
	{
		for (int k = 1; k <= 4 - j; k++)
		{
			if (cards[j] % 100 == cards[j + k] % 100)
			{
				num_score++;
			}
		}
	}
	//����� ������ ������ ���â����
	if (num_score > 0)
	{
		goto Result;
	}
	//��Ʈ����Ʈ ���� �Ǵ�
	for (int j = 0; j <= 3; j++)
	{
		if (cards[j] % 100 == cards[j + 1] % 100 - 1)
		{
			if (j < 3)
			{
				continue; //�ش� �ݺ��� �ݺ�
			}
			else if (j == 3)
			{
				goto Yeonsock; //���� ĭ���� �̵�
			}

		}
		else
		{
			goto Not_Yeonsock; // �ش����� ����. for�� �����
		}
	Yeonsock:
		if (cards[0] % 100 == 1)
		{
			for (int k = 0; k <= 3; k++)
			{
				if (cards[k] / 100 == cards[k + 1] / 100)
				{
					if (k < 3)
					{
						continue;
					}
					else if (k == 3)
					{
						num_score = num_score + 40;
					}
				}
				else
				{
					num_score = num_score + 20;
				}
			}
		}
		else
		{
			for (int k = 0; k <= 3; k++)
			{
				if (cards[k] / 100 == cards[k + 1] / 100)
				{
					if (k < 3)
					{
						continue;
					}
					else if (k == 3)
					{
						num_score = num_score + 30;
					}
				}
				else
				{
					num_score = num_score + 10;
				}
			}
		}
	}

Not_Yeonsock:
	//����� ������ ������ ���â����
	if (num_score > 0)
	{
		goto Result;
	}
	//����ƾ or �ο���Ʈ����Ʈ�÷��� ���� �Ǵ�
	for (int j = 0; j <= 3; j++)
	{
		if (j == 0)
		{
			if (cards[j] % 100 == cards[j + 1] % 100 - 9)
			{
				continue;
			}
			else
			{
				goto Not_Mountain;
			}
		}
		else if (j > 0 && j < 3)
		{
			if (cards[j] % 100 == cards[j + 1] % 100 - 1)
			{
				continue;
			}
			else
			{
				goto Not_Mountain;
			}
		}
		else if (j == 3)
		{
			if (cards[j] % 100 == cards[j + 1] % 100 - 1)
			{
				goto Mountain;
			}
			else
			{
				goto Not_Mountain;
			}
		}
	Mountain:
		for (int k = 0; k <= 3; k++)
		{
			if (cards[k] / 100 == cards[k + 1] / 100)
			{
				if (k < 3)
				{
					continue;
				}
				else if (k == 3)
				{
					num_score = num_score + 60;
				}
			}
			else
			{
				num_score = num_score + 50;
			}
		}
	}

Not_Mountain:
	//����� ������ ������ ���â����
	if (num_score > 0)
	{
		goto Result;
	}
	//�÷��� ���� �Ǵ�
	for (int j = 0; j <= 3; j++)
	{
		if (cards[j] / 100 == cards[j + 1] / 100)
		{
			if (j < 3)
			{
				continue;
			}
			else if (j == 3)
			{
				num_score = num_score + 70;
			}
		}
		else
		{
			goto Not_Flush;
		}
	}

Not_Flush:
	if (num_score > 0)
	{
		goto Result;
	}
Result:
	dewhachang_clear();

	gotoxy(4, 20);
	printf("[��Ŀ ����]");

	gotoxy(4, 22);
	Poker_game_result(num_score);

	gotoxy(70, 24);
	printf("�ƹ� ��ư�̳� �����ּ���");

	button = _getch();
}

//�� ����
void Poker_bone_game()
{
	srand(static_cast<unsigned int>(time(NULL)));
	int cards[5] = { 0 }; //�÷��̾��� ī�带 �����ϴ� ��� / card[0] -> ������ / card[1] -> �÷��̾
	int a1, a2, a3, a4, a5; //��ȯ ���ù��� ĭ
	int boguan; //�������� �� �� ������ ĭ
	int num_score = 0, moyang_score = 0;
	//���Ƿ� ������ �÷��̾��� ī�� ����
	double betting = 0;//�󸶸� �����ұ�?

	dewhachang("[��Ŀ ����]", "�󸶸� �����Ͻðڽ��ϱ�?", "���� �ݾ� : ");
	scanf_s("%lf", &betting);

	money -= betting;

	if (money < 0)
	{
		money += betting;

		dewhachang("[��Ŀ ����]", "���� �����Ѱ� ���׿�..", "�ƹ� ��ư�̳� �����ּ���_");

		button = _getch();
		Poker_yes();
	}

	else
	{
		print_money();

		for (int j = 0; j <= 4; j++)
		{
			cards[j] = (rand() % 13 + 1) + (rand() % 4 + 1) * 100; //���� �ڸ� -> ��� ���� / ���� �ڸ��� -> ���� ����
		}

		//�÷��̾��� �ʱ� ī�� ���

		card(cards[0] / 100 - 1, cards[0] % 100, 7, 8);
		card(cards[1] / 100 - 1, cards[1] % 100, 7, 20);
		card(cards[2] / 100 - 1, cards[2] % 100, 7, 33);
		card(cards[3] / 100 - 1, cards[3] % 100, 7, 46);
		card(cards[4] / 100 - 1, cards[4] % 100, 7, 59);

		//�ٲ� �÷��̾� ī�� ����
		dewhachang_clear();

		gotoxy(4, 20);
		printf("[��Ŀ ����]");

		gotoxy(4, 22);
		printf("�ٲ� ī��� 1, �״�� �� ī��� 0�� �Է����ּ���.");

		gotoxy(65, 24);
		printf("ex) 1 0 0 1 1 : ");
		scanf_s("%d %d %d %d %d", &a1, &a2, &a3, &a4, &a5);

		if (a1 == 1)
			cards[0] = (rand() % 13 + 1) + (rand() % 4 + 1) * 100;
		if (a2 == 1)
			cards[1] = (rand() % 13 + 1) + (rand() % 4 + 1) * 100;
		if (a3 == 1)
			cards[2] = (rand() % 13 + 1) + (rand() % 4 + 1) * 100;
		if (a4 == 1)
			cards[3] = (rand() % 13 + 1) + (rand() % 4 + 1) * 100;
		if (a5 == 1)
			cards[4] = (rand() % 13 + 1) + (rand() % 4 + 1) * 100;

		card(cards[0] / 100 - 1, cards[0] % 100, 7, 8);
		card(cards[1] / 100 - 1, cards[1] % 100, 7, 20);
		card(cards[2] / 100 - 1, cards[2] % 100, 7, 33);
		card(cards[3] / 100 - 1, cards[3] % 100, 7, 46);
		card(cards[4] / 100 - 1, cards[4] % 100, 7, 59);


		for (int j = 0; j <= 3; j++)
		{
			for (int k = 0; k <= 3 - j; k++)
			{
				if (cards[k] % 100 > cards[k + 1] % 100)
				{
					boguan = cards[k];
					cards[k] = cards[k + 1];
					cards[k] = boguan;
				}
				else if (cards[k] % 100 == cards[k + 1] % 100)
				{
					if (cards[k] > cards[k + 1])
					{
						boguan = cards[k];
						cards[k] = cards[k + 1];
						cards[k] = boguan;
					}
					else
					{
						continue;
					}
				}
				else
				{
					continue;
				}
			}
		}
		//��� ��� //�տ������� �������� ������ ������ 1�� ���ϴ� ��� (����, J, Q, K�� �ش�) (�� �ش��ϴ� �͸� ���)
		for (int j = 0; j <= 3; j++)
		{
			for (int k = 1; k <= 4 - j; k++)
			{
				if (cards[j] % 100 == cards[j + k] % 100)
				{
					num_score++;
				}
			}
		}
		//����� ������ ������ ���â����
		if (num_score > 0)
		{
			goto Result;
		}
		//��Ʈ����Ʈ ���� �Ǵ�
		for (int j = 0; j <= 3; j++)
		{
			if (cards[j] % 100 == cards[j + 1] % 100 - 1)
			{
				if (j < 3)
				{
					continue; //�ش� �ݺ��� �ݺ�
				}
				else if (j == 3)
				{
					goto Yeonsock; //���� ĭ���� �̵�
				}

			}
			else
			{
				goto Not_Yeonsock; // �ش����� ����. for�� �����
			}
		Yeonsock:
			if (cards[0] % 100 == 1)
			{
				for (int k = 0; k <= 3; k++)
				{
					if (cards[k] / 100 == cards[k + 1] / 100)
					{
						if (k < 3)
						{
							continue;
						}
						else if (k == 3)
						{
							num_score = num_score + 40;
						}
					}
					else
					{
						num_score = num_score + 20;
					}
				}
			}
			else
			{
				for (int k = 0; k <= 3; k++)
				{
					if (cards[k] / 100 == cards[k + 1] / 100)
					{
						if (k < 3)
						{
							continue;
						}
						else if (k == 3)
						{
							num_score = num_score + 30;
						}
					}
					else
					{
						num_score = num_score + 10;
					}
				}
			}
		}
	Not_Yeonsock:
		//����� ������ ������ ���â����
		if (num_score > 0)
		{
			goto Result;
		}
		//����ƾ or �ο���Ʈ����Ʈ�÷��� ���� �Ǵ�
		for (int j = 0; j <= 3; j++)
		{
			if (j == 0)
			{
				if (cards[j] % 100 == cards[j + 1] % 100 - 9)
				{
					continue;
				}
				else
				{
					goto Not_Mountain;
				}
			}
			else if (j > 0 && j < 3)
			{
				if (cards[j] % 100 == cards[j + 1] % 100 - 1)
				{
					continue;
				}
				else
				{
					goto Not_Mountain;
				}
			}
			else if (j == 3)
			{
				if (cards[j] % 100 == cards[j + 1] % 100 - 1)
				{
					goto Mountain;
				}
				else
				{
					goto Not_Mountain;
				}
			}
		Mountain:
			for (int k = 0; k <= 3; k++)
			{
				if (cards[k] / 100 == cards[k + 1] / 100)
				{
					if (k < 3)
					{
						continue;
					}
					else if (k == 3)
					{
						num_score = num_score + 60;
					}
				}
				else
				{
					num_score = num_score + 50;
				}
			}
		}
	Not_Mountain:
		//����� ������ ������ ���â����
		if (num_score > 0)
		{
			goto Result;
		}
		//�÷��� ���� �Ǵ�
		for (int j = 0; j <= 3; j++)
		{
			if (cards[j] / 100 == cards[j + 1] / 100)
			{
				if (j < 3)
				{
					continue;
				}
				else if (j == 3)
				{
					num_score = num_score + 70;
				}
			}
			else
			{
				goto Not_Flush;
			}
		}
	Not_Flush:
		if (num_score > 0)
		{
			goto Result;
		}
	Result:

		switch (num_score) //������ ���� ���ޱݾ� ���
		{
		case 0:
			betting *= 0;
			break;
		case 1:
			betting *= 1;
			break;
		case 2:
			betting *= 2;
			break;
		case 3:
			betting *= 3;
			break;
		case 10:
			betting *= 5;
			break;
		case 20:
			betting *= 8;
			break;
		case 50:
			betting *= 13;
			break;
		case 70:
			betting *= 21;
			break;
		case 4:
			betting *= 34;
			break;
		case 6:
			betting *= 55;
			break;
		case 30:
			betting *= 89;
			break;
		case 40:
			betting *= 144;
			break;
		case 60:
			betting *= 233;
			break;
		default:
			break;
		}

		money += betting;

		gotoxy(73, 8);
		printf("������ : %11.f", money);

		dewhachang_clear();

		gotoxy(4, 20);
		printf("[��Ŀ ����]");

		gotoxy(4, 22);
		Poker_game_result(num_score);

		gotoxy(70, 24);
		printf("�ƹ� ��ư�̳� �����ּ���");

		button = _getch();
	}
}

//���� ��
void Poker_rule()
{
	mainwhameon_clear();

	for (int i = 1; i < 13; i++)
	{
		gotoxy(3, i);
		cout << t_poker1_rule[i];
	}

	dewhachang("[��Ŀ ����]", "������ �����帮�ڽ��ϴ�. ������ ���÷��� �ƹ� ��ư�̳� �����ּ���.", "�ƹ� ��ư�̳� �����ּ���_");
	button = _getch();

	mainwhameon_clear();

	for (int i = 1; i < 18; i++)
	{
		gotoxy(3, i);
		cout << t_poker2_rule[i];
	}

	dewhachang("[��Ŀ ����]", "������ �����帮�ڽ��ϴ�.", "�ƹ� ��ư�̳� �����ּ���_");
	button = _getch();
}
//���� ��� 1 ~ 13���� ����
int Poker_game_result(int num_score)
{
	switch (num_score)
	{
	case 0:
		printf("����� �Դϴ�. (���� �ݾ� 0�� ����)"); return 0;
	case 1:
		printf("����� �Դϴ�. (���� �ݾ� 1�� ����)"); return 1;
	case 2:
		printf("����� �Դϴ�. (���� �ݾ� 2�� ����)"); return 2;
	case 3:
		printf("Ʈ���� �Դϴ�. (���� �ݾ� 3�� ����)"); return 3;
	case 4:
		printf("Ǯ�Ͽ콺 �Դϴ�. (���� �ݾ� 34�� ����)"); return 8;
	case 6:
		printf("��Ŀ �Դϴ�. (���� �ݾ� 55�� ����)"); return 9;
	case 10:
		printf("��Ʈ����Ʈ �Դϴ�. (���� �ݾ� 5�� ����)"); return 4;
	case 20:
		printf("�齺Ʈ����Ʈ �Դϴ�. (���� �ݾ� 8�� ����)"); return 5;
	case 30:
		printf("��Ʈ����Ʈ �÷��� �Դϴ�. (���� �ݾ� 89�� ����)"); return 10;
	case 40:
		printf("�齺Ʈ����Ʈ �÷��� �Դϴ�. (���� �ݾ� 144�� ����)"); return 11;
	case 50:
		printf("����ƾ �Դϴ�. (���� �ݾ� 13�� ����)"); return 6;
	case 60:
		printf("�ο� ��Ʈ����Ʈ �÷��� �Դϴ�. (���� �ݾ� 233�� ����)"); return 12;
	case 70:
		printf("�÷��� �Դϴ�. (���� �ݾ� 21�� ����)"); return 7;
	default:
		return 0;
	}
}