/*
************************************************
username    :   smmehrab
fullname    :   s.m.mehrabul islam
email       :   mehrab.24csedu.001@gmail.com
institute   :   university of dhaka, bangladesh
session     :   2017-2018
************************************************
*/
/*#include "basic.h"
#include "drawEverything.h"
#include "ttElements.h"
#include "players.h"
#include "allMenu.h"
#include "showEverything.h"
#include "takeInput.h"
#include "ttShots.h"
#include "ENT-ESC.h" */

#define initialX 0
#define initialY  0

#define space ' '
#define enter '\r'
#define esc 27
#define backspace '\b'

#define text1ColorR 0
#define text1ColorG 0
#define text1ColorB 0

#define text2ColorR 255
#define text2ColorG 255
#define text2ColorB 255

#define boardBlackR 119
#define boardBlackG 149
#define boardBlackB 86

#define boardWhiteR 235
#define boardWhiteG 236
#define boardWhiteB 208

#define redR 235
#define redG 67
#define redB 84

#define whiteR 255
#define whiteG 255
#define whiteB 255

#define blackR 0
#define blackG 0
#define blackB 0

#define boardX 50
#define boardY 80
#define boardEdge 60

#define player2TimeX 605
#define player2TimeY 262

#define player1TimeX 705
#define player1TimeY 262

//char s[100];
//int x, y,i;

char whitePieces[6][30] = {
	"Media//wK.bmp",
	"Media//wQ.bmp",
	"Media//wR.bmp",
	"Media//wKn.bmp",
	"Media//wB.bmp",
	"Media//wP.bmp"
};

char blackPieces[6][30] = {
	"Media//bK.bmp",
	"Media//bQ.bmp",
	"Media//bR.bmp",
	"Media//bKn.bmp",
	"Media//bB.bmp",
	"Media//bP.bmp"
};

enum pieces {
	king,queen,rook,knight,bishop,paun
};

int selectPos = 0;
int indexR,indexC;

char HTP[100][100] = {
	"Media//HTP-1.bmp",
	"Media//HTP-2.bmp",
	"Media//HTP-3.bmp",
	"Media//HTP-4.bmp",
	"Media//HTP-5.bmp",
	"Media//HTP-6.bmp",
	"Media//HTP-7.bmp",
	"Media//HTP-8.bmp",
	"Media//HTP-9.bmp",
	"Media//HTP-10.bmp",
	"Media//HTP-11.bmp",
	"Media//HTP-12.bmp",
	"Media//HTP-13.bmp",
	"Media//HTP-14.bmp",
	"Media//HTP-15.bmp",
	"Media//HTP-16.bmp",
	"Media//HTP-17.bmp",
};

enum Menu {
	mainMenu, playOn, inHowToPlay,
	info
}menu;

enum MainMenu {
	newMatch,
	rating,
	howToPlay,
	exitGame,
};

enum Info {
	player1Info,
	player2Info
};

struct Players {
	char mail[100],timeShow[100];
	int rating, index = 0;
	int turn;
	int secs, mins;
}player1,player2;


struct pic {
	int x, y;
	int pxl[800][500];
};

pic wK,wQ,wR,wKn,wB,wP;
pic bK,bQ,bR,bKn,bB,bP;

void myLoad(char *filename, struct pic *aa) {
	FILE *fp = fopen(filename, "r");
	int xx, yy, temp;
	fscanf(fp, "%d %d", &xx, &yy);
	aa->x = xx, aa->y = yy;
	for (int i = 0; i < xx; i++) {
		for (int j = 0; j < yy; j++) {
			if (!feof(fp)) {
				fscanf(fp, "%d", &temp);
				aa->pxl[i][j] = temp;
			}
		}
	}
	fclose(fp);
}

void myShowBMP2(int x, int y, struct pic *a, int ignr0 = -1, int ignr1 = -1, int ignr2 = -1) {
	int xx, yy;
	xx = a->x, yy = a->y;
	int arr[4], temp;
	for (int i = 0; i < xx; i++) {
		for (int j = 0; j < yy; j++) {
			temp = a->pxl[i][j];
			arr[0] = temp / 1000000;
			temp %= 1000000;
			arr[1] = temp / 1000;
			temp %= 1000;
			arr[2] = temp;
			if (arr[0] == ignr0 && arr[1] == ignr1 && arr[2] == ignr2) continue;
			iSetColor(arr[0], arr[1], arr[2]);
			iPoint(i + x, j + y);
		}
	}
}

void showMainMenu(int selectPos) {
	if (selectPos == newMatch) iShowBMP(initialX, initialY, "Media//NEW GAME.bmp");
	else if (selectPos == rating) iShowBMP(initialX, initialY, "Media//Rating.bmp");
	else if (selectPos == howToPlay) iShowBMP(initialX, initialY, "Media//How To Play.bmp");
	else if (selectPos == exitGame) iShowBMP(initialX, initialY, "Media//EXIT.bmp");
}

