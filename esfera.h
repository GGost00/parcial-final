#ifndef ESFERA_H
#define ESFERA_H

#include <QGraphicsItem>
#include <QPainter>

class esfera: public QGraphicsItem
{

    int r;
    int posx, posy;
    int vx,vy;

public:
    esfera(int r_, int x, int y);

    int getR() const;
    void setR(int radio);
    int getPosx() const;
    void setPosx(int px);
    int getPosy() const;
    void setPosy(int py);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);

};

#endif // ESFERA_H
