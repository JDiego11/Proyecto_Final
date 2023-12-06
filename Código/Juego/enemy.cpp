#include "enemy.h"
#include "game.h"
//#include "Chase_Morty.cpp"

#include <QRandomGenerator>

#define W (GameObject::width)

Enemy::Enemy(int et) : GameObject(
    GameObject::Enemy, QPixmap())
{
    enemyType = (EnemyType)et;
    Animation_Frame = 0;
    is_released = false;
    direction = Direction(QRandomGenerator::global()->generate() % 4);

    switch (enemyType) {
    case Big1:
        animation[Up].push_back(QPixmap(":/Resources/Enemy&Objects/BigEnemy_UL_1.png"));
        animation[Up].push_back(QPixmap(":/Resources/Enemy&Objects/BigEnemy_UL_2.png"));
        animation[Up].push_back(QPixmap(":/Resources/Enemy&Objects/BigEnemy_UL_3.png"));
        animation[Up].push_back(QPixmap(":/Resources/Enemy&Objects/BigEnemy_UL_4.png"));
        animation[Down].push_back(QPixmap(":/Resources/Enemy&Objects/BigEnemy_RD_1.png"));
        animation[Down].push_back(QPixmap(":/Resources/Enemy&Objects/BigEnemy_RD_2.png"));
        animation[Down].push_back(QPixmap(":/Resources/Enemy&Objects/BigEnemy_RD_3.png"));
        animation[Down].push_back(QPixmap(":/Resources/Enemy&Objects/BigEnemy_RD_4.png"));
        animation[Left].push_back(QPixmap(":/Resources/Enemy&Objects/BigEnemy_UL_1.png"));
        animation[Left].push_back(QPixmap(":/Resources/Enemy&Objects/BigEnemy_UL_2.png"));
        animation[Left].push_back(QPixmap(":/Resources/Enemy&Objects/BigEnemy_UL_3.png"));
        animation[Left].push_back(QPixmap(":/Resources/Enemy&Objects/BigEnemy_UL_4.png"));
        animation[Right].push_back(QPixmap(":/Resources/Enemy&Objects/BigEnemy_RD_1.png"));
        animation[Right].push_back(QPixmap(":/Resources/Enemy&Objects/BigEnemy_RD_2.png"));
        animation[Right].push_back(QPixmap(":/Resources/Enemy&Objects/BigEnemy_RD_3.png"));
        animation[Right].push_back(QPixmap(":/Resources/Enemy&Objects/BigEnemy_RD_4.png"));
        break;
    case Normal1:
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
        break;
    case Normal2:
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
        break;
    case Normal3:
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
        break;
    case Normal4:
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
        break;
    case Big2:
        animation[Up].push_back(QPixmap(":/Resources/Enemy&Objects/BigEnemy_UL_1.png"));
        animation[Up].push_back(QPixmap(":/Resources/Enemy&Objects/BigEnemy_UL_2.png"));
        animation[Up].push_back(QPixmap(":/Resources/Enemy&Objects/BigEnemy_UL_3.png"));
        animation[Up].push_back(QPixmap(":/Resources/Enemy&Objects/BigEnemy_UL_4.png"));
        animation[Down].push_back(QPixmap(":/Resources/Enemy&Objects/BigEnemy_RD_1.png"));
        animation[Down].push_back(QPixmap(":/Resources/Enemy&Objects/BigEnemy_RD_2.png"));
        animation[Down].push_back(QPixmap(":/Resources/Enemy&Objects/BigEnemy_RD_3.png"));
        animation[Down].push_back(QPixmap(":/Resources/Enemy&Objects/BigEnemy_RD_4.png"));
        animation[Left].push_back(QPixmap(":/Resources/Enemy&Objects/BigEnemy_UL_1.png"));
        animation[Left].push_back(QPixmap(":/Resources/Enemy&Objects/BigEnemy_UL_2.png"));
        animation[Left].push_back(QPixmap(":/Resources/Enemy&Objects/BigEnemy_UL_3.png"));
        animation[Left].push_back(QPixmap(":/Resources/Enemy&Objects/BigEnemy_UL_4.png"));
        animation[Right].push_back(QPixmap(":/Resources/Enemy&Objects/BigEnemy_RD_1.png"));
        animation[Right].push_back(QPixmap(":/Resources/Enemy&Objects/BigEnemy_RD_2.png"));
        animation[Right].push_back(QPixmap(":/Resources/Enemy&Objects/BigEnemy_RD_3.png"));
        animation[Right].push_back(QPixmap(":/Resources/Enemy&Objects/BigEnemy_RD_4.png"));
        break;
    }

    setPixmap(animation[Right][0]);
}

