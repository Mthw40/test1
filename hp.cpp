#include "hp.h"

Hp::Hp()
{
    change = 8;
    this->setPos(910,y()+360);
    setPixmap(QPixmap(":/new/prefix1/Zasoby/hp_full.png"));
}

void Hp::changebar(int a)
{
    change=change+a;
    if(change>8)
        change=8;
    if(change<=8 && change>6)
    {
        setPixmap(QPixmap(":/new/prefix1/Zasoby/hp_full.png"));
    }
    if(change<=6 && change>4)
    {
        setPixmap(QPixmap(":/new/prefix1/Zasoby/hp_75.png"));
    }
    if(change<=4 && change>2)
    {
        setPixmap(QPixmap(":/new/prefix1/Zasoby/hp_50.png"));
    }
    if(change<=2 && change>0)
    {
        setPixmap(QPixmap(":/new/prefix1/Zasoby/hp_25.png"));
    }
    if(change<=0)
    {
        emit gitgud();
    }
}
