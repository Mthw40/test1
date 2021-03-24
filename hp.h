#ifndef HP_H
#define HP_H

#include <QPixmap>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QtCore>

class Hp : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Hp();
    void changebar(int);
    int change;
signals:
    void gitgud();
};

#endif // HP_H
