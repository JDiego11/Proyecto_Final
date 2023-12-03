#include "game.h"
#include <QFile>

#include <QDebug>

#define W (GameObject::width)

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

    //Carga de Gráficos
    QPixmap WallPix(":/Resources/Map_Object/Wall.png");
    /*QPixmap FloorPix(":/Resources/Map_Object/Blank_Floor_0.png");
    QPixmap CarpetPix(":/Resources/Map_Object/Blank_Carpet_1.png");
    QPixmap GrassPix(":/Resources/Map_Object/Blank_Grass_2.png");
    QPixmap RoofPix(":/Resources/Map_Object/Blank_Roof_3.png");
    QPixmap BathPix(":/Resources/Map_Object/Blank_Bath_4.png");
    QPixmap OfficePix(":/Resources/Map_Object/Blank_Office_5.png");
    QPixmap RoomPix(":/Resources/Map_Object/Blank_Room_6.png");*/
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
            /*case '0':
                map[i][j] = new GameObject(GameObject::Floor, FloorPix);
                map[i][j]->setPos(aux_x, aux_y);
                addItem(map[i][j]);
                break;
            case '1':
                map[i][j] = new GameObject(GameObject::Carpet, CarpetPix);
                map[i][j]->setPos(aux_x, aux_y);
                addItem(map[i][j]);
                break;
            case '2':
                map[i][j] = new GameObject(GameObject::Grass, GrassPix);
                map[i][j]->setPos(aux_x, aux_y);
                addItem(map[i][j]);
                break;
            case '3':
                map[i][j] = new GameObject(GameObject::Roof, RoofPix);
                map[i][j]->setPos(aux_x, aux_y);
                addItem(map[i][j]);
                break;
            case '4':
                map[i][j] = new GameObject(GameObject::Bath, BathPix);
                map[i][j]->setPos(aux_x, aux_y);
                addItem(map[i][j]);
                break;
            case '5':
                map[i][j] = new GameObject(GameObject::Office, OfficePix);
                map[i][j]->setPos(aux_x, aux_y);
                addItem(map[i][j]);
                break;
            case '6':
                map[i][j] = new GameObject(GameObject::Room, RoomPix);
                map[i][j]->setPos(aux_x, aux_y);
                addItem(map[i][j]);
                break;*/
            case 'M':
                morty = new Morty;
                morty->game = this;
                morty->setZValue(2);
                morty->setPos(aux_x, aux_y);
                addItem(morty);
                map[i][j] = morty;
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
}

void Game::start()
{
    qDebug() << "Game start";
    Morty_timer = new QTimer(this);
    connect(Morty_timer, SIGNAL(timeout()), this , SLOT(Morty_Movement()));
    Morty_timer->start(MORTY_SPEED);
}

void Game::stop()
{
    Morty_timer->stop();
}

void Game::Morty_Movement()
{
    qDebug() << "Morty_Movement called";
    morty->move();
    if (status == Win) {
        stop();
    }
}

void Game::Morty_Next_Move(GameObject::Direction d)
{
    //qDebug() << "Morty Next Move: " << d;
    morty -> set_next_direction(d);
}

Game::~Game() {
    for (int i=0; i < map_height; i++) {
        for (int j=0; j < map_width; j++) {
            if (map[i][j] != nullptr) delete map[i][j];
        }
        delete[] map[i];
    }
    delete[] map;

    delete Morty_timer;
}
