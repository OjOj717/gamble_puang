#include "gamble_puang.h"

void mart_yes();
void bit_ggapggi();
void lotto();

int mart()
{
play:
	gotoxy(73, 8);
	printf("������ : %11.f", money);

	dewhachang_clear();

	gotoxy(4, 20);
	printf("[���� �Ҹ�]");

	gotoxy(4, 22);
	printf("�ű� û��, ���⼭ ������ �ֳ�?");

	gotoxy(70, 24);
	printf("[y] ��   [n] �ƴϿ�");

	button = _getch();

	switch (button)
	{
	case 'y':
	case 'Y':
		mart_yes();
		goto play;
		break;

	case 'n':
	case 'N':
		return P_none;
		break;

	default:
		dewhachang_clear();

		gotoxy(4, 20);
		printf("[���� �Ҹ�]");
		gotoxy(4, 22);
		printf("�� ��ư�� �ƴ϶�..");
		Sleep(300);
		goto play;

		break;
	}
}

void mart_yes()
{
yes:
	dewhachang_clear();

	gotoxy(4, 20);
	printf("[���� �Ҹ�]");

	gotoxy(4, 22);
	printf("�׷� �� �Ҳ���? ������ 1000���̰� 1��Ը� 1���ִ°� ����?");

	gotoxy(60, 24);
	printf("[1] �� ��ȯ   [2] ����   [3] ���ҷ�");

	switch (button = _getch())
	{
	case '1':
		bit_ggapggi();
		break;

	case '2':
		lotto();
		break;

	case '3':
		chack_go = true;
		break;

	default:
		dewhachang_clear();

		gotoxy(4, 20);
		printf("[���� �Ҹ�]");
		gotoxy(4, 22);
		printf("�� ��ư�� �ƴ϶�..");
		Sleep(300);
		goto yes;

		break;
	}
}

void bit_ggapggi()
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

		button = _getch();
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
			button = _getch();
		}
	}
}

void lotto()
{
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

	switch (button = _getch())
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
		printf("�� ��ȣ�� %d %d %d %d %d %d %d �̴�.", llotto[0], llotto[1], llotto[2], llotto[3], llotto[4], llotto[5], llotto[6]);

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

		button = _getch();
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

		button = _getch();
	}
}