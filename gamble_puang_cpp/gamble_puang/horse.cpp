#include "gamble_puang.h"

void horse_yes(); //���ӽ���
void horse_yeonsoopmode(); //�������
void horse_realmode(); //�������
void horse_rule(); //���ӷ�
void draw_horse(int i, int r); //�� �׸���

int horse()
{
play:
	mainwhameon_clear();

	print_money();

	gotoxy(3, 1);
	printf("= = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =");

	gotoxy(3, 5);
	printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -");

	gotoxy(3, 9);
	printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -");

	gotoxy(3, 13);
	printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -");

	gotoxy(3, 17);
	printf("= = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =");

	draw_horse(1, 1);
	draw_horse(1, 5);
	draw_horse(1, 9);
	draw_horse(1, 13);

	textcolor(6);
	gotoxy(3, 3);
	printf("1");

	gotoxy(3, 7);
	printf("2");

	gotoxy(3, 11);
	printf("3");

	gotoxy(3, 15);
	printf("4");

	textcolor(15);

	dewhachang("[�渶 ����]", "�÷��� �Ͻðڽ��ϱ�?", "[y] ��   [n] �ƴϿ� [r] ���� ��Ģ");

	button = _getch();

	switch (button)
	{
	case 'y':
	case 'Y':
		horse_yes();
		goto play;
		break;

	case 'n':
	case 'N':
		return P_none;
		break;

	case 'r':
	case 'R':
		horse_rule();
		goto play;
		break;

	default:
		dewhachang("[�渶�� ����]", "�ٽ� ������ �ּ���.", " ");

		Sleep(300);
		goto play;

		break;
	}

	return P_none;
}

void horse_yes()
{
yes:
	dewhachang("[�渶�� ����]", "�����Ͻǰǰ���?", "[y] ��   [n] �ƴϿ� (����)");

	button = _getch();

	switch (button)
	{
	case 'y':
	case 'Y':
		horse_yeonsoopmode();
		break;

	case 'n':
	case 'N':
		horse_realmode();
		break;

	default:
		dewhachang("[�渶�� ����]", "�ٽ� ������ �ּ���.", " ");

		Sleep(300);
		goto yes;

		break;
	}
}

void horse_yeonsoopmode()
{
	char suntek;
	int	random, r;
	int i = 0, j = 0, k = 0, l = 0;

	dewhachang_clear();

	gotoxy(4, 20);
	printf("[�渶�� ����]");

	gotoxy(4, 22);
	printf("�׸����� �� �� ����� �Ѹ����� ������ ������ �ּ���.");

	gotoxy(60, 24);
	printf("������ �ּ���_");

	suntek = _getch();

	while (i <= 50 && j <= 50 && k <= 50 && l <= 50)
	{
		srand((unsigned)time(NULL) + rand());
		random = rand() % 4 + 1;

		switch (random)
		{
		case 1:
			i++;
			r = 1;
			draw_horse(i, r);
			break;

		case 2:
			j++;
			r = 5;
			draw_horse(j, r);
			break;

		case 3:
			k++;
			r = 9;
			draw_horse(k, r);
			break;

		case 4:
			l++;
			r = 13;
			draw_horse(l, r);
			break;

		default:
			break;
		}
	}

	if (i == 51 && suntek == '1')
	{
		dewhachang_clear();

		gotoxy(4, 20);
		printf("[�渶�� ����]");

		gotoxy(4, 22);
		printf("�����մϴ�! 1������ ����Ͽ����ϴ�!");

		gotoxy(60, 24);
		printf("�ƹ� ��ư�̳� �����ּ���_");
	}

	else if (i == 51)
	{
		dewhachang_clear();

		gotoxy(4, 20);
		printf("[�渶�� ����]");

		gotoxy(4, 22);
		printf("�ƽ����ϴ�! 1������ ����Ͽ����ϴ�.");

		gotoxy(60, 24);
		printf("�ƹ� ��ư�̳� �����ּ���_");
	}

	else if (j == 51 && suntek == '2')
	{
		dewhachang_clear();

		gotoxy(4, 20);
		printf("[�渶�� ����]");

		gotoxy(4, 22);
		printf("�����մϴ�! 2������ ����Ͽ����ϴ�!");

		gotoxy(60, 24);
		printf("�ƹ� ��ư�̳� �����ּ���_");
	}

	else if (j == 51)
	{
		dewhachang_clear();

		gotoxy(4, 20);
		printf("[�渶�� ����]");

		gotoxy(4, 22);
		printf("�ƽ����ϴ�! 2������ ����Ͽ����ϴ�.");

		gotoxy(60, 24);
		printf("�ƹ� ��ư�̳� �����ּ���_");
	}

	else if (k == 51 && suntek == '3')
	{
		dewhachang_clear();

		gotoxy(4, 20);
		printf("[�渶�� ����]");

		gotoxy(4, 22);
		printf("�����մϴ�! 3������ ����Ͽ����ϴ�!");

		gotoxy(60, 24);
		printf("�ƹ� ��ư�̳� �����ּ���_");
	}

	else if (k == 51)
	{
		dewhachang_clear();

		gotoxy(4, 20);
		printf("[�渶�� ����]");

		gotoxy(4, 22);
		printf("�ƽ����ϴ�! 3������ ����Ͽ����ϴ�.");

		gotoxy(60, 24);
		printf("�ƹ� ��ư�̳� �����ּ���_");
	}

	else if (l == 51 && suntek == '4')
	{
		dewhachang_clear();

		gotoxy(4, 20);
		printf("[�渶�� ����]");

		gotoxy(4, 22);
		printf("�����մϴ�! 4������ ����Ͽ����ϴ�!");

		gotoxy(60, 24);
		printf("�ƹ� ��ư�̳� �����ּ���_");
	}

	else if (l == 51)
	{
		dewhachang_clear();

		gotoxy(4, 20);
		printf("[�渶�� ����]");

		gotoxy(4, 22);
		printf("�ƽ����ϴ�! 4������ ����Ͽ����ϴ�.");

		gotoxy(60, 24);
		printf("�ƹ� ��ư�̳� �����ּ���_");
	}

	button = _getch();
}

