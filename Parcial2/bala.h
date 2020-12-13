#ifndef BALA_H
#define BALA_H
#include "canion.h"
#include <iostream>
#include <cmath>
#include <math.h>

using namespace std;
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
    float G=9.8;
    float pi=3.1416;
public:
    Bala();
    float getV0() const;
    void ImprimirResultados(int ang, int v00, float x, float y, float t);
    void DisparoOfensivo(Canion DO, Canion DD,int V0_);
    void DisparoDefensivo(Canion DO, Canion DD, int V0_);
    void DisparoDefensivo2(Canion DO, Canion DD, int V00, int anguloo, int vo0);
    void DisparoDefensivo3(Canion DO,Canion DD, int V00, int anguloo, int vo0);
    void DisparoOfensivo1(Canion DO,Canion DD, int V00, int anguloo, int vo0, int angulod, int vd0);
};

#endif // BALA_H
