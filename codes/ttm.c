# include "iGraphics.h"
# include "01-40.h"
# include "Box2D/Box2D.h"


void iDraw()
{
	iClear();

	drawBackground();

	if (menu == mainm)
		showMainMenu(selectPos);

	else if (menu == pause)
		showPauseMenu(selectPos);

	else if (menu == instructions)
		showHowToPlay();

	else if (menu == info1)
		showPlayer1Info();

	else if (menu == info2)
		showPlayer2Info();

	else if (menu == null) {
		showTheMatch();
		showTheScore();
	}
}

void iMouseMove(int mx, int my)
{
	// Bat's Movement During Player2's Turn
	if (player2.moveState && !gameOver) {
		if ( mx > board.x + board.width + 10) player2.x = board.x + board.width + 10;
		else if ( mx < board.x - player2.width - 10) player2.x = board.x - player2.width - 10;
		else player2.x = mx;
	}

}

void iMouse(int button, int state, int mx, int my)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		player2.hitState = 1;
		player2.inHitY = my;
		player2.inHitX = mx;
	}

	else if (player2.hitState = 1 && button == GLUT_LEFT_BUTTON && state == GLUT_UP) {
		player2.hitState = 0;
		player2.finHitY = my;
		player2.finHitX = mx;

		if (player2.finHitY - player2.inHitY < 0) {
			ball.mouseSpeedY = 10;
			ball.theta = pi - atan((player2.finHitY - player2.y) / (player2.finHitX - player2.x));
			ball.mouseSpeedX = ball.mouseSpeedY*tan(ball.theta);
		}
		else {
			ball.mouseSpeedY = 5;
			ball.theta = pi - atan((player2.inHitY - player2.y) / (player2.inHitX - player2.x));
			ball.mouseSpeedX = ball.mouseSpeedY*tan(ball.theta);
		}
	}

	else if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) {
		player2.moveState = 1;
	}

	else if (button == GLUT_RIGHT_BUTTON && state == GLUT_UP) {
		player2.moveState = 0;
	}

}
void iKeyboard(unsigned char key)
{
	if (menu == info1) takePlayer1Info(key, selectPos);

	else if (menu == info2) takePlayer2Info(key, selectPos);

	if (key == esc) escFunction(&menu, &selectPos);

	else if (key == enter) enterFunction(&menu, &selectPos);


	else if (key == 's' || key == 'w') ball.smashDirection = 1;
	else if (key == 'a') ball.smashDirection = 0;
	else if (key == 'd') ball.smashDirection = 2;

	else if (key == space && !gameOver) {

		if (ball.smashDirection == 0) ball.keySpeedX = ball.speedA;
		else if (ball.smashDirection == 1) ball.keySpeedX = ball.speedS;
		else if (ball.smashDirection == 2) ball.keySpeedX = ball.speedD;

		if (player1.inRange&& player1.turn) doSmash();
		else if (serve&& player1.turn) doServe();
	}

	else if (key == 'c' && !gameOver) {
		if (ball.smashDirection == 0) ball.keySpeedX = ball.speedA;
		else if (ball.smashDirection == 1) ball.keySpeedX = ball.speedS;
		else if (ball.smashDirection == 2) ball.keySpeedX = ball.speedD;

		if (player1.inRange&& player1.turn) doChop();
	}
}


void iSpecialKeyboard(unsigned char key)
{
	// Main Menu Ups & Downs
	if (menu == mainm) {
		if (key == GLUT_KEY_DOWN && selectPos < 2) selectPos++;
		else if (key == GLUT_KEY_UP && selectPos > 0) selectPos--;
	}

	// Pause Menu Ups & Downs
	else if (menu == pause) {
		if (key == GLUT_KEY_DOWN && selectPos < 2) selectPos++;
		else if (key == GLUT_KEY_UP && selectPos > 0) selectPos--;
	}

	else if (menu == info1) {
		if (key == GLUT_KEY_DOWN && selectPos < 2) selectPos++;
		else if (key == GLUT_KEY_UP && selectPos > 0) selectPos--;
	}
	else if (menu == info2) {
		if (key == GLUT_KEY_DOWN && selectPos < 2) selectPos++;
		else if (key == GLUT_KEY_UP && selectPos > 0) selectPos--;
	}

	// Bat's Movement During Player1's Turn
	else if (!gameOver) {
		if (key == GLUT_KEY_RIGHT && player1.x <= board.x + board.width + 10) player1.x += player1.speed;
		else if (key == GLUT_KEY_LEFT && player1.x >= board.x - player1.width - 10) player1.x -= player1.speed;
	}
}

void ballMoving()
{
	if (serve) {
		if (player1.serveCount) {
			ball.x = player1.x + (player1.width / 2);
			ball.y = player1.y + player1.height;
			if (ball.speedY < 0)  ball.speedY *= -1;
		}

		else {
			ball.x = player2.x + (player2.width / 2);
			ball.y = player2.y - player2.height;
			if (ball.speedY > 0)  ball.speedY *= -1;
		}
	}

	else
	{
		if (player1.turn)
		{
			ball.y += ball.mouseSpeedY;
			ball.x += ball.mouseSpeedX;
			if ((ball.y <= (player1.y + player1.height + 10)) && (ball.y >= player1.y))
			{
				if (ball.x >= player1.x && ball.x <= (player1.x + player1.width)) player1.inRange = 1;
			}
		}

		else if (player2.turn)
		{
			ball.x += ball.keySpeedX;
			ball.y += ball.keySpeedY;
			if ((ball.y >= (player2.y - player2.height - 10)) && ball.y <= player2.y)
			{
				if (ball.x >= player2.x && ball.x <= (player2.x + player2.width)) player2.inRange = 1;
			}
		}

		if ((ball.y > player2.y + 10) || (ball.y < player1.y - 10))
		{
			if (player1.serveCount > 0) { player1.turn = 1; player2.turn = 0; }
			else { player1.turn = 0; player2.turn = 1; }
			serve = 1;
			player1.inRange = 0;
			player2.inRange = 0;


			if ((ball.y > player2.y + 10)) {
				iDelay(1);
				player1.score[scoreIndex]++;
			}
			else if ((ball.y < player1.y - 10)) {
				iDelay(1);
				player2.score[scoreIndex]++;
			}

			if (player1.score[scoreIndex] + player2.score[scoreIndex] > 4) {
				if (player1.score[scoreIndex] - player2.score[scoreIndex] == 2) {
					player1.set++;
					scoreIndex++;
				}
				else if (player2.score[scoreIndex] - player1.score[scoreIndex] == 2) {
					player2.set++;
					scoreIndex++;
				}
			}
			else if (player2.score[scoreIndex] == 3) {
				player2.set++;
				scoreIndex++;
			}
			else if (player1.score[scoreIndex] == 3) {
				player1.set++;
				scoreIndex++;
			}
		}
	}
}

int main()
{
	iSetTimer(20, ballMoving);
	iInitialize(window.width, window.height, "Table Tennis");
	return 0;
}
