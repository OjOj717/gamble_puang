#include "gamble_puang.h"

void CursorView() //醴憮陛 爾檜雖 彊啪 虜萄朝 л熱
{
    CONSOLE_CURSOR_INFO cursorInfo = { 0, };
    cursorInfo.dwSize = 1;
    cursorInfo.bVisible = FALSE;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}

void textcolor(int color_number) //轎溘 儀梃擊 夥脯輿朝 л熱
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color_number);
}

void gotoxy(int x, int y)//轎溘 嬪纂蒂 夥脯輿朝 л熱
{
    COORD pos = { x, y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

bool keeper(int map[][200], int X, int Y)  //雖釭陞夠婁 雖釭陛雖 彊擊 漁擊 掘碟п 輿朝 л熱
{
    if (map[Y + 2][X * 2] == 0 || map[Y + 3][X * 2] == 12) //裘擊 盪濰п菩 寡翮縑憮 0婁 12朝 綴夠檜棻.
    {
        return false;
    }
    else
    {
        return true;
    }
}

void makemap(int map[][200]) //檣攪む檜蝶蒂 斜萵 л熱
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
                printf("式");
                break;
            case 2:
                printf("弛");
                break;
            case 3:
                printf("忙");
                break;
            case 4:
                printf("忖");
                break;
            case 5:
                printf("戌");
                break;
            case 6:
                printf("戎");
                break;
            case 7:
                printf("成");
                break;
            case 8:
                printf("扛");
                break;
            case 9:
                printf("戍");
                break;
            case 10:
                printf("扣");
                break;
            case 101:
                printf("ん");
                break;
            case 102:
                printf("��");
                break;
            case 103:
                printf("礎");
                break;
            case 105:
                printf("碟熱");
                break;
            case 106:
                printf("衙薄");
                break;
            case 107:
                printf("蝸煜該褐");
                break;
            case 108:
                printf("綰楷燮");
                break;
            case 109:
                printf("唳葆濰");
                break;
            case 110:
                printf("醴");
                break;
            case 111:
                printf("#紫夢 斬瞰擎 1336#");
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
    printf("顫檜ぎ戲煎 給嬴陛溥賊 嬴鼠 幗が檜釭 援腦撮蹂_");
	char button = _getch();
}

void move(int map[][200]) //議葛攪陛 遺霜橾 л熱
{
	char text; 
	bool checker;

    while (chack_go)
    {

        text = _getch();
        textcolor(L_blue);
        switch (text) { //殮溘嫡擎 幗が(嬪,嬴楚,豭薹,螃艇薹)縑 評艇 蝶嬪纂僥

        case UP: gotoxy(X, Y + 2);
            if (chack_go == true)
            {
                printf(" ");//橾欽 雖辦堅 衛濛м棲棻.
                Y -= 1;//橾欽 謝ル蒂 檜翕衛麵爾晦

                checker = keeper(map, X, Y);
                //map寡翮 輿模諦 謝ル蒂 剩啖醜 瑣衛棻
                if (checker == false) {
                    gotoxy(X, Y + 2);
                    printf("≒");//雖釭陛紫 脹棻賊 斜濠葬縑 轎溘п輿堅
                    break;
                }
                else if (checker == true)
                {
                    Y += 1;//虞�饡磍抶� 謝ル蒂 棻衛 腎給萼�醴�
                    gotoxy(X, Y + 2);
                    printf("≒");//棻衛 轎溘п鄹棲棻.
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
                    printf("≒");
                    break;
                }
                else if (checker == true)
                {
                    Y -= 1;
                    gotoxy(X, Y + 2);
                    printf("≒");
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
                    printf("≒");

                    break;
                }
                else if (checker == true)
                {
                    X += 1;
                    gotoxy(X, Y + 2);
                    printf("≒");
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
                    printf("≒");

                    break;
                }
                else if (checker == true)
                {
                    X -= 1;
                    gotoxy(X, Y + 2);
                    printf("≒");
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
			case P_blackjack: //綰楷燮 Ы溯檜
				playing_state = blackjack();
				break;

			case P_poker: //ん醴 Ы溯檜
				playing_state = poker();
				break;

			case P_slotmachine: //蝸煜該褐 Ы溯檜
				playing_state = slotmachine();
				break;

			case P_holzzak: //�汕� Ы溯檜
				playing_state = holzzak();
				break;

			case P_horse: //唳葆 Ы溯檜
				playing_state = horse();
				break;

			case P_boonsu: //碟熱 Ы溯檜
				playing_state = boonsu();
				break;

			case P_mart: //葆お 霞殮
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

int eventplay() //檜漸お(啪歜衛濛 蛔蛔)陛 Ы溯檜腆 л熱
{
    textcolor(15);

    if (X == 20 && Y == 10 || X == 21 && Y == 10 || X == 22 && Y == 10) //綰楷燮 Ы溯檜
    {
        chack_go = false;
        Y = 9;
        return P_blackjack;
    }

    else if (X == 11 && Y == 2 || X == 11 && Y == 3 ) //ん醴 Ы溯檜
    {
        chack_go = false;
        X = 12;
        return P_poker;
    }

    else if (X == 17 && Y == 2 || X == 17 && Y == 4 || X == 16 && Y == 2 || X == 16 && Y == 4) //碟熱 檜漪
    {
		chack_go = false;
        if (Y == 2) Y = 1;
        else Y = 5;
        return P_boonsu;
    }

    else if (X == 36 && Y == 6 || X == 37 && Y == 6 || X == 38 && Y == 6) //蝸煜該褐 Ы溯檜
    {
        chack_go = false;
        Y = 7;
        return P_slotmachine;
    }

    else if (X == 9 && Y == 9 || X == 9 && Y == 10) //�汕� Ы溯檜
    {
        chack_go = false;
        X = 10;
        return P_holzzak;
    }

    else if (X == 46 && Y == 10 || X == 47 && Y == 10 || X == 48 && Y == 10) //唳葆 Ы溯檜
    {
        chack_go = false;
        Y = 9;
        return P_horse;
    }

    else if (X == 22 && Y == 4 || X == 22 && Y == 5) //衙薄 檜漸お
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
    printf("[ヰ懈檜]");
    textcolor(15);

    gotoxy(73, 6);
    printf("陴擎 綸 : %11.f", bit);

    gotoxy(73, 8);
    printf("模雖旎 : %11.f", money);
}

void mainwhameon_clear() //詭檣�飛� 蟾晦��
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

void dewhachang_clear() //渠�倥� 蟾晦��
{
	gotoxy(3, 20); printf("                                                                                             ");
	gotoxy(3, 21); printf("                                                                                             ");
	gotoxy(3, 22); printf("                                                                                             ");
	gotoxy(3, 23); printf("                                                                                             ");
	gotoxy(3, 24); printf("                                                                                             ");
}

void dewhachang(string name, string ment, string button) //渠�倥� 轎溘
{
	dewhachang_clear();

	gotoxy(4, 20);
	cout << name;

	gotoxy(4, 22);
	cout << ment;

	gotoxy(60, 24);
	cout << button;
}

void card(int muni, int sutza, int who, int num) //蘋萄 轎溘 л熱
{
	if (muni == 5 && sutza == 0)
	{
		gotoxy(num, who); printf("旨收收收收旬 ");
		gotoxy(num, who + 1); printf("早 ?  早 ");
		gotoxy(num, who + 2); printf("早  ? 早 ");
		gotoxy(num, who + 3); printf("早   ?早 ");
		gotoxy(num, who + 4); printf("曲收收收收旭 ");
	}

	else if (muni == 0 && sutza == 1)
	{
		textcolor(4);
		gotoxy(num, who); printf("旨收收收收旬 ");
		gotoxy(num, who + 1); printf("早 A  早 ");
		gotoxy(num, who + 2); printf("早  Ⅵ 早 ");
		gotoxy(num, who + 3); printf("早   A早 ");
		gotoxy(num, who + 4); printf("曲收收收收旭 ");
		textcolor(15);
	}

	else if (muni == 0 && sutza == 2)
	{
		textcolor(4);
		gotoxy(num, who); printf("旨收收收收旬 ");
		gotoxy(num, who + 1); printf("早 2  早 ");
		gotoxy(num, who + 2); printf("早  Ⅵ 早 ");
		gotoxy(num, who + 3); printf("早   2早 ");
		gotoxy(num, who + 4); printf("曲收收收收旭 ");
		textcolor(15);
	}

	else if (muni == 0 && sutza == 3)
	{
		textcolor(4);
		gotoxy(num, who); printf("旨收收收收旬 ");
		gotoxy(num, who + 1); printf("早 3  早 ");
		gotoxy(num, who + 2); printf("早  Ⅵ 早 ");
		gotoxy(num, who + 3); printf("早   3早 ");
		gotoxy(num, who + 4); printf("曲收收收收旭 ");
		textcolor(15);
	}

	else if (muni == 0 && sutza == 4)
	{
		textcolor(4);
		gotoxy(num, who); printf("旨收收收收旬 ");
		gotoxy(num, who + 1); printf("早 4  早 ");
		gotoxy(num, who + 2); printf("早  Ⅵ 早 ");
		gotoxy(num, who + 3); printf("早   4早 ");
		gotoxy(num, who + 4); printf("曲收收收收旭 ");
		textcolor(15);
	}

	else if (muni == 0 && sutza == 5)
	{
		textcolor(4);
		gotoxy(num, who); printf("旨收收收收旬 ");
		gotoxy(num, who + 1); printf("早 5  早 ");
		gotoxy(num, who + 2); printf("早  Ⅵ 早 ");
		gotoxy(num, who + 3); printf("早   5早 ");
		gotoxy(num, who + 4); printf("曲收收收收旭 ");
		textcolor(15);
	}

	else if (muni == 0 && sutza == 6)
	{
		textcolor(4);
		gotoxy(num, who); printf("旨收收收收旬 ");
		gotoxy(num, who + 1); printf("早 6  早 ");
		gotoxy(num, who + 2); printf("早  Ⅵ 早 ");
		gotoxy(num, who + 3); printf("早   6早 ");
		gotoxy(num, who + 4); printf("曲收收收收旭 ");
		textcolor(15);
	}

	else if (muni == 0 && sutza == 7)
	{
		textcolor(4);
		gotoxy(num, who); printf("旨收收收收旬 ");
		gotoxy(num, who + 1); printf("早 7  早 ");
		gotoxy(num, who + 2); printf("早  Ⅵ 早 ");
		gotoxy(num, who + 3); printf("早   7早 ");
		gotoxy(num, who + 4); printf("曲收收收收旭 ");
		textcolor(15);
	}

	else if (muni == 0 && sutza == 8)
	{
		textcolor(4);
		gotoxy(num, who); printf("旨收收收收旬 ");
		gotoxy(num, who + 1); printf("早 8  早 ");
		gotoxy(num, who + 2); printf("早  Ⅵ 早 ");
		gotoxy(num, who + 3); printf("早   8早 ");
		gotoxy(num, who + 4); printf("曲收收收收旭 ");
		textcolor(15);
	}

	else if (muni == 0 && sutza == 9)
	{
		textcolor(4);
		gotoxy(num, who); printf("旨收收收收旬 ");
		gotoxy(num, who + 1); printf("早 9  早 ");
		gotoxy(num, who + 2); printf("早  Ⅵ 早 ");
		gotoxy(num, who + 3); printf("早   9早 ");
		gotoxy(num, who + 4); printf("曲收收收收旭 ");
		textcolor(15);
	}

	else if (muni == 0 && sutza == 10)
	{
		textcolor(4);
		gotoxy(num, who); printf("旨收收收收旬 ");
		gotoxy(num, who + 1); printf("早10  早 ");
		gotoxy(num, who + 2); printf("早  Ⅵ 早 ");
		gotoxy(num, who + 3); printf("早  10早 ");
		gotoxy(num, who + 4); printf("曲收收收收旭 ");
		textcolor(15);
	}

	else if (muni == 0 && sutza == 11)
	{
		textcolor(4);
		gotoxy(num, who); printf("旨收收收收旬 ");
		gotoxy(num, who + 1); printf("早 J  早 ");
		gotoxy(num, who + 2); printf("早  Ⅵ 早 ");
		gotoxy(num, who + 3); printf("早   J早 ");
		gotoxy(num, who + 4); printf("曲收收收收旭 ");
		textcolor(15);
	}

	else if (muni == 0 && sutza == 12)
	{
		textcolor(4);
		gotoxy(num, who); printf("旨收收收收旬 ");
		gotoxy(num, who + 1); printf("早 Q  早 ");
		gotoxy(num, who + 2); printf("早  Ⅵ 早 ");
		gotoxy(num, who + 3); printf("早   Q早 ");
		gotoxy(num, who + 4); printf("曲收收收收旭 ");
		textcolor(15);
	}

	else if (muni == 0 && sutza == 13)
	{
		textcolor(4);
		gotoxy(num, who); printf("旨收收收收旬 ");
		gotoxy(num, who + 1); printf("早 K  早 ");
		gotoxy(num, who + 2); printf("早  Ⅵ 早 ");
		gotoxy(num, who + 3); printf("早   K早 ");
		gotoxy(num, who + 4); printf("曲收收收收旭 ");
		textcolor(15);
	}

	else if (muni == 1 && sutza == 1)
	{
		gotoxy(num, who); printf("旨收收收收旬 ");
		gotoxy(num, who + 1); printf("早 A  早 ");
		gotoxy(num, who + 2); printf("早  Ⅳ 早 ");
		gotoxy(num, who + 3); printf("早   A早 ");
		gotoxy(num, who + 4); printf("曲收收收收旭 ");
	}

	else if (muni == 1 && sutza == 2)
	{
		gotoxy(num, who); printf("旨收收收收旬 ");
		gotoxy(num, who + 1); printf("早 2  早 ");
		gotoxy(num, who + 2); printf("早  Ⅳ 早 ");
		gotoxy(num, who + 3); printf("早   2早 ");
		gotoxy(num, who + 4); printf("曲收收收收旭 ");
	}

	else if (muni == 1 && sutza == 3)
	{
		gotoxy(num, who); printf("旨收收收收旬 ");
		gotoxy(num, who + 1); printf("早 3  早 ");
		gotoxy(num, who + 2); printf("早  Ⅳ 早 ");
		gotoxy(num, who + 3); printf("早   3早 ");
		gotoxy(num, who + 4); printf("曲收收收收旭 ");
	}

	else if (muni == 1 && sutza == 4)
	{
		gotoxy(num, who); printf("旨收收收收旬 ");
		gotoxy(num, who + 1); printf("早 4  早 ");
		gotoxy(num, who + 2); printf("早  Ⅳ 早 ");
		gotoxy(num, who + 3); printf("早   4早 ");
		gotoxy(num, who + 4); printf("曲收收收收旭 ");
	}

	else if (muni == 1 && sutza == 5)
	{
		gotoxy(num, who); printf("旨收收收收旬 ");
		gotoxy(num, who + 1); printf("早 5  早 ");
		gotoxy(num, who + 2); printf("早  Ⅳ 早 ");
		gotoxy(num, who + 3); printf("早   5早 ");
		gotoxy(num, who + 4); printf("曲收收收收旭 ");
	}

	else if (muni == 1 && sutza == 6)
	{
		gotoxy(num, who); printf("旨收收收收旬 ");
		gotoxy(num, who + 1); printf("早 6  早 ");
		gotoxy(num, who + 2); printf("早  Ⅳ 早 ");
		gotoxy(num, who + 3); printf("早   6早 ");
		gotoxy(num, who + 4); printf("曲收收收收旭 ");
	}

	else if (muni == 1 && sutza == 7)
	{
		gotoxy(num, who); printf("旨收收收收旬 ");
		gotoxy(num, who + 1); printf("早 7  早 ");
		gotoxy(num, who + 2); printf("早  Ⅳ 早 ");
		gotoxy(num, who + 3); printf("早   7早 ");
		gotoxy(num, who + 4); printf("曲收收收收旭 ");
	}

	else if (muni == 1 && sutza == 8)
	{
		gotoxy(num, who); printf("旨收收收收旬 ");
		gotoxy(num, who + 1); printf("早 8  早 ");
		gotoxy(num, who + 2); printf("早  Ⅳ 早 ");
		gotoxy(num, who + 3); printf("早   8早 ");
		gotoxy(num, who + 4); printf("曲收收收收旭 ");
	}

	else if (muni == 1 && sutza == 9)
	{
		gotoxy(num, who); printf("旨收收收收旬 ");
		gotoxy(num, who + 1); printf("早 9  早 ");
		gotoxy(num, who + 2); printf("早  Ⅳ 早 ");
		gotoxy(num, who + 3); printf("早   9早 ");
		gotoxy(num, who + 4); printf("曲收收收收旭 ");
	}

	else if (muni == 1 && sutza == 10)
	{
		gotoxy(num, who); printf("旨收收收收旬 ");
		gotoxy(num, who + 1); printf("早10  早 ");
		gotoxy(num, who + 2); printf("早  Ⅳ 早 ");
		gotoxy(num, who + 3); printf("早  10早 ");
		gotoxy(num, who + 4); printf("曲收收收收旭 ");
	}

	else if (muni == 1 && sutza == 11)
	{
		gotoxy(num, who); printf("旨收收收收旬 ");
		gotoxy(num, who + 1); printf("早 J  早 ");
		gotoxy(num, who + 2); printf("早  Ⅳ 早 ");
		gotoxy(num, who + 3); printf("早   J早 ");
		gotoxy(num, who + 4); printf("曲收收收收旭 ");
	}

	else if (muni == 1 && sutza == 12)
	{
		gotoxy(num, who); printf("旨收收收收旬 ");
		gotoxy(num, who + 1); printf("早 Q  早 ");
		gotoxy(num, who + 2); printf("早  Ⅳ 早 ");
		gotoxy(num, who + 3); printf("早   Q早 ");
		gotoxy(num, who + 4); printf("曲收收收收旭 ");
	}

	else if (muni == 1 && sutza == 13)
	{
		gotoxy(num, who); printf("旨收收收收旬 ");
		gotoxy(num, who + 1); printf("早 K  早 ");
		gotoxy(num, who + 2); printf("早  Ⅳ 早 ");
		gotoxy(num, who + 3); printf("早   K早 ");
		gotoxy(num, who + 4); printf("曲收收收收旭 ");
	}

	else if (muni == 3 && sutza == 1)
	{
		gotoxy(num, who); printf("旨收收收收旬 ");
		gotoxy(num, who + 1); printf("早 A  早 ");
		gotoxy(num, who + 2); printf("早  Ⅷ 早 ");
		gotoxy(num, who + 3); printf("早   A早 ");
		gotoxy(num, who + 4); printf("曲收收收收旭 ");
	}

	else if (muni == 3 && sutza == 2)
	{
		gotoxy(num, who); printf("旨收收收收旬 ");
		gotoxy(num, who + 1); printf("早 2  早 ");
		gotoxy(num, who + 2); printf("早  Ⅷ 早 ");
		gotoxy(num, who + 3); printf("早   2早 ");
		gotoxy(num, who + 4); printf("曲收收收收旭 ");
	}

	else if (muni == 3 && sutza == 3)
	{
		gotoxy(num, who); printf("旨收收收收旬 ");
		gotoxy(num, who + 1); printf("早 3  早 ");
		gotoxy(num, who + 2); printf("早  Ⅷ 早 ");
		gotoxy(num, who + 3); printf("早   3早 ");
		gotoxy(num, who + 4); printf("曲收收收收旭 ");
	}

	else if (muni == 3 && sutza == 4)
	{
		gotoxy(num, who); printf("旨收收收收旬 ");
		gotoxy(num, who + 1); printf("早 4  早 ");
		gotoxy(num, who + 2); printf("早  Ⅷ 早 ");
		gotoxy(num, who + 3); printf("早   4早 ");
		gotoxy(num, who + 4); printf("曲收收收收旭 ");
	}

	else if (muni == 3 && sutza == 5)
	{
		gotoxy(num, who); printf("旨收收收收旬 ");
		gotoxy(num, who + 1); printf("早 5  早 ");
		gotoxy(num, who + 2); printf("早  Ⅷ 早 ");
		gotoxy(num, who + 3); printf("早   5早 ");
		gotoxy(num, who + 4); printf("曲收收收收旭 ");
	}

	else if (muni == 3 && sutza == 6)
	{
		gotoxy(num, who); printf("旨收收收收旬 ");
		gotoxy(num, who + 1); printf("早 6  早 ");
		gotoxy(num, who + 2); printf("早  Ⅷ 早 ");
		gotoxy(num, who + 3); printf("早   6早 ");
		gotoxy(num, who + 4); printf("曲收收收收旭 ");
	}

	else if (muni == 3 && sutza == 7)
	{
		gotoxy(num, who); printf("旨收收收收旬 ");
		gotoxy(num, who + 1); printf("早 7  早 ");
		gotoxy(num, who + 2); printf("早  Ⅷ 早 ");
		gotoxy(num, who + 3); printf("早   7早 ");
		gotoxy(num, who + 4); printf("曲收收收收旭 ");
	}

	else if (muni == 3 && sutza == 8)
	{
		gotoxy(num, who); printf("旨收收收收旬 ");
		gotoxy(num, who + 1); printf("早 8  早 ");
		gotoxy(num, who + 2); printf("早  Ⅷ 早 ");
		gotoxy(num, who + 3); printf("早   8早 ");
		gotoxy(num, who + 4); printf("曲收收收收旭 ");
	}

	else if (muni == 3 && sutza == 9)
	{
		gotoxy(num, who); printf("旨收收收收旬 ");
		gotoxy(num, who + 1); printf("早 9  早 ");
		gotoxy(num, who + 2); printf("早  Ⅷ 早 ");
		gotoxy(num, who + 3); printf("早   9早 ");
		gotoxy(num, who + 4); printf("曲收收收收旭 ");
	}

	else if (muni == 3 && sutza == 10)
	{
		gotoxy(num, who); printf("旨收收收收旬 ");
		gotoxy(num, who + 1); printf("早10  早 ");
		gotoxy(num, who + 2); printf("早  Ⅷ 早 ");
		gotoxy(num, who + 3); printf("早  10早 ");
		gotoxy(num, who + 4); printf("曲收收收收旭 ");
	}

	else if (muni == 3 && sutza == 11)
	{
		gotoxy(num, who); printf("旨收收收收旬 ");
		gotoxy(num, who + 1); printf("早 J  早 ");
		gotoxy(num, who + 2); printf("早  Ⅷ 早 ");
		gotoxy(num, who + 3); printf("早   J早 ");
		gotoxy(num, who + 4); printf("曲收收收收旭 ");
	}

	else if (muni == 3 && sutza == 12)
	{
		gotoxy(num, who); printf("旨收收收收旬 ");
		gotoxy(num, who + 1); printf("早 Q  早 ");
		gotoxy(num, who + 2); printf("早  Ⅷ 早 ");
		gotoxy(num, who + 3); printf("早   Q早 ");
		gotoxy(num, who + 4); printf("曲收收收收旭 ");
	}

	else if (muni == 3 && sutza == 13)
	{
		gotoxy(num, who); printf("旨收收收收旬 ");
		gotoxy(num, who + 1); printf("早 K  早 ");
		gotoxy(num, who + 2); printf("早  Ⅷ 早 ");
		gotoxy(num, who + 3); printf("早   K早 ");
		gotoxy(num, who + 4); printf("曲收收收收旭 ");
	}

	else if (muni == 2 && sutza == 1)
	{
		textcolor(4);
		gotoxy(num, who); printf("旨收收收收旬 ");
		gotoxy(num, who + 1); printf("早 A  早 ");
		gotoxy(num, who + 2); printf("早  ﹣ 早 ");
		gotoxy(num, who + 3); printf("早   A早 ");
		gotoxy(num, who + 4); printf("曲收收收收旭 ");
		textcolor(15);
	}

	else if (muni == 2 && sutza == 2)
	{
		textcolor(4);
		gotoxy(num, who); printf("旨收收收收旬 ");
		gotoxy(num, who + 1); printf("早 2  早 ");
		gotoxy(num, who + 2); printf("早  ﹣ 早 ");
		gotoxy(num, who + 3); printf("早   2早 ");
		gotoxy(num, who + 4); printf("曲收收收收旭 ");
		textcolor(15);
	}

	else if (muni == 2 && sutza == 3)
	{
		textcolor(4);
		gotoxy(num, who); printf("旨收收收收旬 ");
		gotoxy(num, who + 1); printf("早 3  早 ");
		gotoxy(num, who + 2); printf("早  ﹣ 早 ");
		gotoxy(num, who + 3); printf("早   3早 ");
		gotoxy(num, who + 4); printf("曲收收收收旭 ");
		textcolor(15);
	}

	else if (muni == 2 && sutza == 4)
	{
		textcolor(4);
		gotoxy(num, who); printf("旨收收收收旬 ");
		gotoxy(num, who + 1); printf("早 4  早 ");
		gotoxy(num, who + 2); printf("早  ﹣ 早 ");
		gotoxy(num, who + 3); printf("早   4早 ");
		gotoxy(num, who + 4); printf("曲收收收收旭 ");
		textcolor(15);
	}

	else if (muni == 2 && sutza == 5)
	{
		textcolor(4);
		gotoxy(num, who); printf("旨收收收收旬 ");
		gotoxy(num, who + 1); printf("早 5  早 ");
		gotoxy(num, who + 2); printf("早  ﹣ 早 ");
		gotoxy(num, who + 3); printf("早   5早 ");
		gotoxy(num, who + 4); printf("曲收收收收旭 ");
		textcolor(15);
	}

	else if (muni == 2 && sutza == 6)
	{
		textcolor(4);
		gotoxy(num, who); printf("旨收收收收旬 ");
		gotoxy(num, who + 1); printf("早 6  早 ");
		gotoxy(num, who + 2); printf("早  ﹣ 早 ");
		gotoxy(num, who + 3); printf("早   6早 ");
		gotoxy(num, who + 4); printf("曲收收收收旭 ");
		textcolor(15);
	}

	else if (muni == 2 && sutza == 7)
	{
		textcolor(4);
		gotoxy(num, who); printf("旨收收收收旬 ");
		gotoxy(num, who + 1); printf("早 7  早 ");
		gotoxy(num, who + 2); printf("早  ﹣ 早 ");
		gotoxy(num, who + 3); printf("早   7早 ");
		gotoxy(num, who + 4); printf("曲收收收收旭 ");
		textcolor(15);
	}

	else if (muni == 2 && sutza == 8)
	{
		textcolor(4);
		gotoxy(num, who); printf("旨收收收收旬 ");
		gotoxy(num, who + 1); printf("早 8  早 ");
		gotoxy(num, who + 2); printf("早  ﹣ 早 ");
		gotoxy(num, who + 3); printf("早   8早 ");
		gotoxy(num, who + 4); printf("曲收收收收旭 ");
		textcolor(15);
	}

	else if (muni == 2 && sutza == 9)
	{
		textcolor(4);
		gotoxy(num, who); printf("旨收收收收旬 ");
		gotoxy(num, who + 1); printf("早 9  早 ");
		gotoxy(num, who + 2); printf("早  ﹣ 早 ");
		gotoxy(num, who + 3); printf("早   9早 ");
		gotoxy(num, who + 4); printf("曲收收收收旭 ");
		textcolor(15);
	}

	else if (muni == 2 && sutza == 10)
	{
		textcolor(4);
		gotoxy(num, who); printf("旨收收收收旬 ");
		gotoxy(num, who + 1); printf("早10  早 ");
		gotoxy(num, who + 2); printf("早  ﹣ 早 ");
		gotoxy(num, who + 3); printf("早  10早 ");
		gotoxy(num, who + 4); printf("曲收收收收旭 ");
		textcolor(15);
	}

	else if (muni == 2 && sutza == 11)
	{
		textcolor(4);
		gotoxy(num, who); printf("旨收收收收旬 ");
		gotoxy(num, who + 1); printf("早 J  早 ");
		gotoxy(num, who + 2); printf("早  ﹣ 早 ");
		gotoxy(num, who + 3); printf("早   J早 ");
		gotoxy(num, who + 4); printf("曲收收收收旭 ");
		textcolor(15);
	}

	else if (muni == 2 && sutza == 12)
	{
		textcolor(4);
		gotoxy(num, who); printf("旨收收收收旬 ");
		gotoxy(num, who + 1); printf("早 Q  早 ");
		gotoxy(num, who + 2); printf("早  ﹣ 早 ");
		gotoxy(num, who + 3); printf("早   Q早 ");
		gotoxy(num, who + 4); printf("曲收收收收旭 ");
		textcolor(15);
	}

	else if (muni == 2 && sutza == 13)
	{
		textcolor(4);
		gotoxy(num, who); printf("旨收收收收旬 ");
		gotoxy(num, who + 1); printf("早 K  早 ");
		gotoxy(num, who + 2); printf("早  ﹣ 早 ");
		gotoxy(num, who + 3); printf("早   K早 ");
		gotoxy(num, who + 4); printf("曲收收收收旭 ");
		textcolor(15);
	}
}

void giboon_dewhachang() //晦獄 渠�倥�
{
	dewhachang_clear();

	textcolor(9);
	gotoxy(4, 20);
	printf("[ヰ懈檜]");
	textcolor(15);

	gotoxy(4, 22);
	printf("翮褕�� 絲擊 弊橫 綸擊 停濠!!");

	gotoxy(55, 24);
	printf("(寞щ酈蒂 揚楝 ヰ懈檜蒂 檜翕衛麵爾撮蹂)");
}

void ifzero() //絲檜 0錳橾陽 轎溘й 渠�倥�
{
	dewhachang_clear();

	textcolor(9);
	gotoxy(4, 20);
	printf("[ヰ懈檜]");
	textcolor(15);

	gotoxy(4, 22);
	printf("絲檜 橈橫... 碟熱縑 雲橫霞 翕瞪檜 橈擊梱?");

	gotoxy(55, 24);
	printf("(寞щ酈蒂 揚楝 ヰ懈檜蒂 檜翕衛麵爾撮蹂)");
}