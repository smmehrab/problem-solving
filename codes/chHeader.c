/*
************************************************
username    :   smmehrab
fullname    :   s.m.mehrabul islam
email       :   mehrab.24csedu.001@gmail.com
institute   :   university of dhaka, bangladesh
session     :   2017-2018
************************************************
*/
#define windowWidth 840
#define windowHeight 630

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
#define boardLength (8*boardEdge)

#define player2TimeX 605
#define player2TimeY 262

#define player1TimeX 705
#define player1TimeY 262

//char s[100];
//int x, y,i;

struct Click {
	int x, y;
}clickL,clickR;

char boardStatus[8][8] = {
	{'R','N','B','Q','K','B','N','R'},
	{'P','P','P','P','P','P','P','P'},
	//{'\0','\0','\0','\0','\0','\0','\0','\0'},
	{'\0','\0','\0','\0','\0','\0','\0','\0'},
	{'\0','\0','\0','\0','\0','\0','\0','\0'},
	{'\0','\0','\0','\0','\0','\0','\0','\0'},
	{'\0','\0','\0','\0','\0','\0','\0','\0'},
	//{'\0','\0','\0','\0','\0','\0','\0','\0'},
	{'p','p','p','p','p','p','p','p'},
	{'r','n','b','q','k','b','n','r'}
};

int valid[8][8] = {
	{0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0},
				{0,0,0,0,0,0,0,0},
					{0,0,0,0,0,0,0,0},
						{0,0,0,0,0,0,0,0},
							{0,0,0,0,0,0,0,0},
								{0,0,0,0,0,0,0,0},
};
/*
int totalValid[8][8] = {
	{0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0},
				{0,0,0,0,0,0,0,0},
					{0,0,0,0,0,0,0,0},
						{0,0,0,0,0,0,0,0},
							{0,0,0,0,0,0,0,0},
								{0,0,0,0,0,0,0,0},
};
*/

int statusIndexX,statusIndexY;
int indexX, indexY;

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
char win[100] = "Wins!";


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
	info,gameOver
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
	int rating=1200, index = 0;
	int turn,clock;
	int secs, mins;
	char nameShow[100];
	int kingX, kingY;
	int win = 0;
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


void refreshValid() {
	for (indexR = 0; indexR < 8; indexR++) {
		for (indexC = 0; indexC < 8; indexC++) {
			valid[indexR][indexC] = 0;
		}
	}
}

/*
void refreshTotalValid() {
	for (indexR = 0; indexR < 8; indexR++) {
		for (indexC = 0; indexC < 8; indexC++) {
			totalValid[indexR][indexC] = 0;
		}
	}
}*/



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
		PlaySound("Media//Menu Select.wav", 0, 0);
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
		PlaySound("Media//Menu Select.wav", 0, 0);
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

			player1.clock = 1;
			player2.clock = 0;

			player1.win = 0;
			player2.win = 0;
		}
	}

	else if (*menu == gameOver) {
		PlaySound("Media//Menu Select.wav", 0, 0);
		*menu = mainMenu;
		*selectPos = newMatch;
		memset(player1.mail, '\0', 100 * sizeof(char));
		memset(player2.mail, '\0', 100 * sizeof(char));

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

	//Showing Players' Name
	iSetColor(whiteR,whiteG,whiteB);
	sprintf_s(player1.nameShow, "%s (%d)", player1.mail, player1.rating);
	iText(boardX, boardY-30, player1.nameShow, GLUT_BITMAP_TIMES_ROMAN_24);
	sprintf_s(player2.nameShow, "%s (%d)", player2.mail, player2.rating);
	iText(boardX, boardY + boardLength + 20, player2.nameShow, GLUT_BITMAP_TIMES_ROMAN_24);

}

//Drawing The White Pieces
void drawThePieces() {

	for (indexR = 0; indexR < 8; indexR++) {
		for (indexC = 0; indexC < 8; indexC++) {
			if (boardStatus[indexR][indexC] == 'k')
				myShowBMP2(boardX + (boardEdge*indexC), boardY+  ((7 - indexR)*boardEdge), &wK, 0, 0, 0);
			else if (boardStatus[indexR][indexC] == 'q')
				myShowBMP2(boardX + (boardEdge*indexC), boardY + ((7 - indexR)*boardEdge), &wQ, 0, 0, 0);
			else if (boardStatus[indexR][indexC] == 'r')
				myShowBMP2(boardX + (boardEdge*indexC), boardY + ((7 - indexR)*boardEdge), &wR, 0, 0, 0);
			else if (boardStatus[indexR][indexC] == 'n')
				myShowBMP2(boardX + (boardEdge*indexC), boardY + ((7 - indexR)*boardEdge), &wKn, 0, 0, 0);
			else if (boardStatus[indexR][indexC] == 'b')
				myShowBMP2(boardX + (boardEdge*indexC), boardY + ((7 - indexR)*boardEdge), &wB, 0, 0, 0);
			else if (boardStatus[indexR][indexC] == 'p')
				myShowBMP2(boardX + (boardEdge*indexC), boardY + ((7 - indexR)*boardEdge), &wP, 0, 0, 0);


			else if (boardStatus[indexR][indexC] == 'K')
				myShowBMP2(boardX + (boardEdge*indexC), boardY + ((7 - indexR)*boardEdge), &bK, 0, 0, 0);
			else if (boardStatus[indexR][indexC] == 'Q')
				myShowBMP2(boardX + (boardEdge*indexC), boardY + ((7 - indexR)*boardEdge), &bQ, 0, 0, 0);
			else if (boardStatus[indexR][indexC] == 'R')
				myShowBMP2(boardX + (boardEdge*indexC), boardY + ((7 - indexR)*boardEdge), &bR, 0, 0, 0);
			else if (boardStatus[indexR][indexC] == 'N')
				myShowBMP2(boardX + (boardEdge*indexC), boardY + ((7 - indexR)*boardEdge), &bKn, 0, 0, 0);
			else if (boardStatus[indexR][indexC] == 'B')
				myShowBMP2(boardX + (boardEdge*indexC), boardY + ((7 - indexR)*boardEdge), &bB, 0, 0, 0);
			else if (boardStatus[indexR][indexC] == 'P')
				myShowBMP2(boardX + (boardEdge*indexC), boardY + ((7 - indexR)*boardEdge), &bP, 0, 0, 0);
		}
	}
}

void drawTheTimer(Players player1, Players player2) {
	if(player1.clock) iShowBMP(initialX, initialY, "Media//Player-1 Turn.bmp");
	else iShowBMP(initialX, initialY, "Media//Player-2 Turn.bmp");

	if (player2.clock)
		iSetColor(whiteR, whiteG, whiteB);
	else
		iSetColor(blackR, blackG, blackB);

	sprintf_s(player2.timeShow, "%d:%d", player2.mins, player2.secs);
	iText(player2TimeX, player2TimeY + 40, player2.timeShow, GLUT_BITMAP_TIMES_ROMAN_24);

	if (player1.clock)
		iSetColor(whiteR, whiteG, whiteB);
	else
		iSetColor(blackR, blackG, blackB);

	sprintf_s(player1.timeShow, "%d:%d", player1.mins, player1.secs);
	iText(player1TimeX, player1TimeY + 40, player1.timeShow, GLUT_BITMAP_TIMES_ROMAN_24);

	iSetColor(whiteR, whiteG, whiteB);
	iText(player1TimeX+10, player1TimeY-15 , "P1", GLUT_BITMAP_TIMES_ROMAN_24);
	iText(player2TimeX+10, player1TimeY-15, "P2", GLUT_BITMAP_TIMES_ROMAN_24);

}



void findKings() {
	for (indexR = 0; indexR < 8; indexR++) {
		for (indexC = 0; indexC < 8; indexC++) {
			if (boardStatus[indexR][indexC] == 'K') {
				player2.kingX = indexR;
				player2.kingY = indexC;
			}
			else if (boardStatus[indexR][indexC] == 'k') {
				player1.kingX = indexR;
				player1.kingY = indexC;
			}
		}
	}
}

