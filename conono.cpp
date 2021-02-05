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

canonO::canonO(float distancia,float alturaof)
{
    d=distancia;
    Xo=0;
    Ho=alturaof;
    Yo = Ho;
    d0 = 0.05*d;

}