Enemy::EnemyType Enemy::get_EnemyType()
{
    return enemyType;
}

void Enemy::Move_Up()
{
    QVector<QPixmap> *ptr;
    ptr = &animation[Up];
    Animation_Frame++;
    if (Animation_Frame >= ptr->size()) {
        Animation_Frame = 0;
    }
    setPixmap((*ptr)[Animation_Frame]);
    //setY(static_cast<int>(y()) - 1);
    setPos(x(), y() - 1);
}

void Enemy::Move_Down()
{
    QVector<QPixmap> *ptr;
    ptr = &animation[Down];
    Animation_Frame++;
    if (Animation_Frame >= ptr->size()) {
        Animation_Frame = 0;
    }
    setPixmap((*ptr)[Animation_Frame]);
    //setY(static_cast<int>(y()) + 1);
    setPos(x(), y() +1);
}

void Enemy::Move_Left()
{
    QVector<QPixmap> *ptr;
    ptr = &animation[Left];
    Animation_Frame++;
    if (Animation_Frame >= ptr->size()) {
        Animation_Frame = 0;
    }
    setPixmap((*ptr)[Animation_Frame]);
    //setY(static_cast<int>(x()) - 1);
    setPos(x() - 1, y());
}

void Enemy::Move_Right()
{
    QVector<QPixmap> *ptr;
    ptr = &animation[Right];
    Animation_Frame++;
    if (Animation_Frame >= ptr->size()) {
        Animation_Frame = 0;
    }
    setPixmap((*ptr)[Animation_Frame]);
    //setY(static_cast<int>(x()) + 1);
    setPos(x() + 1, y());
}

void Enemy::Random_Direction()
{
    QVector<Direction> List;
    if (Collision(posY, posX + 1)) {
        List.push_back(Right);
    }
    if (Collision(posY, posX - 1)) {
        List.push_back(Left);
    }
    if (Collision(posY + 1, posX)) {
        List.push_back(Down);
    }
    if (Collision(posY - 1, posX)) {
        List.push_back(Up);
    }
    direction = List.at(QRandomGenerator::global()->generate() % List.size());
}

void Enemy::Leave_Portal()
{
    int x_dist_to_portal = game->portal->posX - posX;
    int y_dist_to_portal = game->portal->posY - posY;
    if (x_dist_to_portal > 0) {
        set_direction(GameObject::Right);
    } else if (x_dist_to_portal < 0) {
        set_direction(GameObject::Left);
    } else {
        if (y_dist_to_portal > 0) {
            set_direction(GameObject::Down);
        } else {
            set_direction(GameObject::Up);
        }
    }
}

