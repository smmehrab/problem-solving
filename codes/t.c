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

int backgroundColorR = 255;
int backgroundColorG = 255;
int backgroundColorB = 255;

int textColorR = 179;
int textColorG = 0;
int textColorB = 0;

int boardColorR = 28;
int boardColorG = 79;
int boardColorB = 142;

int borderColorR = 238;
int borderColorG = 238;
int borderColorB = 238;

int netColorR = 238;
int netColorG = 238;
int netColorB = 238;

int ballColorR = 255;
int ballColorG = 174;
int ballColorB = 0;

int myBatColorR = 179;
int myBatColorG = 0;
int myBatColorB = 0;

int pcBatColorR = 179;
int pcBatColorG = 0;
int pcBatColorB = 0;

int initialX = 0;
int initialY = 0;

int windowWidth = 1000;
int windowHeight = 600;

int boardX = 400;
int boardY = 100;
int boardWidth = 250;
int boardHeight = 400;

int borderX = boardX + 5;
int borderY = boardY + 5;
int borderWidth = boardWidth - 10;
int borderHeight = boardHeight - 10;

int netX = boardX - 10;
int netY = boardY + (boardHeight / 2);
int netWidth = boardWidth + 20;
int netHeight = 15;

int ribbonPos = 5;

int midLineInitialX = borderX + (borderWidth / 2);
int midLineInitialY = borderY;
int midLineFinalX = midLineInitialX;
int midLineFinalY = midLineInitialY + borderHeight;

int ballRadius = 5;

int ballX = midLineInitialX;
int ballY = boardY;

int serve = 1;
int myServe = 2;
int pcServe = 0;
int myTurn = 1;
int pcTurn = 0;


int ballSpeedY = 5;
int ballSpeedA = -1;
int ballSpeedS = 0;
int ballSpeedD = +1;

int batWidth = 60;
int batHeight = 10;
int batSpeed = 10;

int myBatX = midLineInitialX - (batWidth / 2);
int myBatY = boardY - (batWidth / 2);

int pcBatX = midLineInitialX - (batWidth / 2);
int pcBatY = boardY + boardHeight + (batWidth / 2);

char scoreShow[200];
int score = 0;
int showResult = 0;

int mainMenu = 1;

int quickMatch = 1;
int howToPlay = 0;
int exitGame = 0;

int selectPos = 0;

int selectQuickMatch = 0;
int selectHowToPlay = 0;
int selectExit = 0;

int pauseMenu = 0;

int resumeMatch = 0;
int restartMatch = 0;
int backToMainMenu = 0;

char space = ' ';
int inRange = 0;

int smashDirection = 1;
int direction = 1;

int leftPart = 0;
int midPart = 1;
int rightPart = 0;


