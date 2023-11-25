#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77

extern double money;
extern int X;
extern int Y;

int mmove = 1;

int makemap(int map[][200]) //ÀÎÅÍÆäÀÌ½º¸¦ ±×¸± ÇÔ¼ö
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
                printf("¦¡");
                break;
            case 2:
                printf("¦¢");
                break;
            case 3:
                printf("¦£");
                break;
            case 4:
                printf("¦¤");
                break;
            case 5:
                printf("¦¦");
                break;
            case 6:
                printf("¦¥");
                break;
            case 7:
                printf("¦¨");
                break;
            case 8:
                printf("¦ª");
                break;
            case 9:
                printf("¦§");
                break;
            case 10:
                printf("¦©");
                break;
            case 101:
                printf("Æ÷");
                break;
            case 102:
                printf("È¦");
                break;
            case 103:
                printf("Â¦");
                break;
            case 105:
                printf("ºÐ¼ö");
                break;
            case 106:
                printf("¸ÅÁ¡");
                break;
            case 107:
                printf("½½·Ô¸Ó½Å");
                break;
            case 108:
                printf("ºí·¢Àè");
                break;
            case 109:
                printf("°æ¸¶Àå");
                break;
            case 110:
                printf("Ä¿");
                break;
            case 111:
                printf("#µµ¹Ú ±ÙÀýÀº 1336#");
                break;
            }
        }
        printf("\n");
    }

    return 0;
}

