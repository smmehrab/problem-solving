struct Window {
	int width = 1000, height = 600;
}window;

struct Background {
	int colorR = 255, colorG = 255, colorB = 255;
}background;

struct Text {
	int colorR = 179, colorG = 0, colorB = 0;
}text;

struct Board {
	int colorR = 28, colorG = 79, colorB = 142;
	int x = 400, y = 100, width = 250, height = 400;
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
	int score = 0;
	char scoreString[100];
}player1;

struct Player2 {
	int colorR = 179, colorG = 0, colorB = 0;
	int width = 60, height = 10, speed = 10;
	int x = border.initialMidX - (width / 2), y = board.y + board.height + (width / 2);
	int serveCount = 0, turn = 0;
	int score = 0;
	char scoreString[100];
}player2;
/*
struct Menu {
	int main = 1;
	int quickMatch = 1;
	int howToPlay = 0;
	int exitGame = 0;

	int selectPos = 0;

	int selectQuickMatch = 0;
	int selectHowToPlay = 0;
	int selectExit = 0;

	int pause = 0;
	int resumeMatch = 0;
	int restartMatch = 0;
	int backToMainMenu = 0;

}menu;*/

enum Menu {
	mainm, pause, null
}menu;

enum MainMenu {
	quickMatch,
	howToPlay,
	exitGame
}mainMenu;

enum PauseMenu {
	resumeMatch,
	restartMatch,
	backToMainMenu,
}pauseMenu;

int selectPos = 0;

int initialX = 0;
int initialY = 0;

char space = ' ';

int serve = 1;
int inRange = 0;


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
	iText(200, 200, "PRESS 'b' to GO BACK", GLUT_BITMAP_HELVETICA_18);
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

	sprintf_s(player1.scoreString, "Player 1: %d", player1.score);
	iText(window.width * 3 / 4, board.y + ((board.height - board.y) / 4), player1.scoreString, GLUT_BITMAP_TIMES_ROMAN_24);

	sprintf_s(player2.scoreString, "Player 2 : %d", player2.score);
	iText(window.width * 3 / 4, board.y + board.height - board.y, player2.scoreString, GLUT_BITMAP_TIMES_ROMAN_24);
}

takeUserName() {

}
