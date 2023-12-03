#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QTimer>

#include "gameobject.h"
#include "morty.h"

#define ENEMY_RELEASE       2500         //Tiempo en que sale cada enemigo
#define ITEM_SPAWN          7500         //Tiempo en que aparecen los items
#define MORTY_SPEED         10          //Velocidad de Morty

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

    GameObject ***map;
    GameObject *portal;
    Morty *morty;
    Status status;

    friend class Morty;

private slots:
    void Morty_Movement();

private:
    int map_height, map_width;
    int map_size;
    int mapX, mapY;
    QTimer *Morty_timer;
};

#endif // GAME_H
