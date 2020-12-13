#include "bala.h"

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

Bala::Bala()
{

}
