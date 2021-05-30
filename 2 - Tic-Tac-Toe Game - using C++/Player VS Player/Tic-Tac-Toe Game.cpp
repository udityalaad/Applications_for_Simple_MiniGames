#include<iostream>
#include<stdlib.h>
using namespace std;

class TicTacToe
{
char square[10]={'0','1','2','3','4','5','6','7','8','9'};
int player=1;

public: void play()
        {
         int choice,i;
         char mark;

         do
            {
             board();

             player = (player%2)? 1:2;
             mark = (player==1)? 'X':'O';

             cout<<"  Player "<<player<<": ";
             cin>>choice;

             if(choice==1 && square[1]=='1')
                square[1]=mark;
             else if(choice==2 && square[2]=='2')
                square[2]=mark;
             else if(choice==3 && square[3]=='3')
                square[3]=mark;
             else if(choice==4 && square[4]=='4')
                square[4]=mark;
             else if(choice==5 && square[5]=='5')
                square[5]=mark;
             else if(choice==6 && square[6]=='6')
                square[6]=mark;
             else if(choice==7 && square[7]=='7')
                square[7]=mark;
             else if(choice==8 && square[8]=='8')
                square[8]=mark;
             else if(choice==9 && square[9]=='9')
                square[9]=mark;
             else
                {
                 cout<<"\n  Invalid move! Please make a valid move.";
                 player--;

                 cin.ignore();
                 cin.get();
                }

             i=checkwin();
             player++;

            }while(i==-1);


         board();

         if(i==1)
            cout<<"  Player "<<--player<<" Wins";
         else
            cout<<"  Game Draw";

         cin.ignore();
         cin.get();
        }


        int checkwin()
        {
         if(square[1]==square[2] && square[2]==square[3])
            return 1;
         else if(square[4]==square[5] && square[5]==square[6])
            return 1;
         else if(square[7]==square[8] && square[8]==square[9])
            return 1;
         else if(square[1]==square[4] && square[4]==square[7])
            return 1;
         else if(square[2]==square[5] && square[5]==square[8])
            return 1;
         else if(square[3]==square[6] && square[6]==square[9])
            return 1;
         else if(square[1]==square[5] && square[5]==square[9])
            return 1;
         else if(square[3]==square[5] && square[5]==square[7])
            return 1;

         else if(square[1]!='1'  &&  square[2]!='2'  &&  square[3]!='3'  &&  square[4]!='4'  &&  square[5]!='5'  &&  square[6]!='6'  &&  square[7]!='7'  &&  square[8]!='8'  &&  square[9]!='9')
            return 0;

         else
            return -1;
        }


        void board()
        {
         system("cls");

         cout<<"---------------------";
         cout<<"\n     Tic-Tac-Toe";
         cout<<"\n---------------------";

         cout<<"\n\n    Player 1 - X";
         cout<<"\n    Player 2 - O";


         cout<<"\n\n\n       |     |";

         cout<<"\n    "<<square[1]<< "  |  "<<square[2]<<"  |  "<<square[3];

         cout<<"\n  _____|_____|_____";
         cout<<"\n       |     |";

         cout<<"\n    "<<square[4]<< "  |  "<<square[5]<<"  |  "<<square[6];

         cout<<"\n  _____|_____|_____";
         cout<<"\n       |     |";

         cout<<"\n    "<<square[7]<< "  |  "<<square[8]<<"  |  "<<square[9];

         cout<<"\n       |     |\n\n\n";
        }
};



int main()
{
TicTacToe t;

t.play();

return 0;
}
