#include <stdio.h>
#include <curses.h>
#include "Vector2.h"
#include "Player.h"
#include "Maze.h"

int main()
{
    initscr();

    curs_set(0);

    noecho();

    WINDOW* win = NULL;
    int height = getmaxy(stdscr);
    int width  = getmaxx(stdscr);

    win = newwin(height, width, 0, 0);

    keypad(win, TRUE);

    wrefresh(stdscr);

    Maze current = MakeMaze("maze.txt", win);

    Vector2 start = current.start;

    Player actor = CreateActor(start, win);

    int ch = ' ';
    Vector2 move = {0, 0};
    PrintMaze(current);

    while(1)
    {
	Update(&actor, move, current);
	ZeroOut(&move);

        ch = wgetch(win);

	if (ch == KEY_DOWN)
	{ move.y++; }
	if (ch == KEY_UP)
	{ move.y--; }
        if (ch == KEY_LEFT)
	{ move.x--; }
        if (ch == KEY_RIGHT)
	{ move.x++; }
	if (ch == ' ')
	{ werase(win);}
	if (ch == 'q')
	{ break;}

	if (EquivV2(AddV2(actor.pos, move), current.goal))
	{
	    mvwprintw(win, 5, 40, "You Win!");
	}

        wrefresh(win);
    }

    delwin(win);
    endwin();

    return 0;
}
