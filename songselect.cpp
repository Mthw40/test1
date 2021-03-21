#include "songselect.h"
#include "ui_songselect.h"

SongSelect::SongSelect(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SongSelect)
{
    ui->setupUi(this);
}

SongSelect::~SongSelect()
{
    delete ui;
}
