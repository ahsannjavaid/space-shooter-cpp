// Function of STAGES
#include <iostream>
#include <stdio.h>
#include <fstream>
#include <graphics.h>

using namespace std;

int bullet=0,x_bullet,y_bullet=860;
int score=0,lives=3,level=1,shoot=0,shoot_accur;
char arr_lives[50],arr_score[50],arr_level[50],arr_shoot[50],arr_shoot_accur[50],arr_high[50];
int x_spaceship=450;
int y_arrow1=460,y_arrow3=460,y_arrow2=400;
int movement[7];
int movement_all=0;
int highest,highest1=0,highest2=0,num;
int rslt_chk=1;

void arc_interface()
{
	// arcade mode interface
	setcolor(WHITE);
	line (30,30,870,30);
	line (870,30,870,925);
	line (900,30,900,925);
	line (30,925,870,925);
	line (30,30,30,925);
	line (900,30,1200,30);
	line (900,925,1200,925);
	line (1200,30,1200,925);
	line (900,200,1200,200);
	line (900,620,1200,620);
	line (900,300,1200,300);
	settextstyle(SMALL_FONT,HORIZ_DIR,5);
	outtextxy(965,145,"PRESS 'ALT' TO PAUSE GAME");
	outtextxy(945,165,"PRESS 'ESCAPE' KEY TO EXIT GAME");
	// updating the LEVEL...
	sprintf(arr_level,"LEVEL %d",level);
	settextstyle(GOTHIC_FONT,HORIZ_DIR,1);
	outtextxy(990,360,arr_level);
	// updating the score...
	sprintf(arr_score,"Score %d",score);
	settextstyle(GOTHIC_FONT,HORIZ_DIR,1);
	outtextxy(940,460,arr_score);
	// updating the shoots...
	sprintf(arr_shoot,"Shoot bullets %d",shoot);
	settextstyle(GOTHIC_FONT,HORIZ_DIR,1);
	outtextxy(940,525,arr_shoot);
	// updating the lives...
	setcolor(RED);
	sprintf(arr_lives,"Lives left %d",lives);
	settextstyle(GOTHIC_FONT,HORIZ_DIR,1);
	outtextxy(940,430,arr_lives);
	setcolor(YELLOW);
	settextstyle(GOTHIC_FONT,HORIZ_DIR,2);
	outtextxy(940,240,"ARCADE Mode");
	settextstyle(GOTHIC_FONT,HORIZ_DIR,2);
	outtextxy(945,60,"Space Shooter");
	settextstyle(SMALL_FONT,HORIZ_DIR,5);
	outtextxy(1060,85,"by AHSAN JAVED");
	setcolor(WHITE);
	settextstyle(GOTHIC_FONT,HORIZ_DIR,2);
	outtextxy(970,650,"Instructions");
	settextstyle(SMALL_FONT,HORIZ_DIR,5);
	outtextxy(920,695,"--> Shoot the Enemies and not let them to cross");
	outtextxy(937,712,"the Border line.");
	outtextxy(920,735,"--> Press Right Arrow Key to move Spaceship Right.");
	outtextxy(920,755,"--> Press Left Arrow Key to move Spaceship Left.");
	outtextxy(920,775,"--> Press Spacebar to shoot a Bullet.");
	outtextxy(920,805,"  > Score 20 to move to LEVEL 2.");
	outtextxy(920,825,"  > Score 40 to move to LEVEL 3.");
	outtextxy(920,845,"  > Score 50 to move to LEVEL 4.");
	outtextxy(920,865,"  > Score 60 to move to LEVEL 5.");
	outtextxy(920,885,"  > Score 70 to WIN the GAME.");
	settextstyle(GOTHIC_FONT,HORIZ_DIR,1);
}

