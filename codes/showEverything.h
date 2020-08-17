void showTheMatch() {
	drawTheTable();
	drawThePlayers();
	drawTheBall();
}

void showTheScore() {
	iSetColor(text.colorR, text.colorG, text.colorB);

	sprintf_s(player1.nameRoll, "%s (%s)", player1.name, player1.rolls);
	iText(player1.scoreX, player1.scoreY + 40, player1.nameRoll, GLUT_BITMAP_TIMES_ROMAN_24);

	sprintf_s(player2.nameRoll, "%s (%s)", player2.name, player2.rolls);
	iText(player2.scoreX, player2.scoreY + 40, player2.nameRoll, GLUT_BITMAP_TIMES_ROMAN_24);

	if (player1.set + player2.set > set) {
		set++;
		sprintf_s(player1.scoreString[scoreIndex - 1], " %d", player1.score[scoreIndex - 1]);
		sprintf_s(player2.scoreString[scoreIndex - 1], " %d", player2.score[scoreIndex - 1]);
	}
	else {
		sprintf_s(player1.scoreString[scoreIndex], " %d", player1.score[scoreIndex]);
		sprintf_s(player2.scoreString[scoreIndex], " %d", player2.score[scoreIndex]);
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


	for (ind = 0; ind < 3; ind++) {
		iRectangle(player1.scoreX - 5 + (ind * 50), player1.scoreY - 5, 30, 30);
		iText(player1.scoreX + (ind * 50), player1.scoreY, player1.scoreString[ind], GLUT_BITMAP_TIMES_ROMAN_24);
		iRectangle(player2.scoreX - 5 + (ind * 50), player2.scoreY - 5, 30, 30);
		iText(player2.scoreX + (ind * 50), player2.scoreY, player2.scoreString[ind], GLUT_BITMAP_TIMES_ROMAN_24);
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

