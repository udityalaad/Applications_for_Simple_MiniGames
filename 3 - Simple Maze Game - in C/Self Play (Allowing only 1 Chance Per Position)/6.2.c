#include<stdio.h>
#define CAPACITY 10

struct stack
{
int row;
int col;
};

struct stack s[CAPACITY];
int top=-1;

int x=0;
int y=0;

int isEmpty()
{
if(top==-1)
    return 1;
else
    return 0;
}


int isFull()
{
if(top==CAPACITY-1)
    return 1;
else
    return 0;
}


void push()
{
if(isFull())
    {
     printf("You have used up all the 10 moves. Please go back to previous steps and try again.\n");
    }

else
    {
     ++top;
     s[top].row=x;
     s[top].col=y;
    }
}


void pop()
{
if(isEmpty())
    {
     printf("You are on the first step. Please make a valid move.\n");
    }

else
    {
     top--;
     x=s[top].row;
     y=s[top].col;
    }
}


int check()
{int i;

if(x==-1  ||  x==6  ||  y==-1  ||  y==6 )
    return 1;
else
    {for(i=0;i<=top+1;i++)
         {if(s[i].row==x && s[i].col==y)
              return 1;
          else
              continue;
         }
     }

return 0;
}



int main()
{
int maze[6][6]={4,0,1,0,1,0,1,0,1,0,1,0,1,0,0,0,0,1,0,0,1,0,1,1,1,0,1,0,0,0,1,1,1,0,1,1};
int i,j,u,v,temp;
char c;

s[0].row=0;
s[0].col=0;

printf("The Maze is:\n");
for(i=0;i<6;i++)
    {for(j=0;j<6;j++)
         printf("%d ",maze[i][j]);
     printf("\n");
    }

printf("\nUse the following control system: \nUp: w\nUp-Right: e\nRight: d\nDown-Right: c\nDown: x\nDown-Left: z\nLeft-a\nUp-Left: q\n\nMove back to the previous step: b\nStop: s\n\n");

printf("\nMake an exit through the element in row 5 - column 6 (starting from the element in row 1 - column 1) to win the game.\nCurrent Position is marked with 4.\n\n");

c='p';
while(c!='s')
    {
     temp=0;

     u=x;
     v=y;

     scanf("%c",&c);

     printf("\n");

     if(c=='w')
         {
          x=x-1;

          if(check()==0 && (maze[x][y]==0))
               push();

          else
              {
               x=x+1;

               printf("Invalid approach.Please re-enter.");
               temp=1;
               continue;
              }
         }

     else if(c=='e')
         {
          x=x-1;
          y=y+1;

          if(check()==0 && (maze[x][y]==0))
               push();

          else
              {
               x=x+1;
               y=y-1;

               printf("Invalid approach.Please re-enter.");
               temp=1;
               continue;
              }
         }

     else if(c=='d')
         {
          y=y+1;

          if(check()==0 && (maze[x][y]==0))
               push();

          else
              {
               y=y-1;

               printf("Invalid approach.Please re-enter.");
               temp=1;
               continue;
              }
         }

     else if(c=='c')
         {
          x=x+1;
          y=y+1;
          if(check()==0 && (maze[x][y]==0))
               push();

          else
              {
               x=x-1;
               y=y+1;

               printf("Invalid approach.Please re-enter.");
               temp=1;
               continue;
              }
         }

     else if(c=='x')
         {
          x=x+1;

          if(check()==0 && (maze[x][y]==0))
               push();

          else
              {
               x=x-1;

               printf("Invalid approach.Please re-enter.");
               temp=1;
               continue;
              }
         }

     else if(c=='z')
         {
          x=x+1;
          y=y-1;

          if(check()==0 && (maze[x][y]==0))
               push();

          else
              {
               x=x-1;
               y=y+1;

               printf("Invalid approach.Please re-enter.");
               temp=1;
               continue;
              }
         }

     else if(c=='a')
         {
          y=y-1;

          if(check()==0 && (maze[x][y]==0))
               push();

          else
              {
               y=y+1;

               printf("Invalid approach.Please re-enter.");
               temp=1;
               continue;
              }
         }

     else if(c=='q')
         {
          x=x-1;
          y=y-1;

          if(check()==0 && (maze[x][y]==0))
               push();

          else
              {
               x=x+1;
               y=y+1;

               printf("Invalid approach.Please re-enter.");
               temp=1;
               continue;
              }
         }

     else if(c=='b')
         pop();

     else if(c=='s' || c=='\n')
         continue;

     else
         {
          printf("Invalid input. Please re-enter.");
          temp=1;
          continue;
         }

     maze[u][v]=0;
     maze[x][y]=4;

     if(temp!=1)
         for(i=0;i<6;i++)
             {for(j=0;j<6;j++)
                  printf("%d ",maze[i][j]);
              printf("\n");
             }

     if(s[top].row==4 && s[top].col==5)
         {
          printf("\nCongratulations. You won the game.");
          break;
         }
     }

return 0;
}


