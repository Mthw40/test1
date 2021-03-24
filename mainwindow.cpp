#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    showFullScreen();
    miss_sound = new QMediaPlayer;
    QPixmap p = QPixmap(":/new/prefix1/Zasoby/cursor.png");
    QCursor c = QCursor(p,0,0);
    setCursor(c);
    inGame=false;
    miss=true;
    tlo = new Tlo();
    scene = new QGraphicsScene();
    theme = new QMediaPlayer();
    kl1 = new Klawisz();
    kl2 = new Klawisz();
    kl3 = new Klawisz();
    kl4 = new Klawisz();
    hpbar = new Hp();
    connect(hpbar,SIGNAL(gitgud()),this,SLOT(endGame()));
    //dodanie hitboxów nut dla poszczególnych klawiszy
    kl1_ok = new Ok();
    kl1_perfect = new Perfect();
    kl2_ok = new Ok();
    kl2_perfect = new Perfect();
    kl3_ok = new Ok();
    kl3_perfect = new Perfect();
    kl4_ok = new Ok();
    kl4_perfect = new Perfect();
    utility = new Utility();

    //ustawienie hitboxów w odpowiednich miejscach
    kl1_ok->setPos(280,y()+800);
    kl1_perfect->setPos(280,y()+850);
    kl2_ok->setPos(430,y()+800);
    kl2_perfect->setPos(430,y()+850);
    kl3_ok->setPos(580,y()+800);
    kl3_perfect->setPos(580,y()+850);
    kl4_ok->setPos(730,y()+800);
    kl4_perfect->setPos(730,y()+850);
    //dodanie hitboxów
    scene->addItem(kl1_ok);
    scene->addItem(kl1_perfect);
    scene->addItem(kl2_ok);
    scene->addItem(kl2_perfect);
    scene->addItem(kl3_ok);
    scene->addItem(kl3_perfect);
    scene->addItem(kl4_ok);
    scene->addItem(kl4_perfect);
    scene->addItem(tlo); //dodanie tła do sceny
    ui->graphicsView->setScene(scene); //ustawienie sceny

    theme->setMedia(QUrl("qrc:/new/prefix1/Zasoby/MainTheme.wav"));//menu theme
    theme->setVolume(100);
    theme->play();

    tempo = new QTimer(this);
    connect(tempo,SIGNAL(timeout()),this,SLOT(beat()));
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
        if(kl1_perfect->check()){
            //score + perfect
            score+=100;
            miss=false;
            utility->showPerfect();
        }
        if(kl1_ok->check()){
            //score + ok
            score+=50;
            miss=false;
            utility->showOk();
        }
    }
    if(event->key()==Qt::Key_F && inGame){ // 2. klawisz
        kl2->clicked();
        if(kl2_perfect->check()){
            //score + perfect
            score+=100;
            miss=false;
            utility->showPerfect();
        }
        if(kl2_ok->check()){
            //score + ok
            score+=50;
            miss=false;
            utility->showOk();
        }
    }
    if(event->key()==Qt::Key_J && inGame){ // 3. klawisz
        kl3->clicked();
        if(kl3_perfect->check()){
            //score + perfect
            score+=100;
            miss=false;
            utility->showPerfect();
        }
        if(kl3_ok->check()){
            //score + ok
            score+=50;
            miss=false;
            utility->showOk();
        }
    }
    if(event->key()==Qt::Key_K && inGame){ // 4. klawisz
        kl4->clicked();
        if(kl4_perfect->check()){
            //score + perfect
            score+=100;
            miss=false;
            utility->showPerfect();
        }
        if(kl4_ok->check()){
            //score + ok
            score+=50;
            miss=false;
            utility->showOk();
        }

    }
    if(miss && inGame){
        missed();

    }
    if(inGame && !miss)
    {
        refreshScore();
        hpbar->changebar(1);
    }
    miss=true;
    if(event->key()==Qt::Key_P && !inGame){ // Zacznij grę
        startGame();
    }
    if(event->key()==Qt::Key_O && !inGame){
        SongSelect SS;
        SS.setModal(true);
        SS.exec();
    }
    if(event->key()==Qt::Key_Q){
        QApplication::quit();
    }
    if(event->key()==Qt::Key_M && !inGame){
        tlo->showMenu();
        theme->setMedia(QUrl("qrc:/new/prefix1/Zasoby/MainTheme.wav"));//menu theme
        theme->setVolume(100);
        theme->play();
    }

     if(event->key()==Qt::Key_E && !inGame){ // E - Credits
        Credits CC;
        CC.setModal(true);
        CC.exec();
     }
}

