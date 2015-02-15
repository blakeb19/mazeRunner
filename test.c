#include <stdio.h>
#include <curses.h>
#include "Vector2.h"
#include "Player.h"

int main()
{
    Vector2 vect;
    vect.x = 1;
    vect.y = 1;

    printV2(vect);
    return 0;
}