void horse_realmode()
{
	char suntek;
	int	random, r, betting;
	int i = 0, j = 0, k = 0, l = 0;

	dewhachang_clear();

	gotoxy(4, 20);
	printf("[�渶�� ����]");

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
		printf("[���� ����]");

		gotoxy(4, 22);
		printf("���� �����Ѱ� ���׿�..");

		gotoxy(70, 24);
		printf("�ƹ� ��ư�̳� �����ּ���_");

		button = _getch();
		horse_yes();
	}

	else
	{

		gotoxy(73, 8);
		printf("������ : %11.f", money);

		dewhachang_clear();

		gotoxy(4, 20);
		printf("[�渶�� ����]");

		gotoxy(4, 22);
		printf("�׸����� �� �� ����� �Ѹ����� ������ ������ �ּ���.");

		gotoxy(60, 24);
		printf("������ �ּ���_");

		suntek = _getch();

		while (i <= 50 && j <= 50 && k <= 50 && l <= 50)
		{
			srand((unsigned)time(NULL) + rand());
			random = rand() % 4 + 1;

			switch (random)
			{
			case 1:
				i++;
				r = 1;
				draw_horse(i, r);
				break;

			case 2:
				j++;
				r = 5;
				draw_horse(j, r);
				break;

			case 3:
				k++;
				r = 9;
				draw_horse(k, r);
				break;

			case 4:
				l++;
				r = 13;
				draw_horse(l, r);
				break;

			default:
				break;
			}
		}

		if (i == 51 && suntek == '1')
		{
			dewhachang_clear();

			gotoxy(4, 20);
			printf("[�渶�� ����]");

			gotoxy(4, 22);
			printf("�����մϴ�! 1������ ����Ͽ����ϴ�! (���ñݾ� 2�� ����)");

			gotoxy(60, 24);
			printf("�ƹ� ��ư�̳� �����ּ���_");

			betting *= 2;
		}

		else if (i == 51)
		{
			dewhachang_clear();

			gotoxy(4, 20);
			printf("[�渶�� ����]");

			gotoxy(4, 22);
			printf("�ƽ����ϴ�! 1������ ����Ͽ����ϴ�.(���ñݾ� �Ҹ�)");

			gotoxy(60, 24);
			printf("�ƹ� ��ư�̳� �����ּ���_");
		}

		else if (j == 51 && suntek == '2')
		{
			dewhachang_clear();

			gotoxy(4, 20);
			printf("[�渶�� ����]");

			gotoxy(4, 22);
			printf("�����մϴ�! 2������ ����Ͽ����ϴ�!(���ñݾ� 2�� ����)");

			gotoxy(60, 24);
			printf("�ƹ� ��ư�̳� �����ּ���_");

			betting *= 2;
		}

		else if (j == 51)
		{
			dewhachang_clear();

			gotoxy(4, 20);
			printf("[�渶�� ����]");

			gotoxy(4, 22);
			printf("�ƽ����ϴ�! 2������ ����Ͽ����ϴ�.(���ñݾ� �Ҹ�)");

			gotoxy(60, 24);
			printf("�ƹ� ��ư�̳� �����ּ���_");
		}

		else if (k == 51 && suntek == '3')
		{
			dewhachang_clear();

			gotoxy(4, 20);
			printf("[�渶�� ����]");

			gotoxy(4, 22);
			printf("�����մϴ�! 3������ ����Ͽ����ϴ�!(���ñݾ� 2�� ����)");

			gotoxy(60, 24);
			printf("�ƹ� ��ư�̳� �����ּ���_");

			betting *= 2;
		}

		else if (k == 51)
		{
			dewhachang_clear();

			gotoxy(4, 20);
			printf("[�渶�� ����]");

			gotoxy(4, 22);
			printf("�ƽ����ϴ�! 3������ ����Ͽ����ϴ�.(���ñݾ� �Ҹ�)");

			gotoxy(60, 24);
			printf("�ƹ� ��ư�̳� �����ּ���_");
		}

		else if (l == 51 && suntek == '4')
		{
			dewhachang_clear();

			gotoxy(4, 20);
			printf("[�渶�� ����]");

			gotoxy(4, 22);
			printf("�����մϴ�! 4������ ����Ͽ����ϴ�!(���ñݾ� 2�� ����)");

			gotoxy(60, 24);
			printf("�ƹ� ��ư�̳� �����ּ���_");

			betting *= 2;
		}

		else if (l == 51)
		{
			dewhachang_clear();

			gotoxy(4, 20);
			printf("[�渶�� ����]");

			gotoxy(4, 22);
			printf("�ƽ����ϴ�! 4������ ����Ͽ����ϴ�.(���ñݾ� �Ҹ�)");

			gotoxy(60, 24);
			printf("�ƹ� ��ư�̳� �����ּ���_");
		}

		money += betting;
		button = _getch();
	}
}

