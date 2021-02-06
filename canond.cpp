#include "canond.h"

float canonD::getXd() const
{
    return Xd;
}

float canonD::getYd() const
{
    return Yd;
}

float canonD::getD0() const
{
    return d0;
}

float canonD::getD() const
{
    return d;
}

QRectF canonD::boundingRect() const
{
    return QRectF(-Xd,-Yd,5,5);
}

void canonD::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::green);
     painter->drawEllipse(boundingRect().center(),d0+5,d0+5);
    painter->setBrush(Qt::darkYellow);
    painter->drawRect(boundingRect());

}

canonD::canonD(float distancia,float alturadf)
{
    d=distancia;
    Hd=alturadf;
    Xd = -d;
    Yd = Hd;
    d0 = 0.05*d;

}
