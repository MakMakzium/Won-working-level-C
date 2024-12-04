#include "Blocks.h"
#include "Controller.h"
#include "Screen.h"
#include "ConsoleCursor.h"

void main() {
	CursurView(false);
	system("mode con cols=76 lines=28 | title 창의실무프로젝트_테트리스_실습");
	/*
	아래의 PlaySound 메서드는 .wav 음악 파일을 재생시켜주는 함수입니다.
	Controller.h 헤더파일에 include한 mmsystem.h 헤더파일을 통해 .wav음악을 출력시키는데,
	음악을 출력할 경우 해당 경로를 Controller.h에 BGM의 경로를 문자열로 지정하면 됩니다.
	그 후 아래 PlaySound 주석 해제.
	
	*/
}