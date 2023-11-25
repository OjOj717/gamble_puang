#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77

extern double money;
extern int X;
extern int Y;

int mmove = 1;

int makemap(int map[][200]) //�������̽��� �׸� �Լ�
{
    for (int i = 0; i < 28; i++)
    {
        for (int j = 0; j < 200; j++)
        {
            switch (map[i][j])
            {
            case 0:
                printf(" ");
                break;
            case 1:
                printf("��");
                break;
            case 2:
                printf("��");
                break;
            case 3:
                printf("��");
                break;
            case 4:
                printf("��");
                break;
            case 5:
                printf("��");
                break;
            case 6:
                printf("��");
                break;
            case 7:
                printf("��");
                break;
            case 8:
                printf("��");
                break;
            case 9:
                printf("��");
                break;
            case 10:
                printf("��");
                break;
            case 101:
                printf("��");
                break;
            case 102:
                printf("Ȧ");
                break;
            case 103:
                printf("¦");
                break;
            case 105:
                printf("�м�");
                break;
            case 106:
                printf("����");
                break;
            case 107:
                printf("���Ըӽ�");
                break;
            case 108:
                printf("����");
                break;
            case 109:
                printf("�渶��");
                break;
            case 110:
                printf("Ŀ");
                break;
            case 111:
                printf("#���� ������ 1336#");
                break;
            }
        }
        printf("\n");
    }

    return 0;
}

int move(int map[][200]) //ĳ���Ͱ� ������ �Լ�
{
    int text, checker;

    while (1)
    {

        text = getch();
        textcolor(9);
        switch (text) { //�Է¹��� ��ư(��,�Ʒ�,����,������)�� ���� ����ġ��

        case UP: gotoxy(X, Y + 2);
			if (mmove == 1)
			{
				printf(" ");//�ϴ� ����� �����մϴ�.
				Y -= 1;//�ϴ� ��ǥ�� �̵����Ѻ���

				checker = keeper(map, X, Y);
				//map�迭 �ּҿ� ��ǥ�� �Ѱ��� ���ô�
				if (checker == 1) {
					gotoxy(X, Y + 2);
					printf("��");//�������� �ȴٸ� ���ڸ��� ������ְ�
					break;
				}
				else if (checker == 0)
				{
					Y += 1;//�������̸� ��ǥ�� �ٽ� �ǵ����Ŀ�
					gotoxy(X, Y + 2);
					printf("��");//�ٽ� ������ݴϴ�.
					break;
				}
			}
			else
				break;
        case DOWN: gotoxy(X, Y + 2);
			if (mmove == 1)
			{
				printf(" ");
				Y += 1;
				checker = keeper(map, X, Y);
				if (checker == 1) {
					gotoxy(X, Y + 2);
					printf("��");
					break;
				}
				else if (checker == 0)
				{
					Y -= 1;
					gotoxy(X, Y + 2);
					printf("��");
					break;
				}
			}
			else
				break;

        case LEFT: gotoxy(X, Y + 2);
			if (mmove == 1)
			{
				printf(" ");
				X -= 1;

				checker = keeper(map, X, Y);
				if (checker == 1) {

					gotoxy(X, Y + 2);
					printf("��");

					break;
				}
				else if (checker == 0)
				{
					X += 1;
					gotoxy(X, Y + 2);
					printf("��");
					break;
				}
			}
			else
				break;

        case RIGHT:   gotoxy(X, Y + 2);
			if (mmove == 1)
			{
				printf(" ");
				X += 1;

				checker = keeper(map, X, Y);
				if (checker == 1) {

					gotoxy(X, Y + 2);
					printf("��");

					break;
				}
				else if (checker == 0)
				{
					X -= 1;
					gotoxy(X, Y + 2);
					printf("��");
					break;
				}
			}
			else
				break;

        }

        eventplay();
		

        continue;
    }


    return 0;
}

