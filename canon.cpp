#include "canon.h"

float Canon::getImpactos_Multiples() const
{
    return Impactos_Multiples;
}

Canon::Canon(float x_, float y_, float imp_, std::string tipo) {
    posx = x_;
    posy = y_;
    Impactos_Multiples = imp_;
    distancia = 100;
    this->tipo = tipo;
}
Canon::Canon(float imp_, std::string tipo) {
    posx = 0;
    posy = 0;
    Impactos_Multiples = imp_;
    distancia = 100;
    this->tipo = tipo;
}

QRectF Canon::boundingRect() const {
    return QRectF(-5, -5, 10, 10);
}
void Canon::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    painter->setPen(QPen(Qt::yellow,  2, Qt::SolidLine));
    painter->drawEllipse(boundingRect().center(), distancia*Radio_Impacto_Enemigo, distancia*Radio_Impacto_Enemigo);
    painter->setPen(QPen());
    painter->setBrush(Qt::blue);
    painter->drawRect(boundingRect());
}

std::vector<Disparo *> Canon::Generar_Disparos_Ofencivos(Canon *Objetivo) {
    setDistancia(Objetivo);
    setRadio_Impacto(); //calcula la distancia al objetivo y en base a eso el radio de impacto

    std::vector<Disparo *> aux;

    int flag = 0; //para romper los ciclos cuando haye los 3 disparos
    float x, y; //posicion del proyectil
    float Vx, Vy; //velocidades en x y y del proyectil
    int V0 = 0; //velocidad inicial del proyectil
    float t = 0;
    int angle = 1; //angulo del proyectil

    for(V0 = 5; V0 < 1000; V0 += 5){ //se va aumentando la velocidad de 5 en 5

        for(angle = 1; angle < 90; angle++){ // se aumenta el  angulo de 1 en 1 hasta que sea 90

            if(posx < Objetivo->getPosx()){ //si el cañon esta ubicado antes del objetivo
                Vx = V0*cos(angle*pi/180);
                Vy = V0*sin(angle*pi/180);
            }
            else if (posx > Objetivo->getPosx()){ //si el cañon esta ubicado despues del objetivo
                Vx = V0*cos((angle+90)*pi/180);
                Vy = V0*sin((angle+90)*pi/180);
            }

            x = 0.0;
            y = 0.0;

            for(t = 0; t < 90 ; t += 0.1){ // se aumenta el tiempo de segundo en segundo

                x = posx + Vx*t;
                y = posy + Vy*t -(0.5*G*t*t);

                if(sqrt(pow((Objetivo->getPosx() - x),2)+pow((Objetivo->getPosy() - y),2)) < Radio_Impacto){ //si la distancia entre el proytectil y el destino es menos que el radio de impacto se cuenta como exitoso

                    if(y<0) //es posible que impacte habiendo pasado un poco del suelo (como si se enterrara, pero me parece mejor que se registre como si hubiera impactado en 0)
                        y = 0;

                    aux.push_back(new Disparo(posx, posy, x, y, Vx, Vy, angle, t, Radio_Impacto, tipo)); // si sale un disparo exitoso se añade al vector que de va a retornar

                    flag++;
                    V0 += 10; //se usaba para crear disparos que no fueran muy parecidos los unos a los otros, pero es probable que ya no la use
                    break;
                }

               // if(y < 0) break; // si se pasa del suelo xd
                if(y < -1*(this->getRadio_Impacto()*2)) break;

            }

            if(flag == 3) break;

        }

        if(flag == 3) break;

    }
    return aux;
}
std::vector<Disparo *> Canon:: Generar_Disparos_Defencivos(Canon *Origen, Disparo *Objetivo, bool Afecta_Ofencivo) {

    std::vector<Disparo *> disparos; //para retornar

    setDistancia(Origen);
    setRadio_Impacto(); //calcula la distancia entre los cañones, y en base a eso el radio de impacto

    if(Afecta_Ofencivo){

        int flag = 0;//para romper los ciclos cuando haye los 3 disparos

        float x, y; //coordenas del disparo defensivo
        int V0 = 0; //velocidad inicial del disparo defensivo
        float Vx, Vy; //velocidades en x y y del disparo defensivo
        int angle = 1; //angulo del disparo defensivo

        float x_ofencivo, y_ofencivo; //coordenadas del disparo ofensivo
        float Vx_ofencivo, Vy_ofencivo; //velocidades en x y y del disparo ofensivo

        float t = 0;

        Vx_ofencivo = Objetivo->getVx();
        Vy_ofencivo = Objetivo->getVy();


        for(V0 = 50;  V0 < 1000; V0 += 1){  //se va aumentando la velocidad de 1 en 1; empieza en 50 para protejer al cañon defensivo

            for(angle = 1; angle < 90; angle++){ // se aumenta el  angulo de 1 en 1 hasta que sea 90

                Vx = V0*cos((angle+90)*pi/180);
                Vy = V0*sin((angle+90)*pi/180);

                x = 0.0;
                y = 0.0;
                x_ofencivo = 0.0;
                y_ofencivo = 0.0;

                for(t = 0; t < 90; t+=0.1){// se aumenta el tiempo de segundo en segundo

                    x_ofencivo = Origen->getPosx() + Vx_ofencivo*(t+2);
                    y_ofencivo = Origen->getPosy() + Vy_ofencivo*(t+2) -(0.5*G*(t+2)*(t+2)); //note que se tienen en cuenta los 2 segundos que tardo la informacion en llegar

                    x = posx + Vx*t;
                    y = posy + Vy*t -(0.5*G*t*t);

                    if(sqrt(pow((x_ofencivo - x), 2)+pow((y_ofencivo - y), 2)) < Radio_Impacto && sqrt(pow((Origen->getPosx() - x), 2)+pow((Origen->getPosy() - y), 2)) > Radio_Impacto){
                        //si la distancia entre el proytectil y el destino es menos que el radio de impacto Y la distanciancia entre el proyectil y el origen es mayor que el radio de impacto se cuenta como exitoso

                        if(y<0)
                            y = 0;

                        disparos.push_back(new Disparo(posx, posy, x, y, Vx, Vy, angle, t, Radio_Impacto, tipo)); // si sale un disparo exitoso se añade al vector que de va a retornar (se toma le tiempo desde que se dispara*)

                        flag ++;
                        V0 += 10; //se usaba para crear disparos que no fueran muy parecidos los unos a los otros, pero es probable que ya no la use
                        break;
                    }

                    //if(y < 0) break; // si se pasa del suelo
                    if(y < -1*(this->getRadio_Impacto()*2)) break;

                    if(flag == 3) break;

                }

                if(flag == 3) break;

            }

            if(flag == 3) break;

        }

    }
    else{ //cuando el cañon ofensivo no importa, y el cañon defensivo mo comprueba si lo impacta o no

        int flag = 0;//para romper los ciclos cuando haye los 3 disparos
        float x, y; //coordenas del disparo defensivo
        int V0 = 0; //velocidad inicial del disparo defensivo
        float Vx, Vy; //velocidades en x y y del disparo defensivo
        int angle = 1; //angulo del disparo defensivo

        float x_ofencivo, y_ofencivo; //coordenadas del disparo ofensivo
        float Vx_ofencivo, Vy_ofencivo; //velocidades en x y y del disparo ofensivo

        float t = 0;

        Vx_ofencivo = Objetivo->getVx();
        Vy_ofencivo = Objetivo->getVy();

        for(V0 = 100; V0 < 1000; V0 += 1){  //se va aumentando la velocidad de 1 en 1; empieza en 100 para que el disparo se destruya lejos del cañon defensivo

            for(angle = 1; angle < 90; angle++){ // se aumenta el  angulo de 1 en 1 hasta que sea 90

                Vx = V0*cos((angle+90)*pi/180);
                Vy = V0*sin((angle+90)*pi/180);

                x = 0.0;
                y = 0.0;
                x_ofencivo = 0.0;
                y_ofencivo = 0.0;

                for(t = 0; t < 90; t+=0.1){// se aumenta el tiempo de segundo en segundo

                    x_ofencivo = Origen->getPosx() + Vx_ofencivo*(t+2);
                    y_ofencivo = Origen->getPosy() + Vy_ofencivo*(t+2) - (0.5*G*(t+2)*(t+2)); //note que se tienen en cuenta los 2 segundos que tardo la informacion en llegar

                    x = posx + Vx*t;
                    y = posy + Vy*t - (0.5*G*t*t);

                    if(sqrt(pow((x_ofencivo - x),2)+pow((y_ofencivo - y), 2)) < Radio_Impacto){ //si la distancia entre el proytectil y el destino es menos que el radio de impacto se cuenta como exitoso

                        if(y<0)
                            y = 0;

                        disparos.push_back(new Disparo(posx, posy, x, y, Vx, Vy, angle, t, Radio_Impacto, tipo)); // si sale un disparo exitoso se añade al vector que de va a retornar (se toma le tiempo desde que se dispara*)

                        flag ++;
                        V0 += 10; //se usaba para crear disparos que no fueran muy parecidos los unos a los otros, pero es probable que ya no la use
                        break;
                    }

                    //if(y < 0) break; // si se pasa del suelo
                    if(y < -1*(this->getRadio_Impacto()*2)) break;

                    if(flag == 3) break;

                }

                if(flag == 3) break;

            }

            if(flag == 3) break;

        }
    }
    return disparos;
}
std::vector<Disparo *> Canon::Generar_Contraataque_Ofencivos(Canon *Canon_Defencivo, Disparo *Disparo_Defencivo, Disparo *Disparo_Ofencivo) {

    std::vector<Disparo *> disparos; //para retornar

    //calcula la distancia entre los cañones, y en base a eso el radio de impacto
    setDistancia(Canon_Defencivo);
    Canon_Defencivo->setDistancia(this);
    setRadio_Impacto();
    Canon_Defencivo->setRadio_Impacto();

    int flag = 0;//para romper los ciclos cuando haye los 3 disparos

    float x, y; //coordenas del disparo que estamos generando
    int V0; //velocidad inicial del disparo que estamos generando
    float Vx, Vy; //velocidades en x y y del disparo que estamos generando
    int angle = 1; //angulo del disparo que estamos generando

    float x_defencivo, y_defencivo; //coordenadas del disparo que va a destruir mi disparo
    float Vx_defencivo, Vy_defencivo; //velocidades en x y y del disparo que va a destruir mi disparo

    float x_ofencivo, y_ofencivo;  //coordenadas del disparo que dispare inicialmente
    float Vx_ofencivo, Vy_ofencivo; //velocidades en x y y del disparo que dispare inicialmente

    float t = 0;
    int d1 = 3; //delay 1
    int d2 = 1; //delay 2

    Vx_defencivo = Disparo_Defencivo->getVx();
    Vy_defencivo = Disparo_Defencivo->getVy();

    Vx_ofencivo = Disparo_Ofencivo->getVx();
    Vy_ofencivo = Disparo_Ofencivo->getVy();

    for(V0 = 1; V0 < 500; V0 += 1) {  //se va aumentando la velocidad de 5 en 5

        for(angle = 1; angle < 90; angle++) { // se aumenta el  angulo de 1 en 1 hasta que sea 90

            Vx = V0*cos((angle)*pi/180);
            Vy = V0*sin((angle)*pi/180);

            x = 0.0;
            y = 0.0;
            x_defencivo = 0.0;
            y_defencivo = 0.0;
            x_ofencivo = 0.0;
            y_ofencivo = 0.0;

            for(t = 0; t < 90; t += 0.1){// se aumenta el tiempo de segundo en segundo

                x_ofencivo = posx + Vx_ofencivo*(t+d1);
                y_ofencivo = posy + Vy_ofencivo*(t+d1) - (0.5*G*(t+d1)*(t+d1));  // *** no estoy seguro de los delays ***

                x_defencivo = Canon_Defencivo->getPosx() + Vx_defencivo*(t+d2);
                y_defencivo = Canon_Defencivo->getPosy() + Vy_defencivo*(t+d2) - (0.5*G*(t+d2)*(t+d2));

                x = posx + Vx*t;
                y = posy + Vy*t - (0.5*G*t*t);

                if(sqrt(pow((x_defencivo - x),2)+pow((y_defencivo - y), 2)) <= Radio_Impacto && sqrt(pow((x_ofencivo - x),2)+pow((y_ofencivo - y), 2)) > Radio_Impacto){
                    // si destruye el proyectil que queremos destruir pero no destruye el que disparamos originalmente

                    disparos.push_back(new Disparo(posx, posy, x, y, Vx, Vy, angle, t, Radio_Impacto, tipo)); // si sale un disparo exitoso se añade al vector que de va a retornar (se toma le tiempo desde que se dispara*)

                    flag ++;
                    //V0 += 10; //se usaba para crear disparos que no fueran muy parecidos los unos a los otros, pero es probable que ya no la use
                    break;
                }

                if(sqrt(pow((x_ofencivo - x_defencivo), 2)+pow((y_ofencivo - y_defencivo), 2)) < Canon_Defencivo->getRadio_Impacto()) break; //si el proyectil defensivo impacta con el ofensivo

                if(y < -1*(this->getRadio_Impacto()*2)) break;

                if(flag == 3) break;

            }

            if(flag == 3) break;

        }

        if(flag == 3) break;

    }

    return disparos;
}

