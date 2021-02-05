#ifndef ESFERA_H
#define ESFERA_H

#include <QGraphicsItem>
#include <QPainter>
#include <math.h>

class esfera: public QGraphicsItem
{

    int r;
    int posx, posy;
    int vx,vy;
    float G =9.81;
    float pi = 3.141617;

public:
    esfera(int r_, int x, int y,float vx_,float vy_);

    int getR() const;
    void setR(int radio);
    int getPosx() const;
    void setPosx(int px);
    int getPosy() const;
    void setPosy(int py);
    void Actualizar(float V0o,float angle,int Y0,int tf);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);

};

#endif // ESFERA_H
