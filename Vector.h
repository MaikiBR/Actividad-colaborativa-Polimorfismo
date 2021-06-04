#ifndef VECTOR_H
#define VECTOR_H
#include "Fraccion.h"

class Vector{
  private:
    Fraccion *arr; // [1/4, 1/2] + [1/4, 1/4] = [1/2, 3/4]
    int size;
    int sizeMem;
  public:
    Vector();
    Vector(int); 
    Vector(int, Fraccion *);

    int getSize();
    void setSize(int);

    Fraccion getFraccion(int);
    void setFraccion(int, Fraccion);
    void agregarFraccion(Fraccion); 
    void eliminarFraccion(); // ultimo elemento 
    void imprimir(bool);

    Vector operator + (Vector);
    Vector operator * (Vector);
    Vector operator - (Vector);

    Vector suma(Vector);
    Vector ppunto(Vector);
    Vector resta(Vector);
    Vector angulo(Vector);
    Vector producto(Vector);
    Vector producto(float);
    float magnitud();
};

#endif // VECTOR_H  
