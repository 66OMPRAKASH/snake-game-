
void snake();
void food();
void set();
void border();
void gameover();

int xar[100][4]={{100,100,110,110},{90,100,100,110},{80,100,90,110}};
int r1,r2;
int n=3,s=110,st=5;
char ch,scr[500];

void main()  //main function
{
  int gd=DETECT,gm;
  int i;
  clrscr();

  initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");

  r1=random(500);
  r2=random(400);

  do
  {
    snake();
    ch=getch();
  }while(ch!='e');

  closegraph();
}

void snake()
{
  int i;

  if( st==(n-3))
  {
    s=s-10;
    st=st+5;
  }
  while(!kbhit())
  {
    border();

    settextstyle(DEFAULT_FONT,0,3);
    sprintf(scr,"%d",(n-3)*10);
    outtextxy(520,80,scr);

    for(i=0;i<n;i++)
    {
	rectangle(xar[i][0],xar[i][1],xar[i][2],xar[i][3]);
	food();
    }

    if(xar[0][0]==-10 || xar[0][1]==-10 || xar[0][0]==500 || xar[0][1]==400)
    {
	gameover();
    }

    if(r1==xar[0][0] && r2==xar[0][1])
    {
	n++;
	r1=random(500);
	r2=random(400);
	food();
    }
    set();
    if(ch==72)
    {
	xar[0][1]=xar[0][1]-10;
	xar[0][3]=xar[0][3]-10;
    }

    if(ch==80)
    {
	xar[0][1]=xar[0][1]+10;
	xar[0][3]=xar[0][3]+10;
    }

    if(ch==75)
    {
	xar[0][0]=xar[0][0]-10;
	xar[0][2]=xar[0][2]-10;
    }

    if(ch==77)
    {
	xar[0][0]=xar[0][0]+10;
	xar[0][2]=xar[0][2]+10;
    }
    delay(s);
    cleardevice();
  }
}

void food()    //function to generate food for snake
{
  r1=r1-r1%10;
  r2=r2-r2%10;

  setcolor(4);
  rectangle(r1,r2,r1+10,r2+10);
  floodfill(r1+2,r2+2,4);
}

void set()    //moves a block to int next block position
{
  int i,j;

  for(i=n-1;i>0;i--)
  {
    for(j=0;j<4;j++)
    {
	xar[i][j]=xar[i-1][j];
    }
  }
}

void border()
{
  setcolor(7);
  rectangle(0,0,630,475);
  line(500,0,500,475);
  line(0,400,500,400);
  settextstyle(DEFAULT_FONT,0,2);
  setcolor(2);
  outtextxy(520,30,"score");
  setcolor(4);
  outtextxy(40,430,"! WELCOME TO SNAKE FOREST !");
  setcolor(9);
  outtextxy(510,400,"Press e");
  outtextxy(510,430,"to exit");
  settextstyle(DEFAULT_FONT,0,1);
  setcolor(5);
  outtextxy(520,280,"Press any");
  outtextxy(520,300,"KEY");
  outtextxy(520,320,"To Pause");
}

void gameover()
{
  char choice;

  setcolor(4);
  settextstyle(DEFAULT_FONT,0,2);
  outtextxy(520,160,"GAME");
  outtextxy(520,180,"is");
  outtextxy(520,200,"OVER");
  getch();
  getch();
  exit(0);
}