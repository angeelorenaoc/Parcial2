#include "bala.h"
Bala::Bala()
{

}

float Bala::getV0() const
{
    return v0;
}

void Bala::ImprimirResultados(int ang, int v00, float x, float y, float t)
{
    cout << "Impacto con un angulo de " << ang << " grados" << endl;
    cout << "Impacto con velocidad incial " << v00 << endl;
    cout << "Impacto con posicion x: " << x << endl;
    cout << "Impacto con posicion y: " << y << endl;
    cout << "Con tiempo: " << t << endl;
    cout << endl;
}

void Bala::DisparoOfensivo(Canion DO, Canion DD, int V0_)
{
    int flag = 0;
//    float x,y;
    float Vxo,Vy0;
    int V0o = 0;
    t = 0;
    angulo = 0;
    for(V0o = V0_; ; V0o+=5){
        for(angulo = 0; angulo < 90; angulo++){
            Vxo = V0o*cos(angulo*pi/180);
            Vy0 = V0o*sin(angulo*pi/180);
            xf = 0.0;
            yf = 0.0;
            for(t = 0; ; t++){
                xf = Vxo*t;
                yf = DO.getY0() + Vy0*t -(0.5*G*t*t);
                if(sqrt(pow((DD.getX0() - xf),2)+pow((DD.getY0() - yf),2)) < DO.getD0()){
                    if(yf<0) yf = 0;
                    ImprimirResultados(angulo, V0o, xf, yf, t);
                    flag += 1;
                    break;
                }
                if(yf < 0){
                    break;
                }
            }
            if(flag == 3) break;

        }
        if(flag == 3) break;
    }
    if(flag != 3){
        cout << "No impacto en los disparos esperados"<< endl;
    }
}

void Bala::DisparoDefensivo(Canion DO, Canion DD, int V0_)
{
    int flag = 0;
    float e = 0;
    float Vxo,Vy0;
    int V0o = 0;
    int t = 0;
    angulo = 0;
    for(V0o = V0_; ; V0o+=5){
        for(angulo = 0; angulo < 90; angulo++){
            Vxo = V0o*cos((angulo+90)*pi/180);
            Vy0 = V0o*sin((angulo+90)*pi/180);
            xf = 0.0;
            yf = 0.0;
            for(t = 0; ; t++){
                xf = DD.getX0()+Vxo*t;
                yf = DD.getY0() + Vy0*t -(0.5*G*t*t);
                e = (sqrt(pow((DO.getX0() - xf),2)+pow((DO.getY0() - yf),2)));
                if(e < DD.getD0()){
                    ImprimirResultados(angulo, V0o, xf, yf, t);
                    flag += 1;
                    break;
                }
                if(yf < 0){
                    break;
                }
            }
            if(flag == 3) break;

        }
        if(flag == 3) break;
    }
    if(flag != 3){
        cout << "No impacto en los disparos esperados"<< endl;
    }
}

void Bala::DisparoDefensivo2(Canion DO, Canion DD, int V00, int anguloo, int vo0)
{
    int flag = 0;
    float x2,y2;
    float Vxo,Vy0, Vxoo,Vyoo;
    int V0o = 0;
    float t = 2.5;
    angulo = 0;
    Vxoo = vo0*cos((anguloo)*pi/180);
    Vyoo = vo0*sin((anguloo)*pi/180);
    for(V0o = V00; ; V0o ++){
        for(angulo = 0; angulo < 90; angulo++){
            Vxo = V0o*cos((angulo+90)*pi/180);
            Vy0 = V0o*sin((angulo+90)*pi/180);
            xf = 0.0;
            yf = 0.0;
            x2 = 0.0;
            y2 = 0.0;
            for(t = 0; ; t++){
                x2 = Vxoo*(t);
                y2 = DO.getY0() + Vyoo*(t) -(0.5*G*(t)*(t));
                xf = DD.getX0()+Vxo*t;
                yf = DD.getY0() + Vy0*t -(0.5*G*t*t);
                if(sqrt(pow((x2 - xf),2)+pow((y2 - yf),2)) < DD.getD0()){
                    if(yf>0 && y2>0){
                    ImprimirResultados(anguloo,vo0,x2,y2,t);
                    cout << "_________________________________"<<endl;
                    ImprimirResultados(angulo, V0o, xf, yf, t);
                    flag += 1;
                    break;}
                }
                if(yf < 0){
                    break;
                }
            }
            if(flag == 3) break;

        }
        if(flag == 3) break;
    }
    if(flag != 3){
        cout << "No impacto en los disparos esperados"<< endl;
    }
}

