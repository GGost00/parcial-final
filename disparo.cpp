#include "disparo.h"


disparo::disparo(float distancia,float Hoo,float Hod, int posx_,int posy_,int V0_,int Angulo_,int _Tf)
{
     disparoO = new canonO(distancia,Hoo);
     disparoD = new canonD(distancia,Hod);
     posx=posx_;
     posy=posy_;
     V0=V0_;
     Angulo=Angulo_;
     Tf=_Tf;

}


void disparo::generar_disparo(int posx, int posy, int V0, int Angulo)
{
    esf = new esfera(5,posx,posy,V0,Angulo);
    scene()->addItem(esf);
}

void disparo::DisparoOfensivo(int Voo, int cantidad)
{
    int flag = 0;
    float x,y;
    float Vxo,Vy0;
    int V0o = 0;
    int t = 0;
    int angle = 0;
    for(V0o = Voo; ; V0o += 5){
        for(angle = 0; angle < 90; angle++){
            Vxo = V0o*cos(angle*pi/180);
            Vy0 = V0o*sin(angle*pi/180);
            x = 0.0;
            y = 0.0;
            for(t = 0; ; t++){
                x = Vxo*t;
                y = disparoO->getYo() + Vy0*t -(0.5*G*t*t);
                if(sqrt(pow((disparoD->getXd() - x),2)+pow((disparoD->getYd() - y),2)) < disparoO->getD0()){
                    if(y<0) y = 0;
                    if(cantidad==1){
                        if (t>2){
                            cout<<"disparo ofensivo--------------"<<endl;
//                            ImprimirResultados1(angle, V0o, x, y, t);
                            disparoO1->setAngulo(angle);
                            disparoO1->setVelocidad(V0o);
                            disparoO1->setTiempo(t);
                            flag += 1;
                            break;
                        }

                    }else{
//                    ImprimirResultados1(angle, V0o, x, y, t);
                        Angulo=angle;
                        V0=V0o;
                        Tf=t;
                        generar_disparo(posx,posy,V0,Angulo);
                    flag += 1;
                    V0o += 50;
                    break;
                    }
                }
                if(y < 0){
                    break;
                }
            }
            if(flag == cantidad) break;

        }
        if(flag == cantidad) break;
    }
}

void disparo::DisparoDefensivo(int Voo, int cantidad)
{

    int flag = 0;
    float x,y;
    float Vxo,Vy0;
    int V0o = 0;
    int t = 0;
    int angle = 0;
    for(V0o = Voo; ; V0o += 5){
        for(angle = 0; angle < 90; angle++){
            Vxo = V0o*cos((angle+90)*pi/180);
            Vy0 = V0o*sin((angle+90)*pi/180);
            x = 0.0;
            y = 0.0;
            for(t = 0; ; t++){
                x = Vxo*t;
                y = disparoD->getYd() + Vy0*t -(0.5*G*t*t);
                if(sqrt(pow((disparoO->getXo() - x),2)+pow((disparoO->getYo() - y),2)) < disparoD->getD0()){
                    if(y<0) y = 0;
                    if(cantidad==1){
                        if (t>2){
                            disparoD1->setAngulo(angle);
                            disparoD1->setVelocidad(V0o);
                            disparoD1->setTiempo(t);
                            flag += 1;
                            break;
                        }
                    }else{
//                    ImprimirResultados1(angle, V0o, x, y, t);

                    flag += 1;
                    V0o += 50;
                    break;
                    }
                }
                if(y < 0){
                    break;
                }
            }
            if(flag == cantidad) break;

        }
        if(flag == cantidad) break;
    }
}

