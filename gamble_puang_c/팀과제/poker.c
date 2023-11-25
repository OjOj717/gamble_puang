#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>

extern double money;
extern int mmove;

int Poker_yes();
int Poker_yeounsoop_game();
int Poker_bone_game();
int Poker_rule();
int Poker_game_result(int num_score);

int poker_num = 0;

int poker()
{
	char sigakbutton;
	int banbok = 0;

	mainwhameon_clear();

	card(5, 0, 7, 8);
	card(5, 0, 7, 20);
	card(5, 0, 7, 33);
	card(5, 0, 7, 46);
	card(5, 0, 7, 59); //카드 뒷면 출력

	gotoxy(73, 8);
	printf("소지금 : %11.f", money);

	dewhachang_clear();

	gotoxy(4, 20);
	printf("[포커 딜러]");

	gotoxy(4, 22);
	printf("플레이 하시겠습니까?");

	gotoxy(60, 24);
	printf("[y] 예   [n] 아니오 [r] 게임 규칙");

	sigakbutton = getch();

	switch (sigakbutton)
	{
	case 'y':
	case 'Y':
		Poker_yes();
		break;
	case 'n':
	case 'N':
		mmove = 1;
		main();
		break;
	case 'r':
	case 'R':
		Poker_rule();
		break;
	default:
		dewhachang_clear();

		gotoxy(4, 20);
		printf("[포커 딜러]");
		gotoxy(4, 22);
		printf("다시 선택해 주세요.");
		Sleep(300);
		poker();

		break;
	}

	return 0;
}

int Poker_yes()
{
	char mode;
	poker_num += 1;
	dewhachang_clear();

	gotoxy(4, 20);
	printf("[포커 딜러]");

	gotoxy(4, 22);
	printf("연습하실건가요?");

	gotoxy(65, 24);
	printf("[y] 예   [n] 아니오 (배팅 모드)");

	mode = getch();

	switch (mode)
	{
	case 'y':
	case 'Y':
		Poker_yeounsoop_game();
		break;
	case 'n':
	case 'N':
		Poker_bone_game();
		break;
	default:
		dewhachang_clear();

		gotoxy(4, 20);
		printf("[포커 딜러]");
		gotoxy(4, 22);
		printf("다시 선택해 주세요.");
		Sleep(300);
		poker();

		break;
	}

	return 0;
}