void clsc_interface(int clsc_diff)
{
	// classic mode interface
	setcolor(WHITE);
	line (30,30,870,30);
	line (870,30,870,925);
	line (900,30,900,925);
	line (30,925,870,925);
	line (30,30,30,925);
	line (900,30,1200,30);
	line (900,925,1200,925);
	line (1200,30,1200,925);
	line (900,200,1200,200);
	line (900,620,1200,620);
	line (900,300,1200,300);
	settextstyle(SMALL_FONT,HORIZ_DIR,5);
	outtextxy(965,145,"PRESS 'ALT' TO PAUSE GAME");
	outtextxy(945,165,"PRESS 'ESCAPE' KEY TO EXIT GAME");
	// updating the lives...
	setcolor(RED);
	sprintf(arr_lives,"Lives left %d",lives);
	settextstyle(GOTHIC_FONT,HORIZ_DIR,1);
	outtextxy(940,420,arr_lives);
	setcolor(YELLOW);
	settextstyle(GOTHIC_FONT,HORIZ_DIR,2);
	outtextxy(940,230,"CLASSIC Mode");
	if (clsc_diff == 0)
	{
		settextstyle(SMALL_FONT,HORIZ_DIR,5);
		outtextxy(1030,260,"(EASY)");
		outtextxy(920,875,"  > Difficulty Level increases as the game proceed.");
		highest = highest1;
	}
	else if (clsc_diff == 1)
	{
		settextstyle(SMALL_FONT,HORIZ_DIR,5);
		outtextxy(1030,260,"(HARD)");
		outtextxy(920,875,"  > Difficulty Level increases as the game proceed.");
		highest = highest2;
	}
	settextstyle(GOTHIC_FONT,HORIZ_DIR,2);
	outtextxy(945,60,"Space Shooter");
	settextstyle(SMALL_FONT,HORIZ_DIR,5);
	outtextxy(1060,85,"by AHSAN JAVED");
	setcolor(WHITE);
	settextstyle(GOTHIC_FONT,HORIZ_DIR,1);
	outtextxy(940,500,"Highest");
	settextstyle(GOTHIC_FONT,HORIZ_DIR,1);
	outtextxy(940,525,"SCORE");
	// updating the score...   
	// updating the highest score...
	sprintf(arr_high,"= %d",highest);
	settextstyle(GOTHIC_FONT,HORIZ_DIR,1);
	outtextxy(1065,513,arr_high);
	sprintf(arr_score,"Score %d",score);
	settextstyle(GOTHIC_FONT,HORIZ_DIR,1);
	outtextxy(940,450,arr_score);
	// updating the shoots...
	sprintf(arr_shoot,"Shoot bullets %d",shoot);
	settextstyle(GOTHIC_FONT,HORIZ_DIR,1);
	outtextxy(940,375,arr_shoot);
	settextstyle(GOTHIC_FONT,HORIZ_DIR,2);
	outtextxy(970,650,"Instructions");
	settextstyle(SMALL_FONT,HORIZ_DIR,5);
	outtextxy(920,725,"--> Shoot the Enemies and not let them to cross");
	outtextxy(937,742,"the Border line.");
	outtextxy(920,765,"--> Press Right Arrow Key to move Spaceship Right.");
	outtextxy(920,785,"--> Press Left Arrow Key to move Spaceship Left.");
	outtextxy(920,805,"--> Press Spacebar to shoot a Bullet.");
	
	settextstyle(GOTHIC_FONT,HORIZ_DIR,1);
}

void bomb (int x,int y)
{
	setcolor(WHITE);
	outtextxy(x+5,y+20,"o");
}

void rmv_bomb (int x,int y)
{
	setcolor(WHITE);
	outtextxy(x+5,y+20,"  ");
}

void rmv_bullet (int x_bullet,int y_bullet)
{
	outtextxy(x_bullet-4,y_bullet+5," ");
}

void rmv_spaceship (int x_spaceship)
{
	// from right side...
	outtextxy(x_spaceship+10,860," ");
	outtextxy(x_spaceship+31,870," ");
	outtextxy(x_spaceship+50,888," ");
	outtextxy(x_spaceship+40,903," ");
	// from left side...
	outtextxy(x_spaceship-10,860," ");
	outtextxy(x_spaceship-30,870," ");
	outtextxy(x_spaceship-46,888," ");
	outtextxy(x_spaceship-38,903," ");
}

void rmv_enemy1 (int x_enemy,int y_enemy)
{
	outtextxy(x_enemy,y_enemy,"   ");
}

void rmv_enemy1_beh (int x_enemy,int y_enemy)
{
	outtextxy(x_enemy,y_enemy-20,"   ");
}

void rmv_enemy2 (int x_enemy,int y_enemy)
{
	outtextxy(x_enemy,y_enemy,"    ");
	outtextxy(x_enemy-20,y_enemy-5,"    ");
	outtextxy(x_enemy+20,y_enemy-5,"    ");
}

void rmv_enemy2_beh (int x_enemy,int y_enemy)
{
	outtextxy(x_enemy,y_enemy-20,"    ");
	// from leftward
	outtextxy(x_enemy-50,y_enemy-10,"     ");
	// from rightward
	outtextxy(x_enemy+50,y_enemy-10,"     ");
}

