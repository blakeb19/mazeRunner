#ifndef PLAYER_H
#define PLAYER_H

#include <curses.h>
#include "Vector2.h"

typedef struct Player
{
    WINDOW* win;
    Vector2 pos;
} Player;

Player CreateActor(Vector2, WINDOW*);
void changePos(Player*, Vector2);
void update(Player*);

#endif
