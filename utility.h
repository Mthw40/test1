#ifndef UTILITY_H
#define UTILITY_H

#include <QPixmap>
#include <QGraphicsPixmapItem>
#include <QTimer>

class Utility : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Utility();
    void showPerfect();
    void showOk();
    void showMiss();
    QTimer *timer;
private slots:
    void perish();
};

#endif // UTILITY_H
