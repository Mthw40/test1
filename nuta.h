#ifndef NUTA_H
#define NUTA_H

#include <QPixmap>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QTimer>
#include <QtCore>

class Nuta : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Nuta();
    QTimer *timer;
private slots:
    void onTimerTimeout();
signals:
    void bruh();
};

#endif // NUTA_H
