#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            this->fields[i][j] = new QPushButton("A", this);
            this->fields[i][j]->setGeometry(QRect(QPoint(i * 50, j * 50), QSize(50, 50)));

            /*QPalette pal = this->fields[i][j]->palette();
            pal.setColor(QPalette::Button, QColor(Qt::red));
            this->fields[i][j]->setAutoFillBackground(true);
            this->fields[i][j]->setPalette(pal);*/

            connect(this->fields[i][j], SIGNAL (released()), this, SLOT (fieldSelected()));
        }
    }
}

void MainWindow::fieldSelected()
{
    /*QPalette pal = this->fields[i][j]->palette();
    pal.setColor(QPalette::Button, QColor(Qt::red));
    this->fields[i][j]->setAutoFillBackground(true);
    this->fields[i][j]->setPalette(pal);*/
}

MainWindow::~MainWindow()
{
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            delete this->fields[i][j];
        }
    }

    delete ui;
}
