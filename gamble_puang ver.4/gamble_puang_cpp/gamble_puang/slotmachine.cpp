#include "gamble_puang.h"

void slot_yes();
void slot_rule();
void slot_yeonsoopmode();
void slot_realmode();
void slotslot(int a);

int slotmachine()
{
play:
	mainwhameon_clear();

	gotoxy(8, 4);
	printf("������������������������������������������������7��7��7������������������������������������������������");
	gotoxy(8, 5);
	printf("��                                                   ��");
	gotoxy(8, 9);
	printf("��                                                   ��");
	gotoxy(8, 10);
	printf("����������������������������������������������������������������������������������������������������������");
	gotoxy(8, 11);
	printf("��                                                   ��");
	gotoxy(8, 12);
	printf("��                                                   ��");
	gotoxy(8, 13);
	printf("����������������������������������������������������������������������������������������������������������");

	gotoxy(12, 15);
	printf(" ������ * 1.0 / �ߡߡ� * 1.1 / ������ * 1.2 / ������ * 1.3 ");

	gotoxy(18, 17);
	printf("000 * 0.5 / �ŢŢ� * 2 / 777 * 3.0");

	gotoxy(61, 7);
	printf("������");
	gotoxy(63, 6);
	printf("��");
	gotoxy(63, 5);
	printf("��");

	textcolor(7);

	gotoxy(20, 6);
	printf("?");

	gotoxy(34, 6);
	printf("?");

	gotoxy(48, 6);
	printf("?");

	textcolor(13);

	gotoxy(20, 7);
	printf("?");

	gotoxy(34, 7);
	printf("?");

	gotoxy(48, 7);
	printf("?");

	textcolor(7);

	gotoxy(20, 8);
	printf("?");

	gotoxy(34, 8);
	printf("?");

	gotoxy(48, 8);
	printf("?");

	textcolor(15); //���� �ӽ� ���

	print_money();

	dewhachang("[���Ըӽ� ����]", "�÷��� �Ͻðڽ��ϱ�?", "[y] ��   [n] �ƴϿ� [r] ���� ��Ģ");

	button = _getch();

	switch (button)
	{
	case 'y':
	case 'Y':
		slot_yes();
		goto play;
		break;

	case 'n':
	case 'N':
		return P_none;
		break;

	case 'r':
	case 'R':
		slot_rule();
		goto play;
		break;

	default:
		dewhachang("[���Ըӽ� ����]", "�ٽ� ������ �ּ���.", " ");

		Sleep(300);
		goto play;
		break;
	}

	return P_none;
}

void slot_yes()
{
yes:
	dewhachang("[���Ըӽ� ����]", "�����Ͻǰǰ���?", "[y] ��   [n] �ƴϿ� (����)");

	switch (button = _getch())
	{
	case 'y':
	case 'Y':
		slot_yeonsoopmode();
		break;

	case 'n':
	case 'N':
		slot_realmode();
		break;

	default:
		dewhachang("[���Ըӽ� ����]", "�ٽ� ������ �ּ���.", " ");

		Sleep(300);
		goto yes;
		break;
	}
}

void slot_rule()
{
	mainwhameon_clear();

	for (int i = 1; i < 17; i++)
	{
		gotoxy(3, i);
		cout << t_slotmachine_rule[i];
	}

	dewhachang("[���Ըӽ� ����]", "������ �����帮�ڽ��ϴ�.", "�ƹ� ��ư�̳� �����ּ���_");
	button = _getch();
}

