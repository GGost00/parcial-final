#ifndef ESFERA_H
#define ESFERA_H
#include <QObject>
#include <QGraphicsItem>
#include <QPainter>
#include <QTimer>
#include <math.h>

class esfera: public QObject,public QGraphicsItem
{
Q_OBJECT
private:
    int r;
    int posx, posy;
    int V0o;
    float G =9.81;
    float pi = 3.141617;
    float dt=0.1;//deltatiempo
    int angle;
    QTimer *timer;

public slots:
    void Actualizar();
public:

    esfera(int r_, int x, int y,float V,int Angle);
    ~esfera();

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
