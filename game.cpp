//============================================================================
// Name        : game.cpp
// Author      : Hassan Mustafa
// Version     :
// Copyright   : (c) Reserved
// Description : Basic 2D game of Dodge 'Em...
//============================================================================

#ifndef DODGE_CPP_
#define DODGE_CPP_
#include "util.h"
#include <iostream>
#include<string>
#include<cmath> 
#include<fstream>// for basic math functions such as cos, sin, sqrt
using namespace std;
bool move_right=false;
bool move_left=false;//global variable used in all fuction
bool move_up=false;
bool move_down=false;
int ax=50;
int ay=50;
float xmy = 468; 
float ymy = 46; 
const int sx = 20;
const int sy = 10;
float x2 = 300; 
float y2 = 46; 
int array[860][860];
int score=0;
int lives=3;
int menu=0;
int carpath;
int comppath;
int comppath2;
int level=3;
float x3=620;
float y3=680;
int highscore;
// seed the random numbers generator by current time (see the documentation of srand for further help)...

/* Function sets canvas size (drawing area) in pixels...
 *  that is what dimensions (x and y) your game will have
 *  Note that the bottom-left coordinate has value (0,0) and top-right coordinate has value (width-1,height-1)
 * */
void SetCanvasSize(int width, int height) {
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, width, 0, height, -1, 1); // set the screen size to given width and height.
	glMatrixMode (GL_MODELVIEW);
	glLoadIdentity();
}


/*
 * Main Canvas drawing function.
 * */
