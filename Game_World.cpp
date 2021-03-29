//Written by Ayush Mishra [Used in College Project]
#include<conio.h>
#include<stdio.h>
#include<dos.h>
#include<stdlib.h>

//TictacToe******************************************************************************************
char square[10] = {'o','1','2','3','4','5','6','7','8','9'};

int checkwin();
void board();

int checkwin()
{
    if (square[1] == square[2] && square[2] == square[3])
	return 1;

    else if (square[4] == square[5] && square[5] == square[6])
	return 1;

    else if (square[7] == square[8] && square[8] == square[9])
	return 1;

    else if (square[1] == square[4] && square[4] == square[7])
	return 1;

    else if (square[2] == square[5] && square[5] == square[8])
	return 1;

    else if (square[3] == square[6] && square[6] == square[9])
	return 1;

    else if (square[1] == square[5] && square[5] == square[9])
	return 1;

    else if (square[3] == square[5] && square[5] == square[7])
	return 1;

    else if (square[1] != '1' && square[2] != '2' && square[3] != '3' &&
	square[4] != '4' && square[5] != '5' && square[6] != '6' && square[7]
	!= '7' && square[8] != '8' && square[9] != '9')

	return 0;
    else
	return  - 1;
}

void board()
{
    clrscr();
    printf("\033[1;33m\n\n\tTic Tac Toe\n\n");

    printf("\033[1;32mPlayer 1 (X)  :   Player 2 (O)\n\n\n");


    printf("\033[1;35m     |     |     \n");
    printf("  %c  |  %c  |  %c \n", square[1], square[2], square[3]);

    printf("_____|_____|_____\n");
    printf("     |     |     \n");

    printf("  %c  |  %c  |  %c \n", square[4], square[5], square[6]);

    printf("_____|_____|_____\n");
    printf("     |     |     \n");

    printf("  %c  |  %c  |  %c \n", square[7], square[8], square[9]);

    printf("     |     |      \n \n\033[1;34m:-ENTER X To EXIT\n\n");
  }

//Snake Game*****************************************************************************************

int i,j,x,y,width=22,height=78,score,v,gameOver,foodX,foodY,k;
int countail=0,tailX[100],tailY[100];

void setup()
{
  gameOver=0;
  x=width/2;
  y=height/2;

     label1:
  foodX=rand()%22;  //stdlib
    if(foodX==0)
    goto label1;

    label2:
  foodY=rand()%78;
    if(foodY==0)
      goto label2;
      score=0;
	for(k=0;k<60;k++)
	{
	  sound(7*k);
	  delay(3);
	  nosound();
	}
}

void input()
{
  if(kbhit())
  {
    switch(getch())
    {
      case 'a':   //a is for left
	  v=1;
	 for(k=0;k<50;k++)
	{
	  sound(350*k);
	  delay(1);
	  nosound();
	}
	    break;
      case 's':                  // s is for right
	  v=2;
	 for(k=0;k<50;k++)
	{
	  sound(350*k);
	  delay(1);
	  nosound();
	}
	    break;
      case 'w':
	  v=3;
	 for(k=0;k<50;k++)                        //w is for up
	{
	  sound(350*k);
	  delay(1);
	  nosound();
	}
	    break;
      case 'z':
	  v=4;
	 for(k=0;k<50;k++)
	{
	  sound(350*k);                                        // z is for down
	  delay(1);
	  nosound();
	}
	    break;
      case 'x':
       for(k=0;k<70;k++)
	{
	  sound(10*k);
	  delay(8);
	  nosound();               // x is exit
	}
	  gameOver=1;
	    break;
      case 'A':
	  v=1;
	 for(k=0;k<50;k++)
	{
	  sound(350*k);
	  delay(1);
	  nosound();
	}
	    break;
      case 'S':
	  v=2;
	 for(k=0;k<50;k++)
	{
	  sound(350*k);
	  delay(1);
	  nosound();
	}
	    break;
      case 'W':
	  v=3;
	 for(k=0;k<50;k++)
	{
	  sound(350*k);
	  delay(1);
	  nosound();
	}
	    break;
      case 'Z':
	  v=4;
	for(k=0;k<50;k++)
	{
	  sound(350*k);
	  delay(1);
	  nosound();
	}
	    break;
      case 'X':
       for(k=0;k<70;k++)
	{
	  sound(10*k);
	  delay(8);
	  nosound();
	}
	  gameOver=1;
    }
  }
}

