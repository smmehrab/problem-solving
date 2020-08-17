struct Player1 {
	int colorR = 179, colorG = 0, colorB = 0;
	int width = 60, height = 10, speed = 10;
	int x = border.initialMidX - (width / 2), y = board.y - (width / 2);
	int serveCount = 2, turn = 1;
	int score[3] = { 0 };
	char scoreString[3][100] = { "-","-","-" };
	char name[100], rolls[10];
	int roll, len, indexN = 0, indexR = 0;
	int scoreX = (window.width * 3 / 4) - 60;
	int scoreY = board.y + ((board.height - board.y) / 4);
	int set = 0;
	char nameRoll[100];
}player1;

struct Player2 {
	int colorR = 179, colorG = 0, colorB = 0;
	int width = 60, height = 10, speed = 10;
	int x = border.initialMidX - (width / 2), y = board.y + board.height + (width / 2);
	int serveCount = 0, turn = 0;
	int score[3] = { 0 };
	char scoreString[3][100] = { "-","-","-" };
	char name[100], rolls[10];
	int roll, len, indexN = 0, indexR = 0;
	int scoreX = (window.width * 3 / 4) - 60;
	int scoreY = board.y + board.height - board.y;
	int set = 0;
	char nameRoll[100];
}player2;
