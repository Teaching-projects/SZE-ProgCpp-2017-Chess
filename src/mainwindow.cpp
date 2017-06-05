#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->game = Game();

    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            this->fields[i][j] = new QPushButton(this);
            this->fields[i][j]->setGeometry(QRect(QPoint(i * 75, j * 75), QSize(75, 75)));
            this->fields[i][j]->setObjectName(QString::number(i).append(QString::number(j)));

            QString style("QPushButton {border: 0, 0, 0, 0; color: gray; background: %1;} QPushButton:hover {border: 5px solid orange;}");
            QString color;

            if (i % 2 == 0)
            {
                if (j % 2 == 0)
                {
                    color = QString("white");
                }
                else
                {
                    color = QString("black");
                }
            }
            else
            {
                if (j % 2 == 0)
                {
                    color = QString("black");
                }
                else
                {
                    color = QString("white");
                }
            }

            this->fields[i][j]->setStyleSheet(style.arg(color));

            connect(this->fields[i][j], SIGNAL (released()), this, SLOT (fieldSelected()));
        }
    }

    this->drawChesspieces();
}

void MainWindow::drawDiscoveredSteps()
{
    /*QPalette pal = this->fields[i][j]->palette();
    pal.setColor(QPalette::Button, QColor(Qt::red));
    this->fields[i][j]->setAutoFillBackground(true);
    this->fields[i][j]->setPalette(pal);*/
}

void MainWindow::drawChesspieces()
{
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            this->fields[i][j]->setText("Chess");
            this->fields[i][j]->update();
        }
    }
}

void MainWindow::fieldSelected()
{
    QPushButton* buttonClicked = qobject_cast<QPushButton*>(sender());

    if (buttonClicked)
    {
        QString buttonName = buttonClicked->objectName();

        int x = buttonName.toStdString()[0];
        int y = buttonName.toStdString()[1];

        /*if (this->buttonClickForPieceSelection)
        {
            if (this->game.selectPieceForStep(x, y)) // Is selection valid?
            {
                this->drawDiscoveredSteps();
                this->buttonClickForPieceSelection = false;
            }
        }
        else
        {
            if (this->game.movePieceTo(x, y)) // Is selection valid?
            {
                this->drawChesspieces();
                this->buttonClickForPieceSelection = true;
            }

        }*/
    }
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
