#include "perfect.h"

Perfect::Perfect()
{
    setPixmap(QPixmap(":/new/prefix1/Zasoby/perfect_hitbox.png")); //hitbox dla "Perfect"
}
bool Perfect::check()
{
    //sprawdzenie kolizji dla hitboxa perfect
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for(int i=0, n=colliding_items.size();i<n;++i){
        if(typeid(*(colliding_items[i]))==typeid(Nuta)){
            scene()->removeItem(colliding_items[i]);
            delete colliding_items[i];
            return true;
        }
    }
    return false;
}
