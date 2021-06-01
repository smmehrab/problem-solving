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
	int x= border.initialMidX - (width / 2),y= board.y - (width / 2);
	int serveCount=2, turn=1;
}player1;

struct Player2 {
	int colorR = 179, colorG = 0, colorB = 0;
	int width = 60, height = 10, speed = 10;
	int x = border.initialMidX - (width / 2), y = board.y + board.height + (width / 2);
	int serveCount = 0, turn = 0;
}player2;

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

}menu;

int initialX = 0;
int initialY = 0;

char space = ' ';

int serve = 1;
int inRange = 0;

char scoreShow[200];
int score = 0;
int showResult = 0;

int leftPart = 0;
int midPart = 1;
int rightPart = 0;


void iDraw()
{
	iClear();

	iSetColor(background.colorR, background.colorG, background.colorB);
	iFilledRectangle(initialX, initialY, window.width, window.height);

	if (menu.main)
	{
		if (menu.quickMatch) iShowBMP(initialX, initialY, "Media//QuickMatch.bmp");
		else if (menu.howToPlay) iShowBMP(initialX, initialY, "Media//HowToPlay.bmp");
		else if (menu.exitGame) iShowBMP(initialX, initialY, "Media//Exit.bmp");
	}
	else if (menu.pause)
	{
		if (menu.resumeMatch) iShowBMP(initialX, initialY, "Media//Resume.bmp");
		else if (menu.restartMatch) iShowBMP(initialX, initialY, "Media//Restart.bmp");
		else if (menu.backToMainMenu) iShowBMP(initialX, initialY, "Media//MainMenu.bmp");
	}
	else if (menu.selectQuickMatch)
	{
		iSetColor(board.colorR, board.colorG, board.colorB);
		iFilledRectangle(board.x, board.y, board.width, board.height);

		iSetColor(border.colorR, border.colorG, border.colorB);
		iRectangle(border.x, border.y, border.width, border.height);

		iSetColor(net.colorR, net.colorG, net.colorB);
		iRectangle(net.x, net.y, net.width, net.height);

		iLine(border.initialMidX, border.initialMidY, border.finalMidX, border.finalMidY);

		for (net.ribbonPos = 5; net.ribbonPos < net.width; net.ribbonPos += 5) iLine(net.x + net.ribbonPos, net.y, net.x + net.ribbonPos, net.y + net.height);
		for (net.ribbonPos = 2; net.ribbonPos < net.height; net.ribbonPos += 2) iLine(net.x, net.y + net.ribbonPos, net.x + net.width, net.y + net.ribbonPos);

		iSetColor(0, 0, 0);

		iLine(board.x, net.y, net.x, net.y);
		iLine(net.x, net.y, net.x, net.y + net.height);
		iFilledRectangle(board.x - 5, net.y - 10, 5, 10);

		iLine(board.x + board.width, net.y, net.x + net.width, net.y);
		iLine(net.x + net.width, net.y, net.x + net.width, net.y + net.height);
		iFilledRectangle(board.x + board.width, net.y - 10, 5, 10);

		iSetColor(player1.colorR, player1.colorG, player1.colorB);
		iFilledRectangle(player1.x, player1.y, player1.width, player1.height);

		iSetColor(player2.colorR, player2.colorG, player2.colorB);
		iFilledRectangle(player2.x, player2.y-player2.height, player2.width, player2.height);

		iSetColor(ball.colorR, ball.colorG, ball.colorB);
		iFilledCircle(ball.x, ball.y, ball.radius, 100);
	}

	else if (menu.selectHowToPlay)
	{
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
	if (menu.selectHowToPlay == 1 && key == 'b') menu.main = 1;

	else if (menu.selectQuickMatch == 1 && key == 'p')
	{
		menu.pause = 1;
		menu.resumeMatch = 1;
		menu.selectQuickMatch = 0;
		iPauseTimer(0);
	}


	else if (key == 'w' && (menu.main == 1 || menu.pause == 1))
	{
		if (menu.main)
		{
			menu.main = 0;
			menu.selectPos = 0;
			if (menu.quickMatch)
			{
				menu.selectQuickMatch = 1;
				menu.selectHowToPlay = 0;
			}
			else if (menu.howToPlay)
			{
				menu.selectQuickMatch = 0;
				menu.selectHowToPlay = 1;
			}
			else if (menu.exitGame) exit(0);
		}
		else if (menu.pause)
		{
			menu.pause = 0;
			menu.selectPos = 0;
			if (menu.resumeMatch) iResumeTimer(0);
			else if (menu.restartMatch) menu.selectQuickMatch = 1;
			else if (menu.backToMainMenu) menu.main = 1;
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

	else if (serve && key == space)
	{
		ball.direction = ball.smashDirection;
		if (player1.serveCount)
		{
			player1.serveCount--;
			if (!player1.serveCount) player2.serveCount = 2;
		}

		else if (player2.serveCount)
		{
			player2.serveCount--;
			if (!player2.serveCount) player1.serveCount = 2;
		}
		serve = 0;
		player1.turn ^= player2.turn ^= player1.turn ^= player2.turn;
	}



}

void iSpecialKeyboard(unsigned char key)
{
	if (menu.main) // Main Menu Ups & Downs
	{
		if (key == GLUT_KEY_DOWN && menu.selectPos < 2) menu.selectPos++;
		else if (key == GLUT_KEY_UP && menu.selectPos > 0) menu.selectPos--;

		if (menu.selectPos == 0)
		{
			menu.quickMatch = 1;
			menu.howToPlay = 0;
			menu.exitGame = 0;
		}

		else if (menu.selectPos == 1)
		{
			menu.quickMatch = 0;
			menu.howToPlay = 1;
			menu.exitGame = 0;
		}

		else if (menu.selectPos == 2)
		{
			menu.quickMatch = 0;
			menu.howToPlay = 0;
			menu.exitGame = 1;
		}
	}
	else if (menu.pause) // Pause Menu Ups & Downs
	{
		if (key == GLUT_KEY_DOWN && menu.selectPos < 2) menu.selectPos++;
		else if (key == GLUT_KEY_UP && menu.selectPos > 0) menu.selectPos--;

		if (menu.selectPos == 0)
		{
			menu.resumeMatch = 1;
			menu.restartMatch = 0;
			menu.backToMainMenu = 0;
		}

		else if (menu.selectPos == 1)
		{
			menu.resumeMatch = 0;
			menu.restartMatch = 1;
			menu.backToMainMenu = 0;
		}

		else if (menu.selectPos == 2)
		{
			menu.resumeMatch = 0;
			menu.restartMatch = 0;
			menu.backToMainMenu = 1;
		}
	}

	else if (player1.turn) // Bat's Movement During My Turn
	{
		if (key == GLUT_KEY_RIGHT && player1.x <= board.x + board.width + 10) player1.x += player1.speed;
		else if (key == GLUT_KEY_LEFT && player1.x >= board.x - player1.width - 10) player1.x -= player1.speed;
	}
	else if (player2.turn) // Bat's Movement During Pc Turn
	{
		if (key == GLUT_KEY_RIGHT && player2.x <= board.x + board.width + 10) player2.x += player2.speed;
		else if (key == GLUT_KEY_LEFT && player2.x >= board.x - player2.width - 10) player2.x -= player2.speed;
	}
}

void ballMoving()
{
	if (serve)
	{
		if (player1.serveCount)
		{
			ball.x = player1.x + (player1.width / 2);
			ball.y = player1.y + player1.height;
			if (ball.speedY < 0)  ball.speedY *= -1;
		}

		else
		{
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
		}
	}
}

int main()
{
	iSetTimer(20, ballMoving);
	iInitialize(window.width, window.height, "Table Tennis");
	return 0;
}