int blackjack(); //���� ���� �Լ�
int poker(); //��Ŀ ���� �Լ�
int slotmachine(); //���Ըӽ� ���� �Լ�
int holzzak();//Ȧ¦ ���� �Լ�

int eventplay() //�̺�Ʈ(���ӽ��� ���)�� �÷��̵� �Լ�
{
    textcolor(15);

    if (X == 20 && Y == 10 || X == 21 && Y == 10 || X == 22 && Y == 10) //���� �÷���
    {
		mmove = 0;
		X = 20; Y = 9;
        blackjack();
    }

	else if (X == 11 && Y == 2) //��Ŀ �÷���
	{
		mmove = 0;
		X = 12; Y = 2;
		poker();
	}
	else if (X == 11 && Y == 3)
	{
		mmove = 0;
		X = 12; Y = 3;
		poker();
	}
	
	else if (X == 17 && Y == 2) //�м� �̺�
	{
		X = 17; Y = 1;
		boonsu();
	}
	else if (X == 17 && Y == 4)
	{
		X = 17; Y = 5;
		boonsu();
	}
	else if (X == 16 && Y == 2)
	{
		X = 16; Y = 1;
		boonsu();
	}
	else if (X == 16 && Y == 4)
	{
		X = 16; Y = 5;
		boonsu();
	}

	else if (X == 36 && Y == 6) //���Ըӽ� �÷���
	{
		mmove = 0;
		X = 36; Y = 7;
		slotmachine();
	}
	else if (X == 37 && Y == 6)
	{
		mmove = 0;
		X = 37; Y = 7;
		slotmachine();
	}
	else if (X == 38 && Y == 6)
	{
		mmove = 0;
		X = 38; Y = 7;
		slotmachine();
	}

	else if (X == 9 && Y == 9) //Ȧ¦ �÷���
	{
		X = 10; Y = 9;
		mmove = 0;
		holzzak();
	}
	else if (X == 9 && Y == 10)
	{
		X = 10; Y = 10;
		mmove = 0;
		holzzak();
	}
	
	else if (X == 46 && Y == 10) //�渶�� �̺�Ʈ
	{
		X = 46; Y = 9;
		horse();
	}
	else if (X == 47 && Y == 10)
	{
		X = 47; Y = 9;
		horse();
	}
	else if (X == 48 && Y == 10)
	{
		X = 48; Y = 9;
		horse();
	}

	else if (X == 22 && Y == 4) //���� �̺�Ʈ
	{
		X = 21; Y = 4;
		mmove = 0;
		mart();
	}
	else if (X == 22 && Y == 5)
	{
		X = 21; Y = 5;
		mmove = 0;
		mart();
	}

    return 0;
}

int mainwhameon_clear() //����ȭ�� �ʱ�ȭ
{
	gotoxy(3, 1); printf("                                                                   ");
	gotoxy(3, 2); printf("                                                                   ");
	gotoxy(3, 3); printf("                                                                   ");
	gotoxy(3, 4); printf("                                                                   ");
	gotoxy(3, 5); printf("                                                                   ");
	gotoxy(3, 6); printf("                                                                   ");
	gotoxy(3, 7); printf("                                                                   ");
	gotoxy(3, 8); printf("                                                                   ");
	gotoxy(3, 9); printf("                                                                   ");
	gotoxy(3, 10); printf("                                                                   ");
	gotoxy(3, 11); printf("                                                                   ");
	gotoxy(3, 12); printf("                                                                   ");
	gotoxy(3, 13); printf("                                                                   ");
	gotoxy(3, 14); printf("                                                                   ");
	gotoxy(3, 15); printf("                                                                   ");
	gotoxy(3, 16); printf("                                                                   ");
	gotoxy(3, 17); printf("                                                                   ");

	return 0;
}

