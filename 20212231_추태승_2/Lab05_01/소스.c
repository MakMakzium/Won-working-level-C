#include <stdio.h>
#include <windows.h>

void gotoxy(short x, short y) {
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}


void CursorView(char show) {
	CONSOLE_CURSOR_INFO ConsoleCussor;
	ConsoleCussor.bVisible = show;
	ConsoleCussor.dwSize = 1;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &ConsoleCussor);
}

int main(void) {
	printf("Enter입력 시 시작 :");
	getchar();
	CursorView(0);
	srand((unsigned int)time(NULL));
	while (1) {
		gotoxy((rand() % 300) / 2, rand() % 25);
		printf("*");
		Sleep(100);
	}
}