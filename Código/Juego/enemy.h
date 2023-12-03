#ifndef ENEMY_H
#define ENEMY_H

#include <QVector>

#include "gameobject.h"

class Enemy : public GameObject
{
public:
    const static int EnemyNum = 6;
    Game *game;

    Enemy();
    void move();

    friend class Game;
    friend class Morty;

private:
    void Move_Up();
    void Move_Down();
    void Move_Left();
    void Move_Right();

    void Random_Direction();
    void Leave_Portal();
    bool Collision();

    QVector<QPixmap> animation[4];
    int Animation_Frame;
    int Release_Time;
    bool is_released;
};

#endif // ENEMY_H
