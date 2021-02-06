#ifndef CANON_H
#define CANON_H
#include <QObject>
#include <vector>
#include <math.h>
#include <QGraphicsItem>
#include <QColor>
#include "disparo.h"

#define G 9.81
#define pi 3.141617
#define v_limit 720

class Canon : public QObject, public QGraphicsItem {
    Q_OBJECT
public: //variables

private: //variables
    float posx, posy;
    float Impactos_Multiples;
    float Radio_Impacto;
    float Radio_Impacto_Enemigo;
    float distancia;

    std::string tipo;

public: //methods
    Canon(float x_, float y_, float imp_, std::string type);
    Canon(float imp_, std::string type);

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);

    std::vector <Disparo *> Generar_Disparos_Ofencivos(Canon *Objetivo); //puntos 1 y 2 (target es el cañon que se quiere destruir)
    std::vector <Disparo *> Generar_Disparos_Defencivos(Canon *Origen, Disparo *Objetivo, bool Afecta_Ofencivo); //puntos 3 y 4 (target es el disparo que se quiere destruir y origin es el cañon que los disparó)
    std::vector<Disparo *> Generar_Contraataque_Ofencivos(Canon *Canon_Defencivo, Disparo *Disparo_Defencivo, Disparo *Disparo_Ofencivo); //punto 5 (target_canyon es el cañon que se quiere destruir, target_shot es el disparo que hay que destruir, y mine es el disparo que hayq ue proteger)

    bool Impacta(Canon *Origen, Disparo *Ofencivo); //confirma que el diaparo impacta su destino (el cañon que realiza este calculo es el destino (this) )
    bool Impacta(Canon *Ofencivo, Disparo *Of, Canon *Defencivo, Disparo *def);

    float getPosx() const;
    float getPosy() const;
    void setPosx(float value);
    void setPosy(float value);

    float getDistancia() const;
    void setDistancia(Canon *Destino);
    void setDistancia(float dis);

    float getRadio_Impacto() const;
    void setRadio_Impacto();

    void setRadio_Impacto_Enemigo(float value);

    float getImpactos_Multiples() const;

private:

signals:

};

#endif // CANON_H