bool Canon::Impacta(Canon *Origen, Disparo *Ofencivo) {

    float x, y; //posicion del proyectil
    float Vx = Ofencivo->getVx(), Vy = Ofencivo->getVy(); //velocidades en x y y del proyectil
    //int V0 = ofense->getV0(); //velocidad inicial del proyectil
    float t = 0;

//    if(origin.getPosx() > posx){ //si el origen esta ubicado antes del objetivo
//        Vx = V0*cos(ofense.getAngle()*pi/180);
//        Vy = V0*sin(ofense.getAngle()*pi/180);
//    }
//    else if (origin.getPosx() < posx){ //si el origen esta ubicado despues del objetivo
//        Vx = V0*cos((ofense.getAngle()+90)*pi/180);
//        Vy = V0*sin((ofense.getAngle()+90)*pi/180);
//    }

    //Vx = V0*cos(ofense->getAngle()*pi/180);
    //Vy = V0*sin(ofense->getAngle()*pi/180);

    Origen->setDistancia(this);
    Origen->setRadio_Impacto(); //calcula la distancia entre los cañones, y en base a eso el radio de impacto

    for(t = 0; ; t += 0.1){ // se aumenta el tiempo de segundo en segundo

        x = Origen->getPosx() + Vx*t;
        y = Origen->getPosy() + Vy*t -(0.5*G*t*t);

        if(sqrt(pow((posx - x), 2)+pow((posy - y), 2)) < Ofencivo->getRadio_Impacto()) //si la distancia entre el proytectil y el destino es menos que el radio de impacto se cuenta como un impacto
            return true;

        if(y < -1*(Ofencivo->getRadio_Impacto()*2))
            break;

    }
    return false;
}
bool Canon::Impacta(Canon *ofencivo, Disparo *of, Canon *defencivo, Disparo *def) {

    float x_defencivo, y_defencivo; //coordenas del disparo defensivo
    float Vx_defencivo, Vy_defencivo; //velocidades en x y y del disparo defensivo

    float x_ofencivo, y_ofencivo; //coordenadas del disparo ofensivo
    float Vx_ofencivo, Vy_ofencivo; //velocidades en x y y del disparo ofensivo

    Vx_defencivo = def->getV0()*cos((def->getAngle()+90)*pi/180);
    Vy_defencivo = def->getV0()*sin((def->getAngle()+90)*pi/180);

    Vx_ofencivo = of->getV0()*cos((of->getAngle())*pi/180);
    Vy_ofencivo = of->getV0()*sin((of->getAngle())*pi/180);

    ofencivo->setDistancia(defencivo);
    ofencivo->setRadio_Impacto();
    defencivo->setDistancia(ofencivo);
    defencivo->setRadio_Impacto();

    for(int t = 0; ; t++){// se aumenta el tiempo de segundo en segundo

        x_ofencivo = ofencivo->getPosx() + Vx_ofencivo*(t+2);
        y_ofencivo = ofencivo->getPosy() + Vy_ofencivo*(t+2) -(0.5*G*(t+2)*(t+2)); //note que se tienen en cuenta los 2 segundos que tardo la informacion en llegar

        x_defencivo = defencivo->getPosx() + Vx_defencivo*t;
        y_defencivo = defencivo->getPosy() + Vy_defencivo*t -(0.5*G*t*t);

        if(sqrt(pow((x_ofencivo - x_defencivo), 2)+pow((y_ofencivo - y_defencivo), 2)) < defencivo->getRadio_Impacto()) //si la distancia entre el proytectil y el destino es menos que el radio de impacto se cuenta como exitoso
            return true;


        if(y_defencivo < -1*(defencivo->getRadio_Impacto()*2) || y_ofencivo < -1*(ofencivo->getRadio_Impacto()*2)) break; // si se pasa del suelo

    }

    return false;
}

float Canon::getPosx() const {
    return posx;
}
float Canon::getPosy() const {
    return posy;
}
void Canon::setPosx(float value) {
    posx = value;

    setX(posx);
    //setPos(posx, posy);
}
void Canon::setPosy(float value) {
    posy = value;

    setY(v_limit - posy);
    //setPos(posx, posy);
}

float Canon::getDistancia() const {
    return distancia;
}
void Canon::setDistancia(Canon *Destino) {
    distancia = abs(posx - Destino->getPosx()); //calcula la distancia entre los 2 cañones
}
void Canon::setDistancia(float dis) {
    distancia = dis;
}

float Canon::getRadio_Impacto() const {
    return Radio_Impacto;
}
void Canon::setRadio_Impacto() {
    Radio_Impacto = Impactos_Multiples*distancia;
}

void Canon::setRadio_Impacto_Enemigo(float value)
{
    Radio_Impacto_Enemigo = value;
}
