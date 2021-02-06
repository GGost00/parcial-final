#include "esfera.h"

esfera::esfera(int r_, int x, int y,float V,int Angle)
{
    r = r_;
    posx = x;
    posy = y;
    V0o=V;
    dt=1;
    angle=Angle;
    timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(Actualizar()));
    timer->start(10);

}

esfera::~esfera()
{
    delete timer;
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

void esfera::Actualizar()
{
    dt+=1;
    float Vxo,Vy0;
    Vxo = V0o*cos(angle*pi/180);
    Vy0 = V0o*sin(angle*pi/180);
    posx = posx + Vxo*dt;
    posy = (posy + Vy0*dt -(0.5*G*dt*dt));

    setPos(posx,posy);
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