void rmv_giant_enemy_beh (int x_enemy,int y_enemy)
{
	setcolor(RED);
	outtextxy(x_enemy+3,y_enemy-100,"         ");
	outtextxy(x_enemy+3,y_enemy-80,"         ");
	outtextxy(x_enemy+3,y_enemy-60,"         ");
	// from rightward
	outtextxy(x_enemy+77,y_enemy-50,"         ");
	outtextxy(x_enemy+77,y_enemy-30,"         ");
	outtextxy(x_enemy+77,y_enemy-20,"         ");
	outtextxy(x_enemy+77,y_enemy,"         ");
	// from leftward
	outtextxy(x_enemy-70,y_enemy-50,"         ");
	outtextxy(x_enemy-70,y_enemy-30,"         ");
	outtextxy(x_enemy-70,y_enemy-20,"         ");
	outtextxy(x_enemy-70,y_enemy,"         ");
}

void spaceship (int x_spaceship)
{
	setcolor(BLUE);
	outtextxy(x_spaceship,860,"*");
	outtextxy(x_spaceship-20,870,"-----");
	outtextxy(x_spaceship-36,888,"^^^^^^");
	outtextxy(x_spaceship-28,903,"^     ^");
}

void mov_spaceship()
{
	// moving the SPACESHIP...
	if (GetAsyncKeyState(VK_RIGHT))
	{
		if (x_spaceship <= 805)		// bounding the Rightward distance...
		{
			x_spaceship += 8;
		}
	}
	if (GetAsyncKeyState(VK_LEFT))
	{
		if (x_spaceship >= 85)		// bounding the Leftward distance...
		{
			x_spaceship -= 8;
		}
	}
}

void bullet_prop()
{
	if (GetAsyncKeyState(' ') && bullet == 0)	// bullet shooting...
	{
		shoot++;
		bullet = 1;
		x_bullet = x_spaceship + 5;
	}
	if (bullet == 1)
	{
		setcolor(WHITE);
		circle(x_bullet,y_bullet,5);		// bullet
		rmv_bullet(x_bullet,y_bullet);
		y_bullet -= 15;
	}
	if (y_bullet <= 30)
	{
		rmv_bullet(x_bullet,y_bullet-5);
		x_bullet = x_spaceship + 5;
		bullet = 0;
		y_bullet = 860;
	}
}

void enemy1 (int x_enemy,int y_enemy)
{
	setcolor(RED);
	outtextxy(x_enemy,y_enemy,"[-]");
}

void enemy2 (int x_enemy,int y_enemy)
{
	setcolor(RED);
	outtextxy(x_enemy,y_enemy,")*(");
}

void giant_enemy (int x_enemy,int y_enemy)
{
	setcolor(RED);
	outtextxy(x_enemy,y_enemy-40,")*****(");
	outtextxy(x_enemy,y_enemy-20,")*****(");
	outtextxy(x_enemy,y_enemy,")*****(");
}

