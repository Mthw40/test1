#include "credits.h"
#include "ui_credits.h"

Credits::Credits(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Credits)
{

    ui->setupUi(this);

    QPixmap p = QPixmap(":/new/prefix1/Zasoby/cursor.png");
    QCursor c = QCursor(p,0,0);
    setCursor(c);
    setFixedSize(size());
}

Credits::~Credits()
{
    delete ui;
}