int ifCheck(Players player1, Players player2) {
	if (player1.turn) {
		indexR = player1.kingX; indexC = player1.kingY;
		while (indexR < 7 && indexC < 7) {
			indexR++;
			indexC++;
			if ((boardStatus[indexR][indexC] > 'a' && boardStatus[indexR][indexC] < 'z')) break;
			else if ((boardStatus[indexR][indexC] > 'A' &&  boardStatus[indexR][indexC] < 'Z')) {
				if (boardStatus[indexR][indexC] == 'Q' || boardStatus[indexR][indexC] == 'B')
					return 1;
				else if ((boardStatus[indexR][indexC] == 'P' || boardStatus[indexR][indexC] == 'K') && (abs(indexR - player1.kingY) == 1) && (abs(indexC - player1.kingX) == 1))
					return 1;
			}
		}

		indexR = player1.kingX; indexC = player1.kingY;
		while (indexR < 7 && indexC >0) {
			indexR++;
			indexC--;
			if ((boardStatus[indexR][indexC] > 'a' && boardStatus[indexR][indexC] < 'z')) break;
			else if ((boardStatus[indexR][indexC] > 'A' &&  boardStatus[indexR][indexC] < 'Z')) {
				if (boardStatus[indexR][indexC] == 'Q' || boardStatus[indexR][indexC] == 'B')
					return 1;
				else if ((boardStatus[indexR][indexC] == 'P' || boardStatus[indexR][indexC] == 'K') && (abs(indexR - player1.kingY) == 1) && (abs(indexC - player1.kingX) == 1))
					return 1;
			}
		}

		indexR = player1.kingX; indexC = player1.kingY;
		while (indexR > 0 && indexC < 7) {
			indexR--;
			indexC++;
			if ((boardStatus[indexR][indexC] > 'a' && boardStatus[indexR][indexC] < 'z')) break;
			else if ((boardStatus[indexR][indexC] > 'A' &&  boardStatus[indexR][indexC] < 'Z')) {
				if (boardStatus[indexR][indexC] == 'Q' || boardStatus[indexR][indexC] == 'B')
					return 1;
				else if ((boardStatus[indexR][indexC] == 'P' || boardStatus[indexR][indexC] == 'K') && (abs(indexR - player1.kingY) == 1) && (abs(indexC - player1.kingX) == 1))
					return 1;
			}
		}

		indexR = player1.kingX; indexC = player1.kingY;
		while (indexR > 0 && indexC > 0) {
			indexR--;
			indexC--;
			if ((boardStatus[indexR][indexC] > 'a' && boardStatus[indexR][indexC] < 'z')) break;
			else if ((boardStatus[indexR][indexC] > 'A' &&  boardStatus[indexR][indexC] < 'Z')) {
				if (boardStatus[indexR][indexC] == 'Q' || boardStatus[indexR][indexC] == 'B')
					return 1;
				else if ((boardStatus[indexR][indexC] == 'P' || boardStatus[indexR][indexC] == 'K') && (abs(indexR - player1.kingY) == 1) && (abs(indexC - player1.kingX) == 1))
					return 1;
			}
		}

		indexR = player1.kingX; indexC = player1.kingY;
		while (indexR > 0) {
			indexR--;
			if ((boardStatus[indexR][indexC] > 'a' &&  boardStatus[indexR][indexC] < 'z')) break;
			else if ((boardStatus[indexR][indexC] > 'A'&&  boardStatus[indexR][indexC] < 'Z')) {
				if (boardStatus[indexR][indexC] == 'Q' || boardStatus[indexR][indexC] == 'R')
					return 1;
				else if ((boardStatus[indexR][indexC] == 'K') && (abs(indexR - player1.kingY) == 1))
					return 1;
			}
		}

		indexR = player1.kingX; indexC = player1.kingY;
		while (indexR < 7) {
			indexR++;
			if ((boardStatus[indexR][indexC] > 'a' &&  boardStatus[indexR][indexC] < 'z')) break;
			else if ((boardStatus[indexR][indexC] > 'A'&&  boardStatus[indexR][indexC] < 'Z')) {
				if (boardStatus[indexR][indexC] == 'Q' || boardStatus[indexR][indexC] == 'R')
					return 1;
				else if ((boardStatus[indexR][indexC] == 'K') && (abs(indexR - player1.kingY) == 1))
					return 1;
			}
		}

		indexR = player1.kingX; indexC = player1.kingY;
		while (indexC > 0) {
			indexC--;
			if ((boardStatus[indexR][indexC] > 'a' &&  boardStatus[indexR][indexC] < 'z')) break;
			else if ((boardStatus[indexR][indexC] > 'A'&&  boardStatus[indexR][indexC] < 'Z')) {
				if (boardStatus[indexR][indexC] == 'Q' || boardStatus[indexR][indexC] == 'R')
					return 1;
				else if ((boardStatus[indexR][indexC] == 'K') && (abs(indexC - player1.kingX) == 1))
					return 1;
			}
		}

		indexR = player1.kingX; indexC = player1.kingY;
		while (indexC < 7) {
			indexC++;
			if ((boardStatus[indexR][indexC] > 'a' &&  boardStatus[indexR][indexC] < 'z')) break;
			else if ((boardStatus[indexR][indexC] > 'A'&&  boardStatus[indexR][indexC] < 'Z')) {
				if (boardStatus[indexR][indexC] == 'Q' || boardStatus[indexR][indexC] == 'R')
					return 1;
				else if ((boardStatus[indexR][indexC] == 'K') && (abs(indexC - player1.kingX) == 1))
					return 1;
			}

		}

		indexR = player1.kingX; indexC = player1.kingY;

		if (boardStatus[indexR + 2][indexC + 1] == 'N' && (indexR + 2 < 8) && (indexC + 1 < 8))
			return 1;

		if (boardStatus[indexR - 2][indexC + 1] == 'N' && (indexR - 2 >= 0) && (indexC + 1 < 8))
			return 1;

		if ((boardStatus[indexR + 2][indexC - 1] == 'N') && (indexR + 2 < 8) && (indexC - 1 >= 0))
			return 1;

		if ((boardStatus[indexR - 2][indexC - 1] == 'N') && (indexR - 2 >= 0) && (indexC - 1 >= 0))
			return 1;

		if ((boardStatus[indexR + 1][indexC + 2] == 'N') && (indexR + 1 < 8) && (indexC + 2 < 8))
			return 1;

		if ((boardStatus[indexR - 1][indexC + 2] == 'N') && (indexR - 1 >= 0) && (indexC + 2 < 8))
			return 1;

		if ((boardStatus[indexR + 1][indexC - 2] == 'N') && (indexR + 1 < 8) && (indexC - 2 >= 0))
			return 1;

		if ((boardStatus[indexR - 1][indexC - 2] == 'N') && (indexR - 1 >= 0) && (indexC - 2 >= 0))
			return 1;
	}

	else if (player2.turn) {
		indexR = player2.kingX; indexC = player2.kingY;
		while (indexR < 7 && indexC < 7) {
			indexR++;
			indexC++;
			if ((boardStatus[indexR][indexC] > 'A' && boardStatus[indexR][indexC] < 'Z')) break;
			else if ((boardStatus[indexR][indexC] > 'a' &&  boardStatus[indexR][indexC] < 'z')) {
				if (boardStatus[indexR][indexC] == 'q' || boardStatus[indexR][indexC] == 'b')
					return 1;
				else if ((boardStatus[indexR][indexC] == 'p' || boardStatus[indexR][indexC] == 'k') && (abs(indexR - player2.kingY) == 1) && (abs(indexC - player2.kingX) == 1))
					return 1;
			}
		}

		indexR = player2.kingX; indexC = player2.kingY;
		while (indexR < 7 && indexC >0) {
			indexR++;
			indexC--;
			if ((boardStatus[indexR][indexC] > 'A' && boardStatus[indexR][indexC] < 'Z')) break;
			else if ((boardStatus[indexR][indexC] > 'a' &&  boardStatus[indexR][indexC] < 'z')) {
				if (boardStatus[indexR][indexC] == 'q' || boardStatus[indexR][indexC] == 'b')
					return 1;
				else if ((boardStatus[indexR][indexC] == 'p' || boardStatus[indexR][indexC] == 'k') && (abs(indexR - player2.kingY) == 1) && (abs(indexC - player2.kingX) == 1))
					return 1;
			}
		}

		indexR = player2.kingX; indexC = player2.kingY;
		while (indexR > 0 && indexC < 7) {
			indexR--;
			indexC++;
			if ((boardStatus[indexR][indexC] > 'A' && boardStatus[indexR][indexC] < 'Z')) break;
			else if ((boardStatus[indexR][indexC] > 'a' &&  boardStatus[indexR][indexC] < 'z')) {
				if (boardStatus[indexR][indexC] == 'q' || boardStatus[indexR][indexC] == 'b')
					return 1;
				else if ((boardStatus[indexR][indexC] == 'p' || boardStatus[indexR][indexC] == 'k') && (abs(indexR - player2.kingY) == 1) && (abs(indexC - player2.kingX) == 1))
					return 1;
			}
		}

		indexR = player2.kingX; indexC = player2.kingY;
		while (indexR > 0 && indexC > 0) {
			indexR--;
			indexC--;
			if ((boardStatus[indexR][indexC] > 'A' && boardStatus[indexR][indexC] < 'Z')) break;
			else if ((boardStatus[indexR][indexC] > 'a' &&  boardStatus[indexR][indexC] < 'z')) {
				if (boardStatus[indexR][indexC] == 'q' || boardStatus[indexR][indexC] == 'b')
					return 1;
				else if ((boardStatus[indexR][indexC] == 'p' || boardStatus[indexR][indexC] == 'k') && (abs(indexR - player2.kingY) == 1) && (abs(indexC - player2.kingX) == 1))
					return 1;
			}
		}

		indexR = player2.kingX; indexC = player2.kingY;
		while (indexR > 0) {
			indexR--;
			if ((boardStatus[indexR][indexC] > 'A' &&  boardStatus[indexR][indexC] < 'Z')) break;
			else if ((boardStatus[indexR][indexC] > 'a'&&  boardStatus[indexR][indexC] < 'z')) {
				if (boardStatus[indexR][indexC] == 'q' || boardStatus[indexR][indexC] == 'r')
					return 1;
				else if ((boardStatus[indexR][indexC] == 'k') && (abs(indexR - player2.kingY) == 1))
					return 1;
			}
		}

		indexR = player2.kingX; indexC = player2.kingY;
		while (indexR < 7) {
			indexR++;
			if ((boardStatus[indexR][indexC] > 'A' &&  boardStatus[indexR][indexC] < 'Z')) break;
			else if ((boardStatus[indexR][indexC] > 'a'&&  boardStatus[indexR][indexC] < 'z')) {
				if (boardStatus[indexR][indexC] == 'q' || boardStatus[indexR][indexC] == 'r')
					return 1;
				else if ((boardStatus[indexR][indexC] == 'k') && (abs(indexR - player2.kingY) == 1))
					return 1;
			}
		}

		indexR = player2.kingX; indexC = player2.kingY;
		while (indexC > 0) {
			indexC--;
			if ((boardStatus[indexR][indexC] > 'A' &&  boardStatus[indexR][indexC] < 'Z')) break;
			else if ((boardStatus[indexR][indexC] > 'a'&&  boardStatus[indexR][indexC] < 'z')) {
				if (boardStatus[indexR][indexC] == 'q' || boardStatus[indexR][indexC] == 'r')
					return 1;
				else if ((boardStatus[indexR][indexC] == 'k') && (abs(indexC - player2.kingX) == 1))
					return 1;
			}
		}

		indexR = player2.kingX; indexC = player2.kingY;
		while (indexC < 7) {
			indexC++;
			if ((boardStatus[indexR][indexC] > 'A' &&  boardStatus[indexR][indexC] < 'Z')) break;
			else if ((boardStatus[indexR][indexC] > 'a'&&  boardStatus[indexR][indexC] < 'z')) {
				if (boardStatus[indexR][indexC] == 'q' || boardStatus[indexR][indexC] == 'r')
					return 1;
				else if ((boardStatus[indexR][indexC] == 'k') && (abs(indexC - player2.kingX) == 1))
					return 1;
			}

		}

		indexR = player2.kingX; indexC = player2.kingY;

		if (boardStatus[indexR + 2][indexC + 1] == 'n' && (indexR + 2 < 8) && (indexC + 1 < 8))
			return 1;

		if (boardStatus[indexR - 2][indexC + 1] == 'n' && (indexR - 2 >= 0) && (indexC + 1 < 8))
			return 1;

		if ((boardStatus[indexR + 2][indexC - 1] == 'n') && (indexR + 2 < 8) && (indexC - 1 >= 0))
			return 1;

		if ((boardStatus[indexR - 2][indexC - 1] == 'n') && (indexR - 2 >= 0) && (indexC - 1 >= 0))
			return 1;

		if ((boardStatus[indexR + 1][indexC + 2] == 'n') && (indexR + 1 < 8) && (indexC + 2 < 8))
			return 1;

		if ((boardStatus[indexR - 1][indexC + 2] == 'n') && (indexR - 1 >= 0) && (indexC + 2 < 8))
			return 1;

		if ((boardStatus[indexR + 1][indexC - 2] == 'n') && (indexR + 1 < 8) && (indexC - 2 >= 0))
			return 1;

		if ((boardStatus[indexR - 1][indexC - 2] == 'n') && (indexR - 1 >= 0) && (indexC - 2 >= 0))
			return 1;
	}

	return 0;
}

