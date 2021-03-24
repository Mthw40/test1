#include "hp.h"

Hp::Hp()
{
    change = 4;
    this->setPos(910,y()+360);
    setPixmap(QPixmap(":/new/prefix1/Zasoby/hp_full.png"));
}

void Hp::changebar(int a)
{
    change = change+a;

    if(change==4)
    {
        setPixmap(QPixmap(":/new/prefix1/Zasoby/hp_full.png"));
    }
    if(change==3)
    {
        setPixmap(QPixmap(":/new/prefix1/Zasoby/hp_75.png"));
    }
    if(change==2)
    {
        setPixmap(QPixmap(":/new/prefix1/Zasoby/hp_50.png"));
    }
    if(change==1)
    {
        setPixmap(QPixmap(":/new/prefix1/Zasoby/hp_25.png"));
    }

}
