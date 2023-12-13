#include "gamble_puang.h"
#include "GP_variables.h"

int main()
{
	do
	{
		switch (game_state)
		{
		case G_title: //게임 타이틀 화면 출력
            game_state = title();
			break;

		case G_opening: //오프닝 스토리 출력 및 게임 시작
			game_state = opening();
			break;

		case G_rule: //게임 설명 출력
			game_state = rule();
			break;

		case G_credit: //게임 크레딧 출력
			game_state = credit();
			break;

		case G_playing: //게임 시작 및 스토리 출력
			game_state = playing();
			break;
		}
	} while (game_state != G_quit);

	return game_state;
}