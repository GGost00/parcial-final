#ifndef BALAD_H
#define BALAD_H


class balaD
{
private:
    int angulo;
    int velocidad;
    double tiempo;
public:
    balaD();
    float getAngulo() const;
    void setAngulo(float value);
    float getVelocidad() const;
    void setVelocidad(float value);
    float getTiempo() const;
    void setTiempo(float value);
};

#endif // BALAD_H
