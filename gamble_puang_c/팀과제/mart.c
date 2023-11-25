#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>

int mart_yes();
int bit_ggapggi();
int lotto();

extern double money;
extern int mmove;
extern double bit;

extern int poker_num;
extern int BJ_num;
extern int slot_num;
extern int holzzak_num;

int mart()
{
	char sigakbutton;
	int banbok = 0;

	gotoxy(73, 8);
	printf("소지금 : %11.f", money);

	dewhachang_clear();

	gotoxy(4, 20);
	printf("[매점 할매]");

	gotoxy(4, 22);
	printf("거기 청년, 여기서 할일이 있나?");

	gotoxy(70, 24);
	printf("[y] 예   [n] 아니오");

	sigakbutton = getch();

	switch (sigakbutton)
	{
	case 'y':
	case 'Y':
		mart_yes();
		break;
	case 'n':
	case 'N':
		mmove = 1;
		main();
		break;
	default:
		dewhachang_clear();

		gotoxy(4, 20);
		printf("[매점 할매]");
		gotoxy(4, 22);
		printf("그 버튼이 아니라구..");
		Sleep(300);
		mart();

		break;
	}

	return 0;
}

int mart_yes()
{
	char mode;

	dewhachang_clear();

	gotoxy(4, 20);
	printf("[매점 할매]");

	gotoxy(4, 22);
	printf("그럼 뭘 할껀데? 복권은 1000원이고 1등에게만 1억주는건 알지?");

	gotoxy(60, 24);
	printf("[1] 빚 상환   [2] 복권   [3] 안할래");

	mode = getch();

	switch (mode)
	{
	case '1':
		bit_ggapggi();
		break;
	case '2':
		lotto();
		break;
	case '3':
		mmove = 1;
		main();
		break;
	default:
		dewhachang_clear();

		gotoxy(4, 20);
		printf("[매점 할매]");
		gotoxy(4, 22);
		printf("그 버튼이 아니라구..");
		Sleep(300);
		mart();

		break;
	}

	return 0;
}

int bit_ggapggi()
{
	int ggapggi = 0;

	dewhachang_clear();

	gotoxy(4, 20);
	printf("[매점 할매]");

	gotoxy(4, 22);
	printf("얼마나 갚을 건데?");

	gotoxy(70, 24);
	printf("갚을 금액 : ");

	scanf_s("%d", &ggapggi);

	money -= ggapggi;

	if (money <= 0)
	{
		money += ggapggi;

		dewhachang_clear();

		gotoxy(4, 20);
		printf("[매점 할매]");

		gotoxy(4, 22);
		printf("아직 그정도로 못 벌었잖아?");

		gotoxy(70, 24);
		printf("아무 버튼이나 눌러주세요_");

		getch();
		mart();
	}

	else
	{
		gotoxy(73, 8);
		printf("소지금 : %11.f", money);

		bit -= ggapggi;

		gotoxy(73, 6);
		printf("남은 빚 : %11.f", bit);

		if (bit <= 0) //빚을 다 갚으면 끝
		{
			system("cls");
			gotoxy(0, 1);
			textcolor(11);
			printf("~엔딩 엔딩~");
			textcolor(15);
			printf("\n 플레이한 포커 횟수 : %d", poker_num);
			printf("\n 플레이한 블랙잭 횟수 : %d", BJ_num);
			printf("\n 플레이한 슬롯머신 횟수 : %d", slot_num);
			printf("\n 플레이한 홀짝 횟수 : %d", holzzak_num);
			printf("\n\n곧게임이 종료됩니다. BYE BYE~");
			Sleep(1000);
			exit(0);
		}

		else
		{

			dewhachang_clear();

			gotoxy(4, 20);
			printf("[매점 할매]");

			gotoxy(4, 22);
			printf("열심히 더 벌으라구 ㅎㅎ");

			gotoxy(70, 24);
			printf("아무 버튼이나 눌러주세요_");
			getch();
			mart();
		}
	}
	return 0;
}

