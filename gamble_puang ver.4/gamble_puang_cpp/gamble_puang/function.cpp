#include "gamble_puang.h"

void CursorView() //Ŀ���� ������ �ʰ� ����� �Լ�
{
    CONSOLE_CURSOR_INFO cursorInfo = { 0, };
    cursorInfo.dwSize = 1;
    cursorInfo.bVisible = FALSE;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}

void textcolor(int color_number) //��� ������ �ٲ��ִ� �Լ�
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color_number);
}

void gotoxy(int x, int y)//��� ��ġ�� �ٲ��ִ� �Լ�
{
    COORD pos = { x, y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

bool keeper(int map[][200], int X, int Y)  //���������� �������� ���� ���� ������ �ִ� �Լ�
{
    if (map[Y + 2][X * 2] == 0 || map[Y + 3][X * 2] == 12) //���� �����ص� �迭���� 0�� 12�� ����̴�.
    {
        return false;
    }
    else
    {
        return true;
    }
}

void makemap(int map[][200]) //�������̽��� �׸� �Լ�
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
}

void draw_interface(int blank[][200])
{
    gotoxy(0, 0);
    makemap(blank);
}

void return_title()
{
    Sleep(800);
    gotoxy(46, 23);
    printf("Ÿ��Ʋ���� ���ư����� �ƹ� ��ư�̳� ��������_");
	char button = _getch();
}

void move(int map[][200]) //ĳ���Ͱ� ������ �Լ�
{
	char text; 
	bool checker;

    while (chack_go)
    {

        text = _getch();
        textcolor(L_blue);
        switch (text) { //�Է¹��� ��ư(��,�Ʒ�,����,������)�� ���� ����ġ��

        case UP: gotoxy(X, Y + 2);
            if (chack_go == true)
            {
                printf(" ");//�ϴ� ����� �����մϴ�.
                Y -= 1;//�ϴ� ��ǥ�� �̵����Ѻ���

                checker = keeper(map, X, Y);
                //map�迭 �ּҿ� ��ǥ�� �Ѱ��� ���ô�
                if (checker == false) {
                    gotoxy(X, Y + 2);
                    printf("��");//�������� �ȴٸ� ���ڸ��� ������ְ�
                    break;
                }
                else if (checker == true)
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
            if (chack_go == true)
            {
                printf(" ");
                Y += 1;
                checker = keeper(map, X, Y);
                if (checker == false) {
                    gotoxy(X, Y + 2);
                    printf("��");
                    break;
                }
                else if (checker == true)
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
            if (chack_go == true)
            {
                printf(" ");
                X -= 1;

                checker = keeper(map, X, Y);
                if (checker == false) {

                    gotoxy(X, Y + 2);
                    printf("��");

                    break;
                }
                else if (checker == true)
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
            if (chack_go == true)
            {
                printf(" ");
                X += 1;

                checker = keeper(map, X, Y);
                if (checker == false) {

                    gotoxy(X, Y + 2);
                    printf("��");

                    break;
                }
                else if (checker == true)
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

        playing_state = eventplay();

		while (playing_state != P_none)
		{
			switch (playing_state)
			{
			case P_blackjack: //���� �÷���
				playing_state = blackjack();
				break;

			case P_poker: //��Ŀ �÷���
				playing_state = poker();
				break;

			case P_slotmachine: //���Ըӽ� �÷���
				playing_state = slotmachine();
				break;

			case P_holzzak: //Ȧ¦ �÷���
				playing_state = holzzak();
				break;

			case P_horse: //�渶 �÷���
				playing_state = horse();
				break;

			case P_boonsu: //�м� �÷���
				playing_state = boonsu();
				break;

			case P_mart: //��Ʈ ����
				playing_state = mart();
				break;

			case P_packman:
				playing_state = packman();
				break;

			case P_snake:
				playing_state = snake();

			default:
				playing_state = P_none;
				break;
			}
		}

        continue;
    }

}

int eventplay() //�̺�Ʈ(���ӽ��� ���)�� �÷��̵� �Լ�
{
    textcolor(15);

    if (X == 20 && Y == 10 || X == 21 && Y == 10 || X == 22 && Y == 10) //���� �÷���
    {
        chack_go = false;
        Y = 9;
        return P_blackjack;
    }

    else if (X == 11 && Y == 2 || X == 11 && Y == 3 ) //��Ŀ �÷���
    {
        chack_go = false;
        X = 12;
        return P_poker;
    }

    else if (X == 17 && Y == 2 || X == 17 && Y == 4 || X == 16 && Y == 2 || X == 16 && Y == 4) //�м� �̺�
    {
		chack_go = false;
        if (Y == 2) Y = 1;
        else Y = 5;
        return P_boonsu;
    }

    else if (X == 36 && Y == 6 || X == 37 && Y == 6 || X == 38 && Y == 6) //���Ըӽ� �÷���
    {
        chack_go = false;
        Y = 7;
        return P_slotmachine;
    }

    else if (X == 9 && Y == 9 || X == 9 && Y == 10) //Ȧ¦ �÷���
    {
        chack_go = false;
        X = 10;
        return P_holzzak;
    }

    else if (X == 46 && Y == 10 || X == 47 && Y == 10 || X == 48 && Y == 10) //�渶 �÷���
    {
        chack_go = false;
        Y = 9;
        return P_horse;
    }

    else if (X == 22 && Y == 4 || X == 22 && Y == 5) //���� �̺�Ʈ
    {
        chack_go = false;
        X = 21;
        return P_mart;
    }

    else
    {
        return P_none;
    }

}

void draw_puang()
{
    gotoxy(65, 8);
    textcolor(6);
    printf("         -.");

    gotoxy(65, 9);
    textcolor(6);
    printf("        +  |,            _");

    gotoxy(65, 10);
    textcolor(6);
    printf("        ]   .*          / ;");

    gotoxy(55, 11);
    textcolor(9);
    printf("           / `.   ");

    textcolor(6);
    printf("i  } ");

    textcolor(9);
    printf(",=^     ");

    textcolor(6);
    printf(" [   ,");

    gotoxy(55, 12);
    textcolor(9);
    printf("           ;,r.w'\" * ^''  \\   ");

    textcolor(6);
    printf("&   /'");

    gotoxy(55, 13);
    textcolor(9);
    printf("         .z^`              `");

    textcolor(6);
    printf("\"   r");

    gotoxy(55, 14);
    textcolor(9);
    printf("       ,z                    '=  -\"'^");

    gotoxy(55, 15);
    printf(" ~   ./     ");

    textcolor(11);
    printf("(  )    (   )       ");

    textcolor(9);
    printf("^r  : .~");

    gotoxy(55, 16);
    printf("(   Y      ");

    textcolor(15);
    printf("##          ##          ");

    textcolor(9);
    printf("}_/");

    gotoxy(55, 17);
    printf(" \\,j      ");

    textcolor(15);
    printf("###         ###      ");

    textcolor(9);
    printf(",/\", 'j");

    gotoxy(55, 18);
    printf("   f`\\,");

    textcolor(13);
    printf("**     ");

    textcolor(7);
    printf("' '        ");

    textcolor(13);
    printf("**");

    textcolor(9);
    printf(",>~/     {");

    gotoxy(55, 19);
    printf("   {  ");

    textcolor(13);
    printf("****   ");

    textcolor(3);
    printf("~\"\"\"\"\"\\,   ");

    textcolor(13);
    printf("****");

    textcolor(9);
    printf("/ ");

    gotoxy(55, 20);
    printf("   f   ");

    textcolor(13);
    printf("**   ");

    textcolor(3);
    printf("[   .- - L   ");

    textcolor(13);
    printf("**      ");

    textcolor(9);
    printf("   }");

    gotoxy(55, 21);
    printf("    k        ");

    textcolor(3);
    printf("L` , ,_J              ");

    textcolor(9);
    printf(")");

    gotoxy(55, 22);
    printf("     b,                           i");

    gotoxy(55, 23);
    printf("       p                        q'");

    gotoxy(55, 24);
    printf("         `-.                .n-\"");
}

void print_money()
{
    textcolor(9);
    gotoxy(80, 3);
    printf("[Ǫ����]");
    textcolor(15);

    gotoxy(73, 6);
    printf("���� �� : %11.f", bit);

    gotoxy(73, 8);
    printf("������ : %11.f", money);
}

void mainwhameon_clear() //����ȭ�� �ʱ�ȭ
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
}

void dewhachang_clear() //��ȭâ �ʱ�ȭ
{
	gotoxy(3, 20); printf("                                                                                             ");
	gotoxy(3, 21); printf("                                                                                             ");
	gotoxy(3, 22); printf("                                                                                             ");
	gotoxy(3, 23); printf("                                                                                             ");
	gotoxy(3, 24); printf("                                                                                             ");
}

void dewhachang(string name, string ment, string button) //��ȭâ ���
{
	dewhachang_clear();

	gotoxy(4, 20);
	cout << name;

	gotoxy(4, 22);
	cout << ment;

	gotoxy(60, 24);
	cout << button;
}

void card(int muni, int sutza, int who, int num) //ī�� ��� �Լ�
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
}

void giboon_dewhachang() //�⺻ ��ȭâ
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
}

void ifzero() //���� 0���϶� ����� ��ȭâ
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
}