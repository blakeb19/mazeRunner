#ifndef MAZE_H
#define MAZE_H

#include <stdio.h>
#include <curses.h>
#include "Vector2.h"

typedef struct Maze
{
    char layout[21][31];
    WINDOW* win;
    Vector2 start;
    Vector2 goal;
} Maze;

Maze MakeMaze(char[], WINDOW*);
void PrintMaze(Maze);

#endif
