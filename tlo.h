#ifndef TLO_H
#define TLO_H

#include <QPixmap>
#include <QKeyEvent>
#include <QGraphicsPixmapItem>
#include "nuta.h"

class Tlo : public QObject, public QGraphicsPixmapItem
{
public:
    Tlo();
    void showMenu();
    void lvl();
    void fail();
    void win();
};

#endif // TLO_H
