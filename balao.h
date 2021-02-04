#ifndef BALAO_H
#define BALAO_H


class balaO
{
private:
    int angulo;
    int velocidad;
    double tiempo;
public:
    balaO();
    float getAngulo() const;
    void setAngulo(float value);
    float getVelocidad() const;
    void setVelocidad(float value);
    float getTiempo() const;
    void setTiempo(float value);
};

#endif // BALAO_H
