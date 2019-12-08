void check_turn2(int& x, int& y)
{

    if(x == 4 && y == 7)
    {
        x++;
        y++;
    }
    else if(x == 5 && y>7 && y<12)
    {
        y++;
    }
    else if(x >= 5 && y == 12 && x <= 7)
    {
        x++;
    }
    else if( y<= 12 && x == 7 && y > 8)
    {
        y--;
    }
    else if(y == 8 && x == 7)
    {
        x++;
        y++;
    }
    else if(x >= 8 && x < 12 && y== 7)
    {
        x++;
    }
    else if(x == 12 && y <= 7 && y > 5)
    {
        y--;
    }
    else if(y == 5 && x >= 12 && x < 8)
    {
        x--;

    }
    else if(x == 8 && y == 5)
    {
        x--;
        y--;
    }
    else if(y <= 4 && y > 0 && x == 7)
    {
        y--;
    }
    else if(x <= 7 && y == 0 && x > 5)
    {
        x--;
    }
    else if(x == 5 && y >= 0 && y < 4)
    {
        y++;
    }
    else if(x == 5 && y == 4)
    {
        x--;
        y++;
    }
    else if(y == 5 && x <5 && x > 0)
    {
        i--;
    }
    else if(y > 5 && < 6 && x == 0)
    {
        y++;
    }
    else if(x == 0 && y == 6 && x<=5)
    {
        x++;
    }
    else {x--;}




}
