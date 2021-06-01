/*
************************************************
username    :   smmehrab
fullname    :   s.m.mehrabul islam
email       :   mehrab.24csedu.001@gmail.com
institute   :   university of dhaka, bangladesh
session     :   2017-2018
************************************************
*/
struct Window {
	int width =1000, height=600;
}window;

struct Background {
	int colorR = 255, colorG = 255, colorB = 255;
}background;

struct Text {
	int colorR = 179, colorG = 0, colorB = 0;
}text;

struct Board {
	int colorR = 28, colorG = 79, colorB = 142;
	int x = 400, y = 100, width =250, height = 400;
}board;

struct Border {
	int colorR = 238, colorG = 238, colorB = 238;
	int x = board.x + 5;
	int y = board.y + 5;
	int width = board.width - 10;
	int height = board.height - 10;

	int initialMidX = x + (width / 2);
	int initialMidY = y;
	int finalMidX = initialMidX;
	int finalMidY = initialMidY + height;
}border;

struct Net {
	int colorR = 238, colorG = 238, colorB = 238;
	int x = board.x - 10;
	int y = board.y + (board.height / 2);
	int width = board.width + 20;
	int height = 15;
	int ribbonPos = 5;
}net;

struct Ball {
	int colorR = 255, colorG = 174, colorB = 0;
	int radius = 5;
	int x = border.initialMidX;
	int y = board.y;

	int speedY = 5;
	int speedA = -1;
	int speedS = 0;
	int speedD = +1;

	int smashDirection = 1;
	int direction = 1;
}ball;

struct Player1 {
	int colorR = 179, colorG = 0, colorB = 0;
	int width = 60, height = 10, speed = 10;
	int x = border.initialMidX - (width / 2), y = board.y - (width / 2);
	int serveCount = 2, turn = 1;
	int score[3] = { 0 };
	char scoreString[3][100] = { "-","-","-" };
	char name[100], rolls[10];
	int roll, len, indexN = 0, indexR = 0;
	int scoreX = (window.width * 3 / 4) - 60;
	int scoreY= board.y + ((board.height - board.y) / 4);
	int set = 0;
	char nameRoll[100];
}player1;

struct Player2 {
	int colorR = 179, colorG = 0, colorB = 0;
	int width = 60, height = 10, speed = 10;
	int x = border.initialMidX - (width / 2), y = board.y + board.height + (width / 2);
	int serveCount = 0, turn = 0;
	int score[3] = { 0 };
	char scoreString[3][100] = {"-","-","-"};
	char name[100],rolls[10];
	int roll,len, indexN = 0, indexR = 0;
	int scoreX = (window.width * 3 / 4)-60;
	int scoreY = board.y + board.height - board.y;
	int set = 0;
	char nameRoll[100];
}player2;

enum Menu {
	mainm, pause, null, instructions,
	info1,info2
}menu;

enum MainMenu {
	quickMatch,
	howToPlay,
	exitGame,
};

enum PauseMenu {
	resumeMatch,
	restartMatch,
	backToMainMenu,
};

enum info1 {
	Name1, Roll1, OK1
};

enum info2 {
	Name2, Roll2, OK2
};

int initialX = 0;
int initialY = 0;

int scoreIndex = 0;

#define space ' '
#define enter '\r'
#define esc 27

int selectPos = 0;
int ind;
int set = 0;

int serve = 1;
int inRange = 0;

int gameOver = 0;


void drawBackground() {
	iSetColor(background.colorR, background.colorG, background.colorB);
	iFilledRectangle(initialX, initialY, window.width, window.height);
}

void showMainMenu(int selectPos) {
	if (selectPos == quickMatch) iShowBMP(initialX, initialY, "Media//QuickMatch.bmp");
	else if (selectPos == howToPlay) iShowBMP(initialX, initialY, "Media//HowToPlay.bmp");
	else if (selectPos == exitGame) iShowBMP(initialX, initialY, "Media//Exit.bmp");
}

void showPauseMenu(int selectPos) {
	if (selectPos == resumeMatch) iShowBMP(initialX, initialY, "Media//Resume.bmp");
	else if (selectPos == restartMatch) iShowBMP(initialX, initialY, "Media//Restart.bmp");
	else if (selectPos == backToMainMenu) iShowBMP(initialX, initialY, "Media//MainMenu.bmp");
}

void showHowToPlay() {
	iSetColor(text.colorR, text.colorG, text.colorB);

	iText(200, 500, "INSTRUCTIONS:", GLUT_BITMAP_HELVETICA_18);
	iText(240, 460, "- Hit Ulala to Play Lalala", GLUT_BITMAP_HELVETICA_18);
	iText(240, 440, "- Hit Ulala to Play Lalala", GLUT_BITMAP_HELVETICA_18);
	iText(240, 420, "- Hit Ulala to Play Lalala", GLUT_BITMAP_HELVETICA_18);
	iText(240, 400, "- Hit Ulala to Play Lalala", GLUT_BITMAP_HELVETICA_18);
	iText(240, 380, "- Hit Ulala to Play Lalala", GLUT_BITMAP_HELVETICA_18);
	iText(240, 360, "- Hit Ulala to Play Lalala", GLUT_BITMAP_HELVETICA_18);
	iText(240, 340, "- Hit Ulala to Play Lalala", GLUT_BITMAP_HELVETICA_18);
}