void player1MarkValidSpots(int x, int y) {

	indexR = x;
	indexC = y;

	if (boardStatus[indexR][indexC] == 'k') {


		if ((boardStatus[indexR + 1][indexC]<'a' || boardStatus[indexR + 1][indexC] > 'z')&& (indexR+1<8)) {
			valid[indexR + 1][indexC] = 1;
			iSetColor(redR, redG, redB);
			iFilledRectangle(boardX + ((indexC)*boardEdge), boardY + ((7-indexR-1)*boardEdge), boardEdge, boardEdge);
		}

		if ((boardStatus[indexR - 1][indexC]<'a' || boardStatus[indexR - 1][indexC] > 'z') && (indexR - 1 >= 0)) {
			valid[indexR - 1][indexC] = 1;
			iSetColor(redR, redG, redB);
			iFilledRectangle(boardX + ((indexC)*boardEdge), boardY + ((7-indexR + 1)*boardEdge), boardEdge, boardEdge);
		}

		if ((boardStatus[indexR][indexC+1]<'a' || boardStatus[indexR][indexC+1] > 'z') && (indexC + 1 < 8)) {
			valid[indexR][indexC + 1] = 1;
			iSetColor(redR, redG, redB);
			iFilledRectangle(boardX + ((indexC+1)*boardEdge), boardY + ((7 - indexR)*boardEdge), boardEdge, boardEdge);
		}

		if ((boardStatus[indexR][indexC-1]<'a' || boardStatus[indexR][indexC-1] > 'z') && (indexC - 1 >=0)) {
			valid[indexR][indexC - 1] = 1;
			iSetColor(redR, redG, redB);
			iFilledRectangle(boardX + ((indexC-1)*boardEdge), boardY + ((7 - indexR)*boardEdge), boardEdge, boardEdge);
		}

		if ((boardStatus[indexR - 1][indexC-1]<'a' || boardStatus[indexR - 1][indexC-1] > 'z') && (indexR - 1 >= 0)  && (indexC - 1 >= 0)) {
			valid[indexR - 1][indexC - 1] = 1;
			iSetColor(redR, redG, redB);
			iFilledRectangle(boardX + ((indexC-1)*boardEdge), boardY + ((7 - indexR + 1)*boardEdge), boardEdge, boardEdge);
		}

		if ((boardStatus[indexR - 1][indexC + 1]<'a' || boardStatus[indexR - 1][indexC + 1] > 'z') && (indexR - 1 >= 0)  && (indexC + 1 <8)) {
			valid[indexR - 1][indexC + 1] = 1;
			iSetColor(redR, redG, redB);
			iFilledRectangle(boardX + ((indexC + 1)*boardEdge), boardY + ((7 - indexR + 1)*boardEdge), boardEdge, boardEdge);
		}

		if ((boardStatus[indexR + 1][indexC - 1]<'a' || boardStatus[indexR + 1][indexC - 1] > 'z') && (indexR + 1 <8)  && (indexC - 1 >= 0)) {
			valid[indexR + 1][indexC - 1] = 1;
			iSetColor(redR, redG, redB);
			iFilledRectangle(boardX + ((indexC - 1)*boardEdge), boardY + ((7 - indexR - 1)*boardEdge), boardEdge, boardEdge);
		}

		if ((boardStatus[indexR + 1][indexC + 1]<'a' || boardStatus[indexR + 1][indexC + 1] > 'z') && (indexR + 1 < 8) && (indexC + 1 < 8) ) {
			valid[indexR + 1][indexC + 1] = 1;
			iSetColor(redR, redG, redB);
			iFilledRectangle(boardX + ((indexC + 1)*boardEdge), boardY + ((7 - indexR - 1)*boardEdge), boardEdge, boardEdge);
		}
	}

	else if (boardStatus[indexR][indexC] == 'q') {
		indexR =x; indexC = y;
		while (indexR < 7 && indexC < 7) {
			indexR++;
			indexC++;
			if ((boardStatus[indexR][indexC] > 'a' && boardStatus[indexR][indexC] < 'z')) break;
			else if((boardStatus[indexR][indexC] > 'A' &&  boardStatus[indexR][indexC] < 'Z')) {
				valid[indexR][indexC] = 1;
				iSetColor(redR, redG, redB);
				iFilledRectangle(boardX + ((indexC)*boardEdge), boardY + ((7 - indexR)*boardEdge), boardEdge, boardEdge);
				break;
			}
			else {
				valid[indexR][indexC] = 1;
				iSetColor(redR, redG, redB);
				iFilledRectangle(boardX + ((indexC)*boardEdge), boardY + ((7 - indexR)*boardEdge), boardEdge, boardEdge);
			}
		}

		indexR = x; indexC = y;
		while (indexR < 7 && indexC >0) {
			indexR++;
			indexC--;
			if ((boardStatus[indexR][indexC] > 'a' &&  boardStatus[indexR][indexC] < 'z')) break;
			else if ((boardStatus[indexR][indexC] > 'A'&&  boardStatus[indexR][indexC] < 'Z')) {
				valid[indexR][indexC] = 1;
				iSetColor(redR, redG, redB);
				iFilledRectangle(boardX + ((indexC)*boardEdge), boardY + ((7 - indexR)*boardEdge), boardEdge, boardEdge);
				break;
			}
			else {
				valid[indexR][indexC] = 1;
				iSetColor(redR, redG, redB);
				iFilledRectangle(boardX + ((indexC)*boardEdge), boardY + ((7 - indexR)*boardEdge), boardEdge, boardEdge);
			}
		}

		indexR = x; indexC = y;
		while (indexR > 0 && indexC < 7) {
			indexR--;
			indexC++;
			if ((boardStatus[indexR][indexC] > 'a'&&  boardStatus[indexR][indexC] < 'z')) break;
			else if ((boardStatus[indexR][indexC] > 'A' &&  boardStatus[indexR][indexC] < 'Z')) {
				valid[indexR][indexC] = 1;
				iSetColor(redR, redG, redB);
				iFilledRectangle(boardX + ((indexC)*boardEdge), boardY + ((7 - indexR)*boardEdge), boardEdge, boardEdge);
				break;
			}
			else {
				valid[indexR][indexC] = 1;
				iSetColor(redR, redG, redB);
				iFilledRectangle(boardX + ((indexC)*boardEdge), boardY + ((7 - indexR)*boardEdge), boardEdge, boardEdge);
			}
		}

		indexR = x; indexC = y;
		while (indexR > 0 && indexC > 0) {
			indexR--;
			indexC--;
			if ((boardStatus[indexR][indexC] > 'a' &&  boardStatus[indexR][indexC] < 'z')) break;
			else if ((boardStatus[indexR][indexC] > 'A' &&  boardStatus[indexR][indexC] < 'Z')) {
				valid[indexR][indexC] = 1;
				iSetColor(redR, redG, redB);
				iFilledRectangle(boardX + ((indexC)*boardEdge), boardY + ((7 - indexR)*boardEdge), boardEdge, boardEdge);
				break;
			}
			else {
				valid[indexR][indexC] = 1;
				iSetColor(redR, redG, redB);
				iFilledRectangle(boardX + ((indexC)*boardEdge), boardY + ((7 - indexR)*boardEdge), boardEdge, boardEdge);
			}
		}

		indexR = x; indexC = y;
		while (indexR > 0) {
			indexR--;
			if ((boardStatus[indexR][indexC] > 'a' &&  boardStatus[indexR][indexC] < 'z')) break;
			else if ((boardStatus[indexR][indexC] > 'A' &&  boardStatus[indexR][indexC] < 'Z')) {
				valid[indexR][indexC] = 1;
				iSetColor(redR, redG, redB);
				iFilledRectangle(boardX + ((indexC)*boardEdge), boardY + ((7 - indexR)*boardEdge), boardEdge, boardEdge);
				break;
			}
			else {
				valid[indexR][indexC] = 1;
				iSetColor(redR, redG, redB);
				iFilledRectangle(boardX + ((indexC)*boardEdge), boardY + ((7 - indexR)*boardEdge), boardEdge, boardEdge);
			}
		}

		indexR = x; indexC = y;
		while (indexR < 7) {
			indexR++;
			if ((boardStatus[indexR][indexC] > 'a' &&  boardStatus[indexR][indexC] < 'z')) break;
			else if ((boardStatus[indexR][indexC] > 'A' &&  boardStatus[indexR][indexC] < 'Z')) {
				valid[indexR][indexC] = 1;
				iSetColor(redR, redG, redB);
				iFilledRectangle(boardX + ((indexC)*boardEdge), boardY + ((7 - indexR)*boardEdge), boardEdge, boardEdge);
				break;
			}
			else {
				valid[indexR][indexC] = 1;
				iSetColor(redR, redG, redB);
				iFilledRectangle(boardX + ((indexC)*boardEdge), boardY + ((7 - indexR)*boardEdge), boardEdge, boardEdge);
			}
		}

		indexR = x; indexC = y;
		while (indexC > 0) {
			indexC--;
			if ((boardStatus[indexR][indexC] > 'a' &&  boardStatus[indexR][indexC] < 'z')) break;
			else if ((boardStatus[indexR][indexC] > 'A' &&  boardStatus[indexR][indexC] < 'Z')) {
				valid[indexR][indexC] = 1;
				iSetColor(redR, redG, redB);
				iFilledRectangle(boardX + ((indexC)*boardEdge), boardY + ((7 - indexR)*boardEdge), boardEdge, boardEdge);
				break;
			}
			else {
				valid[indexR][indexC] = 1;
				iSetColor(redR, redG, redB);
				iFilledRectangle(boardX + ((indexC)*boardEdge), boardY + ((7 - indexR)*boardEdge), boardEdge, boardEdge);
			}
		}

		indexR = x; indexC = y;
		while (indexC < 7) {
			indexC++;
			if ((boardStatus[indexR][indexC] > 'a'&&  boardStatus[indexR][indexC] < 'z')) break;
			else if ((boardStatus[indexR][indexC] > 'A' &&  boardStatus[indexR][indexC] < 'Z')) {
				valid[indexR][indexC] = 1;
				iSetColor(redR, redG, redB);
				iFilledRectangle(boardX + ((indexC)*boardEdge), boardY + ((7 - indexR)*boardEdge), boardEdge, boardEdge);
				break;
			}
			else {
				valid[indexR][indexC] = 1;
				iSetColor(redR, redG, redB);
				iFilledRectangle(boardX + ((indexC)*boardEdge), boardY + ((7 - indexR)*boardEdge), boardEdge, boardEdge);
			}
		}
	}

	else if (boardStatus[indexR][indexC] == 'r') {
		indexR = x; indexC = y;
		while (indexR > 0) {
			indexR--;
			if ((boardStatus[indexR][indexC] > 'a' &&  boardStatus[indexR][indexC] < 'z')) break;
			else if ((boardStatus[indexR][indexC] > 'A' &&  boardStatus[indexR][indexC] < 'Z')) {
				valid[indexR][indexC] = 1;
				iSetColor(redR, redG, redB);
				iFilledRectangle(boardX + ((indexC)*boardEdge), boardY + ((7 - indexR)*boardEdge), boardEdge, boardEdge);
				break;
			}
			else {
				valid[indexR][indexC] = 1;
				iSetColor(redR, redG, redB);
				iFilledRectangle(boardX + ((indexC)*boardEdge), boardY + ((7 - indexR)*boardEdge), boardEdge, boardEdge);
			}
		}

		indexR = x; indexC = y;
		while (indexR < 7) {
			indexR++;
			if ((boardStatus[indexR][indexC] > 'a' &&  boardStatus[indexR][indexC] < 'z')) break;
			else if ((boardStatus[indexR][indexC] > 'A' &&  boardStatus[indexR][indexC] < 'Z')) {
				valid[indexR][indexC] = 1;
				iSetColor(redR, redG, redB);
				iFilledRectangle(boardX + ((indexC)*boardEdge), boardY + ((7 - indexR)*boardEdge), boardEdge, boardEdge);
				break;
			}
			else {
				valid[indexR][indexC] = 1;
				iSetColor(redR, redG, redB);
				iFilledRectangle(boardX + ((indexC)*boardEdge), boardY + ((7 - indexR)*boardEdge), boardEdge, boardEdge);
			}
		}

		indexR = x; indexC = y;
		while (indexC > 0) {
			indexC--;
			if ((boardStatus[indexR][indexC] > 'a' &&  boardStatus[indexR][indexC] < 'z')) break;
			else if ((boardStatus[indexR][indexC] > 'A' &&  boardStatus[indexR][indexC] < 'Z')) {
				valid[indexR][indexC] = 1;
				iSetColor(redR, redG, redB);
				iFilledRectangle(boardX + ((indexC)*boardEdge), boardY + ((7 - indexR)*boardEdge), boardEdge, boardEdge);
				break;
			}
			else {
				valid[indexR][indexC] = 1;
				iSetColor(redR, redG, redB);
				iFilledRectangle(boardX + ((indexC)*boardEdge), boardY + ((7 - indexR)*boardEdge), boardEdge, boardEdge);
			}
		}

		indexR = x; indexC = y;
		while (indexC < 7) {
			indexC++;
			if ((boardStatus[indexR][indexC] > 'a'&&  boardStatus[indexR][indexC] < 'z')) break;
			else if ((boardStatus[indexR][indexC] > 'A' &&  boardStatus[indexR][indexC] < 'Z')) {
				valid[indexR][indexC] = 1;
				iSetColor(redR, redG, redB);
				iFilledRectangle(boardX + ((indexC)*boardEdge), boardY + ((7 - indexR)*boardEdge), boardEdge, boardEdge);
				break;
			}
			else {
				valid[indexR][indexC] = 1;
				iSetColor(redR, redG, redB);
				iFilledRectangle(boardX + ((indexC)*boardEdge), boardY + ((7 - indexR)*boardEdge), boardEdge, boardEdge);
			}
		}
	}

	else if (boardStatus[indexR][indexC] == 'n') {

		if ((boardStatus[indexR + 2][indexC+1]<'a' || boardStatus[indexR + 2][indexC+1] > 'z') && (indexR + 2 < 8) && (indexC + 1 < 8)) {
			valid[indexR + 2][indexC + 1] = 1;
			iSetColor(redR, redG, redB);
			iFilledRectangle(boardX + ((indexC+1)*boardEdge), boardY + ((7 - indexR - 2)*boardEdge), boardEdge, boardEdge);
		}

		if ((boardStatus[indexR - 2][indexC+1]<'a' || boardStatus[indexR - 2][indexC+1] > 'z') && (indexR - 2 >= 0) && (indexC + 1 < 8)) {
			valid[indexR - 2][indexC + 1] = 1;
			iSetColor(redR, redG, redB);
			iFilledRectangle(boardX + ((indexC+1)*boardEdge), boardY + ((7 - indexR + 2)*boardEdge), boardEdge, boardEdge);
		}

		if ((boardStatus[indexR + 2][indexC - 1]<'a' || boardStatus[indexR + 2][indexC - 1] > 'z') && (indexR + 2 < 8) && (indexC - 1 >=0)) {
			valid[indexR + 2][indexC - 1] = 1;
			iSetColor(redR, redG, redB);
			iFilledRectangle(boardX + ((indexC - 1)*boardEdge), boardY + ((7 - indexR - 2)*boardEdge), boardEdge, boardEdge);
		}

		if ((boardStatus[indexR - 2][indexC - 1]<'a' || boardStatus[indexR - 2][indexC - 1] > 'z') && (indexR - 2 >= 0) && (indexC - 1 >= 0)) {
			valid[indexR - 2][indexC - 1] = 1;
			iSetColor(redR, redG, redB);
			iFilledRectangle(boardX + ((indexC - 1)*boardEdge), boardY + ((7 - indexR + 2)*boardEdge), boardEdge, boardEdge);
		}

		if ((boardStatus[indexR + 1][indexC + 2]<'a' || boardStatus[indexR + 1][indexC + 2] > 'z') && (indexR + 1 < 8) && (indexC + 2 < 8)) {
			valid[indexR + 1][indexC + 2] = 1;
			iSetColor(redR, redG, redB);
			iFilledRectangle(boardX + ((indexC + 2)*boardEdge), boardY + ((7 - indexR - 1)*boardEdge), boardEdge, boardEdge);
		}

		if ((boardStatus[indexR - 1][indexC + 2]<'a' || boardStatus[indexR - 1][indexC + 2] > 'z') && (indexR - 1 >= 0) && (indexC + 2 < 8)) {
			valid[indexR - 1][indexC + 2] = 1;
			iSetColor(redR, redG, redB);
			iFilledRectangle(boardX + ((indexC + 2)*boardEdge), boardY + ((7 - indexR + 1)*boardEdge), boardEdge, boardEdge);
		}

		if ((boardStatus[indexR + 1][indexC - 2]<'a' || boardStatus[indexR + 1][indexC - 2] > 'z') && (indexR + 1 < 8) && (indexC - 2 >= 0)) {
			valid[indexR + 1][indexC - 2] = 1;
			iSetColor(redR, redG, redB);
			iFilledRectangle(boardX + ((indexC - 2)*boardEdge), boardY + ((7 - indexR - 1)*boardEdge), boardEdge, boardEdge);
		}

		if ((boardStatus[indexR - 1][indexC - 2]<'a' || boardStatus[indexR - 1][indexC - 2] > 'z') && (indexR - 1 >= 0) && (indexC - 2 >= 0)) {
			valid[indexR - 1][indexC - 2] = 1;
			iSetColor(redR, redG, redB);
			iFilledRectangle(boardX + ((indexC - 2)*boardEdge), boardY + ((7 - indexR + 1)*boardEdge), boardEdge, boardEdge);
		}

	}

	else if (boardStatus[indexR][indexC] == 'b') {
		indexR = x; indexC = y;
		while (indexR < 7 && indexC < 7) {
			indexR++;
			indexC++;
			if ((boardStatus[indexR][indexC] > 'a' && boardStatus[indexR][indexC] < 'z')) break;
			else if ((boardStatus[indexR][indexC] > 'A' &&  boardStatus[indexR][indexC] < 'Z')) {
				valid[indexR][indexC] = 1;
				iSetColor(redR, redG, redB);
				iFilledRectangle(boardX + ((indexC)*boardEdge), boardY + ((7 - indexR)*boardEdge), boardEdge, boardEdge);
				break;
			}
			else {
				valid[indexR][indexC] = 1;
				iSetColor(redR, redG, redB);
				iFilledRectangle(boardX + ((indexC)*boardEdge), boardY + ((7 - indexR)*boardEdge), boardEdge, boardEdge);
			}
		}

		indexR = x; indexC = y;
		while (indexR < 7 && indexC >0) {
			indexR++;
			indexC--;
			if ((boardStatus[indexR][indexC] > 'a' &&  boardStatus[indexR][indexC] < 'z')) break;
			else if ((boardStatus[indexR][indexC] > 'A'&&  boardStatus[indexR][indexC] < 'Z')) {
				valid[indexR][indexC] = 1;
				iSetColor(redR, redG, redB);
				iFilledRectangle(boardX + ((indexC)*boardEdge), boardY + ((7 - indexR)*boardEdge), boardEdge, boardEdge);
				break;
			}
			else {
				valid[indexR][indexC] = 1;
				iSetColor(redR, redG, redB);
				iFilledRectangle(boardX + ((indexC)*boardEdge), boardY + ((7 - indexR)*boardEdge), boardEdge, boardEdge);
			}
		}

		indexR = x; indexC = y;
		while (indexR > 0 && indexC < 7) {
			indexR--;
			indexC++;
			if ((boardStatus[indexR][indexC] > 'a'&&  boardStatus[indexR][indexC] < 'z')) break;
			else if ((boardStatus[indexR][indexC] > 'A' &&  boardStatus[indexR][indexC] < 'Z')) {
				valid[indexR][indexC] = 1;
				iSetColor(redR, redG, redB);
				iFilledRectangle(boardX + ((indexC)*boardEdge), boardY + ((7 - indexR)*boardEdge), boardEdge, boardEdge);
				break;
			}
			else {
				valid[indexR][indexC] = 1;
				iSetColor(redR, redG, redB);
				iFilledRectangle(boardX + ((indexC)*boardEdge), boardY + ((7 - indexR)*boardEdge), boardEdge, boardEdge);
			}
		}

		indexR = x; indexC = y;
		while (indexR > 0 && indexC > 0) {
			indexR--;
			indexC--;
			if ((boardStatus[indexR][indexC] > 'a' &&  boardStatus[indexR][indexC] < 'z')) break;
			else if ((boardStatus[indexR][indexC] > 'A' &&  boardStatus[indexR][indexC] < 'Z')) {
				valid[indexR][indexC] = 1;
				iSetColor(redR, redG, redB);
				iFilledRectangle(boardX + ((indexC)*boardEdge), boardY + ((7 - indexR)*boardEdge), boardEdge, boardEdge);
				break;
			}
			else {
				valid[indexR][indexC] = 1;
				iSetColor(redR, redG, redB);
				iFilledRectangle(boardX + ((indexC)*boardEdge), boardY + ((7 - indexR)*boardEdge), boardEdge, boardEdge);
			}
		}
	}

	else if (boardStatus[indexR][indexC] == 'p') {

		if (indexR == 6 && boardStatus[5][indexC] == '\0') {
			valid[indexR - 2][indexC] = 1;
			iSetColor(redR, redG, redB);
			iFilledRectangle(boardX + ((indexC)*boardEdge), boardY + ((7 - indexR + 2)*boardEdge), boardEdge, boardEdge);
		}

		if ((boardStatus[indexR - 1][indexC]<'a' || boardStatus[indexR - 1][indexC] > 'z') && (indexR - 1 >= 0)) {
			valid[indexR - 1][indexC] = 1;
			iSetColor(redR, redG, redB);
			iFilledRectangle(boardX + ((indexC)*boardEdge), boardY + ((7 - indexR + 1)*boardEdge), boardEdge, boardEdge);
		}

		if ((boardStatus[indexR - 1][indexC+1]>'A' && boardStatus[indexR - 1][indexC+1] < 'Z') && (indexR - 1 >= 0) && (indexC + 1)<8) {
			valid[indexR - 1][indexC+1] = 1;
			iSetColor(redR, redG, redB);
			iFilledRectangle(boardX + ((indexC+1)*boardEdge), boardY + ((7 - indexR + 1)*boardEdge), boardEdge, boardEdge);
		}

		if ((boardStatus[indexR - 1][indexC-1]>'A' && boardStatus[indexR - 1][indexC-1] < 'Z') && (indexR - 1 >= 0) && (indexC - 1)) {
			valid[indexR - 1][indexC-1] = 1;
			iSetColor(redR, redG, redB);
			iFilledRectangle(boardX + ((indexC-1)*boardEdge), boardY + ((7 - indexR + 1)*boardEdge), boardEdge, boardEdge);
		}
	}
}

