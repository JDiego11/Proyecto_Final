#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle(tr("Morty y los invasores"));

    QColor Background_Color(207, 187, 137);
    //QBrush Background_brush(Background_Color);

    ui->graphicsView->setStyleSheet("QGraphicsView {border: none;}");
    ui->graphicsView->setBackgroundBrush(Background_Color);
    ui->graphicsView->setFocusPolicy(Qt::NoFocus);
    //qDebug() << "Focus Policy: " << ui->graphicsView->focusPolicy();

    int map_height = 20, map_width = 30;
    int x = 10, y = 10;
    int w = (map_width * GameObject::width);
    int h = (map_height * GameObject::width);

    ui->graphicsView->setGeometry(x, y, w, h);
    game = new Game(x, y, map_width, map_height, ":/Resources/Map_Object/Mapa_0.txt");
    ui->graphicsView->setScene(game);
    game->start();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *k) {
    //qDebug() << "Key Pressed: " << k->key();
    switch (k->key()) {
    case Qt::Key_W:
        game->Morty_Next_Move(GameObject::Up);
        break;
    case Qt::Key_A:
        game->Morty_Next_Move(GameObject::Left);
        break;
    case Qt::Key_S:
        game->Morty_Next_Move(GameObject::Down);
        break;
    case Qt::Key_D:
        game->Morty_Next_Move(GameObject::Right);
        break;
    }
}

