#include "gamble_puang.h"

//게임 상태별 진행
int title()
{
	CursorView();
	SetConsoleTitle(TEXT("##Gamble PUANG##"));

	draw_interface(blank_screen);

	for (int i = 0; i < 5; i++)
	{
		gotoxy(3, i + 1);
		cout << t_gamble[i];
	}

	textcolor(L_aqua);
	for (int i = 0; i < 6; i++)
	{
		gotoxy(9, i + 5);
		cout << t_PUANG[i];
	}

	draw_puang();

    textcolor(L_white);
	for (int i = 0; i < 3; i++)
	{
		gotoxy(15, i * 2 + 16);
		cout << t_title_choice[i];
	}

	title_choice = _getch();

	switch (title_choice)
	{
	case '1':
		return G_opening;
		break;

    case '2':
        return G_rule;
        break;
        
    case '3':
        return G_credit;
	}

    return 0;
}

int opening()
{
    draw_interface(blank_screen);

    gotoxy(25, 9);
    printf("본 게임은 저장과 불러오기가 가능한 \"게임\"입니다.");

    gotoxy(37, 12);
    textcolor(12);
    printf("하지만 현실은 다릅니다.");

    gotoxy(34, 14);
    textcolor(4);
    printf("도박, 게임으로만 즐겨주세요.");

    textcolor(15);

    Sleep(3000);

    draw_interface(blank_screen);

    Sleep(1000);
    for (int i = 0; i < 14; i++)
    {
        gotoxy(8, i + 3);
        cout << t_opning_story[i];

        if (t_opning_story[i] == " ")
        {
            Sleep(500);
        }
    }

    Sleep(2000);
    gotoxy(8, 19);
    textcolor(3);
    cout << t_opning_story[14];

    Sleep(2000);

    return G_playing;
}

int rule()
{
    draw_interface(blank_screen);

    gotoxy(40, 3);
    printf("[  게 임  설 명  ]");

    for (int i = 0; i < 4; i++)
    {
        if (i < 4)
        {
            gotoxy(10, i * 2 + 7);
            cout << t_rule[i];

            if (i == 2)
            {
                gotoxy(35, 11);
                textcolor(L_blue);
                printf("●");
                textcolor(L_white);
            }
        }

        else if (i >= 4)
        {
            gotoxy(10, i + 11);
            cout << t_rule[i];
        }
    }

    return_title();

    return G_title;
}

int credit()
{
    draw_interface(blank_screen);

    for (int i = 0; i < 8; i++)
    {
        gotoxy(38, i * 2 + 3);
        cout << t_credit[i];
    }

    return_title();

    return G_title;
}

int playing()
{
    textcolor(L_white);
    draw_interface(casino_map);

    print_money();

    if (money <= 0)
        ifzero();
    else
        giboon_dewhachang();

    textcolor(L_blue);
    gotoxy(X, Y + 2);
    printf("●");

    chack_go = true;
    move(casino_map);

    return G_playing;
}