int dewhachang_clear() //��ȭâ �ʱ�ȭ
{
    gotoxy(3, 20); printf("                                                                                             ");
    gotoxy(3, 21); printf("                                                                                             ");
    gotoxy(3, 22); printf("                                                                                             ");
    gotoxy(3, 23); printf("                                                                                             ");
    gotoxy(3, 24); printf("                                                                                             ");
      
    return 0;
} 

int card(int muni, int sutza, int who, int num) //ī�� ��� �Լ�
{
	if (muni == 5 && sutza == 0)
	{
		gotoxy(num, who); printf("������������ ");
		gotoxy(num, who + 1); printf("�� ?  �� ");
		gotoxy(num, who + 2); printf("��  ? �� ");
		gotoxy(num, who + 3); printf("��   ?�� ");
		gotoxy(num, who + 4); printf("������������ ");
	}

	else if (muni == 0 && sutza == 1)
	{
		textcolor(4);
		gotoxy(num, who); printf("������������ ");
		gotoxy(num, who + 1); printf("�� A  �� ");
		gotoxy(num, who + 2); printf("��  �� �� ");
		gotoxy(num, who + 3); printf("��   A�� ");
		gotoxy(num, who + 4); printf("������������ ");
		textcolor(15);
	}

	else if (muni == 0 && sutza == 2)
	{
		textcolor(4);
		gotoxy(num, who); printf("������������ ");
		gotoxy(num, who + 1); printf("�� 2  �� ");
		gotoxy(num, who + 2); printf("��  �� �� ");
		gotoxy(num, who + 3); printf("��   2�� ");
		gotoxy(num, who + 4); printf("������������ ");
		textcolor(15);
	}

	else if (muni == 0 && sutza == 3)
	{
		textcolor(4);
		gotoxy(num, who); printf("������������ ");
		gotoxy(num, who + 1); printf("�� 3  �� ");
		gotoxy(num, who + 2); printf("��  �� �� ");
		gotoxy(num, who + 3); printf("��   3�� ");
		gotoxy(num, who + 4); printf("������������ ");
		textcolor(15);
	}

	else if (muni == 0 && sutza == 4)
	{
		textcolor(4);
		gotoxy(num, who); printf("������������ ");
		gotoxy(num, who + 1); printf("�� 4  �� ");
		gotoxy(num, who + 2); printf("��  �� �� ");
		gotoxy(num, who + 3); printf("��   4�� ");
		gotoxy(num, who + 4); printf("������������ ");
		textcolor(15);
	}

	else if (muni == 0 && sutza == 5)
	{
		textcolor(4);
		gotoxy(num, who); printf("������������ ");
		gotoxy(num, who + 1); printf("�� 5  �� ");
		gotoxy(num, who + 2); printf("��  �� �� ");
		gotoxy(num, who + 3); printf("��   5�� ");
		gotoxy(num, who + 4); printf("������������ ");
		textcolor(15);
	}

	else if (muni == 0 && sutza == 6)
	{
		textcolor(4);
		gotoxy(num, who); printf("������������ ");
		gotoxy(num, who + 1); printf("�� 6  �� ");
		gotoxy(num, who + 2); printf("��  �� �� ");
		gotoxy(num, who + 3); printf("��   6�� ");
		gotoxy(num, who + 4); printf("������������ ");
		textcolor(15);
	}

	else if (muni == 0 && sutza == 7)
	{
		textcolor(4);
		gotoxy(num, who); printf("������������ ");
		gotoxy(num, who + 1); printf("�� 7  �� ");
		gotoxy(num, who + 2); printf("��  �� �� ");
		gotoxy(num, who + 3); printf("��   7�� ");
		gotoxy(num, who + 4); printf("������������ ");
		textcolor(15);
	}

	else if (muni == 0 && sutza == 8)
	{
		textcolor(4);
		gotoxy(num, who); printf("������������ ");
		gotoxy(num, who + 1); printf("�� 8  �� ");
		gotoxy(num, who + 2); printf("��  �� �� ");
		gotoxy(num, who + 3); printf("��   8�� ");
		gotoxy(num, who + 4); printf("������������ ");
		textcolor(15);
	}

	else if (muni == 0 && sutza == 9)
	{
		textcolor(4);
		gotoxy(num, who); printf("������������ ");
		gotoxy(num, who + 1); printf("�� 9  �� ");
		gotoxy(num, who + 2); printf("��  �� �� ");
		gotoxy(num, who + 3); printf("��   9�� ");
		gotoxy(num, who + 4); printf("������������ ");
		textcolor(15);
	}

	else if (muni == 0 && sutza == 10)
	{
		textcolor(4);
		gotoxy(num, who); printf("������������ ");
		gotoxy(num, who + 1); printf("��10  �� ");
		gotoxy(num, who + 2); printf("��  �� �� ");
		gotoxy(num, who + 3); printf("��  10�� ");
		gotoxy(num, who + 4); printf("������������ ");
		textcolor(15);
	}

	else if (muni == 0 && sutza == 11)
	{
		textcolor(4);
		gotoxy(num, who); printf("������������ ");
		gotoxy(num, who + 1); printf("�� J  �� ");
		gotoxy(num, who + 2); printf("��  �� �� ");
		gotoxy(num, who + 3); printf("��   J�� ");
		gotoxy(num, who + 4); printf("������������ ");
		textcolor(15);
	}

	else if (muni == 0 && sutza == 12)
	{
		textcolor(4);
		gotoxy(num, who); printf("������������ ");
		gotoxy(num, who + 1); printf("�� Q  �� ");
		gotoxy(num, who + 2); printf("��  �� �� ");
		gotoxy(num, who + 3); printf("��   Q�� ");
		gotoxy(num, who + 4); printf("������������ ");
		textcolor(15);
	}

	else if (muni == 0 && sutza == 13)
	{
		textcolor(4);
		gotoxy(num, who); printf("������������ ");
		gotoxy(num, who + 1); printf("�� K  �� ");
		gotoxy(num, who + 2); printf("��  �� �� ");
		gotoxy(num, who + 3); printf("��   K�� ");
		gotoxy(num, who + 4); printf("������������ ");
		textcolor(15);
	}

	else if (muni == 1 && sutza == 1)
	{
		gotoxy(num, who); printf("������������ ");
		gotoxy(num, who + 1); printf("�� A  �� ");
		gotoxy(num, who + 2); printf("��  �� �� ");
		gotoxy(num, who + 3); printf("��   A�� ");
		gotoxy(num, who + 4); printf("������������ ");
	}

	else if (muni == 1 && sutza == 2)
	{
		gotoxy(num, who); printf("������������ ");
		gotoxy(num, who + 1); printf("�� 2  �� ");
		gotoxy(num, who + 2); printf("��  �� �� ");
		gotoxy(num, who + 3); printf("��   2�� ");
		gotoxy(num, who + 4); printf("������������ ");
	}

	else if (muni == 1 && sutza == 3)
	{
		gotoxy(num, who); printf("������������ ");
		gotoxy(num, who + 1); printf("�� 3  �� ");
		gotoxy(num, who + 2); printf("��  �� �� ");
		gotoxy(num, who + 3); printf("��   3�� ");
		gotoxy(num, who + 4); printf("������������ ");
	}

	else if (muni == 1 && sutza == 4)
	{
		gotoxy(num, who); printf("������������ ");
		gotoxy(num, who + 1); printf("�� 4  �� ");
		gotoxy(num, who + 2); printf("��  �� �� ");
		gotoxy(num, who + 3); printf("��   4�� ");
		gotoxy(num, who + 4); printf("������������ ");
	}

	else if (muni == 1 && sutza == 5)
	{
		gotoxy(num, who); printf("������������ ");
		gotoxy(num, who + 1); printf("�� 5  �� ");
		gotoxy(num, who + 2); printf("��  �� �� ");
		gotoxy(num, who + 3); printf("��   5�� ");
		gotoxy(num, who + 4); printf("������������ ");
	}

	else if (muni == 1 && sutza == 6)
	{
		gotoxy(num, who); printf("������������ ");
		gotoxy(num, who + 1); printf("�� 6  �� ");
		gotoxy(num, who + 2); printf("��  �� �� ");
		gotoxy(num, who + 3); printf("��   6�� ");
		gotoxy(num, who + 4); printf("������������ ");
	}

	else if (muni == 1 && sutza == 7)
	{
		gotoxy(num, who); printf("������������ ");
		gotoxy(num, who + 1); printf("�� 7  �� ");
		gotoxy(num, who + 2); printf("��  �� �� ");
		gotoxy(num, who + 3); printf("��   7�� ");
		gotoxy(num, who + 4); printf("������������ ");
	}

	else if (muni == 1 && sutza == 8)
	{
		gotoxy(num, who); printf("������������ ");
		gotoxy(num, who + 1); printf("�� 8  �� ");
		gotoxy(num, who + 2); printf("��  �� �� ");
		gotoxy(num, who + 3); printf("��   8�� ");
		gotoxy(num, who + 4); printf("������������ ");
	}

	else if (muni == 1 && sutza == 9)
	{
		gotoxy(num, who); printf("������������ ");
		gotoxy(num, who + 1); printf("�� 9  �� ");
		gotoxy(num, who + 2); printf("��  �� �� ");
		gotoxy(num, who + 3); printf("��   9�� ");
		gotoxy(num, who + 4); printf("������������ ");
	}

	else if (muni == 1 && sutza == 10)
	{
		gotoxy(num, who); printf("������������ ");
		gotoxy(num, who + 1); printf("��10  �� ");
		gotoxy(num, who + 2); printf("��  �� �� ");
		gotoxy(num, who + 3); printf("��  10�� ");
		gotoxy(num, who + 4); printf("������������ ");
	}

	else if (muni == 1 && sutza == 11)
	{
		gotoxy(num, who); printf("������������ ");
		gotoxy(num, who + 1); printf("�� J  �� ");
		gotoxy(num, who + 2); printf("��  �� �� ");
		gotoxy(num, who + 3); printf("��   J�� ");
		gotoxy(num, who + 4); printf("������������ ");
	}

	else if (muni == 1 && sutza == 12)
	{
		gotoxy(num, who); printf("������������ ");
		gotoxy(num, who + 1); printf("�� Q  �� ");
		gotoxy(num, who + 2); printf("��  �� �� ");
		gotoxy(num, who + 3); printf("��   Q�� ");
		gotoxy(num, who + 4); printf("������������ ");
	}

	else if (muni == 1 && sutza == 13)
	{
		gotoxy(num, who); printf("������������ ");
		gotoxy(num, who + 1); printf("�� K  �� ");
		gotoxy(num, who + 2); printf("��  �� �� ");
		gotoxy(num, who + 3); printf("��   K�� ");
		gotoxy(num, who + 4); printf("������������ ");
	}

	else if (muni == 3 && sutza == 1)
	{
		gotoxy(num, who); printf("������������ ");
		gotoxy(num, who + 1); printf("�� A  �� ");
		gotoxy(num, who + 2); printf("��  �� �� ");
		gotoxy(num, who + 3); printf("��   A�� ");
		gotoxy(num, who + 4); printf("������������ ");
	}

	else if (muni == 3 && sutza == 2)
	{
		gotoxy(num, who); printf("������������ ");
		gotoxy(num, who + 1); printf("�� 2  �� ");
		gotoxy(num, who + 2); printf("��  �� �� ");
		gotoxy(num, who + 3); printf("��   2�� ");
		gotoxy(num, who + 4); printf("������������ ");
	}

	else if (muni == 3 && sutza == 3)
	{
		gotoxy(num, who); printf("������������ ");
		gotoxy(num, who + 1); printf("�� 3  �� ");
		gotoxy(num, who + 2); printf("��  �� �� ");
		gotoxy(num, who + 3); printf("��   3�� ");
		gotoxy(num, who + 4); printf("������������ ");
	}

	else if (muni == 3 && sutza == 4)
	{
		gotoxy(num, who); printf("������������ ");
		gotoxy(num, who + 1); printf("�� 4  �� ");
		gotoxy(num, who + 2); printf("��  �� �� ");
		gotoxy(num, who + 3); printf("��   4�� ");
		gotoxy(num, who + 4); printf("������������ ");
	}

	else if (muni == 3 && sutza == 5)
	{
		gotoxy(num, who); printf("������������ ");
		gotoxy(num, who + 1); printf("�� 5  �� ");
		gotoxy(num, who + 2); printf("��  �� �� ");
		gotoxy(num, who + 3); printf("��   5�� ");
		gotoxy(num, who + 4); printf("������������ ");
	}

	else if (muni == 3 && sutza == 6)
	{
		gotoxy(num, who); printf("������������ ");
		gotoxy(num, who + 1); printf("�� 6  �� ");
		gotoxy(num, who + 2); printf("��  �� �� ");
		gotoxy(num, who + 3); printf("��   6�� ");
		gotoxy(num, who + 4); printf("������������ ");
	}

	else if (muni == 3 && sutza == 7)
	{
		gotoxy(num, who); printf("������������ ");
		gotoxy(num, who + 1); printf("�� 7  �� ");
		gotoxy(num, who + 2); printf("��  �� �� ");
		gotoxy(num, who + 3); printf("��   7�� ");
		gotoxy(num, who + 4); printf("������������ ");
	}

	else if (muni == 3 && sutza == 8)
	{
		gotoxy(num, who); printf("������������ ");
		gotoxy(num, who + 1); printf("�� 8  �� ");
		gotoxy(num, who + 2); printf("��  �� �� ");
		gotoxy(num, who + 3); printf("��   8�� ");
		gotoxy(num, who + 4); printf("������������ ");
	}

	else if (muni == 3 && sutza == 9)
	{
		gotoxy(num, who); printf("������������ ");
		gotoxy(num, who + 1); printf("�� 9  �� ");
		gotoxy(num, who + 2); printf("��  �� �� ");
		gotoxy(num, who + 3); printf("��   9�� ");
		gotoxy(num, who + 4); printf("������������ ");
	}

	else if (muni == 3 && sutza == 10)
	{
		gotoxy(num, who); printf("������������ ");
		gotoxy(num, who + 1); printf("��10  �� ");
		gotoxy(num, who + 2); printf("��  �� �� ");
		gotoxy(num, who + 3); printf("��  10�� ");
		gotoxy(num, who + 4); printf("������������ ");
	}

	else if (muni == 3 && sutza == 11)
	{
		gotoxy(num, who); printf("������������ ");
		gotoxy(num, who + 1); printf("�� J  �� ");
		gotoxy(num, who + 2); printf("��  �� �� ");
		gotoxy(num, who + 3); printf("��   J�� ");
		gotoxy(num, who + 4); printf("������������ ");
	}

	else if (muni == 3 && sutza == 12)
	{
		gotoxy(num, who); printf("������������ ");
		gotoxy(num, who + 1); printf("�� Q  �� ");
		gotoxy(num, who + 2); printf("��  �� �� ");
		gotoxy(num, who + 3); printf("��   Q�� ");
		gotoxy(num, who + 4); printf("������������ ");
	}

	else if (muni == 3 && sutza == 13)
	{
		gotoxy(num, who); printf("������������ ");
		gotoxy(num, who + 1); printf("�� K  �� ");
		gotoxy(num, who + 2); printf("��  �� �� ");
		gotoxy(num, who + 3); printf("��   K�� ");
		gotoxy(num, who + 4); printf("������������ ");
	}

	else if (muni == 2 && sutza == 1)
	{
		textcolor(4);
		gotoxy(num, who); printf("������������ ");
		gotoxy(num, who + 1); printf("�� A  �� ");
		gotoxy(num, who + 2); printf("��  �� �� ");
		gotoxy(num, who + 3); printf("��   A�� ");
		gotoxy(num, who + 4); printf("������������ ");
		textcolor(15);
	}

	else if (muni == 2 && sutza == 2)
	{
		textcolor(4);
		gotoxy(num, who); printf("������������ ");
		gotoxy(num, who + 1); printf("�� 2  �� ");
		gotoxy(num, who + 2); printf("��  �� �� ");
		gotoxy(num, who + 3); printf("��   2�� ");
		gotoxy(num, who + 4); printf("������������ ");
		textcolor(15);
	}

	else if (muni == 2 && sutza == 3)
	{
		textcolor(4);
		gotoxy(num, who); printf("������������ ");
		gotoxy(num, who + 1); printf("�� 3  �� ");
		gotoxy(num, who + 2); printf("��  �� �� ");
		gotoxy(num, who + 3); printf("��   3�� ");
		gotoxy(num, who + 4); printf("������������ ");
		textcolor(15);
	}

	else if (muni == 2 && sutza == 4)
	{
		textcolor(4);
		gotoxy(num, who); printf("������������ ");
		gotoxy(num, who + 1); printf("�� 4  �� ");
		gotoxy(num, who + 2); printf("��  �� �� ");
		gotoxy(num, who + 3); printf("��   4�� ");
		gotoxy(num, who + 4); printf("������������ ");
		textcolor(15);
	}

	else if (muni == 2 && sutza == 5)
	{
		textcolor(4);
		gotoxy(num, who); printf("������������ ");
		gotoxy(num, who + 1); printf("�� 5  �� ");
		gotoxy(num, who + 2); printf("��  �� �� ");
		gotoxy(num, who + 3); printf("��   5�� ");
		gotoxy(num, who + 4); printf("������������ ");
		textcolor(15);
	}

	else if (muni == 2 && sutza == 6)
	{
		textcolor(4);
		gotoxy(num, who); printf("������������ ");
		gotoxy(num, who + 1); printf("�� 6  �� ");
		gotoxy(num, who + 2); printf("��  �� �� ");
		gotoxy(num, who + 3); printf("��   6�� ");
		gotoxy(num, who + 4); printf("������������ ");
		textcolor(15);
	}

	else if (muni == 2 && sutza == 7)
	{
		textcolor(4);
		gotoxy(num, who); printf("������������ ");
		gotoxy(num, who + 1); printf("�� 7  �� ");
		gotoxy(num, who + 2); printf("��  �� �� ");
		gotoxy(num, who + 3); printf("��   7�� ");
		gotoxy(num, who + 4); printf("������������ ");
		textcolor(15);
	}

	else if (muni == 2 && sutza == 8)
	{
		textcolor(4);
		gotoxy(num, who); printf("������������ ");
		gotoxy(num, who + 1); printf("�� 8  �� ");
		gotoxy(num, who + 2); printf("��  �� �� ");
		gotoxy(num, who + 3); printf("��   8�� ");
		gotoxy(num, who + 4); printf("������������ ");
		textcolor(15);
	}

	else if (muni == 2 && sutza == 9)
	{
		textcolor(4);
		gotoxy(num, who); printf("������������ ");
		gotoxy(num, who + 1); printf("�� 9  �� ");
		gotoxy(num, who + 2); printf("��  �� �� ");
		gotoxy(num, who + 3); printf("��   9�� ");
		gotoxy(num, who + 4); printf("������������ ");
		textcolor(15);
	}

	else if (muni == 2 && sutza == 10)
	{
		textcolor(4);
		gotoxy(num, who); printf("������������ ");
		gotoxy(num, who + 1); printf("��10  �� ");
		gotoxy(num, who + 2); printf("��  �� �� ");
		gotoxy(num, who + 3); printf("��  10�� ");
		gotoxy(num, who + 4); printf("������������ ");
		textcolor(15);
	}

	else if (muni == 2 && sutza == 11)
	{
		textcolor(4);
		gotoxy(num, who); printf("������������ ");
		gotoxy(num, who + 1); printf("�� J  �� ");
		gotoxy(num, who + 2); printf("��  �� �� ");
		gotoxy(num, who + 3); printf("��   J�� ");
		gotoxy(num, who + 4); printf("������������ ");
		textcolor(15);
	}

	else if (muni == 2 && sutza == 12)
	{
		textcolor(4);
		gotoxy(num, who); printf("������������ ");
		gotoxy(num, who + 1); printf("�� Q  �� ");
		gotoxy(num, who + 2); printf("��  �� �� ");
		gotoxy(num, who + 3); printf("��   Q�� ");
		gotoxy(num, who + 4); printf("������������ ");
		textcolor(15);
	}

	else if (muni == 2 && sutza == 13)
	{
		textcolor(4);
		gotoxy(num, who); printf("������������ ");
		gotoxy(num, who + 1); printf("�� K  �� ");
		gotoxy(num, who + 2); printf("��  �� �� ");
		gotoxy(num, who + 3); printf("��   K�� ");
		gotoxy(num, who + 4); printf("������������ ");
		textcolor(15);
	}

	return 0;
}

