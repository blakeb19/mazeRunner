#include <stdio.h>
#include <curses.h>
#include "Vector2.h"
#include "Maze.h"

Maze MakeMaze(char filename[], WINDOW* win)
{
    FILE* file = fopen(filename, "r");
    Maze current;

    for (int i = 0; i < 21; i++)
    {
	for (int j = 0; j <= 31; j++)
	{
            char next = fgetc(file);
	    if (next == 'X')
	    {
		Vector2 start = {j, i};
		current.start = start;
            }

	    else if (next == 'O')
	    {
		Vector2 goal = {j, i};
		current.goal = goal;
	    }
            if (next != '\n' && next != EOF)
	    {
		current.layout[i][j] = next;
	    }
	}
    }

    current.win = win;

    fclose(file);
    return current;
}

void PrintMaze(Maze maze)
{
    for (int i = 0; i < 21; i++)
    {
        for (int j = 0; j < 31; j++)
	{
	    if (maze.layout[i][j] != ' ')
	    {
		mvwaddch(maze.win, i, j, maze.layout[i][j]);
	    }
	}

        printf("\n");
    }
}