void showHowToPlay(int selectPos) {
		iShowBMP(initialX, initialY, HTP[selectPos]);
}

void showInfoMenu(int selectPos) {
	if (selectPos == player1Info)
		iShowBMP(initialX, initialY, "Media//Player-1 Info.bmp");

	else if (selectPos == player2Info)
		iShowBMP(initialX, initialY, "Media//Player-2 Info.bmp");

	iSetColor(text1ColorR, text1ColorG, text1ColorB);

	iText(350, 410, player1.mail, GLUT_BITMAP_TIMES_ROMAN_24);
	iText(350, 295, player2.mail, GLUT_BITMAP_TIMES_ROMAN_24);

}

//Taking Players' Info
void takePlayersInfo(char key, int *selectPos) {
	if (*selectPos == player1Info) {
		if (key != backspace && key != enter) {
			player1.mail[player1.index++] = key;
			player1.mail[player1.index] = '\0';
		}
		else if(key != enter) {
			if (player1.index <= 0)
				player1.index = 0;
			else
				player1.index--;
			player1.mail[player1.index] = '\0';
		}
	}

	else if (*selectPos == player2Info) {
		if (key != backspace && key != enter) {
			player2.mail[player2.index++] = key;
			player2.mail[player2.index] = '\0';
		}
		else if (key != enter) {
			if (player2.index <= 0)
				player2.index = 0;
			else
				player2.index--;
			player2.mail[player2.index] = '\0';
		}
	}

}

//Handling ESC Press
void escFunction(Menu *menu, int *selectPos) {
	if (*menu == playOn) {

	}

	else if (*menu == inHowToPlay) {
		*menu = mainMenu;
		*selectPos = newMatch;
	}

	else if (*selectPos == player1Info) {
		*menu = mainMenu;
	}

	else if (*selectPos == player2Info) {
		*selectPos--;
	}
}

//Handling ENT Press
void enterFunction(Menu *menu, int *selectPos) {

	if (*menu == mainMenu) {
		if (*selectPos == newMatch) {
			*menu = info;
			*selectPos = player1Info;
		}
		else if (*selectPos == howToPlay) {
			*menu = inHowToPlay;
			*selectPos = 0;
		}
		else if (*selectPos == exitGame) exit(0);
	}

	else if (*menu == info) {
		if (*selectPos == player1Info)
			*selectPos = player2Info;
		else {
			*menu = playOn;

			player1.secs = 59;
			player1.mins = 4;
			player2.secs = 59;
			player2.mins = 4;

			player1.turn = 1;
			player2.turn = 0;
		}
	}
}

//Drawing The Chess Board
void drawTheBoard() {

	//Drawing The Board Border
	iSetColor(20, 20, 20);
	iFilledRectangle(boardX - 4, boardY - 4, (boardEdge * 8) + 8, (boardEdge * 8) + 8);
	iSetColor(248,248,248);
	iFilledRectangle(boardX - 2, boardY - 2, (boardEdge*8) + 4, (boardEdge*8) + 4);


	//Drawing The Board
	for (indexR = 0; indexR < 8; indexR++) {
		for (indexC = 0; indexC < 8; indexC++) {
			if ((indexR + indexC) % 2 == 0) iSetColor(boardWhiteR, boardWhiteG, boardWhiteB);
			else iSetColor(boardBlackR, boardBlackG, boardBlackB);
			iFilledRectangle(boardX+(boardEdge*indexC), boardY+(boardEdge*indexR), boardEdge, boardEdge);
		}
	}

}

//Drawing The White Pieces
void drawTheWhitePieces() {

	indexC = 0;
	myShowBMP2(boardX + (boardEdge*indexC++), boardY, &wR, 0, 0, 0);
	myShowBMP2(boardX + (boardEdge*indexC++), boardY, &wKn, 0, 0, 0);
	myShowBMP2(boardX + (boardEdge*indexC++), boardY, &wB, 0, 0, 0);
	myShowBMP2(boardX + (boardEdge*indexC++), boardY, &wQ, 0, 0, 0);
	myShowBMP2(boardX + (boardEdge*indexC++), boardY, &wK, 0, 0, 0);
	myShowBMP2(boardX + (boardEdge*indexC++), boardY, &wB, 0, 0, 0);
	myShowBMP2(boardX + (boardEdge*indexC++), boardY, &wKn, 0, 0, 0);
	myShowBMP2(boardX + (boardEdge*indexC++), boardY, &wR, 0, 0, 0);

	for (indexC = 0; indexC < 8; indexC++)
		myShowBMP2(boardX + (boardEdge*indexC), boardY + boardEdge, &wP, 0,0,0);

}

