enum Menu {
	mainm, pause, null, instructions,
	info1, info2
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

