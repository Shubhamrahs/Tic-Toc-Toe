#include<bits/stdc++.h>
using namespace std;

bool flag=true;
string Player1="[X]",Player2="[0]";
int first,second;
int start=0;
char block[9]={'1','2','3','4','5','6','7','8','9'};

void welcome()
{
    cout<<"   \n\n";
    cout<<" \t \t  \\\\        //\\\\        //    ///////       //            ////////     //////////    //\\\\        //\\\\            ////////  \n";
    cout<<" \t \t   \\\\      //  \\\\      //    //            //            //           //      //    //  \\\\      //  \\\\          //         \n";
    cout<<" \t \t    \\\\    //    \\\\    //    ///////       //            //           //      //    //    \\\\    //    \\\\        ///////     \n";
    cout<<" \t \t     \\\\  //      \\\\  //    //            //            //           //      //    //      \\\\  //      \\\\      //           \n";
    cout<<" \t \t      \\\\//        \\\\//    ////////      /////////     /////////    //////////    //        \\\\//        \\\\    /////////     \n\n\n";
}

void show()
{
    cout<<"\n \n";
    cout<<"\t //////// ////////   ///////           ////////  //\\\\      ///////             ////////  ////////  ///////             \n";
    cout<<"\t   //       //      //        //////     //     //==\\\\    //        //////       //     //    //  //==                   \n";
    cout<<"\t  //    ////////   ///////              //     //    \\\\  ///////                //     ////////  ///////               \n\n\n";
    cout<<"\t Choose any one \n";
    cout<<"\t 1. New Game \n";
    cout<<"\t 2. Score \n";
    cout<<"\t 3. Reset Your Score \n";
    cout<<"\t 4. Hint \n";
    cout<<"\t 5. Quit \n";
    cout<<"\t 6. About \n";
}

bool check()
{
    if(((block[0]==block[4]) && (block[0]==block[8])) || ((block[0]==block[1]) && (block[0]==block[2])) ||((block[3]==block[4]) && (block[3]==block[5])) || ((block[6]==block[7]) && (block[6]==block[8])) ||((block[0]==block[3]) && (block[0]==block[6])) || ((block[1]==block[4]) && (block[1]==block[7])) ||((block[2]==block[5]) && (block[2]==block[8])) || ((block[2]==block[4]) && (block[2]==block[6])))
            return true;
    return false;
}

void initial()
{
    for(int i=0;i<9;i++)
        block[i]=49+i;
}

void board()
{

    system("cls");
    cout<<"\n";
    cout<<"\t\t         |         |      \n";
    cout<<"\t\t         |         |      \n";
	cout<<"\t\t         |         |      \n";
	cout<<"\t\t     "<<block[0]<<"   |   "<<block[1]<<"     |   "<<block[2]<<"   \n";
	cout<<"\t\t_________|_________|_________\n";
	cout<<"\t\t         |         |      \n";
	cout<<"\t\t         |         |      \n";
	cout<<"\t\t     "<<block[3]<<"   |   "<<block[4]<<"     |   "<<block[5]<<"  \n";
	cout<<"\t\t         |         |      \n";
	cout<<"\t\t_________|_________|_________\n";
	cout<<"\t\t         |         |      \n";
	cout<<"\t\t     "<<block[6]<<"   |   "<<block[7]<<"     |   "<<block[8]<<"  \n";
	cout<<"\t\t         |         |      \n";
	cout<<"\t\t         |         |      \n";
	cout<<"\t\t         |         |      \n";
}

void action()
{
    int val,f=0;
    for(int j=1;j<=9;j++)
    {
        if(j%2!=0)
            cout<<Player1<<" It's your turn [X] \n";
        else
            cout<<Player2<<" It's your turn [0] \n";
        cin>>val;

        if(val>=1 && val<=9)
        {
            if(block[val-1]=='X' || block[val-1]=='0')
            {
                cout<<"This place is filled. Please enter differnet value. \n";
                j=j-1;
                continue;
            }
            else if(j%2!=0)
                block[val-1]='X';
            else
                block[val-1]='0';
            board();
            if(check())
            {
                if(j%2!=0)
                {
                    cout<<"\t "<<Player1<<" [X] 'WIN' this Match \n\n";
                    first++;
                    cout<<"\n\t\tScore:- "<<Player1<<" "<<first<<" , "<<Player2<<" "<<second<<"\n";
                }
                else
                {
                    cout<<"\t "<<Player2<<" [0] 'WIN' this Match \n\n";
                    second++;
                    cout<<"\n\t\tScore:- "<<Player1<<" "<<first<<" , "<<Player2<<" "<<second<<"\n";
                }
                f=1;
                break;
            }
        }
        else
        {
            cout<<"\t Invalid Input Please try again\n";
            cout<<"\n\t\tScore:- "<<Player1<<" "<<first<<" , "<<Player2<<" "<<second<<"\n";
            j=j-1;
        }
    }
    if(f==0)
    {
        cout<<"\t This Match is 'TIE' \n";
        cout<<"\n\t\tScore:- "<<Player1<<" "<<first<<" , "<<Player2<<" "<<second<<"\n";
    }
}