void arc_stage (double x_stage[],double y_stage[],double rec_y_stage[],int no_of_enemy,double speed,int horiz_mov_typ)
{
	int x_start_range,x_end_range,y_start_range,y_end_range,rand;
	for (int i=0 ; i<no_of_enemy ; i++)
	{
		if (y_stage[i] >= 30)
		{
			if (horiz_mov_typ == 0)
			{
				enemy1(x_stage[i],y_stage[i]);
				rmv_enemy1_beh(x_stage[i],y_stage[i]);
			}
			else if (horiz_mov_typ == 1 || horiz_mov_typ == 2)
			{
				enemy2(x_stage[i],y_stage[i]);
				rmv_enemy2_beh(x_stage[i],y_stage[i]);
			}
			else if (horiz_mov_typ == 3)
			{
				giant_enemy(x_stage[i],y_stage[i]);
				rmv_giant_enemy_beh(x_stage[i],y_stage[i]);
			}
		}
		if (horiz_mov_typ == 3)
		{
			x_start_range = x_stage[i] - 30;
			x_end_range = x_stage[i] + 65;	
			y_start_range = y_stage[i] - 30;
			y_end_range = y_stage[i] + 30;
		}
		else
		{
			x_start_range = x_stage[i] - 10;
			x_end_range = x_stage[i] + 35;	
			y_start_range = y_stage[i] - 10;
			y_end_range = y_stage[i] + 10;
		}
		if ((x_bullet >= x_start_range && x_bullet <= x_end_range) && (y_bullet >= y_start_range && y_bullet <= y_end_range))
		{
			Beep(100,50);
			bomb(x_stage[i],y_stage[i]);
			delay(10);
			rmv_bomb(x_stage[i],y_stage[i]);
			rmv_bullet(x_bullet,y_bullet-5);
			if (horiz_mov_typ == 0)
			{
				rmv_enemy1(x_stage[i],y_stage[i]);
			}
			else if (horiz_mov_typ == 1 || horiz_mov_typ == 2)
			{
				rmv_enemy2(x_stage[i],y_stage[i]);
			}
			x_bullet = x_spaceship + 5;
			bullet=0;
			y_bullet = 860;
			score++;
			// allotting a sort of Random y_point for the enemy...
			if (horiz_mov_typ == 0 || horiz_mov_typ == 1 || horiz_mov_typ == 2)
			{
				rand = i+1;
				if (rand >= no_of_enemy)
				{
					rand = rand - no_of_enemy;
				}
				y_stage[i]=rec_y_stage[rand];
			}
		}
		if (y_stage[i] >= 905)	// enemy crossing the border line...
		{
			Beep(500,20);
			if (horiz_mov_typ == 0)
			{
				rmv_enemy1(x_stage[i],y_stage[i]);
			}
			else if (horiz_mov_typ == 1 || horiz_mov_typ == 2)
			{
				rmv_enemy2(x_stage[i],y_stage[i]);
			}
			if (horiz_mov_typ == 3)
			{
				lives -= 3;
			}
			else
			{
				lives--;
			}
			// allotting a sort of Random y_point for the enemy...
			if (horiz_mov_typ == 0 || horiz_mov_typ == 1 || horiz_mov_typ == 2)
			{
				rand = i+1;
				if (rand >= no_of_enemy)
				{
					rand = rand - no_of_enemy;
				}
				y_stage[i]=rec_y_stage[rand];
			}
		}
		if (horiz_mov_typ == 3)
		{
			y_stage[i] += speed*0.3;
		}
		else
		{
			y_stage[i] += speed;
		}
		if (horiz_mov_typ == 1)
		{
			// for Horizontal movement...
			if (x_stage[i] >= 830)
			{
				movement[i] = 1;
			}
			if (x_stage[i] <= 50)
			{
				movement[i] = 0;
			}
			if (movement[i] == 0)		// for rightward
			{
				x_stage[i] += speed*4;
			}
			if (movement[i] == 1)		// for leftward
			{
				x_stage[i] -= speed*4;
			}
		}
		else if (horiz_mov_typ == 2)
		{
			// for Horizontal instant movement...
			if (x_stage[i] >= 830)
			{
				movement_all = 1;
			}
			if (x_stage[i] <= 50)
			{
				movement_all = 0;
			}
			if (movement_all == 0)		// for rightward
			{
				x_stage[i] += speed*4;
			}
			if (movement_all == 1)		// for leftward
			{
				x_stage[i] -= speed*4;
			}
		}
		else if (horiz_mov_typ == 3)
		{
			// for Horizontal and Vertical instantat movement...
			if (x_stage[i] >= 770)
			{
				movement[i] = 1;
			}
			if (x_stage[i] <= 50)
			{
				movement[i] = 0;
			}
			if (movement[i] == 0)		// for rightward
			{
				x_stage[i] += speed*4;
			}
			if (movement[i] == 1)		// for leftward
			{
				x_stage[i] -= speed*4;
			}
			if ((y_stage[i] >= 100 && y_stage[i] <= 300) || (y_stage[i] >= 500 && y_stage[i] <= 600) || (y_stage[i] >= 800 && y_stage[i] <= 950))
			{
				y_stage[i] += speed*4;
			}
		}
	}
}