void player2MarkValidSpots(int x, int y) {

	indexR = x;
	indexC = y;

	if (boardStatus[indexR][indexC] == 'K') {

		if ((boardStatus[indexR + 1][indexC]<'A' || boardStatus[indexR + 1][indexC] > 'Z') && (indexR + 1 < 8)) {
			valid[indexR + 1][indexC] = 1;
			iSetColor(redR, redG, redB);
			iFilledRectangle(boardX + ((indexC)*boardEdge), boardY + ((7 - indexR-1)*boardEdge), boardEdge, boardEdge);
		}

		if ((boardStatus[indexR - 1][indexC]<'A' || boardStatus[indexR - 1][indexC] > 'Z') && (indexR - 1 >= 0)) {
			valid[indexR - 1][indexC] = 1;
			iSetColor(redR, redG, redB);
			iFilledRectangle(boardX + ((indexC)*boardEdge), boardY + ((7 - indexR + 1)*boardEdge), boardEdge, boardEdge);
		}

		if ((boardStatus[indexR][indexC + 1]<'A' || boardStatus[indexR][indexC + 1] > 'Z') && (indexC + 1 < 8) ) {
			valid[indexR][indexC + 1] = 1;
			iSetColor(redR, redG, redB);
			iFilledRectangle(boardX + ((indexC + 1)*boardEdge), boardY + ((7 - indexR)*boardEdge), boardEdge, boardEdge);
		}

		if ((boardStatus[indexR][indexC - 1]<'A' || boardStatus[indexR][indexC - 1] > 'Z') && (indexC - 1 >= 0) ) {
			valid[indexR][indexC - 1] = 1;
			iSetColor(redR, redG, redB);
			iFilledRectangle(boardX + ((indexC - 1)*boardEdge), boardY + ((7 - indexR)*boardEdge), boardEdge, boardEdge);
		}

		if ((boardStatus[indexR - 1][indexC - 1]<'A' || boardStatus[indexR - 1][indexC - 1] > 'Z') && (indexR - 1 >= 0) && (indexC - 1 >= 0)) {
			valid[indexR - 1][indexC - 1] = 1;
			iSetColor(redR, redG, redB);
			iFilledRectangle(boardX + ((indexC - 1)*boardEdge), boardY + ((7 - indexR + 1)*boardEdge), boardEdge, boardEdge);
		}

		if ((boardStatus[indexR - 1][indexC + 1]<'A' || boardStatus[indexR - 1][indexC + 1] > 'Z') && (indexR - 1 >= 0)&& (indexC + 1 < 8)) {
			valid[indexR - 1][indexC + 1] = 1;
			iSetColor(redR, redG, redB);
			iFilledRectangle(boardX + ((indexC + 1)*boardEdge), boardY + ((7 - indexR + 1)*boardEdge), boardEdge, boardEdge);
		}

		if ((boardStatus[indexR + 1][indexC - 1]<'A' || boardStatus[indexR + 1][indexC - 1] > 'Z') && (indexR + 1 < 8)  && (indexC - 1 >= 0)) {
			valid[indexR + 1][indexC - 1] = 1;
			iSetColor(redR, redG, redB);
			iFilledRectangle(boardX + ((indexC - 1)*boardEdge), boardY + ((7 - indexR - 1)*boardEdge), boardEdge, boardEdge);
		}

		if ((boardStatus[indexR + 1][indexC + 1]<'A' || boardStatus[indexR + 1][indexC + 1] > 'Z') && (indexR + 1 < 8)&& (indexC + 1 < 8)) {
			valid[indexR + 1][indexC + 1] = 1;
			iSetColor(redR, redG, redB);
			iFilledRectangle(boardX + ((indexC + 1)*boardEdge), boardY + ((7 - indexR - 1)*boardEdge), boardEdge, boardEdge);
		}
	}

	else if (boardStatus[indexR][indexC] == 'Q') {
		indexR = x; indexC = y;
		while (indexR < 7 && indexC < 7) {
			indexR++;
			indexC++;
			if ((boardStatus[indexR][indexC] > 'A' && boardStatus[indexR][indexC] < 'Z')) break;
			else if ((boardStatus[indexR][indexC] > 'a' &&  boardStatus[indexR][indexC] < 'z')) {
				valid[indexR][indexC] = 1;
				iSetColor(redR, redG, redB);
				iFilledRectangle(boardX + ((indexC)*boardEdge), boardY + ((7 - indexR)*boardEdge), boardEdge, boardEdge);
				break;
			}
			else {
				valid[indexR][indexC] = 1;
				iSetColor(redR, redG, redB);
				iFilledRectangle(boardX + ((indexC)*boardEdge), boardY + ((7 - indexR)*boardEdge), boardEdge, boardEdge);
			}
		}

		indexR = x; indexC = y;
		while (indexR < 7 && indexC >0) {
			indexR++;
			indexC--;
			if ((boardStatus[indexR][indexC] > 'A' &&  boardStatus[indexR][indexC] < 'Z')) break;
			else if ((boardStatus[indexR][indexC] > 'a'&&  boardStatus[indexR][indexC] < 'z')) {
				valid[indexR][indexC] = 1;
				iSetColor(redR, redG, redB);
				iFilledRectangle(boardX + ((indexC)*boardEdge), boardY + ((7 - indexR)*boardEdge), boardEdge, boardEdge);
				break;
			}
			else {
				valid[indexR][indexC] = 1;
				iSetColor(redR, redG, redB);
				iFilledRectangle(boardX + ((indexC)*boardEdge), boardY + ((7 - indexR)*boardEdge), boardEdge, boardEdge);
			}
		}

		indexR = x; indexC = y;
		while (indexR > 0 && indexC < 7) {
			indexR--;
			indexC++;
			if ((boardStatus[indexR][indexC] > 'A'&&  boardStatus[indexR][indexC] < 'Z')) break;
			else if ((boardStatus[indexR][indexC] > 'a' &&  boardStatus[indexR][indexC] < 'z')) {
				valid[indexR][indexC] = 1;
				iSetColor(redR, redG, redB);
				iFilledRectangle(boardX + ((indexC)*boardEdge), boardY + ((7 - indexR)*boardEdge), boardEdge, boardEdge);
				break;
			}
			else {
				valid[indexR][indexC] = 1;
				iSetColor(redR, redG, redB);
				iFilledRectangle(boardX + ((indexC)*boardEdge), boardY + ((7 - indexR)*boardEdge), boardEdge, boardEdge);
			}
		}

		indexR = x; indexC = y;
		while (indexR > 0 && indexC > 0) {
			indexR--;
			indexC--;
			if ((boardStatus[indexR][indexC] > 'A' &&  boardStatus[indexR][indexC] < 'Z')) break;
			else if ((boardStatus[indexR][indexC] > 'a' &&  boardStatus[indexR][indexC] < 'z')) {
				valid[indexR][indexC] = 1;
				iSetColor(redR, redG, redB);
				iFilledRectangle(boardX + ((indexC)*boardEdge), boardY + ((7 - indexR)*boardEdge), boardEdge, boardEdge);
				break;
			}
			else {
				valid[indexR][indexC] = 1;
				iSetColor(redR, redG, redB);
				iFilledRectangle(boardX + ((indexC)*boardEdge), boardY + ((7 - indexR)*boardEdge), boardEdge, boardEdge);
			}
		}

		indexR = x; indexC = y;
		while (indexR > 0) {
			indexR--;
			if ((boardStatus[indexR][indexC] > 'A' &&  boardStatus[indexR][indexC] < 'Z')) break;
			else if ((boardStatus[indexR][indexC] > 'a' &&  boardStatus[indexR][indexC] < 'z')) {
				valid[indexR][indexC] = 1;
				iSetColor(redR, redG, redB);
				iFilledRectangle(boardX + ((indexC)*boardEdge), boardY + ((7 - indexR)*boardEdge), boardEdge, boardEdge);
				break;
			}
			else {
				valid[indexR][indexC] = 1;
				iSetColor(redR, redG, redB);
				iFilledRectangle(boardX + ((indexC)*boardEdge), boardY + ((7 - indexR)*boardEdge), boardEdge, boardEdge);
			}
		}

		indexR = x; indexC = y;
		while (indexR < 7) {
			indexR++;
			if ((boardStatus[indexR][indexC] > 'A' &&  boardStatus[indexR][indexC] < 'Z')) break;
			else if ((boardStatus[indexR][indexC] > 'a' &&  boardStatus[indexR][indexC] < 'z')) {
				valid[indexR][indexC] = 1;
				iSetColor(redR, redG, redB);
				iFilledRectangle(boardX + ((indexC)*boardEdge), boardY + ((7 - indexR)*boardEdge), boardEdge, boardEdge);
				break;
			}
			else {
				valid[indexR][indexC] = 1;
				iSetColor(redR, redG, redB);
				iFilledRectangle(boardX + ((indexC)*boardEdge), boardY + ((7 - indexR)*boardEdge), boardEdge, boardEdge);
			}
		}

		indexR = x; indexC = y;
		while (indexC > 0) {
			indexC--;
			if ((boardStatus[indexR][indexC] > 'A' &&  boardStatus[indexR][indexC] < 'Z')) break;
			else if ((boardStatus[indexR][indexC] > 'a' &&  boardStatus[indexR][indexC] < 'z')) {
				valid[indexR][indexC] = 1;
				iSetColor(redR, redG, redB);
				iFilledRectangle(boardX + ((indexC)*boardEdge), boardY + ((7 - indexR)*boardEdge), boardEdge, boardEdge);
				break;
			}
			else {
				valid[indexR][indexC] = 1;
				iSetColor(redR, redG, redB);
				iFilledRectangle(boardX + ((indexC)*boardEdge), boardY + ((7 - indexR)*boardEdge), boardEdge, boardEdge);
			}
		}

		indexR = x; indexC = y;
		while (indexC < 7) {
			indexC++;
			if ((boardStatus[indexR][indexC] > 'A'&&  boardStatus[indexR][indexC] < 'Z')) break;
			else if ((boardStatus[indexR][indexC] > 'a' &&  boardStatus[indexR][indexC] < 'z')) {
				valid[indexR][indexC] = 1;
				iSetColor(redR, redG, redB);
				iFilledRectangle(boardX + ((indexC)*boardEdge), boardY + ((7 - indexR)*boardEdge), boardEdge, boardEdge);
				break;
			}
			else {
				valid[indexR][indexC] = 1;
				iSetColor(redR, redG, redB);
				iFilledRectangle(boardX + ((indexC)*boardEdge), boardY + ((7 - indexR)*boardEdge), boardEdge, boardEdge);
			}
		}
	}

	else if (boardStatus[indexR][indexC] == 'R') {
		indexR = x; indexC = y;
		while (indexR > 0) {
			indexR--;
			if ((boardStatus[indexR][indexC] > 'A' &&  boardStatus[indexR][indexC] < 'Z')) break;
			else if ((boardStatus[indexR][indexC] > 'a' &&  boardStatus[indexR][indexC] < 'z')) {
				valid[indexR][indexC] = 1;
				iSetColor(redR, redG, redB);
				iFilledRectangle(boardX + ((indexC)*boardEdge), boardY + ((7 - indexR)*boardEdge), boardEdge, boardEdge);
				break;
			}
			else {
				valid[indexR][indexC] = 1;
				iSetColor(redR, redG, redB);
				iFilledRectangle(boardX + ((indexC)*boardEdge), boardY + ((7 - indexR)*boardEdge), boardEdge, boardEdge);
			}
		}

		indexR = x; indexC = y;
		while (indexR < 7) {
			indexR++;
			if ((boardStatus[indexR][indexC] > 'A' &&  boardStatus[indexR][indexC] < 'Z')) break;
			else if ((boardStatus[indexR][indexC] > 'a' &&  boardStatus[indexR][indexC] < 'z')) {
				valid[indexR][indexC] = 1;
				iSetColor(redR, redG, redB);
				iFilledRectangle(boardX + ((indexC)*boardEdge), boardY + ((7 - indexR)*boardEdge), boardEdge, boardEdge);
				break;
			}
			else {
				valid[indexR][indexC] = 1;
				iSetColor(redR, redG, redB);
				iFilledRectangle(boardX + ((indexC)*boardEdge), boardY + ((7 - indexR)*boardEdge), boardEdge, boardEdge);
			}
		}

		indexR = x; indexC = y;
		while (indexC > 0) {
			indexC--;
			if ((boardStatus[indexR][indexC] > 'A' &&  boardStatus[indexR][indexC] < 'Z')) break;
			else if ((boardStatus[indexR][indexC] > 'a' &&  boardStatus[indexR][indexC] < 'z')) {
				valid[indexR][indexC] = 1;
				iSetColor(redR, redG, redB);
				iFilledRectangle(boardX + ((indexC)*boardEdge), boardY + ((7 - indexR)*boardEdge), boardEdge, boardEdge);
				break;
			}
			else {
				valid[indexR][indexC] = 1;
				iSetColor(redR, redG, redB);
				iFilledRectangle(boardX + ((indexC)*boardEdge), boardY + ((7 - indexR)*boardEdge), boardEdge, boardEdge);
			}
		}

		indexR = x; indexC = y;
		while (indexC < 7) {
			indexC++;
			if ((boardStatus[indexR][indexC] > 'A'&&  boardStatus[indexR][indexC] < 'Z')) break;
			else if ((boardStatus[indexR][indexC] > 'a' &&  boardStatus[indexR][indexC] < 'z')) {
				valid[indexR][indexC] = 1;
				iSetColor(redR, redG, redB);
				iFilledRectangle(boardX + ((indexC)*boardEdge), boardY + ((7 - indexR)*boardEdge), boardEdge, boardEdge);
				break;
			}
			else {
				valid[indexR][indexC] = 1;
				iSetColor(redR, redG, redB);
				iFilledRectangle(boardX + ((indexC)*boardEdge), boardY + ((7 - indexR)*boardEdge), boardEdge, boardEdge);
			}
		}
	}

	else 	if (boardStatus[indexR][indexC] == 'N') {

		if ((boardStatus[indexR + 2][indexC + 1]<'A' || boardStatus[indexR + 2][indexC + 1] > 'Z') && (indexR + 2 < 8) && (indexC + 1 < 8)) {
			valid[indexR + 2][indexC + 1] = 1;
			iSetColor(redR, redG, redB);
			iFilledRectangle(boardX + ((indexC + 1)*boardEdge), boardY + ((7 - indexR - 2)*boardEdge), boardEdge, boardEdge);
		}

		if ((boardStatus[indexR - 2][indexC + 1]<'A' || boardStatus[indexR - 2][indexC + 1] > 'Z') && (indexR - 2 >= 0) && (indexC + 1 < 8)) {
			valid[indexR - 2][indexC + 1] = 1;
			iSetColor(redR, redG, redB);
			iFilledRectangle(boardX + ((indexC + 1)*boardEdge), boardY + ((7 - indexR + 2)*boardEdge), boardEdge, boardEdge);
		}

		if ((boardStatus[indexR + 2][indexC - 1]<'A' || boardStatus[indexR + 2][indexC - 1] > 'Z') && (indexR + 2 < 8) && (indexC - 1 >= 0)) {
			valid[indexR + 2][indexC - 1] = 1;
			iSetColor(redR, redG, redB);
			iFilledRectangle(boardX + ((indexC - 1)*boardEdge), boardY + ((7 - indexR - 2)*boardEdge), boardEdge, boardEdge);
		}

		if ((boardStatus[indexR - 2][indexC - 1]<'A' || boardStatus[indexR - 2][indexC - 1] > 'Z') && (indexR - 2 >= 0) && (indexC - 1 >= 0)) {
			valid[indexR - 2][indexC - 1] = 1;
			iSetColor(redR, redG, redB);
			iFilledRectangle(boardX + ((indexC - 1)*boardEdge), boardY + ((7 - indexR + 2)*boardEdge), boardEdge, boardEdge);
		}

		if ((boardStatus[indexR + 1][indexC + 2]<'A' || boardStatus[indexR + 1][indexC + 2] > 'Z') && (indexR + 1 < 8) && (indexC + 2 < 8)) {
			valid[indexR + 1][indexC + 2] = 1;
			iSetColor(redR, redG, redB);
			iFilledRectangle(boardX + ((indexC + 2)*boardEdge), boardY + ((7 - indexR - 1)*boardEdge), boardEdge, boardEdge);
		}

		if ((boardStatus[indexR - 1][indexC + 2]<'A' || boardStatus[indexR - 1][indexC + 2] > 'Z') && (indexR - 1 >= 0) && (indexC + 2 < 8)) {
			valid[indexR - 1][indexC + 2] = 1;
			iSetColor(redR, redG, redB);
			iFilledRectangle(boardX + ((indexC + 2)*boardEdge), boardY + ((7 - indexR + 1)*boardEdge), boardEdge, boardEdge);
		}

		if ((boardStatus[indexR + 1][indexC - 2]<'A' || boardStatus[indexR + 1][indexC - 2] > 'Z') && (indexR + 1 < 8) && (indexC - 2 >= 0)) {
			valid[indexR + 1][indexC - 2] = 1;
			iSetColor(redR, redG, redB);
			iFilledRectangle(boardX + ((indexC - 2)*boardEdge), boardY + ((7 - indexR - 1)*boardEdge), boardEdge, boardEdge);
		}

		if ((boardStatus[indexR - 1][indexC - 2]<'A' || boardStatus[indexR - 1][indexC - 2] > 'Z') && (indexR - 1 >= 0) && (indexC - 2 >= 0)) {
			valid[indexR - 1][indexC - 2] = 1;
			iSetColor(redR, redG, redB);
			iFilledRectangle(boardX + ((indexC - 2)*boardEdge), boardY + ((7 - indexR + 1)*boardEdge), boardEdge, boardEdge);
		}

	}

	else if (boardStatus[indexR][indexC] == 'B') {
		indexR = x; indexC = y;
		while (indexR < 7 && indexC < 7) {
			indexR++;
			indexC++;
			if ((boardStatus[indexR][indexC] > 'A' && boardStatus[indexR][indexC] < 'Z')) break;
			else if ((boardStatus[indexR][indexC] > 'a' &&  boardStatus[indexR][indexC] < 'z')) {
				valid[indexR][indexC] = 1;
				iSetColor(redR, redG, redB);
				iFilledRectangle(boardX + ((indexC)*boardEdge), boardY + ((7 - indexR)*boardEdge), boardEdge, boardEdge);
				break;
			}
			else {
				valid[indexR][indexC] = 1;
				iSetColor(redR, redG, redB);
				iFilledRectangle(boardX + ((indexC)*boardEdge), boardY + ((7 - indexR)*boardEdge), boardEdge, boardEdge);
			}
		}

		indexR = x; indexC = y;
		while (indexR < 7 && indexC >0) {
			indexR++;
			indexC--;
			if ((boardStatus[indexR][indexC] > 'A' &&  boardStatus[indexR][indexC] < 'Z')) break;
			else if ((boardStatus[indexR][indexC] > 'a'&&  boardStatus[indexR][indexC] < 'z')) {
				valid[indexR][indexC] = 1;
				iSetColor(redR, redG, redB);
				iFilledRectangle(boardX + ((indexC)*boardEdge), boardY + ((7 - indexR)*boardEdge), boardEdge, boardEdge);
				break;
			}
			else {
				valid[indexR][indexC] = 1;
				iSetColor(redR, redG, redB);
				iFilledRectangle(boardX + ((indexC)*boardEdge), boardY + ((7 - indexR)*boardEdge), boardEdge, boardEdge);
			}
		}

		indexR = x; indexC = y;
		while (indexR > 0 && indexC < 7) {
			indexR--;
			indexC++;
			if ((boardStatus[indexR][indexC] > 'A'&&  boardStatus[indexR][indexC] < 'Z')) break;
			else if ((boardStatus[indexR][indexC] > 'a' &&  boardStatus[indexR][indexC] < 'z')) {
				valid[indexR][indexC] = 1;
				iSetColor(redR, redG, redB);
				iFilledRectangle(boardX + ((indexC)*boardEdge), boardY + ((7 - indexR)*boardEdge), boardEdge, boardEdge);
				break;
			}
			else {
				valid[indexR][indexC] = 1;
				iSetColor(redR, redG, redB);
				iFilledRectangle(boardX + ((indexC)*boardEdge), boardY + ((7 - indexR)*boardEdge), boardEdge, boardEdge);
			}
		}

		indexR = x; indexC = y;
		while (indexR > 0 && indexC > 0) {
			indexR--;
			indexC--;
			if ((boardStatus[indexR][indexC] > 'A' &&  boardStatus[indexR][indexC] < 'Z')) break;
			else if ((boardStatus[indexR][indexC] > 'a' &&  boardStatus[indexR][indexC] < 'z')) {
				valid[indexR][indexC] = 1;
				iSetColor(redR, redG, redB);
				iFilledRectangle(boardX + ((indexC)*boardEdge), boardY + ((7 - indexR)*boardEdge), boardEdge, boardEdge);
				break;
			}
			else {
				valid[indexR][indexC] = 1;
				iSetColor(redR, redG, redB);
				iFilledRectangle(boardX + ((indexC)*boardEdge), boardY + ((7 - indexR)*boardEdge), boardEdge, boardEdge);
			}
		}
	}

	else if (boardStatus[indexR][indexC] == 'P') {

		if (indexR == 1 && boardStatus[2][indexC]=='\0') {
			valid[indexR + 2][indexC] = 1;
			iSetColor(redR, redG, redB);
			iFilledRectangle(boardX + ((indexC)*boardEdge), boardY + ((7 - indexR - 2)*boardEdge), boardEdge, boardEdge);
		}

		if ((boardStatus[indexR + 1][indexC]<'A' || boardStatus[indexR + 1][indexC] > 'Z') && (indexR +1<8)) {
			valid[indexR + 1][indexC] = 1;
			iSetColor(redR, redG, redB);
			iFilledRectangle(boardX + ((indexC)*boardEdge), boardY + ((7 - indexR - 1)*boardEdge), boardEdge, boardEdge);
		}

		if ((boardStatus[indexR + 1][indexC + 1] > 'a' && boardStatus[indexR + 1][indexC + 1] < 'z') && (indexR + 1 < 8) && (indexC + 1) < 8) {
			valid[indexR + 1][indexC + 1] = 1;
			iSetColor(redR, redG, redB);
			iFilledRectangle(boardX + ((indexC + 1)*boardEdge), boardY + ((7 - indexR - 1)*boardEdge), boardEdge, boardEdge);
		}

		if ((boardStatus[indexR + 1][indexC - 1] > 'a' && boardStatus[indexR + 1][indexC - 1] < 'z') && (indexR + 1 < 8) && (indexC - 1)) {
			valid[indexR + 1][indexC - 1] = 1;
			iSetColor(redR, redG, redB);
			iFilledRectangle(boardX + ((indexC - 1)*boardEdge), boardY + ((7 - indexR - 1)*boardEdge), boardEdge, boardEdge);
		}
	}
}

