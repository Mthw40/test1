#ifndef HP_H
#define HP_H

#include <QPixmap>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>

class Hp : public QObject, public QGraphicsPixmapItem
{
public:
    Hp();
    void changebar(int);
    int change;
};

#endif // HP_H
