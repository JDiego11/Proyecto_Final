#include "morty.h"

Morty::Morty() : GameObject(GameObject::Morty, QPixmap(":/Resources/Morty_Sprites/Morty_Down_1.png"))
{
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