void slot_yeonsoopmode()
{
	int first_slot = 0, second_slot = 0, third_slot = 0;
	int stop = 0;

	dewhachang_clear();

	gotoxy(4, 20);
	printf("[���Ըӽ� ����]");

	gotoxy(4, 22);
	printf("���߷��� Enter�� �����ּ���.");

	gotoxy(80, 24);
	printf("[ Enter ]");

	gotoxy(20, 7); //ù��° ���� ������
	textcolor(13);
	slotslot(first_slot);

	gotoxy(20, 6);
	textcolor(7);
	if (first_slot == 6)
	{
		slotslot(0);
	}
	else
	{
		slotslot(first_slot + 1);
	}

	gotoxy(20, 7);
	textcolor(13);
	slotslot(first_slot);

	while (stop == 0)
	{
		gotoxy(20, 8);
		textcolor(7);
		slotslot(first_slot);

		if (first_slot == 6)
		{
			first_slot = 0;
		}
		else
		{
			first_slot += 1;
		}

		gotoxy(20, 7);
		textcolor(13);
		slotslot(first_slot);

		gotoxy(20, 6);
		textcolor(7);
		if (first_slot == 6)
		{
			slotslot(0);
		}
		else
		{
			slotslot(first_slot + 1);
		}

		if (_kbhit() == 1)
		{
			if (_getch() == 13)
				stop = 1;
		}

	}

	stop = 0;

	gotoxy(34, 7); //�ι�° ���� ������
	textcolor(13);
	slotslot(second_slot);

	gotoxy(34, 6);
	textcolor(7);
	if (second_slot == 6)
	{
		slotslot(0);
	}
	else
	{
		slotslot(second_slot + 1);
	}

	gotoxy(34, 7);
	textcolor(13);
	slotslot(second_slot);

	while (stop == 0)
	{
		gotoxy(34, 8);
		textcolor(7);
		slotslot(second_slot);

		if (second_slot == 6)
		{
			second_slot = 0;
		}
		else
		{
			second_slot += 1;
		}

		gotoxy(34, 7);
		textcolor(13);
		slotslot(second_slot);

		gotoxy(34, 6);
		textcolor(7);
		if (second_slot == 6)
		{
			slotslot(0);
		}
		else
		{
			slotslot(second_slot + 1);
		}

		if (_kbhit() == 1)
		{
			if (_getch() == 13)
				stop = 1;
		}

	}

	stop = 0;

	gotoxy(48, 7); //����° ���� ������
	textcolor(13);
	slotslot(third_slot);

	gotoxy(48, 6);
	textcolor(7);
	if (third_slot == 6)
	{
		slotslot(0);
	}
	else
	{
		slotslot(third_slot + 1);
	}

	gotoxy(48, 7);
	textcolor(13);
	slotslot(third_slot);

	while (stop == 0)
	{
		gotoxy(48, 8);
		textcolor(7);
		slotslot(third_slot);

		if (third_slot == 6)
		{
			third_slot = 0;
		}
		else
		{
			third_slot += 1;
		}

		gotoxy(48, 7);
		textcolor(13);
		slotslot(third_slot);

		gotoxy(48, 6);
		textcolor(7);
		if (third_slot == 6)
		{
			slotslot(0);
		}
		else
		{
			slotslot(third_slot + 1);
		}

		if (_kbhit() == 1)
		{
			if (_getch() == 13)
				stop = 1;
		}

	}

	if (first_slot == second_slot && second_slot == third_slot) //��� ���
	{
		if (first_slot == 0)
		{
			dewhachang_clear();

			gotoxy(4, 20);
			printf("[���Ըӽ� ����]");

			gotoxy(4, 22);
			printf("�������� ������ϴ�!");

			gotoxy(70, 24);
			printf("�ƹ� ��ư�̳� �����ּ���_");

			button = _getch();
		}
		else if (first_slot == 1)
		{
			dewhachang_clear();

			gotoxy(4, 20);
			printf("[���Ըӽ� ����]");

			gotoxy(4, 22);
			printf("�������� ������ϴ�!");

			gotoxy(70, 24);
			printf("�ƹ� ��ư�̳� �����ּ���_");

			button = _getch();
		}
		else if (first_slot == 2)
		{
			dewhachang_clear();

			gotoxy(4, 20);
			printf("[���Ըӽ� ����]");

			gotoxy(4, 22);
			printf("�ż����� ������ϴ�!");

			gotoxy(70, 24);
			printf("�ƹ� ��ư�̳� �����ּ���_");

			button = _getch();
		}
		else if (first_slot == 3)
		{
			dewhachang_clear();

			gotoxy(4, 20);
			printf("[���Ըӽ� ����]");

			gotoxy(4, 22);
			printf("�������� ������ϴ�!");

			gotoxy(70, 24);
			printf("�ƹ� ��ư�̳� �����ּ���_");

			button = _getch();
		}
		else if (first_slot == 4)
		{
			dewhachang_clear();

			gotoxy(4, 20);
			printf("[���Ըӽ� ����]");

			gotoxy(4, 22);
			printf("0������ ������ϴ�!");

			gotoxy(70, 24);
			printf("�ƹ� ��ư�̳� �����ּ���_");

			button = _getch();
		}
		else if (first_slot == 5)
		{
			dewhachang_clear();

			gotoxy(4, 20);
			printf("[���Ըӽ� ����]");

			gotoxy(4, 22);
			printf("�߼����� ������ϴ�!");

			gotoxy(70, 24);
			printf("�ƹ� ��ư�̳� �����ּ���_");

			button = _getch();
		}
		else if (first_slot == 6)
		{
			dewhachang_clear();

			gotoxy(4, 20);
			printf("[���Ըӽ� ����]");

			gotoxy(4, 22);
			printf("7������ ������ϴ�!");

			gotoxy(70, 24);
			printf("�ƹ� ��ư�̳� �����ּ���_");

			button = _getch();
		}
	}
	else
	{
		dewhachang_clear();

		gotoxy(4, 20);
		printf("[���Ըӽ� ����]");

		gotoxy(4, 22);
		printf("�����߽��ϴ�!");

		gotoxy(60, 24);
		printf("�ƹ� ��ư�̳� �����ּ���_");

		button = _getch();
	}
}

