#ifndef MORTY_H
#define MORTY_H

/*
#include <QGraphicsPixmapItem>
#include <QGraphicsObject>
#include <QGraphicsView>
#include <QGraphicsItem>*/
#include <QVector>

#include "gameobject.h"

class Morty : public GameObject
{

public:
    Morty();        //Constructor
    void move();
    Game *game;

    friend class Game;

private:
    void Move_up();
    void Move_down();
    void Move_left();
    void Move_right();
    bool Collision(int, int);
    void Collect_Bottle(int, int);

    QVector<QPixmap> animation[4];
    int Anim_Frame;

};

#endif // MORTY_H
