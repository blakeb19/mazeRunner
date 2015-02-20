#ifndef PLAYER_H
#define PLAYER_H

#include <curses.h>
#include "Vector2.h"
#include "Maze.h"

typedef struct Player
{
    WINDOW* win;
    Vector2 pos;
} Player;

Player CreateActor(Vector2, WINDOW*);
void ChangePos(Player*, Vector2);
void Update(Player*, Vector2, Maze);

#endif