void slot_realmode()
{
	int first_slot = 0, second_slot = 0, third_slot = 0;
	int stop = 0;
	double betting = 0;//�󸶸� �����ұ�?

	dewhachang_clear();

	gotoxy(4, 20);
	printf("[���Ըӽ� ����]");

	gotoxy(4, 22);
	printf("�󸶸� �����Ͻðڽ��ϱ�?");

	gotoxy(60, 24);
	printf("���� �ݾ� : ");
	scanf_s("%lf", &betting);

	money -= betting;

	if (money < 0)
	{
		money += betting;

		dewhachang_clear();

		gotoxy(4, 20);
		printf("[���Ըӽ� ����]");

		gotoxy(4, 22);
		printf("���� �����Ѱ� ���׿�..");

		gotoxy(70, 24);
		printf("�ƹ� ��ư�̳� �����ּ���_");

		button = _getch();
		slot_yes();
	}

	else
	{
		gotoxy(73, 8);
		printf("������ : %11.f", money);

		dewhachang_clear();

		gotoxy(4, 20);
		printf("[���Ըӽ� ����]");

		gotoxy(4, 22);
		printf("���߷��� Enter�� �����ּ���.");

		gotoxy(80, 24);
		printf("[ Enter ]");

		gotoxy(20, 7); //ù��° ���� ������
		textcolor(13);
		slotslot(first_slot);

		gotoxy(20, 6);
		textcolor(7);
		if (first_slot == 6)
		{
			slotslot(0);
		}
		else
		{
			slotslot(first_slot + 1);
		}

		gotoxy(20, 7);
		textcolor(13);
		slotslot(first_slot);

		while (stop == 0)
		{
			gotoxy(20, 8);
			textcolor(7);
			slotslot(first_slot);

			if (first_slot == 6)
			{
				first_slot = 0;
			}
			else
			{
				first_slot += 1;
			}

			gotoxy(20, 7);
			textcolor(13);
			slotslot(first_slot);

			gotoxy(20, 6);
			textcolor(7);
			if (first_slot == 6)
			{
				slotslot(0);
			}
			else
			{
				slotslot(first_slot + 1);
			}

			if (_kbhit() == 1)
			{
				if (_getch() == 13)
					stop = 1;
			}

		}

		stop = 0;

		gotoxy(34, 7); //�ι�° ���� ������
		textcolor(13);
		slotslot(second_slot);

		gotoxy(34, 6);
		textcolor(7);
		if (second_slot == 6)
		{
			slotslot(0);
		}
		else
		{
			slotslot(second_slot + 1);
		}

		gotoxy(34, 7);
		textcolor(13);
		slotslot(second_slot);

		while (stop == 0)
		{
			gotoxy(34, 8);
			textcolor(7);
			slotslot(second_slot);

			if (second_slot == 6)
			{
				second_slot = 0;
			}
			else
			{
				second_slot += 1;
			}

			gotoxy(34, 7);
			textcolor(13);
			slotslot(second_slot);

			gotoxy(34, 6);
			textcolor(7);
			if (second_slot == 6)
			{
				slotslot(0);
			}
			else
			{
				slotslot(second_slot + 1);
			}

			if (_kbhit() == 1)
			{
				if (_getch() == 13)
					stop = 1;
			}

		}

		stop = 0;

		gotoxy(48, 7); //����° ���� ������
		textcolor(13);
		slotslot(third_slot);

		gotoxy(48, 6);
		textcolor(7);
		if (third_slot == 6)
		{
			slotslot(0);
		}
		else
		{
			slotslot(third_slot + 1);
		}

		gotoxy(48, 7);
		textcolor(13);
		slotslot(third_slot);

		while (stop == 0)
		{
			gotoxy(48, 8);
			textcolor(7);
			slotslot(third_slot);

			if (third_slot == 6)
			{
				third_slot = 0;
			}
			else
			{
				third_slot += 1;
			}

			gotoxy(48, 7);
			textcolor(13);
			slotslot(third_slot);

			gotoxy(48, 6);
			textcolor(7);
			if (third_slot == 6)
			{
				slotslot(0);
			}
			else
			{
				slotslot(third_slot + 1);
			}

			if (_kbhit() == 1)
			{
				if (_getch() == 13)
					stop = 1;
			}

		}

		if (first_slot == second_slot && second_slot == third_slot)
		{
			if (first_slot == 0)
			{
				dewhachang_clear();

				gotoxy(4, 20);
				printf("[���Ըӽ� ����]");

				gotoxy(4, 22);
				printf("�������� ������ϴ�! (���� �ݾ��� 2�� ����)");

				gotoxy(70, 24);
				printf("�ƹ� ��ư�̳� �����ּ���");

				betting *= 2;
			}
			else if (first_slot == 1)
			{
				dewhachang_clear();

				gotoxy(4, 20);
				printf("[���Ըӽ� ����]");

				gotoxy(4, 22);
				printf("�������� ������ϴ�!");

				gotoxy(70, 24);
				printf("�ƹ� ��ư�̳� �����ּ���");

				betting *= 1.8;
			}
			else if (first_slot == 2)
			{
				dewhachang_clear();

				gotoxy(4, 20);
				printf("[���Ըӽ� ����]");

				gotoxy(4, 22);
				printf("�ż����� ������ϴ�!");

				gotoxy(70, 24);
				printf("�ƹ� ��ư�̳� �����ּ���");

				betting *= 2;
			}
			else if (first_slot == 3)
			{
				dewhachang_clear();

				gotoxy(4, 20);
				printf("[���Ըӽ� ����]");

				gotoxy(4, 22);
				printf("�������� ������ϴ�!");

				gotoxy(70, 24);
				printf("�ƹ� ��ư�̳� �����ּ���");
			}
			else if (first_slot == 4)
			{
				dewhachang_clear();

				gotoxy(4, 20);
				printf("[���Ըӽ� ����]");

				gotoxy(4, 22);
				printf("0������ ������ϴ�!");

				gotoxy(70, 24);
				printf("�ƹ� ��ư�̳� �����ּ���");

				betting *= 0.5;
			}
			else if (first_slot == 5)
			{
				dewhachang_clear();

				gotoxy(4, 20);
				printf("[���Ըӽ� ����]");

				gotoxy(4, 22);
				printf("�߼����� ������ϴ�!");

				gotoxy(70, 24);
				printf("�ƹ� ��ư�̳� �����ּ���");

				betting *= 1.3;
			}
			else if (first_slot == 6)
			{
				dewhachang_clear();

				gotoxy(4, 20);
				printf("[���Ըӽ� ����]");

				gotoxy(4, 22);
				printf("7������ ������ϴ�!");

				gotoxy(70, 24);
				printf("�ƹ� ��ư�̳� �����ּ���");

				betting *= 3;
			}
		}
		else
		{
			dewhachang_clear();

			gotoxy(4, 20);
			printf("[���Ըӽ� ����]");

			gotoxy(4, 22);
			printf("�����߽��ϴ�!");

			gotoxy(60, 24);
			printf("�ƹ� ��ư�̳� �����ּ���");
		}

		money += betting;
		button = _getch();
	}
}

void slotslot(int a)
{
	switch (a)
	{
	case 0:
		printf("��");
		Sleep(100);
		break;
	case 1:
		printf("��");
		Sleep(120);
		break;
	case 2:
		printf("��");
		Sleep(50);
		break;
	case 3:
		printf("��");
		Sleep(160);
		break;
	case 4:
		printf("0");
		Sleep(200);
		break;
	case 5:
		printf("��");
		Sleep(140);
		break;
	case 6:
		printf("7");
		Sleep(20);
		break;
	default:
		break;
	}
}