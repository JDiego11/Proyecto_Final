#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
//#include <QGraphicsScene>
//#include <QString>
#include <QKeyEvent>

#include "game.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void keyPressEvent(QKeyEvent *k);

private:
    Ui::MainWindow *ui;
    //QGraphicsScene *Scene;
    //QString h;

    //GameObject *Morty;
    Game *game;

};
#endif // MAINWINDOW_H
