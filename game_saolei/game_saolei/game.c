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
	//�кŵĴ�ӡ
	for (i = 0; i <= col; i++) {
		printf("%d ", i);
	}
	printf("\n");
	
	for ( i = 1; i <= row; i++)
	{
		//�кŵĴ�ӡ
		printf("%d ", i);
		for (j = 1; j <= col; j++) {
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
	printf("-------------------------\n");
}

void SetMine(char board[ROWS][COLS], int row, int col) {
	//��������겼����
	//���ö�����
	int count = EASY_COUNT;
	while (count)
	{
		//���óɹ�һ���� count--
		//�����������
		int x = rand()%row+1;//1-9������
		int y = rand()%col+1;//1-9������
		//������ 
		//û���ù��Ų���
		if (board[x][y] == '0') {
			board[x][y] = '1';
			count--;
		}
	}
}

int GetMineCount(char mine[ROWS][COLS], int x, int y) {
	//��Χ�ַ���� �����׵ĸ���
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
	//��Ϸ��������
	//1����ը��
	//2���ų������в����׵�λ��
	while (win<ROW*COL-EASY_COUNT) {
		printf("������Ҫ�Ų�����꣺");
		scanf("%d%d", &x, &y);
		//�ж������Ƿ�Ϸ�
		if (x >= 1 && x <= row && y >= 1 && y <= col) {
			//�ж����괦�Ƿ�����
			if (mine[x][y] == '1') {
				printf("�㱻ը����\n");
				DisplayBoard(mine, row, col);
				break;
			}
			else {
				//������ ��ͳ����Χ�м�����
				int count = GetMineCount(mine,x,y);
				show[x][y] = count + '0';
				DisplayBoard(show, row, col);
				win++;
			}
		}
		else
		{
			printf("����Ƿ�������������\n");
		}
	}
	if (win == ROW * COL - EASY_COUNT) {
		printf("���׳ɹ���\n");
	}
}