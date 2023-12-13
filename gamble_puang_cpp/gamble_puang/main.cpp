#include "gamble_puang.h"
#include "GP_variables.h"

int main()
{
	do
	{
		switch (game_state)
		{
		case G_title: //���� Ÿ��Ʋ ȭ�� ���
            game_state = title();
			break;

		case G_opening: //������ ���丮 ��� �� ���� ����
			game_state = opening();
			break;

		case G_rule: //���� ���� ���
			game_state = rule();
			break;

		case G_credit: //���� ũ���� ���
			game_state = credit();
			break;

		case G_playing: //���� ���� �� ���丮 ���
			game_state = playing();
			break;
		}
	} while (game_state != G_quit);

	return game_state;
}