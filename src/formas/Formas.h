#ifndef __FORMAS_H__
#define __FORMAS_H__

#include "Matriz.h"
#include <vector>
#include <math.h>
#include <time.h>




class Forma{

public:
    Coord m;
    Vector3 pos;
    Forma(int DIM, Vector3 pos);
    void render();
    void esfera(int r);
    void cubo(float tamanho);
    void elipsoide(int rx, int ry, int rz);
    void cilindro(int r);
    void superficie();
    void funcao(float ini, float fim, float (*f)(float, float));
};








#endif