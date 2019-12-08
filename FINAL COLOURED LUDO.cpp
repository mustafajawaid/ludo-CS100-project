#include <iostream>
#include <cmath>
#include <string>
#include <cstdlib>
#include <ctime>
#include<iomanip>
#include <conio.h>
#include <windows.h>

using namespace std;

//ALL FUNCTIONS

void check_turn1(int& i, int& j);                               //function to check for turning points for Player 1
void check_turn2(int& x, int& y);                               //function to check for turning points for Player 2
int dice();                                                     //Simulates dice roll
void PrintBoard(string ludo[13][13], int posi, int posj);       //When called, prints board
void kill(int i, int j, int x, int y);                          //Kills one token depending on a coin toss

int main()
{
    int posi; //initial row value for p1
    int posj;  //initial column value for p1
    int posx;  //initial row value for p2
    int posy;  //initial column value for p2

    string ludo[13][13]; //declaring a 13 by 13 array to act as the board

    HANDLE color=GetStdHandle(STD_OUTPUT_HANDLE);// code to get color

    for(int i = 0; i<5; i++) //Assigns initial values for Quadrant 2
    {
        for(int j = 0; j<5; j++)
        {
            ludo[i][j] = "0";
        }
    }
    for(int i = 8; i<13; i++) //Assigns initial values for Quadrant 3
    {
        for(int j = 0; j<5; j++)
        {
            ludo[i][j] = "0";
        }
    }
    for(int i = 0; i<5; i++) //Assigns initial values for Quadrant 1
    {
        for(int j = 8; j<13; j++)
        {
            ludo[i][j] = "0";
        }
    }
    for(int i = 8; i<13; i++) //Assigns initial values for Quadrant 4
    {
        for(int j = 8; j<13; j++)
        {
            ludo[i][j] = "0";
        }
    }
    SetConsoleTextAttribute(color, 11);

    cout<<setw(50)<<"---          ----    ----   ------          ______"<<endl;
    cout<<setw(50)<<"|  |         |  |    |  |   |  __  \\       / ____ \\"<<endl;
    cout<<setw(50)<<"|  |         |  |    |  |   | |  \\  \\     / /    \\ \\"<<endl;
    cout<<setw(50)<<"|  |         |  |    |  |   | |   |  |   | |      | |"<<endl;
    cout<<setw(50)<<"|  |         |  |    |  |   | |__/  /    \\ \\     / /"<<endl;
    cout<<setw(50)<<"|   -----    \\  \\____/  /   |      /      \\ \\____/ /"<<endl;
    cout<<setw(50)<<"|________|    \\________/    |_____/        \\______/ " <<endl<<endl;

    SetConsoleTextAttribute(color, 14);

    PrintBoard(ludo, posi, posj); //Prints empty starting board

    int input_p1, input_p2;
    int roll1, roll2;

    do //loop to free first token for either p1 or p2
    {
        SetConsoleTextAttribute(color, 12);

        cout<<"\nPLAYER 1 Press 1 to roll dice: ";
        cin>>input_p1;

        roll1=dice(); //Roll 6 to free token
        SetConsoleTextAttribute(color, 12);
        cout<<"\nNumber rolled is "<<roll1<<endl<<endl;

        if(roll1==6) //If 6 is rolled, token is freed and added to the board (PLAYER 1)
        {
            posi = 11;  //initial row value for p2
            posj = 5;  //initial column value for p2
            ludo[posi][posj]="1";
            SetConsoleTextAttribute(color, 14);
            PrintBoard(ludo, posi, posj);
            break;
        }

        SetConsoleTextAttribute(color, 14);
        PrintBoard(ludo, posi, posj);

        SetConsoleTextAttribute(color, 10);
        cout<<"\nPLAYER 2 Press 1 to roll dice: ";
        cin>>input_p2;

        roll2=dice(); //Roll 6 to free token
        SetConsoleTextAttribute(color, 10);
        cout<<"\nNumber rolled is "<<roll2<<endl<<endl;

        if(roll2==6) //If 6 is rolled, token is freed and added to the board (PLAYER 2)
        {
            posx = 1;  //initial row value for p2
            posy = 7;  //initial column value for p2
            ludo[posx][posy]="2";
            SetConsoleTextAttribute(color, 14);
            PrintBoard(ludo, posx, posy);
            break;
        }

        SetConsoleTextAttribute(color, 14);
        PrintBoard(ludo, posx, posy);

    }while(roll1!=6 || roll2!=6);

    bool winner1 = false;
    bool winner2 = false;
    int counter=0;


    if(roll1==6) //Player 1 was first to roll a 6
    {
            do{
            SetConsoleTextAttribute(color, 12);
            cout<<"\nPLAYER 1 Press 1 to roll dice: "; //2nd turn of P1 after rolling a 6
            cin>>input_p1;
            int roll = dice();
            SetConsoleTextAttribute(color, 12);
            cout<<"\nNumber rolled is "<<roll<<endl<<endl;

            ludo[posi][posj] = " ";
            for(int i = 0; i < roll; i++) // Moves p1's token according to the dice rolls
            {
                check_turn1(posi, posj);
                /*kill(posi,posj,posx,posy);*/
                //Following conditional checks whether PLAYER 1 will win at any given turn
                if(posi == 12 && posj == 7 && roll >= 6 || posi == 12 && posj == 6 && roll >= 5 || posi == 11 && posj == 6 && roll >= 4 || posi == 10 && posj == 6 && roll >= 3 || posi == 9 && posj == 6 && roll >= 2 || posi == 8 && posj == 6 && roll >= 1)
                {
                    winner1 = true; break; //Assigns true to boolean var, terminating the for loop
                }
            }

            ludo[posi][posj] = "1";
            SetConsoleTextAttribute(color, 14);
            PrintBoard(ludo, posi, posj);

            if(winner1){cout<<endl<<endl << "WINNER: PLAYER 1\n\n"; ludo[posi][posj] = " "; ludo[6][6] = "1"; PrintBoard(ludo, posi, posj);break;} //If boolean var is true, larger do-while loop will be terminated, and program will end

            cout<<endl<<endl;

            if(counter==0) //counter present to check whether p2 has rolled the 6 required to free the token
            {   SetConsoleTextAttribute(color, 10);
                cout<<"PLAYER 2 Press 1 to roll dice: ";
                cin>>input_p2;
                roll2=dice(); //Roll 6 to free token
                SetConsoleTextAttribute(color, 10);
                cout<<"\nNumber rolled is "<<roll2<<endl<<endl;
                if(roll2==6) //If 6 is rolled, token will appear and counter will be incremented, thus code will not rerun as condition in line 126 will not be met
                {
                    posx=1;
                    posy=7;
                    ludo[posx][posy]="2";
                    SetConsoleTextAttribute(color, 14);
                    PrintBoard(ludo, posx, posy);
                    counter++;
                }
            }

            if(counter>0) //This will only be executed if the previous counter was incremented, meaning that if the initial 6 was not rolled, this part of the code will not execute
            {
                SetConsoleTextAttribute(color, 10);
                cout<<"PLAYER 2 Press 1 to roll dice: ";
                cin>>input_p2;
                int roll = dice();
                SetConsoleTextAttribute(color, 10);
                cout<<"\nNumber rolled is "<<roll<<endl<<endl;

                ludo[posx][posy] = " ";
                for(int i = 0; i < roll; i++) //Moves p2's token according to the dice rolls
                {
                    check_turn2(posx, posy);
                    /*kill(posi,posj,posx,posy);*/
                    //Following conditional checks whether PLAYER 2 will win at any given turn
                    if(posx == 0 && posy == 5 && roll == 6 || posx == 0 && posy == 6 && roll >= 5 || posx == 1 && posy == 6 && roll >= 4 || posx == 2 && posy == 6 && roll >= 3 || posx == 3 && posy == 6 && roll >= 2 || posx == 4 && posy == 6 && roll >= 1)
                    {
                        winner2 = true; break; //Assigns true to boolean var, terminating the for loop
                    }
                }

                ludo[posx][posy] = "2";
                SetConsoleTextAttribute(color, 14);
                PrintBoard(ludo, posx, posy);

                SetConsoleTextAttribute(color, 10);
                if(winner2){cout<<endl<<endl << "WINNER: PLAYER 2\n\n"; ludo[posx][posy] = " "; ludo[6][6] = "2"; PrintBoard(ludo, posx, posy); break;} //If boolean var is true, larger do-while loop will be terminated, and program will end

            }

            else
            {
                SetConsoleTextAttribute(color, 14);
                PrintBoard(ludo, posi, posj);
            }
            }while(!winner1 || !winner2);

    }

    else if(roll2==6) //Player 2 was first to roll a 6
    {
            do{
            SetConsoleTextAttribute(color, 10);
            cout<<"\nPLAYER 2 Press 1 to roll dice: ";
            cin>>input_p2;
            int roll = dice();
            SetConsoleTextAttribute(color, 10);
            cout<<"\nNumber rolled is "<<roll<<endl<<endl;

            ludo[posx][posy] = " ";
            for(int i = 0; i < roll; i++)
            {
                check_turn2(posx, posy);
                /*kill(posi,posj,posx,posy);*/
                if(posx == 0 && posy == 5 && roll == 6 || posx == 0 && posy == 6 && roll >= 5 || posx == 1 && posy == 6 && roll >= 4 || posx == 2 && posy == 6 && roll >= 3 || posx == 3 && posy == 6 && roll >= 2 || posx == 4 && posy == 6 && roll >= 1)
                {
                    winner2 = true; break;
                }
            }

            ludo[posx][posy] = "2";
            SetConsoleTextAttribute(color, 14);
            PrintBoard(ludo, posx, posy);

            SetConsoleTextAttribute(color, 10);
            if(winner2 == true){cout<<endl<<endl << "WINNER: PLAYER 2\n\n";ludo[posx][posy] = " ";ludo[6][6] = "2";PrintBoard(ludo, posx, posy);break;}

            cout<<endl<<endl;

            if(counter==0)
            {   SetConsoleTextAttribute(color, 12);
                cout<<"PLAYER 1 Press 1 to roll dice: ";
                cin>>input_p1;
                roll1=dice(); //Roll 6 to free token
                SetConsoleTextAttribute(color, 12);
                cout<<"\nNumber rolled is "<<roll1<<endl<<endl;
                if(roll1==6)
                {
                    posi=11;
                    posj=5;
                    ludo[posi][posj]="1";
                    SetConsoleTextAttribute(color, 14);
                    PrintBoard(ludo, posi, posj);
                    counter++;
                }
            }

            if(counter>0)
            {
                SetConsoleTextAttribute(color, 12);
                cout<<"\nPLAYER 1 Press 1 to roll dice: ";
                cin>>input_p1;
                int roll = dice();
                SetConsoleTextAttribute(color, 12);
                cout<<"\nNumber rolled is "<<roll<<endl<<endl;

                ludo[posi][posj] = " ";
                for(int i = 0; i < roll; i++)
                {
                    check_turn1(posi, posj);
                    /*kill(posi,posj,posx,posy);*/
                    //Following conditional checks whether PLAYER 1 will win
                    if(posi == 12 && posj == 7 && roll >= 6 || posi == 12 && posj == 6 && roll >= 5 || posi == 11 && posj == 6 && roll >= 4 || posi == 10 && posj == 6 && roll >= 3 || posi == 9 && posj == 6 && roll >= 2 || posi == 8 && posj == 6 && roll >= 1)
                    {
                        winner1 = true; break;
                    }
                }

                ludo[posi][posj] = "1";
                SetConsoleTextAttribute(color, 14);
                PrintBoard(ludo, posi, posj);

                SetConsoleTextAttribute(color, 12);
                if(winner1){cout<<endl<<endl << "WINNER: PLAYER 1\n\n"; ludo[posi][posj] = " "; ludo[6][6] = "1"; PrintBoard(ludo, posi, posj);break;}

            }

            else
            {
                SetConsoleTextAttribute(color, 14);
                PrintBoard(ludo, posi, posj);
            }

            }while(!winner1 || !winner2);
    }

    return 0;
}


