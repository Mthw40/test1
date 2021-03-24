#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QtCore>
#include <QString>
#include <QPixmap>
#include <QKeyEvent>
#include <QMediaPlayer>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QRandomGenerator>
#include <QPushButton>
#include <QVBoxLayout>
#include <QCursor>
#include <QFile>
#include <QTextStream>
#include <QList>
#include <QMessageBox>
#include "tlo.h"
#include "nuta.h"
#include "klawisz.h"
#include "ok.h"
#include "perfect.h"
#include "songselect.h"
#include "utility.h"
#include "hp.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
protected:
    void keyPressEvent(QKeyEvent *event);

    void keyReleaseEvent(QKeyEvent *event);
private:
    Ui::MainWindow *ui;
    Tlo *tlo;
    QGraphicsScene *scene;
    QMediaPlayer *theme;
    QFile song;
    QTimer *tempo;
    QList<QString> content;
    Nuta *nuta;
    Klawisz *kl1;
    Klawisz *kl2;
    Klawisz *kl3;
    Klawisz *kl4;
    Ok *kl1_ok;
    Ok *kl2_ok;
    Ok *kl3_ok;
    Ok *kl4_ok;
    Perfect *kl1_perfect;
    Perfect *kl2_perfect;
    Perfect *kl3_perfect;
    Perfect *kl4_perfect;
    Utility *utility;
    Hp *hpbar;
    bool inGame;
    bool miss;
    int index;
    int score;
    int BPM;
    QString line;
    QString songPath;
    void startGame();
    void refreshScore();
private slots:
    void missed();
    void beat();
    void endGame();
    void won();
};
#endif // MAINWINDOW_H
