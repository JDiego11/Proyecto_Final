#include "game.h"
#include <QFile>

#include <QDebug>

#define W (GameObject::width)

int ENEMY_RELEASE_TIME[] = {0, 200/*, 400, 600, 800, 1000*/};

Game::Game(int x, int y, int m_Width, int m_Height, QString map_File)
    : QGraphicsScene(x, y, W * m_Width, W * m_Height)
{
    mapX = x;
    mapY = y;
    status = Playing;

    //Punteros para el mapa
    map_size = m_Width * m_Height;
    map_width = m_Width;
    map_height = m_Height;

    map = new GameObject**[m_Height];
    for (int i=0; i < m_Height; i++) {
        map[i] = new GameObject*[m_Width];
        for (int j=0; j < m_Width; j++) {
            map[i][j] = nullptr;
        }
    }

    Bottle_Num = collected_bottles = 0;
    int Enemy_i = 0;
    //int cont_Enemy = 0;
    //Carga de Gráficos
    QPixmap WallPix(":/Resources/Map_Object/Wall.png");
    QPixmap PortalPix(":/Resources/Map_Object/Portal.png");
    QPixmap BottlePix(":/Resources/Enemy&Objects/Bottle_1.png");
    QPixmap BlankPix;

    QFile mapfile(map_File);
    mapfile.open(QIODevice::ReadOnly|QIODevice::Text);

    morty = new Morty();

    for (int i=0; i < m_Height; i++) {
        QByteArray line = mapfile.readLine();
        for (int j=0; j < m_Width; j++) {
            int aux_x = x + (j * W);
            int aux_y = y + (i * W);
            switch (line[j]) {
            case 'W':
                map[i][j] = new GameObject(GameObject::Wall, WallPix);
                map[i][j]->setPos(aux_x, aux_y);
                addItem(map[i][j]);
                break;
            case 'B':
                map[i][j] = new GameObject(GameObject::Bottle, BottlePix);
                map[i][j]->set_Bottle_Score(BOTTLE_SCORE);
                map[i][j]->setPos(aux_x, aux_y);
                addItem(map[i][j]);
                Bottle_Num++;
                break;
            case 'E':
                /*if (cont_Enemy == 0 || cont_Enemy == 5) {
                    Enemy_i = 1;
                } else {
                    Enemy_i = 0;
                }*/
                map[i][j] = new GameObject(GameObject::Blank, BlankPix);
                enemy[Enemy_i] = new Enemy(Enemy_i);
                enemy[Enemy_i]->game = this;
                enemy[Enemy_i]->setZValue(2);
                enemy[Enemy_i]->Release_Time = ENEMY_RELEASE_TIME[Enemy_i];
                enemy[Enemy_i]->posX = j;
                enemy[Enemy_i]->posY = i;
                enemy[Enemy_i]->setPos(aux_x, aux_y);
                addItem(enemy[Enemy_i]);
                //cont_Enemy++;
                Enemy_i++;
                break;
            case 'M':
                morty = new Morty;
                morty->game = this;
                morty->setZValue(2);
                morty->setPos(aux_x, aux_y);
                addItem(morty);
                map[i][j] = morty;
                break;
            case 'P':
                portal = new GameObject(GameObject::Portal, PortalPix);
                portal->posX = j;
                portal->posY = i;
                portal->setPos(aux_x, aux_y);
                addItem(portal);
                map[i][j] = portal;
                break;
            case '-':
                map[i][j] = new GameObject(GameObject::Blank, BlankPix);
                break;
            }
            if (map[i][j]) {
                map[i][j]->posX = j;
                map[i][j]->posY = i;
            }
        }
    }

    enemy[Enemy::Normal1]->Chase = &Chase2;
    enemy[Enemy::Big1]->Chase = &Chase1;
}

void Game::start()
{
    Morty_timer = new QTimer(this);
    connect(Morty_timer, SIGNAL(timeout()), this , SLOT(Morty_Movement()));
    Morty_timer->start(MORTY_SPEED);

    /*for (int i = 0; i < Enemy::EnemyNum; i++) {
        Enemy_Timer[i] = new QTimer(this);
        connect(Enemy_Timer[i], &QTimer::timeout, [=](){Enemy_Movement(i);});
        Enemy_Timer[i]->start(ENEMY_SPEED);
    }*/
}

void Game::stop()
{
    Morty_timer->stop();
    for (int i = 0; i < Enemy::EnemyNum; i++) {
        Enemy_Timer[i]->stop();
    }
}

void Game::Morty_Movement()
{
    morty->move();
    if (status == Win) {
        stop();
    }
}

void Game::Enemy_Movement(int enemy_id)
{
    enemy[enemy_id]->move();
    if (status == Lose) {
        stop();
    }
}

void Game::Morty_Next_Move(GameObject::Direction d)
{
    //qDebug() << "Morty Next Move: " << d;
    morty -> set_next_direction(d);
}

int Game::get_score()
{
    return score;
}

Game::~Game() {
    for (int i=0; i < map_height; i++) {
        for (int j=0; j < map_width; j++) {
            if (map[i][j] != nullptr) {
                delete map[i][j];
            }
        }
        delete[] map[i];
    }
    delete[] map;

    delete Morty_timer;
    for (int i=0; i < Enemy::EnemyNum; i++) {
        delete Enemy_Timer[i];
    }
}
