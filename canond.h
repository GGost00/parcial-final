#ifndef CANOND_H
#define CANOND_H
#include<math.h>
#include<iostream>
#include <QGraphicsItem>
#include <QPainter>
using namespace std;

class canonD:public QGraphicsItem
{
private:
    float d ;
    float Hd;
    float Xd;
    float Yd;
    float d0;
public:
    canonD(float distancia,float alturaof);
    float getXd() const;
    float getYd() const;
    float getD0() const;
    float getD() const;
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
};

#endif // CANOND_H
