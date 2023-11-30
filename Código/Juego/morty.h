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

    ///Get Methods
    /*int getHealth() const;
    int getStrength() const;
    int getResistance() const;*/

    ///Set Methods
    /*void setHealth(int _Health);
    void setStrenght(int _Strength);
    void setResistance(int _Resistance);*/

private:
    /*int Health;
    int Strength;
    int Resistance;*/

    void Move_up();
    void Move_down();
    void Move_left();
    void Move_right();

    /*void Take_Damage(int);
    void Get_object(int, int);*/

    QVector<QPixmap> animation[4];
    int Anim_Frame;

};

#endif // MORTY_H
