#include "tlo.h"

Tlo::Tlo()
{
    showMenu();
}

void Tlo::showMenu()
{
    setPixmap(QPixmap("")); //menu główne
}

void Tlo::lvl()
{
    setPixmap(QPixmap(":/new/prefix1/Zasoby/lvl.jpg")); //poziom
    //!!!do tworzenia tła poziomu używać tej samej rozdzielczości!!!
}