void clsc_stage (double x_stage[],double y_stage[],double rec_y_stage[],double speed,int diffic_level)
{
	int x_start_range,x_end_range,y_start_range,y_end_range,rand;
	for (int i=0 ; i<10 ; i++)
	{
	if (y_stage[i] >= 30)
	{
		if (diffic_level == 0)
		{
			enemy1(x_stage[i],y_stage[i]);
			rmv_enemy1_beh (x_stage[i],y_stage[i]);
		}
		else if (diffic_level == 1)
		{
			enemy2(x_stage[i],y_stage[i]);
			rmv_enemy2_beh (x_stage[i],y_stage[i]);
		}
	}
	x_start_range = x_stage[i] - 10;
	x_end_range = x_stage[i] + 35;	
	y_start_range = y_stage[i] - 10;
	y_end_range = y_stage[i] + 10;
	if ((x_bullet >= x_start_range && x_bullet <= x_end_range) && (y_bullet >= y_start_range && y_bullet <= y_end_range))
	{
		Beep(100,50);
		bomb(x_stage[i],y_stage[i]);
		delay(10);
		rmv_bomb(x_stage[i],y_stage[i]);
		rmv_bullet(x_bullet,y_bullet-5);
		if (diffic_level == 0)
		{
			rmv_enemy1(x_stage[i],y_stage[i]);
		}
		else if (diffic_level == 1)
		{
			rmv_enemy2(x_stage[i],y_stage[i]);
		}
		x_bullet = x_spaceship + 5;
		bullet=0;
		y_bullet = 860;
		rand = i+3;
		if (rand >= 10)
		{
			rand = rand - 10;
		}
		y_stage[i]=rec_y_stage[rand];
		score++;
	}
	if (y_stage[i] >= 905)		// enemy crossing the border line...
	{
		Beep(500,20);
		if (diffic_level == 0)
		{
			rmv_enemy1(x_stage[i],y_stage[i]);
		}
		else if (diffic_level == 1)
		{
			rmv_enemy2(x_stage[i],y_stage[i]);
		}
		rand = i+3;
		if (rand >= 10)
		{
			rand = rand - 10;
		}
		y_stage[i]=rec_y_stage[rand];
		lives--;
	}
	if (diffic_level == 1)
	{
		if (x_stage[i] >= 830)
		{
			movement[i] = 1;
		}
		if (x_stage[i] <= 50)
		{
			movement[i] = 0;
		}
		if (movement[i] == 0)		// for rightward
		{
			x_stage[i] += speed*3;
		}
		if (movement[i] == 1)		// for leftward
		{
			x_stage[i] -= speed*3;
		}
	}
	y_stage[i] += speed+((double)(score*0.01));
	}
}

void arrow (int y)
{
	settextstyle(BOLD_FONT,HORIZ_DIR,4);
	setcolor(WHITE);
	outtextxy(400,y,">");
}

void rmv_arrow (int y)
{
	setcolor(WHITE);
	outtextxy(400,y," ");
}

void main_menu ()
{
	arrow(y_arrow1);
	line(30,30,1240,30);
	line(30,930,1240,930);
	line(30,30,30,930);
	line(1240,30,1240,930);
	setcolor(YELLOW);
	settextstyle(GOTHIC_FONT,HORIZ_DIR,2);
	outtextxy(60,60,"Space Shooter");
	settextstyle(SMALL_FONT,HORIZ_DIR,5);
	outtextxy(62,86,"by AHSAN JAVED");
	setcolor(WHITE);
	settextstyle(BOLD_FONT,HORIZ_DIR,4);
	outtextxy(517,460,"START Game");
	outtextxy(520,560,"EXIT Game");
	settextstyle(BOLD_FONT,HORIZ_DIR,7);
	outtextxy(440,310,"MAIN MENU");
	line(435,380,785,380);
	line(435,385,785,385);
	if (GetAsyncKeyState(VK_UP))
	{
		if (y_arrow1 > 460)		// bounding the Upward distance...
		{
			rmv_arrow(y_arrow1);
			y_arrow1 -= 100;
			Beep(1000,25);
		}
	}
	if (GetAsyncKeyState(VK_DOWN))
	{
		if (y_arrow1 < 560)		// bounding the Downward distance...
		{
			rmv_arrow(y_arrow1);
			y_arrow1 += 100;
			Beep(1000,25);
		}
	}
}

void mode_menu ()
{
	arrow(y_arrow2);
	line(30,30,1240,30);
	line(30,930,1240,930);
	line(30,30,30,930);
	line(1240,30,1240,930);
	setcolor(YELLOW);
	settextstyle(GOTHIC_FONT,HORIZ_DIR,2);
	outtextxy(60,60,"Space Shooter");
	settextstyle(SMALL_FONT,HORIZ_DIR,5);
	outtextxy(62,86,"by AHSAN JAVED");
	setcolor(WHITE);
	settextstyle(BOLD_FONT,HORIZ_DIR,4);
	outtextxy(520,400,"ARCADE Mode");
	outtextxy(518,500,"CLASSIC Mode");
	outtextxy(520,600,"Back");
	settextstyle(BOLD_FONT,HORIZ_DIR,7);
	outtextxy(440,250,"START GAME");
	line(440,320,820,320);
	line(440,325,820,325);
	if (GetAsyncKeyState(VK_UP))
	{
		delay(300);
		if (y_arrow2 > 400)		// bounding the Upward distance...
		{
			rmv_arrow(y_arrow2);
			y_arrow2 -= 100;
			Beep(1000,25);
		}
	}
	if (GetAsyncKeyState(VK_DOWN))
	{
		delay(300);
		if (y_arrow2 < 600)		// bounding the Downward distance...
		{
			rmv_arrow(y_arrow2);
			y_arrow2 += 100;
			Beep(1000,25);
		}
	}
}