void drawTheBoard() {
	iSetColor(board.colorR, board.colorG, board.colorB);
	iFilledRectangle(board.x, board.y, board.width, board.height);
}

void drawTheBorder() {
	iSetColor(border.colorR, border.colorG, border.colorB);
	iRectangle(border.x, border.y, border.width, border.height);
	iLine(border.initialMidX, border.initialMidY, border.finalMidX, border.finalMidY);
}

void drawTheNet() {
	iSetColor(net.colorR, net.colorG, net.colorB);
	iRectangle(net.x, net.y, net.width, net.height);

	for (net.ribbonPos = 5; net.ribbonPos < net.width; net.ribbonPos += 5) iLine(net.x + net.ribbonPos, net.y, net.x + net.ribbonPos, net.y + net.height);
	for (net.ribbonPos = 2; net.ribbonPos < net.height; net.ribbonPos += 2) iLine(net.x, net.y + net.ribbonPos, net.x + net.width, net.y + net.ribbonPos);
}

void drawTheNetHolder() {
	iSetColor(0, 0, 0);

	iLine(board.x, net.y, net.x, net.y);
	iLine(net.x, net.y, net.x, net.y + net.height);
	iFilledRectangle(board.x - 5, net.y - 10, 5, 10);

	iLine(board.x + board.width, net.y, net.x + net.width, net.y);
	iLine(net.x + net.width, net.y, net.x + net.width, net.y + net.height);
	iFilledRectangle(board.x + board.width, net.y - 10, 5, 10);
}

void drawTheTable() {

	drawTheBoard();
	drawTheBorder();
	drawTheNet();
	drawTheNetHolder();
}

void drawThePlayers() {
	iSetColor(player1.colorR, player1.colorG, player1.colorB);
	iFilledRectangle(player1.x, player1.y, player1.width, player1.height);

	iSetColor(player2.colorR, player2.colorG, player2.colorB);
	iFilledRectangle(player2.x, player2.y - player2.height, player2.width, player2.height);
}

void drawTheBall() {
	iSetColor(ball.colorR, ball.colorG, ball.colorB);
	iFilledCircle(ball.x, ball.y, ball.radius, 100);
}

void showTheMatch() {
	drawTheTable();
	drawThePlayers();
	drawTheBall();
}

void showTheScore() {
	iSetColor(text.colorR, text.colorG, text.colorB);

	sprintf_s(player1.nameRoll, "%s (%s)", player1.name, player1.rolls);
	iText(player1.scoreX, player1.scoreY+40, player1.nameRoll, GLUT_BITMAP_TIMES_ROMAN_24);

	sprintf_s(player2.nameRoll, "%s (%s)", player2.name, player2.rolls);
	iText(player2.scoreX, player2.scoreY+40, player2.nameRoll, GLUT_BITMAP_TIMES_ROMAN_24);

	if (player1.set + player2.set > set) {
		set++;
		sprintf_s(player1.scoreString[scoreIndex-1], " %d", player1.score[scoreIndex-1]);
		sprintf_s(player2.scoreString[scoreIndex-1], " %d", player2.score[scoreIndex-1]);
	}
	else {
		sprintf_s(player1.scoreString[scoreIndex], " %d", player1.score[scoreIndex]);
		sprintf_s(player2.scoreString[scoreIndex], " %d", player2.score[scoreIndex]);
	}

	for (ind = 0; ind < 3; ind++) {
		iRectangle(player1.scoreX - 5 + (ind * 50), player1.scoreY-5, 30, 30);
		iText(player1.scoreX+(ind*50), player1.scoreY, player1.scoreString[ind], GLUT_BITMAP_TIMES_ROMAN_24);
		iRectangle(player2.scoreX - 5 + (ind * 50), player2.scoreY-5, 30, 30);
		iText(player2.scoreX+(ind*50), player2.scoreY, player2.scoreString[ind], GLUT_BITMAP_TIMES_ROMAN_24);
	}
	if (player1.set == 2) {
		iFilledRectangle(0, 250, 1000, 100);
		iSetColor(255, 255, 255);
		sprintf_s(player1.nameRoll, "%s Wins!", player1.name);
		iText(500, 300, player1.nameRoll, GLUT_BITMAP_TIMES_ROMAN_24);
		gameOver = 1;
	}
	else if (player2.set == 2) {
		iFilledRectangle(0, 250, 1000, 100);
		iSetColor(255, 255, 255);
		sprintf_s(player2.nameRoll, "%s Wins!", player2.name);
		iText(500, 300, player2.nameRoll, GLUT_BITMAP_TIMES_ROMAN_24);
		gameOver = 1;
	}
}

