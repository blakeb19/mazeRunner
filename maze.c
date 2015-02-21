#include <stdio.h>
#include <stdlib.h>
#include <curses.h>


int main()
{

	FILE*  fPtr;

	printMaze(fPtr);
	
	return 0;

}

int printMaze(FILE* fPtr)
{
	WINDOW* window = NULL;

	int maxHeight = 21;
	int maxWidth = 31;

	char symbol;

	initscr();

	noecho();

	int winHeight = getmaxy(stdscr);
	int winWidth = getmaxx(stdscr);

	window = newwin(winHeight, winWidth, 0, 0);


	wrefresh(stdscr);



	if( ( fPtr = fopen( "maze.txt", "r" ) ) == NULL)
	{
		wprintw(window, "The file could not be opened\n");
		wrefresh(window);
		endwin();
	}
	else
	{

		while( !feof( fPtr ) )
		{
			symbol = fgetc(fPtr);
			wprintw(window,"%c",symbol);
		}
		
		wrefresh(window);
	}

	

	fclose(fPtr);

	return 0;
}
