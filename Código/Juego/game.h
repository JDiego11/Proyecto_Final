#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QTimer>
#include <QPair>

#include "gameobject.h"
#include "morty.h"
#include "enemy.h"

#define BOTTLE_SCORE        10          //Puntuación por botella
#define ENEMY_RELEASE       2500        //Tiempo en que sale cada enemigo
#define ITEM_SPAWN          7500        //Tiempo en que aparecen los items
#define MORTY_SPEED         10          //Velocidad de Morty
#define ENEMY_SPEED         10          //Velocidad de los enemigos

class Game : public QGraphicsScene//, public QObject
{
    Q_OBJECT

public:
    enum Status {Playing, Win, Lose};
    Game(int, int, int, int, QString);
    ~Game();
    void start();
    void stop();
    void Morty_Next_Move(GameObject::Direction);
    int get_score();

    GameObject ***map;
    GameObject *portal;
    Morty *morty;
    Enemy *enemy[Enemy::EnemyNum];
    Status status;

    friend class Morty;
    friend class Enemy;

private slots:
    void Morty_Movement();
    void Enemy_Movement(int);

private:
    int map_height, map_width;
    int map_size;
    int Bottle_Num, collected_bottles, score;
    int mapX, mapY;

    QTimer *Enemy_Timer[Enemy::EnemyNum];
    QTimer *Morty_timer;
};

#endif // GAME_H
