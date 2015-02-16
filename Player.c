#include <stdio.h>
#include <curses.h>
#include "Vector2.h"
#include "Player.h"

Player CreateActor(Vector2 start, WINDOW* parent)
{
    Player actor;
    actor.pos = start;
    actor.win = parent;
    return actor;
}

void changePos(Player* actor, Vector2 move)
{
    actor->pos = addV2(actor->pos, move);
}

void update(Player* actor)
{
    mvwaddch(actor->win, actor->pos.y, actor->pos.x, 'X');
}
