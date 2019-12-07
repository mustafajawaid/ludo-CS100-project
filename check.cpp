#include <iostream>
#include <cmath>
#include <string>
#include <cstdlib>
#include <ctime>
#include<iomanip>

using namespace std;

void check_turn(int& i, int& j);
int dice(); //Simulates dice roll
void PrintBoard(string ludo[13][13], int posi, int posj);

int main()
{
    int posi = 11;
    int posj = 5;
    string ludo[13][13];

    for(int i = 0; i<5; i++) //Quadrant 2
    {
        for(int j = 0; j<5; j++)
        {
            ludo[i][j] = "0";
        }
    }
    for(int i = 8; i<13; i++) //Quadrant 3
    {
        for(int j = 0; j<5; j++)
        {
            ludo[i][j] = "0";
        }
    }
    for(int i = 0; i<5; i++) //Quadrant 1
    {
        for(int j = 8; j<13; j++)
        {
            ludo[i][j] = "0";
        }
    }
    for(int i = 8; i<13; i++) //Quadrant 4
    {
        for(int j = 8; j<13; j++)
        {
            ludo[i][j] = "0";
        }
    }

    PrintBoard(ludo, posi, posj);


    int input;
    int roll1;

    do
    {
        cout<<"\nPress 1 to roll dice: ";
        cin>>input;

        roll1=dice(); //Roll 6 to free gotti
        cout<<"\nNumber rolled is "<<roll1<<endl<<endl;

        if(roll1==6)
        {
            ludo[posi][posj]="1";
        }

        PrintBoard(ludo, posi, posj);

    }
    while(roll1!=6);

    cout<<"\nPress 1 to roll dice: ";

    while(cin>>input)
    {
        int roll = dice();
        cout<<"\nNumber rolled is "<<roll<<endl<<endl;

        ludo[posi][posj] = " ";
        for(int i = 0; i < roll; i++)
        {
            check_turn(posi, posj);
            cout << posi << " " << posj << endl;
        }
        ludo[posi][posj] = "1";



        /* if(posi-roll<8)
         {
             ludo[posi-4][posj-(roll-3)]="1";
             ludo[posi][posj] = " ";
         }

         else
         {
             ludo[posi-roll][posj]="1";
             ludo[posi][posj] = " ";
         }*/



        /*for(int i = initial_i; i>initial_i-roll-1; i--)
        {
            ludo[i][5]="1";
        }*/

        PrintBoard(ludo, posi, posj);
        cout<<endl<<endl;
        cout<<"Press 1 to roll dice: ";

    }

    return 0;
}

void check_turn(int& i, int& j)
{
    if(i==7 && j <5 && j >0 )
    {
        j--;
    }
    else if(i==8 && j == 5)
    {
        i--;
        j--;
    }
    else if(i<=7 && j==0 && i>5)
    {
        i--;
    }
    else if(i==5 && j >=0 && j<4)
    {
        j++;
    }
    /*else if(i==5 && j<4 && j>0)
    {
        j--;
    }*/
    else if(i==5 && j==4)
    {
        i--;
        j++;
    }
    else if(j==5 && i <5 && i>0)
    {
        i--;
    }
    else if(j>=5 && i==0 && j<7)
    {
        j++;
    }
    else if(j==7 && i>=0 && i <4)
    {
        i++;
    }
    else if(i==4 && j==7)
    {
        j++;
        i++;
    }
    else if(i==5 && j >=8 & j<12)
    {
        j++;
    }
    else if(i>=5 && j==12 && i <7)
    {
        i++;
    }
    else if(i==7 && j<=12 && j>8)
    {
        j--;
    }
    else if(i==7 && j==8)
    {
        i++;
        j--;
    }
    else if(i>=7 && j==7 && i<12)
    {
        i++;
    }
    else if(i==12 && j==7)
    {
        j--;
    }
    else if(j==6 && i<=12 && i>=8)
    {
        i--;
    }
    else
    {
        i--;
    }

    //if posi == posa

}

int dice() //Simulates dice roll
{
    srand(time(0));
    int roll= rand()%6+1;

    return roll;
}

void PrintBoard(string ludo[13][13], int posi, int posj)
{
    for(int i = 0; i<13; i++) //Empty Board Printing
    {
        for(int j = 0; j<13; j++)
        {
            cout << setw(1) << ludo[i][j];
        }
        cout<<endl;
    }
}

