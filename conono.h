#ifndef CANONO_H
#define CANONO_H
#include<math.h>
#include<iostream>
#include <QGraphicsItem>
#include <QPainter>
using namespace std;

class canonO:public QGraphicsItem
{
private:
    float d ;
    float Ho ;
    float Xo ;
    float Yo ;
    float d0 ;
public:
    canonO(float distancia,float alturaof);
    float getD() const;
    float getYo() const;
    float getD0() const;
    float getXo() const;
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);

};

#endif // CANONO_H