void showPlayer1Info() {
	if (selectPos == Name1) iShowBMP(initialX, initialY, "Media//Player1InputName.bmp");
	else if (selectPos == Roll1) iShowBMP(initialX, initialY, "Media//Player1InputRoll.bmp");
	else if (selectPos == OK1) iShowBMP(initialX, initialY, "Media//Player1OK.bmp");

	iSetColor(text.colorR, text.colorG, text.colorB);
	iText(530, 353, player1.name, GLUT_BITMAP_TIMES_ROMAN_24);
	iText(555, 265, player1.rolls, GLUT_BITMAP_TIMES_ROMAN_24);
}

void showPlayer2Info() {
	if (selectPos == Name2)	iShowBMP(initialX, initialY, "Media//Player2InputName.bmp");
	else if (selectPos == Roll2) iShowBMP(initialX, initialY, "Media//Player2InputRoll.bmp");
	else if (selectPos == OK2) iShowBMP(initialX, initialY, "Media//Player2OK.bmp");

	iSetColor(text.colorR, text.colorG, text.colorB);
	iText(530, 353, player2.name, GLUT_BITMAP_TIMES_ROMAN_24);
	iText(555, 265, player2.rolls, GLUT_BITMAP_TIMES_ROMAN_24);
}

void takePlayer1Info(char key, int selectPos) {
	if (selectPos == Name1) {
		if (key != '\b') {
			player1.name[player1.indexN++] = key;
			player1.name[player1.indexN] = '\0';
		}
		else {
			if (player1.indexN <= 0)
				player1.indexN = 0;
			else
				player1.indexN--;
			player1.name[player1.indexN] = '\0';
		}
	}
	else if (selectPos == Roll1) {
		if (key != '\b') {
			player1.rolls[player1.indexR++] = key;
			player1.rolls[player1.indexR] = '\0';
		}
		else {
			if (player1.indexR <= 0)
				player1.indexR = 0;
			else
				player1.indexR--;
			player1.rolls[player1.indexR] = '\0';
		}
	}
}

void takePlayer2Info(char key, int selectPos) {
	if (selectPos == Name2) {
		if (key != '\b') {
			player2.name[player2.indexN++] = key;
			player2.name[player2.indexN] = '\0';
		}
		else {
			if (player2.indexN <= 0)
				player2.indexN = 0;
			else
				player2.indexN--;
			player2.name[player2.indexN] = '\0';
		}
	}
	else if (selectPos == Roll1) {
		if (key != '\b') {
			player2.rolls[player2.indexR++] = key;
			player2.rolls[player2.indexR] = '\0';
		}
		else {
			if (player2.indexR <= 0)
				player2.indexR = 0;
			else
				player2.indexR--;
			player2.rolls[player2.indexR] = '\0';
		}
	}
}

void doServe() {
	ball.direction = ball.smashDirection;

	if (player1.serveCount) {
		player1.serveCount--;
		if (!player1.serveCount) player2.serveCount = 2;
	}

	else if (player2.serveCount) {
		player2.serveCount--;
		if (!player2.serveCount) player1.serveCount = 2;
	}

	serve = 0;
	player1.turn ^= player2.turn ^= player1.turn ^= player2.turn;
}

void doSmash() {
	ball.direction = ball.smashDirection;
	inRange = 0;
	ball.speedY *= -1;
	player1.turn ^= player2.turn ^= player1.turn ^= player2.turn;
}

void escFunction(Menu *menu,int *selectPos) {
	if (*menu == null) {
		iPauseTimer(0);
		*menu = pause;
		*selectPos = resumeMatch;
	}

	else if (*menu == pause) {
		*menu = null;
		iResumeTimer(0);
	}

	else if (*menu == info2) {
		*menu = info1;
		*selectPos = Name1;
	}

	else if (*menu == info1) {
		*menu = mainm;
		*selectPos = quickMatch;
	}

	else if (*menu == instructions) {
		*menu = mainm;
		*selectPos = quickMatch;
	}
}

void enterFunction(Menu *menu, int *selectPos){
	if (gameOver) {
		*menu = mainm;
		gameOver = 0;
	}
	else if (*menu == mainm) {
		if (*selectPos == quickMatch) {
			*menu = info1;
			*selectPos = Name1;
		}
		else if (*selectPos == howToPlay) *menu = instructions;
		else if (*selectPos == exitGame) exit(0);
	}

	else if (*menu == info1) {
		if (*selectPos == OK1) {
			*menu = info2;
			*selectPos = Name2;
		}
		else if (*selectPos == Name1) (*selectPos)++;
		else if (*selectPos == Roll1) (*selectPos)++;
	}

	else if (*menu == info2) {
		if (*selectPos == OK2) *menu = null;
		else if (*selectPos == Name2) (*selectPos)++;
		else if (*selectPos == Roll2) (*selectPos)++;
	}

	else if (*menu == pause) {
		*menu = null;
		if (*selectPos == resumeMatch) iResumeTimer(0);
		else if (*selectPos == restartMatch) {

			*selectPos = quickMatch;
		}
		else if (*selectPos == backToMainMenu) *menu = mainm;
	}
}

