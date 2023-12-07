#pragma once

//include
#include <iostream>
using namespace std;

#include <windows.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

//define
#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77 //방향키

enum Color //색깔
{
	black, blue, green, aqua, red, purple, yellow, white, gray, L_blue, L_green, L_aqua, L_red, L_purple, L_yellow, L_white
};

enum G_state //게임 상태
{
	G_quit, G_title, G_opening, G_rule, G_credit, G_playing
};

enum P_state //미니게임 실행
{
	P_none, P_blackjack, P_poker, P_slotmachine, P_holzzak, P_horse, P_boonsu, P_mart
};

//extern variables
extern double money; //소지금
extern double bit; //빚

extern int once; //게임에 한번만 입장할 수 있도록 하는 변수
extern int X , Y; //푸앙이의 위치
extern bool chack_go; //움직여도 되는지 확인

extern int game_state;
extern int playing_state;
extern char title_choice;

extern char button;

extern int casino_map[][200];
extern int blank_screen[][200];

extern string t_gamble[5];
extern string t_PUANG[6];
extern string t_title_choice[3];
extern string t_rule[6];
extern string t_credit[8];
extern string t_opning_story[15];
extern string t_BJ_rule[16];

//function prototype
//function.cpp
void CursorView();
void textcolor(int color_number);
void gotoxy(int x, int y);
bool keeper(int map[][200], int X, int Y);

void makemap(int map[][200]);
void draw_interface(int blank[][200]);
void return_title();
void move(int map[][200]);
int eventplay();

void draw_puang();
void print_money();

void mainwhameon_clear();
void dewhachang_clear();
void dewhachang(string name, string ment, string button);
void card(int muni, int sutza, int who, int num);

void giboon_dewhachang();
void ifzero();

//game_state.cpp
int title();
int opening();
int rule();
int credit();
int playing();

//Playing
int blackjack();
int poker();
int slotmachine();
int holzzak();
int horse();
int boonsu();
int mart();