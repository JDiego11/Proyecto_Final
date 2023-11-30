#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include "gameobject.h"
#include "morty.h"

#define ENEMY_RELEASE       2500         //Tiempo en que sale cada enemigo
#define ITEM_SPAWN          7500         //Tiempo en que aparecen los items

class Game : public QGraphicsScene
{
public:
    Game(int, int, int, int, QString);
    ~Game();

    void Morty_Next_Move(GameObject::Direction);

    GameObject ***map;
    Morty *morty;

    friend class Morty;

private:
    int map_height;
    int map_width;
    int map_size;
    int mapX;
    int mapY;
};

#endif // GAME_H
