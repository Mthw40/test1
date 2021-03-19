#include "klawisz.h"

Klawisz::Klawisz()//1. tekstura
{
    setPixmap(QPixmap(":/new/prefix1/Zasoby/kl1.png"));
    player=new QMediaPlayer;
}

void Klawisz::released()
{
    setPixmap(QPixmap(":/new/prefix1/Zasoby/kl1.png"));
}

void Klawisz::clicked()
{
    setPixmap(QPixmap(":/new/prefix1/Zasoby/kl2.png")); //tekstura klikniętego klawisza

    random=QRandomGenerator::global()->bounded(1,5);
    switch(random)
    {
        case 1:
            player->setMedia(QUrl("qrc:/new/prefix1/Zasoby/key-press-1.wav"));
            player->play();
            break;
        case 2:
            player->setMedia(QUrl("qrc:/new/prefix1/Zasoby/key-press-2.wav"));
            player->play();
            break;
        case 3:
            player->setMedia(QUrl("qrc:/new/prefix1/Zasoby/key-press-3.wav"));
            player->play();
            break;
        case 4:
            player->setMedia(QUrl("qrc:/new/prefix1/Zasoby/key-press-4.wav"));
            player->play();
            break;
    }

}

