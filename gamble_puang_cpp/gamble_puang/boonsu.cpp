#include "gamble_puang.h"

int boonsu() //�м� �̺�Ʈ
{
	srand(rand());

	int hwakrull = rand() % 100 + 1;

	if (hwakrull > 98) //2%Ȯ���� 500�� �ݱ�
	{
		dewhachang_clear();

		textcolor(9);
		gotoxy(4, 20);
		printf("[Ǫ����]");
		textcolor(15);

		gotoxy(4, 22);
		printf("�м����� 500���� �߰��ߴ�!");

		money += 500;

		gotoxy(73, 8);
		printf("������ : %11.f", money);
	}

	else if (hwakrull > 80) //18%Ȯ���� 100�� �ݱ�
	{
		dewhachang_clear();

		textcolor(9);
		gotoxy(4, 20);
		printf("[Ǫ����]");
		textcolor(15);

		gotoxy(4, 22);
		printf("�м����� 100���� �߰��ߴ�!");

		money += 100;

		gotoxy(73, 8);
		printf("������ : %11.f", money);
	}

	else //80%Ȯ���� �ƹ��͵� ���ݱ�
	{
		dewhachang_clear();

		textcolor(9);
		gotoxy(4, 20);
		printf("[Ǫ����]");
		textcolor(15);

		gotoxy(4, 22);
		printf("�м��� ������ ������ ����..");
	}

	Sleep(600);

	return P_none;
}