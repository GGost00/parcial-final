#ifndef DISPARO_H
#define DISPARO_H
#include <QGraphicsItem>
#include "canond.h"
#include "conono.h"
#include "balao.h"
#include "balad.h"
#include <math.h>
#define G 9.81
#define pi 3.141617

class disparo: public QGraphicsItem
{
private:
    *disparoO1 = new balaD();
    *disparoD1 = new balaO();
    canonO *disparoO ;
    canonD *disparoD ;
public:
    disparo(float distancia,float Hoo,float Hod);
    void DisparoOfensivo(canonO disparoO,canonD disparoD, int Voo,int cantidad);
    void DisparoDefensivo(canonO disparoO,canonD disparoD, int Voo,int cantidad);
    void DefensaDefensivo1(canonO disparoO,canonD disparoD,int cantidad);
    void ContraAtaqueOf(canonO disparoO,canonD disparoD,int cantidad);
};

#endif // DISPARO_H
