#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"

void InitBoard(char board[ROWS][COLS], int rows, int cols,char set) {
	int i = 0;
	int j = 0;
	for ( i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++) {
			board[i][j] = set;
		}
	}
}

void DisplayBoard(char board[ROWS][COLS], int row, int col) {
	int i = 0;
	int j = 0;
	printf("-------------------------\n");
	//列号的打印
	for (i = 0; i <= col; i++) {
		printf("%d ", i);
	}
	printf("\n");
	
	for ( i = 1; i <= row; i++)
	{
		//行号的打印
		printf("%d ", i);
		for (j = 1; j <= col; j++) {
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
	printf("-------------------------\n");
}

void SetMine(char board[ROWS][COLS], int row, int col) {
	//随机找坐标布置雷
	//布置多少雷
	int count = EASY_COUNT;
	while (count)
	{
		//布置成功一个雷 count--
		//生成随机坐标
		int x = rand()%row+1;//1-9的数字
		int y = rand()%col+1;//1-9的数字
		//布置雷 
		//没布置过才布置
		if (board[x][y] == '0') {
			board[x][y] = '1';
			count--;
		}
	}
}

int GetMineCount(char mine[ROWS][COLS], int x, int y) {
	//周围字符相加 即是雷的个数
	return mine[x - 1][y] + 
	mine[x - 1][y - 1] + 
	mine[x][y - 1] + 
	mine[x + 1][y - 1] + 
	mine[x + 1][y] + 
	mine[x + 1][y + 1] + 
	mine[x][y + 1] + 
	mine[x - 1][y + 1]-8*'0';
}

void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col) {
	int x = 0;
	int y = 0;
	int win = 0;
	//游戏结束条件
	//1、被炸死
	//2、排除了所有不是雷的位置
	while (win<ROW*COL-EASY_COUNT) {
		printf("请输入要排查的坐标：");
		scanf("%d%d", &x, &y);
		//判断坐标是否合法
		if (x >= 1 && x <= row && y >= 1 && y <= col) {
			//判断坐标处是否有雷
			if (mine[x][y] == '1') {
				printf("你被炸死了\n");
				DisplayBoard(mine, row, col);
				break;
			}
			else {
				//不是雷 则统计周围有几个雷
				int count = GetMineCount(mine,x,y);
				show[x][y] = count + '0';
				DisplayBoard(show, row, col);
				win++;
			}
		}
		else
		{
			printf("坐标非法，请重新输入\n");
		}
	}
	if (win == ROW * COL - EASY_COUNT) {
		printf("排雷成功！\n");
	}
}