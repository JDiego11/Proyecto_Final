#include "morty.h"

void Morty::Move_up()
{
    int posy = getPosY();
    setPosY(posy - 1);
}

void Morty::Move_down()
{
    int posy = getPosY();
    setPosY(posy + 1);
}

void Morty::Move_left()
{
    int posx = getPosX();
    setPosX(posx - 1);
}

void Morty::Move_right()
{
    int posx = getPosX();
    setPosX(posx - 1);
}

void Morty::Take_Damage(int damage)
{
    int NewHealth;
    NewHealth = Health - (damage - (damage * Resistance / 100));

    setHealth(NewHealth);
}
