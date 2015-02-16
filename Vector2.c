#include <stdio.h>
#include "Vector2.h"

void PrintV2(Vector2 vect)
{
    printf("Vector x: %d y: %d\n", vect.x, vect.y);
}

Vector2 AddV2(Vector2 a, Vector2 b)
{
    Vector2 sum;
    sum.x = a.x + b.x;
    sum.y = a.y + b.y;
    return sum;
}

void ZeroOut(Vector2* in)
{
    in->x = 0;
    in->y = 0;
}