void disparo::DefensaDefensivo1(int cantidad)
{
    DisparoOfensivo(1,1);
    float tiempoRes =disparoO1->getTiempo()-2;
    float xb,yb;
    int flag = 0;
    float x,y;
    float Vxo,Vy0,vxoo,vyoo;
    int vbd = 0;
    float t = tiempoRes/2;
    int anglbd = 0;
    vxoo=disparoO1->getVelocidad()*cos((disparoO1->getAngulo())*pi/180);
    vyoo=disparoO1->getVelocidad()*sin((disparoO1->getAngulo())*pi/180);
    xb=vxoo*(t +2);
    yb=disparoO->getYo()+vyoo*(t +2)-((1/2)*G*(pow(t,2)));




    for(vbd = 1; ; vbd += 1){
        for(anglbd = 0; anglbd < 90; anglbd++){
            Vxo = abs(vbd*cos((anglbd+90)*pi/180));
            Vy0 = abs(vbd*sin((anglbd+90)*pi/180));
            x = 0.0;
            y = 0.0;

            x = Vxo*(t +2);
            y = disparoD->getYd() + Vy0*(t+2) -(0.5*G*(pow(t,2)));
            if(sqrt(pow((xb - x),2)+pow((yb - y),2)) < disparoO->getD0()){
                if(y<0) y = 0;
                if(cantidad==1){
                    if (t>3){
                        cout<<"disparo defensivo--------------"<<endl;
//                        ImprimirResultados1(anglbd+90, vbd, x, y, t);
                        disparoD1->setAngulo(anglbd);
                        disparoD1->setVelocidad(vbd);
                        disparoD1->setTiempo(t);
                        flag += 1;
                        break;
                    }
                }else{
//                    ImprimirResultados1(anglbd+90, vbd, x, y, t);
                    tiempoRes=tiempoRes/2;
                    t+=tiempoRes/2;
                    flag += 1;
                    vbd =0;
                    break;
                }
            }
            if(y < 0){
                break;
            }


        }
        if(flag == cantidad) break;
    }
}

void disparo::ContraAtaqueOf( int cantidad)
{
    DefensaDefensivo1(1);


    float tiempoRes =disparoD1->getTiempo()-1;
    float xb,yb;
    int flag = 0;
    float x,y;
    float Vxo,Vy0,vxoo,vyoo;
    int vbd = 0;
    float t = tiempoRes/2;
    int anglbd = 0;
    vxoo=disparoD1->getVelocidad()*cos((disparoD1->getAngulo()+90)*pi/180);
    vyoo=disparoD1->getVelocidad()*sin((disparoD1->getAngulo()+90)*pi/180);
    xb=disparoD->getD()+ vxoo*(t +1);
    yb=disparoO->getYo()+vyoo*(t +1)-((1/2)*G*(pow(t,2)));




    for(vbd = 1; ; vbd += 1){
        for(anglbd = 0; anglbd < 90; anglbd++){
            Vxo = abs(vbd*cos((anglbd)*pi/180));
            Vy0 = abs(vbd*sin((anglbd)*pi/180));
            x = 0.0;
            y = 0.0;

            x = Vxo*(t +1);
            y = disparoO->getYo() + Vy0*(t+1) -(0.5*G*(pow(t,2)));
            if(sqrt(pow((xb - x),2)+pow((yb - y),2)) < disparoD->getD()*0.005){
                if(y<0) y = 0;
                if(cantidad==1){
                    if (t>3){
                        disparoD1->setAngulo(anglbd);
                        disparoD1->setVelocidad(vbd);
                        disparoD1->setTiempo(t);
                        flag += 1;
                        break;
                    }
                }else{
//                    ImprimirResultados1(anglbd, vbd, x, y, t);
                    tiempoRes=tiempoRes/2;
                    t+=tiempoRes/2;
                    flag += 1;
                    vbd =0;
                    break;
                }
            }
            if(y < 0){
                break;
            }


        }
        if(flag == cantidad) break;
    }
}

QRectF disparo::boundingRect() const
{
    return QRectF(-5,-5,10,10);
}

void disparo::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::yellow);
    painter->drawEllipse(boundingRect());
    painter->setBrush(Qt::darkYellow);
    painter->drawEllipse(boundingRect().center(),20,20);

}