//Board *b;
void GameDisplay()/**/{
	// set the background color using function glClearColor.
	// to change the background play with the red, green and blue values below.
	// Note that r, g and b values must be in the range [0,1] where 0 means dim rid and 1 means pure red and so on.

	glClearColor(0/*Red Component*/, 0,	//148.0/255/*Green Component*/,
			0.0/*Blue Component*/, 0 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
	glClear (GL_COLOR_BUFFER_BIT); //Update the colors

	// calling some functions from util.cpp file to help students

	//Square at 400,20 position
	//DrawSquare( 400 , 20 ,40,colors[RED]); 
	//Square at 250,250 position
	DrawSquare(  0, 0 ,1000,colors[GREEN]); 
	//Display Score
	//DrawString( 50, 800, "Score=0", colors[MISTY_ROSE]);
	//Triangle at 300, 4508 position
	//DrawTriangle( 300, 450 , 340, 450 , 320 , 490, colors[MISTY_ROSE] ); 
	// Trianlge Vertices v1(300,50) , v2(500,50) , v3(400,250)
	//Circle at 50, 670 position
	
	
	




	//Line from 550,50 to 550,480 with width 10
	//DrawLine(int x1, int y1, int x2, int y2, int lwidth, float *color)
	//DrawLine( 550 , 50 ,  550 , 480 , 10 , colors[MISTY_ROSE] );	
	
	// Drawing opponent car
	//float x = 673; 
	//float y = 96;

/*if(score<=96)
{
level=1;
 move_right=false;
 move_left=false;
 move_up=false;
 move_down=false;
 ax=50;
 ay=50;
 xmy = 468; 
 ymy = 46; 

 x2 = 300; 
 y2 = 46; 
 score=0;


}
if(score>92&&score<=292)
	{
	level=2;
	
 move_right=false;
 move_left=false;
 move_up=false;
 move_down=false;
 ax=50;
 ay=50;
 xmy = 468; 
 ymy = 46; 
 
 x2 = 300; 
 y2 = 46; 
 score+=100;
}
if(score>192&&score<=288)
	{
	level=3;
 move_right=false;
 move_left=false;
 move_up=false;
 move_down=false;
 ax=50;
 ay=50;
 xmy = 468; 
 ymy = 46; 
 
 x2 = 300; 
 y2 = 46; 
 score+=100;
}
if(score>288&&score<384)
	{
	level=4;
 move_right=false;
 move_left=false;
 move_up=false;
 move_down=false;
 ax=50;
 ay=50;
 xmy = 468; 
 ymy = 46; 
 
 x2 = 300; 
 y2 = 46; 
 score+=100;
}*/
	if(score<96)//when score is less than 96 level is
	{
		 level=1;
	}
	if(score==96)//score==96 level is 2
	{
		 level=2;
		

		for(int i=0;i<840;i++)//redrwanig of food
			{
				for(int j=0;j<840;j++)
					{
		array[i][j]={0};
		}
		}		
		for(int i=60;i<840;i+=80)
		{
			for(int j=60;j<840;j+=80)
			{
			if(i>=400&&i<=470){i+=10;}
			if(array[i][j]!=1){DrawCircle(i,j,8,colors[PURPLE]);
			}else{
				
				}			
								
					//DrawCircle(i,j,8,colors[PURPLE]);
				}
		
			}
	}
	if(score==192)//score is equal to 192 level is equal to 3
		{
			level=3;
			for(int i=0;i<840;i++)
				{
					for(int j=0;j<840;j++)
						{
			array[i][j]={0};
			}
			}		
			for(int i=60;i<840;i+=80)
			{
				for(int j=60;j<840;j+=80)
				{
				if(i>=400&&i<=470){i+=10;}
				if(array[i][j]!=1){DrawCircle(i,j,8,colors[PURPLE]);
				}else{
				
					}			
									
						//DrawCircle(i,j,8,colors[PURPLE]);
					}
			
			}
			}
		if(score==288)//if score is equal to 288 level is equal to 288
		{
			level=4;
			for(int i=0;i<840;i++)
				{
					for(int j=0;j<840;j++)
						{
							array[i][j]={0};
					}
				}		
				for(int i=60;i<840;i+=80)
				{
					for(int j=60;j<840;j+=80)
			{
				if(i>=400&&i<=470){i+=10;}
				if(array[i][j]!=1){DrawCircle(i,j,8,colors[PURPLE]);
				}else{
					
					}			
										
						//DrawCircle(i,j,8,colors[PURPLE]);
					}
		
			}

	
	
			}
		if(score==384)//when score is equal to 384 player won
		{
			DrawSquare(  0, 0 ,1000,colors[BLUE]);
			DrawString( 50+200, 450, "You WOn", colors[MISTY_ROSE]);
		}

	if(level==1)//level display
	{
	DrawString( 120, 803, "level=1", colors[RED]);
	}
	if(level==2)
	{
	DrawString( 120, 803, "level=2", colors[RED]);
	}
	if(level==3)
	{
	DrawString( 120, 803, "level=3", colors[RED]);
	}
	if(level==4)
	{
	DrawString( 120, 803, "level=4", colors[RED]);

}


	if(menu==0)//when menu==0 command of menu will show
	{

	DrawSquare(  0, 0 ,1000,colors[RED]);
	DrawString( 50+200, 450, "1)PRESS ONE TO PLAY", colors[MISTY_ROSE]);
	DrawString( 50+200, 400, "2)PRESS Two for Help", colors[MISTY_ROSE]);
	DrawString( 50+200, 350, "3)PRESS three for Highscore", colors[MISTY_ROSE]);
	DrawString( 50+200, 250, "4)PRESS three to Quit", colors[MISTY_ROSE]);
	}
	if(menu==2) //when menu is 2 help will display
	{
	DrawSquare(  0, 0 ,1000,colors[ORANGE]);
	DrawString( 50+100, 400,"1)PRESS  UP key to move up ", colors[MISTY_ROSE]);
	DrawString(50+100,350,"2)PRESS  down key to move down", colors[MISTY_ROSE]);
	DrawString(50+100,300,"3)PRESS  right key to move right", colors[MISTY_ROSE]);
	DrawString(50+100,270,"4)Press space bar to speed up  ", colors[MISTY_ROSE]);

	}
	if(menu==3) //when menu==3 highscore will display
	{
	ifstream high;
	high.open("high_score.txt");
	high>>highscore;
	high.close();
	if(highscore<score)
	{
		highscore=score;
	}
		ofstream highk;
		highk.open("high_score.txt");
		highk<<highscore;
		highk.close();

	} 
	if(menu==1)//when menu is 1 game will continue
	{
		
		//player car
		float width = 10; 
		float height = 7.5;
		float* color = colors[ORANGE]; 
		float radius = 5.0;
		DrawRoundRect(xmy,ymy,width,height,color,radius); // bottom left tyre
		DrawRoundRect(xmy+width*3,ymy,width,height,color,radius); // bottom right tyre
		DrawRoundRect(xmy+width*3,ymy+height*4,width,height,color,radius); // top right tyre
		DrawRoundRect(xmy,ymy+height*4,width,height,color,radius); // top left tyre
		DrawRoundRect(xmy, ymy+height*2, width, height, color, radius/2); // body left rect
		DrawRoundRect(xmy+width, ymy+height, width*2, height*3, color, radius/2); // body center rect
		DrawRoundRect(xmy+width*3, ymy+height*2, width, height, color, radius/2); // body right rect*/
		//computer controlled car
		float width2 = 10; 
		float height2 = 7.5;
		float* color2 = colors[INDIGO]; 
		float radius2 = 5.0;
		DrawRoundRect(x2,y2,width2,height2,color2,radius2); // bottom left tyre
		DrawRoundRect(x2+width2*3,y2,width2,height2,color2,radius2); // bottom right tyre
		DrawRoundRect(x2+width2*3,y2+height2*4,width2,height2,color2,radius2); // top right tyre
		DrawRoundRect(x2,y2+height2*4,width2,height2,color2,radius2); // top left tyre
		DrawRoundRect(x2, y2+height2*2, width2, height2, color2, radius2/2); // body left rect
		DrawRoundRect(x2+width2, y2+height2, width2*2, height2*3, color2, radius2/2); // body center rect
		DrawRoundRect(x2+width2*3, y2+height2*2, width2, height2, color2, radius2/2); // body right rect
		//conversion of score intp string to displayed on screen
		string scr=to_string(score);
		DrawString( 510, 803, scr, colors[RED]);

	if(level==4) //computer controlled car when level is 4
	{
		float width3 = 10; 
		float height3 = 7.5;
		float* color3 = colors[KHAKI]; 
		float radius3 = 5.0;
		DrawRoundRect(x3,y3,width3,height3,color3,radius3); // bottom left tyre
		DrawRoundRect(x3+width3*3,y3,width3,height3,color3,radius3); // bottom right tyre
		DrawRoundRect(x3+width3*3,y3+height3*4,width3,height3,color3,radius3); // top right tyre
		DrawRoundRect(x3,y3+height3*4,width3,height3,color3,radius3); // top left tyre
		DrawRoundRect(x3, y3+height3*2, width3, height3, color3, radius3/2); // body left rect
		DrawRoundRect(x3+width3, y3+height3, width3*2, height3*3, color3, radius3/2); // body center rect
		DrawRoundRect(x3+width3*3, y3+height3*2, width3, height3, color3, radius3/2); // body right rect
	}
		
		// Drawing Arena
		// Drawing Arena 1
		int gap_turn = 80;
		int sx = 50;
		int sy = 40;
		int swidth = 765/2 - gap_turn/2; // half width
		int sheight = 05;
		float *scolor = colors[BROWN];
		DrawRectangle(sx, sy, swidth, sheight, scolor); // bottom left
		DrawRectangle(sx + swidth + gap_turn, sy, swidth, sheight, scolor); // bottom right
		/*DrawRectangle(ax,ay,10,10,scolor);*/
		DrawRectangle(sx+swidth*2+gap_turn, sy+sheight, sheight*2, swidth, scolor); // right down
		DrawRectangle(sx+swidth*2+gap_turn, sy+sheight+swidth+gap_turn, sheight*2, swidth, scolor); // right up
		DrawRectangle(sx + swidth + gap_turn, sy+760, swidth, sheight, scolor); // top left
		DrawRectangle(sx, sy+760, swidth, sheight, scolor); // top right
		DrawRectangle(sx-sheight*3, sy+sheight+swidth+gap_turn, sheight*3, swidth, scolor); // left up
		DrawRectangle(sx-sheight*2, sy+sheight, sheight*2, swidth, scolor); // left down
		
		
		 /*if(  (xmy==x2-1 && ymy==y2) || (xmy==x2 && ymy==y2) )*/ //crash when x and y axus are same 
		while((xmy<=x2-5)&&(xmy>=x2+5)&&(ymy<=y2-5)&&(ymy>=y2+5)||(ymy==y2&&xmy==x2)||(xmy==x2-1 && ymy==y2) || (xmy==x2 && ymy==y2))	//condition for crashing car 
		{


		cout<<"hello world"<<endl;
			
			 x2 = 24+150; 
			 y2 = 46; 
			 xmy=30+450; 
			 ymy = 46;
			lives=lives-1;
			score=0;

			for(int i=0;i<840;i++)
				{
					for(int j=0;j<840;j++)
						{
			array[i][j]={0};
			}
			}		
			for(int i=60;i<840;i+=80)
			{
				for(int j=60;j<840;j+=80)
				{
				if(i>=400&&i<=470){i+=10;}
				if(array[i][j]!=1){DrawCircle(i,j,8,colors[PURPLE]);
				}else{
					
					}			
									
						//DrawCircle(i,j,8,colors[PURPLE]);
					
			
				}
				
			
		}
	}
	if(level==4) ///works only in level for ///new opponent car crashing condutions
	{
	while((xmy<=x3-5)&&(xmy>=x3+5)&&(ymy<=y3-5)&&(ymy>=y3+5)||(ymy==y3&&xmy==x3)||(xmy==x3-1 && ymy==y3) || (xmy==x3 && ymy==y3))	
		{


		cout<<"hello world"<<endl;
			
			 x3 = 24+150; 
			 y3 = 46; 
			 xmy=30+450; 
			 ymy = 46;
			lives=lives-1;
			score=0;

			for(int i=0;i<840;i++)
				{
					for(int j=0;j<840;j++)
						{
			array[i][j]={0};
			}
			}		
			for(int i=60;i<840;i+=80)
			{
				for(int j=60;j<840;j+=80)
				{
				if(i>=400&&i<=470){i+=10;}
				if(array[i][j]!=1){DrawCircle(i,j,8,colors[PURPLE]);
				}else{
					
					}			
									
						//DrawCircle(i,j,8,colors[PURPLE]);
					
			
				}
				
			
		}
	}		
		
		
	}
		
		
		
		/*if(rand()%2)
		{
			if(x2==420&&y2!=80&&y2<300)
			{
				y2=y2+1;
			}
		}*/
		

		//areena 2
		int gap_turn1 = 80;
		int sx1 = 120;
		int sy1 = 120;
		int swidth1 = 610/2 - gap_turn1/2; // half width
		int sheight1 = 5;
		float *scolor1 = colors[BROWN];
		DrawRectangle(sx1, sy1, swidth1, sheight1, scolor1); // bottom left
		DrawRectangle(sx1 + swidth1 + gap_turn1, sy1, swidth1, sheight1, scolor1); // bottom right
		DrawRectangle(sx1+swidth1*2+gap_turn1, sy1+sheight1, sheight1*2, swidth1, scolor1); // right down
		DrawRectangle(sx1+swidth1*2+gap_turn1, sy1+sheight1+swidth1+gap_turn1, sheight1*2, swidth1, scolor1); // right up
		DrawRectangle(sx1 + swidth1 + gap_turn1, sy1+610, swidth1, sheight1, scolor1); // top left
		DrawRectangle(sx1, sy1+610, swidth1, sheight1, scolor1); // top right
		DrawRectangle(sx1-sheight1*2, sy1+sheight1+swidth1+gap_turn1, sheight1*2, swidth1, scolor1); // left up
		DrawRectangle(sx1-sheight1*2, sy1+sheight1, sheight1*2, swidth1, scolor1);// left down
		//arena 3
		int gap_turn2 = 80;
		int sx2 = 180;
		int sy2 = 180;
		int swidth2 = 480/2 - gap_turn2/2; // half width
		int sheight2 = 8;
		float *scolor2 = colors[BLUE];
		DrawRectangle(sx2, sy2, swidth2, sheight2, scolor2); // bottom left
		DrawRectangle(sx2 + swidth2 + gap_turn2, sy2, swidth2, sheight2, scolor2); // bottom right
		DrawRectangle(sx2+swidth2*2+gap_turn2, sy2+sheight2, sheight2*2, swidth2, scolor2); // right down
		DrawRectangle(sx2+swidth2*2+gap_turn2, sy2+sheight2+swidth2+gap_turn2, sheight2*2, swidth2, scolor2); // right up
		DrawRectangle(sx2 + swidth2 + gap_turn2, sy2+480, swidth2, sheight2, scolor2); // top left
		DrawRectangle(sx2, sy2+480, swidth2, sheight2, scolor2); // top right
		DrawRectangle(sx2-sheight2*2, sy2+sheight2+swidth2+gap_turn2, sheight2*2, swidth2, scolor2); // left up
		DrawRectangle(sx2-sheight2*2, sy2+sheight2, sheight2*2, swidth2, scolor2);// left down       
		//arena 4
		int gap_turn3 = 80;
		int sx3 = 280;
		int sy3 = 280;
		int swidth3 = 300/2 - gap_turn2/2; // half width
		int sheight3 = 8;
		float *scolor3 = colors[BROWN];
		DrawRectangle(sx3, sy3, swidth3, sheight3, scolor3); // bottom left
		DrawRectangle(sx3 + swidth3 + gap_turn3, sy3, swidth3, sheight3, scolor3); // bottom right
		DrawRectangle(sx3+swidth3*2+gap_turn3, sy3+sheight3, sheight3*2, swidth3, scolor3); // right down
		DrawRectangle(sx3+swidth3*2+gap_turn3, sy3+sheight3+swidth3+gap_turn3, sheight3*2, swidth3, scolor3); // right up
		DrawRectangle(sx3 + swidth3 + gap_turn3, sy3+300, swidth3, sheight3, scolor3); // top left
		DrawRectangle(sx3, sy3+300, swidth3, sheight3, scolor3); // top right
		DrawRectangle(sx3-sheight3*2, sy3+sheight3+swidth3+gap_turn3, sheight3*2, swidth3, scolor3); // left up
		DrawRectangle(sx3-sheight3*2, sy3+sheight2, sheight3*2, swidth3, scolor3);// left
		//arena 5		
		int gap_turn4 = 05;
		int sx4 = 370;
		int sy4 = 360;
		int swidth4 = 200/2 - gap_turn2/2; // half width
		int sheight4 = 8;
		float *scolor4 = colors[BROWN];
		DrawRectangle(sx4, sy4, swidth4, sheight4, scolor4); // bottom left
		DrawRectangle(sx4 + swidth4 + gap_turn4, sy4, swidth4, sheight4, scolor4); // bottom right
		DrawRectangle(sx4+swidth4*2+gap_turn4, sy4+sheight4, sheight4*2, swidth4, scolor4); // right down
		DrawRectangle(sx4+swidth4*2+gap_turn4, sy4+sheight4+swidth4+gap_turn4, sheight4*2, swidth4, scolor4); // right up
		DrawRectangle(sx4 + swidth4 + gap_turn4, sy4+130, swidth4, sheight4, scolor4); // top left
		DrawRectangle(sx4, sy4+130, swidth4, sheight4, scolor4); // top right
		DrawRectangle(sx4-sheight4*2, sy4+sheight4+swidth4+gap_turn4, sheight4*2, swidth4, scolor4); // left up
		DrawRectangle(sx4-sheight4*2, sy4+sheight4, sheight4*2, swidth4, scolor4);// left
		//live counter
		if(lives==3)//check lives
		{
		DrawString( 387+10, 380, "lives=3", colors[RED]);
		}
		if(lives==2)
		{
		DrawString( 387+10, 380, "lives=2", colors[RED]);
		
		}
		if(lives==1)
		{
		DrawString( 387+10, 380, "lives=1", colors[RED]);
		}
		if(lives==0)//programme exit when lives are zero
		{
		exit(1);
		}
		
	 if(lives==3)
	{
		for(int i=60;i<840;i+=80)
			{
				for(int j=60;j<840;j+=80)
				{
	if(i>=400&&i<=470){i+=10;}

	if((i>=xmy && i<=xmy+40)  && (j>=ymy && j<=ymy+40)   )
	{
					
		if(array[i][j]!=1)	
		score+=1;
		/*cout<<"score"<<score;*/
		array[i][j]= 1; /*cout<<"Here"<<endl;*/
	}

					
									
					//DrawCircle(i,j,8,colors[PURPLE]);
					
			
				}	
				
			}
		
		for(int i=60;i<840;i+=80)
			{
				for(int j=60;j<840;j+=80)
				{
	if(i>=400&&i<=470){i+=10;}
		if(array[i][j]!=1){DrawCircle(i,j,8,colors[PURPLE]);
	}else{
					
		}			
									
					//DrawCircle(i,j,8,colors[PURPLE]);
					
			
				}	
				
			}

	}
		
	 if(lives==2)//food drwaing conditons
	{
		for(int i=60;i<840;i+=80)
			{
				for(int j=60;j<840;j+=80)
				{
	if(i>=400&&i<=470){i+=10;}

	if((i>=xmy && i<=xmy+40)  && (j>=ymy && j<=ymy+40)   )
	{
					
		if(array[i][j]!=1)	
		score+=1;
		/*cout<<"score"<<score;*/
		array[i][j]= 1; /*cout<<"Here"<<endl;*/
	}

					
									
					//DrawCircle(i,j,8,colors[PURPLE]);
					
			
				}	
				
			}
		
		for(int i=60;i<840;i+=80)
			{
				for(int j=60;j<840;j+=80)
				{
	if(i>=400&&i<=470){i+=10;}
		if(array[i][j]!=1){DrawCircle(i,j,8,colors[PURPLE]);
	}else{
					
		}			
									
					//DrawCircle(i,j,8,colors[PURPLE]);
					
			
				}	
				
			}

	}
		
	 if(lives==1)
	{
		for(int i=60;i<840;i+=80)
			{
				for(int j=60;j<840;j+=80)
				{
	if(i>=400&&i<=470){i+=10;}

	if((i>=xmy && i<=xmy+40)  && (j>=ymy && j<=ymy+40)   )
	{
					
		if(array[i][j]!=1)    //removing of foof	
		score+=1;//increamenting score 
		/*cout<<"score"<<score;*/
		array[i][j]= 1; /*cout<<"Here"<<endl;*/
	}

					
									
					//DrawCircle(i,j,8,colors[PURPLE]);
					
			
				}	
				
			}
		
		for(int i=60;i<840;i+=80)
			{
				for(int j=60;j<840;j+=80)
				{
	if(i>=400&&i<=470){i+=10;}
		if(array[i][j]!=1){DrawCircle(i,j,8,colors[PURPLE]);
	}else{
					
		}			
									
					//DrawCircle(i,j,8,colors[PURPLE]);
					
			
				}	
				
			}

	}
	//to keep car in between boundary	
	if(xmy>820)
	{
			move_left=true;
		        move_right=false;
		        move_up=false;
		        move_down=false;
	}
	if(ymy>820)
	{
			move_left=false;
		        move_right=false;
		        move_up=false;
		        move_down=true;
	}	
	if(xmy<10)
	{	
			move_left=false;
		        move_right=true;
		        move_up=false;
		        move_down=false;
	}	
	if(ymy<10)
	{
		move_left=false;
		        move_right=false;
		        move_up=true;
		        move_down=true;
	}	
		
		
		
		
		/*for(sx=40;sx<=880;sx+=70)
			{
				for(sy=40;sy<880;sy+=70)
				{
					if(x==sx||y==sy)
					{
					DrawCircle(sx,sy,5,colors[BLACK]);
					sy=-500;
					sx=-500;			
					}
			
			
				}	
				
			}*/

		
	}


		 glutPostRedisplay();
		glutSwapBuffers(); // do not modify this line.. or draw anything below this line
}

/*This function is called (automatically) whenever any non-printable key (such as up-arrow, down-arraw)
 * is pressed from the keyboard
 *
 * You will have to add the necessary code here when the arrow keys are pressed or any other key is pressed...
 *
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 *
 * */








void NonPrintableKeys(int key, int x, int y) {
	if (key
			== GLUT_KEY_LEFT /*GLUT_KEY_LEFT is constant and contains ASCII for left arrow key*/){
                if(ymy>390 && ymy<450) ///retricting car movement
		// what to do when left key is pressed...
		{move_left=true;
                move_right=false;
                move_up=false;
                move_down=false;
		}

	} else if (key
			== GLUT_KEY_RIGHT /*GLUT_KEY_RIGHT is constant and contains ASCII for right arrow key*/) {
               if(ymy>390 && ymy<450)
               {move_left=false;
                move_right=true;
                move_up=false;
                move_down=false;
		}
  

	} else if (key
			== GLUT_KEY_UP/*GLUT_KEY_UP is constant and contains ASCII for up arrow key*/) {
               if(xmy>360 && xmy<420)
              { move_left=false;
                move_right=false;
                move_up=true;
                move_down=false;
		}
	}

	else if (key
			== GLUT_KEY_DOWN/*GLUT_KEY_DOWN is constant and contains ASCII for down arrow key*/) {
               if(xmy>360 && xmy<420)
              {move_left=false;
                move_right=false;
                move_up=false;
                move_down=true;}
		
	}


	/* This function calls the Display function to redo the drawing. Whenever you need to redraw just call
	 * this function*/

	//glutPostRedisplay();

}

/*This function is called (automatically) whenever any printable key (such as x,b, enter, etc.)
 * is pressed from the keyboard
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 * */
void PrintableKeys(unsigned char key, int x, int y) {
	if (key == 27/* Escape key ASCII*/) {
		exit(1); // exit the program when escape key is pressed.
	}

	if (key =='1')
			{
		//do something if b is pressed
		menu=1;
		
		
	}
	if(key =='2')
	{
		menu=2;

	}
	if(key=='P'||key=='p')//p pressed game will pause
	{
	menu=0;
	}
	if(key=='3')
	{
	menu=3;
	}
	if(key=='4')
	{
	exit(1);
	}
	glutPostRedisplay();
}

/*
 * This function is called after every 1000.0/FPS milliseconds
 * (FPS is defined on in the beginning).
 * You can use this function to animate objects and control the
 * speed of different moving objects by varying the constant FPS.
 *
 * */
void Timer(int m) {

	// implement your functionality here
	if(move_right)//player car movement
	   {
             //ax++;
             
		xmy+=1;//right
		
		/*cout<<"y1:"<<ymy<<endl;
		cout<<"x1:"<<xmy<<endl;*/
             
          }
        if(move_up)
          {
              
             	 ymy+=1;//up
		
		/*cout<<"x1:"<<xmy<<endl;
		cout<<"y1:"<<ymy<<endl;*/
          }
        if(move_down)
        {
			
		   ymy-=1;//down
		/*cout<<"x2:"<<xmy;
		cout<<"y1:"<<ymy<<endl;*/
	}
        if(move_left)
	{	
             	
             	xmy-=1;//lwft

		/*cout<<"y3"<<ymy;
		cout<<"x1:"<<xmy<<endl;*/
		
	}	
	/*if(x=825)
	{
	move_right=true;
	move_down=false;
	} */      
		
	/*if(y<=32&&x<=110)
	{
		 move_left=false;
                move_right=true;
                move_up=false;
                move_down=false;
	}
	if(y<=50&&x>=760)
	{
		 move_left=false;
                move_right=false;
                move_up=true;
                move_down=false;
	}
	if(y>=750&&x>=755)
	{
		 move_left=true;
                move_right=false;
                move_up=false;
                move_down=false;
	}
	if(y>=750&&x<=40)
	{
		 move_left=false;
                move_right=false;
                move_up=false;
                move_down=true;
	}
	if(x>180&&x<230&&y>=602&&y<=627)
	{
		move_left=false;
                move_right=false;
                move_up=false;
                move_down=true;
	}
	if(x>=210&&x<=219&&y>200&&y<230)
	{
		move_left=false;
                move_right=true;
                move_up=false;
                move_down=false;
	}
	if(y>190&&y<235&&x>600&&x<640)
	{
		move_left=false;
                move_right=false;
                move_up=true;
                move_down=false;
	}
	

	if(x>690&&x<720&&y>90&&y<120)
	{
		move_left=false;
                move_right=false;
                move_up=true;
                move_down=false;
	}

	if(x>685&&x<698&&y>685&&y<698)
	{
		move_left=true;
                move_right=false;
                move_up=false;
                move_down=false;
	}
	
	if(x>110&&x<130&&y>680&&y<698)
	{
		move_left=false;
                move_right=false;
                move_up=false;
                move_down=true;
	}
	if(x>110&&x<130&&y>94&&y<115)
	{
		move_left=false;
                move_right=true;
                move_up=false;
                move_down=false;
	}
	
	if(x>219&&x<230&&y>190&&y<230)
	{
		move_left=false;
                move_right=true;
                move_up=false;
                move_down=false;
	}*/
	
	



	/*if(y2<=32&&x2<=100)
	{
		 x2+=4;
		
				
	}
	if(y2<=50&&x2>=760)
	{
	         y2-=4;	 
	}
	if(y2>=750&&x2>=755)
	{
		x2-=4;
	}
	if(y2>=750&&x2<=40)
	{
		y2+=4;	
	}*/
	/*if(x>600&&x<650&&y>=614&&y<=627)
	{
	move_left=true;
                move_right=false;
                move_up=false;
                move_down=false;
	}
	if(x>286&&x<320&&y>=290&&y<=320)
	{
	move_left=false;
                move_right=true;
                move_up=false;
                move_down=false;
	}
	if(x>490&&x<540&&y>=310&&y<=330)
	{
	move_left=false;
                move_right=false;
                move_up=true;
                move_down=false;
	}
	if(x>280&&x<320&&y>=510&&y<=530)
	{
	move_left=false;
                move_right=false;
                move_up=false;
                move_down=true;
	}
	if(x>480&&x<520&&y>=510&&y<=530)//restiction for player
	{
	move_left=true;
                move_right=false;
                move_up=false;
                move_down=false;
	}
	if(x>720&&x<790&&y>=460&&y<=720)
	{
	move_left=false;
                move_right=false;
                move_up=true;
                move_down=false;
	}
	if(x>740&&x<780&&y>=140&&y<=360)
	{
	move_left=false;
                move_right=false;
                move_up=true;
                move_down=false;
	}
	if(x>480&&x<725&&y>=740&&y<=800)
	{
	move_left=true;
                move_right=false;
                move_up=false;
                move_down=false;
	}
	if(x>70&&x<380&&y>=740&&y<=800)
	{
	move_left=true;
                move_right=false;
                move_up=false;
                move_down=false;
	}
	if(x>0&&x<60&&y>=460&&y<=750)
	{
	move_left=false;
                move_right=false;
                move_up=false;
                move_down=true;
	}
	if(x>0&&x<60&&y>=76&&y<=375)
	{
	move_left=false;
                move_right=false;
                move_up=false;
                move_down=true;
	}
	if(x>0&&x<360&&y>=0&&y<=76)
	{
	move_left=false;
                move_right=true;
                move_up=false;
                move_down=false;
	}
	if(x>444&&x<780&&y>=0&&y<=76)
	{
	move_left=false;
                move_right=true;
                move_up=false;
                move_down=false;
	}*/
	
	
		
			
	 /*if(x>=800)
           {
                move_left=false;
                move_right=false;
                move_up=false;
                move_down=false;
           }
	if(y<=35)
           {
                move_left=false;
                move_right=false;
                move_up=false;
                move_down=false;
           }
	if(x<22&&y<=800)
	{
                move_left=false;
                move_right=false;
                move_up=false;
                move_down=false;
           }	
	if(y>=780)
           {
                move_left=false;
                move_right=false;
                move_up=false;
                move_down=false;
           }*/

	
	/*if((y>=102&&y<=385)||(x>=740&&x<=743))
	{
		  move_left=false;
                move_right=false;
                move_up=false;
                move_down=true;	
	}*/

	if(level==1||level==2||level==4)//level 3 has different speed
{
	if(y2==46 && x2!=48)//computer driven car //areena 1 conditon
	{
		x2=x2-1;
		comppath=1;//path check for ai movement
		cout<<"x2:"<<x2;	
	}	
	else if( x2==48 && y2!=762)
		{		
		y2=y2+1;
		comppath=1;//path check for ai movement
		cout<<"y2:"<<y2;
		}
	else if(y2==762 && x2!=776)
		{
			x2=x2+1;
		comppath=1;
			cout<<"x2:"<<x2;		
		}	
	else if( x2==776 && y2!=46)
		{
				
				y2=y2-1;
				comppath=1;
				/*cout<<"y2"<<y2;*/
		}
	if(y2==124&&x2!=122&&y2!=46&&x2!=48&&x2!=776) //arena 2 movement condition
	{	
		x2=x2-1;
		comppath=2;//path check for ai movement
	}
	if(x2==122&&y2!=680&&x2!=48&&y2!=762&&y2!=46)
	{
		y2=y2+1;
		comppath=2;
	}
	if(y2==680&&x2!=688&&x2!=48&&y2!=762&&y2!=46&&x2!=776)
	{
		x2=x2+1;
		comppath=2;//path check for ai movement
	}
	if(x2==688&&y2!=124&&x2!=48&&y2!=762&&y2!=46&&y2!=776)
	{
		y2=y2-1;
		comppath=2;
	}


	if(y2==204&&x2!=204&&x2!=48&&y2!=762&&y2!=46&&y2!=762&&y2!=124&&x2!=122&&x2!=776&&x2!=688) //areena 3 movement conditiom
	{
		x2=x2-1;
		comppath=3;//path check for ai movement
	}
	if(y2==604&&x2!=620&&x2!=48&&y2!=762&&y2!=46&&y2!=776&&y2!=124&&x2!=122&&x2!=776&&x2!=688)
	{
		x2=x2+1;
		comppath=3;
	}
	if(x2==204&&y2!=604&&x2!=48&&x2!=776&&x2!=122&&x2!=688&&y2!=46&&y2!=762&&y2!=680&&y2!=124)
	{
		y2=y2+1;
		comppath=3;//path check for ai movement
	}
	if(x2==620&&y2!=204&&x2!=48&&x2!=776&&x2!=122&&x2!=688&&y2!=46&&y2!=762&&y2!=124&&y2!=680)
	{
		y2=y2-1;
		comppath=3;
	}
	


	if(y2==288&&x2!=292&&x2!=48&&y2!=762&&y2!=46&&y2!=762&&y2!=124&&x2!=122&&x2!=776&&x2!=688&&x2!=620&&x2!=204) //arena 4 movement condition
	{
		x2=x2-1;
		comppath=4;//path check for ai movement
	}
	if(y2==526&&x2!=540&&x2!=48&&y2!=762&&y2!=46&&y2!=776&&y2!=124&&x2!=122&&x2!=776&&x2!=688&&x2!=620&&x2!=204)
	{
		x2=x2+1;
		comppath=4;//path check for ai movement
	}
	if(x2==292&&y2!=526&&x2!=48&&x2!=776&&x2!=122&&x2!=688&&y2!=46&&y2!=762&&y2!=680&&y2!=124&&y2!=204&&y2!=604)
	{
		y2=y2+1;
		comppath=4;
	}
	if(x2==540&&y2!=288&&x2!=48&&x2!=776&&x2!=122&&x2!=688&&y2!=46&&y2!=762&&y2!=124&&y2!=680&&y2!=204&&y2!=604)
	{
		y2=y2-1;
		comppath=4;//path check for ai movement
	}
		



//level 4 condition for second oppoent car
	if(y3==46 && x3!=48)//computer driven car   
	{
		x3=x3-1;
		comppath2=1;//path check for ai movement
		cout<<"x2:"<<x2;	
	}	
	else if( x3==48 && y3!=762)
		{		
		y3=y3+1;
		comppath2=1;
		cout<<"y2:"<<y2;
		}
	else if(y3==762 && x3!=776)
		{
			x3=x3+1;
		comppath2=1;
			cout<<"x2:"<<x2;		
		}	
	else if( x3==776 && y3!=46)
		{
				
				y3=y3-1;
				comppath2=1;
				/*cout<<"y2"<<y2;*/
		}
	if(y3==124&&x3!=122&&y3!=46&&x3!=48&&x3!=776)
	{	
		x3=x3-1;
		comppath2=2;
	}
	if(x3==122&&y3!=680&&x3!=48&&y3!=762&&y3!=46)
	{
		y3=y3+1;
		comppath2=2;//path check for ai movement
	}
	if(y3==680&&x3!=688&&x3!=48&&y3!=762&&y3!=46&&x3!=776)
	{
		x3=x3+1;
		comppath2=2;
	}
	if(x3==688&&y3!=124&&x3!=48&&y3!=762&&y3!=46&&y3!=776)
	{
		y3=y3-1;
		comppath2=2;//path check for ai movement
	}


	if(y3==204&&x3!=204&&x3!=48&&y3!=762&&y3!=46&&y3!=762&&y3!=124&&x3!=122&&x3!=776&&x3!=688)
	{
		x3=x3-1;
		comppath2=3;
	}
	if(y3==604&&x3!=620&&x3!=48&&y3!=762&&y3!=46&&y3!=776&&y3!=124&&x3!=122&&x3!=776&&x3!=688)
	{
		x3=x3+1;
		comppath2=3;
	}
	if(x3==204&&y3!=604&&x3!=48&&x3!=776&&x3!=122&&x3!=688&&y3!=46&&y3!=762&&y3!=680&&y3!=124)
	{
		y3=y3+1;
		comppath2=3;//path check for ai movement
	}
	if(x3==620&&y3!=204&&x3!=48&&x3!=776&&x3!=122&&x3!=688&&y3!=46&&y3!=762&&y3!=124&&y3!=680)
	{
		y3=y3-1;
		comppath2=3;
	}
	


	if(y3==288&&x3!=292&&x3!=48&&y3!=762&&y3!=46&&y3!=762&&y3!=124&&x3!=122&&x3!=776&&x3!=688&&x3!=620&&x3!=204)
	{
		x3=x3-1;
		comppath2=4;
	}
	if(y3==526&&x3!=540&&x3!=48&&y3!=762&&y3!=46&&y3!=776&&y3!=124&&x3!=122&&x3!=776&&x3!=688&&x3!=620&&x3!=204)
	{
		x3=x3+1;
		comppath2=4;//path check for ai movement
	}
	if(x3==292&&y3!=526&&x3!=48&&x3!=776&&x3!=122&&x3!=688&&y3!=46&&y3!=762&&y3!=680&&y3!=124&&y3!=204&&y3!=604)
	{
		y3=y3+1;
		comppath2=4;//path check for ai movement
	}
	if(x3==540&&y3!=288&&x3!=48&&x3!=776&&x3!=122&&x3!=688&&y3!=46&&y3!=762&&y3!=124&&y3!=680&&y3!=204&&y3!=604)
	{
		y3=y3-1;
		comppath2=4;//path check for ai movement
	}








}
	if(level==3)
{
	if(y2==46 && x2!=48)//computer driven car
	{
		x2=x2-2;
		comppath=1;
		cout<<"x2:"<<x2;//path check for ai movement	
	}	
	else if( x2==48 && y2!=762)
		{		
		y2=y2+2;
		comppath=1;
		cout<<"y2:"<<y2;
		}
	else if(y2==762 && x2!=776)
		{
			x2=x2+2;
		comppath=1;
			cout<<"x2:"<<x2;		
		}	
	else if( x2==776 && y2!=46)
		{
				
				y2=y2-2;
				comppath=1;
				/*cout<<"y2"<<y2;*/
		}
	if(y2==124&&x2!=122&&y2!=46&&x2!=48&&x2!=776)
	{	
		x2=x2-2;
		comppath=2;
	}
	if(x2==122&&y2!=680&&x2!=48&&y2!=762&&y2!=46&&y2<=763)
	{
		y2=y2+2;
		comppath=2;
	}
	if(y2==680&&x2!=688&&x2!=48&&y2!=762&&y2!=46&&x2!=776)
	{
		x2=x2+2;
		comppath=2;
	}
	if(x2==688&&y2!=124&&x2!=48&&y2!=762&&y2!=46&&y2!=776)
	{
		y2=y2-2;
		comppath=2;
	}


	if(y2==204&&x2!=204&&x2!=48&&y2!=762&&y2!=46&&y2!=762&&y2!=124&&x2!=122&&x2!=776&&x2!=688)
	{
		x2=x2-2;
		comppath=3;
	}
	if(y2==604&&x2!=620&&x2!=48&&y2!=762&&y2!=46&&y2!=776&&y2!=124&&x2!=122&&x2!=776&&x2!=688)
	{
		x2=x2+2;
		comppath=3;
	}
	if(x2==204&&y2!=604&&x2!=48&&x2!=776&&x2!=122&&x2!=688&&y2!=46&&y2!=762&&y2!=680&&y2!=124&&x2!=620)
	{
		y2=y2+2;
		comppath=3;
	}
	if(x2==620&&y2!=204&&x2!=48&&x2!=776&&x2!=122&&x2!=688&&y2!=46&&y2!=762&&y2!=124&&y2!=680&&x2!=204)
	{
		y2=y2-2;
		comppath=3;
	}
	


	if(y2==288&&x2!=292&&x2!=48&&y2!=762&&y2!=46&&y2!=762&&y2!=124&&x2!=122&&x2!=776&&x2!=688&&x2!=620&&x2!=204)
	{
		x2=x2-2;
		comppath=4;
	}
	if(y2==526&&x2!=540&&x2!=48&&y2!=762&&y2!=46&&y2!=776&&y2!=124&&x2!=122&&x2!=776&&x2!=688&&x2!=620&&x2!=204)
	{
		x2=x2+2;
		comppath=4;
	}
	if(x2==292&&y2!=526&&x2!=48&&x2!=776&&x2!=122&&x2!=688&&y2!=46&&y2!=762&&y2!=680&&y2!=124&&y2!=204&&y2!=604)
	{
		y2=y2+2;
		comppath=4;
	}
	if(x2==540&&y2!=288&&x2!=48&&x2!=776&&x2!=122&&x2!=688&&y2!=46&&y2!=762&&y2!=124&&y2!=680&&y2!=204&&y2!=604)
	{
		y2=y2-2;
		comppath=4;
	}
		
}		
			
	
	


/*	else if((x2>390 && x2<450)&&(y2!=124&&y2!=680&&y2!=762)&&(xmy==124||ymy==122||xmy==688||  			ymy==680||xmy==292||xmy==540||ymy==526||ymy==288)&&(xmy!=46&&ymy!=48&&xmy!=776&&y2!=526))
	{
		y2=y2+1;
	}
	else if((x2>390 && x2<450)&&(xmy==620||xmy==204||ymy==604||ymy==204)&&(y2!=680&&y2!=762&&y2!=204&&y2!=604&&y2!=288&&y2!=526&&y2!=288&&y2!=526&&xmy!=620&&xmy!=204&&y2!=288&&y2!=526))
	{
		y2=y2+1;
	}
else if((x2>390 && x2<450)&&(xmy==292||xmy==540||ymy==526||ymy==288)&&(y2!=680&&y2!=762&&y2!=604&&y2!=526&&y2!=288&&y2!=124))
	{
		y2=y2+1;
	}
else if((x2>390 && x2<450)&&(xmy==124||ymy==122||xmy==688||ymy==680||xmy==292||xmy==540||ymy==526||ymy==288)&&(y2!=46&&y2!=680))
	{
		y2=y2-1;
	}
	
	(y2==762 && x2!=776)
		{
			x2=x2+1;
			cout<<"x2:"<<x2;		
		}*/
	
	







	if(ymy==46 && xmy!=776)// driven car //arena 1 movemnt
	{
		move_left=false;
                move_right=true;
                move_up=false;
                move_down=false;
		carpath=1;
		/*cout<<"x2:"<<x2;*/	
	}	
	else if( xmy==776 && ymy!=762)
		{		
		move_left=false;
                move_right=false;
                move_up=true;
                move_down=false;
		carpath=1;
		/*cout<<"y:"<<y2;*/
		}
	else if(ymy==762 && xmy!=48)
		{
		move_left=true;
                move_right=false;
                move_up=false;
                move_down=false;
		carpath=1;
			/*cout<<"x:"<<x2;*/		
		}	
	else if( xmy==48 && ymy!=46)
		{
				
				move_left=false;
                move_right=false;
                move_up=false;
                move_down=true;
		carpath=1;
				/*cout<<"y2"<<y2;*/
		}
		
	if(ymy==124 && xmy!=688&&xmy!=776&&xmy!=48)//computer driven car //arena 2 movemnet
	{
		move_left=false;
                move_right=true;
                move_up=false;
                move_down=false;
		carpath=2;
		/*cout<<"x2:"<<x2;*/	
	}	
	else if( xmy==688 && ymy!=680&&ymy!=46&&ymy!=762)
		{		
		move_left=false;
                move_right=false;
                move_up=true;
                move_down=false;
		carpath=2;
		/*cout<<"y:"<<y2;*/
		}
	else if(ymy==680 && xmy!=122&&xmy!=776&&xmy!=48)
		{
			move_left=true;
                move_right=false;
                move_up=false;
                move_down=false;
		carpath=2;
			/*cout<<"x:"<<x2;*/		
		}	
	else if( xmy==122 && ymy!=124&&ymy!=762&&ymy!=46)
		{
				
				move_left=false;
                move_right=false;
                move_up=false;
                move_down=true;
		carpath=2;
				/*cout<<"y2"<<y2;*/
		}
		
	if(ymy==204 && xmy!=620 &&xmy!=776&&xmy!=48&&xmy!=620&&xmy!=122&&xmy!=688)//driven car arena 3 movement=
	{
		move_left=false;
                move_right=true;
                move_up=false;
                move_down=false;
		carpath=3;
		/*cout<<"x2:"<<x2;*/	
	}	
	else if( xmy==620 && ymy!=604&&ymy!=46&&ymy!=762&&ymy!=124&&ymy!=680)
		{		
		move_left=false;
                move_right=false;
                move_up=true;
                move_down=false;
		carpath=3;
		/*cout<<"y:"<<y2;*/
		}
	else if(ymy==604 && xmy!=204&&xmy!=776&&xmy!=48&&xmy!=688&&xmy!=122)
		{
			move_left=true;
                move_right=false;
                move_up=false;
                move_down=false;
		carpath=3;
			/*cout<<"x:"<<x2;*/		
		}	
	else if( xmy==204 && ymy!=204&&ymy!=762&&ymy!=46&&ymy!=124&&ymy!=692&&ymy!=680)
		{
				
				move_left=false;
                move_right=false;
                move_up=false;
                move_down=true;
		carpath=3;
				/*cout<<"y2"<<y2;*/
		}
	if(ymy==288 && xmy!=540 &&xmy!=776&&xmy!=48&&xmy!=620&&xmy!=122&&xmy!=688&&xmy!=620&&xmy!=204)// driven car arena 4 movemenr
	{
		move_left=false;
                move_right=true;
                move_up=false;
                move_down=false;
		carpath=4;
		/*cout<<"x2:"<<x2;*/	
	}	
	else if( xmy==540 && ymy!=526&&ymy!=46&&ymy!=762&&ymy!=124&&ymy!=680&&ymy!=604&&ymy!=204&&ymy!=692)
		{		
		move_left=false;
                move_right=false;
                move_up=true;
                move_down=false;
		carpath=4;
		/*cout<<"y:"<<y2;*/
		}
	else if(ymy==526 && xmy!=292&&xmy!=776&&xmy!=48&&xmy!=688&&xmy!=122&&xmy!=620&&xmy!=204)
		{
		move_left=true;
                move_right=false;
                move_up=false;
                move_down=false;
		carpath=4;
			/*cout<<"x:"<<x2;*/		
		}	
	else if( xmy==292 && ymy!=288&&ymy!=762&&ymy!=46&&ymy!=124&&ymy!=680&&ymy!=604&&ymy!=204)
		{
				
		move_left=false;
                move_right=false;
                move_up=false;
                move_down=true;
		carpath=4;
				/*cout<<"y2"<<y2;*/
		}


		//AI of computer car-------------------------------
		if((carpath==2||carpath==3||carpath==4)&&comppath==1) //check if car is in arena path 2 3 or 4
		{
			if(y2==46&&x2>360 && x2<420)
			{y2+=78;}
			if(y2==762&&x2>360 && x2<420)
			{y2-=82;}
		}

		if((carpath==3||carpath==4)&&comppath==2)//check if car is in arena path  3 or 4
		{
			if(y2==124&&x2>360 && x2<420)
			{y2+=80;}
			if(y2==680&&x2>360 && x2<420)
			{y2-=76;}
		}

		if(carpath==4&&comppath==3)//check if car is in arena path 4
		{
			if(y2==204&&x2>360 && x2<420)
			{y2+=84;}
			if(y2==604&&x2>360 && x2<420)
			{y2-=78;}
		}


		if((carpath==1||carpath==2||carpath==3)&&comppath==4)//check if car is in arena path 1 2 3 
		{
			if(y2==288&&x2>360 && x2<420)
			{y2-=84;}
			if(y2==526&&x2>360 && x2<420)
			{y2+=78;}
		}

		if((carpath==1||carpath==2)&&comppath==3)//check if car is in arena path 1 2
		{
			if(y2==204&&x2>360 && x2<420)
			{y2-=80;}
			if(y2==604&&x2>360 && x2<420)
			{y2+=76;}
		}

		if((carpath==1)&&comppath==2)//check if car is in arena path 1
		{
			if(y2==124&&x2>360 && x2<420)
			{y2-=78;}
			if(y2==680&&x2>360 && x2<420)
			{y2+=82;}
		}






		//providing access to x axis as well in level greater than 1
		if(level==2||level==3||level==4)//check if car is in arena path 2 3 or 4
		{
		if((carpath==2||carpath==3||carpath==4)&&comppath==1)
		{
			if(x2==48&&y2>390 && y2<450)
			{x2+=74;}
			if(x2==776&&y2>390 && y2<450)
			{x2-=88;}
		}

		if((carpath==3||carpath==4)&&comppath==2)//check if car is in arena path  3 or 4
		{
			if(x2==122&&y2>390 && y2<450)
			{x2+=82;}
			if(x2==688&&y2>390 && y2<450)
			{x2-=68;}	
		}

		if(carpath==4&&comppath==3)//check if car is in arena path 4
		{
			if(x2==204&&y2>390 && y2<450)
			{x2+=88;}
			if(x2==620&&y2>390 && y2<450)
			{x2-=80;}
		}


		if((carpath==1||carpath==2||carpath==3)&&comppath==4)
		{
			if(x2==540&&y2>390 && y2<450)
			{x2+=80;}
			if(x2==292&&y2>390 && y2<450)
			{x2-=88;}
		}

		if((carpath==1||carpath==2)&&comppath==3)
		{
			if(x2==620&&y2>390 && y2<450)
			{x2+=68;}
			if(x2==204&&y2>390 && y2<450)
			{x2-=82;}
		}

		if((carpath==1)&&comppath==2)
		{
			if(x2==688&&y2>390 && y2<450)
			{x2+=88;}
			if(x2==122&&y2>390 && y2<450)
			{x2-=74;}
		}
			
			


		}

				
		if(xmy>776)
		{
				move_left=true;
				move_right=false;
				move_up=false;
				move_down=false;
		}
		if(ymy>762)
		{
				move_left=false;
				move_right=false;
				move_up=false;
				move_down=true;
		}	
		if(xmy<48)
		{	
				move_left=false;
				move_right=true;
				move_up=false;
				move_down=false;
		}	
		if(ymy<44)
		{
			move_left=false;
				move_right=false;
				move_up=true;
				move_down=true;
		}
		if (level==4) //level 4 condition for 2nd opponent car
		{

			if((carpath==2||carpath==3||carpath==4)&&comppath2==1)
		{
			if(x3==48&&y3>390 && y3<450)
			{x3+=74;}
			if(x3==776&&y3>390 && y3<450)
			{x3-=88;}
		}

		if((carpath==3||carpath==4)&&comppath2==2)
		{
			if(x3==122&&y3>390 && y3<450)
			{x3+=82;}
			if(x3==688&&y3>390 && y3<450)
			{x3-=68;}	
		}

		if(carpath==4&&comppath2==3)
		{
			if(x3==204&&y3>390 && y3<450)
			{x3+=88;}
			if(x3==620&&y3>390 && y3<450)
			{x3-=80;}
		}


		if((carpath==1||carpath==2||carpath==3)&&comppath2==4)
		{
			if(x3==540&&y3>390 && y3<450)
			{x3+=80;}
			if(x3==292&&y3>390 && y3<450)
			{x3-=88;}
		}

		if((carpath==1||carpath==2)&&comppath2==3)
		{
			if(x3==620&&y3>390 && y3<450)
			{x3+=68;}
			if(x3==204&&y3>390 && y3<450)
			{x3-=82;}
		}

		if((carpath==1)&&comppath2==2)
		{
			if(x3==688&&y3>390 && y3<450)
			{x3+=88;}
			if(x3==122&&y3>390 && y3<450)
			{x3-=74;}
		}	
		}






	// once again we tell the library to call our Timer function after next 1000/FPS
	if(menu==0)	
	{	
	glutTimerFunc(1000.0, Timer, 0);
	}	
	else if(menu==1)
	glutTimerFunc(1000/FPS-10, Timer, 10);


}

/*This function is called (automatically) whenever your mouse moves witin inside the game window
 *
 * You will have to add the necessary code here for finding the direction of shooting
 *
 * This function has two arguments: x & y that tells the coordinate of current position of move mouse
 *
 * */
void MousePressedAndMoved(int x, int y) {
	cout << xmy << " " << ymy << endl;
	glutPostRedisplay();
}
void MouseMoved(int x, int y) {

	glutPostRedisplay();
}

/*This function is called (automatically) whenever your mouse button is clicked witin inside the game window
 *
 * You will have to add the necessary code here for shooting, etc.
 *
 * This function has four arguments: button (Left, Middle or Right), state (button is pressed or released),
 * x & y that tells the coordinate of current position of move mouse
 *
 * */
void MouseClicked(int button, int state, int x, int y) {

	if (button == GLUT_LEFT_BUTTON) // dealing only with left button
			{
		cout << GLUT_DOWN << " " << GLUT_UP << endl;

	} else if (button == GLUT_RIGHT_BUTTON) // dealing with right button
			{

	}
	glutPostRedisplay();
}
/*
 * our gateway main function
 * */
int main(int argc, char*argv[]) {

	//b = new Board(60, 60); // create a new board object to use in the Display Function ...

	int width = 840, height = 840; // i have set my window size to be 800 x 600
	//b->InitalizeBoard(width, height);
	InitRandomizer(); // seed the random number generator...
	glutInit(&argc, argv); // initialize the graphics library...
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); // we will be using color display mode
	glutInitWindowPosition(50, 50); // set the initial position of our window
	glutInitWindowSize(width, height); // set the size of our window
	glutCreateWindow("Dodge_em"); // set the title of our game window
	SetCanvasSize(width, height); // set the number of pixels...

	// Register your functions to the library,
	// you are telling the library names of function to call for different tasks.
	//glutDisplayFunc(display); // tell library which function to call for drawing Canvas.

	glutDisplayFunc(GameDisplay); // tell library which function to call for drawing Canvas.
	glutSpecialFunc(NonPrintableKeys); // tell library which function to call for non-printable ASCII characters
	glutKeyboardFunc(PrintableKeys); // tell library which function to call for printable ASCII characters
	// This function tells the library to call our Timer function after 1000.0/FPS milliseconds...
	glutTimerFunc(1000.0, Timer, 0);

	glutMouseFunc(MouseClicked);
	glutPassiveMotionFunc(MouseMoved); // Mouse
	glutMotionFunc(MousePressedAndMoved); // Mouse

	// now handle the control to library and it will call our registered functions when
	// it deems necessary...
	glutMainLoop();
	return 1;
}
#endif /* AsteroidS_CPP_ */
