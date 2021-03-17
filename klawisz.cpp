#include "klawisz.h"

Klawisz::Klawisz()// 1. tekstura
{
    setPixmap(QPixmap(":/new/prefix1/Zasoby/kl1.png"));
}

void Klawisz::setSecond()//2. tekstura
{
    setPixmap(QPixmap(":/new/prefix1/Zasoby/kl2.png"));
}

void Klawisz::clicked()
{
    //setPixmap(QPixmap("")); //tekstura klikniętego klawisza

}

