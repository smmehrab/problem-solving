void drawBackground() {
	iSetColor(background.colorR, background.colorG, background.colorB);
	iFilledRectangle(initialX, initialY, window.width, window.height);
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
