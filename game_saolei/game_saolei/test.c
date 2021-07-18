#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"

void game() {
	//创建两个数组 一个存放雷的消息 一个存放排查后的信息
	//存放布置好的雷
	char mine[ROWS][COLS] = { 0 };//9*9的棋盘 创建成11*11 避免越界访问
	//存放排查出来的雷的信息
	char show[ROWS][COLS] = { 0 };
	InitBoard(mine, ROWS, COLS,'0');//初始化棋盘
	InitBoard(show, ROWS, COLS,'*');//初始化棋盘
	DisplayBoard(show,ROW,COL);
	//1、布置雷
	SetMine(mine,ROW,COL);
	DisplayBoard(mine, ROW, COL);
	//2、扫雷
	FindMine(mine,show, ROW, COL);
}

void menu() {
	printf("##########################\n");
	printf("######### 1、play ########\n");
	printf("######### 0、exit ########\n");
	printf("##########################\n");
}

int main() {
	
	int input = 0;
	srand((unsigned int)time(NULL));//设置随机数的生成起点
	do
	{
		menu();
		printf("请选择：");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();//扫雷游戏
			break;
		case 0:
			printf("退出游戏");
			break;
		default:
			printf("选择错误，重新选择");
			break;
		}
	} while (input);

	return 0;
}
