#include<time.h>
#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
int xt=200,yt=20,xe=300,ye=300,p1=2,p2=20,p3=3,m=3;
int maze[150][150];
int xu,yu,e1,e2;
int check(int m,int d);
void draw_maze(int xt,int yt,int xe,int ye,int m);
void main()
{
	clrscr();
	srand(time(NULL));
	int win=WHITE,s,x1,y1,r,gd=DETECT,gm,i,j,k,l,g[9],sum,x,y,d,n=0;
  //	int xt=100,yt=100,xe=400,ye=300,p1=2,p2=50,p3=4,m=3;
	initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
	//r=rand()%4;
	xu=xt+m;yu=yt+3*m;
	for(i=xt+0;i<xt+xe;i++)
		for(j=yt+0;j<yt+ye;j++)
			putpixel(i,j,WHITE);
	i=xt+m;j=yt+3*m;
/*	for(k=-m;k<=m;k++)
		for(l=-m;l<=m;l++)
			putpixel(i+k,j+l,BLACK);
  */	x=xt+3*m;y=yt+3*m;
	x1=x;y1=y;
	setcolor(BLACK);
	while(x<xt+xe-m)
	{
		r=rand()%4;
		s=rand()%(p2);
		s=s-(s%(2*m));
		s=s+2*m;
		switch(r)
		{
			case 0: if(y-s>(2*m+yt))
				{
				x1=x;y1=y-s;
				for(i=-m;i<=m;i++)
					line(x+i,y+m,x1+i,y1-m);
				x=x1;y=y1;
				}
				break;
			case 1: //if(x+s<400-2*m)
				//{
				x1=x+s;y1=y;
				for(i=-m;i<=m;i++)
					line(x-m,y+i,x1+m,y1+i);
				x=x1;y=y1;
				//}
				break;
			case 2: if(y+s<(yt+ye-2*m))
				{
				x1=x;y1=y+s;

				for(i=-m;i<=m;i++)
					line(x+i,y-m,x1+i,y1+m);
				x=x1;y=y1;
				}
				break;
			case 3: if(x-s>(2*m+xt))
				{
				x1=x-s;y1=y;

				for(i=-m;i<=m;i++)
					line(x+m,y+i,x1-m,y1+i);
				x=x1;y=y1;
				}
				break;

		}

	}
		i=x=x+2*m;j=y;
		for(k=-m;k<=m;k++)
			for(l=-m;l<=m;l++)
				putpixel(i+k,j+l,BLACK);
		while(x>(xt+xe-2*m))
			x=x-2*m;
		e1=x=x+2*m;e2=y;
		for(k=-m;k<=m;k++)
			for(l=-m;l<=m;l++)
				putpixel(e1+k,e2+l,RED);
	for(i=3*m+xt;i<xe-3*m+xt;i=i+2*m)
		for(j=3*m+yt;j<ye-3*m+yt;j=j+2*m)
		{
			for(k=0;k<9;k++)
				g[k]=0;
			n=0;
			sum=0;
			for(k=-(2*m);k<=2*m;k=k+2*m)
				for(l=-(2*m);l<=2*m;l=l+2*m)
				{
					if(getpixel(i+k,j+l)==BLACK)
					{
						g[n]=1;
						sum++;
					}
					n++;
				}
			r=rand()%(p1);
			for(k=-m;k<=m;k++)
				for(l=-m;l<=m;l++)
				{
					if(sum==9||sum==8)
						putpixel(i+k,j+l,WHITE);
					else if(g[0]==0&&g[1]==0&&g[2]==0&&sum==6)
						putpixel(i+k,j+l,WHITE);
					else if(g[2]==0&&g[5]==0&&g[8]==0&&sum==6)
						putpixel(i+k,j+l,WHITE);
					else if(g[6]==0&&g[7]==0&&g[8]==0&&sum==6)
						putpixel(i+k,j+l,WHITE);
					else if(g[0]==0&&g[3]==0&&g[6]==0&&sum==6)
						putpixel(i+k,j+l,WHITE);
					else if(r==0&&sum<p3)
						putpixel(i+k,j+l,BLACK);
				}
		}
	k=0;
	for(i=m+xt;i<xe+xt;i=i+2*m)
	{	k++;l=0;
		for(j=m+yt;j<ye+yt;j=j+2*m)
		{	maze[k][l]=getpixel(i,j);
			l++;
		}
	}
	getch();
	xu=xu+2*m;
	while(win!=RED&&d!=-1)
	{       d=0;
		closegraph();
		clrscr();
		initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
		draw_maze(xt,yt,xe,ye,m);
		setcolor(GREEN);
		for(i=0;i<m;i++)
			circle(xu,yu,i);
		for(k=-m;k<=m;k++)
			for(l=-m;l<=m;l++)
				putpixel(e1+k,e2+l,RED);
		while(d!=2&&d!=4&&d!=6&&d!=8&&d!=-1)
		{
			printf("\n## ENTER DIRECTION ##\n       8"
			"\n      /\\\n  4  <  >  6\n      \\/\n       2\n");
			scanf("%d",&d);
			if(d!=2&&d!=4&&d!=6&&d!=8)
				printf("\nINVALID OP\n");
		}
		win=check(m,d);
	}
	closegraph();
	if(d!=-1)
		printf("\n\n\n\n\n\t\t\t*********CONGRATULATION************");
	getch();
}
int check(int m,int d)
{
	int win,l=WHITE,r=WHITE,i;
	setcolor(BLACK);
	switch(d)
	{
		case 2: win=getpixel(xu,yu+2*m);
			if(win==RED)
				break;
			else if(win==WHITE)
				printf("INVALID OP.");
			else if(win==BLACK)
				while(win==BLACK&&l==WHITE&&r==WHITE)
				{       for(i=0;i<m;i++)
						circle(xu,yu,i);
					yu=yu+2*m;
					setcolor(GREEN);
					for(i=0;i<m;i++)
						circle(xu,yu,i);
					delay(200);
					setcolor(BLACK);
					win=getpixel(xu,yu+2*m);
					l=getpixel(xu+2*m,yu);
					r=getpixel(xu-2*m,yu);
				}
			break;
		case 4: win=getpixel(xu-2*m,yu);
			if(win==RED)
				break;
			else if(win==WHITE)
				printf("INVALID OP.");
			else if(win==BLACK)
				while(win==BLACK&&l==WHITE&&r==WHITE)
				{       for(i=0;i<m;i++)
						circle(xu,yu,i);
					xu=xu-2*m;
					setcolor(GREEN);
					for(i=0;i<m;i++)
						circle(xu,yu,i);
					delay(200);
					setcolor(BLACK);
					win=getpixel(xu-2*m,yu);
					l=getpixel(xu,yu+2*m);
					r=getpixel(xu,yu-2*m);
				}
			break;
		case 6: win=getpixel(xu+2*m,yu);
			if(win==RED)
				break;
			else if(win==WHITE)
				printf("INVALID OP.");
			else if(win==BLACK)
				while(win==BLACK&&l==WHITE&&r==WHITE)
				{       for(i=0;i<m;i++)
						circle(xu,yu,i);
					xu=xu+2*m;
					setcolor(GREEN);
					for(i=0;i<m;i++)
						circle(xu,yu,i);
					delay(200);
					setcolor(BLACK);
					win=getpixel(xu+2*m,yu);
					l=getpixel(xu,yu-2*m);
					r=getpixel(xu,yu+2*m);
				}
			break;
		case 8: win=getpixel(xu,yu-2*m);
			if(win==RED)
				break;
			else if(win==WHITE)
				printf("INVALID OP.");
			else if(win==BLACK)
				while(win==BLACK&&l==WHITE&&r==WHITE)
				{       for(i=0;i<m;i++)
						circle(xu,yu,i);
					yu=yu-2*m;
					setcolor(GREEN);
					for(i=0;i<m;i++)
						circle(xu,yu,i);
					delay(200);
					setcolor(BLACK);
					win=getpixel(xu,yu-2*m);
					l=getpixel(xu-2*m,yu);
					r=getpixel(xu+2*m,yu);
				}
			break;
	}
	return win;
}
void draw_maze(int xt,int yt,int xe,int ye,int m)
{
	int i,j,k,l,a,b;
	k=0;
	for(i=m+xt;i<xe+xt;i=i+2*m)
	{	k++;l=0;
		for(j=m+yt;j<ye+yt;j=j+2*m)
		{
		       for(a=-m;a<=m;a++)
				for(b=-m;b<=m;b++)
					putpixel(i+a,j+b,maze[k][l]);
			l++;
		}
	}
}