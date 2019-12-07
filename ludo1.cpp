#include <iostream>
#include <cmath>
#include <string>
#include <cstdlib>
#include <ctime>
#include<iomanip>

using namespace std;

void check_turn(int& i, int& j)
{
    if(i = 7 && j <=5 )
    {
        j = j--;
    }
    else{i = i--;}

}

int dice() //Simulates dice roll
{
    srand(time(0));
    int roll= rand()%6+1;

    return roll;
}

void PrintBoard();

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
        ludo[posi][posj]="1";
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

    for(int i = 0; i < roll; i++)
    {
        check_turn(posi, posj);


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
