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
