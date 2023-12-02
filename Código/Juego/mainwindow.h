#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
//#include <QGraphicsScene>
//#include <QString>
#include <QKeyEvent>
#include <QBrush>
#include <QColor>

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

    void keyPressEvent(QKeyEvent *k) override;

private:
    Ui::MainWindow *ui;
    Game *game;

};
#endif // MAINWINDOW_H