void Score()
{
    system("cls");
    cout<<Player1<<" Score:- "<<first<<"\n";
    cout<<Player2<<" Score:- "<<second<<"\n\n";
    if(first>second)
        cout<<" Overall "<<Player1<<" is WIN today's Game. With Final Score is "<<first<<" - "<<second<<" \n\n";
    else if(first<second)
        cout<<" Overall "<<Player2<<" is WIN today's Game. With Final Score is "<<second<<" - "<<first<<" \n\n";
    else
        cout<<" Overall today's Game is 'TIE' between "<<Player1<<" and "<<Player2<<" With Final Score is "<<first<<" - "<<second<<" \n\n";


    bool f=true;
    while(f)
    {
        char var;
        cout<<" \t Press 'r' to Return on previous menu. \n";
        cin>>var;
        if(var=='r')
            f=false;
        else
            cout<<" Please Press correct key. \n\n";
    }
    system("cls");
}

bool new_game()
{
    char c;
    bool f=true;
    cout<<" Do you want to Play Again \n";
    while(f)
    {
        cout<<" Press 'y' for (YES) and 'n' for (NO) \n";
        cin>>c;
        if(c=='y')
        {
            f=false;
            return true;

        }
        else if(c=='n')
        {
            f=false;
            cout<<"OK.... Your score is:- \n";
            cout<<Player1<<" Score:- "<<first<<"\n";
            cout<<Player2<<" Score:- "<<second<<"\n";

        }
        else
            cout<<" Please enter correct value. \n\n";
    }

    char var;
    bool f2=true;
    while(f2)
    {
        cout<<"\n\n \t Press 'r' to Return on previous menu. \n";
        cin>>var;
        if(var=='r')
        {
            f2 =false;
            return false;
        }

        else
            cout<<" Please Press correct key. \n\n";
    }

}



void game()
{
    if(start==0)
    {
        cout<<" Enter Player1 name: ";
        cin>>Player1;
        cout<<" Enter Player2 name: ";
        cin>>Player2;
        start=1;
    }
    initial();
    board();
    cout<<"\n\t\tScore:- "<<Player1<<" "<<first<<" , "<<Player2<<" "<<second<<"\n";
    action();
    if(new_game())
        game();
    else
        system("cls");
}








void Reset()
{
    system("cls");
    char c;
    bool f=true;
    cout<<" Do you want to Reset Your score! \n";


    while(f)
    {
        cout<<" Press 'y' for (YES) and 'n' for (NO) \n";
        cin>>c;
        if(c=='y')
        {
            first=0;
            second=0;
            cout<<"Your Score is Reset. \n";
            f=false;
        }
        else if(c=='n')
        {
            cout<<" OK... Your Score is: \n";
            cout<<Player1<<" Score:- "<<first<<"\n";
            cout<<Player2<<" Score:- "<<second<<"\n\n";
            f=false;
        }
        else
        {
            cout<<" Please enter correct value. \n";
            f=true;
        }

    }



    char var;
    bool f2=true;
    while(f2)
    {
        cout<<" \t Press 'r' to Return on previous menu. \n";
        cin>>var;
        if(var=='r')
            f2=false;
        else
            cout<<" Please Press correct key. \n\n";
    }
    system("cls");

}

void Hint()
{
    system("cls");
    cout<<" \t RULES FOR TIC-TAC-TOE \n";

    cout<<" The game is played on a grid that's 3 squares by 3 squares.";
    cout<<" Let, You are X, your friend is O. Players take turns putting their marks in empty squares.\n";
    cout<<" The first player to get 3 of her marks in a row (up, down, across, or diagonally) is the winner.";
    cout<<" When all 9 squares are full, the game is over. If no player has 3 marks in a row, the game ends in a tie.\n\n";
    char var;
    bool f=true;
    while(f)
    {
        cout<<" \t Press 'r' to Return on previous menu. \n";
        cin>>var;
        if(var=='r')
            f=false;
        else
            cout<<" Please Press correct key. \n\n";
    }
    system("cls");

}

void Quit()
{
    system("cls");
    char c;
    bool f=true;
    cout<<" Do you Really want to Quit. \n";
    while(f)
    {
        cout<<" Press 'y' for (YES) and 'n' for (NO) \n";
        cin>>c;
        if(c=='y')
        {
            flag = false;
            f=false;
        }
        else if(c=='n')
        {
            flag=true;
            f=false;
        }
        else
        {
            cout<<" Please enter correct value. \n";
            f=true;
        }
    }
    char var;
    bool f2=true;
    while(f2)
    {
        cout<<" \t Press 'r' to Return our Main menu. \n";
        cin>>var;
        if(var=='r')
            f2=false;
        else
            cout<<" Please Press correct key. \n\n";
    }
    system("cls");
}

void About()
{
    system("cls");
    cout<<"\tThis is a game, named as 'TIC-TAC-TOE'. \n";
    cout<<"\tDeveloped by 'SHUBHAM SHARMA'. \n\n";
    char var;
    bool f=true;
    while(f)
    {
        cout<<" \t Press 'r' to Return on previous menu. \n";
        cin>>var;
        if(var=='r')
            f=false;
        else
            cout<<" Please Press correct key. \n\n";
    }
    system("cls");
}

void wrong()
{
    cout<<"\t Invalid !.... Please select correct number.  \n";
}

void window()
{
    int choice;
    cin>>choice;
    switch(choice)
    {
        case 1: game(); break;
        case 2: Score(); break;
        case 3: Reset(); break;
        case 4: Hint(); break;
        case 5: Quit(); break;
        case 6: About(); break;
        default: wrong(); break;
    }
}

main()
{
    welcome();
    while(flag)
    {
        show();
        window();
    }
    welcome();
    show();
    cout<<"\n\n\t\t -------------------Thanks for Using our game----------------------- \n\n";
}
