//..........SNAKE GAME..........//
//.......... created by Indranil Das...........//


using namespace std;
#include<stdlib.h>
#include<conio.h>
#include<stdio.h>
#include<iostream>
int L=20,W=20,gameover;
int hx,hy,fx,fy,score,flag;
int tailx[100],taily[100];
int counttail;
int setups()
{
	gameover=0;
	hx=W/2;
	hy=L/2;
	
	lable1:
	fx=rand()%20;
	if(fx==0)
	goto lable1;
	
	lable2:
	fy=rand()%20;
	if(fy==0)
	goto lable2;
	
	score=0;
	
}//end setup
int draw()
{
	int i,j,k;
	system("cls");
	for(i=0;i<L;i++)
	{
		for(j=0;j<W;j++)
		{
			if(i==0||i==L-1||j==0||j==W-1)
			{
			cout<<"*";	//border
			}
			else //blank space area
			{
				if(i==hx && j==hy)
				cout<<"o";
				else if(i==fx && j==fy)
				cout<<"F";
				else
				{
					int ch=0;
					for(k=0;k<counttail;k++)//i,j pair
					{
						if(i==tailx[k] && j==taily[k])
						{
							cout<<"o";
							ch=1;
						}
						
					}
					if(ch==0)
					cout<<" ";	
				}
				
					
			}
			
		}
		cout<<endl;
	}
	cout<<"SCORE-"<<score<<endl;
}//end draw

void input()
{
	if (kbhit()) //aswz
	{
		switch(getch())
		{
			case 'a':
				flag=1;
				break; 
			case 's':
				flag=2;
				break;
			case 'w':
				flag=3;
				break;
			case 'z':
				flag=4;
				break;
			case 'x':
				gameover=1;
				break;		
		}
	}
}

void logic()
{
	int i,j;
	int prex=tailx[0];
	int prey=taily[0];
	int tempx,tempy;
	tailx[0]=hx;
	taily[0]=hy;
	
	for(i=1;i<counttail;i++)//insertion an element an array
	{
		tempx=tailx[i];
		tempy=taily[i];
		tailx[i]=prex;
		taily[i]=prey;
		prex=tempx;
		prey=tempy;
	}
	
	
	switch(flag) 
	{
		case 1:
			hy--;
			break;
		case 2:
			hy++;
			break;
		case 3:
			hx--;
			break;
		case 4:
			hx++;
			break;
		defult:
		break;			
	}
	if(hx<0||hx>W||hy<0||hy>L)
	gameover=1;
	for(j=1;j<counttail;j++)
	{
		if(hx==tailx[j] && hy==taily[j])
		gameover=1;
	}
	if(hx==fx && hy==fy)
	{
	lable3:
	fx=rand()%20;
	if(fx==0)
	goto lable3;
	
	lable4:
	fy=rand()%20;
	if(fy==0)
	goto lable4;
	score++;
	counttail++;	
	}
}

void delay(int x)
{
	int m,n;
for(m=0;m<x+100;m++)
	{
		for(n=0;n<x;n++)
		{ 
		}	
	}	
}


main()
{	
	int m,n,c;
	do
	{
	counttail=0;
	score=0;	
	setups();
	while(!gameover)
	{
	draw();	
	input();
	logic();
	delay(900);	
    }
    cout<<"ENTER 1 TO PLAY AGAIN AND 0 TO EXIT-";
    cin>>c;
    }while(c);
}
