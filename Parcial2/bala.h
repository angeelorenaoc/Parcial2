#ifndef BALA_H
#define BALA_H
#include "canion.h"

class Bala
{
private:
    int angulo;
    float vx;
    float vy;
    float t;
    float v0;
    float xf;
    float yf;
public:
    Bala(int v0_);
    float getV0() const;
    void ImprimirResultados(int ang, int v00, float x, float y, float t);
    void DisparoOfensivo(Canion DO, Canion DD,int V0_);
    void DisparoDefensivo(Canion DO, Canion DD, int V0_);
    void DisparoDefensivo2(Canion DO, Canion DD, int V00, int anguloo, int vo0);
    void DisparoDefensivo3(Canion DO,Canion DD, int V00, int angeloo, int vo0);
    void DisparoOfensivo1(Canion DO,Canion DD, int V00, int anguloo, int vo0, int angulod, int vd0);
};

#endif // BALA_H
