#include "songselect.h"
#include "ui_songselect.h"

SongSelect::SongSelect(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SongSelect)
{
    ui->setupUi(this);

    QSettings settings("TheTwatSquad","SuperGra");
    settings.beginGroup("Level");
    //zaznaczenie checkboxa, którego piosenka jest aktualnie wybrana
    if(settings.value("Id").toInt()==1){
        ui->option1->setChecked(true);
    }
    else if(settings.value("Id").toInt()==2){
        ui->option2->setChecked(true);
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
        path="D:/Projekty/Qt Projects/coop/test1/Tracks/AmongDrip.txt"; // !względna! ścieżka do pliku txt piosenki
        id=1;
    }
    else if(ui->option2->isChecked()){
        path="";
        id=2;
    }

    QSettings settings("TheTwatSquad","SuperGra");
    settings.beginGroup("Level");
    settings.setValue("Song",path);
    settings.setValue("Id",id);
    settings.endGroup();
}
