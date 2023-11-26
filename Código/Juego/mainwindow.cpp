#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    Morty = new GameObject(GameObject::Morty, QPixmap(":/Resources/Morty_Sprites/Morty_Down_1.png"));
    Morty -> setPos((ui->graphicsView->width()/2)-50, (ui->graphicsView->height()/2)-50);
    Scene = new QGraphicsScene;

    Scene -> setSceneRect(0,0,ui->graphicsView->width()-5, ui->graphicsView->height()-5);
    Scene -> addItem(Morty);    //Agregar al morty
    //Scene -> removeItem(Morty); // ELiminar al morty
    ui -> graphicsView -> setScene(Scene);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *k)
{
    switch (k->key()) {
    case Qt::Key_W:
        Morty->set_next_direction(GameObject::Up);
        break;
    case Qt::Key_A:
        Morty->set_next_direction(GameObject::Left);
        break;
    case Qt::Key_S:
        Morty->set_next_direction(GameObject::Down);
        break;
    case Qt::Key_D:
        Morty->set_next_direction(GameObject::Right);
        break;
    }
}

