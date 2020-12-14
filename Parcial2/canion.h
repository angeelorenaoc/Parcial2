#ifndef CANION_H
#define CANION_H


class Canion
{
private:
    float d;
    float H0;
    float x0;
    float y0;
    float d0;
public:
    Canion(float d_,float h0_, float x0_,float d0_);
    float getH0() const;
    float getX0() const;
    float getY0() const;
    float getD0() const;
    float getD() const;
};

#endif // CANION_H
