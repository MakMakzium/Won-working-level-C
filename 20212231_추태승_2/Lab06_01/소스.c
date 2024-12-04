#include <stdio.h>
#include <stdbool.h>
#include <Windows.h>

#define DINO_BOTTOM_Y 17 //공룡의 Y 위치
#define CACTUS_BOTTOM_X 45 //선인장 X 위치
#define CACTUS_BOTTOM_Y 25 //선인장 Y위치

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


int main() {//공룡!!!!!!!
	SetConsoleView();
	while (true)
	{
		int dinoY = DINO_BOTTOM_Y;
		int cactusX = CACTUS_BOTTOM_X;
		while (true) { //게임 한판에 대한 루프
			//선인장이 왼쪽으로 (x음수) 가도록 하고
			//선인장의 위치가 왼쪽 끝으로가면 다시 오른쪽 끝으로 소환
			cactusX -= 2;
			if (cactusX <= 0) cactusX = CACTUS_BOTTOM_X;
		
		DrawDino(dinoY);//공룡 그리기
		DrawCactus(cactusX);//선인장 그리기

		Sleep(60);//Game speed
		system("cls");//clear
		}
	}
	
}
void SetColor(unsigned short text) {//콘솔 텍스트 색상 변경해주는 함수
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), text);

}
void CursorView(char show) {//커서 on/off
	CONSOLE_CURSOR_INFO ConsoleCursor;
	ConsoleCursor.bVisible = show;//커서를 보일지 말지 (0:안보임 0 이외:보임)
	ConsoleCursor.dwSize = 1; //커서의 크기를 결정 (1~100사이만 가능)
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &ConsoleCursor);
}


//콘솔 창의 크기와 제목을 지정하는 함수
void SetConsoleView() {
	//Console창의 가로와 세로 크기를 결정
	system("mode con:cols=120 lines=30");
	//Console창의 제목창 표시
	system("title 창의싦무프로젝트 구글 공룡 게임 [Production By. TaeSeung Chu] [Present By.YongWon Kim]");
	//커서 안보이게
	CursorView(false);

}

void DrawDino(int dinoY){
	SetColor(GRAY);
	GotoXY(0,dinoY);

	static int legFlag = true; //움직이는 공룡!!


	printf("        $$$$$$$ \n");		// 8, 7, 1
	printf("       $$ $$$$$$\n");		// 7, 2, 1, 6
	printf("       $$$$$$$$$\n");		// 7, 9
	printf("$      $$$      \n");		// 1, 6, 3, 6
	printf("$$     $$$$$$$  \n");		// 2, 5, 7, 2
	printf("$$$   $$$$$     \n");		// 3, 3, 5, 5
	printf(" $$  $$$$$$$$$$ \n");		// 1, 2, 2, 10, 1
	printf(" $$");									// 1, 2
	SetColor(RED);
	printf("원광대");
	SetColor(GRAY);
	printf("$$$    \n");						// 3, 4
	printf("  $$$");								// 2, 3
	SetColor(GREEN);
	printf("컴소공");
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

void DrawCactus(int cactusX) {//선인장을 그리는 함수
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

void GotoXY(int x, int y) {//커서의 위치를 x, y로 이동하는 함수
	COORD Pos;
	Pos.X = 2 * x;
	Pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}
