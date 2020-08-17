# include "iGraphics.h"

int initial_x = 0;
int initial_y = 0;

int window_width = 1000;
int window_height = 600;

int board_width = 100;
int board_height = 15;

int egg_width = 10;
int egg_height = 15;

int board_x = 500;
int board_y = 0;

int egg_x;
int egg_y;

int new_egg = 1;

int bg_clr_r = 252;
int bg_clr_g = 194;
int bg_clr_b = 51;

int board_clr_r = 229;
int board_clr_g = 55;
int board_clr_b = 56;

int egg_clr_r = 255;
int egg_clr_g = 145;
int egg_clr_b = 100;

int board_speed = 25;
int egg_speed = 5;

char score_show[200];
int score = 0;

int score_bar_width = window_width;
int score_bar_height = 50;

char time_show[200];
int sec_timee = 60;
int min_timee = 1;

int life=3;

int pause=0;
int menu=1;

int select_x=100;
int select_y=350;
int select_gap=100;
int selecton_width=400;
int selection_height=100;
int select_pos=0;

int info=0;
int show_result=0;

int HighScore;


bool musicOn=true;

void iDraw()
{
	iClear();

	iSetColor(bg_clr_r, bg_clr_g, bg_clr_b);
	iFilledRectangle(initial_x, initial_y, window_width, window_height);

	iSetColor(board_clr_r, board_clr_g, board_clr_b);
	iFilledRectangle(initial_x, window_height, score_bar_width, score_bar_height);

	if(menu)
	{
		iSetColor(egg_clr_r, egg_clr_g, egg_clr_b);
		iFilledEllipse(egg_x, egg_y, egg_width, egg_height);

		iSetColor(board_clr_r, board_clr_g, board_clr_b);
		iFilledRectangle(initial_x, window_height, score_bar_width, score_bar_height);

		iShowBMP(100,150,"bc//Game Menu.bmp");
		iShowBMP(500,150,"bc//murgi.bmp");
		iText(230, 125, "PRESS 's' to SELECT", GLUT_BITMAP_HELVETICA_12);

		iSetColor(board_clr_r, board_clr_g, board_clr_b);
		iRectangle(select_x ,select_y, selecton_width, selection_height);

	}

	else if(info)
	{
			iSetColor(egg_clr_r, egg_clr_g, egg_clr_b);
			iFilledEllipse(egg_x, egg_y, egg_width, egg_height);

			iSetColor(board_clr_r, board_clr_g, board_clr_b);
			iFilledRectangle(initial_x, window_height, score_bar_width, score_bar_height);

			iSetColor(board_clr_r, board_clr_g, board_clr_b);

			iText(200, 500, "INSTRUCTIONS:", GLUT_BITMAP_HELVETICA_18);
			iText(240, 460, "- PRESS 'Right Arrow' or 'Left Arrow' key to move the board.", GLUT_BITMAP_HELVETICA_18);
			iText(240, 440, "- PRESS 'p' to pause the game.", GLUT_BITMAP_HELVETICA_18);

			iText(200, 400, "BEHIND THE SCENE:", GLUT_BITMAP_HELVETICA_18);

			iText(240, 360, "S.M.MEHRABUL ISLAM", GLUT_BITMAP_HELVETICA_18);
			iText(240, 320, "Batch : 24", GLUT_BITMAP_HELVETICA_18);
			iText(360, 320, "Roll : 01", GLUT_BITMAP_HELVETICA_18);
			iText(240, 280, "Department of Computer Science & Engineering", GLUT_BITMAP_HELVETICA_18);
			iText(240, 240, "University of Dhaka", GLUT_BITMAP_HELVETICA_18);

			iText(200, 200, "PRESS 'b' to GO BACK", GLUT_BITMAP_HELVETICA_12);
	}

	else if(pause)
	{
		iShowBMP(100,150,"bc//Pause Menu.bmp");
		iShowBMP(500,150,"bc//Pause Menu Pic.bmp");
		iText(230, 125, "PRESS 's' to SELECT", GLUT_BITMAP_HELVETICA_12);

		iSetColor(board_clr_r, board_clr_g, board_clr_b);
		iRectangle(select_x ,select_y, selecton_width, selection_height);

	}

	else
	{
		iSetColor(egg_clr_r, egg_clr_g, egg_clr_b);
		iFilledEllipse(egg_x, egg_y, egg_width, egg_height);


		iSetColor(board_clr_r, board_clr_g, board_clr_b);
		iFilledRectangle(board_x, board_y, board_width, board_height);

		iSetColor(board_clr_r, board_clr_g, board_clr_b);
		iFilledRectangle(initial_x, window_height, score_bar_width, score_bar_height);



		iSetColor(255, 255, 255);

		if (egg_y == board_height)
		{
			if (egg_x >= board_x && (egg_x + egg_width) <= (board_x + board_width))
			{
				score += 1;
				egg_x = rand() % (window_width - egg_width);
				egg_y = window_height + 10;
				new_egg = 0;
			}
			else if (egg_x <= board_x && (egg_x + egg_width) >= (board_x + board_width)) life-=1;
		}

		iText(5 * (window_width / 7), window_height + (score_bar_height / 3), "Lives Remaining:", GLUT_BITMAP_HELVETICA_18);
		for(int i=0;i<life;i++) iFilledEllipse(866+(5.00/2.00)*i*egg_width,623, egg_width, egg_height);


		sprintf_s(score_show, "Score: %d", score);
		iText(3 * (window_width / 7), window_height + (score_bar_height / 3), score_show, GLUT_BITMAP_HELVETICA_18);

		sprintf_s(time_show, "%d : %d", min_timee,sec_timee);
		iText((window_width / 14), window_height +(score_bar_height / 3), time_show, GLUT_BITMAP_HELVETICA_18);

		if(life<0 || min_timee<0)
		{
			iSetColor(bg_clr_r, bg_clr_g, bg_clr_b);
			iFilledRectangle(initial_x, initial_y, window_width, window_height+score_bar_height);

			iSetColor(board_clr_r, board_clr_g, board_clr_b);
			/*if(score>=HighScore)
			{
				iShowBMP(100, 250, "bc\\High Scores.bmp");
				iShowBMP(500, 250, "bc\\Congratulations.bmp");
				sprintf_s(score_show, "Score: %d", score);
				iText(650, 200, score_show, GLUT_BITMAP_TIMES_ROMAN_24);
			}
			else
			{*/
				iShowBMP(100, 250, "bc\\why.bmp");
				iShowBMP(500, 250, "bc\\GAME OVER.bmp");
				sprintf_s(score_show, "Score: %d", score);
				iText(600, 200, score_show, GLUT_BITMAP_HELVETICA_18);
			//}
			show_result++;
			if(show_result>1000) menu=1;
		}
	}
}