void player1ValidSpots(int x, int y) {

	indexR = x;
	indexC = y;

	if (boardStatus[indexR][indexC] == 'k') {


		if ((boardStatus[indexR + 1][indexC]<'a' || boardStatus[indexR + 1][indexC] > 'z') && (indexR + 1 < 8))
			valid[indexR + 1][indexC] = 1;

		if ((boardStatus[indexR - 1][indexC]<'a' || boardStatus[indexR - 1][indexC] > 'z') && (indexR - 1 >= 0))
			valid[indexR - 1][indexC] = 1;


		if ((boardStatus[indexR][indexC + 1]<'a' || boardStatus[indexR][indexC + 1] > 'z') && (indexC + 1 < 8))
			valid[indexR][indexC + 1] = 1;

		if ((boardStatus[indexR][indexC - 1]<'a' || boardStatus[indexR][indexC - 1] > 'z') && (indexC - 1 >= 0))
			valid[indexR][indexC - 1] = 1;

		if ((boardStatus[indexR - 1][indexC - 1]<'a' || boardStatus[indexR - 1][indexC - 1] > 'z') && (indexR - 1 >= 0) && (indexC - 1 >= 0))
			valid[indexR - 1][indexC - 1] = 1;

		if ((boardStatus[indexR - 1][indexC + 1]<'a' || boardStatus[indexR - 1][indexC + 1] > 'z') && (indexR - 1 >= 0) && (indexC + 1 < 8))
			valid[indexR - 1][indexC + 1] = 1;

		if ((boardStatus[indexR + 1][indexC - 1]<'a' || boardStatus[indexR + 1][indexC - 1] > 'z') && (indexR + 1 < 8) && (indexC - 1 >= 0))
			valid[indexR + 1][indexC - 1] = 1;

		if ((boardStatus[indexR + 1][indexC + 1]<'a' || boardStatus[indexR + 1][indexC + 1] > 'z') && (indexR + 1 < 8) && (indexC + 1 < 8))
			valid[indexR + 1][indexC + 1] = 1;

	}

	else if (boardStatus[indexR][indexC] == 'q') {
		indexR = x; indexC = y;
		while (indexR < 7 && indexC < 7) {
			indexR++;
			indexC++;
			if ((boardStatus[indexR][indexC] > 'a' && boardStatus[indexR][indexC] < 'z')) break;
			else if ((boardStatus[indexR][indexC] > 'A' &&  boardStatus[indexR][indexC] < 'Z')) {
				valid[indexR][indexC] = 1;
				break;
			}
			else {
				valid[indexR][indexC] = 1;
			}
		}

		indexR = x; indexC = y;
		while (indexR < 7 && indexC >0) {
			indexR++;
			indexC--;
			if ((boardStatus[indexR][indexC] > 'a' &&  boardStatus[indexR][indexC] < 'z')) break;
			else if ((boardStatus[indexR][indexC] > 'A'&&  boardStatus[indexR][indexC] < 'Z')) {
				valid[indexR][indexC] = 1;
				break;
			}
			else {
				valid[indexR][indexC] = 1;
			}
		}

		indexR = x; indexC = y;
		while (indexR > 0 && indexC < 7) {
			indexR--;
			indexC++;
			if ((boardStatus[indexR][indexC] > 'a'&&  boardStatus[indexR][indexC] < 'z')) break;
			else if ((boardStatus[indexR][indexC] > 'A' &&  boardStatus[indexR][indexC] < 'Z')) {
				valid[indexR][indexC] = 1;
				break;
			}
			else {
				valid[indexR][indexC] = 1;

			}
		}

		indexR = x; indexC = y;
		while (indexR > 0 && indexC > 0) {
			indexR--;
			indexC--;
			if ((boardStatus[indexR][indexC] > 'a' &&  boardStatus[indexR][indexC] < 'z')) break;
			else if ((boardStatus[indexR][indexC] > 'A' &&  boardStatus[indexR][indexC] < 'Z')) {
				valid[indexR][indexC] = 1;
				break;
			}
			else {
				valid[indexR][indexC] = 1;
			}
		}

		indexR = x; indexC = y;
		while (indexR > 0) {
			indexR--;
			if ((boardStatus[indexR][indexC] > 'a' &&  boardStatus[indexR][indexC] < 'z')) break;
			else if ((boardStatus[indexR][indexC] > 'A' &&  boardStatus[indexR][indexC] < 'Z')) {
				valid[indexR][indexC] = 1;
				break;
			}
			else {
				valid[indexR][indexC] = 1;
			}
		}

		indexR = x; indexC = y;
		while (indexR < 7) {
			indexR++;
			if ((boardStatus[indexR][indexC] > 'a' &&  boardStatus[indexR][indexC] < 'z')) break;
			else if ((boardStatus[indexR][indexC] > 'A' &&  boardStatus[indexR][indexC] < 'Z')) {
				valid[indexR][indexC] = 1;
				break;
			}
			else {
				valid[indexR][indexC] = 1;
			}
		}

		indexR = x; indexC = y;
		while (indexC > 0) {
			indexC--;
			if ((boardStatus[indexR][indexC] > 'a' &&  boardStatus[indexR][indexC] < 'z')) break;
			else if ((boardStatus[indexR][indexC] > 'A' &&  boardStatus[indexR][indexC] < 'Z')) {
				valid[indexR][indexC] = 1;
				break;
			}
			else {
				valid[indexR][indexC] = 1;
			}
		}

		indexR = x; indexC = y;
		while (indexC < 7) {
			indexC++;
			if ((boardStatus[indexR][indexC] > 'a'&&  boardStatus[indexR][indexC] < 'z')) break;
			else if ((boardStatus[indexR][indexC] > 'A' &&  boardStatus[indexR][indexC] < 'Z')) {
				valid[indexR][indexC] = 1;
				break;
			}
			else {
				valid[indexR][indexC] = 1;
			}
		}
	}

	else if (boardStatus[indexR][indexC] == 'r') {
		indexR = x; indexC = y;
		while (indexR > 0) {
			indexR--;
			if ((boardStatus[indexR][indexC] > 'a' &&  boardStatus[indexR][indexC] < 'z')) break;
			else if ((boardStatus[indexR][indexC] > 'A' &&  boardStatus[indexR][indexC] < 'Z')) {
				valid[indexR][indexC] = 1;
				break;
			}
			else {
				valid[indexR][indexC] = 1;
			}
		}

		indexR = x; indexC = y;
		while (indexR < 7) {
			indexR++;
			if ((boardStatus[indexR][indexC] > 'a' &&  boardStatus[indexR][indexC] < 'z')) break;
			else if ((boardStatus[indexR][indexC] > 'A' &&  boardStatus[indexR][indexC] < 'Z')) {
				valid[indexR][indexC] = 1;
				break;
			}
			else {
				valid[indexR][indexC] = 1;
			}
		}

		indexR = x; indexC = y;
		while (indexC > 0) {
			indexC--;
			if ((boardStatus[indexR][indexC] > 'a' &&  boardStatus[indexR][indexC] < 'z')) break;
			else if ((boardStatus[indexR][indexC] > 'A' &&  boardStatus[indexR][indexC] < 'Z')) {
				valid[indexR][indexC] = 1;
				break;
			}
			else {
				valid[indexR][indexC] = 1;
			}
		}

		indexR = x; indexC = y;
		while (indexC < 7) {
			indexC++;
			if ((boardStatus[indexR][indexC] > 'a'&&  boardStatus[indexR][indexC] < 'z')) break;
			else if ((boardStatus[indexR][indexC] > 'A' &&  boardStatus[indexR][indexC] < 'Z')) {
				valid[indexR][indexC] = 1;
				break;
			}
			else {
				valid[indexR][indexC] = 1;
			}
		}
	}

	else if (boardStatus[indexR][indexC] == 'n') {

		if ((boardStatus[indexR + 2][indexC + 1]<'a' || boardStatus[indexR + 2][indexC + 1] > 'z') && (indexR + 2 < 8) && (indexC + 1 < 8)) {
			valid[indexR + 2][indexC + 1] = 1;
		}

		if ((boardStatus[indexR - 2][indexC + 1]<'a' || boardStatus[indexR - 2][indexC + 1] > 'z') && (indexR - 2 >= 0) && (indexC + 1 < 8)) {
			valid[indexR - 2][indexC + 1] = 1;
		}

		if ((boardStatus[indexR + 2][indexC - 1]<'a' || boardStatus[indexR + 2][indexC - 1] > 'z') && (indexR + 2 < 8) && (indexC - 1 >= 0)) {
			valid[indexR + 2][indexC - 1] = 1;
		}

		if ((boardStatus[indexR - 2][indexC - 1]<'a' || boardStatus[indexR - 2][indexC - 1] > 'z') && (indexR - 2 >= 0) && (indexC - 1 >= 0)) {
			valid[indexR - 2][indexC - 1] = 1;
		}

		if ((boardStatus[indexR + 1][indexC + 2]<'a' || boardStatus[indexR + 1][indexC + 2] > 'z') && (indexR + 1 < 8) && (indexC + 2 < 8)) {
			valid[indexR + 1][indexC + 2] = 1;
		}

		if ((boardStatus[indexR - 1][indexC + 2]<'a' || boardStatus[indexR - 1][indexC + 2] > 'z') && (indexR - 1 >= 0) && (indexC + 2 < 8)) {
			valid[indexR - 1][indexC + 2] = 1;
		}

		if ((boardStatus[indexR + 1][indexC - 2]<'a' || boardStatus[indexR + 1][indexC - 2] > 'z') && (indexR + 1 < 8) && (indexC - 2 >= 0)) {
			valid[indexR + 1][indexC - 2] = 1;
		}

		if ((boardStatus[indexR - 1][indexC - 2]<'a' || boardStatus[indexR - 1][indexC - 2] > 'z') && (indexR - 1 >= 0) && (indexC - 2 >= 0)) {
			valid[indexR - 1][indexC - 2] = 1;
		}

	}

	else if (boardStatus[indexR][indexC] == 'b') {
		indexR = x; indexC = y;
		while (indexR < 7 && indexC < 7) {
			indexR++;
			indexC++;
			if ((boardStatus[indexR][indexC] > 'a' && boardStatus[indexR][indexC] < 'z')) break;
			else if ((boardStatus[indexR][indexC] > 'A' &&  boardStatus[indexR][indexC] < 'Z')) {
				valid[indexR][indexC] = 1;
				break;
			}
			else {
				valid[indexR][indexC] = 1;
			}
		}

		indexR = x; indexC = y;
		while (indexR < 7 && indexC >0) {
			indexR++;
			indexC--;
			if ((boardStatus[indexR][indexC] > 'a' &&  boardStatus[indexR][indexC] < 'z')) break;
			else if ((boardStatus[indexR][indexC] > 'A'&&  boardStatus[indexR][indexC] < 'Z')) {
				valid[indexR][indexC] = 1;
				break;
			}
			else {
				valid[indexR][indexC] = 1;
				iSetColor(redR, redG, redB);
				iFilledRectangle(boardX + ((indexC)*boardEdge), boardY + ((7 - indexR)*boardEdge), boardEdge, boardEdge);
			}
		}

		indexR = x; indexC = y;
		while (indexR > 0 && indexC < 7) {
			indexR--;
			indexC++;
			if ((boardStatus[indexR][indexC] > 'a'&&  boardStatus[indexR][indexC] < 'z')) break;
			else if ((boardStatus[indexR][indexC] > 'A' &&  boardStatus[indexR][indexC] < 'Z')) {
				valid[indexR][indexC] = 1;
				break;
			}
			else {
				valid[indexR][indexC] = 1;
			}
		}

		indexR = x; indexC = y;
		while (indexR > 0 && indexC > 0) {
			indexR--;
			indexC--;
			if ((boardStatus[indexR][indexC] > 'a' &&  boardStatus[indexR][indexC] < 'z')) break;
			else if ((boardStatus[indexR][indexC] > 'A' &&  boardStatus[indexR][indexC] < 'Z')) {
				valid[indexR][indexC] = 1;
				break;
			}
			else {
				valid[indexR][indexC] = 1;
			}
		}
	}

	else if (boardStatus[indexR][indexC] == 'p') {

		if (indexR == 6 && boardStatus[indexR - 2][indexC] == '\0') {
			valid[indexR - 2][indexC] = 1;
		}

		if ((boardStatus[indexR - 1][indexC]<'a' || boardStatus[indexR - 1][indexC] > 'z') && (indexR - 1 >= 0)) {
			valid[indexR - 1][indexC] = 1;
		}

		if ((boardStatus[indexR - 1][indexC + 1] > 'A' && boardStatus[indexR - 1][indexC + 1] < 'Z') && (indexR - 1 >= 0) && (indexC + 1) < 8) {
			valid[indexR - 1][indexC + 1] = 1;
		}

		if ((boardStatus[indexR - 1][indexC - 1] > 'A' && boardStatus[indexR - 1][indexC - 1] < 'Z') && (indexR - 1 >= 0) && (indexC - 1)) {
			valid[indexR - 1][indexC - 1] = 1;
		}
	}
}

