#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    showFullScreen();

    inGame=false;
    tlo = new Tlo();
    scene = new QGraphicsScene();
    theme = new QMediaPlayer();
    kl1 = new Klawisz();
    kl2 = new Klawisz();
    kl2->setSecond();
    kl3 = new Klawisz();
    kl4 = new Klawisz();
    kl4->setSecond();

    scene->addItem(tlo); //dodanie tła do sceny
    ui->graphicsView->setScene(scene); //ustawienie sceny

    theme->setMedia(QUrl("qrc:/new/prefix1/Zasoby/MainTheme.wav"));//menu theme
    theme->setVolume(100);
    theme->play();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *event) //zczytanie z klawiatury
{
    if(event->key()==Qt::Key_D && inGame){ // 1. klawisz
        kl1->clicked();
    }
    if(event->key()==Qt::Key_F && inGame){ // 2. klawisz
        kl2->clicked();
    }
    if(event->key()==Qt::Key_J && inGame){ // 3. klawisz
        kl3->clicked();
    }
    if(event->key()==Qt::Key_K && inGame){ // 4. klawisz
        kl4->clicked();
    }
    if(event->key()==Qt::Key_P && !inGame){ // Zacznij grę
        startGame();
    }
    if(event->key()==Qt::Key_Q){
        QApplication::quit();
    }

}

void MainWindow::startGame()
{
    tlo->lvl();
    scene->addItem(kl1); //dodanie i ustawienie klawiszy w odpowiednich miejscach
    kl1->setPos(8,y()+800);
    scene->addItem(kl2);
    kl2->setPos(483,y()+800);
    scene->addItem(kl3);
    kl3->setPos(956,y()+800);
    scene->addItem(kl4);
    kl4->setPos(1430,y()+800);

    inGame=true;
}