int Poker_yeounsoop_game()
{
	srand(time(NULL));
	int cards[5] = { 0 }; //플레이어의 카드를 저장하는 어레이 / card[0] -> 딜러꺼 / card[1] -> 플레이어꺼
	int a1, a2, a3, a4, a5; //교환 선택받을 칸
	int boguan; //버블정렬 할 때 보관할 칸
	int num_score = 0, moyang_score = 0;
	//임의로 딜러와 플레이어의 카드 설정
	for (int j = 0; j <= 4; j++)
	{
		cards[j] = (rand() % 13 + 1) + (rand() % 4 + 1) * 100; //백의 자리 -> 모양 결정 / 십의 자리수 -> 숫자 결정
	}
	
	//플레이어의 초기 카드 출력
	
	card(cards[0]/100-1, cards[0]%100, 7, 8);
	card(cards[1] / 100-1, cards[1] % 100, 7, 20);
	card(cards[2] / 100-1, cards[2] % 100, 7, 33);
	card(cards[3] / 100-1, cards[3] % 100, 7, 46);
	card(cards[4] / 100-1, cards[4] % 100, 7, 59);

	//바꿀 플레이어 카드 설정
	dewhachang_clear();

	gotoxy(4, 20);
	printf("[포커 딜러]");

	gotoxy(4, 22);
	printf("바꿀 카드는 1, 그대로 둘 카드는 0을 입력해주세요.");

	gotoxy(65, 24);
	printf("ex) 1 0 0 1 1 : ");
	scanf_s("%d %d %d %d %d", &a1, &a2, &a3, &a4, &a5);

	if (a1 == 1)
		cards[0] = (rand() % 13 + 1) + (rand() % 4 + 1) * 100;
	if (a2 == 1)
		cards[1] = (rand() % 13 + 1) + (rand() % 4 + 1) * 100;
	if (a3 == 1)
		cards[2] = (rand() % 13 + 1) + (rand() % 4 + 1) * 100;
	if (a4 == 1)
		cards[3] = (rand() % 13 + 1) + (rand() % 4 + 1) * 100;
	if (a5 == 1)
		cards[4] = (rand() % 13 + 1) + (rand() % 4 + 1) * 100;

	card(cards[0] / 100-1, cards[0] % 100, 7, 8);
	card(cards[1] / 100-1, cards[1] % 100, 7, 20);
	card(cards[2] / 100-1, cards[2] % 100, 7, 33);
	card(cards[3] / 100-1, cards[3] % 100, 7, 46);
	card(cards[4] / 100-1, cards[4] % 100, 7, 59);

	
		for (int j = 0; j <= 3; j++)
		{
			for (int k = 0; k <= 3 - j; k++)
			{
				if (cards[k] % 100 > cards[k + 1] % 100)
				{
					boguan = cards[k];
					cards[k] = cards[k + 1];
					cards[k] = boguan;
				}
				else if (cards[k] % 100 == cards[k + 1] % 100)
				{
					if (cards[k] > cards[k + 1])
					{
						boguan = cards[k];
						cards[k] = cards[k + 1];
						cards[k] = boguan;
					}
					else
					{
						continue;
					}
				}
				else
				{
					continue;
				}
			}
		}
		//등급 계산 //앞에서부터 차례차례 같은게 있으면 1을 더하는 방식 (숫자, J, Q, K만 해당) (페어에 해당하는 것만 결산)
		for (int j = 0; j <= 3; j++) 
		{
			for (int k = 1; k <= 4 - j; k++)
			{
				if (cards[j] % 100 == cards[j + k] % 100)
				{
					num_score++;
				}
			}
		}
		//결과가 있으면 마지막 결과창으로
		if (num_score > 0)
		{
			goto Result;
		}
		//스트레이트 여부 판단
		for (int j = 0; j <= 3; j++)
		{
			if (cards[j] % 100 == cards[j + 1] % 100 - 1)
			{
				if (j < 3)
				{
					continue; //해당 반복문 반복
				}
				else if (j == 3)
				{
					goto Yeonsock; //연속 칸으로 이동
				}

			}
			else
			{
				goto Not_Yeonsock; // 해당하지 않음. for문 벗어나기
			}
		Yeonsock:
			if (cards[0] % 100 == 1)
			{
				for (int k = 0; k <= 3; k++)
				{
					if (cards[k] / 100 == cards[k + 1] / 100)
					{
						if (k < 3)
						{
							continue;
						}
						else if (k == 3)
						{
							num_score = num_score + 40;
						}
					}
					else
					{
						num_score = num_score + 20;
					}
				}
			}
			else
			{
				for (int k = 0; k <= 3; k++)
				{
					if (cards[k] / 100 == cards[k + 1] / 100)
					{
						if (k < 3)
						{
							continue;
						}
						else if (k == 3)
						{
							num_score = num_score + 30;
						}
					}
					else
					{
						num_score = num_score + 10;
					}
				}
			}
		}
	Not_Yeonsock:
		//결과가 있으면 마지막 결과창으로
		if (num_score > 0)
		{
			goto Result;
		}
		//마운틴 or 로열스트레이트플레시 여부 판단
		for (int j = 0; j <= 3; j++)
		{
			if (j == 0)
			{
				if (cards[j] % 100 == cards[j + 1] % 100 - 9)
				{
					continue;
				}
				else
				{
					goto Not_Mountain;
				}
			}
			else if (j > 0 && j < 3)
			{
				if (cards[j] % 100 == cards[j + 1] % 100 - 1)
				{
					continue;
				}
				else
				{
					goto Not_Mountain;
				}
			}
			else if (j == 3)
			{
				if (cards[j] % 100 == cards[j + 1] % 100 - 1)
				{
					goto Mountain;
				}
				else
				{
					goto Not_Mountain;
				}
			}
		Mountain:
			for (int k = 0; k <= 3; k++)
			{
				if (cards[k] / 100 == cards[k + 1] / 100)
				{
					if (k < 3)
					{
						continue;
					}
					else if (k == 3)
					{
						num_score = num_score + 60;
					}
				}
				else
				{
					num_score = num_score + 50;
				}
			}
		}
	Not_Mountain:
		//결과가 있으면 마지막 결과창으로
		if (num_score > 0)
		{
			goto Result;
		}
		//플러쉬 여부 판단
		for (int j = 0; j <= 3; j++)
		{
			if (cards[j] / 100 == cards[j + 1] / 100)
			{
				if (j < 3)
				{
					continue;
				}
				else if (j == 3)
				{
					num_score = num_score + 70;
				}
			}
			else
			{
				goto Not_Flush;
			}
		}
	Not_Flush:
		if (num_score > 0)
		{
			goto Result;
		}
		Result:
		dewhachang_clear();

		gotoxy(4, 20);
		printf("[포커 딜러]");

		gotoxy(4, 22);
		Poker_game_result(num_score);

		gotoxy(70, 24);
		printf("아무 버튼이나 눌러주세요");

		getch();
		poker();
	
}
//본 게임 / 본 게임에 배팅 기능은 들어가 있지 않습니다.
int Poker_bone_game()
{
	srand(time(NULL));
	int cards[5] = { 0 }; //플레이어의 카드를 저장하는 어레이 / card[0] -> 딜러꺼 / card[1] -> 플레이어꺼
	int a1, a2, a3, a4, a5; //교환 선택받을 칸
	int boguan; //버블정렬 할 때 보관할 칸
	int num_score = 0, moyang_score = 0;
	//임의로 딜러와 플레이어의 카드 설정
	int betting = 0;//얼마를 배팅할까?

	dewhachang_clear();

	gotoxy(4, 20);
	printf("[포커 딜러]");

	gotoxy(4, 22);
	printf("얼마를 배팅하시겠습니까?");

	gotoxy(60, 24);
	printf("배팅 금액 : ");
	scanf_s("%d", &betting);

	money -= betting;

	if (money < 0)
	{
		money += betting;

		dewhachang_clear();

		gotoxy(4, 20);
		printf("[포커 딜러]");

		gotoxy(4, 22);
		printf("돈이 부족한것 같네요..");

		gotoxy(70, 24);
		printf("아무 버튼이나 눌러주세요_");

		getch();
		Poker_yes();
	}

	else
	{
		gotoxy(73, 8);
		printf("소지금 : %11.f", money);

		for (int j = 0; j <= 4; j++)
		{
			cards[j] = (rand() % 13 + 1) + (rand() % 4 + 1) * 100; //백의 자리 -> 모양 결정 / 십의 자리수 -> 숫자 결정
		}

		//플레이어의 초기 카드 출력

		card(cards[0] / 100 - 1, cards[0] % 100, 7, 8);
		card(cards[1] / 100 - 1, cards[1] % 100, 7, 20);
		card(cards[2] / 100 - 1, cards[2] % 100, 7, 33);
		card(cards[3] / 100 - 1, cards[3] % 100, 7, 46);
		card(cards[4] / 100 - 1, cards[4] % 100, 7, 59);

		//바꿀 플레이어 카드 설정
		dewhachang_clear();

		gotoxy(4, 20);
		printf("[포커 딜러]");

		gotoxy(4, 22);
		printf("바꿀 카드는 1, 그대로 둘 카드는 0을 입력해주세요.");

		gotoxy(65, 24);
		printf("ex) 1 0 0 1 1 : ");
		scanf_s("%d %d %d %d %d", &a1, &a2, &a3, &a4, &a5);

		if (a1 == 1)
			cards[0] = (rand() % 13 + 1) + (rand() % 4 + 1) * 100;
		if (a2 == 1)
			cards[1] = (rand() % 13 + 1) + (rand() % 4 + 1) * 100;
		if (a3 == 1)
			cards[2] = (rand() % 13 + 1) + (rand() % 4 + 1) * 100;
		if (a4 == 1)
			cards[3] = (rand() % 13 + 1) + (rand() % 4 + 1) * 100;
		if (a5 == 1)
			cards[4] = (rand() % 13 + 1) + (rand() % 4 + 1) * 100;

		card(cards[0] / 100 - 1, cards[0] % 100, 7, 8);
		card(cards[1] / 100 - 1, cards[1] % 100, 7, 20);
		card(cards[2] / 100 - 1, cards[2] % 100, 7, 33);
		card(cards[3] / 100 - 1, cards[3] % 100, 7, 46);
		card(cards[4] / 100 - 1, cards[4] % 100, 7, 59);


		for (int j = 0; j <= 3; j++)
		{
			for (int k = 0; k <= 3 - j; k++)
			{
				if (cards[k] % 100 > cards[k + 1] % 100)
				{
					boguan = cards[k];
					cards[k] = cards[k + 1];
					cards[k] = boguan;
				}
				else if (cards[k] % 100 == cards[k + 1] % 100)
				{
					if (cards[k] > cards[k + 1])
					{
						boguan = cards[k];
						cards[k] = cards[k + 1];
						cards[k] = boguan;
					}
					else
					{
						continue;
					}
				}
				else
				{
					continue;
				}
			}
		}
		//등급 계산 //앞에서부터 차례차례 같은게 있으면 1을 더하는 방식 (숫자, J, Q, K만 해당) (페어에 해당하는 것만 결산)
		for (int j = 0; j <= 3; j++)
		{
			for (int k = 1; k <= 4 - j; k++)
			{
				if (cards[j] % 100 == cards[j + k] % 100)
				{
					num_score++;
				}
			}
		}
		//결과가 있으면 마지막 결과창으로
		if (num_score > 0)
		{
			goto Result;
		}
		//스트레이트 여부 판단
		for (int j = 0; j <= 3; j++)
		{
			if (cards[j] % 100 == cards[j + 1] % 100 - 1)
			{
				if (j < 3)
				{
					continue; //해당 반복문 반복
				}
				else if (j == 3)
				{
					goto Yeonsock; //연속 칸으로 이동
				}

			}
			else
			{
				goto Not_Yeonsock; // 해당하지 않음. for문 벗어나기
			}
		Yeonsock:
			if (cards[0] % 100 == 1)
			{
				for (int k = 0; k <= 3; k++)
				{
					if (cards[k] / 100 == cards[k + 1] / 100)
					{
						if (k < 3)
						{
							continue;
						}
						else if (k == 3)
						{
							num_score = num_score + 40;
						}
					}
					else
					{
						num_score = num_score + 20;
					}
				}
			}
			else
			{
				for (int k = 0; k <= 3; k++)
				{
					if (cards[k] / 100 == cards[k + 1] / 100)
					{
						if (k < 3)
						{
							continue;
						}
						else if (k == 3)
						{
							num_score = num_score + 30;
						}
					}
					else
					{
						num_score = num_score + 10;
					}
				}
			}
		}
	Not_Yeonsock:
		//결과가 있으면 마지막 결과창으로
		if (num_score > 0)
		{
			goto Result;
		}
		//마운틴 or 로열스트레이트플레시 여부 판단
		for (int j = 0; j <= 3; j++)
		{
			if (j == 0)
			{
				if (cards[j] % 100 == cards[j + 1] % 100 - 9)
				{
					continue;
				}
				else
				{
					goto Not_Mountain;
				}
			}
			else if (j > 0 && j < 3)
			{
				if (cards[j] % 100 == cards[j + 1] % 100 - 1)
				{
					continue;
				}
				else
				{
					goto Not_Mountain;
				}
			}
			else if (j == 3)
			{
				if (cards[j] % 100 == cards[j + 1] % 100 - 1)
				{
					goto Mountain;
				}
				else
				{
					goto Not_Mountain;
				}
			}
		Mountain:
			for (int k = 0; k <= 3; k++)
			{
				if (cards[k] / 100 == cards[k + 1] / 100)
				{
					if (k < 3)
					{
						continue;
					}
					else if (k == 3)
					{
						num_score = num_score + 60;
					}
				}
				else
				{
					num_score = num_score + 50;
				}
			}
		}
	Not_Mountain:
		//결과가 있으면 마지막 결과창으로
		if (num_score > 0)
		{
			goto Result;
		}
		//플러쉬 여부 판단
		for (int j = 0; j <= 3; j++)
		{
			if (cards[j] / 100 == cards[j + 1] / 100)
			{
				if (j < 3)
				{
					continue;
				}
				else if (j == 3)
				{
					num_score = num_score + 70;
				}
			}
			else
			{
				goto Not_Flush;
			}
		}
	Not_Flush:
		if (num_score > 0)
		{
			goto Result;
		}
	Result:

		switch (num_score) //족보에 따른 지급금액 계산
		{
		case 0:
			betting *= 0;
			break;
		case 1:
			betting *= 1;
			break;
		case 2:
			betting *= 2;
			break;
		case 3:
			betting *= 3;
			break;
		case 10:
			betting *= 5;
			break;
		case 20:
			betting *= 8;
			break;
		case 50:
			betting *= 13;
			break;
		case 70:
			betting *= 21;
			break;
		case 4:
			betting *= 34;
			break;
		case 6:
			betting *= 55;
			break;
		case 30:
			betting *= 89;
			break;
		case 40:
			betting *= 144;
			break;
		case 60:
			betting *= 233;
			break;
		default:
			break;
		}

		money += betting;

		gotoxy(73, 8);
		printf("소지금 : %11.f", money);

		dewhachang_clear();

		gotoxy(4, 20);
		printf("[포커 딜러]");

		gotoxy(4, 22);
		Poker_game_result(num_score);

		gotoxy(70, 24);
		printf("아무 버튼이나 눌러주세요");

		getch();
		poker();
	}

	return 0;
}
//게임 결과 1 ~ 13까지 리턴
int Poker_game_result(int num_score)
{
	switch (num_score)
	{
	case 0:
		printf("노페어 입니다. (배팅 금액 0배 지급)"); return 0;
	case 1:
		printf("원페어 입니다. (배팅 금액 1배 지급)"); return 1;
	case 2:
		printf("투페어 입니다. (배팅 금액 2배 지급)"); return 2;
	case 3:
		printf("트리플 입니다. (배팅 금액 3배 지급)"); return 3;
	case 4:
		printf("풀하우스 입니다. (배팅 금액 34배 지급)"); return 8;
	case 6:
		printf("포커 입니다. (배팅 금액 55배 지급)"); return 9;
	case 10:
		printf("스트레이트 입니다. (배팅 금액 5배 지급)"); return 4;
	case 20:
		printf("백스트레이트 입니다. (배팅 금액 8배 지급)"); return 5;
	case 30:
		printf("스트레이트 플러쉬 입니다. (배팅 금액 89배 지급)"); return 10;
	case 40:
		printf("백스트레이트 플러쉬 입니다. (배팅 금액 144배 지급)"); return 11;
	case 50:
		printf("마운틴 입니다. (배팅 금액 13배 지급)"); return 6;
	case 60:
		printf("로열 스트레이트 플러쉬 입니다. (배팅 금액 233배 지급)"); return 12;
	case 70:
		printf("플러쉬 입니다. (배팅 금액 21배 지급)"); return 7;
	}
}
//게임 룰
int Poker_rule()
{
	mainwhameon_clear();

	gotoxy(3, 1);
	printf("<< POKER >>");

	gotoxy(3, 2);
	printf(" 플레잉 카드로 할 수 있는 대표적인 카드 게임 중 하나로 카드의");

	gotoxy(3, 3);
	printf(" 족보를 판단하여 승패를 결정하는 게임입니다. 우리 카지노에서는 ");

	gotoxy(3, 4);
	printf(" 싱글플레이로 진행되는 테이블 포커의 규칙을 따르고 있습니다.");

	gotoxy(3, 6);
	printf("- 게임 방법");

	gotoxy(3, 7);
	printf(" 1. 연습 모드와 배팅 모드를 선택합니다.");

	gotoxy(3, 8);
	printf(" 2. 배팅 모드라면 배팅 금액을 입력합니다.");

	gotoxy(3, 9);
	printf(" 3. 랜덤 카드 5장을 받습니다.");

	gotoxy(3, 10);
	printf(" 4. 높은 족보에 유리하도록 0과 1을 입력해 바꿀 카드를 정합니다.");

	gotoxy(3, 11);
	printf(" 5. 1로 선택한 카드만 다른 랜덤 카드로 교체한뒤 족보에 따라 ");

	gotoxy(3, 12);
	printf("    배팅 금액에 해당하는 배율을 곱한만큼 돈을 지급 받습니다.");

	dewhachang_clear();

	gotoxy(4, 20);
	printf("[포커 딜러]");

	gotoxy(4, 22);
	printf("룰지를 보여드리겠습니다. 족보를 보시려면 아무 버튼이나 눌러주세요.");

	gotoxy(70, 24);
	printf("아무 버튼이나 눌러주세요_");

	getch();

	mainwhameon_clear();

	gotoxy(3, 1);
	printf("<< POKER >>");

	gotoxy(3, 2);
	printf(" 노페어 (0배 지급) : 어느 족보에도 해당하지 않는 조합");

	gotoxy(3, 3);
	printf(" 원페어 (1배 지급) : 숫자가 같은 카드 2장");

	gotoxy(3, 4);
	printf(" 투페어 (2배 지급) : 원페어가 2개 존재");

	gotoxy(3, 5);
	printf(" 트리플 (3배 지급) : 숫자가 같은 카드 3장");

	gotoxy(3, 6);
	printf(" 스트레이트 (5배 지급) : 숫자가 이어지는 카드 5장");

	gotoxy(3, 7);
	printf(" 백스트레이트 (8배 지급) : A, 2, 3, 4, 5 다섯장으로 이루어진 조합");

	gotoxy(3, 8);
	printf(" 마운틴 (13배 지급) : A, K, Q, J, 10 다섯장으로 이루어진 조합");

	gotoxy(3, 9);
	printf(" 플러시 (21배 지급) : 무늬가 같은 카드 5장");

	gotoxy(3, 10);
	printf(" 풀하우스 (34배 지급) : 숫자가 같은 카드 3장 + 숫자가 같은 카드 2장");

	gotoxy(3, 11);
	printf(" 포커 (55배 지급) : 숫자가 같은 카드 4장");

	gotoxy(3, 12);
	printf(" 스트레이트 플러쉬 (89배 지급) :");

	gotoxy(3, 13);
	printf("                   숫자가 이어지고 무늬가 같은 카드 5장");

	gotoxy(3, 14);
	printf(" 백스트레이트 플러쉬 (144배 지급) :");

	gotoxy(3, 15);
	printf("                     무늬가 같은 A, 2, 3, 4, 5 다섯장");

	gotoxy(3, 16);
	printf(" 로열 스트레이트 플러쉬 (233배 지급) :");

	gotoxy(3, 17);
	printf("                        무늬가 같은 A, K, Q, J, 10 다섯장");

	dewhachang_clear();

	gotoxy(4, 20);
	printf("[슬롯머신 딜러]");

	gotoxy(4, 22);
	printf("룰지를 보여드리겠습니다.");

	gotoxy(70, 24);
	printf("아무 버튼이나 눌러주세요_");

	getch();
	poker();

	return 0;
}