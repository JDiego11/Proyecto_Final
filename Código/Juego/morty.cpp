#include "morty.h"
#include "game.h"

#include <QDebug>

#define W (GameObject::width)

Morty::Morty() : GameObject(GameObject::Morty, QPixmap(":/Resources/Morty_Sprites/Morty_Down_1.png"))
{
    direction = Stop;
    next_direction = Stop;
    Anim_Frame = 0;
    ///Animación -> caminar arriba
    animation[Up].push_back(QPixmap(":/Resources/Morty_Sprites/Morty_Up_1.png"));
    animation[Up].push_back(QPixmap(":/Resources/Morty_Sprites/Morty_Up_2.png"));
    animation[Up].push_back(QPixmap(":/Resources/Morty_Sprites/Morty_Up_3.png"));
    animation[Up].push_back(QPixmap(":/Resources/Morty_Sprites/Morty_Up_4.png"));
    ///Animación -> caminar derecha
    animation[Right].push_back(QPixmap(":/Resources/Morty_Sprites/Morty_Right_1.png"));
    animation[Right].push_back(QPixmap(":/Resources/Morty_Sprites/Morty_Right_2.png"));
    animation[Right].push_back(QPixmap(":/Resources/Morty_Sprites/Morty_Right_3.png"));
    animation[Right].push_back(QPixmap(":/Resources/Morty_Sprites/Morty_Right_4.png"));
    ///Animación -> caminar abajo
    animation[Down].push_back(QPixmap(":/Resources/Morty_Sprites/Morty_Down_1.png"));
    animation[Down].push_back(QPixmap(":/Resources/Morty_Sprites/Morty_Down_2.png"));
    animation[Down].push_back(QPixmap(":/Resources/Morty_Sprites/Morty_Down_3.png"));
    animation[Down].push_back(QPixmap(":/Resources/Morty_Sprites/Morty_Down_4.png"));
    ///Animación -> caminar izquierda
    animation[Left].push_back(QPixmap(":/Resources/Morty_Sprites/Morty_Left_1.png"));
    animation[Left].push_back(QPixmap(":/Resources/Morty_Sprites/Morty_Left_2.png"));
    animation[Left].push_back(QPixmap(":/Resources/Morty_Sprites/Morty_Left_3.png"));
    animation[Left].push_back(QPixmap(":/Resources/Morty_Sprites/Morty_Left_4.png"));
}

void Morty::Move_up()
{
    Anim_Frame++;
    if(Anim_Frame == animation[Up].size()) {
        Anim_Frame = 0;
    }
    setPixmap(animation[Up][Anim_Frame]);   //Frame de la animación
    setY(static_cast<int>(y())-1);          //Mover objeto
}

void Morty::Move_down()
{
    Anim_Frame++;
    if(Anim_Frame == animation[Down].size()) {
        Anim_Frame = 0;
    }
    setPixmap(animation[Down][Anim_Frame]);   //Frame de la animación
    setY(static_cast<int>(y())+1);          //Mover objeto
}

void Morty::Move_left()
{
    Anim_Frame++;
    if(Anim_Frame == animation[Left].size()) {
        Anim_Frame = 0;
    }
    setPixmap(animation[Left][Anim_Frame]);   //Frame de la animación
    setY(static_cast<int>(x())-1);          //Mover objeto
}

void Morty::Move_right()
{
    Anim_Frame++;
    if(Anim_Frame == animation[Right].size()) {
        Anim_Frame = 0;
    }
    setPixmap(animation[Right][Anim_Frame]);   //Frame de la animación
    setY(static_cast<int>(x())+1);          //Mover objeto
}

bool Morty::Collision(int i, int j)
{
    if (i < 0 || j > 0) {
        return false;
    }
    if (i >= game->map_height || j >= game->map_width) {
        return false;
    }
    switch (game->map[i][j]->get_Type()) {
    case Wall:
    default:
        return true;
    }
}

void Morty::move()
{
    //qDebug() << "Morty Move";
    int Morty_x = static_cast<int>(x());
    int Morty_y = static_cast<int>(y());
    int _x = (Morty_x - game->mapX) / W;
    int _y = (Morty_y - game->mapY) / W;
    int x_aux = (Morty_x - game->mapX) % W;
    int y_aux = (Morty_y - game->mapY) % W;
    Direction next_direction = get_next_direction();

    if (x_aux == 0) {
        if (y_aux) {
            posX = _x;
            posY = _y;
        }

        switch (next_direction) {
        case Stop:
            direction = next_direction;
            break;
        case Up:
            if (Collision(posY - 1, posX)) {
                direction = next_direction;
            }
            break;
        case Down:
            if (Collision(posY + 1, posX)) {
                direction = next_direction;
            }
            break;
        case Left:
            if (y_aux && Collision(posY, posX - 1)) {
                direction = next_direction;
            }
            break;
        case Right:
            if (y_aux && Collision(posY, posX + 1)) {
                direction = next_direction;
            }
            break;
        }
    }
    else if (y_aux) {
        switch (next_direction) {
        case Stop:
            direction = next_direction;
            break;
        case Left:
            if (Collision(posY, posX - 1)) {
                direction = next_direction;
            }
            break;
        case Right:
            if (Collision(posY, posX + 1)) {
                direction = next_direction;
            }
            break;
        default:
            break;
        }
    }

    switch (direction) {
    case Stop:
        break;
    case Up:
        if (y_aux == 0 && !Collision(posY - 1, posX)) {
            direction = Stop;
            next_direction = Stop;
        } else {
            Move_up();
        }
        break;
    case Down:
        if (y_aux == 0 && !Collision(posY + 1, posX)) {
            direction = Stop;
            next_direction = Stop;
        } else {
            Move_down();
        }
        break;
    case Left:
        if (y_aux == 0 && !Collision(posY, posX - 1)) {
            direction = Stop;
            next_direction = Stop;
        } else {
            Move_left();
        }
        break;
    case Right:
        if (y_aux == 0 && !Collision(posY, posX + 1)) {
            direction = Stop;
            next_direction = Stop;
        } else {
            Move_right();
        }
        break;
    }
}
/*
void Morty::Take_Damage(int damage)
{
    int NewHealth;
    NewHealth = Health - (damage - (damage * Resistance / 100));

    setHealth(NewHealth);
}

void Morty::Get_object(int, int)
{

}

int Morty::getHealth() const
{
    return Health;
}

int Morty::getStrength() const
{
    return Strength;
}

int Morty::getResistance() const
{
    return Resistance;
}

void Morty::setHealth(int _Health)
{
    Health = _Health;
}

void Morty::setStrenght(int _Strength)
{
    Strength = _Strength;
}

void Morty::setResistance(int _Resistance)
{
    Resistance = _Resistance;
}
*/
