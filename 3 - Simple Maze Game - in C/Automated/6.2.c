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
if(!isFull())
    {
     top++;
     s[top].row=x;
     s[top].col=y;
    }
}


void pop()
{
if(!isEmpty())
    {
     top--;
     x=s[top].row;
     y=s[top].col;
    }
}


int check(int a,int b)
{int i;

if(a==-1  ||  a==6  ||  b==-1  ||  b==6 )
    return 1;
else
    {for(i=0;i<=top+1;i++)
         {if(s[i].row==a && s[i].col==b)
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
int i,j,d,u,v;
char c;

s[0].row=0;
s[0].col=0;

printf("The Maze is:\n");
for(i=0;i<6;i++)
    {for(j=0;j<6;j++)
         printf("%d ",maze[i][j]);
     printf("\n");
    }

d=1;
while(d>0)
    {
     u=x;
     v=y;

     if(check(x-1,y)==0 && (maze[x-1][y]==0))
         {
          x--;
          push();
         }

     else if(check(x-1,y+1)==0 && (maze[x-1][y+1]==0))
               {
                x--;
                y++;
                push();
               }

     else if(check(x,y+1)==0 && (maze[x][y+1]==0))
               {
                y++;
                push();
               }

     else if(check(x+1,y+1)==0 && (maze[x+1][y+1]==0))
               {
                x++;
                y++;
                push();
               }

     else if(check(x+1,y)==0 && (maze[x+1][y]==0))
               {
                x++;
                push();
               }

     else if(check(x+1,y-1)==0 && (maze[x+1][y-1]==0))
               {
                x++;
                y--;
                push();
               }

     else if(check(x,y-1)==0 && (maze[x][y-1]==0))
               {
                y--;
                push();
               }

     else if(check(x-1,y-1)==0 && (maze[x-1][y-1]==0))
         {
          x--;
          y--;
          push();
         }

     else
         {
          pop();
         }


     maze[u][v]=0;
     maze[x][y]=4;

     printf("\n");
     for(i=0;i<6;i++)
         {for(j=0;j<6;j++)
          printf("%d ",maze[i][j]);
          printf("\n");
         }

     if(s[top].row==4 && s[top].col==5)
         {
          printf("\nGame successfully completed.");
          break;
         }

    }
    
    scanf("%c",&c);

return 0;
}
