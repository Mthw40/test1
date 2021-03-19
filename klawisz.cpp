#include "klawisz.h"

Klawisz::Klawisz()//1. tekstura
{
    setPixmap(QPixmap(":/new/prefix1/Zasoby/kl1.png"));
}

void Klawisz::released()
{
    setPixmap(QPixmap(":/new/prefix1/Zasoby/kl1.png"));
}



void Klawisz::clicked()
{
    setPixmap(QPixmap(":/new/prefix1/Zasoby/kl2.png")); //tekstura klikniętego klawisza

}

