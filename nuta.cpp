#include "nuta.h"

Nuta::Nuta()
{
    setPixmap(QPixmap(":/new/prefix1/Zasoby/note1.png")); //tekstura nuty
    timer = new QTimer(this);

    connect(timer,SIGNAL(timeout()),this,SLOT(onTimerTimeout())); //połączenie timera z funkcją, która powoduje "spadek" nuty
    timer->start(10); //prędkość spadku nuty
}
void Nuta::onTimerTimeout()
{
    setPos(x(),y()+10);
    if(this->y()>=870) //w przypadku gdy nuta "ucieknie"
    {
        emit bruh(); //sygnał do missed()
        delete this;
    }
}
