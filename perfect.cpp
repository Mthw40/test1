#include "perfect.h"

Perfect::Perfect()
{
    player = new QMediaPlayer();
    player->setMedia(QUrl(""));
    setPixmap(QPixmap(":/new/prefix1/Zasoby/perfect_hitbox.png")); //hitbox dla "Perfect"
}
void Perfect::check()
{
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for(int i=0, n=colliding_items.size();i<n;++i){
        if(typeid(*(colliding_items[i]))==typeid(Nuta)){
            player->play(); //odtworzenie dźwięku nuty
            checked=true;
            scene()->removeItem(colliding_items[i]);
            delete colliding_items[i];
            return;
        }
    }
}

bool Perfect::isChecked()
{
    bool temp = checked;
    checked = false;
    return temp;
}