void horse_rule()
{
	mainwhameon_clear();

	gotoxy(3, 1);
	printf("<< HORSE RACING >>");

	gotoxy(3, 2);
	printf(" �渶�� ���� ������ ������ ���ÿ� ��߽�Ű��,  ");

	gotoxy(3, 3);
	printf(" Ư�� �Ÿ��� �޸� �� ��¼��� ����ϵ��� ���ָ� ���Ѽ� ");

	gotoxy(3, 4);
	printf(" ���� ���� ������ ������ �ܷ�� �������Դϴ�.");

	gotoxy(3, 6);
	printf("- ���� ���");

	gotoxy(3, 7);
	printf(" 1. ���� ���� ���� ��带 �����մϴ�.");

	gotoxy(3, 8);
	printf(" 2. ���� ����� ���� �ݾ��� �Է��մϴ�.");

	gotoxy(3, 9);
	printf(" 3. 1,2,3,4���� �߿��� ����� ���̶�� ����Ǵ� ���� �����մϴ�.");

	gotoxy(3, 10);
	printf(" 4. ���ָ� �����մϴ�.");

	gotoxy(3, 11);
	printf(" 5-1. ���� ������ ���� ����ߴٸ� ���ñݾ��� �ι踦 �����ް�,");

	gotoxy(3, 12);
	printf(" 5-2. ������� ���ߴٸ� ���ñ��� �ҽ��ϴ�.");

	dewhachang_clear();

	gotoxy(4, 20);
	printf("[�渶�� ����]");

	gotoxy(4, 22);
	printf("������ �����帮�ڽ��ϴ�.");

	gotoxy(70, 24);
	printf("�ƹ� ��ư�̳� �����ּ���_");

	button = _getch();
}

void draw_horse(int i, int r)
{
	gotoxy(4 + i, 1 + r);
	printf("    _____,,;;`");

	gotoxy(4 + i, 2 + r);
	printf(" ,~(  )  )~\\|");

	gotoxy(4 + i, 3 + r);
	printf("   /     |   ");

	Sleep(30);
}