void player2ValidSpots(int x, int y) {

	indexR = x;
	indexC = y;

	if (boardStatus[indexR][indexC] == 'K') {

		if ((boardStatus[indexR + 1][indexC]<'A' || boardStatus[indexR + 1][indexC] > 'Z') && (indexR + 1 < 8)) {
			valid[indexR + 1][indexC] = 1;
		}

		if ((boardStatus[indexR - 1][indexC]<'A' || boardStatus[indexR - 1][indexC] > 'Z') && (indexR - 1 >= 0)) {
			valid[indexR - 1][indexC] = 1;
		}

		if ((boardStatus[indexR][indexC + 1]<'A' || boardStatus[indexR][indexC + 1] > 'Z') && (indexC + 1 < 8)) {
			valid[indexR][indexC + 1] = 1;
		}

		if ((boardStatus[indexR][indexC - 1]<'A' || boardStatus[indexR][indexC - 1] > 'Z') && (indexC - 1 >= 0)) {
			valid[indexR][indexC - 1] = 1;
		}

		if ((boardStatus[indexR - 1][indexC - 1]<'A' || boardStatus[indexR - 1][indexC - 1] > 'Z') && (indexR - 1 >= 0) && (indexC - 1 >= 0)) {
			valid[indexR - 1][indexC - 1] = 1;
		}

		if ((boardStatus[indexR - 1][indexC + 1]<'A' || boardStatus[indexR - 1][indexC + 1] > 'Z') && (indexR - 1 >= 0) && (indexC + 1 < 8)) {
			valid[indexR - 1][indexC + 1] = 1;
		}

		if ((boardStatus[indexR + 1][indexC - 1]<'A' || boardStatus[indexR + 1][indexC - 1] > 'Z') && (indexR + 1 < 8) && (indexC - 1 >= 0)) {
			valid[indexR + 1][indexC - 1] = 1;
		}

		if ((boardStatus[indexR + 1][indexC + 1]<'A' || boardStatus[indexR + 1][indexC + 1] > 'Z') && (indexR + 1 < 8) && (indexC + 1 < 8)) {
			valid[indexR + 1][indexC + 1] = 1;
		}
	}

	else if (boardStatus[indexR][indexC] == 'Q') {
		indexR = x; indexC = y;
		while (indexR < 7 && indexC < 7) {
			indexR++;
			indexC++;
			if ((boardStatus[indexR][indexC] > 'A' && boardStatus[indexR][indexC] < 'Z')) break;
			else if ((boardStatus[indexR][indexC] > 'a' &&  boardStatus[indexR][indexC] < 'z')) {
				valid[indexR][indexC] = 1;
				break;
			}
			else {
				valid[indexR][indexC] = 1;
			}
		}

		indexR = x; indexC = y;
		while (indexR < 7 && indexC >0) {
			indexR++;
			indexC--;
			if ((boardStatus[indexR][indexC] > 'A' &&  boardStatus[indexR][indexC] < 'Z')) break;
			else if ((boardStatus[indexR][indexC] > 'a'&&  boardStatus[indexR][indexC] < 'z')) {
				valid[indexR][indexC] = 1;
				break;
			}
			else {
				valid[indexR][indexC] = 1;
			}
		}

		indexR = x; indexC = y;
		while (indexR > 0 && indexC < 7) {
			indexR--;
			indexC++;
			if ((boardStatus[indexR][indexC] > 'A'&&  boardStatus[indexR][indexC] < 'Z')) break;
			else if ((boardStatus[indexR][indexC] > 'a' &&  boardStatus[indexR][indexC] < 'z')) {
				valid[indexR][indexC] = 1;
				break;
			}
			else {
				valid[indexR][indexC] = 1;
			}
		}

		indexR = x; indexC = y;
		while (indexR > 0 && indexC > 0) {
			indexR--;
			indexC--;
			if ((boardStatus[indexR][indexC] > 'A' &&  boardStatus[indexR][indexC] < 'Z')) break;
			else if ((boardStatus[indexR][indexC] > 'a' &&  boardStatus[indexR][indexC] < 'z')) {
				valid[indexR][indexC] = 1;
				break;
			}
			else {
				valid[indexR][indexC] = 1;
			}
		}

		indexR = x; indexC = y;
		while (indexR > 0) {
			indexR--;
			if ((boardStatus[indexR][indexC] > 'A' &&  boardStatus[indexR][indexC] < 'Z')) break;
			else if ((boardStatus[indexR][indexC] > 'a' &&  boardStatus[indexR][indexC] < 'z')) {
				valid[indexR][indexC] = 1;
				break;
			}
			else {
				valid[indexR][indexC] = 1;
			}
		}

		indexR = x; indexC = y;
		while (indexR < 7) {
			indexR++;
			if ((boardStatus[indexR][indexC] > 'A' &&  boardStatus[indexR][indexC] < 'Z')) break;
			else if ((boardStatus[indexR][indexC] > 'a' &&  boardStatus[indexR][indexC] < 'z')) {
				valid[indexR][indexC] = 1;
				break;
			}
			else {
				valid[indexR][indexC] = 1;
			}
		}

		indexR = x; indexC = y;
		while (indexC > 0) {
			indexC--;
			if ((boardStatus[indexR][indexC] > 'A' &&  boardStatus[indexR][indexC] < 'Z')) break;
			else if ((boardStatus[indexR][indexC] > 'a' &&  boardStatus[indexR][indexC] < 'z')) {
				valid[indexR][indexC] = 1;
				break;
			}
			else {
				valid[indexR][indexC] = 1;
			}
		}

		indexR = x; indexC = y;
		while (indexC < 7) {
			indexC++;
			if ((boardStatus[indexR][indexC] > 'A'&&  boardStatus[indexR][indexC] < 'Z')) break;
			else if ((boardStatus[indexR][indexC] > 'a' &&  boardStatus[indexR][indexC] < 'z')) {
				valid[indexR][indexC] = 1;
				break;
			}
			else {
				valid[indexR][indexC] = 1;
			}
		}
	}

	else if (boardStatus[indexR][indexC] == 'R') {
		indexR = x; indexC = y;
		while (indexR > 0) {
			indexR--;
			if ((boardStatus[indexR][indexC] > 'A' &&  boardStatus[indexR][indexC] < 'Z')) break;
			else if ((boardStatus[indexR][indexC] > 'a' &&  boardStatus[indexR][indexC] < 'z')) {
				valid[indexR][indexC] = 1;
				break;
			}
			else {
				valid[indexR][indexC] = 1;
			}
		}

		indexR = x; indexC = y;
		while (indexR < 7) {
			indexR++;
			if ((boardStatus[indexR][indexC] > 'A' &&  boardStatus[indexR][indexC] < 'Z')) break;
			else if ((boardStatus[indexR][indexC] > 'a' &&  boardStatus[indexR][indexC] < 'z')) {
				valid[indexR][indexC] = 1;
				break;
			}
			else {
				valid[indexR][indexC] = 1;
			}
		}

		indexR = x; indexC = y;
		while (indexC > 0) {
			indexC--;
			if ((boardStatus[indexR][indexC] > 'A' &&  boardStatus[indexR][indexC] < 'Z')) break;
			else if ((boardStatus[indexR][indexC] > 'a' &&  boardStatus[indexR][indexC] < 'z')) {
				valid[indexR][indexC] = 1;
				break;
			}
			else {
				valid[indexR][indexC] = 1;
			}
		}

		indexR = x; indexC = y;
		while (indexC < 7) {
			indexC++;
			if ((boardStatus[indexR][indexC] > 'A'&&  boardStatus[indexR][indexC] < 'Z')) break;
			else if ((boardStatus[indexR][indexC] > 'a' &&  boardStatus[indexR][indexC] < 'z')) {
				valid[indexR][indexC] = 1;
				break;
			}
			else {
				valid[indexR][indexC] = 1;
			}
		}
	}

	else 	if (boardStatus[indexR][indexC] == 'N') {

		if ((boardStatus[indexR + 2][indexC + 1]<'A' || boardStatus[indexR + 2][indexC + 1] > 'Z') && (indexR + 2 < 8) && (indexC + 1 < 8)) {
			valid[indexR + 2][indexC + 1] = 1;
		}

		if ((boardStatus[indexR - 2][indexC + 1]<'A' || boardStatus[indexR - 2][indexC + 1] > 'Z') && (indexR - 2 >= 0) && (indexC + 1 < 8)) {
			valid[indexR - 2][indexC + 1] = 1;
		}

		if ((boardStatus[indexR + 2][indexC - 1]<'A' || boardStatus[indexR + 2][indexC - 1] > 'Z') && (indexR + 2 < 8) && (indexC - 1 >= 0)) {
			valid[indexR + 2][indexC - 1] = 1;
		}

		if ((boardStatus[indexR - 2][indexC - 1]<'A' || boardStatus[indexR - 2][indexC - 1] > 'Z') && (indexR - 2 >= 0) && (indexC - 1 >= 0)) {
			valid[indexR - 2][indexC - 1] = 1;
		}

		if ((boardStatus[indexR + 1][indexC + 2]<'A' || boardStatus[indexR + 1][indexC + 2] > 'Z') && (indexR + 1 < 8) && (indexC + 2 < 8)) {
			valid[indexR + 1][indexC + 2] = 1;
		}

		if ((boardStatus[indexR - 1][indexC + 2]<'A' || boardStatus[indexR - 1][indexC + 2] > 'Z') && (indexR - 1 >= 0) && (indexC + 2 < 8)) {
			valid[indexR - 1][indexC + 2] = 1;
		}

		if ((boardStatus[indexR + 1][indexC - 2]<'A' || boardStatus[indexR + 1][indexC - 2] > 'Z') && (indexR + 1 < 8) && (indexC - 2 >= 0)) {
			valid[indexR + 1][indexC - 2] = 1;
		}

		if ((boardStatus[indexR - 1][indexC - 2]<'A' || boardStatus[indexR - 1][indexC - 2] > 'Z') && (indexR - 1 >= 0) && (indexC - 2 >= 0)) {
			valid[indexR - 1][indexC - 2] = 1;
		}

	}

	else if (boardStatus[indexR][indexC] == 'B') {
		indexR = x; indexC = y;
		while (indexR < 7 && indexC < 7) {
			indexR++;
			indexC++;
			if ((boardStatus[indexR][indexC] > 'A' && boardStatus[indexR][indexC] < 'Z')) break;
			else if ((boardStatus[indexR][indexC] > 'a' &&  boardStatus[indexR][indexC] < 'z')) {
				valid[indexR][indexC] = 1;
				break;
			}
			else {
				valid[indexR][indexC] = 1;
			}
		}

		indexR = x; indexC = y;
		while (indexR < 7 && indexC >0) {
			indexR++;
			indexC--;
			if ((boardStatus[indexR][indexC] > 'A' &&  boardStatus[indexR][indexC] < 'Z')) break;
			else if ((boardStatus[indexR][indexC] > 'a'&&  boardStatus[indexR][indexC] < 'z')) {
				valid[indexR][indexC] = 1;
				break;
			}
			else {
				valid[indexR][indexC] = 1;
			}
		}

		indexR = x; indexC = y;
		while (indexR > 0 && indexC < 7) {
			indexR--;
			indexC++;
			if ((boardStatus[indexR][indexC] > 'A'&&  boardStatus[indexR][indexC] < 'Z')) break;
			else if ((boardStatus[indexR][indexC] > 'a' &&  boardStatus[indexR][indexC] < 'z')) {
				valid[indexR][indexC] = 1;
				break;
			}
			else {
				valid[indexR][indexC] = 1;
			}
		}

		indexR = x; indexC = y;
		while (indexR > 0 && indexC > 0) {
			indexR--;
			indexC--;
			if ((boardStatus[indexR][indexC] > 'A' &&  boardStatus[indexR][indexC] < 'Z')) break;
			else if ((boardStatus[indexR][indexC] > 'a' &&  boardStatus[indexR][indexC] < 'z')) {
				valid[indexR][indexC] = 1;
				break;
			}
			else {
				valid[indexR][indexC] = 1;
			}
		}
	}

	else if (boardStatus[indexR][indexC] == 'P') {

		if (indexR == 1 && boardStatus[indexR + 2][indexC] == '\0') {
			valid[indexR + 2][indexC] = 1;
		}

		if ((boardStatus[indexR + 1][indexC]<'A' || boardStatus[indexR + 1][indexC] > 'Z') && (indexR + 1 < 8)) {
			valid[indexR + 1][indexC] = 1;
		}

		if ((boardStatus[indexR + 1][indexC + 1] > 'a' && boardStatus[indexR + 1][indexC + 1] < 'z') && (indexR + 1 < 8) && (indexC + 1) < 8) {
			valid[indexR + 1][indexC + 1] = 1;
		}

		if ((boardStatus[indexR + 1][indexC - 1] > 'a' && boardStatus[indexR + 1][indexC - 1] < 'z') && (indexR + 1 < 8) && (indexC - 1)) {
			valid[indexR + 1][indexC - 1] = 1;
		}
	}
}
/*
/*
int ifCheckMate() {
	/*if (player1.turn) {
		for (indexX = 0; indexX < 8; indexX++) {
			for (indexY = 0; indexY < 8; indexY++) {
				refreshValid();
				player1ValidSpots(indexX, indexY);
				for (indexR = 0; indexR < 8; indexR++) {
					for (indexC = 0; indexC < 8; indexC++) {
						if (valid[indexR][indexC]) {
							findKings();
							if (boardStatus[indexX][indexY]) {
								char temp = boardStatus[indexX][indexY];
								boardStatus[indexX][indexY] = boardStatus[statusIndexX][statusIndexY];
								boardStatus[statusIndexX][statusIndexY] = '\0';
								findKings();
								if (ifCheck(player1, player2) == 0)
									return 0;
								boardStatus[statusIndexX][statusIndexY] = boardStatus[indexX][indexY];
								boardStatus[indexX][indexY] = temp;
							}

							else {
								boardStatus[indexX][indexY] ^= boardStatus[statusIndexX][statusIndexY] ^= boardStatus[indexX][indexY] ^= boardStatus[statusIndexX][statusIndexY];
								findKings();
								if (ifCheck(player1, player2) == 0)
									return 0;

								boardStatus[indexX][indexY] ^= boardStatus[statusIndexX][statusIndexY] ^= boardStatus[indexX][indexY] ^= boardStatus[statusIndexX][statusIndexY];
							}
						}
					}
				}
			}
		}
	}

	if (player2.turn) {
		for (indexX = 0; indexX < 8; indexX++) {
			for (indexY = 0; indexY < 8; indexY++) {
				refreshValid();
				player2ValidSpots(indexX, indexY);
				for (indexR = 0; indexR < 8; indexR++) {
					for (indexC = 0; indexC < 8; indexC++) {
						if (valid[indexR][indexC]) {
							findKings();
							if (boardStatus[indexX][indexY]) {
								char temp = boardStatus[indexX][indexY];
								boardStatus[indexX][indexY] = boardStatus[statusIndexX][statusIndexY];
								boardStatus[statusIndexX][statusIndexY] = '\0';
								findKings();
								if (ifCheck(player1, player2) == 0)
									return 0;
								boardStatus[statusIndexX][statusIndexY] = boardStatus[indexX][indexY];
								boardStatus[indexX][indexY] = temp;
							}

							else {
								boardStatus[indexX][indexY] ^= boardStatus[statusIndexX][statusIndexY] ^= boardStatus[indexX][indexY] ^= boardStatus[statusIndexX][statusIndexY];
								findKings();
								if (ifCheck(player1, player2) == 0)
									return 0;

								boardStatus[indexX][indexY] ^= boardStatus[statusIndexX][statusIndexY] ^= boardStatus[indexX][indexY] ^= boardStatus[statusIndexX][statusIndexY];
							}
						}
					}
				}
			}
		}
	}*/
	/*if (player1.turn) {
		findKings();
		refreshValid();
		int x = player1.kingX, y = player1.kingY;
		player1ValidSpots(x, y);

		for (indexR = 0; indexR < 8; indexR++) {
			for (indexC = 0; indexC < 8; indexC++) {
				if (valid[indexR][indexC]) {
					player1.kingX = indexR; player1.kingY = indexC;
					if (!ifCheck(player1, player2))
						return 0;
				}
			}
		}
		refreshValid();
	}

	else if (player2.turn) {
		findKings();
		refreshValid();
		int x = player2.kingX, y = player2.kingY;
		player2ValidSpots(x, y);

		for (indexR = 0; indexR < 8; indexR++) {
			for (indexC = 0; indexC < 8; indexC++) {
				if (valid[indexR][indexC]) {
					player2.kingX = indexR; player2.kingY = indexC;
					if (!ifCheck(player1, player2))
						return 0;
				}
			}
		}
		refreshValid();
	}

	return 1;*/