int lotto()
{
	char jjadong;
	int ssudong[7] = { 0 };
	int llotto[7] = { 0 };

	money -= 1000;

	gotoxy(73, 8);
	printf("소지금 : %11.f", money);

	dewhachang_clear();

	gotoxy(4, 20);
	printf("[매점 할매]");

	gotoxy(4, 22);
	printf("직접 쓸래? 아니면 자동으로 할래?");

	gotoxy(60, 24);
	printf("[1] 수기로 작성 [2] 자동으로 구매");

	jjadong = getch();

	switch (jjadong)
	{
	case '1':
		dewhachang_clear();

		gotoxy(4, 20);
		printf("[매점 할매]");

		gotoxy(4, 22);
		printf("7개의 숫자를 띄어쓰기해서 적어라");

		gotoxy(60, 24);
		printf("숫자 : ");

		scanf_s("%d %d %d %d %d %d %d", &ssudong[0], &ssudong[1], &ssudong[2], &ssudong[3], &ssudong[4], &ssudong[5], &ssudong[6]); //수기로 로또 번호 입력받기
		break;
	case '2':
		srand(time(NULL));
		ssudong[0] = rand() % 10;
		ssudong[1] = rand() % 10;
		ssudong[2] = rand() % 10;
		ssudong[3] = rand() % 10;
		ssudong[4] = rand() % 10;
		ssudong[5] = rand() % 10;
		ssudong[6] = rand() % 10; //랜덤으로 로또 번호 지정하기

		dewhachang_clear();

		gotoxy(4, 20);
		printf("[매점 할매]");

		gotoxy(4, 22);
		printf("네 번호는 %d %d %d %d %d %d %d 이다.",llotto[0], llotto[1], llotto[2], llotto[3], llotto[4], llotto[5], llotto[6]);

		Sleep(2000);

		break;
	default:
		break;
	}

	srand(time(NULL));
	llotto[0] = rand() % 10;
	llotto[1] = rand() % 10;
	llotto[2] = rand() % 10;
	llotto[3] = rand() % 10;
	llotto[4] = rand() % 10;
	llotto[5] = rand() % 10;
	llotto[6] = rand() % 10;

	dewhachang_clear();

	gotoxy(4, 20);
	printf("[매점 할매]");

	gotoxy(4, 22);
	printf("이번 회차의 결과는 ");

	Sleep(100);
	printf("%d, ", llotto[0]);

	Sleep(100);
	printf("%d, ", llotto[1]);

	Sleep(100);
	printf("%d, ", llotto[2]);

	Sleep(100);
	printf("%d, ", llotto[3]);

	Sleep(100);
	printf("%d, ", llotto[4]);

	Sleep(100);
	printf("%d, ", llotto[5]);

	Sleep(200);
	printf("%d ", llotto[6]);

	Sleep(20);
	printf("이다.");

	Sleep(1000);

	if (ssudong[0] == llotto[0] && ssudong[1] == llotto[1] && ssudong[2] == llotto[2] && ssudong[3] == llotto[3] && ssudong[4] == llotto[4] && ssudong[5] == llotto[5] && ssudong[6] == llotto[6])
	{
		money += 100000000;

		gotoxy(73, 8);
		printf("소지금 : %11.f", money);

		dewhachang_clear();

		gotoxy(4, 20);
		printf("[매점 할매]");

		gotoxy(4, 22);
		printf("오 1등이 나왔구려..!! 축하한다네");

		gotoxy(70, 24);
		printf("아무 버튼이나 눌러주세요_");

		getch();
		mart();
	}
	else
	{
		dewhachang_clear();

		gotoxy(4, 20);
		printf("[매점 할매]");

		gotoxy(4, 22);
		printf("안타깝구려.. 다음을 노려봅세.");

		gotoxy(70, 24);
		printf("아무 버튼이나 눌러주세요_");

		getch();
		mart();
	}
	return 0;
}