void MainWindow::missed()
{
    score-=10;
    utility->showMiss();
    hpbar->changebar(-1);
    miss_sound->setMedia(QUrl("qrc:/new/prefix1/Zasoby/miss.wav"));
    miss_sound->play();
}

void MainWindow::startGame()
{
    tlo->lvl();
    scene->addItem(utility);
    scene->addItem(hpbar);
    hpbar->changebar(0);
    inGame=true;
    score=0;
    index=0;
    //dodanie i ustawienie klawiszy w odpowiednich miejscach
    scene->addItem(kl1);
    kl1->setPos(280,y()+915);
    scene->addItem(kl2);
    kl2->setPos(430,y()+915);
    scene->addItem(kl3);
    kl3->setPos(580,y()+915);
    scene->addItem(kl4);
    kl4->setPos(730,y()+915);

    //ustawienie odpowiedniego utworu
    QSettings settings("TheTwatSquad","SuperGra");
    settings.beginGroup("Level");
    if(settings.value("Id").toInt()==1){ //
        theme->setMedia(QUrl("qrc:/new/prefix1/Zasoby/Tracks/Amogus.mp3"));
    }
    else if(settings.value("Id").toInt()==2){
        theme->setMedia(QUrl(""));
    }
    theme->play();
    songPath=settings.value("Song").toString();
    settings.endGroup();
    //odczytanie pliku utworu z odpowiedniego pliku .txt
    QFile song(songPath);
    if(!song.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::critical(0,"Błąd","Błąd odczytu z pliku!");
    }
    BPM = song.readLine().toInt();
    qDebug()<<BPM;
    while(!song.atEnd()){
        content.append(song.readLine());
    }
    tempo->start(1000/(BPM/60));
}
void MainWindow::beat()
{
    if(index==content.count()-1){ //koniec utworu
        tempo->stop();
        song.close();
        QTimer::singleShot(4000,this,SLOT(won()));
        return;
    }
    line = content[index];
    index++;
    if(line.size()<4) return;
    if(line[0]=="*"){
        nuta = new Nuta();
        connect(nuta,SIGNAL(bruh()),this,SLOT(missed()));
        nuta->setPos(280,y());
        scene->addItem(nuta);
    }
    if(line[1]=="*"){
        nuta = new Nuta();
        connect(nuta,SIGNAL(bruh()),this,SLOT(missed()));
        nuta->setPos(430,y());
        scene->addItem(nuta);
    }
    if(line[2]=="*"){
        nuta = new Nuta();
        connect(nuta,SIGNAL(bruh()),this,SLOT(missed()));
        nuta->setPos(580,y());
        scene->addItem(nuta);
    }
    if(line[3]=="*"){
        nuta = new Nuta();
        connect(nuta,SIGNAL(bruh()),this,SLOT(missed()));
        nuta->setPos(730,y());
        scene->addItem(nuta);
    }
}


void MainWindow::endGame()
{
    ui->Score->setText("");
    hpbar->changebar(4);
    scene->removeItem(utility);
    scene->removeItem(hpbar);
    scene->removeItem(kl1);
    scene->removeItem(kl2);
    scene->removeItem(kl3);
    scene->removeItem(kl4);
    theme->stop();
    theme->setMedia(QUrl("qrc:/new/prefix1/Zasoby/fail_music.mp3"));//fail theme
    theme->setVolume(100);
    theme->play();
    tlo->fail();
    index=0;
    content.clear();
    inGame=false;

}

void MainWindow::won()
{

    ui->Score->setText("");
    hpbar->changebar(4);
    scene->removeItem(utility);
    scene->removeItem(hpbar);
    scene->removeItem(kl1);
    scene->removeItem(kl2);
    scene->removeItem(kl3);
    scene->removeItem(kl4);
    theme->stop();
    theme->setMedia(QUrl("qrc:/new/prefix1/Zasoby/victory_music.mp3"));//victory theme
    theme->setVolume(100);
    theme->play();
    tlo->win();
    index=0;
    content.clear();
    inGame=false;

}

void MainWindow::refreshScore()
{
    ui->Score->setText("Wynik: "+QString::number(score));
}
