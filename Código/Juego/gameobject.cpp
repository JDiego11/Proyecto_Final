#include "gameobject.h"
#include "game.h"

#include <QDebug>

GameObject::GameObject(ObjectType t, QPixmap pixmap) : QGraphicsPixmapItem(pixmap)
{
    type = t;
}

GameObject::~GameObject()
{

}

GameObject::ObjectType GameObject::get_Type()
{
    return type;
}

int GameObject::getPosX() const
{
    return posX;
}

int GameObject::getPosY() const
{
    return posY;
}

int GameObject::get_Bottle_Score()
{
    return Bottle_Score;
}

void GameObject::set_Bottle_Score(int bs)
{
    Bottle_Score = bs;
}

GameObject::Direction GameObject::get_direction()
{
    return direction;
}

GameObject::Direction GameObject::get_next_direction()
{
    return next_direction;
}

void GameObject::set_direction(Direction dir)
{
    direction = dir;
}

void GameObject::set_next_direction(Direction dir)
{
    //qDebug() << "Morty Next directio: " << dir;
    next_direction = dir;
}
