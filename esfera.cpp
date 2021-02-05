#include "esfera.h"

esfera::esfera(int r_, int x, int y,float vx_,float vy_)
{
    r = r_;
    posx = x;
    posy = y;
    vx=vx_;
    vy=vy_;
    setPos(posx,posy);
}
int esfera::getR() const
{
    return r;
}

void esfera::setR(int value)
{
    r = value;
}

int esfera::getPosx() const
{
    return posx;
}

void esfera::setPosx(int value)
{
    posx = value;
}

int esfera::getPosy() const
{
    return posy;
}

void esfera::setPosy(int value)
{
    posy = value;
}

void esfera::Actualizar(float V0o,float angle,int Y0,int tf)
{
    int t;
    float Vxo,Vy0;
    Vxo = V0o*cos(angle*pi/180);
    Vy0 = V0o*sin(angle*pi/180);
    for(t = 0;t>=tf ; t++){
        posx = Vxo*t;
        posy = (Y0 + Vy0*t -(0.5*G*t*t));
        setPos(posx,posy);
    }
}

QRectF esfera::boundingRect() const
{
    return QRectF(-r,-r,2*r,2*r);
}

void esfera::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::darkYellow);
    painter->drawEllipse(boundingRect());

}
