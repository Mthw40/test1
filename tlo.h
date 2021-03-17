#ifndef TLO_H
#define TLO_H

#include <QPixmap>
#include <QKeyEvent>
#include <QGraphicsPixmapItem>

class Tlo : public QObject, public QGraphicsPixmapItem
{
public:
    Tlo();
    void lvl1();
};

#endif // TLO_H
