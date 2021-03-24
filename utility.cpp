#include "utility.h"

Utility::Utility()
{
    this->setPos(475,500);
}

void Utility::showPerfect()
{
    setPixmap(QPixmap(":/new/prefix1/Zasoby/perfect.png"));
    QTimer::singleShot(500,this,SLOT(perish()));
}

void Utility::showOk()
{
    setPixmap(QPixmap(":/new/prefix1/Zasoby/ok.png"));
    QTimer::singleShot(500,this,SLOT(perish()));
}

void Utility::showMiss()
{
    setPixmap(QPixmap(":/new/prefix1/Zasoby/miss.png"));
    QTimer::singleShot(500,this,SLOT(perish()));
}

void Utility::perish()
{
    setPixmap(QPixmap(""));
}
