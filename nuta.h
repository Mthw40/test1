#ifndef NUTA_H
#define NUTA_H

#include <QPixmap>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QMediaPlayer>
#include <QTimer>
#include <QtCore>

class Nuta : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Nuta();
    QTimer *timer;
    QMediaPlayer *player;
private slots:
    void onTimerTimeout();
};

#endif // NUTA_H