int move(int map[][200]) //Ä³¸¯ÅÍ°¡ ¿òÁ÷ÀÏ ÇÔ¼ö
{
    int text, checker;

    while (1)
    {

        text = getch();
        textcolor(9);
        switch (text) { //ÀÔ·Â¹ÞÀº ¹öÆ°(À§,¾Æ·¡,¿ÞÂÊ,¿À¸¥ÂÊ)¿¡ µû¸¥ ½ºÀ§Ä¡¹®

        case UP: gotoxy(X, Y + 2);
			if (mmove == 1)
			{
				printf(" ");//ÀÏ´Ü Áö¿ì°í ½ÃÀÛÇÕ´Ï´Ù.
				Y -= 1;//ÀÏ´Ü ÁÂÇ¥¸¦ ÀÌµ¿½ÃÄÑº¸±â

				checker = keeper(map, X, Y);
				//map¹è¿­ ÁÖ¼Ò¿Í ÁÂÇ¥¸¦ ³Ñ°ÜÁà º¾½Ã´Ù
				if (checker == 1) {
					gotoxy(X, Y + 2);
					printf("¡Ü");//Áö³ª°¡µµ µÈ´Ù¸é ±×ÀÚ¸®¿¡ Ãâ·ÂÇØÁÖ°í
					break;
				}
				else if (checker == 0)
				{
					Y += 1;//¸·Èù±æÀÌ¸é ÁÂÇ¥¸¦ ´Ù½Ã µÇµ¹¸°ÈÄ¿¡
					gotoxy(X, Y + 2);
					printf("¡Ü");//´Ù½Ã Ãâ·ÂÇØÁÝ´Ï´Ù.
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
					printf("¡Ü");
					break;
				}
				else if (checker == 0)
				{
					Y -= 1;
					gotoxy(X, Y + 2);
					printf("¡Ü");
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
					printf("¡Ü");

					break;
				}
				else if (checker == 0)
				{
					X += 1;
					gotoxy(X, Y + 2);
					printf("¡Ü");
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
					printf("¡Ü");

					break;
				}
				else if (checker == 0)
				{
					X -= 1;
					gotoxy(X, Y + 2);
					printf("¡Ü");
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

int blackjack(); //ºí·¢Àè ½ÇÇà ÇÔ¼ö
int poker(); //Æ÷Ä¿ ½ÇÇà ÇÔ¼ö
int slotmachine(); //½½·Ô¸Ó½Å ½ÇÇà ÇÔ¼ö
int holzzak();//È¦Â¦ ½ÇÇà ÇÔ¼ö

int eventplay() //ÀÌº¥Æ®(°ÔÀÓ½ÃÀÛ µîµî)°¡ ÇÃ·¹ÀÌµÉ ÇÔ¼ö
{
    textcolor(15);

    if (X == 20 && Y == 10 || X == 21 && Y == 10 || X == 22 && Y == 10) //ºí·¢Àè ÇÃ·¹ÀÌ
    {
		mmove = 0;
		X = 20; Y = 9;
        blackjack();
    }

	else if (X == 11 && Y == 2) //Æ÷Ä¿ ÇÃ·¹ÀÌ
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
	
	else if (X == 17 && Y == 2) //ºÐ¼ö ÀÌº¬
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

	else if (X == 36 && Y == 6) //½½·Ô¸Ó½Å ÇÃ·¹ÀÌ
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

	else if (X == 9 && Y == 9) //È¦Â¦ ÇÃ·¹ÀÌ
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
	
	else if (X == 46 && Y == 10) //°æ¸¶Àå ÀÌº¥Æ®
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

	else if (X == 22 && Y == 4) //¸ÅÁ¡ ÀÌº¥Æ®
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

int mainwhameon_clear() //¸ÞÀÎÈ­¸é ÃÊ±âÈ­
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

int dewhachang_clear() //´ëÈ­Ã¢ ÃÊ±âÈ­
{
    gotoxy(3, 20); printf("                                                                                             ");
    gotoxy(3, 21); printf("                                                                                             ");
    gotoxy(3, 22); printf("                                                                                             ");
    gotoxy(3, 23); printf("                                                                                             ");
    gotoxy(3, 24); printf("                                                                                             ");
      
    return 0;
} 

int card(int muni, int sutza, int who, int num) //Ä«µå Ãâ·Â ÇÔ¼ö
{
	if (muni == 5 && sutza == 0)
	{
		gotoxy(num, who); printf("¦®¦¬¦¬¦¬¦¬¦¯ ");
		gotoxy(num, who + 1); printf("¦­ ?  ¦­ ");
		gotoxy(num, who + 2); printf("¦­  ? ¦­ ");
		gotoxy(num, who + 3); printf("¦­   ?¦­ ");
		gotoxy(num, who + 4); printf("¦±¦¬¦¬¦¬¦¬¦° ");
	}

	else if (muni == 0 && sutza == 1)
	{
		textcolor(4);
		gotoxy(num, who); printf("¦®¦¬¦¬¦¬¦¬¦¯ ");
		gotoxy(num, who + 1); printf("¦­ A  ¦­ ");
		gotoxy(num, who + 2); printf("¦­  ¢¾ ¦­ ");
		gotoxy(num, who + 3); printf("¦­   A¦­ ");
		gotoxy(num, who + 4); printf("¦±¦¬¦¬¦¬¦¬¦° ");
		textcolor(15);
	}

	else if (muni == 0 && sutza == 2)
	{
		textcolor(4);
		gotoxy(num, who); printf("¦®¦¬¦¬¦¬¦¬¦¯ ");
		gotoxy(num, who + 1); printf("¦­ 2  ¦­ ");
		gotoxy(num, who + 2); printf("¦­  ¢¾ ¦­ ");
		gotoxy(num, who + 3); printf("¦­   2¦­ ");
		gotoxy(num, who + 4); printf("¦±¦¬¦¬¦¬¦¬¦° ");
		textcolor(15);
	}

	else if (muni == 0 && sutza == 3)
	{
		textcolor(4);
		gotoxy(num, who); printf("¦®¦¬¦¬¦¬¦¬¦¯ ");
		gotoxy(num, who + 1); printf("¦­ 3  ¦­ ");
		gotoxy(num, who + 2); printf("¦­  ¢¾ ¦­ ");
		gotoxy(num, who + 3); printf("¦­   3¦­ ");
		gotoxy(num, who + 4); printf("¦±¦¬¦¬¦¬¦¬¦° ");
		textcolor(15);
	}

	else if (muni == 0 && sutza == 4)
	{
		textcolor(4);
		gotoxy(num, who); printf("¦®¦¬¦¬¦¬¦¬¦¯ ");
		gotoxy(num, who + 1); printf("¦­ 4  ¦­ ");
		gotoxy(num, who + 2); printf("¦­  ¢¾ ¦­ ");
		gotoxy(num, who + 3); printf("¦­   4¦­ ");
		gotoxy(num, who + 4); printf("¦±¦¬¦¬¦¬¦¬¦° ");
		textcolor(15);
	}

	else if (muni == 0 && sutza == 5)
	{
		textcolor(4);
		gotoxy(num, who); printf("¦®¦¬¦¬¦¬¦¬¦¯ ");
		gotoxy(num, who + 1); printf("¦­ 5  ¦­ ");
		gotoxy(num, who + 2); printf("¦­  ¢¾ ¦­ ");
		gotoxy(num, who + 3); printf("¦­   5¦­ ");
		gotoxy(num, who + 4); printf("¦±¦¬¦¬¦¬¦¬¦° ");
		textcolor(15);
	}

	else if (muni == 0 && sutza == 6)
	{
		textcolor(4);
		gotoxy(num, who); printf("¦®¦¬¦¬¦¬¦¬¦¯ ");
		gotoxy(num, who + 1); printf("¦­ 6  ¦­ ");
		gotoxy(num, who + 2); printf("¦­  ¢¾ ¦­ ");
		gotoxy(num, who + 3); printf("¦­   6¦­ ");
		gotoxy(num, who + 4); printf("¦±¦¬¦¬¦¬¦¬¦° ");
		textcolor(15);
	}

	else if (muni == 0 && sutza == 7)
	{
		textcolor(4);
		gotoxy(num, who); printf("¦®¦¬¦¬¦¬¦¬¦¯ ");
		gotoxy(num, who + 1); printf("¦­ 7  ¦­ ");
		gotoxy(num, who + 2); printf("¦­  ¢¾ ¦­ ");
		gotoxy(num, who + 3); printf("¦­   7¦­ ");
		gotoxy(num, who + 4); printf("¦±¦¬¦¬¦¬¦¬¦° ");
		textcolor(15);
	}

	else if (muni == 0 && sutza == 8)
	{
		textcolor(4);
		gotoxy(num, who); printf("¦®¦¬¦¬¦¬¦¬¦¯ ");
		gotoxy(num, who + 1); printf("¦­ 8  ¦­ ");
		gotoxy(num, who + 2); printf("¦­  ¢¾ ¦­ ");
		gotoxy(num, who + 3); printf("¦­   8¦­ ");
		gotoxy(num, who + 4); printf("¦±¦¬¦¬¦¬¦¬¦° ");
		textcolor(15);
	}

	else if (muni == 0 && sutza == 9)
	{
		textcolor(4);
		gotoxy(num, who); printf("¦®¦¬¦¬¦¬¦¬¦¯ ");
		gotoxy(num, who + 1); printf("¦­ 9  ¦­ ");
		gotoxy(num, who + 2); printf("¦­  ¢¾ ¦­ ");
		gotoxy(num, who + 3); printf("¦­   9¦­ ");
		gotoxy(num, who + 4); printf("¦±¦¬¦¬¦¬¦¬¦° ");
		textcolor(15);
	}

	else if (muni == 0 && sutza == 10)
	{
		textcolor(4);
		gotoxy(num, who); printf("¦®¦¬¦¬¦¬¦¬¦¯ ");
		gotoxy(num, who + 1); printf("¦­10  ¦­ ");
		gotoxy(num, who + 2); printf("¦­  ¢¾ ¦­ ");
		gotoxy(num, who + 3); printf("¦­  10¦­ ");
		gotoxy(num, who + 4); printf("¦±¦¬¦¬¦¬¦¬¦° ");
		textcolor(15);
	}

	else if (muni == 0 && sutza == 11)
	{
		textcolor(4);
		gotoxy(num, who); printf("¦®¦¬¦¬¦¬¦¬¦¯ ");
		gotoxy(num, who + 1); printf("¦­ J  ¦­ ");
		gotoxy(num, who + 2); printf("¦­  ¢¾ ¦­ ");
		gotoxy(num, who + 3); printf("¦­   J¦­ ");
		gotoxy(num, who + 4); printf("¦±¦¬¦¬¦¬¦¬¦° ");
		textcolor(15);
	}

	else if (muni == 0 && sutza == 12)
	{
		textcolor(4);
		gotoxy(num, who); printf("¦®¦¬¦¬¦¬¦¬¦¯ ");
		gotoxy(num, who + 1); printf("¦­ Q  ¦­ ");
		gotoxy(num, who + 2); printf("¦­  ¢¾ ¦­ ");
		gotoxy(num, who + 3); printf("¦­   Q¦­ ");
		gotoxy(num, who + 4); printf("¦±¦¬¦¬¦¬¦¬¦° ");
		textcolor(15);
	}

	else if (muni == 0 && sutza == 13)
	{
		textcolor(4);
		gotoxy(num, who); printf("¦®¦¬¦¬¦¬¦¬¦¯ ");
		gotoxy(num, who + 1); printf("¦­ K  ¦­ ");
		gotoxy(num, who + 2); printf("¦­  ¢¾ ¦­ ");
		gotoxy(num, who + 3); printf("¦­   K¦­ ");
		gotoxy(num, who + 4); printf("¦±¦¬¦¬¦¬¦¬¦° ");
		textcolor(15);
	}

	else if (muni == 1 && sutza == 1)
	{
		gotoxy(num, who); printf("¦®¦¬¦¬¦¬¦¬¦¯ ");
		gotoxy(num, who + 1); printf("¦­ A  ¦­ ");
		gotoxy(num, who + 2); printf("¦­  ¢¼ ¦­ ");
		gotoxy(num, who + 3); printf("¦­   A¦­ ");
		gotoxy(num, who + 4); printf("¦±¦¬¦¬¦¬¦¬¦° ");
	}

	else if (muni == 1 && sutza == 2)
	{
		gotoxy(num, who); printf("¦®¦¬¦¬¦¬¦¬¦¯ ");
		gotoxy(num, who + 1); printf("¦­ 2  ¦­ ");
		gotoxy(num, who + 2); printf("¦­  ¢¼ ¦­ ");
		gotoxy(num, who + 3); printf("¦­   2¦­ ");
		gotoxy(num, who + 4); printf("¦±¦¬¦¬¦¬¦¬¦° ");
	}

	else if (muni == 1 && sutza == 3)
	{
		gotoxy(num, who); printf("¦®¦¬¦¬¦¬¦¬¦¯ ");
		gotoxy(num, who + 1); printf("¦­ 3  ¦­ ");
		gotoxy(num, who + 2); printf("¦­  ¢¼ ¦­ ");
		gotoxy(num, who + 3); printf("¦­   3¦­ ");
		gotoxy(num, who + 4); printf("¦±¦¬¦¬¦¬¦¬¦° ");
	}

	else if (muni == 1 && sutza == 4)
	{
		gotoxy(num, who); printf("¦®¦¬¦¬¦¬¦¬¦¯ ");
		gotoxy(num, who + 1); printf("¦­ 4  ¦­ ");
		gotoxy(num, who + 2); printf("¦­  ¢¼ ¦­ ");
		gotoxy(num, who + 3); printf("¦­   4¦­ ");
		gotoxy(num, who + 4); printf("¦±¦¬¦¬¦¬¦¬¦° ");
	}

	else if (muni == 1 && sutza == 5)
	{
		gotoxy(num, who); printf("¦®¦¬¦¬¦¬¦¬¦¯ ");
		gotoxy(num, who + 1); printf("¦­ 5  ¦­ ");
		gotoxy(num, who + 2); printf("¦­  ¢¼ ¦­ ");
		gotoxy(num, who + 3); printf("¦­   5¦­ ");
		gotoxy(num, who + 4); printf("¦±¦¬¦¬¦¬¦¬¦° ");
	}

	else if (muni == 1 && sutza == 6)
	{
		gotoxy(num, who); printf("¦®¦¬¦¬¦¬¦¬¦¯ ");
		gotoxy(num, who + 1); printf("¦­ 6  ¦­ ");
		gotoxy(num, who + 2); printf("¦­  ¢¼ ¦­ ");
		gotoxy(num, who + 3); printf("¦­   6¦­ ");
		gotoxy(num, who + 4); printf("¦±¦¬¦¬¦¬¦¬¦° ");
	}

	else if (muni == 1 && sutza == 7)
	{
		gotoxy(num, who); printf("¦®¦¬¦¬¦¬¦¬¦¯ ");
		gotoxy(num, who + 1); printf("¦­ 7  ¦­ ");
		gotoxy(num, who + 2); printf("¦­  ¢¼ ¦­ ");
		gotoxy(num, who + 3); printf("¦­   7¦­ ");
		gotoxy(num, who + 4); printf("¦±¦¬¦¬¦¬¦¬¦° ");
	}

	else if (muni == 1 && sutza == 8)
	{
		gotoxy(num, who); printf("¦®¦¬¦¬¦¬¦¬¦¯ ");
		gotoxy(num, who + 1); printf("¦­ 8  ¦­ ");
		gotoxy(num, who + 2); printf("¦­  ¢¼ ¦­ ");
		gotoxy(num, who + 3); printf("¦­   8¦­ ");
		gotoxy(num, who + 4); printf("¦±¦¬¦¬¦¬¦¬¦° ");
	}

	else if (muni == 1 && sutza == 9)
	{
		gotoxy(num, who); printf("¦®¦¬¦¬¦¬¦¬¦¯ ");
		gotoxy(num, who + 1); printf("¦­ 9  ¦­ ");
		gotoxy(num, who + 2); printf("¦­  ¢¼ ¦­ ");
		gotoxy(num, who + 3); printf("¦­   9¦­ ");
		gotoxy(num, who + 4); printf("¦±¦¬¦¬¦¬¦¬¦° ");
	}

	else if (muni == 1 && sutza == 10)
	{
		gotoxy(num, who); printf("¦®¦¬¦¬¦¬¦¬¦¯ ");
		gotoxy(num, who + 1); printf("¦­10  ¦­ ");
		gotoxy(num, who + 2); printf("¦­  ¢¼ ¦­ ");
		gotoxy(num, who + 3); printf("¦­  10¦­ ");
		gotoxy(num, who + 4); printf("¦±¦¬¦¬¦¬¦¬¦° ");
	}

	else if (muni == 1 && sutza == 11)
	{
		gotoxy(num, who); printf("¦®¦¬¦¬¦¬¦¬¦¯ ");
		gotoxy(num, who + 1); printf("¦­ J  ¦­ ");
		gotoxy(num, who + 2); printf("¦­  ¢¼ ¦­ ");
		gotoxy(num, who + 3); printf("¦­   J¦­ ");
		gotoxy(num, who + 4); printf("¦±¦¬¦¬¦¬¦¬¦° ");
	}

	else if (muni == 1 && sutza == 12)
	{
		gotoxy(num, who); printf("¦®¦¬¦¬¦¬¦¬¦¯ ");
		gotoxy(num, who + 1); printf("¦­ Q  ¦­ ");
		gotoxy(num, who + 2); printf("¦­  ¢¼ ¦­ ");
		gotoxy(num, who + 3); printf("¦­   Q¦­ ");
		gotoxy(num, who + 4); printf("¦±¦¬¦¬¦¬¦¬¦° ");
	}

	else if (muni == 1 && sutza == 13)
	{
		gotoxy(num, who); printf("¦®¦¬¦¬¦¬¦¬¦¯ ");
		gotoxy(num, who + 1); printf("¦­ K  ¦­ ");
		gotoxy(num, who + 2); printf("¦­  ¢¼ ¦­ ");
		gotoxy(num, who + 3); printf("¦­   K¦­ ");
		gotoxy(num, who + 4); printf("¦±¦¬¦¬¦¬¦¬¦° ");
	}

	else if (muni == 3 && sutza == 1)
	{
		gotoxy(num, who); printf("¦®¦¬¦¬¦¬¦¬¦¯ ");
		gotoxy(num, who + 1); printf("¦­ A  ¦­ ");
		gotoxy(num, who + 2); printf("¦­  ¢À ¦­ ");
		gotoxy(num, who + 3); printf("¦­   A¦­ ");
		gotoxy(num, who + 4); printf("¦±¦¬¦¬¦¬¦¬¦° ");
	}

	else if (muni == 3 && sutza == 2)
	{
		gotoxy(num, who); printf("¦®¦¬¦¬¦¬¦¬¦¯ ");
		gotoxy(num, who + 1); printf("¦­ 2  ¦­ ");
		gotoxy(num, who + 2); printf("¦­  ¢À ¦­ ");
		gotoxy(num, who + 3); printf("¦­   2¦­ ");
		gotoxy(num, who + 4); printf("¦±¦¬¦¬¦¬¦¬¦° ");
	}

	else if (muni == 3 && sutza == 3)
	{
		gotoxy(num, who); printf("¦®¦¬¦¬¦¬¦¬¦¯ ");
		gotoxy(num, who + 1); printf("¦­ 3  ¦­ ");
		gotoxy(num, who + 2); printf("¦­  ¢À ¦­ ");
		gotoxy(num, who + 3); printf("¦­   3¦­ ");
		gotoxy(num, who + 4); printf("¦±¦¬¦¬¦¬¦¬¦° ");
	}

	else if (muni == 3 && sutza == 4)
	{
		gotoxy(num, who); printf("¦®¦¬¦¬¦¬¦¬¦¯ ");
		gotoxy(num, who + 1); printf("¦­ 4  ¦­ ");
		gotoxy(num, who + 2); printf("¦­  ¢À ¦­ ");
		gotoxy(num, who + 3); printf("¦­   4¦­ ");
		gotoxy(num, who + 4); printf("¦±¦¬¦¬¦¬¦¬¦° ");
	}

	else if (muni == 3 && sutza == 5)
	{
		gotoxy(num, who); printf("¦®¦¬¦¬¦¬¦¬¦¯ ");
		gotoxy(num, who + 1); printf("¦­ 5  ¦­ ");
		gotoxy(num, who + 2); printf("¦­  ¢À ¦­ ");
		gotoxy(num, who + 3); printf("¦­   5¦­ ");
		gotoxy(num, who + 4); printf("¦±¦¬¦¬¦¬¦¬¦° ");
	}

	else if (muni == 3 && sutza == 6)
	{
		gotoxy(num, who); printf("¦®¦¬¦¬¦¬¦¬¦¯ ");
		gotoxy(num, who + 1); printf("¦­ 6  ¦­ ");
		gotoxy(num, who + 2); printf("¦­  ¢À ¦­ ");
		gotoxy(num, who + 3); printf("¦­   6¦­ ");
		gotoxy(num, who + 4); printf("¦±¦¬¦¬¦¬¦¬¦° ");
	}

	else if (muni == 3 && sutza == 7)
	{
		gotoxy(num, who); printf("¦®¦¬¦¬¦¬¦¬¦¯ ");
		gotoxy(num, who + 1); printf("¦­ 7  ¦­ ");
		gotoxy(num, who + 2); printf("¦­  ¢À ¦­ ");
		gotoxy(num, who + 3); printf("¦­   7¦­ ");
		gotoxy(num, who + 4); printf("¦±¦¬¦¬¦¬¦¬¦° ");
	}

	else if (muni == 3 && sutza == 8)
	{
		gotoxy(num, who); printf("¦®¦¬¦¬¦¬¦¬¦¯ ");
		gotoxy(num, who + 1); printf("¦­ 8  ¦­ ");
		gotoxy(num, who + 2); printf("¦­  ¢À ¦­ ");
		gotoxy(num, who + 3); printf("¦­   8¦­ ");
		gotoxy(num, who + 4); printf("¦±¦¬¦¬¦¬¦¬¦° ");
	}

	else if (muni == 3 && sutza == 9)
	{
		gotoxy(num, who); printf("¦®¦¬¦¬¦¬¦¬¦¯ ");
		gotoxy(num, who + 1); printf("¦­ 9  ¦­ ");
		gotoxy(num, who + 2); printf("¦­  ¢À ¦­ ");
		gotoxy(num, who + 3); printf("¦­   9¦­ ");
		gotoxy(num, who + 4); printf("¦±¦¬¦¬¦¬¦¬¦° ");
	}

	else if (muni == 3 && sutza == 10)
	{
		gotoxy(num, who); printf("¦®¦¬¦¬¦¬¦¬¦¯ ");
		gotoxy(num, who + 1); printf("¦­10  ¦­ ");
		gotoxy(num, who + 2); printf("¦­  ¢À ¦­ ");
		gotoxy(num, who + 3); printf("¦­  10¦­ ");
		gotoxy(num, who + 4); printf("¦±¦¬¦¬¦¬¦¬¦° ");
	}

	else if (muni == 3 && sutza == 11)
	{
		gotoxy(num, who); printf("¦®¦¬¦¬¦¬¦¬¦¯ ");
		gotoxy(num, who + 1); printf("¦­ J  ¦­ ");
		gotoxy(num, who + 2); printf("¦­  ¢À ¦­ ");
		gotoxy(num, who + 3); printf("¦­   J¦­ ");
		gotoxy(num, who + 4); printf("¦±¦¬¦¬¦¬¦¬¦° ");
	}

	else if (muni == 3 && sutza == 12)
	{
		gotoxy(num, who); printf("¦®¦¬¦¬¦¬¦¬¦¯ ");
		gotoxy(num, who + 1); printf("¦­ Q  ¦­ ");
		gotoxy(num, who + 2); printf("¦­  ¢À ¦­ ");
		gotoxy(num, who + 3); printf("¦­   Q¦­ ");
		gotoxy(num, who + 4); printf("¦±¦¬¦¬¦¬¦¬¦° ");
	}

	else if (muni == 3 && sutza == 13)
	{
		gotoxy(num, who); printf("¦®¦¬¦¬¦¬¦¬¦¯ ");
		gotoxy(num, who + 1); printf("¦­ K  ¦­ ");
		gotoxy(num, who + 2); printf("¦­  ¢À ¦­ ");
		gotoxy(num, who + 3); printf("¦­   K¦­ ");
		gotoxy(num, who + 4); printf("¦±¦¬¦¬¦¬¦¬¦° ");
	}

	else if (muni == 2 && sutza == 1)
	{
		textcolor(4);
		gotoxy(num, who); printf("¦®¦¬¦¬¦¬¦¬¦¯ ");
		gotoxy(num, who + 1); printf("¦­ A  ¦­ ");
		gotoxy(num, who + 2); printf("¦­  ¡ß ¦­ ");
		gotoxy(num, who + 3); printf("¦­   A¦­ ");
		gotoxy(num, who + 4); printf("¦±¦¬¦¬¦¬¦¬¦° ");
		textcolor(15);
	}

	else if (muni == 2 && sutza == 2)
	{
		textcolor(4);
		gotoxy(num, who); printf("¦®¦¬¦¬¦¬¦¬¦¯ ");
		gotoxy(num, who + 1); printf("¦­ 2  ¦­ ");
		gotoxy(num, who + 2); printf("¦­  ¡ß ¦­ ");
		gotoxy(num, who + 3); printf("¦­   2¦­ ");
		gotoxy(num, who + 4); printf("¦±¦¬¦¬¦¬¦¬¦° ");
		textcolor(15);
	}

	else if (muni == 2 && sutza == 3)
	{
		textcolor(4);
		gotoxy(num, who); printf("¦®¦¬¦¬¦¬¦¬¦¯ ");
		gotoxy(num, who + 1); printf("¦­ 3  ¦­ ");
		gotoxy(num, who + 2); printf("¦­  ¡ß ¦­ ");
		gotoxy(num, who + 3); printf("¦­   3¦­ ");
		gotoxy(num, who + 4); printf("¦±¦¬¦¬¦¬¦¬¦° ");
		textcolor(15);
	}

	else if (muni == 2 && sutza == 4)
	{
		textcolor(4);
		gotoxy(num, who); printf("¦®¦¬¦¬¦¬¦¬¦¯ ");
		gotoxy(num, who + 1); printf("¦­ 4  ¦­ ");
		gotoxy(num, who + 2); printf("¦­  ¡ß ¦­ ");
		gotoxy(num, who + 3); printf("¦­   4¦­ ");
		gotoxy(num, who + 4); printf("¦±¦¬¦¬¦¬¦¬¦° ");
		textcolor(15);
	}

	else if (muni == 2 && sutza == 5)
	{
		textcolor(4);
		gotoxy(num, who); printf("¦®¦¬¦¬¦¬¦¬¦¯ ");
		gotoxy(num, who + 1); printf("¦­ 5  ¦­ ");
		gotoxy(num, who + 2); printf("¦­  ¡ß ¦­ ");
		gotoxy(num, who + 3); printf("¦­   5¦­ ");
		gotoxy(num, who + 4); printf("¦±¦¬¦¬¦¬¦¬¦° ");
		textcolor(15);
	}

	else if (muni == 2 && sutza == 6)
	{
		textcolor(4);
		gotoxy(num, who); printf("¦®¦¬¦¬¦¬¦¬¦¯ ");
		gotoxy(num, who + 1); printf("¦­ 6  ¦­ ");
		gotoxy(num, who + 2); printf("¦­  ¡ß ¦­ ");
		gotoxy(num, who + 3); printf("¦­   6¦­ ");
		gotoxy(num, who + 4); printf("¦±¦¬¦¬¦¬¦¬¦° ");
		textcolor(15);
	}

	else if (muni == 2 && sutza == 7)
	{
		textcolor(4);
		gotoxy(num, who); printf("¦®¦¬¦¬¦¬¦¬¦¯ ");
		gotoxy(num, who + 1); printf("¦­ 7  ¦­ ");
		gotoxy(num, who + 2); printf("¦­  ¡ß ¦­ ");
		gotoxy(num, who + 3); printf("¦­   7¦­ ");
		gotoxy(num, who + 4); printf("¦±¦¬¦¬¦¬¦¬¦° ");
		textcolor(15);
	}

	else if (muni == 2 && sutza == 8)
	{
		textcolor(4);
		gotoxy(num, who); printf("¦®¦¬¦¬¦¬¦¬¦¯ ");
		gotoxy(num, who + 1); printf("¦­ 8  ¦­ ");
		gotoxy(num, who + 2); printf("¦­  ¡ß ¦­ ");
		gotoxy(num, who + 3); printf("¦­   8¦­ ");
		gotoxy(num, who + 4); printf("¦±¦¬¦¬¦¬¦¬¦° ");
		textcolor(15);
	}

	else if (muni == 2 && sutza == 9)
	{
		textcolor(4);
		gotoxy(num, who); printf("¦®¦¬¦¬¦¬¦¬¦¯ ");
		gotoxy(num, who + 1); printf("¦­ 9  ¦­ ");
		gotoxy(num, who + 2); printf("¦­  ¡ß ¦­ ");
		gotoxy(num, who + 3); printf("¦­   9¦­ ");
		gotoxy(num, who + 4); printf("¦±¦¬¦¬¦¬¦¬¦° ");
		textcolor(15);
	}

	else if (muni == 2 && sutza == 10)
	{
		textcolor(4);
		gotoxy(num, who); printf("¦®¦¬¦¬¦¬¦¬¦¯ ");
		gotoxy(num, who + 1); printf("¦­10  ¦­ ");
		gotoxy(num, who + 2); printf("¦­  ¡ß ¦­ ");
		gotoxy(num, who + 3); printf("¦­  10¦­ ");
		gotoxy(num, who + 4); printf("¦±¦¬¦¬¦¬¦¬¦° ");
		textcolor(15);
	}

	else if (muni == 2 && sutza == 11)
	{
		textcolor(4);
		gotoxy(num, who); printf("¦®¦¬¦¬¦¬¦¬¦¯ ");
		gotoxy(num, who + 1); printf("¦­ J  ¦­ ");
		gotoxy(num, who + 2); printf("¦­  ¡ß ¦­ ");
		gotoxy(num, who + 3); printf("¦­   J¦­ ");
		gotoxy(num, who + 4); printf("¦±¦¬¦¬¦¬¦¬¦° ");
		textcolor(15);
	}

	else if (muni == 2 && sutza == 12)
	{
		textcolor(4);
		gotoxy(num, who); printf("¦®¦¬¦¬¦¬¦¬¦¯ ");
		gotoxy(num, who + 1); printf("¦­ Q  ¦­ ");
		gotoxy(num, who + 2); printf("¦­  ¡ß ¦­ ");
		gotoxy(num, who + 3); printf("¦­   Q¦­ ");
		gotoxy(num, who + 4); printf("¦±¦¬¦¬¦¬¦¬¦° ");
		textcolor(15);
	}

	else if (muni == 2 && sutza == 13)
	{
		textcolor(4);
		gotoxy(num, who); printf("¦®¦¬¦¬¦¬¦¬¦¯ ");
		gotoxy(num, who + 1); printf("¦­ K  ¦­ ");
		gotoxy(num, who + 2); printf("¦­  ¡ß ¦­ ");
		gotoxy(num, who + 3); printf("¦­   K¦­ ");
		gotoxy(num, who + 4); printf("¦±¦¬¦¬¦¬¦¬¦° ");
		textcolor(15);
	}

	return 0;
}

int boonsu() //ºÐ¼ö ÀÌº¥Æ®
{
	srand(rand());

	int hwakrull = rand() % 100 + 1;

	if (hwakrull>98) //2%È®·ü·Î 500¿ø ÁÝ±â
	{
		dewhachang_clear();

		textcolor(9);
		gotoxy(4, 20);
		printf("[Çª¾ÓÀÌ]");
		textcolor(15);

		gotoxy(4, 22);
		printf("ºÐ¼ö¿¡¼­ 500¿øÀ» ¹ß°ßÇß´Ù!");

		money += 500;

		gotoxy(73, 8);
		printf("¼ÒÁö±Ý : %11.f", money);
	}

	else if (hwakrull > 80) //18%È®·ü·Î 100¿ø ÁÝ±â
	{
		dewhachang_clear();

		textcolor(9);
		gotoxy(4, 20);
		printf("[Çª¾ÓÀÌ]");
		textcolor(15);

		gotoxy(4, 22);
		printf("ºÐ¼ö¿¡¼­ 100¿øÀ» ¹ß°ßÇß´Ù!");

		money += 100;

		gotoxy(73, 8);
		printf("¼ÒÁö±Ý : %11.f", money);
	}

	else //80%È®·ü·Î ¾Æ¹«°Íµµ ¸øÁÝ±â
	{
		dewhachang_clear();

		textcolor(9);
		gotoxy(4, 20);
		printf("[Çª¾ÓÀÌ]");
		textcolor(15);

		gotoxy(4, 22);
		printf("ºÐ¼ö¿¡ ¶³¾îÁø µ¿ÀüÀÌ ¾ø³×..");
	}

	Sleep(600);
	main();

	return 0;
}

int giboon_dewhachang() //±âº» ´ëÈ­Ã¢
{
	dewhachang_clear();

	textcolor(9);
	gotoxy(4, 20);
	printf("[Çª¾ÓÀÌ]");
	textcolor(15);

	gotoxy(4, 22);
	printf("¿­½ÉÈ÷ µ·À» ¹ú¾î ºúÀ» °±ÀÚ!!");

	gotoxy(55, 24);
	printf("(¹æÇâÅ°¸¦ ´­·¯ Çª¾ÓÀÌ¸¦ ÀÌµ¿½ÃÄÑº¸¼¼¿ä)");

	return 0;
}

int ifzero() //µ·ÀÌ 0¿øÀÏ¶§ Ãâ·ÂÇÒ ´ëÈ­Ã¢
{
	dewhachang_clear();

	textcolor(9);
	gotoxy(4, 20);
	printf("[Çª¾ÓÀÌ]");
	textcolor(15);

	gotoxy(4, 22);
	printf("µ·ÀÌ ¾ø¾î... ºÐ¼ö¿¡ ¶³¾îÁø µ¿ÀüÀÌ ¾øÀ»±î?");

	gotoxy(55, 24);
	printf("(¹æÇâÅ°¸¦ ´­·¯ Çª¾ÓÀÌ¸¦ ÀÌµ¿½ÃÄÑº¸¼¼¿ä)");

	return 0;
}