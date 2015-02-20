#include <stdio.h>
#include <curses.h>
#include "Vector2.h"
#include "Player.h"
#include "Maze.h"

Player CreateActor(Vector2 start, WINDOW* parent)
{
    Player actor;
    actor.pos = start;
    actor.win = parent;
    return actor;
}

void ChangePos(Player* actor, Vector2 move)
{
    actor->pos = AddV2(actor->pos, move);
}

void Update(Player* actor, Vector2 move, Maze m)
{
    mvwaddch(actor->win, actor->pos.y, actor->pos.x, ' ');

    if (actor->pos.x + move.x < 0 || actor->pos.x + move.x > getmaxx(actor->win) - 1)
    { move.x = 0; }

    else if (m.layout[actor->pos.y][actor->pos.x + move.x] != ' ')
    { move.x = 0; }

    if (actor->pos.y + move.y < 0 || actor->pos.y + move.y > getmaxy(actor->win) - 1)
    { move.y = 0; }

    else if (m.layout[actor->pos.y + move.y][actor->pos.x] != ' ')
    { move.y = 0; }

    ChangePos(actor, move);
    mvwaddch(actor->win, actor->pos.y, actor->pos.x, 'X');
}
