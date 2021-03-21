#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    showFullScreen();

    QPixmap p = QPixmap(":/new/prefix1/Zasoby/cursor.png");
    QCursor c = QCursor(p,0,0);
    setCursor(c);
    inGame=false;
    tlo = new Tlo();
    scene = new QGraphicsScene();
    theme = new QMediaPlayer();
    kl1 = new Klawisz();
    kl2 = new Klawisz();
    kl3 = new Klawisz();
    kl4 = new Klawisz();
    //dodanie hitboxów nut dla poszczególnych klawiszy
    kl1_ok = new Ok();
    kl1_perfect = new Perfect();
    kl2_ok = new Ok();
    kl2_perfect = new Perfect();
    kl3_ok = new Ok();
    kl3_perfect = new Perfect();
    kl4_ok = new Ok();
    kl4_perfect = new Perfect();

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
void MainWindow::keyReleaseEvent(QKeyEvent *event)
{
    if(event->key()==Qt::Key_D && inGame){ // 1. klawisz
        kl1->released();
    }
    if(event->key()==Qt::Key_F && inGame){ // 2. klawisz
        kl2->released();
    }
    if(event->key()==Qt::Key_J && inGame){ // 3. klawisz
        kl3->released();
    }
    if(event->key()==Qt::Key_K && inGame){ // 4. klawisz
        kl4->released();
    }
}
void MainWindow::keyPressEvent(QKeyEvent *event) //zczytanie z klawiatury
{
    if(event->key()==Qt::Key_D && inGame){ // 1. klawisz
        kl1->clicked();
        kl1_perfect->check();
        if(kl1_perfect->isChecked()){
            //score + perfect
            score+=100;
        }
        kl1_ok->check();
        if(kl1_ok->isChecked()){
            //score + ok
            score+=50;
        }
        refreshScore();
    }
    if(event->key()==Qt::Key_F && inGame){ // 2. klawisz
        kl2->clicked();
        kl2_perfect->check();
        if(kl2_perfect->isChecked()){
            //score + perfect
            score+=100;
        }
        kl2_ok->check();
        if(kl2_ok->isChecked()){
            //score + ok
            score+=50;
        }
        refreshScore();
    }
    if(event->key()==Qt::Key_J && inGame){ // 3. klawisz
        kl3->clicked();
        kl3_perfect->check();
        if(kl3_perfect->isChecked()){
            //score + perfect
            score+=100;
        }
        kl3_ok->check();
        if(kl3_ok->isChecked()){
            //score + ok
            score+=50;
        }
        refreshScore();
    }
    if(event->key()==Qt::Key_K && inGame){ // 4. klawisz
        kl4->clicked();
        kl4_perfect->check();
        if(kl4_perfect->isChecked()){
            //score + perfect
            score+=100;
        }
        kl4_ok->check();
        if(kl4_ok->isChecked()){
            //score + ok
            score+=50;
        }
        refreshScore();
    }
    if(event->key()==Qt::Key_P && !inGame){ // Zacznij grę
        startGame();
        theme->stop();
    }
    if(event->key()==Qt::Key_O && !inGame){
        SongSelect SS;
        SS.setModal(true);
        SS.exec();
    }
    if(event->key()==Qt::Key_Q){
        QApplication::quit();
    }
    if(event->key()==Qt::Key_N && inGame){
        nuta = new Nuta();
        nuta->setPos(483,y());
        scene->addItem(nuta);
    }
}

void MainWindow::startGame()
{
    tlo->lvl();
    score=0;
    //dodanie i ustawienie klawiszy w odpowiednich miejscach
    scene->addItem(kl1);
    kl1->setPos(8,y()+800);
    scene->addItem(kl2);
    kl2->setPos(483,y()+800);
    scene->addItem(kl3);
    kl3->setPos(956,y()+800);
    scene->addItem(kl4);
    kl4->setPos(1430,y()+800);
    //dodanie i ustawienie hitboxów w odpowiednich miejscach !!!współrzędne y jeszcze nie są ustawione!!!
    /*
    scene->addItem(kl1_ok);
    kl1_ok->setPos(8,y());
    scene->addItem(kl1_perfect);
    kl1_perfect->setPos(8,y());
    scene->addItem(kl2_ok);
    kl2_ok->setPos(483,y());
    scene->addItem(kl2_perfect);
    kl2_perfect->setPos(483,y());
    scene->addItem(kl3_ok);
    kl3_ok->setPos(956,y());
    scene->addItem(kl3_perfect);
    kl3_perfect->setPos(956,y());
    scene->addItem(kl4_ok);
    kl4_ok->setPos(1430,y());
    scene->addItem(kl4_perfect);
    kl4_perfect->setPos(1430,y());
    */

    //theme->setMedia(QUrl("qrc:/new/prefix1/Zasoby/MainTheme.wav")); //theme poziomu
    //theme->play();

    inGame=true;
}

void MainWindow::endGame()
{
    inGame=false;
}

void MainWindow::refreshScore()
{
    //ui->scoreLabel->setText("Wynik: "+score);
}