/*
	function iMouseMove() is called when the user presses and drags the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouseMove(int mx, int my)
{

}

/*
	function iMouse() is called when the user presses/releases the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouse(int button, int state, int mx, int my)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{

	}
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{

	}
}

void iKeyboard(unsigned char key)
{
	if(info==1 && key=='b') menu=1;
	else if (key == 'p')
	{
		iPauseTimer(0);
		pause=1;
	}


	if(menu==1 && key=='s')
	{
		if(select_pos==0)
		{
			info=0;
			new_egg=1;
			life=3;
			score=0;
			sec_timee=60;
			min_timee=1;
			menu=0;
		}
		else if(select_pos==1)
		{
			info=1;
			menu=0;
		}
		else if(select_pos==2) exit(0);
	}
	if(pause==1 && key=='s')
	{
		if(select_pos==0)
		{
			iResumeTimer(0);
			pause=0;
		}
		else if(select_pos==1)
		{
			score=0;
			sec_timee=60;
			min_timee=1;
			life=3;
			new_egg=1;
			iResumeTimer(0);
			pause=0;
		}
		else if(select_pos==2) exit(0);
	}

}

void iSpecialKeyboard(unsigned char key)
{
	if (key == GLUT_KEY_RIGHT && board_x <= (window_width - board_width - board_speed)) board_x += board_speed;
	else if (key == GLUT_KEY_LEFT && board_x >= board_speed)	board_x -= board_speed;

	if(menu==1 || pause==1)
	{
		if(key==GLUT_KEY_DOWN && select_pos<2)
		{
			select_y-=select_gap;
			select_pos+=1;
		}

		else if(key==GLUT_KEY_UP && select_pos>0)
		{
			select_y+=select_gap;
			select_pos-=1;
		}
	}
}

void egg_falling()
{
	if (new_egg)
	{
		egg_x =egg_width + rand() % (window_width - 2*egg_width);
		egg_y = window_height + 10;
		new_egg = 0;
	}

	else
	{
		egg_y -= egg_speed;
		if (egg_y <= -20)
		{
			new_egg = 1;
			life-=1;
		}
	}

}


void timer()
{
	if(!pause) sec_timee--;
	if(sec_timee==0) min_timee--;
}

int main()
{
	iSetTimer(2, egg_falling);
	iSetTimer(1000, timer);
	if(musicOn) PlaySound("bc\\gamemusic.wav",NULL,SND_LOOP|SND_ASYNC);
	iInitialize(window_width, (window_height + score_bar_height),"CATCH THE EGGS");
	return 0;
}

