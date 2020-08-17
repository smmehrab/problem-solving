# include "iGraphics.h"

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
	int speedMoreA = -2;
	int speedMoreD = +2;

	int smashDirection = 1;
	int direction = 1;
}ball;

struct Player1 {
	int colorR = 179, colorG = 0, colorB = 0;
	int width = 60, height = 10, speed = 10;
	int x= border.initialMidX - (width / 2),y= board.y - (width / 2);
	int serveCount=2, turn=1;
	int score=0;
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
	mainm,pause,null
}menu;

enum MainMenu {
	 quickMatch ,
	 howToPlay ,
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


char scoreShow[100];

int leftPart = 0;
int midPart = 1;
int rightPart = 0;

void drawBackground(){
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

void showTheMatch(){
	drawTheTable();
	drawThePlayers();
	drawTheBall();
}

void showTheScore() {
	iSetColor(text.colorR, text.colorG, text.colorB);

	sprintf_s(player1.scoreString, "Player 1: %d", player1.score);
	iText(window.width*3/4, board.y+((board.height-board.y) / 4), player1.scoreString, GLUT_BITMAP_TIMES_ROMAN_24);

	sprintf_s(player2.scoreString, "Player 2 : %d", player2.score);
	iText(window.width*3/4, board.y+board.height-board.y, player2.scoreString, GLUT_BITMAP_TIMES_ROMAN_24);
}
void hitTheBall(int  x){
    if (!serve) {
            ball.smashDirection = x;

            ball.direction = ball.smashDirection;

            inRange = 0;
            ball.speedY *= -1;
            player1.turn ^= player2.turn ^= player1.turn ^= player2.turn;
        }

        else if (serve){
        ball.smashDirection = x;
		ball.direction = ball.smashDirection;

		if (player1.serveCount){
			player1.serveCount--;
			if (!player1.serveCount) player2.serveCount = 2;
		}

		else if (player2.serveCount){
			player2.serveCount--;
			if (!player2.serveCount) player1.serveCount = 2;
		}

		serve = 0;
		player1.turn ^= player2.turn ^= player1.turn ^= player2.turn;
	} }


void iDraw()
{
	iClear();

	drawBackground();

	if (menu == mainm)
		showMainMenu(selectPos);

	else if (menu == pause)
		showPauseMenu(selectPos);

	else if (selectPos == quickMatch) {
		showTheMatch();
		showTheScore();
	}

	else if (selectPos == howToPlay)
		showHowToPlay();


}

/*
	function iMouseMove() is called when the user presses and drags the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouseMove(int mx, int my)
{
	//place your codes here
}

/*
	function iMouse() is called when the user presses/releases the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouse(int button, int state, int mx, int my)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
	      if(mx>=ball.x-5&&mx<=ball.x+5&&inRange){
                hitTheBall(1);
             }
          else if(ball.x>mx&&ball.x-100<=mx&&inRange){
                hitTheBall(0);
            }
	      else if(mx>ball.x&&mx<=ball.x+100&&inRange){
                hitTheBall(2);
             }
          else if(mx>ball.x+100&&inRange){
                hitTheBall(3);
            }
	      else if(mx<ball.x-100&&inRange){
                hitTheBall(4);
             }
		//place your codes here

    }
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here
	}
}

/*
	function iKeyboard() is called whenever the user hits a key in keyboard.
	key- holds the ASCII value of the key pressed.
*/
void iKeyboard(unsigned char key)
{
	if (selectPos==howToPlay && key == 'b') menu = mainm;

	/*else if (selectPos==quickMatch && key == 'p'){
		menu = pause;
		selectPos = resumeMatch;
		iPauseTimer(0);
	}*/

	else if (key == space && (menu == mainm || menu == pause)){

		if (menu==mainm){
			menu=null;
			if (selectPos == exitGame) exit(0);
		}

		else if (menu==pause){
			menu == null;
			if (selectPos==resumeMatch) iResumeTimer(0);
			else if (selectPos == restartMatch) {

				selectPos == quickMatch;
			}
			else if (selectPos==backToMainMenu) menu = mainm;
		}
	}

	else if (key == 's') ball.smashDirection = 1;
	else if (key == 'a') ball.smashDirection = 0;
	else if (key == 'd') ball.smashDirection = 2;

	else if (key == space && inRange == 1)
	{
		ball.direction = ball.smashDirection;

		inRange = 0;
		ball.speedY *= -1;
		player1.turn ^= player2.turn ^= player1.turn ^= player2.turn;
	}

	else if (serve && key == space){

		ball.direction = ball.smashDirection;

		if (player1.serveCount){
			player1.serveCount--;
			if (!player1.serveCount) player2.serveCount = 2;
		}

		else if (player2.serveCount){
			player2.serveCount--;
			if (!player2.serveCount) player1.serveCount = 2;
		}

		serve = 0;
		player1.turn ^= player2.turn ^= player1.turn ^= player2.turn;
	}
}

void iSpecialKeyboard(unsigned char key)
{
	// Main Menu Ups & Downs
	if (menu==mainm){
		if (key == GLUT_KEY_DOWN && selectPos < 2) selectPos++;
		else if (key == GLUT_KEY_UP && selectPos > 0) selectPos--;
	}

	// Pause Menu Ups & Downs
	else if (menu==pause) {
		if (key == GLUT_KEY_DOWN && selectPos < 2) selectPos++;
		else if (key == GLUT_KEY_UP && selectPos > 0) selectPos--;
	}

	// Bat's Movement During Player1's Turn
	else if (player1.turn){
		if (key == GLUT_KEY_RIGHT && player1.x <= board.x + board.width + 10) player1.x += player1.speed;
		else if (key == GLUT_KEY_LEFT && player1.x >= board.x - player1.width - 10) player1.x -= player1.speed;
	}

	// Bat's Movement During Player2's Turn
	else if (player2.turn)
	{
		if (key == GLUT_KEY_RIGHT && player2.x <= board.x + board.width + 10) player2.x += player2.speed;
		else if (key == GLUT_KEY_LEFT && player2.x >= board.x - player2.width - 10) player2.x -= player2.speed;
	}

}

void ballMoving()
{
	if (serve){
		if (player1.serveCount){
			ball.x = player1.x + (player1.width / 2);
			ball.y = player1.y + player1.height;
			if (ball.speedY < 0)  ball.speedY *= -1;
		}

		else{
			ball.x = player2.x + (player2.width / 2);
			ball.y = player2.y - player2.height;
			if (ball.speedY > 0)  ball.speedY *= -1;
		}
	}

	else
	{
		ball.y += ball.speedY;
		if (ball.direction == 0) ball.x += ball.speedA;
		else if (ball.direction == 1) ball.x += ball.speedS;
		else if (ball.direction == 2) ball.x += ball.speedD;
		else if (ball.direction == 3) ball.x += ball.speedMoreD;
		else if (ball.direction == 4) ball.x += ball.speedMoreA;

		if (player1.turn)
		{
			if ((ball.y <= (player1.y + player1.height + 10)) && (ball.y >= player1.y))
			{
				if (ball.x >= player1.x && ball.x <= (player1.x + player1.width)) inRange = 1;
			}
		}

		else if (player2.turn)
		{
			if ((ball.y >= (player2.y - player2.height - 10)) && ball.y <= player2.y)
			{
				if (ball.x >= player2.x && ball.x <= (player2.x + player2.width)) inRange = 1;
			}
		}

		if ((ball.y > player2.y + 10) || (ball.y < player1.y - 10))
		{
			if (player1.serveCount > 0) { player1.turn = 1; player2.turn = 0; }
			else { player1.turn = 0; player2.turn = 1; }
			serve = 1;
			inRange = 0;

			if ((ball.y > player2.y + 10))  player1.score++;
			else if ((ball.y < player1.y - 10))   player2.score++;
		}
	}
}

int main()
{
	iSetTimer(20, ballMoving);
	iInitialize(window.width, window.height, "Table Tennis");
	return 0;
}
