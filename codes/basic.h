#define space ' '
#define enter '\r'
#define esc 27
#define pi acos(-1.0)

int initialX = 0;
int initialY = 0;

int scoreIndex = 0;

int selectPos = 0;
int ind;
int set = 0;

int serve = 1;
int inRange = 0;

int gameOver = 0;

struct Window {
	int width = 1000, height = 600;
}window;

struct Background {
	int colorR = 255, colorG = 255, colorB = 255;
}background;

struct Text {
	int colorR = 179, colorG = 0, colorB = 0;
}text;




