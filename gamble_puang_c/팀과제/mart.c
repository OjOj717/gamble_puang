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
	printf("������ : %11.f", money);

	dewhachang_clear();

	gotoxy(4, 20);
	printf("[���� �Ҹ�]");

	gotoxy(4, 22);
	printf("�ű� û��, ���⼭ ������ �ֳ�?");

	gotoxy(70, 24);
	printf("[y] ��   [n] �ƴϿ�");

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
		printf("[���� �Ҹ�]");
		gotoxy(4, 22);
		printf("�� ��ư�� �ƴ϶�..");
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
	printf("[���� �Ҹ�]");

	gotoxy(4, 22);
	printf("�׷� �� �Ҳ���? ������ 1000���̰� 1��Ը� 1���ִ°� ����?");

	gotoxy(60, 24);
	printf("[1] �� ��ȯ   [2] ����   [3] ���ҷ�");

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
		printf("[���� �Ҹ�]");
		gotoxy(4, 22);
		printf("�� ��ư�� �ƴ϶�..");
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
	printf("[���� �Ҹ�]");

	gotoxy(4, 22);
	printf("�󸶳� ���� �ǵ�?");

	gotoxy(70, 24);
	printf("���� �ݾ� : ");

	scanf_s("%d", &ggapggi);

	money -= ggapggi;

	if (money <= 0)
	{
		money += ggapggi;

		dewhachang_clear();

		gotoxy(4, 20);
		printf("[���� �Ҹ�]");

		gotoxy(4, 22);
		printf("���� �������� �� �����ݾ�?");

		gotoxy(70, 24);
		printf("�ƹ� ��ư�̳� �����ּ���_");

		getch();
		mart();
	}

	else
	{
		gotoxy(73, 8);
		printf("������ : %11.f", money);

		bit -= ggapggi;

		gotoxy(73, 6);
		printf("���� �� : %11.f", bit);

		if (bit <= 0) //���� �� ������ ��
		{
			system("cls");
			gotoxy(0, 1);
			textcolor(11);
			printf("~���� ����~");
			textcolor(15);
			printf("\n �÷����� ��Ŀ Ƚ�� : %d", poker_num);
			printf("\n �÷����� ���� Ƚ�� : %d", BJ_num);
			printf("\n �÷����� ���Ըӽ� Ƚ�� : %d", slot_num);
			printf("\n �÷����� Ȧ¦ Ƚ�� : %d", holzzak_num);
			printf("\n\n������� ����˴ϴ�. BYE BYE~");
			Sleep(1000);
			exit(0);
		}

		else
		{

			dewhachang_clear();

			gotoxy(4, 20);
			printf("[���� �Ҹ�]");

			gotoxy(4, 22);
			printf("������ �� ������ ����");

			gotoxy(70, 24);
			printf("�ƹ� ��ư�̳� �����ּ���_");
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
	printf("������ : %11.f", money);

	dewhachang_clear();

	gotoxy(4, 20);
	printf("[���� �Ҹ�]");

	gotoxy(4, 22);
	printf("���� ����? �ƴϸ� �ڵ����� �ҷ�?");

	gotoxy(60, 24);
	printf("[1] ����� �ۼ� [2] �ڵ����� ����");

	jjadong = getch();

	switch (jjadong)
	{
	case '1':
		dewhachang_clear();

		gotoxy(4, 20);
		printf("[���� �Ҹ�]");

		gotoxy(4, 22);
		printf("7���� ���ڸ� �����ؼ� �����");

		gotoxy(60, 24);
		printf("���� : ");

		scanf_s("%d %d %d %d %d %d %d", &ssudong[0], &ssudong[1], &ssudong[2], &ssudong[3], &ssudong[4], &ssudong[5], &ssudong[6]); //����� �ζ� ��ȣ �Է¹ޱ�
		break;
	case '2':
		srand(time(NULL));
		ssudong[0] = rand() % 10;
		ssudong[1] = rand() % 10;
		ssudong[2] = rand() % 10;
		ssudong[3] = rand() % 10;
		ssudong[4] = rand() % 10;
		ssudong[5] = rand() % 10;
		ssudong[6] = rand() % 10; //�������� �ζ� ��ȣ �����ϱ�

		dewhachang_clear();

		gotoxy(4, 20);
		printf("[���� �Ҹ�]");

		gotoxy(4, 22);
		printf("�� ��ȣ�� %d %d %d %d %d %d %d �̴�.",llotto[0], llotto[1], llotto[2], llotto[3], llotto[4], llotto[5], llotto[6]);

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
	printf("[���� �Ҹ�]");

	gotoxy(4, 22);
	printf("�̹� ȸ���� ����� ");

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
	printf("�̴�.");

	Sleep(1000);

	if (ssudong[0] == llotto[0] && ssudong[1] == llotto[1] && ssudong[2] == llotto[2] && ssudong[3] == llotto[3] && ssudong[4] == llotto[4] && ssudong[5] == llotto[5] && ssudong[6] == llotto[6])
	{
		money += 100000000;

		gotoxy(73, 8);
		printf("������ : %11.f", money);

		dewhachang_clear();

		gotoxy(4, 20);
		printf("[���� �Ҹ�]");

		gotoxy(4, 22);
		printf("�� 1���� ���Ա���..!! �����Ѵٳ�");

		gotoxy(70, 24);
		printf("�ƹ� ��ư�̳� �����ּ���_");

		getch();
		mart();
	}
	else
	{
		dewhachang_clear();

		gotoxy(4, 20);
		printf("[���� �Ҹ�]");

		gotoxy(4, 22);
		printf("��Ÿ������.. ������ �������.");

		gotoxy(70, 24);
		printf("�ƹ� ��ư�̳� �����ּ���_");

		getch();
		mart();
	}
	return 0;
}