#ifndef SONGSELECT_H
#define SONGSELECT_H

#include <QDialog>
#include <QDebug>
#include <QSettings>
#include <QCursor>

namespace Ui {
class SongSelect;
}

class SongSelect : public QDialog
{
    Q_OBJECT

public:
    explicit SongSelect(QWidget *parent = nullptr);
    ~SongSelect();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::SongSelect *ui;
    QString path;
    int id;
};

#endif // SONGSELECT_H
