#ifndef KLAWISZ_H
#define KLAWISZ_H

#include <QPixmap>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QMediaPlayer>
#include <QTimer>
#include <QtCore>
#include <QRandomGenerator>

class Klawisz : public QObject, public QGraphicsPixmapItem
{
public:
    Klawisz();
    void released(); // druga tekstura klawisza
    void clicked();
    int random;
    QMediaPlayer *player;
};

#endif // KLAWISZ_H
