#ifndef OK_H
#define OK_H
#include <QPixmap>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QMediaPlayer>
#include "nuta.h"

class Ok : public QObject, public QGraphicsPixmapItem
{
public:
    Ok();
    QMediaPlayer *player;
    bool check();
};

#endif // OK_H
