#include "canion.h"

float Canion::getH0() const
{
    return H0;
}

float Canion::getX0() const
{
    return x0;
}

float Canion::getY0() const
{
    return y0;
}

float Canion::getD0() const
{
    return d0;
}

float Canion::getD() const
{
    return d;
}

Canion::Canion(float d_,float h0_, float x0_,float d0_)
{
    d=d_;
    H0=h0_;
    x0=x0_;
    y0=h0_;
    d0=d0_*d;

}
