#include "songselect.h"
#include "ui_songselect.h"

SongSelect::SongSelect(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SongSelect)
{
    ui->setupUi(this);

    QPixmap p = QPixmap(":/new/prefix1/Zasoby/cursor.png");
    QCursor c = QCursor(p,0,0);
    setCursor(c);
    setFixedSize(size());

    QSettings settings("TheTwatSquad","SuperGra");
    settings.beginGroup("Level");
    //zaznaczenie checkboxa, którego piosenka jest aktualnie wybrana
    if(settings.value("Id").toInt()==1){
        ui->option1->setChecked(true);
    }
    else if(settings.value("Id").toInt()==2){
        ui->option2->setChecked(true);
    }
    else if(settings.value("Id").toInt()==3){
        ui->option3->setChecked(true);
    }
    settings.endGroup();
}

SongSelect::~SongSelect()
{
    delete ui;
}

void SongSelect::on_buttonBox_accepted()
{
    if(ui->option1->isChecked()){
        path=":/new/prefix1/Zasoby/Tracks/AmongDrip.txt"; // !względna! ścieżka do pliku txt piosenki
        id=1;
    }
    else if(ui->option2->isChecked()){
        path=":/new/prefix1/Zasoby/Tracks/La Passion.txt";
        id=2;
    }
    else if(ui->option3->isChecked()){
        path=":/new/prefix1/Zasoby/Tracks/chacha.txt";
        id=3;
    }
    QSettings settings("TheTwatSquad","SuperGra");
    settings.beginGroup("Level");
    settings.setValue("Song",path);
    settings.setValue("Id",id);
    settings.endGroup();
}
