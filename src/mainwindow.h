#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QPalette>
#include "Game.h"


#include <iostream>

#define ROW 8
#define COL 8

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    QPushButton *fields[ROW][COL];

    Game game;
    bool buttonClickForPieceSelection = true;

    void drawDiscoveredSteps();
    void drawChesspieces();

private slots:
    void fieldSelected();
};

#endif // MAINWINDOW_H
