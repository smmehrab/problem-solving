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

struct Window{
    int width = 1000,height = 600;
}window;

struct Background{
    int colorR = 255,colorG = 255,colorB = 255;
}background;

struct Text{
    int colorR = 179,colorG = 0,colorB = 0;
}text;

struct Board{
    int colorR = 28,colorG = 79,colorB = 142;
    int x = 400,y = 100,width = 250,height = 400;
}board;

struct Border{
    int borderColorR = 238,colorG = 238,colorB = 238;
    int x = board.x + 5;
    int y = board.y + 5;
    int width = board.width - 10;
    int height = board.height - 10;
}border;

struct Net{
    int colorR = 238,colorG = 238,colorB = 238;
    int x = board.x - 10;
    int y = board.y + (board.height / 2);
    int width = board.width + 20;
    int height = 15;
}net;

int ribbonPos = 5;

int midLineInitialX = borderX + (borderWidth / 2);
int midLineInitialY = borderY;
int midLineFinalX = midLineInitialX;
int midLineFinalY = midLineInitialY + borderHeight;


struct Ball{
    int colorR = 255,colorG = 174,colorB = 0;
    int radius = 5;
    int x = midLineInitialX;
    int y = boardY;

    int speedY = 5;
    int speedA = -1;
    int speedS = 0;
    int speedD = +1;

    int smashDirection = 1;
    int direction = 1;
}ball;

struct Bat{
    int colorR = 179,colorG = 0,colorB = 0;
    int width = 60,height = 10,speed = 10;
    int x,y;
}bat;


struct Player1{
    bat bat;
    player1.bat.x = midLineInitialX - (bat.width / 2);
    player1.bat.y = board.y - (bat.width / 2);
    int serveCount=2,turn=1;
}player1;

struct Player2{
    bat bat;
    player2.bat.x = midLineInitialX - (bat.width / 2);
    player2.bat.y = board.y + board.height + (bat.width / 2);
    int serveCount=0,turn=0;
}player2;


int serve = 1;


char scoreShow[200];
int score = 0;
int showResult = 0;

struct Menu{
    int main=1;
    int quickMatch=1;
    int howToPlay=0;
    int exitGame=0;

    int selectPos = 0;

    int selectQuickMatch = 0;
    int selectHowToPlay = 0;
    int selectExit = 0;

    int pause = 0;
    int resumeMatch = 0;
    int restartMatch = 0;
    int backToMainMenu = 0;

}menu;

int initialX=0;
int initialY=0;

char space = ' ';
int inRange = 0;

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

		iLine(midLineInitialX, midLineInitialY, midLineFinalX, midLineFinalY);

		for (ribbonPos = 5; ribbonPos < net.width; ribbonPos += 5) iLine(net.x + ribbonPos, net.y, net.x + ribbonPos, net.y + net.height);
		for (ribbonPos = 2; ribbonPos < net.height; ribbonPos += 2) iLine(net.x, net.y + ribbonPos, net.x + netWidth, net.y + ribbonPos);

		iSetColor(0, 0, 0);

		iLine(board.x, net.y, net.x, net.y);
		iLine(net.x, net.y, net.x, net.y + net.height);
		iFilledRectangle(board.x - 5, net.y - 10, 5, 10);

		iLine(board.x + board.width, net.y, net.x + net.width, net.y);
		iLine(net.x + net.width, net.y, net.x + net.width, net.y + net.height);
		iFilledRectangle(board.x + board.width, net.y - 10, 5, 10);

		iSetColor(player2.bat.colorR, player2.bat.colorG, player2.bat.colorB);
		iFilledRectangle(player2.bat.x, player2.bat.y - bat.height, bat.width, bat.height);

		iSetColor(player1.bat.colorR, player1.bat.colorG, player1.bat.colorB);
		iFilledRectangle(player1.bat.x, player1.bat.y, bat.width, bat.height);

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
		direction = smashDirection;

		inRange = 0;
		ball.speedY *= -1;
		player1.turn ^= player2.turn ^= player1.turn ^= player2.turn;
	}

	else if (serve && key == space)
	{
		direction = smashDirection;
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

		if (menu.selectPos==0)
		{
			menu.quickMatch = 1;
			menu.howToPlay = 0;
			menu.exitGame = 0;
		}

		else if (menu.selectPos==1)
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
		if (key == GLUT_KEY_RIGHT && player1.bat.x <= board.x + board.width + 10) player1.bat.x += bat.speed;
		else if (key == GLUT_KEY_LEFT && player1.bat.x >= board.x - bat.width - 10) player1.bat.x -= bat.speed;
	}
	else if (player2.turn) // Bat's Movement During Pc Turn
	{
		if (key == GLUT_KEY_RIGHT && player2.bat.x <= board.x + board.width + 10) player2.bat.x += bat.speed;
		else if (key == GLUT_KEY_LEFT && player2.bat.x >= board.x - bat.width - 10) player2.bat.x -= bat.speed;
	}
}

void ballMoving()
{
	if (serve)
	{
		if (player1.serveCount)
		{
			ball.x = player1.bat.x + (bat.width / 2);
			ball.y = player1.bat.x + bat.height;
			if (ball.speedY < 0)  ball.speedY *= -1;
		}

		else
		{
			ball.x = player2.bat.x + (bat.width / 2);
			ball.y = player2.bat.x - bat.height;
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
			if ((ball.y <= (player1.bat.y + bat.height + 10)) && (ball.y >= player1.bat.y))
			{
				if (ball.x >= player1.bat.x && ball.x <= (player1.bat.x + bat.width)) inRange = 1;
			}
		}

		else if (player2.turn)
		{
			if ((ball.y >= (player2.bat.y - bat.height - 10)) && ball.y <= player2.bat.y)
			{
				if (ball.x >= player2.bat.x && ball.x <= (player2.bat.x + bat.width)) inRange = 1;
			}
		}

		if ((ball.y > player2.bat.y + 10) || (ball.y < player1.bat.y - 10))
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
