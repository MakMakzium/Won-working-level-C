#include <stdio.h>
#include <Windows.h>
#include <conio.h>

#define Left 75
#define Right 77
#define UP 72
#define DOWN 80
#define ARROW 224

void GotoXY(int x, int y) {
	COORD Pos;
	Pos.X = x;
	Pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

void CursorView(char show) {
	CONSOLE_CURSOR_INFO ConsoleCursor;
	ConsoleCursor.bVisible = show;
	ConsoleCursor.dwSize = 1;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &ConsoleCursor);
}

void setcolor(unsigned short text, unsigned shord back) {
	SetConsoleTextAttribute(GetstdHandle(STD_OUTPUT_HANDLE), &)
}