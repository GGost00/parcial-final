#ifndef DISPARO_H
#define DISPARO_H

#include <QObject>
#include <QGraphicsItem>
#include <QPainter>
#include <math.h>

#define G 9.81
#define v_limit 720

class Disparo : public QObject, public QGraphicsItem {
    Q_OBJECT
public: //variables
    float x_i, y_i;
    float x, y; //posicion del disparo
    float V0; //velocidad inicial del disparo
    float Vx, Vy;
    float f_time; //tiempo final de impacto
    int angle; //angulo inicial del disparo
    float Radio_Impacto; //radio de impacto ya multiplicado por la distancia

    std::string tipo;

private: //variables

public: //methods
    Disparo(float xi, float yi, float posx, float posy, float vx_, float vy_, int angle_, float Tiempo_Final_, float Radio_Impacto_, std::string tipo);
    Disparo(int velocidad, int angle_, std::string tipo);
    Disparo();
    ~Disparo();

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);

    int getAngle() const;
    float getV0();
    float getF_time() const;
    float getX() const;
    float getY() const;

    void setX(float value);
    void setY(float value);
    void setAngle(int value);
    void setF_time(int value);
    void setV0(int value);

    float getRadio_Impacto() const;

    void set_Posicion_Final();

    float getX_i() const;

    float getY_i() const;

    float getVx() const;

    float getVy() const;

    std::string getTipo() const;

private: //methods

};

#endif // DISPARO_H
