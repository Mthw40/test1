#include "nuta.h"

Nuta::Nuta()
{
    setPixmap(QPixmap("")); //tekstura nuty
    timer = new QTimer(this);

    player = new QMediaPlayer();
    player->setMedia(QUrl("")); //dźwięk uderzenia w nutę
    player->setVolume(80);

    connect(timer,SIGNAL(timeout()),this,SLOT(onTimerTimeout())); //połączenie timera z funkcją, która powoduje "spadek" nuty
    timer->start(20);
}

void Nuta::onTimerTimeout()
{
    setPos(x(),y()+10);
}