void Bala::DisparoDefensivo3(Canion DO, Canion DD, int V00, int anguloo, int vo0)
{
    int flag = 0;
    bool flag2 = 0;
    float x2,y2;
    float aux,auy;
    float Vxo,Vy0, Vxoo,Vyoo;
    int V0o = 0;
    float t = 2.5;
    angulo = 0;
    Vxoo = vo0*cos((anguloo)*pi/180);
    Vyoo = vo0*sin((anguloo)*pi/180);
    for(V0o = V00; ; V0o ++){
        for(angulo = 0; angulo < 90; angulo++){
            Vxo = V0o*cos((angulo+90)*pi/180);
            Vy0 = V0o*sin((angulo+90)*pi/180);
            xf = 0.0;
            yf = 0.0;
            x2 = 0.0;
            y2 = 0.0;
            for(t = 0; ; t++){
                x2 = Vxoo*(t);
                y2 = DO.getY0() + Vyoo*(t) -(0.5*G*(t)*(t));
                xf = DD.getX0()+Vxo*t;
                yf = DD.getY0() + Vy0*t -(0.5*G*t*t);
                for(int t2 = t; ;t2++){
                    aux = DD.getX0()+Vxo*t2;
                    auy = DD.getY0() + Vy0*t2 -(0.5*G*t2*t2);
                    if(sqrt(pow((DO.getX0() - aux),2)+pow((DO.getY0() - auy),2)) < DD.getD0()){
                        flag2 = 1;
                        break;
                    }
                    if(auy < 0){
                        break;
                    }
                }
                if(flag2){
                    flag2 = 0;
                    break;
                }
                if(sqrt(pow((DD.getX0() - x2),2)+pow((DD.getY0() - y2),2)) < DO.getD0()){
                    break;
                }
                if(sqrt(pow((x2 - xf),2)+pow((y2 - yf),2)) < DD.getD0()){
                    if(yf<0) yf = 0;
                    flag += 1;
                    cout << "Disparo numero " << flag << endl;
                    ImprimirResultados(anguloo,vo0,x2,y2,t);
                    cout << "_________________________________"<<endl;
                    ImprimirResultados(angulo, V0o, xf, yf, t);
                    break;
                }
                if(yf < 0){
                    break;
                }
            }
            if(flag == 3) break;

        }
        if(flag == 3) break;
    }
    if(flag != 3){
        cout << "No impacto en los disparos esperados"<< endl;
    }
}

void Bala::DisparoOfensivo1(Canion DO, Canion DD, int V00, int anguloo, int vo0, int angulod, int vd0)
{
    int flag = 0;
    float x2,y2,x3,y3;
    float Vxo,Vy0, Vxoo,Vyoo,Vxd,Vyd;
    int V0o = 0;
    float t = 4;
    angulo = 0;
    Vxoo = vo0*cos((anguloo)*pi/180);
    Vyoo = vo0*sin((anguloo)*pi/180);
    Vxd = vd0*cos((angulod+90)*pi/180);
    Vyd = vd0*sin((angulod+90)*pi/180);
    for(V0o = V00; ; V0o ++){
        for(angulo = 0; angulo < 90; angulo++){
            Vxo = V0o*cos((angulo)*pi/180);
            Vy0 = V0o*sin((angulo)*pi/180);
            xf = 0.0;
            yf = 0.0;
            x2 = 0.0;
            y2 = 0.0;
            x3 = 0.0;
            y3 = 0.0;
            for(t = 4; ; t=+0.1){
                x3 = Vxd*(t);
                y3 = DD.getY0() + Vyd*(t) -(0.5*G*(t)*(t));
                x2 = Vxoo*(t);
                y2 = DO.getY0() + Vyoo*(t) -(0.5*G*(t)*(t));
                xf = Vxo*t;
                yf = DO.getY0() + Vy0*t -(0.5*G*t*t);
                if(sqrt(pow((x3 - xf),2)+pow((y3 - yf),2)) < DO.getD0() && sqrt(pow((xf - x2),2)+pow((yf - y2),2)) > DO.getD0()){
                    if (yf <= 0)break;
                    else{
                        flag++;
                        cout << "Disparo numero " << flag << endl;
                        ImprimirResultados(angulo,V0o,xf,yf,t);
                        cout << "Posicion del proyectil ofensivo y defensivo" << endl;
                        ImprimirResultados(anguloo,vo0,x2,y2,t);
                        ImprimirResultados(angulod,vd0,x3,y3,t);
                        cout << endl;
                    }
                }
                if (yf<=0)break;
            }
            if (flag == 3)break;
        }
        if (flag == 3)break;
    }
}

