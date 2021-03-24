#include "tlo.h"

Tlo::Tlo()
{
    showMenu();
}

void Tlo::showMenu()
{
    setPixmap(QPixmap(":/new/prefix1/Zasoby/menu.jpg")); //menu główne
}

void Tlo::lvl()
{
    setPixmap(QPixmap(":/new/prefix1/Zasoby/lvl.jpg")); //poziom
    //!!!do tworzenia tła poziomu używać tej samej rozdzielczości!!!
}

void Tlo::fail()
{
    setPixmap(QPixmap(":/new/prefix1/Zasoby/fail.jpg"));
}

void Tlo::win()
{
    setPixmap(QPixmap(":/new/prefix1/Zasoby/win.jpg"));
}

