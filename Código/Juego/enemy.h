#ifndef ENEMY_H
#define ENEMY_H

#include <QVector>

#include "gameobject.h"

class Enemy : public GameObject
{
public:
    enum EnemyType {Big1 = 0, Normal1 = 1/*, Normal2 = 2, Normal3 = 3, Normal4 = 4, Big2 = 5*/};
    const static int EnemyNum = 2;
    Game *game;

    Enemy(int);
    void move();
    EnemyType get_EnemyType();

    friend class Game;
    friend class Morty;

private:
    void Move_Up();
    void Move_Down();
    void Move_Left();
    void Move_Right();

    void Random_Direction();
    void Leave_Portal();
    void Look4Morty();
    QPair<int, int> (*Chase)(Enemy*);
    bool Collision(int, int);

    EnemyType enemyType;
    QVector<QPixmap> animation[4];
    int Animation_Frame;
    int Release_Time;
    bool is_released;
};

QPair<int, int> Chase1(Enemy*);
QPair<int, int> Chase2(Enemy*);

#endif // ENEMY_H
