#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>

extern double money;
extern int mmove;

int Poker_yes();
int Poker_yeounsoop_game();
int Poker_bone_game();
int Poker_rule();
int Poker_game_result(int num_score);

int poker_num = 0;

int poker()
{
	char sigakbutton;
	int banbok = 0;

	mainwhameon_clear();

	card(5, 0, 7, 8);
	card(5, 0, 7, 20);
	card(5, 0, 7, 33);
	card(5, 0, 7, 46);
	card(5, 0, 7, 59); //ī�� �޸� ���

	gotoxy(73, 8);
	printf("������ : %11.f", money);

	dewhachang_clear();

	gotoxy(4, 20);
	printf("[��Ŀ ����]");

	gotoxy(4, 22);
	printf("�÷��� �Ͻðڽ��ϱ�?");

	gotoxy(60, 24);
	printf("[y] ��   [n] �ƴϿ� [r] ���� ��Ģ");

	sigakbutton = getch();

	switch (sigakbutton)
	{
	case 'y':
	case 'Y':
		Poker_yes();
		break;
	case 'n':
	case 'N':
		mmove = 1;
		main();
		break;
	case 'r':
	case 'R':
		Poker_rule();
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

int Poker_yes()
{
	char mode;
	poker_num += 1;
	dewhachang_clear();

	gotoxy(4, 20);
	printf("[��Ŀ ����]");

	gotoxy(4, 22);
	printf("�����Ͻǰǰ���?");

	gotoxy(65, 24);
	printf("[y] ��   [n] �ƴϿ� (���� ���)");

	mode = getch();

	switch (mode)
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

int Poker_yeounsoop_game()
{
	srand(time(NULL));
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
	
	card(cards[0]/100-1, cards[0]%100, 7, 8);
	card(cards[1] / 100-1, cards[1] % 100, 7, 20);
	card(cards[2] / 100-1, cards[2] % 100, 7, 33);
	card(cards[3] / 100-1, cards[3] % 100, 7, 46);
	card(cards[4] / 100-1, cards[4] % 100, 7, 59);

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

	card(cards[0] / 100-1, cards[0] % 100, 7, 8);
	card(cards[1] / 100-1, cards[1] % 100, 7, 20);
	card(cards[2] / 100-1, cards[2] % 100, 7, 33);
	card(cards[3] / 100-1, cards[3] % 100, 7, 46);
	card(cards[4] / 100-1, cards[4] % 100, 7, 59);

	
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

		getch();
		poker();
	
}
//�� ���� / �� ���ӿ� ���� ����� �� ���� �ʽ��ϴ�.
int Poker_bone_game()
{
	srand(time(NULL));
	int cards[5] = { 0 }; //�÷��̾��� ī�带 �����ϴ� ��� / card[0] -> ������ / card[1] -> �÷��̾
	int a1, a2, a3, a4, a5; //��ȯ ���ù��� ĭ
	int boguan; //�������� �� �� ������ ĭ
	int num_score = 0, moyang_score = 0;
	//���Ƿ� ������ �÷��̾��� ī�� ����
	int betting = 0;//�󸶸� �����ұ�?

	dewhachang_clear();

	gotoxy(4, 20);
	printf("[��Ŀ ����]");

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
		printf("[��Ŀ ����]");

		gotoxy(4, 22);
		printf("���� �����Ѱ� ���׿�..");

		gotoxy(70, 24);
		printf("�ƹ� ��ư�̳� �����ּ���_");

		getch();
		Poker_yes();
	}

	else
	{
		gotoxy(73, 8);
		printf("������ : %11.f", money);

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

		getch();
		poker();
	}

	return 0;
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
	}
}
//���� ��
int Poker_rule()
{
	mainwhameon_clear();

	gotoxy(3, 1);
	printf("<< POKER >>");

	gotoxy(3, 2);
	printf(" �÷��� ī��� �� �� �ִ� ��ǥ���� ī�� ���� �� �ϳ��� ī����");

	gotoxy(3, 3);
	printf(" ������ �Ǵ��Ͽ� ���и� �����ϴ� �����Դϴ�. �츮 ī���뿡���� ");

	gotoxy(3, 4);
	printf(" �̱��÷��̷� ����Ǵ� ���̺� ��Ŀ�� ��Ģ�� ������ �ֽ��ϴ�.");

	gotoxy(3, 6);
	printf("- ���� ���");

	gotoxy(3, 7);
	printf(" 1. ���� ���� ���� ��带 �����մϴ�.");

	gotoxy(3, 8);
	printf(" 2. ���� ����� ���� �ݾ��� �Է��մϴ�.");

	gotoxy(3, 9);
	printf(" 3. ���� ī�� 5���� �޽��ϴ�.");

	gotoxy(3, 10);
	printf(" 4. ���� ������ �����ϵ��� 0�� 1�� �Է��� �ٲ� ī�带 ���մϴ�.");

	gotoxy(3, 11);
	printf(" 5. 1�� ������ ī�常 �ٸ� ���� ī��� ��ü�ѵ� ������ ���� ");

	gotoxy(3, 12);
	printf("    ���� �ݾ׿� �ش��ϴ� ������ ���Ѹ�ŭ ���� ���� �޽��ϴ�.");

	dewhachang_clear();

	gotoxy(4, 20);
	printf("[��Ŀ ����]");

	gotoxy(4, 22);
	printf("������ �����帮�ڽ��ϴ�. ������ ���÷��� �ƹ� ��ư�̳� �����ּ���.");

	gotoxy(70, 24);
	printf("�ƹ� ��ư�̳� �����ּ���_");

	getch();

	mainwhameon_clear();

	gotoxy(3, 1);
	printf("<< POKER >>");

	gotoxy(3, 2);
	printf(" ����� (0�� ����) : ��� �������� �ش����� �ʴ� ����");

	gotoxy(3, 3);
	printf(" ����� (1�� ����) : ���ڰ� ���� ī�� 2��");

	gotoxy(3, 4);
	printf(" ����� (2�� ����) : ���� 2�� ����");

	gotoxy(3, 5);
	printf(" Ʈ���� (3�� ����) : ���ڰ� ���� ī�� 3��");

	gotoxy(3, 6);
	printf(" ��Ʈ����Ʈ (5�� ����) : ���ڰ� �̾����� ī�� 5��");

	gotoxy(3, 7);
	printf(" �齺Ʈ����Ʈ (8�� ����) : A, 2, 3, 4, 5 �ټ������� �̷���� ����");

	gotoxy(3, 8);
	printf(" ����ƾ (13�� ����) : A, K, Q, J, 10 �ټ������� �̷���� ����");

	gotoxy(3, 9);
	printf(" �÷��� (21�� ����) : ���̰� ���� ī�� 5��");

	gotoxy(3, 10);
	printf(" Ǯ�Ͽ콺 (34�� ����) : ���ڰ� ���� ī�� 3�� + ���ڰ� ���� ī�� 2��");

	gotoxy(3, 11);
	printf(" ��Ŀ (55�� ����) : ���ڰ� ���� ī�� 4��");

	gotoxy(3, 12);
	printf(" ��Ʈ����Ʈ �÷��� (89�� ����) :");

	gotoxy(3, 13);
	printf("                   ���ڰ� �̾����� ���̰� ���� ī�� 5��");

	gotoxy(3, 14);
	printf(" �齺Ʈ����Ʈ �÷��� (144�� ����) :");

	gotoxy(3, 15);
	printf("                     ���̰� ���� A, 2, 3, 4, 5 �ټ���");

	gotoxy(3, 16);
	printf(" �ο� ��Ʈ����Ʈ �÷��� (233�� ����) :");

	gotoxy(3, 17);
	printf("                        ���̰� ���� A, K, Q, J, 10 �ټ���");

	dewhachang_clear();

	gotoxy(4, 20);
	printf("[���Ըӽ� ����]");

	gotoxy(4, 22);
	printf("������ �����帮�ڽ��ϴ�.");

	gotoxy(70, 24);
	printf("�ƹ� ��ư�̳� �����ּ���_");

	getch();
	poker();

	return 0;
}