int boonsu() //�м� �̺�Ʈ
{
	srand(rand());

	int hwakrull = rand() % 100 + 1;

	if (hwakrull>98) //2%Ȯ���� 500�� �ݱ�
	{
		dewhachang_clear();

		textcolor(9);
		gotoxy(4, 20);
		printf("[Ǫ����]");
		textcolor(15);

		gotoxy(4, 22);
		printf("�м����� 500���� �߰��ߴ�!");

		money += 500;

		gotoxy(73, 8);
		printf("������ : %11.f", money);
	}

	else if (hwakrull > 80) //18%Ȯ���� 100�� �ݱ�
	{
		dewhachang_clear();

		textcolor(9);
		gotoxy(4, 20);
		printf("[Ǫ����]");
		textcolor(15);

		gotoxy(4, 22);
		printf("�м����� 100���� �߰��ߴ�!");

		money += 100;

		gotoxy(73, 8);
		printf("������ : %11.f", money);
	}

	else //80%Ȯ���� �ƹ��͵� ���ݱ�
	{
		dewhachang_clear();

		textcolor(9);
		gotoxy(4, 20);
		printf("[Ǫ����]");
		textcolor(15);

		gotoxy(4, 22);
		printf("�м��� ������ ������ ����..");
	}

	Sleep(600);
	main();

	return 0;
}

int giboon_dewhachang() //�⺻ ��ȭâ
{
	dewhachang_clear();

	textcolor(9);
	gotoxy(4, 20);
	printf("[Ǫ����]");
	textcolor(15);

	gotoxy(4, 22);
	printf("������ ���� ���� ���� ����!!");

	gotoxy(55, 24);
	printf("(����Ű�� ���� Ǫ���̸� �̵����Ѻ�����)");

	return 0;
}

int ifzero() //���� 0���϶� ����� ��ȭâ
{
	dewhachang_clear();

	textcolor(9);
	gotoxy(4, 20);
	printf("[Ǫ����]");
	textcolor(15);

	gotoxy(4, 22);
	printf("���� ����... �м��� ������ ������ ������?");

	gotoxy(55, 24);
	printf("(����Ű�� ���� Ǫ���̸� �̵����Ѻ�����)");

	return 0;
}