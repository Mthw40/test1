#ifndef SONGSELECT_H
#define SONGSELECT_H

#include <QDialog>

namespace Ui {
class SongSelect;
}

class SongSelect : public QDialog
{
    Q_OBJECT

public:
    explicit SongSelect(QWidget *parent = nullptr);
    ~SongSelect();

private:
    Ui::SongSelect *ui;
};

#endif // SONGSELECT_H
