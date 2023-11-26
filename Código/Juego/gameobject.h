#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <QGraphicsPixmapItem>
#include <QGraphicsObject>
#include <QGraphicsView>
#include <QGraphicsItem>
#include <QString>

//#include <QObject>

class Game;

class GameObject : public QGraphicsPixmapItem
{
public:
    enum ObjectType {Morty, Enemy, Heart, Shield, Sword};
    enum Direction {Up = 0, Down = 1, Left = 2, Right = 3, Stop = 4};
    static const int widht = 50;        //Tamaño objetos en el juego

    GameObject(ObjectType, QPixmap);
    ~GameObject();

    ObjectType get_Type();
    int getPosX() const;
    int getPosY() const;
    Direction get_direction();
    Direction get_next_direction();

    //void setPosX(int _X);
    //void setPosY(int _Y);
    void set_direction(Direction);
    void set_next_direction(Direction);

    friend class Game;

private:
    int posX;
    int posY;
    Direction direction;
    Direction next_direction;
    ObjectType type;
};

#endif // GAMEOBJECT_H
