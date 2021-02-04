#ifndef CANOND_H
#define CANOND_H
#include<math.h>
#include<iostream>
using namespace std;

class canonD
{
private:
    float d ;
    float Hd;
    float Xd;
    float Yd;
    float d0;
public:
    canonD(float distancia,float alturaof);
    float getXd() const;
    float getYd() const;
    float getD0() const;
    float getD() const;
};

#endif // CANOND_H
