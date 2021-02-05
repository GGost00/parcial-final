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

canonD::canonD(float distancia,float alturadf)
{
    d=distancia;
    Hd=alturadf;
    Xd = d;
    Yd = Hd;
    d0 = 0.025*d;

}
