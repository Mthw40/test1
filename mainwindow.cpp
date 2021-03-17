#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    showFullScreen();

    tlo = new Tlo();
    scene = new QGraphicsScene();
    theme = new QMediaPlayer();

    scene->addItem(tlo); //dodanie tła do sceny
    ui->graphicsView->setScene(scene); //ustawienie sceny

    theme->setMedia(QUrl(""));//menu theme
    theme->setVolume(100);
    //theme->play();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *event) //zczytanie z klawiatury
{
    if(event->key()==Qt::Key_Q){
        QApplication::quit();
    }

}