void check_turn1(int& i, int& j)
{
    if(i==7 && j <5 && j >0 )// first turning point (7, 5) for player1
    {
        j--;
    }
    else if(i==8 && j == 5)// first jumping point for player1
    {
        i--;
        j--;
    }
    else if(i<=7 && j==0 && i>5)// second turning point (7, 0) for player 1
    {
        i--;
    }
    else if(i==5 && j >=0 && j<4)// third turning point(5, 0) for player1

    {
        j++;
    }
    else if(i==5 && j==4)// second jumping point (5, 4) for player1
    {
        i--;
        j++;
    }
    else if(j==5 && i <5 && i>0)// fourth turning point (5, 4) for player1
    {
        i--;
    }
    else if(j>=5 && i==0 && j<7)//fifth turning point (0, 5) for player1
    {
        j++;
    }
    else if(j==7 && i>=0 && i <4)// sixth turning point (0, 7) for player1
    {
        i++;
    }
    else if(i==4 && j==7)// third jumping point (4, 7) for player1
    {
        j++;
        i++;
    }
    else if(i==5 && j >=8 & j<12)// seventh turning point (5, 8) for player1
    {
        j++;
    }
    else if(i>=5 && j==12 && i <7)// eight turning point (5, 12) for player1
    {
        i++;
    }
    else if(i==7 && j<=12 && j>8)// ninth turning point (7, 12) for player1
    {
        j--;
    }
    else if(i==7 && j==8)// fourth jumping point (7, 8)
    {
        i++;
        j--;
    }
    else if(i>=7 && j==7 && i<12)// tenth turning point
    {
        i++;
    }
    else if(i==12 && j==7)// eleventh turning point (home run)
    {
        j--;
    }
    else if(j==6 && i<=12 && i>=8)// home run
    {
        i--;
    }
    else
    {
        i--;
    }

}

