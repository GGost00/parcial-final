#ifndef CANONO_H
#define CANONO_H
#include<math.h>
#include<iostream>
using namespace std;

class canonO
{
private:
    float d ;
    float Ho ;
    float Xo ;
    float Yo ;
    float d0 ;
public:
    canonO(float distancia,float alturaof);

    float getYo() const;
    float getD0() const;
    float getXo() const;
};

#endif // CANONO_H