void diff_menu ()
{
	arrow(y_arrow3);
	line(30,30,1240,30);
	line(30,930,1240,930);
	line(30,30,30,930);
	line(1240,30,1240,930);
	setcolor(YELLOW);
	settextstyle(GOTHIC_FONT,HORIZ_DIR,2);
	outtextxy(60,60,"Space Shooter");
	settextstyle(SMALL_FONT,HORIZ_DIR,5);
	outtextxy(62,86,"by AHSAN JAVED");
	setcolor(WHITE);
	settextstyle(BOLD_FONT,HORIZ_DIR,4);
	outtextxy(550,460,"Easy");
	outtextxy(550,510,"Difficult");
	outtextxy(550,560,"Back");
	settextstyle(BOLD_FONT,HORIZ_DIR,7);
	outtextxy(425,300,"CLASSIC MODE");
	line(425,370,880,370);
	line(425,375,880,375);
	if (GetAsyncKeyState(VK_UP))
	{
		delay(300);
		if (y_arrow3 > 460)		// bounding the Upward distance...
		{
			rmv_arrow(y_arrow3);
			y_arrow3 -= 50;
			Beep(1000,5);
		}
	}
	if (GetAsyncKeyState(VK_DOWN))
	{
		delay(300);
		if (y_arrow3 < 560)		// bounding the Downward distance...
		{
			rmv_arrow(y_arrow3);
			y_arrow3 += 50;
			Beep(1000,5);
		}
	}	
}

void result_wind (int rslt_chk,int clsc_diff)
{
	line(30,30,1240,30);
	line(30,930,1240,930);
	line(30,30,30,930);
	line(1240,30,1240,930);
	setcolor(YELLOW);
	settextstyle(GOTHIC_FONT,HORIZ_DIR,2);
	outtextxy(60,60,"Space Shooter");
	settextstyle(SMALL_FONT,HORIZ_DIR,5);
	outtextxy(62,86,"by AHSAN JAVED");
	setcolor(WHITE);
	settextstyle(BOLD_FONT,HORIZ_DIR,7);
	outtextxy(225,300,"RESULTS:-");
	settextstyle(GOTHIC_FONT,HORIZ_DIR,2);
	if (clsc_diff == 0 || clsc_diff == 1)
	{
		if (score > highest)
		{
			setcolor(YELLOW);
			outtextxy(225,380,"CONGRATULATIONS! You have scored the highest Score!");
		}
	}
	setcolor(WHITE);
	// updating the score...
	sprintf(arr_score,"- Score %d",score);
	outtextxy(225,500,arr_score);
	// calculating the shoot average...
	if (score == 0)
	{
		shoot_accur = 0;
	}
	else
	{
		shoot_accur = (score*100)/shoot;
	}
	sprintf(arr_shoot_accur,"- Shoot Accuracy %d",shoot_accur);
	outtextxy(225,550,arr_shoot_accur);
	outtextxy(540,550,"%");
	// shifting towards main menu message...
	settextstyle(GOTHIC_FONT,HORIZ_DIR,1);
	outtextxy(225,750,"==> Press ESCAPE Key to shift towards MAIN MENU.");
	if (rslt_chk == 1)
	{
		fstream hscore;
		if (score > highest)
		{
			if (clsc_diff == 0)
			{
				hscore.open("score.txt",ios::app);
			}
			else if (clsc_diff == 1)
			{
				hscore.open("score2.txt",ios::app);
			}
			hscore<<score<<"\n";
			hscore.close();
		}
		rslt_chk = 0;
	}
}

void win_wind ()
{
	line(30,30,1240,30);
	line(30,930,1240,930);
	line(30,30,30,930);
	line(1240,30,1240,930);
	setcolor(YELLOW);
	settextstyle(GOTHIC_FONT,HORIZ_DIR,2);
	outtextxy(60,60,"Space Shooter");
	settextstyle(SMALL_FONT,HORIZ_DIR,5);
	outtextxy(62,86,"by AHSAN JAVED");
	setcolor(WHITE);
	settextstyle(BOLD_FONT,HORIZ_DIR,7);
	outtextxy(225,250,"CONGRATULATIONS!");//350
	settextstyle(BOLD_FONT,HORIZ_DIR,4);
	outtextxy(230,330,"You have WON the Game!");//450
	settextstyle(GOTHIC_FONT,HORIZ_DIR,2);
	// updating the score...
	sprintf(arr_score,"- Score %d",score);
	outtextxy(225,500,arr_score);
	// calculating the shoot average...
	if (score == 0)
	{
		shoot_accur = 0;
	}
	else
	{
		shoot_accur = (score*100)/shoot;
	}
	sprintf(arr_shoot_accur,"- Shoot Accuracy %d",shoot_accur);
	outtextxy(225,550,arr_shoot_accur);
	outtextxy(540,550,"%");
	// shifting towards main menu message...
	settextstyle(GOTHIC_FONT,HORIZ_DIR,1);
	outtextxy(225,750,"==> Press ESCAPE Key to shift towards MAIN MENU.");
}

