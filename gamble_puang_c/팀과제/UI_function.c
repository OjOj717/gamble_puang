#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77

extern double money;
extern int X;
extern int Y;

int mmove = 1;

int makemap(int map[][200]) //檣攪む檜蝶蒂 斜萵 л熱
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

    return 0;
}

int move(int map[][200]) //議葛攪陛 遺霜橾 л熱
{
    int text, checker;

    while (1)
    {

        text = getch();
        textcolor(9);
        switch (text) { //殮溘嫡擎 幗が(嬪,嬴楚,豭薹,螃艇薹)縑 評艇 蝶嬪纂僥

        case UP: gotoxy(X, Y + 2);
			if (mmove == 1)
			{
				printf(" ");//橾欽 雖辦堅 衛濛м棲棻.
				Y -= 1;//橾欽 謝ル蒂 檜翕衛麵爾晦

				checker = keeper(map, X, Y);
				//map寡翮 輿模諦 謝ル蒂 剩啖醜 瑣衛棻
				if (checker == 1) {
					gotoxy(X, Y + 2);
					printf("≒");//雖釭陛紫 脹棻賊 斜濠葬縑 轎溘п輿堅
					break;
				}
				else if (checker == 0)
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
			if (mmove == 1)
			{
				printf(" ");
				Y += 1;
				checker = keeper(map, X, Y);
				if (checker == 1) {
					gotoxy(X, Y + 2);
					printf("≒");
					break;
				}
				else if (checker == 0)
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
			if (mmove == 1)
			{
				printf(" ");
				X -= 1;

				checker = keeper(map, X, Y);
				if (checker == 1) {

					gotoxy(X, Y + 2);
					printf("≒");

					break;
				}
				else if (checker == 0)
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
			if (mmove == 1)
			{
				printf(" ");
				X += 1;

				checker = keeper(map, X, Y);
				if (checker == 1) {

					gotoxy(X, Y + 2);
					printf("≒");

					break;
				}
				else if (checker == 0)
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

        eventplay();
		

        continue;
    }


    return 0;
}

int blackjack(); //綰楷燮 褒ч л熱
int poker(); //ん醴 褒ч л熱
int slotmachine(); //蝸煜該褐 褒ч л熱
int holzzak();//�汕� 褒ч л熱

int eventplay() //檜漸お(啪歜衛濛 蛔蛔)陛 Ы溯檜腆 л熱
{
    textcolor(15);

    if (X == 20 && Y == 10 || X == 21 && Y == 10 || X == 22 && Y == 10) //綰楷燮 Ы溯檜
    {
		mmove = 0;
		X = 20; Y = 9;
        blackjack();
    }

	else if (X == 11 && Y == 2) //ん醴 Ы溯檜
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
	
	else if (X == 17 && Y == 2) //碟熱 檜漪
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

	else if (X == 36 && Y == 6) //蝸煜該褐 Ы溯檜
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

	else if (X == 9 && Y == 9) //�汕� Ы溯檜
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
	
	else if (X == 46 && Y == 10) //唳葆濰 檜漸お
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

	else if (X == 22 && Y == 4) //衙薄 檜漸お
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

int mainwhameon_clear() //詭檣�飛� 蟾晦��
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

int dewhachang_clear() //渠�倥� 蟾晦��
{
    gotoxy(3, 20); printf("                                                                                             ");
    gotoxy(3, 21); printf("                                                                                             ");
    gotoxy(3, 22); printf("                                                                                             ");
    gotoxy(3, 23); printf("                                                                                             ");
    gotoxy(3, 24); printf("                                                                                             ");
      
    return 0;
} 

int card(int muni, int sutza, int who, int num) //蘋萄 轎溘 л熱
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

	return 0;
}

int boonsu() //碟熱 檜漸お
{
	srand(rand());

	int hwakrull = rand() % 100 + 1;

	if (hwakrull>98) //2%�捕�煎 500錳 鄹晦
	{
		dewhachang_clear();

		textcolor(9);
		gotoxy(4, 20);
		printf("[ヰ懈檜]");
		textcolor(15);

		gotoxy(4, 22);
		printf("碟熱縑憮 500錳擊 嫦唯ц棻!");

		money += 500;

		gotoxy(73, 8);
		printf("模雖旎 : %11.f", money);
	}

	else if (hwakrull > 80) //18%�捕�煎 100錳 鄹晦
	{
		dewhachang_clear();

		textcolor(9);
		gotoxy(4, 20);
		printf("[ヰ懈檜]");
		textcolor(15);

		gotoxy(4, 22);
		printf("碟熱縑憮 100錳擊 嫦唯ц棻!");

		money += 100;

		gotoxy(73, 8);
		printf("模雖旎 : %11.f", money);
	}

	else //80%�捕�煎 嬴鼠匙紫 跤鄹晦
	{
		dewhachang_clear();

		textcolor(9);
		gotoxy(4, 20);
		printf("[ヰ懈檜]");
		textcolor(15);

		gotoxy(4, 22);
		printf("碟熱縑 雲橫霞 翕瞪檜 橈啻..");
	}

	Sleep(600);
	main();

	return 0;
}

int giboon_dewhachang() //晦獄 渠�倥�
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

	return 0;
}

int ifzero() //絲檜 0錳橾陽 轎溘й 渠�倥�
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

	return 0;
}