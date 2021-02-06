#include "conono.h"

float canonO::getYo() const
{
    return Yo;
}

float canonO::getD0() const
{
    return d0;
}

float canonO::getXo() const
{
    return Xo;
}

QRectF canonO::boundingRect() const
{
        return QRectF(-Xo,-Yo,5,5);
}

void canonO::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::blue);
     painter->drawEllipse(boundingRect().center(),d0+5,d0+5);
    painter->setBrush(Qt::darkYellow);
    painter->drawRect(boundingRect());
}

float canonO::getD() const
{
    return d;
}

canonO::canonO(float distancia,float alturaof)
{
    d=distancia;
    Xo=0;
    Ho=alturaof;
    Yo = Ho;
    d0 = 0.025*d;

}


