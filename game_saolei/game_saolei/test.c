#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"

void game() {
	//������������ һ������׵���Ϣ һ������Ų�����Ϣ
	//��Ų��úõ���
	char mine[ROWS][COLS] = { 0 };//9*9������ ������11*11 ����Խ�����
	//����Ų�������׵���Ϣ
	char show[ROWS][COLS] = { 0 };
	InitBoard(mine, ROWS, COLS,'0');//��ʼ������
	InitBoard(show, ROWS, COLS,'*');//��ʼ������
	DisplayBoard(show,ROW,COL);
	//1��������
	SetMine(mine,ROW,COL);
	DisplayBoard(mine, ROW, COL);
	//2��ɨ��
	FindMine(mine,show, ROW, COL);
}

void menu() {
	printf("##########################\n");
	printf("######### 1��play ########\n");
	printf("######### 0��exit ########\n");
	printf("##########################\n");
}

int main() {
	
	int input = 0;
	srand((unsigned int)time(NULL));//������������������
	do
	{
		menu();
		printf("��ѡ��");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();//ɨ����Ϸ
			break;
		case 0:
			printf("�˳���Ϸ");
			break;
		default:
			printf("ѡ���������ѡ��");
			break;
		}
	} while (input);

	return 0;
}
