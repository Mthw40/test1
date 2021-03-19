#include "nuta.h"

Nuta::Nuta()
{
    setPixmap(QPixmap(":/new/prefix1/Zasoby/kl2.png")); //tekstura nuty
    timer = new QTimer(this);

    connect(timer,SIGNAL(timeout()),this,SLOT(onTimerTimeout())); //połączenie timera z funkcją, która powoduje "spadek" nuty
    timer->start(20);
}
void Nuta::onTimerTimeout()
{
    setPos(x(),y()+60);
    if(this->y()>=800)
    {
        delete this;
    }
}
