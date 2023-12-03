#include "enemy.h"
#include "game.h"

#include <QRandomGenerator>

#define W (GameObject::Width)

Enemy::Enemy() : GameObject(GameObject::Enemy, QPixmap())
{
    Animation_Frame = 0;
    is_released = false;
    direction = Direction(QRandomGenerator::global()->generate() % 4);

    animation[Up].push_back(QPixmap(":/Resources/Enemy&Objects/Enemy_RightUp_1.png"));
    animation[Up].push_back(QPixmap(":/Resources/Enemy&Objects/Enemy_RightUp_2.png"));
    animation[Up].push_back(QPixmap(":/Resources/Enemy&Objects/Enemy_RightUp_3.png"));
    animation[Up].push_back(QPixmap(":/Resources/Enemy&Objects/Enemy_RightUp_4.png"));
    animation[Down].push_back(QPixmap(":/Resources/Enemy&Objects/Enemy_LeftDown_1.png"));
    animation[Down].push_back(QPixmap(":/Resources/Enemy&Objects/Enemy_LeftDown_2.png"));
    animation[Down].push_back(QPixmap(":/Resources/Enemy&Objects/Enemy_LeftDown_3.png"));
    animation[Down].push_back(QPixmap(":/Resources/Enemy&Objects/Enemy_LeftDown_4.png"));
    animation[Left].push_back(QPixmap(":/Resources/Enemy&Objects/Enemy_LeftDown_1.png"));
    animation[Left].push_back(QPixmap(":/Resources/Enemy&Objects/Enemy_LeftDown_2.png"));
    animation[Left].push_back(QPixmap(":/Resources/Enemy&Objects/Enemy_LeftDown_3.png"));
    animation[Left].push_back(QPixmap(":/Resources/Enemy&Objects/Enemy_LeftDown_4.png"));
    animation[Right].push_back(QPixmap(":/Resources/Enemy&Objects/Enemy_RightUp_1.png"));
    animation[Right].push_back(QPixmap(":/Resources/Enemy&Objects/Enemy_RightUp_2.png"));
    animation[Right].push_back(QPixmap(":/Resources/Enemy&Objects/Enemy_RightUp_3.png"));
    animation[Right].push_back(QPixmap(":/Resources/Enemy&Objects/Enemy_RightUp_4.png"));
}
