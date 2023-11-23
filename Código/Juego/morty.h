#ifndef MORTY_H
#define MORTY_H

#include <QGraphicsPixmapItem>
#include <QGraphicsObject>
#include <QGraphicsView>
#include <QGraphicsItem>

class Morty : public QGraphicsItem
{
private:
    int posX;
    int poxY;
    int Health;
    int Strength;
    int Resistance;

    void Move_up();
    void Move_down();
    void Move_left();
    void Move_right();

    void Take_Damage(int);
    void Get_object(int, int);
public:
    enum ObjectType {Heart, Shield, Sword};

    Morty();

    //Get Methods
    int getPosX() const;
    int getPosY() const;
    int getHealth() const;
    int getStrength() const;
    int getResistance() const;

    //Set Methods
    void setPosX(int _X);
    void setPosY(int _Y);
    void setHealth(int _Health);
    void setStrenght(int _Strength);
    void setResistance(int _Resistance);
};

#endif // MORTY_H