void iDraw()
{
	iClear();

	iSetColor(backgroundColorR, backgroundColorG, backgroundColorB);
	iFilledRectangle(initialX, initialY, windowWidth, windowHeight);

	if (mainMenu)
	{
		if (quickMatch) iShowBMP(initialX, initialY, "Media//QuickMatch.bmp");
		else if (howToPlay) iShowBMP(initialX, initialY, "Media//HowToPlay.bmp");
		else if (exitGame) iShowBMP(initialX, initialY, "Media//Exit.bmp");
	}
	else if (pauseMenu)
	{
		if (resumeMatch) iShowBMP(initialX, initialY, "Media//Resume.bmp");
		else if (restartMatch) iShowBMP(initialX, initialY, "Media//Restart.bmp");
		else if (backToMainMenu) iShowBMP(initialX, initialY, "Media//MainMenu.bmp");
	}
	else if (selectQuickMatch)
	{
		iSetColor(boardColorR, boardColorG, boardColorB);
		iFilledRectangle(boardX, boardY, boardWidth, boardHeight);

		iSetColor(borderColorR, borderColorG, borderColorB);
		iRectangle(borderX, borderY, borderWidth, borderHeight);

		iSetColor(netColorR, netColorG, netColorB);
		iRectangle(netX, netY, netWidth, netHeight);

		iLine(midLineInitialX, midLineInitialY, midLineFinalX, midLineFinalY);

		for (ribbonPos = 5; ribbonPos < netWidth; ribbonPos += 5) iLine(netX + ribbonPos, netY, netX + ribbonPos, netY + netHeight);
		for (ribbonPos = 2; ribbonPos < netHeight; ribbonPos += 2) iLine(netX, netY + ribbonPos, netX + netWidth, netY + ribbonPos);

		iSetColor(0, 0, 0);

		iLine(boardX, netY, netX, netY);
		iLine(netX, netY, netX, netY + netHeight);
		iFilledRectangle(boardX - 5, netY - 10, 5, 10);

		iLine(boardX + boardWidth, netY, netX + netWidth, netY);
		iLine(netX + netWidth, netY, netX + netWidth, netY + netHeight);
		iFilledRectangle(boardX + boardWidth, netY - 10, 5, 10);

		iSetColor(pcBatColorR, pcBatColorG, pcBatColorB);
		iFilledRectangle(pcBatX, pcBatY - batHeight, batWidth, batHeight);

		iSetColor(myBatColorR, myBatColorG, myBatColorB);
		iFilledRectangle(myBatX, myBatY, batWidth, batHeight);

		iSetColor(ballColorR, ballColorG, ballColorB);
		iFilledCircle(ballX, ballY, ballRadius, 100);
	}
	else if (selectHowToPlay)
	{
		iSetColor(textColorR, textColorG, textColorB);

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
	if (selectHowToPlay == 1 && key == 'b') mainMenu = 1;

	else if (selectQuickMatch == 1 && key == 'p')
	{
		pauseMenu = 1;
		resumeMatch = 1;
		selectQuickMatch = 0;
		iPauseTimer(0);
	}


	else if (key == 'w' && (mainMenu == 1 || pauseMenu == 1))
	{
		if (mainMenu == 1)
		{
			mainMenu = 0;
			selectPos = 0;
			if (quickMatch)
			{
				selectQuickMatch = 1;
				selectHowToPlay = 0;
			}
			else if (howToPlay)
			{
				selectQuickMatch = 0;
				selectHowToPlay = 1;
			}
			else if (exitGame) exit(0);
		}
		else if (pauseMenu)
		{
			pauseMenu = 0;
			selectPos = 0;
			if (resumeMatch) iResumeTimer(0);
			else if (restartMatch) selectQuickMatch = 1;
			else if (backToMainMenu) mainMenu = 1;
		}
	}

	else if (key == 's') smashDirection = 1;
	else if (key == 'a') smashDirection = 0;
	else if (key == 'd') smashDirection = 2;

	else if (key == space && inRange == 1)
	{
		direction = smashDirection;

		inRange = 0;
		ballSpeedY *= -1;
		myTurn ^= pcTurn ^= myTurn ^= pcTurn;
	}

	else if (serve == 1 && key == space)
	{
		direction = smashDirection;
		if (myServe)
		{
			myServe--;
			if (myServe == 0) pcServe = 2;
		}

		else if (pcServe)
		{
			pcServe--;
			if (pcServe == 0) myServe = 2;
		}
		serve = 0;
		myTurn ^= pcTurn ^= myTurn ^= pcTurn;
	}



}

void iSpecialKeyboard(unsigned char key)
{
	if (mainMenu) // Main Menu Ups & Downs
	{
		if (key == GLUT_KEY_DOWN && selectPos < 2) selectPos++;
		else if (key == GLUT_KEY_UP && selectPos > 0) selectPos--;

		if (selectPos == 0)
		{
			quickMatch = 1; howToPlay = 0; exitGame = 0;
		}

		else if (selectPos == 1)
		{
			quickMatch = 0; howToPlay = 1; exitGame = 0;
		}

		else if (selectPos == 2)
		{
			quickMatch = 0; howToPlay = 0; exitGame = 1;
		}
	}
	else if (pauseMenu) // Pause Menu Ups & Downs
	{
		if (key == GLUT_KEY_DOWN && selectPos < 2) selectPos++;
		else if (key == GLUT_KEY_UP && selectPos > 0) selectPos--;

		if (selectPos == 0)
		{
			resumeMatch = 1; restartMatch = 0; backToMainMenu = 0;
		}

		else if (selectPos == 1)
		{
			resumeMatch = 0; restartMatch = 1; backToMainMenu = 0;
		}

		else if (selectPos == 2)
		{
			resumeMatch = 0; restartMatch = 0; backToMainMenu = 1;
		}
	}

	else if (myTurn) // Bat's Movement During My Turn
	{
		if (key == GLUT_KEY_RIGHT && myBatX <= boardX + boardWidth + 10) myBatX += batSpeed;
		else if (key == GLUT_KEY_LEFT && myBatX >= boardX - batWidth - 10) myBatX -= batSpeed;
	}
	else if (pcTurn) // Bat's Movement During Pc Turn
	{
		if (key == GLUT_KEY_RIGHT && pcBatX <= boardX + boardWidth + 10) pcBatX += batSpeed;
		else if (key == GLUT_KEY_LEFT && pcBatX >= boardX - batWidth - 10) pcBatX -= batSpeed;
	}
}

void ballMoving()
{
	if (serve)
	{
		if (myServe)
		{
			ballX = myBatX + (batWidth / 2);
			ballY = myBatY + batHeight;
			if (ballSpeedY < 0)  ballSpeedY *= -1;
		}

		else
		{
			ballX = pcBatX + (batWidth / 2);
			ballY = pcBatY - batHeight;
			if (ballSpeedY > 0)  ballSpeedY *= -1;
		}
	}

	else
	{
		ballY += ballSpeedY;
		if (direction == 0) ballX += ballSpeedA;
		else if (direction == 1) ballX += ballSpeedS;
		else if (direction == 2) ballX += ballSpeedD;

		if (myTurn)
		{
			if ((ballY <= (myBatY + batHeight + 10)) && (ballY >= myBatY))
			{
				if (ballX >= myBatX && ballX <= (myBatX + batWidth)) inRange = 1;
			}
		}

		else if (pcTurn)
		{
			if ((ballY >= (pcBatY - batHeight - 10)) && ballY <= pcBatY)
			{
				if (ballX >= pcBatX && ballX <= (pcBatX + batWidth)) inRange = 1;
			}
		}

		if ((ballY > pcBatY + 10) || (ballY < myBatY - 10))
		{
			if (myServe > 0) { myTurn = 1; pcTurn = 0; }
			else { myTurn = 0; pcTurn = 1; }
			serve = 1;
			inRange = 0;
		}
	}
}

int main()
{
	iSetTimer(20, ballMoving);
	iInitialize(windowWidth, windowHeight, "Table Tennis");
	return 0;
}
