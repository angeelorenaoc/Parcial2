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
    float x,y;
    float Vxo,Vy0;
    int V0o = 0;
    int t = 0;
    int angle = 0;
    for(V0o = V0_; ; V0o += 5){
        for(angle = 0; angle < 90; angle++){
            Vxo = V0o*cos(angle*pi/180);
            Vy0 = V0o*sin(angle*pi/180);
            x = 0.0;
            y = 0.0;
            for(t = 0; ; t++){
                x = Vxo*t;
                y = DO.getY0() + Vy0*t -(0.5*G*t*t);
                if(sqrt(pow((DD.getX0() - x),2)+pow((DD.getY0() - y),2)) < DO.getD0()){
                    if(y<0) y = 0;
                    ImprimirResultados(angle, V0o, x, y, t);
                    flag += 1;
                    V0o += 50;
                    break;
                }
                if(y < 0){
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
    float x,y;
    float Vxo,Vy0;
    int V0o = 0;
    int t = 0;
    int angle = 0;
    for(V0o = V0_; ; V0o += 5){
        for(angle = 0; angle < 90; angle++){
            Vxo = V0o*cos((angle+90)*pi/180);
            Vy0 = V0o*sin((angle+90)*pi/180);
            x = 0.0;
            y = 0.0;
            for(t = 0; ; t++){
                x = Vxo*t;
                y = DD.getY0() + Vy0*t -(0.5*G*t*t);
                if(sqrt(pow((DO.getX0() - x),2)+pow((DO.getY0() - y),2)) < DD.getD0()){
                    if(y<0) y = 0;
                    flag += 1;
                    cout << "Disparo " << flag << endl;
                    ImprimirResultados(angle, V0o, x, y, t);
                    V0o += 50;
                    break;
                }
                if(y < 0){
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
    float x,y,x2,y2;
    float Vxo,Vy0, Vxoo,Vyoo;
    int V0o = 0;
    float t = 2.5;
    int angle = 0;
    Vxoo = vo0*cos((anguloo)*pi/180);
    Vyoo = vo0*sin((anguloo)*pi/180);
    for(V0o = V00; ; V0o += 5){
        for(angle = 0; angle < 90; angle++){
            Vxo = V0o*cos((angle+90)*pi/180);
            Vy0 = V0o*sin((angle+90)*pi/180);
            x = 0.0;
            y = 0.0;
            x2 = 0.0;
            y2 = 0.0;
            for(t = 0; ; t++){
                x2 = Vxoo*(t);
                y2 = DO.getY0() + Vyoo*(t) -(0.5*G*(t)*(t));
                x = DD.getX0()+Vxo*t;
                y = DD.getY0() + Vy0*t -(0.5*G*t*t);
                if(sqrt(pow((x2 - x),2)+pow((y2 - y),2)) < DD.getD0()){
                    if(y>0 && y2>0){
                    ImprimirResultados(anguloo,vo0,x2,y2,t);
                    cout << "_________________________________"<<endl;
                    ImprimirResultados(angle, V0o, x, y, t);
                    flag += 1;
                    V0o += 50;
                    break;}
                }
                if(y < 0){
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
    float x,y,x2,y2;
    float aux,auy;
    float Vxo,Vy0, Vxoo,Vyoo;
    int V0o = 0;
    float t = 2.5;
    int angle = 0;
    Vxoo = vo0*cos((anguloo)*pi/180);
    Vyoo = vo0*sin((anguloo)*pi/180);
    for(V0o = V00; ; V0o += 5){
        for(angle = 0; angle < 90; angle++){
            Vxo = V0o*cos((angle+90)*pi/180);
            Vy0 = V0o*sin((angle+90)*pi/180);
            x = 0.0;
            y = 0.0;
            x2 = 0.0;
            y2 = 0.0;
            for(t = 0; ; t++){
                x2 = Vxoo*(t);
                y2 = DO.getY0() + Vyoo*(t) -(0.5*G*(t)*(t));
                x = DD.getX0()+Vxo*t;
                y = DD.getY0() + Vy0*t -(0.5*G*t*t);
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
                if(sqrt(pow((x2 - x),2)+pow((y2 - y),2)) < DD.getD0()){
                    if(y<0) y = 0;
                    flag += 1;
                    cout << "Disparo numero " << flag << endl;
                    ImprimirResultados(anguloo,vo0,x2,y2,t);
                    cout << "_________________________________"<<endl;
                    ImprimirResultados(angle, V0o, x, y, t);
                    V0o += 50;
                    break;
                }
                if(y < 0){
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

