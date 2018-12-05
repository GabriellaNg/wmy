#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SNAKE_MAX_LENGTH 20
#define SNAKE_HEAD 'H'
#define SNAKE_BODY 'X'
#define BLANK_CELL ' '
#define SNAKE_FOOD '$'
#define WALL_CELL '*'

void snakeMove(int x,int y,int game);
void put_money(void);
void output(void);
void gameover(void);

char map[12][13] = {
"************",   
"*          *", 
"*          *",
"*          *",
"*          *",
"*          *",
"*          *",
"*          *",
"*          *",
"*          *",
"*          *",
"************",};

int snakeX[SNAKE_MAX_LENGTH]={1,2,3,4,5};
int snakeY[SNAKE_MAX_LENGTH]={1,1,1,1,1};
int snakeLength = 5; 
int main()
{
    int game=1;
    char ch;
    output();
    put_money();
    while(game==1)
    {
        scanf("%c",&ch);
		switch(ch) {
			case 'A':
				snakeMove(-1,0,1);
				break;
			case 'D':
				snakeMove(1,0,1);
				break;
			case 'W':
				snakeMove(0,-1,1);
				break;
			case 'S':
				snakeMove(0,1,1);
				break;
		}
		output();
        }
        renturn 0;
    } 
void snakeMove(x,y,game)
{
    if(map[snakeX[0]+x][snakeY[0]+y]==BLANK_CELL)
    {
    for(int i=1;i<snakeLength;i++)
    {
        snakeX[i]=snakeX[i-1];
        snakeY[i]=snakeY[i-1];
        }
    snakeX[0]=snakeX[0]+x;
    snakeY[0]=snakeY[0]+y;
}
    if (map[snakeX[0]+x][snakeY[0]+y]==SNAKE_FOOD)
    {
        snakeLength++;
        for(int i=1;i<=snakeLength;i++)
    {
        snakeX[i]=snakeX[i-1];
        snakeY[i]=snakeY[i-1];
        }
    snakeX[0]=snakeX[0]+x;
    snakeY[0]=snakeY[0]+y;
    if(snakeLength>=20)
    {
        game=1;
        gameover();
        }
    put_money();
        }
    if(map[snakeX[0]+x][snakeY[0]+y]==WALL_CELL)
    {
        game=0;
        gameover();
        }
    }
void output()
{
    map[snake[0]][snakeY[0]]=SNAKE_HEAD;
    for(int i=1;i<snakeLength;i++)
    {
        map[snakeX[i]][snakeY[i]]=SNAKE_BODY;
        }
    for(int i=0;i<12;i++)
    {
        for(int j=0;j<13;j++)
        {printf("%s",map[i][j]);}
        }
    }
void put_money()
{
    int moneyX,moneyY;
    moneyX = rand() % 10 +1;
	moneyY = rand() % 10 +1;
    while(map[moneyX][moneyY]!=BLANK_CELL)
    {
    moneyX = rand() % 10 +1;
	moneyY = rand() % 10 +1;
        }
    map[moneyX][moneyY]=SNAKE_FOOD;
    }
void gameover()
{
    if(game==1) printf("Congratulation!")；
    if(game==0) printf("Gameover");
    }
