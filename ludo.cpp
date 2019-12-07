#include <iostream>
#include <cmath>
#include <string>
#include <cstdlib>
#include <ctime>
#include<iomanip>

using namespace std;

int dice() //Simulates dice roll
{
    srand(time(0));
    int roll= rand()%6+1;

    return roll;
}

void PrintBoard();

int main()
{

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


int initial_i=11, initial_j=5;
//ludo[initial_i][initial_j]="1";
int input;

for(int i = 0; i<13; i++) //Empty Board Printing
{
    for(int j = 0; j<13; j++)
    {
        cout << setw(1) << ludo[i][j];
    }
    cout<<endl;
}

int roll1;
do
{
    cout<<"\nPress 1 to roll dice: ";
    cin>>input;

    roll1=dice(); //Roll 6 to free gotti
    cout<<"\nNumber rolled is "<<roll1<<endl<<endl;

    if(roll1==6)
    {
        ludo[initial_i][initial_j]="1";
    }

    for(int i = 0; i<13; i++) //Empty Board Printing
    {
        for(int j = 0; j<13; j++)
        {
            cout << setw(1) << ludo[i][j];
        }
    cout<<endl;
    }

}while(roll1!=6);

cout<<"\nPress 1 to roll dice: ";
while(cin>>input)
{
    int roll = dice();
    cout<<"\nNumber rolled is "<<roll<<endl<<endl;

    if(initial_i-roll<8)
    {
        ludo[initial_i-4][initial_j-(roll-3)]="1";
        int pos_i=initial_i-4, pos_j=initial_j-roll+3;
    }

    else
    {
        ludo[initial_i-roll][initial_j]="1";
    }



/*for(int i = initial_i; i>initial_i-roll-1; i--)
{
    ludo[i][5]="1";
}*/

    for(int i = 0; i<13; i++) //Board Printing
    {
        for(int j = 0; j<13; j++)
        {
            cout << setw(1) << ludo[i][j];
        }
            cout<<endl;
    }

    cout<<endl<<endl;
    cout<<"Press 1 to roll dice: ";

}

return 0;
}
