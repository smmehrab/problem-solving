/*
************************************************
username    :   smmehrab
fullname    :   s.m.mehrabul islam
email       :   mehrab.24csedu.001@gmail.com
institute   :   university of dhaka, bangladesh
session     :   2017-2018
************************************************
*/
# include "iGraphics.h"
#include "01-40.h"

void iDraw()
{
	iClear();

	//Showing Main Menu
	if (menu == mainMenu)
		showMainMenu(selectPos);

	//Showing How To Play Infos
	else if (menu == inHowToPlay)
		showHowToPlay(selectPos);

	//Showing Info Menu
	if (menu == info)
		showInfoMenu(selectPos);

	//Showing The Game
	else if (menu == playOn) {
		showTheMatch();
	}

	else if (menu == gameOver) {
		showGameOver();
	}


	//sprintf_s(s, "%d:%d", x, y);
	//iSetColor(0, 0, 0);
	//iText(0, 10, s, GLUT_BITMAP_TIMES_ROMAN_24);
}

void iMouseMove(int mx, int my)
{

}

void iMouse(int button, int state, int mx, int my)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN){
		clickL.x = mx;
		clickL.y = my;
		leftClick(clickL);
	}

	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		refreshValid();
		clickR.x = mx;
		clickR.y = my;
	}
}

void iKeyboard(unsigned char key)
{
	//Taking Players' Info
	if (menu == info)
		takePlayersInfo(key, &selectPos);

	//Handling ESC press
	if (key == esc)
		escFunction(&menu, &selectPos);

	//Handling ENT press
	else if (key == enter)
		enterFunction(&menu, &selectPos);
}

void iSpecialKeyboard(unsigned char key)
{
	// Main Menu Moving
	if (menu == mainMenu) {
		if (key == GLUT_KEY_DOWN && selectPos < 3) {
			selectPos++;
			PlaySound("Media//Menu Move.wav",0,0);
		}

		else if (key == GLUT_KEY_UP && selectPos > 0) {
			selectPos--;
			PlaySound("Media//Menu Move.wav", 0, 0);
		}
	}

	//Info Menu Moving
	else if (menu == info) {
		if (key == GLUT_KEY_DOWN && selectPos == 0) {
			selectPos++;
			PlaySound("Media//Menu Move.wav", 0, 0);
		}
		else if (key == GLUT_KEY_UP && selectPos == 1) {
			selectPos--;
			PlaySound("Media//Menu Move.wav", 0, 0);
		}
	}

	//How To Play Scrolling
	else if (menu == inHowToPlay) {
		if (key == GLUT_KEY_DOWN && selectPos<16) selectPos++;
		else if (key == GLUT_KEY_UP && selectPos>0) selectPos--;
	}
}

void player1Timer()
{
	if (player1.clock) {
		if (player1.secs == 0) {
			player1.mins--;
			player1.secs = 59;
		}
		else player1.secs--;
	}
}

void player2Timer()
{
	if (player2.clock) {
		if (player2.secs == 0) {
			player2.mins--;
			player2.secs = 59;
		}
		else player2.secs--;
	}
}

int main()
{
	iSetTimer(1000, player1Timer);
	iSetTimer(1000, player2Timer);
	loadAllThePieces();
	iInitialize(840, 630, "Chess.com");
	return 0;
}