int main()
{
	initwindow(1280,1024);
	lab:
	int clrscr_chk1=0,clrscr_chk2=0,clrscr_chk3=0,clrscr_chk4=0;
	int mode,clsc_diff,main_menu_chk=1,mode_menu_chk=0,diff_menu_chk=0,result_wind_chk=0,win_wind_chk=0;
	double x_stage1[7] = {90,210,330,450,570,690,810};
	double y_stage1[7] = {-870,-2470,-3270,0,-1670,-400,-1000};
	double rec_y_stage1[7] = {-870,-2470,-3270,0,-1670,-400,-1000};
	double x_stage2[10] = {90,170,250,330,410,490,570,650,730,810};
	double y_stage2[10] = {-130,-920,-4440,0,-80,-510,-790,-260,-3440,-370};
	double rec_y_stage2[10] = {-130,-920,-4440,0,-80,-510,-790,-260,-3440,-370};
	double x_stage3[7] = {90,210,330,450,570,690,810};
	double y_stage3[7] = {-80,-240,-170,0,-1170,-450,-710};
	double rec_y_stage3[7] = {-80,-240,-170,0,-1170,-450,-710};
	double x_stage4[10] = {90,170,250,330,410,490,570,650,730,810};
	double y_stage4[10] = {-130,-920,-440,0,-80,-510,-790,-260,30,-370};
	double rec_y_stage4[10] = {-130,-920,-440,0,-80,-510,-790,-260,30,-370};
	double x_stage5[1] = {580};
	double y_stage5[1] = {-130};
	double rec_y_stage5[2] = {-130,-45};
	double clsc_x_stage[10] = {570,170,730,810,250,490,90,650,410,330};
	double clsc_y_stage[10] = {-6300,-900,-7200,-3600,-5400,0,-4500,-2700,-8100,-1800};
	double clsc_rec_y_stage[10] = {-6300,-900,-7200,-3600,-5400,0,-4500,-2700,-8100,-1800};
	fstream hscore;
	hscore.open("score.txt",ios::in);
	while(!hscore.eof())
	{
		hscore>>num;
		if (num > highest1)
		{
			highest1 = num;		
		}
	}
	hscore.close();
	hscore.open("score2.txt",ios::in);
	while(!hscore.eof())
	{
		hscore>>num;
		if (num > highest2)
		{
			highest2 = num;		
		}
	}
	hscore.close();
	
	for (int i=0 ; i<7 ; i++)
	{
		movement[i] = 0;
	}
	
	for (;;)
	{
		if (main_menu_chk == 1)
		{
			score=0;
			lives=3;
			level=1;
			shoot=0;
			clrscr_chk1=0;
			clrscr_chk2=0;
			clrscr_chk3=0;
			clrscr_chk4=0;
			main_menu();
			if (GetAsyncKeyState(VK_RETURN) && y_arrow1 == 460)
			{
				Beep(500,10);
				delay(300);
				cleardevice();
				main_menu_chk = 0;
				mode_menu_chk = 1;
			}
			else if (GetAsyncKeyState(VK_RETURN) && y_arrow1 == 560)
			{
				Beep(500,10);
				break;
			}
		}
		if (mode_menu_chk == 1)
		{
			mode_menu ();
			if (GetAsyncKeyState(VK_RETURN) && y_arrow2 == 400)
			{
				delay(300);
				Beep(500,10);
				cleardevice();
				mode_menu_chk = 0;
				mode = 1;
			}
			else if (GetAsyncKeyState(VK_RETURN) && y_arrow2 == 500)
			{
				delay(300);
				Beep(500,10);
				cleardevice();
				mode_menu_chk = 0;
				diff_menu_chk = 1;
			}
			else if (GetAsyncKeyState(VK_RETURN) && y_arrow2 == 600)
			{
				delay(300);
				Beep(500,10);
				cleardevice();
				mode_menu_chk = 0;
				main_menu_chk = 1;
			}
		}
		if (diff_menu_chk == 1)
		{
			diff_menu();
			if (GetAsyncKeyState(VK_RETURN) && y_arrow3 == 460)
			{
				delay(300);
				Beep(500,10);
				cleardevice();
				diff_menu_chk = 0;
				clsc_diff = 0;
				mode = 2;
			}
			else if (GetAsyncKeyState(VK_RETURN) && y_arrow3 == 510)
			{
				delay(300);
				Beep(500,10);
				cleardevice();
				diff_menu_chk = 0;
				clsc_diff = 1;
				mode = 2;
			}
			else if (GetAsyncKeyState(VK_RETURN) && y_arrow3 == 560)
			{
				delay(300);
				Beep(500,10);
				cleardevice();
				diff_menu_chk = 0;
				mode_menu_chk = 1;
			}
		}
		if (mode == 1)
		{
			arc_interface();
			// level 1...
			if (score >= 0 && score < 20)
			{
				if (score == 0)
				{
					outtextxy(395,500,"Level 1");
				}
				if (score == 1)
				{
					outtextxy(395,500,"            ");
				}
				arc_stage(x_stage1,y_stage1,rec_y_stage1,7,1.0,0);
			}
			// level 2...
			else if (score >= 20 && score < 40)
			{
				if (clrscr_chk1 == 0)
				{
					cleardevice();
					clrscr_chk1 = 1;
				}
				if (score == 20)
				{
					outtextxy(395,500,"Level 2");
					outtextxy(275,530,"More Speed and Enemies");
				}
				if (score == 21)
				{
					outtextxy(395,500,"            ");
					outtextxy(275,530,"                                              ");
				}
				level = 2;
				arc_stage(x_stage2,y_stage2,rec_y_stage2,10,1.8,0);
			}
			// level 3...
			if (score >= 40 && score < 50)
			{
				if (clrscr_chk2 == 0)
				{
					cleardevice();
					clrscr_chk2 = 1;
				}
				if (score == 40)
				{
					outtextxy(395,500,"Level 3");
					outtextxy(320,530,"Powerful Enemies");
				}
				if (score == 41)
				{
					outtextxy(395,500,"            ");
					outtextxy(320,530,"                                ");
				}
				level = 3;
				arc_stage(x_stage3,y_stage3,rec_y_stage3,7,1.5,1);
			}
			// level 4...
			else if (score >= 50 && score < 60)
			{
				if (clrscr_chk3 == 0)
				{
					cleardevice();
					clrscr_chk3 = 1;
				}
				if (score == 50)
				{
					outtextxy(395,500,"Level 4");
					outtextxy(285,530,"More Powerful Enemies");
				}
				if (score == 51)
				{
					outtextxy(395,500,"            ");
					outtextxy(285,530,"                                         ");
				}
				level = 4;
				arc_stage(x_stage4,y_stage4,rec_y_stage4,10,1.2,2);	
			}
			// level 5...
			else if (score >= 60 && score < 70)
			{
				if (clrscr_chk4 == 0)
				{
					cleardevice();
					clrscr_chk4 = 1;
				}
				if (score == 60)
				{
					outtextxy(395,500,"Final LEVEL");
					outtextxy(350,530,"Defeat the 'BOSS'!");
				}
				if (score == 61)
				{
					outtextxy(395,500,"                     ");
					outtextxy(350,530,"                                      ");
				}
				level = 5;
				arc_stage(x_stage5,y_stage5,rec_y_stage5,1,1.5,3);
			}
			if (score == 70)
			{
				cleardevice();
				win_wind_chk=1;
				mode = 0;
			}
		}
		else if (mode == 2)
		{
			int rslt_chk=1;
			clsc_interface(clsc_diff);
			clsc_stage(clsc_x_stage,clsc_y_stage,clsc_rec_y_stage,1.1,clsc_diff);
		}
		if (mode == 1 || mode == 2)
		{
			spaceship(x_spaceship);
			rmv_spaceship(x_spaceship);
			mov_spaceship();
			bullet_prop();
			if (lives <= 0)
			{
				cleardevice();
				result_wind_chk = 1;
				mode = 0;
			}
			if (GetAsyncKeyState(VK_ESCAPE))
			{
				Beep(500,10);
				cleardevice();
				result_wind_chk = 1;
				mode = 0;
			}
		}
		if (result_wind_chk == 1)
		{
			delay(300);
			result_wind(rslt_chk,clsc_diff);
			if (GetAsyncKeyState(VK_ESCAPE))
			{
				Beep(500,10);
				cleardevice();
				result_wind_chk = 0;
				goto lab;
			}
		}
		if (win_wind_chk == 1)
		{
			win_wind();
			if (GetAsyncKeyState(VK_ESCAPE))
			{
				Beep(500,10);
				cleardevice();
				win_wind_chk = 0;
				goto lab;
			}
		}
		delay(10);
	}
	getch();
	return 0;			
}