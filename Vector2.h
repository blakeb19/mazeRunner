#ifndef VECTOR2_H
#define VECTOR2_H

typedef struct Vector2
{
    int x;
    int y;
} Vector2;

void PrintV2(Vector2);
Vector2 AddV2(Vector2, Vector2);
int EquivV2(Vector2, Vector2);
void ZeroOut(Vector2*);

#endif
