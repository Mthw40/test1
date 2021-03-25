#ifndef PERFECT_H
#define PERFECT_H
#include <QPixmap>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include "nuta.h"

class Perfect : public QObject, public QGraphicsPixmapItem
{
public:
    Perfect();
    bool check();
};

#endif // PERFECT_H
