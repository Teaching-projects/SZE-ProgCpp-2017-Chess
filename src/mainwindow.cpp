#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //this->game = Game();
    this->game.startNew();

    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            this->fields[i][j] = new QPushButton(this);
            this->fields[i][j]->setGeometry(QRect(QPoint(i * 75, j * 75), QSize(75, 75)));
            this->fields[i][j]->setObjectName(QString::number(i).append(QString::number(j)));
            this->fields[i][j]->setProperty("discovered", false);

            QString style("QPushButton[discovered=true] {border: 3px solid red;} QPushButton[discovered=false] {border: 0, 0, 0, 0; color: gray; background: %1;} QPushButton:hover {border: 5px solid orange;}");
            QString color;

            if (i % 2 == 0)
            {
                if (j % 2 == 0)
                {
                    color = QString("#ffffff");
                }
                else
                {
                    color = QString("#666666");
                }
            }
            else
            {
                if (j % 2 == 0)
                {
                    color = QString("#666666");
                }
                else
                {
                    color = QString("#ffffff");
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
    /*QPalette pal = this->fields[3][3]->palette();
    pal.setColor(QPalette::Button, QColor(Qt::red));
    this->fields[3][3]->setAutoFillBackground(true);
    this->fields[3][3]->setPalette(pal);*/

    std::vector<DiscoveredStep> discoveredSteps = this->game.getDiscoveredSteps();

    for (int i = 0; i < discoveredSteps.size(); i++)
    {
        this->fields[discoveredSteps[i].getX()][discoveredSteps[i].getY()]->setProperty("discovered", true);
        this->fields[discoveredSteps[i].getX()][discoveredSteps[i].getY()]->setStyleSheet("border: 3px solid red;");
    }
}

void MainWindow::drawChesspieces()
{
    std::vector<std::string> pieceNames;

    this->game.getChessPieces(pieceNames);

    int j = 0;
    int k = -1;

    for (int i = 0; i < pieceNames.size(); i++, j++)
    {
        if (i % 8 == 0)
        {
            j = 0;
            k++;
        }

        if (pieceNames[i] != "")
        {
            QString pieceName = QString::fromStdString(pieceNames[i]);
            QPixmap pixmap(QString("C:/Users/Tomi/Desktop/SZE-ProgCpp-2017-Chess/src/img/%1.png").arg(pieceName));
            QIcon buttonIcon(pixmap);

            this->fields[j][k]->setIcon(buttonIcon);
            this->fields[j][k]->setIconSize(QSize(60, 60));
        }
        else
        {
            this->fields[j][k]->setIcon(QIcon());
        }
    };
}

void MainWindow::clearDiscoveredSteps()
{
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            this->fields[i][j]->setProperty("discovered", false);
            this->fields[i][j]->setStyleSheet("border: 0 0 0 0;");
        }
    }
}

void MainWindow::fieldSelected()
{
    QPushButton* buttonClicked = qobject_cast<QPushButton*>(sender());

    if (buttonClicked)
    {
        QString buttonName = buttonClicked->objectName();

        int x = buttonName.toStdString()[0] - '0';
        int y = buttonName.toStdString()[1] - '0';

        if (this->buttonClickForPieceSelection)
        {
            if (this->game.selectPieceForStep(x, y)) // Is selection valid?
            {
                this->drawDiscoveredSteps();
                this->buttonClickForPieceSelection = false;
            }
        }
        else
        {
            if (this->game.changeSelection(x, y) && this->game.selectPieceForStep(x, y))
            {
                this->clearDiscoveredSteps();
                this->drawDiscoveredSteps();
                this->buttonClickForPieceSelection = false;
            }
            else if (this->game.movePieceTo(x, y)) // Is selection valid?
            {
                this->clearDiscoveredSteps();
                this->drawChesspieces();
                this->buttonClickForPieceSelection = true;
            }
        }
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