/*
	for (indexX = 0; indexX < 8; indexX++) {
		for (indexY = 0; indexY < 8; indexY++) {
			if (totalValid[indexX][indexY] == 1) return 0;
		}
	}
	return 1;
	*/

void clickOnBoard(Click clickR) {
	if (player1.turn) {
		if (boardStatus[statusIndexX][statusIndexY]>'a' && boardStatus[statusIndexX][statusIndexY] <'z') {
			iSetColor(redR, redG, redB);
			iFilledRectangle(clickR.x, clickR.y, boardEdge, boardEdge);
		}
		player1MarkValidSpots(statusIndexX,statusIndexY);
	}

	else if (player2.turn) {
		if (boardStatus[statusIndexX][statusIndexY] > 'A' && boardStatus[statusIndexX][statusIndexY] < 'Z') {
			iSetColor(redR, redG, redB);
			iFilledRectangle(clickR.x, clickR.y, boardEdge, boardEdge);
		}
		player2MarkValidSpots(statusIndexX, statusIndexY);
	}
}

void clickOnClock(Click clickL) {
	if (player1.clock && clickL.x > 675 && clickL.x < 773 && clickL.y>284 && clickL.y < 338) {
		PlaySound("Media//Clock.wav", 0, 0);
		player1.clock ^= player2.clock ^= player1.clock ^= player2.clock;
		player2.turn = 1;
		player1.turn = 0;
		player1.secs += 5;
		player1.mins += (player1.secs / 60);
		player1.secs %= 60;
	}
	else if (player2.clock && clickL.x > 579 && clickL.x < 675 && clickL.y>284 && clickL.y < 338) {
		PlaySound("Media//Clock.wav", 0, 0);
		player1.clock ^= player2.clock ^= player1.clock ^= player2.clock;
		player2.turn = 0;
		player1.turn = 1;
		player2.secs += 5;
		player2.mins += (player2.secs / 60);
		player2.secs %= 60;
	}
}