void draw()
{
  clrscr();
   for(i=0;i<=width;i++)
   {
      for(j=0;j<=height;j++)
      {
	if(i==0||i==width||j==0||j==height)
	{
	  printf("\033[0;31m*");    //red
	}
	else
	{
	  if(i==x&&j==y)
	    printf("\033[1;32mO");  //snake head
	  else if(i==foodX&&j==foodY)           //food
	   printf("\033[1;36mo");
	  else
	  {
	    int ch=0,k;
	    for(k=0;k<countail;k++)
	    {
	      if(i==tailX[k]&&j==tailY[k])
	      {
		printf("\033[1;33mx");   //color code
		 ch=1;
	      }
	    }
	       if(ch==0)
	       {
		 printf(" ");  //blank
	       }
	  }
	}
      }
      printf("\n");
   }
   printf("\033[1;35mSCORE:%d \t        Press any Key To Replay                 Press X to exit",score);
}

void logic()
{
   int m,n;
  int prevX=tailX[0];   //tailX[100]                  //tailX
  int prevY=tailY[0];
    int prev2X,prev2Y;                     //
  tailX[0]=x;               //tailX  tailY
  tailY[0]=y;
     for(i=1;i<countail;i++)
     {
	prev2X=tailX[i];                  //iniatial=setup() food head score
	prev2Y=tailY[i];
	 tailX[i]=prevX;     //ooooO
	 tailY[i]=prevY;
	prevX=prev2X;       //main point       //o
	prevY=prev2Y;
     }

  switch(v)
  {
    case 1:
	y--;
      break;
    case 2:
	y++;
      break;
    case 3:
	x--;
      break;
    case 4:
	x++;
      break;
    default:
      break;
  }
    if(x<0||x>width-1||y<0||y>height-1)
    {
      gameOver=1;
      char kb;
      setup();
      countail=0;
       for(k=0;k<70;k++)
	{
	  sound(10*k);
	  delay(10);
	  nosound();
	}

      if(kbhit)
      {
      switch(getch())
       {
	 case 'x':
	    gameOver=1;
       for(k=0;k<70;k++)
	{
	  sound(10*k);
	  delay(8);
	  nosound();
	}
	      break;
	 case 'X':
	    gameOver=1;
	 for(k=0;k<70;k++)
	{
	  sound(10*k);
	  delay(8);
	  nosound();
	}
	 default:
	    break;
       }
     }
  }

    for(i=0;i<countail;i++)
    {
      if(x==tailX[i]&&y==tailY[i])
      {
       gameOver=1;
	for(k=0;k<70;k++)
	{
	  sound(10*k);
	  delay(10);
	  nosound();
	}
	setup();
       char kb;
       countail=0;

       if(kbhit)
      {
      switch(getch())
       {
	 case 'x':
	    gameOver=1;
	for(k=0;k<70;k++)
	{
	  sound(10*k);
	  delay(8);
	  nosound();
	}
	      break;
	case 'X':
	    gameOver=1;
	for(k=0;k<70;k++)
	{
	  sound(10*k);
	  delay(8);
	  nosound();
	}
	 default:
	    break;
       }
     }
    }
  }
    if(x==foodX&&y==foodY)
    {
    label3:
  foodX=rand()%22;
    if(foodX==0)
    goto label3;

    label4:
  foodY=rand()%78;
    if(foodY==0)
      goto label4;
	for(k=0;k<10;k++)
	{
	  sound(160*k);
	  delay(3);
	  nosound();
	}

      score+=10;
	countail++;
    }
}
//************************************MAIN()**************************************
int main(int argc, const char *argv[])
{
char  bb;
   clrscr();
   printf("\033[1;31m\n\n\t\t\t \033[1;35m   @@@@@@@@@@@@@@@@@@@@@\033[1;31m\n\t\t\t  \033[1;35m  @\033[1;31m###################\033[1;35m@\033[1;31m\n\t\t\t   \033[1;35m @\033[1;31m#\033[1;32m THE GAME CENTER\033[1;31m #\033[1;35m@\n\t\t\t   \033[1;35m @\033[1;31m###################\033[1;35m@"
"\n\t\t\t    @@@@@@@@@@@@@@@@@@@@@\033[1;31m\n     ||||||||||||||\t\t\t    \t       |||||||||||||||||||||||\n     |\033[1;34m SNAKE GAME\033[1;31m |\t\t\t\t       |\033[1;36m ROCK PAPER SCISSORS\033[1;31m |\n     ||||||||||||||          \t\t\t       |||||||||||||||||||||||\n    \033[1;33m  Enter 'S'(s) \t\t\t\t\t  \033[1;33m   Enter 'R'(r)\033[1;31m\n\n\n\t\t\t       |||||||||||||||\n\t\t\t       |\033[1;35m TIC TAC TOE\033[1;31m |\n\t\t\t       |||||||||||||||\n\t\t\t\t \033[1;33mEnter 'T'(t)\n\n\t\t\t\t\t\t    [\033[1;31mEnter OTHER Key TO EXIT\033[1;33m]\n\t\t\033[1;32m[{ YOU }]:-");
    fflush(stdin);    //input buffer empty
   scanf("%c",&bb);
//***************************SnakeGame********************************************
 if(bb=='S'||bb=='s')
     {
       char dd;
       clrscr();
  printf("\033[1;36m*******************************************************************************\n*\t\t\t\t\t\t\t\t\t      *\n*                       -::-  \033[1;32m [SNAKE GAME] \033[1;36m  -::-\t\t\t      *\n*\t          \t--------------------------\t\t\t      *\n*\t          \t**************************\t\t\t      *\n*\t\t\t    \033[1;33m     TUTORIAL\033[1;36m\t                              *\n*\t\t\t\t\t\t\t\t              *\n*       :-                Press 'a' or 'A'to go Left\t\t\t      *\n*\t\t\t\t\t\t\t\t              *\n*\t:-                Press 's' or 'S'to go Right\t\t              *\n*\t\t\t\t\t\t\t\t              *\n*\t:-                Press 'w' or 'W' to go Up\t\t\t      *\n*\t\t\t\t\t\t\t\t\t      *\n*\t:-                Press 'z' or 'Z' to go Down\t\t\t      *\n*\t\t\t\t\t\t\t\t\t      *\n*\t\t\t\t\t\t\t\t              *\n*\t\t\t\t\t\t\t\t\t      *\n*\t      ************\033[1;31mEnter Other key to exit\033[1;36m************\t\t      *\n*"
  "\t\t\t\t\t\t\t\t\t      *\n*    \t\t\t\t\t\t\t\t              *\n*                 =::**\033[1;34m[\033[1;33mEnter Y To START \033[0;32m'GAME'\033[1;34m]\033[1;36m**::= \t\t\t      *\n*\t\t\t\t\t\t\t\t\t      *\n******************************************************************************* \033[1;35mYou:-");
   fflush(stdin);   //empty
  scanf("%c",&dd);
   if(dd=='y'||dd=='Y')   //to play the snake game (to enter in)
   {
     clrscr();
    int m,n;
     setup();
      while(!gameOver)
      {
	 draw();
	 input();
	 logic();

	   for(m=0;m<2000;m++)
	   {
	     for(n=0;n<8500;n++){}
	   }
      }
   }
     }
//********************************TicTacToe***************************************
 else if(bb=='T'||bb=='t')
 {
    char jj;
       clrscr();
       printf("\n\n\n\t\t\t\t\033[1;35m_TIC_TAC_TOE_\n\t\t\t\t\n\t\t\t\t\033[1;36m{{TUTORIAL}}\n\t\t\t\t------------\n\n\n\t\033[1;34m :-\tChose 'X' Or '0'.\n\n\t :-\tEnter 1 to 9 to give location of your symbol\n\n\n\n\t\t\t:-\033[1;33mEnter 'Y' to START\n\n\n\t\t    \033[1;32m :-\033[1;34mEnter Other Key To EXIT     \033[1;32mYou:-");
       fflush(stdin);
  scanf("%c",&jj);
   if(jj=='y'||jj=='Y')   //to enter the game
   {
       label1:
	for(k=0;k<60;k++)
	{
	  sound(7*k);
	  delay(3);
	  nosound();
	}
    int player=1,b;
    char choice;

    char mark;
    label:
    do
    {
    board();
   scanf("%c",&choice);

    if(choice=='x'||choice=='X')
    {
	for(k=0;k<70;k++)
	{
	  sound(10*k);
	  delay(8);
	  nosound();
	}
      printf("\033[0;31m:-YOU EXIT THE GAME-:");
      getch();
      exit(0);
    }
	player=(player%2)?1:2;

	printf("\033[1;34mPlayer %d, enter a number: ", player);

	  scanf("%d",&choice);
	mark=(player==1)?'X':'O';

	if(choice==1 && square[1]=='1')
	{
	    square[1]=mark;
	  for(k=0;k<50;k++)
	  {
	    sound(350*k);
	    delay(1);
	    nosound();
	  }
	}

	else if (choice==2 && square[2]=='2')
	{
	    square[2]=mark;
	  for(k=0;k<50;k++)
	  {
	    sound(350*k);
	    delay(1);
	    nosound();
	  }
	}

	else if (choice==3 && square[3]=='3')
	{
	    square[3]=mark;
	  for(k=0;k<50;k++)
	  {
	    sound(350*k);
	    delay(1);
	    nosound();
	  }
	}

	else if (choice==4 && square[4]=='4')
	{
	    square[4]=mark;
	   for(k=0;k<50;k++)
	  {
	    sound(350*k);
	    delay(1);
	    nosound();
	  }
	}

	else if (choice==5 && square[5]=='5')
	{
	    square[5]=mark;
	   for(k=0;k<50;k++)
	  {
	    sound(350*k);
	    delay(1);
	    nosound();
	  }
	}

	else if (choice==6 && square[6]=='6')
	{
	    square[6]=mark;
	  for(k=0;k<50;k++)
	  {
	    sound(350*k);
	    delay(1);
	    nosound();
	  }
	}

	else if (choice==7 && square[7]=='7')
	{
	    square[7]=mark;
	   for(k=0;k<50;k++)
	  {
	    sound(350*k);
	    delay(1);
	    nosound();
	  }
	}

	else if (choice==8 && square[8]=='8')
	{
	    square[8]=mark;
	   for(k=0;k<50;k++)
	  {
	    sound(350*k);
	    delay(1);
	    nosound();
	  }
	}

	else if(choice==9 && square[9]=='9')
	{
	    square[9]=mark;
	   for(k=0;k<50;k++)
	  {
	    sound(350*k);
	    delay(1);
	    nosound();
	  }
	}

	else
	{
	  printf("\033[1;31mInvalid move");
	  for(k=0;k<40;k++)
	  {
	    sound(10*k);
	    delay(3);
	    nosound();
	  }
	    getch();
	      goto label;
	}
	b=checkwin();

	player++;
    }while (b==-1);

    board();

    if (b==1)
    {
	printf("\033[1;31m==>\aPlayer %d win!!!       ::Enter Y To Play Again And Other Key To Exit:-", --player);
    }

    else
    {
	printf("\033[1;31m==>\aGame draw!!        :: Enter Y To Play Again And Other Key To Exit:-");
    }

    getch();
     char gg;
     fflush(stdin);
       getch();
      scanf("%c",&gg);
      clrscr();
    if(gg=='y'||gg=='Y')
    {
      choice=0;
      square[1]='1';
      square[2]='2';
      square[3]='3';
      square[4]='4';
      square[5]='5';
      square[6]='6';
      square[7]='7';
      square[8]='8';
      square[9]='9';

      goto label1;
    }
   }
 }

//*******************************RockPaperScissors***************************
 else if(bb=='r'||bb=='R')
{
   char jj;
       clrscr();
  printf("\n\n\n\t\t\t   \033[1;34m(:_ROCK_PAPER_SCISSORS_:)\n\n\n\t\t\t\t\033[1;35m{{TUTORIAL}}\n\t\t\t\t------------\n\n\n\t\033[1;36m :-\tYOU ARE PLAYING THIS WITH COMPUTER:) [!ATB!]\n\n\t :-\tENTER: ('1' For Rock), ('2' For Paper) And ('3' For Scissors)\n \n\n\n\t\t\t:-\033[1;33mEnter 'Y' to START\n\n\n\t\t    \033[1;36m :-\033[1;31mEnter Other Key To EXIT  \033[0;33m   You:- ");
 fflush(stdin);
  scanf("%c",&jj);
   if(jj=='y'||jj=='Y')
   {
   clrscr();
   int computer, you;
	for(k=0;k<60;k++)
	{
	  sound(7*k);
	  delay(3);
	  nosound();
	}
  char choice;
  while(choice!='n')
  {
   clrscr();
	printf("\n\n\n\t\t\033[1;35m\t     |||||||||||||||||||||\n\t\t\t     |\033[1;32mRock Paper Scissors\033[1;35m|\n\t\t\033[1;35m\t     |||||||||||||||||||||\n\n\n");

	printf("\n\n\033[1;32m:-\033[1;36mEnter \033[1;33m1\033[1;36m To Select \033[1;33mRock");

	printf("  \033[1;32m:-\033[1;36mEnter \033[0;36m2\033[1;36m To Select \033[0;36mPaper");

	printf("  \033[1;32m:-\033[1;36mEnter \033[0;35m3\033[1;36m To Select \033[0;35mScissor");

	printf("\n\t\t\t  \033[1;32m:-\033[1;36mEnter \033[0;31m4\033[1;36m To \033[0;31mExit\033[1;36m The Game");

	printf("\n\n\033[1;34m::::Enter your choice \033[1;32m:");
	fflush(stdin);
	char ch;

	 if(scanf("%d",&ch)!=1)
	  {
	    printf("\033[1;31mInvalid choice");
	    scanf("%*s");
	    goto jump;
	  }
	computer=rand()%4;

	you=ch;

	while(computer==0)
	{
	   computer=rand()%4;
	}

	switch(you)
	{
	  case 1:
		if (computer==1)
		{
			       for(k=0;k<110;k++)
				   {
				     sound(60*k);
				     delay(3);
				     nosound();
				   }
			printf("\n\033[0;31mGame draw\n");
			printf("\033[1;34m.....\t    ..........\n.\033[1;33myou\033[1;34m.\033[1;32m=\033[1;36mRock  \033[1;34m.\033[0;32mComputer\033[1;34m.\033[1;32m=\033[1;35mrock\n\033[1;34m.....\t    ..........\n");
		}
		else if (computer==2)
		{
			    for(k=0;k<110;k++)
				   {
				     sound(60*k);
				     delay(3);
				     nosound();
				   }
			printf("\n\033[0;33mComputer won\n");
			printf("\033[1;34m.....\t    ..........\n.\033[1;33myou\033[1;34m.\033[1;32m=\033[1;36mrock  \033[1;34m.\033[0;32mcomputer\033[1;34m.\033[1;32m=\033[1;35mpaper\n\033[1;34m.....\t    ..........\n");
		}
		else
		{
				for(k=0;k<110;k++)
				   {
				     sound(60*k);
				     delay(3);
				     nosound();
				   }
			printf("\n\033[1;32mYou won\n");
			printf("\033[1;34m.....\t    ..........\n.\033[1;33myou\033[1;34m.\033[1;32m=\033[1;36mrock  \033[1;34m.\033[0;32mComputer\033[1;34m.\033[1;32m=\033[1;35mscissor\n\033[1;34m.....\t    ..........\n");
		}
	      break;
	    case 2:
		    if (computer==1)
		    {
		    for(k=0;k<110;k++)
				   {

				     sound(60*k);
				     delay(3);
				     nosound();
				   }
			printf("\n\033[1;32mYou won\n");
			printf("\033[1;34m.....\t     ..........\n.\033[1;33myou\033[1;34m.\033[1;32m=\033[1;36mpaper  \033[1;34m.\033[0;32mComputer\033[1;34m.\033[1;32m=\033[1;35mrock\n\033[1;34m.....\t     ..........\n");
		    }
		    else if (computer==2)
		    {
			       for(k=0;k<110;k++)
				   {
				     sound(60*k);
				     delay(3);
				     nosound();
				   }
			printf("\n\033[0;31mGame draw\n");
			printf("\033[1;34m.....\t     ..........\n.\033[1;33myou\033[1;34m.\033[1;32m=\033[1;36mpaper  \033[1;34m.\033[0;32mComputer\033[1;34m.\033[1;32m=\033[1;35m=paper\n\033[1;34m.....\t     ..........\n");
		    }
		    else
		    {
				 for(k=0;k<110;k++)
				   {
				     sound(60*k);
				     delay(3);
				     nosound();
				   }
			printf("\n\033[0;33mComputer won\n");
			printf("\033[1;34m.....\t     ..........\n.\033[1;33myou\033[1;34m.\033[1;32m=\033[1;36mpaper  \033[1;34m.\033[0;32mComputer\033[1;34m.\033[1;32m=\033[1;35mscissor\n\033[1;34m.....\t     ..........\n");
		    }
		    break;
	    case 3:
		   if (computer==1)
		  {
				for(k=0;k<110;k++)
				   {
				     sound(60*k);
				     delay(3);
				     nosound();
				   }
			printf("\n\033[0;33mComputer won\n");
			printf("\033[1;34m.....\t       ..........\n.\033[1;33myou\033[1;34m.\033[1;32m=\033[1;36mscissor  \033[1;34m.\033[0;32mComputer\033[1;34m.\033[1;32m=\033[1;35mrock\n\033[1;34m.....\t       ..........\n");
		  }
		   else if (computer==2)
		  {
				 for(k=0;k<110;k++)
				   {
				     sound(60*k);
				     delay(3);
				     nosound();
				   }
			printf("\n\033[1;32mYou won\n");
			printf("\033[1;34m.....\t       ..........\n.\033[1;33myou\033[1;34m.\033[1;32m=\033[1;36mscissor  \033[1;34m.\033[0;32mComputer\033[1;34m.\033[1;32m=\033[1;35mpaper\n\033[1;34m.....\t       ..........\n");
		  }
		   else
		  {
				 for(k=0;k<110;k++)
				   {
				     sound(60*k);
				     delay(3);
				     nosound();
				   }
			printf("\n\033[0;31mGame draw\n");
			printf("\033[1;34m.....\t       ..........\n.\033[1;33myou\033[1;34m.\033[1;32m=\033[1;36mscissor  \033[1;34m.\033[0;32mComputer\033[1;34m.\033[1;32m=\033[1;35mscissor\n\033[1;34m.....\t       ..........\n");
		  }
		  break;
	    case 4:
			     for(k=0;k<70;k++)
				    {
				      sound(10*k);
				      delay(8);
				      nosound();
				    }
		     printf("\n\n\033[0;31m!!YOU EXIT THE GAME!!\n\n\n\033[0;34mThank you for playing\n");
		     getch();
		     exit(0);
	    default:
		    for(k=0;k<40;k++)
		     {
		       sound(10*k);
		       delay(3);
		       nosound();
		     }
		    printf("\n\033[1;31mInvalid choice");
	  }
	  jump:
	  printf("\n\033[1;32m :-\033[1;33mTo Continue Enter a key       \033[1;32m:-\033[1;31mTo Exit Enter N \033[0;33m      You \033[1;32m: ");
	  fflush(stdin);
	  scanf("%c",&choice);

   }
	for(k=0;k<60;k++)
	{
	  sound(7*k);
	  delay(3);
	  nosound();
	}
  printf("\n\033[0;34mThank you for playing\n");
  getch();
   }
 }
  return 0;
}
//**********************************THE END*****************************************************
//**********************************************************************************************