void Enemy::Look4Morty()
{
    bool can_move[5] = {false, false, false, false, false};
    QVector<Direction> List;
    if (Collision(posY, posX + 1)) {
        can_move[Right] = true;
        List.push_back(Right);
    }
    if (Collision(posY, posX - 1)) {
        can_move[Left] = true;
        List.push_back(Left);
    }
    if (Collision(posY + 1, posX)) {
        can_move[Down] = true;
        List.push_back(Down);
    }
    if (Collision(posY - 1, posX)) {
        can_move[Up] = true;
        List.push_back(Up);
    }

    Direction Back_Direction;
    switch (direction) {
    case Up:
        Back_Direction = Down;
        break;
    case Down:
        Back_Direction = Up;
        break;
    case Left:
        Back_Direction = Right;
        break;
    case Right:
        Back_Direction = Left;
        break;
    case Stop:
        Back_Direction = Stop;
        break;
    }

    if (List.size() > 2) {
        QPair<int, int> vector = Chase(this);
        int dist_x = vector.first;
        int dist_y = vector.second;
        if (dist_y > 0) {
            if (can_move[Down] && direction != Up) {
                direction = Down;
            } else {
                if (dist_x >= 0) {
                    if (can_move[Right]) {
                        direction = Right;
                    } else if (can_move[Left]) {
                        direction = Left;
                    }
                } else {
                    if (can_move[Left]) {
                        direction = Left;
                    } else if (can_move[Right]) {
                        direction = Right;
                    }
                }
            }
        } else if (dist_y < 0) {
            if (can_move[Up] && direction != Down) {
                direction = Up;
            } else {
                if (dist_x >= 0) {
                    if (can_move[Right]) {
                        direction = Right;
                    } else if (can_move[Left]) {
                        direction = Left;
                    }
                } else {
                    if (can_move[Left]) {
                        direction = Left;
                    } else if (can_move[Right]) {
                        direction = Right;
                    }
                }
            }
        } else if (dist_x > 0) {
            if (can_move[Right] && direction != Left) {
                direction = Right;
            } else {
                if (can_move[Up]) {
                    direction = Up;
                } else if(can_move[Down]) {
                    direction = Down;
                }
            }
        } else if (dist_x < 0) {
            if (can_move[Left] && direction != Right) {
                direction = Left;
            } else {
                if (can_move[Up]) {
                    direction = Up;
                } else if(can_move[Down]) {
                    direction = Down;
                }
            }
        }
    } else if (List.size() == 2) {
        if (can_move[direction] == false) {
            //Enemigo en la esquina
            if (List[0] == Back_Direction) {
                direction = List[1];
            } else {
                direction = List[2];
            }
        }
    }
}

bool Enemy::Collision(int i, int j)
{
    if (i < 0 || j < 0) {
        return false;
    }
    if (i >= game->map_height || j >= game->map_width) {
        return false;
    }
    switch (game->map[i][j]->get_Type()) {
    case Wall:
        return false;
    case Portal:
        if (is_released == false && Release_Time == 0) {
            return true;
        } else {
            return false;
        }
    default:
        return true;
    }
}

void Enemy::move()
{
    if (Release_Time > 0) {
        Release_Time--;
        game->Enemy_Timer[enemyType]->setInterval(ENEMY_SPEED);
    }

    int Ene_x = static_cast<int>(x());
    int Ene_y = static_cast<int>(y());
    int _x = (Ene_x - game->mapX) / W;
    int _y = (Ene_y - game->mapY) / W;
    int x_aux = (Ene_x - game->mapX) % W;
    int y_aux = (Ene_y - game->mapY) % W;

    if (x_aux == 0 && y_aux == 0) {
        posX = _x;
        posY = _y;
        if (is_released) {
            Look4Morty();
        } else {
            if (Release_Time == 0) {
                Leave_Portal();
                if (game->map[posY][posX]->get_Type() == Portal) {
                    is_released = true;
                }
            } else {
                Random_Direction();
            }
        }
    }

    switch (direction) {
    case Stop:
        break;
    case Up:
        Move_Up();
        break;
    case Down:
        Move_Down();
        break;
    case Left:
        Move_Left();
        break;
    case Right:
        Move_Right();
        break;
    }

    //Cuando se choca con Morty
    if (collidesWithItem(game->morty, Qt::IntersectsItemShape)) {
        game->status = Game::Lose;
    }
}
