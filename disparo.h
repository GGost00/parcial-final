#ifndef DISPARO_H
#define DISPARO_H
#include <QGraphicsItem>
#include <QGraphicsScene>
#include "canond.h"
#include "conono.h"
#include "balao.h"
#include "balad.h"
#include "esfera.h"
#include <math.h>
#define G 9.81
#define pi 3.141617

class disparo:public QGraphicsItem
{

private:
    balaD  *disparoO1 = new balaD();
    balaO *disparoD1 = new balaO();
    canonO *disparoO ;
    canonD *disparoD ;
    esfera *bala;
public:
    disparo(float distancia,float Hoo,float Hod);
    void DisparoOfensivo( int Voo,int cantidad);
    void DisparoDefensivo( int Voo,int cantidad);
    void DefensaDefensivo1(int cantidad);
    void ContraAtaqueOf(int cantidad);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
};

#endif // DISPARO_H