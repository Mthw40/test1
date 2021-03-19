#ifndef PERFECT_H
#define PERFECT_H
#include <QPixmap>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QMediaPlayer>
#include "nuta.h"

class Perfect : public QObject, public QGraphicsPixmapItem
{
public:
    Perfect();
    QMediaPlayer *player;
    void check();
    bool isChecked();
    bool checked;
};

#endif // PERFECT_H