void rightClick(Click clickR) {
	if (clickR.x > boardX && clickR.x < (boardX + boardLength) && clickR.y > boardY && clickR.y < (boardY + boardLength)) {

		clickR.x = boardX + ((((clickR.x-boardX) / boardEdge))*boardEdge);
		clickR.y = boardY + ((((clickR.y -boardY) / boardEdge))*boardEdge);

		//if (!boardX) click.x -= boardEdge;
		//if (!boardY) click.y -= boardEdge;

		statusIndexX =7-((clickR.y - boardY) / boardEdge);
		statusIndexY =((clickR.x - boardX) / boardEdge);

		clickOnBoard(clickR);
	}
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


void placeThePiece() {

	indexX = 7 - ((clickL.y - boardY) / boardEdge);
	indexY = ((clickL.x - boardX) / boardEdge);

	statusIndexX = 7 - ((clickR.y - boardY) / boardEdge);
	statusIndexY = ((clickR.x - boardX) / boardEdge);

	if (valid[indexX][indexY]) {

		PlaySound("Media//Piece.wav", 0, 0);

		if (boardStatus[indexX][indexY]) {

			char temp = boardStatus[indexX][indexY];
			boardStatus[indexX][indexY] = boardStatus[statusIndexX][statusIndexY];
			boardStatus[statusIndexX][statusIndexY] = '\0';

			findKings();

			if (ifCheck(player1, player2)) {
				boardStatus[statusIndexX][statusIndexY] = boardStatus[indexX][indexY];
				boardStatus[indexX][indexY] = temp;
			}

			else{
				if (temp == 'K') player1.win = 1;
				else if (temp == 'k') player2.win = 1;
				player1.turn ^= player2.turn ^= player1.turn ^= player2.turn;
			}
		}

		else {
			boardStatus[indexX][indexY] ^= boardStatus[statusIndexX][statusIndexY] ^= boardStatus[indexX][indexY] ^= boardStatus[statusIndexX][statusIndexY];

			findKings();

			if (ifCheck(player1, player2)) {
				boardStatus[indexX][indexY] ^= boardStatus[statusIndexX][statusIndexY] ^= boardStatus[indexX][indexY] ^= boardStatus[statusIndexX][statusIndexY];
			}

			else {
				player1.turn ^= player2.turn ^= player1.turn ^= player2.turn;
			}
		}
	}
}

void leftClick(Click clickL) {
	if (clickL.x > 579 && clickL.y < 773)
		clickOnClock(clickL);
	else if(clickL.x>boardX && clickL.x<=(boardX+boardLength) && clickL.y > boardY && clickL.y <= (boardY + boardLength))
		placeThePiece();
}

void showTheMatch() {
	drawTheTimer(player1, player2);
	drawTheBoard();
	rightClick(clickR);
	drawThePieces();
	if (ifCheck(player1, player2)) {
		iSetColor(255, 255, 255);
		iText(0, 0, "Check!", GLUT_BITMAP_HELVETICA_18);
		//if (ifCheckMate())
			//iText(100, 0, "Checkmate!", GLUT_BITMAP_HELVETICA_18);
	}

	if (player1.win || player2.win)
		menu = gameOver;

}


void showGameOver() {

	drawTheTimer(player1, player2);
	drawTheBoard();
	drawThePieces();

	iSetColor(redR, redG, redB);
	iFilledRectangle(0, windowHeight / 3, windowWidth, windowHeight / 3);
	if (player1.win) {
		iSetColor(whiteR, whiteG, whiteB);
		sprintf_s(player1.nameShow, "%s (%d)", player1.mail, player1.rating);
		iText(boardX + boardLength / 2, boardY + (boardLength / 2)+20, player1.nameShow, GLUT_BITMAP_TIMES_ROMAN_24);
		iText(boardX + boardLength / 2, boardY + (boardLength / 2) - 40+20, "WINS!", GLUT_BITMAP_TIMES_ROMAN_24);
		iText(boardX + boardLength / 2, boardY + (boardLength / 2) - 80+20, "+50", GLUT_BITMAP_TIMES_ROMAN_24);
	}

	else if (player2.win) {
		iSetColor(whiteR, whiteG, whiteB);
		sprintf_s(player2.nameShow, "%s (%d)", player2.mail, player2.rating);
		iText(boardX + boardLength / 2, boardY + (boardLength / 2), player2.nameShow, GLUT_BITMAP_TIMES_ROMAN_24);
		iText(boardX + boardLength / 2, boardY + (boardLength / 2) - 40, "WINS!", GLUT_BITMAP_TIMES_ROMAN_24);
		iText(boardX + boardLength / 2, boardY + (boardLength / 2) - 80, "+50", GLUT_BITMAP_TIMES_ROMAN_24);
	}
}

/*
int canCastle() {

}
*/
