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
    enum ObjectType {Morty, Wall, Floor, Roof, Grass, Bath, Room, Carpet, Office, Blank/*, Enemy, Heart, Shield, Sword*/};
    enum Direction {Up = 0, Down = 1, Left = 2, Right = 3};
    static const int width = 50;        //Tamaño objetos en el juego

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

protected:
    int posX;
    int posY;
    Direction direction;
    Direction next_direction;
    ObjectType type;
};

#endif // GAMEOBJECT_H
