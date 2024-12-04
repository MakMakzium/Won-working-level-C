#include <stdio.h>
#include <stdbool.h>
#include <Windows.h>

#define DINO_BOTTOM_Y 17 //������ Y ��ġ
#define CACTUS_BOTTOM_X 45 //������ X ��ġ
#define CACTUS_BOTTOM_Y 25 //������ Y��ġ

void CursorView(char show);
void SetColor(unsigned short text);
void SetConsoleView();
void DrawDino(int dinoY);
void GotoXY(int x, int y);
void DrawCactus(int cactusX);



enum {
	BLACK,	//0
	DARK_BLUE,	//1
	DARK_GREEN,	//2
	DARK_SKYBLUE,	//3
	DARK_RED,	//4
	DARK_VOILET, //5
	DARK_YELLOW, //6
	GRAY,//7
	DARK_GRAY,	//8
	BLUE,//9
	GREEN,//10
	SKYBLUE,//11
	RED,//12
	VIOLET,//13
	YELLOW,//14
	WHITE,//15

};


int main() {//����!!!!!!!
	SetConsoleView();
	while (true)
	{
		int dinoY = DINO_BOTTOM_Y;
		int cactusX = CACTUS_BOTTOM_X;
		while (true) { //���� ���ǿ� ���� ����
			//�������� �������� (x����) ������ �ϰ�
			//�������� ��ġ�� ���� �����ΰ��� �ٽ� ������ ������ ��ȯ
			cactusX -= 2;
			if (cactusX <= 0) cactusX = CACTUS_BOTTOM_X;
		
		DrawDino(dinoY);//���� �׸���
		DrawCactus(cactusX);//������ �׸���

		Sleep(60);//Game speed
		system("cls");//clear
		}
	}
	
}
void SetColor(unsigned short text) {//�ܼ� �ؽ�Ʈ ���� �������ִ� �Լ�
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), text);

}
void CursorView(char show) {//Ŀ�� on/off
	CONSOLE_CURSOR_INFO ConsoleCursor;
	ConsoleCursor.bVisible = show;//Ŀ���� ������ ���� (0:�Ⱥ��� 0 �̿�:����)
	ConsoleCursor.dwSize = 1; //Ŀ���� ũ�⸦ ���� (1~100���̸� ����)
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &ConsoleCursor);
}


//�ܼ� â�� ũ��� ������ �����ϴ� �Լ�
void SetConsoleView() {
	//Consoleâ�� ���ο� ���� ũ�⸦ ����
	system("mode con:cols=120 lines=30");
	//Consoleâ�� ����â ǥ��
	system("title â�ǚ乫������Ʈ ���� ���� ���� [Production By. TaeSeung Chu] [Present By.YongWon Kim]");
	//Ŀ�� �Ⱥ��̰�
	CursorView(false);

}

void DrawDino(int dinoY){
	SetColor(GRAY);
	GotoXY(0,dinoY);

	static int legFlag = true; //�����̴� ����!!


	printf("        $$$$$$$ \n");		// 8, 7, 1
	printf("       $$ $$$$$$\n");		// 7, 2, 1, 6
	printf("       $$$$$$$$$\n");		// 7, 9
	printf("$      $$$      \n");		// 1, 6, 3, 6
	printf("$$     $$$$$$$  \n");		// 2, 5, 7, 2
	printf("$$$   $$$$$     \n");		// 3, 3, 5, 5
	printf(" $$  $$$$$$$$$$ \n");		// 1, 2, 2, 10, 1
	printf(" $$");									// 1, 2
	SetColor(RED);
	printf("������");
	SetColor(GRAY);
	printf("$$$    \n");						// 3, 4
	printf("  $$$");								// 2, 3
	SetColor(GREEN);
	printf("�ļҰ�");
	SetColor(GRAY);
	printf("$    \n");							// 1, 4
	printf("    $$$$$$$$    \n");		// 4, 8, 4
	printf("     $$$$$$     \n");		// 5, 6, 5
	printf("     $    $$$   \n");		// 5, 1, 4, 3, 3
	printf("     $$         ");			// 5, 2, 9

	if (legFlag) {
		printf("     $    $$$   \n");
		printf("     $$         ");
		legFlag = false;
	}
	else
	{
		printf("     $$$  $     \n");
		printf("          $$    ");
		legFlag = true;
	}

}

void DrawCactus(int cactusX) {//�������� �׸��� �Լ�
	SetColor(GREEN);
	GotoXY(cactusX, CACTUS_BOTTOM_Y);
	printf("   $");
	GotoXY(cactusX, CACTUS_BOTTOM_Y+1);
	printf("$ $  ");
	GotoXY(cactusX, CACTUS_BOTTOM_Y+2);
	printf("$ $ $");
	GotoXY(cactusX, CACTUS_BOTTOM_Y+3);
	printf("$$$$$");
	GotoXY(cactusX, CACTUS_BOTTOM_Y+4);
	printf("  $  ");
}

void GotoXY(int x, int y) {//Ŀ���� ��ġ�� x, y�� �̵��ϴ� �Լ�
	COORD Pos;
	Pos.X = 2 * x;
	Pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}
