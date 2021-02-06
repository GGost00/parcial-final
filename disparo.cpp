#include "disparo.h"
Disparo::Disparo() {
    x = 0;
    y = 0;
    V0 = 0;
   angle = 0;
   f_time = 0;
   this->tipo = "";
}
std::string Disparo::getTipo() const
{
    return tipo;
}

Disparo::Disparo(float xi, float yi, float posx, float posy, float vx_, float vy_, int angle_, float Tiempo_Final_, float Radio_Impacto_, std::string tipo) {
    x_i = xi;
    y_i = yi;
    x = posx;
    y = posy;
    Vx = vx_;
    Vy = vy_;
    angle = angle_;
    f_time = Tiempo_Final_;
    Radio_Impacto = Radio_Impacto_;
    this->tipo = tipo;
}
Disparo::Disparo(int velocidad, int angle_, std::string tipo) {
    V0 = velocidad;
    angle = angle_;
    this->tipo = tipo;
}
Disparo::~Disparo() {

}

QRectF Disparo::boundingRect() const {
    return QRectF(-2, -2, 4, 4);
}
void Disparo::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {

    if(tipo == "d")
        painter->setPen(QPen(Qt::green,  2, Qt::DotLine));
    else if(tipo == "o")

        painter->setPen(QPen(Qt::red,  2, Qt::DotLine));

    painter->drawEllipse(boundingRect().center(), Radio_Impacto, Radio_Impacto);
    painter->setPen(QPen());
    painter->setBrush(Qt::black);
    painter->drawEllipse(boundingRect());
}

float Disparo::getRadio_Impacto() const
{
    return Radio_Impacto;
}

void Disparo::set_Posicion_Final() {
    x = x_i + Vx*f_time;
    y = y_i + Vy*f_time -(0.5*G*f_time*f_time);

    setPos(x, v_limit - y);
}

void Disparo::setX(float value) {
    x = value;
}
void Disparo::setY(float value) {
    y = value;
}

void Disparo::setAngle(int value) {
    angle = value;
}
void Disparo::setF_time(int value) {
    f_time = value;
}
void Disparo::setV0(int value) {
    V0 = value;
}

float Disparo::getX() const {
    return x;
}
float Disparo::getY() const {
    return y;
}

int Disparo::getAngle() const {
    return angle;
}
float Disparo::getF_time() const {
    return f_time;
}
float Disparo::getV0() {

    V0 = sqrt( pow(Vx ,2) + pow(Vy ,2) );

    return V0;
}

float Disparo::getX_i() const
{
    return x_i;
}
float Disparo::getY_i() const
{
    return y_i;
}
float Disparo::getVx() const
{
    return Vx;
}
float Disparo::getVy() const
{
    return Vy;
}

