#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QTimer>
#include <QVector>

//#include <QObject>

class Game;

class GameObject : public QGraphicsPixmapItem
{
public:
    enum ObjectType {Morty, Wall, Blank, Portal, Enemy, Bottle};
    enum Direction {Up = 0, Down = 1, Left = 2, Right = 3, Stop = 4};
    static const int width = 50;        //Tamaño objetos en el juego

    GameObject(ObjectType, QPixmap);
    ~GameObject();

    ObjectType get_Type();
    int getPosX() const;
    int getPosY() const;

    int get_Bottle_Score();
    void set_Bottle_Score(int);

    Direction get_direction();
    Direction get_next_direction();

    void set_direction(Direction);
    void set_next_direction(Direction);

    friend class Game;
    friend class Enemy;

protected:
    int posX;
    int posY;
    Direction direction;
    Direction next_direction;
    ObjectType type;
    int Bottle_Score;
};

#endif // GAMEOBJECT_H