void check_turn2(int& x, int& y)
{
    if(x >= 1 && x < 4 && y == 7 && y > 0)
    {
        x++;
    }
    else if(x == 4 && y == 7)// first jumping point player2
    {
        x++;
        y++;
    }
    else if(x == 5 && y >= 7 && y<12)// first turning point player2
    {
        y++;
    }
    else if(x >= 5 && y == 12 && x < 7)// second turning point player2
    {
        x++;
    }
    else if( y<= 12 && x == 7 && y > 8)// third turning point player2
    {
        y--;
    }
    else if(y == 8 && x == 7)// second jumping point player2
    {
        x++;
        y--;
    }
    else if(x >= 8 && x < 12 && y == 7)// fourth turning point
    {
        x++;
    }
    else if(x == 12 && y <= 7 && y > 5)// fifth turning point
    {
        y--;
    }
    else if(y == 5 && x <=12 && x > 8)// sixth turning point
    {
        x--;

    }
    else if(x == 8 && y == 5)// third jumping point
    {
        x--;
        y--;
    }
    else if(y <= 4 && y > 0 && x == 7)// seventh turning point
    {
        y--;
    }
    else if(x <= 7 && y == 0 && x > 5)// eighth turning point
    {
        x--;
    }
    else if(x == 5 && y >= 0 && y < 4)// ninth turning point
    {
        y++;
    }
    else if(x == 5 && y == 4)// fourth jumping point
    {
        x--;
        y++;
    }
    /*else if(y == 5 && x <5 && x > 0)
    {
        x--;
    }
    */
    else if(y == 5 && x == 0)// tenth turning point (home run)
    {
        y++;
    }
    else if(x >= 0 && y == 6)// home run
    {
        x++;
    }
    else {x--;}


}
int dice()
{
    srand(time(0));
    int roll= rand()%6+1;

    return roll;
}

void PrintBoard(string ludo[13][13], int posi, int posj)
{
    for(int i = 0; i<13; i++)
    {
        for(int j = 0; j<13; j++)
        {
            cout << setw(1) << ludo[i][j];
        }
        cout<<endl;
    }
}
void kill(int i, int j, int x, int y)
{
    if(i == x && j == y)
    {
        cout << "COIN TOSS!" << endl;
        int a = rand()%2;
        char b;
        if(a == 0){b = 'H';}
        else{b = 'T';}

        if(b == 'H')
        {
            cout << "COIN TOSS YIELDED HEADS: PLAYER 1 KILLED" << endl;
            i = 11; j = 5;
        }
        else if(b == 'T')
        {
            cout << "COIN TOSS YIELDED TAILS: PLAYER 2 KILLED" << endl;
            x = 1;
            y = 7;
        }
    }
}