//Drawing The Black Pieces
void drawTheBlackPieces() {

	indexC = 0;
	myShowBMP2(boardX + (boardEdge*indexC++), boardY + (7 * boardEdge), &bR, 0,0,0);
	myShowBMP2(boardX + (boardEdge*indexC++), boardY + (7 * boardEdge), &bKn, 0,0,0);
	myShowBMP2(boardX + (boardEdge*indexC++), boardY + (7 * boardEdge), &bB, 0,0,0);
	myShowBMP2(boardX + (boardEdge*indexC++), boardY + (7 * boardEdge), &bQ, 0,0,0);
	myShowBMP2(boardX + (boardEdge*indexC++), boardY + (7 * boardEdge), &bK, 0,0,0);
	myShowBMP2(boardX + (boardEdge*indexC++), boardY + (7 * boardEdge), &bB, 0,0,0);
	myShowBMP2(boardX + (boardEdge*indexC++), boardY + (7 * boardEdge), &bKn, 0,0,0);
	myShowBMP2(boardX + (boardEdge*indexC++), boardY + (7 * boardEdge), &bR, 0,0,0);

	for (indexC = 0; indexC < 8; indexC++)
		myShowBMP2(boardX+(boardEdge*indexC), boardY + (6 * boardEdge), &bP, 0,0,0);

}

void drawTheTimer(Players player1, Players player2) {
	if(player1.turn) iShowBMP(initialX, initialY, "Media//Player-1 Turn.bmp");
	else iShowBMP(initialX, initialY, "Media//Player-2 Turn.bmp");

	if (player2.turn)
		iSetColor(whiteR, whiteG, whiteB);
	else
		iSetColor(blackR, blackG, blackB);

	sprintf_s(player2.timeShow, "%d:%d", player2.mins, player2.secs);
	iText(player2TimeX, player2TimeY + 40, player2.timeShow, GLUT_BITMAP_TIMES_ROMAN_24);

	if (player1.turn)
		iSetColor(whiteR, whiteG, whiteB);
	else
		iSetColor(blackR, blackG, blackB);

	sprintf_s(player1.timeShow, "%d:%d", player1.mins, player1.secs);
	iText(player1TimeX, player1TimeY + 40, player1.timeShow, GLUT_BITMAP_TIMES_ROMAN_24);

}

void showTheMatch() {
	drawTheTimer(player1, player2);
	drawTheBoard();
	drawTheWhitePieces();
	drawTheBlackPieces();

}

//Loading All The Images At Once As iShowBMP Makes The Game Slower
void loadAllThePieces() {
	myLoad("PIC/OUTPUT/bK.rs", &bK);
	myLoad("PIC/OUTPUT/bQ.rs", &bQ);
	myLoad("PIC/OUTPUT/bR.rs", &bR);
	myLoad("PIC/OUTPUT/bKn.rs", &bKn);
	myLoad("PIC/OUTPUT/bB.rs", &bB);
	myLoad("PIC/OUTPUT/bP.rs", &bP);

	myLoad("PIC/OUTPUT/wK.rs", &wK);
	myLoad("PIC/OUTPUT/wQ.rs", &wQ);
	myLoad("PIC/OUTPUT/wR.rs", &wR);
	myLoad("PIC/OUTPUT/wKn.rs", &wKn);
	myLoad("PIC/OUTPUT/wB.rs", &wB);
	myLoad("PIC/OUTPUT/wP.rs", &wP);
}


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

	//sprintf_s(s, "%d:%d", x, y);
	//iSetColor(0, 0, 0);
	//iText(0, 10, s, GLUT_BITMAP_TIMES_ROMAN_24);
}

void iMouseMove(int mx, int my)
{

}

void iMouse(int button, int state, int mx, int my)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{

	}
	else if (button == GLUT_LEFT_BUTTON && state == GLUT_UP)
	{

	}
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{

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
		if (key == GLUT_KEY_DOWN && selectPos < 3) selectPos++;
		else if (key == GLUT_KEY_UP && selectPos > 0) selectPos--;
	}

	//Info Menu Moving
	else if (menu == info) {
		if (key == GLUT_KEY_DOWN && selectPos == 0) selectPos++;
		else if (key == GLUT_KEY_UP && selectPos == 1) selectPos--;
	}

	//How To Play Scrolling
	else if (menu == inHowToPlay) {
		if (key == GLUT_KEY_DOWN && selectPos<16) selectPos++;
		else if (key == GLUT_KEY_UP && selectPos>0) selectPos--;
	}
}

void player1Timer()
{
	if (player1.turn) {
		player1.secs--;
		if (player1.secs == 0) player1.mins--;
	}
}

void player2Timer()
{
	if (player2.turn) {
		player2.secs--;
		if (player2.secs == 0) player2.mins--;
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
