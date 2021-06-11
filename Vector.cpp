#include <iostream>
#include <math.h>
#include <stdio.h>
#include "Vector.h"

using namespace std;

Vector::Vector(){
  arr = new Fraccion[1];
  size = 1;
  sizeMem = 1;
}

// Constructor con tamaño especifico
Vector::Vector(int s){
  arr = new Fraccion[s];
  size = s;
  sizeMem = s;
}

// Constructor con vector especifico
Vector::Vector(int s, Fraccion * compf){
  arr = compf;
  size = s;
  sizeMem = s;
}

// Obtener tamaño del vector
int Vector::getSize(){
  return size;
}

// Obtener Fraccion por indice

Fraccion Vector::getFraccion(int i){
  return arr[i];
}

void Vector::setFraccion(int i, Fraccion f){
  arr[i] = f;
}

void Vector::agregarFraccion(Fraccion f){
  // Se duplica el tamaño de la memoria para evitar trasladar arreglos de elementos cada que se agrega una fraccion
  if(size+1 > sizeMem){
    // Se crea un nuevo arreglo de fracciones con el doble de memoria
    Fraccion * newArr = new Fraccion[size*2];
    //Se copia el arreglo en el nuevo arreglo
    for (int i=0; i < size; i++){
      newArr[i] = arr[i];
    }
    newArr[size+1] = f;
    arr = newArr;
    sizeMem = size*2;
    size = size+1;
  }else{ //Si hay suficiente memoria reservado, entonces, simplemente agregalo
    arr[size+1] =  f;
    size++;
  }
}

void Vector::eliminarFraccion(){
  arr[size].setNumerador(0);
  arr[size].setDenominador(1);
  size--;
}

void Vector::imprimir(bool showSize){
  if(showSize)
    cout << "size: " << size << ", sizeMem: " << sizeMem << "---";
  cout << "[";
  int i;
  for (i=0; i<size; i++){
    cout << arr[i].getNumerador() << "/" << arr[i].getDenominador();
    if(i < size-1)
      cout << ", ";
  }
  cout << "]" << endl;
}

void Vector::setSize(int _size){
  this->size = _size;
}

Vector Vector::operator + (Vector obj){
    return this->suma(obj);
}

Vector Vector::suma(Vector varg){
  if(size == varg.getSize()){
    Vector newVecFracc(size);
    for (int i=0; i<size; i++){
      newVecFracc.setFraccion(i, arr[i].suma(varg.getFraccion(i)));
    }
    return newVecFracc;
  }else{
    cout << "Los vectores no tienen las mismas dimensiones" << endl;
    return Vector();
  }
}

Vector Vector::operator * (Vector obj){
    return this->ppunto(obj);
}

Vector Vector::ppunto(Vector varg){
  if(size == varg.getSize()){
    Vector newVecFracc(size);
    for (int i=0; i<size; i++){
      newVecFracc.setFraccion(i, arr[i].multiplicacion(varg.getFraccion(i)));
    }
    Fraccion sumatoria;
    Vector resultado;
    for (int i=0; i<size; i++){
      sumatoria = sumatoria.suma(newVecFracc.getFraccion(i));
    }
    resultado.setFraccion(0, sumatoria);
    return resultado;
  }else{
    cout << "Los vectores no tienen las mismas dimensiones" << endl;
    return Vector();
  }
}

/*Vector Vector::mult(Vector varg){
  if(size == varg.getSize()){
    Vector newVecFracc(size);
    for (int i=0; i<size; i++){
      newVecFracc.setFraccion(i, arr[i].multiplicacion(varg.getFraccion(i)));
    }
    return newVecFracc;
  }else{
    cout << "Los vectores no tienen las mismas dimensiones" << endl;
    return Vector();
  }
}*/

Vector Vector::operator - (Vector obj){
    return this->resta(obj);
}

Vector Vector::resta(Vector varg){
  if(size == varg.getSize()){
    Vector newVecFracc(size);
    for (int i=0; i<size; i++){
      newVecFracc.setFraccion(i, arr[i].resta(varg.getFraccion(i)));
    }
    return newVecFracc;
  }else{
    cout << "Los vectores no tienen las mismas dimensiones" << endl;
    return Vector();
  }
}
 
Vector Vector::producto(Vector varg){
  Vector resultado(size);
  Fraccion f1, f2, f1_2, f3, f4, f3_4, f5, f6, f5_6, a(-1,1);
  if(size == varg.getSize() && size == 3){
    f1 = arr[1].multiplicacion(varg.getFraccion(2));
    f2 = arr[2].multiplicacion(varg.getFraccion(1));
    f1_2 = f1.resta(f2);

    f3 = arr[0].multiplicacion(varg.getFraccion(2));
    f4 = arr[2].multiplicacion(varg.getFraccion(0));
    f3_4 = f3.resta(f4);

    f5 = arr[0].multiplicacion(varg.getFraccion(1));
    f6 = arr[1].multiplicacion(varg.getFraccion(0));
    f5_6 = f5.resta(f6);

    resultado.setFraccion(0, f1_2);
    resultado.setFraccion(1, f3_4.multiplicacion(a));
    resultado.setFraccion(2, f5_6);

  }else{
	  cout <<  "Los vectores exceden las dimensiones permitidas o tienen diferentes dimensiones. " << endl;
    return Vector();
  }
  return resultado;
}

Vector Vector::producto(float a){
  Fraccion f(a,1);
  Vector newVecFracc(size);
  for (int i=0; i<size; i++){
    newVecFracc.setFraccion(i, arr[i].multiplicacion(f));
    }
  return newVecFracc;
}

float Vector::magnitud(){
  Vector newVecFracc(size);
  Fraccion a;
  for (int i=0; i<size; i++){
    newVecFracc.setFraccion(i, arr[i].multiplicacion(arr[i]));
  }
  Fraccion sumatoria;
  Vector resultado;
  for (int i=0; i<size; i++){
    sumatoria = sumatoria.suma(newVecFracc.getFraccion(i));
  }
  resultado.setFraccion(0, sumatoria);
  double raizNum, raizDen;
  float magnitud;
  raizNum = sqrt(resultado.getFraccion(0).getNumerador());
  raizDen = sqrt(resultado.getFraccion(0).getDenominador());
  magnitud = raizNum/raizDen;

  return magnitud;
}
/*
Vector Vector::angulo(Vector obj){
  Vector resultado, pp;
  float m_a, m_b, pp_num, pp_den, punto, ang;
  pp = arr[]*obj;
  pp_num = pp.getFraccion(0).getNumerador();
  pp_den = pp.getFraccion(0).getDenominador();
  punto = pp_num / pp_den;
  m_a = arr[].magnitud();
  m_b = obj.magnitud();

  ang = cos(punto / m_a * m_b);
  Fraccion f(ang,1);
  resultado.setFraccion(0, f);

  return resultado;
}*/
