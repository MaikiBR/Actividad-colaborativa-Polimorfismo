/*
Team 4:
José Ángel Tobón Salazar A01411655
Miguel Ángel Bermea Rodríguez A01411671
Jesús Eduardo Rodríguez Romero A01411628
Luis Ángel Ramiro Amaro A01411763
Gustavo Luna Muñoz  A01411619
*/
#include <iostream>
#include "Vector.h"
using namespace std;

int main() {
  // Crear dos vectores con 4 dimensiones y verificar todas las operaciones, la operacion de producto cruz debera mostrar que no esta soportada. [Desplegar resultado de cada operacion]

  // Crear dos vectores con 3 dimensiones y verificar nuevamente todas las operaciones, adicionalmente probar los métodos de magnitud y escalamiento. 

  // Validar que operaciones de vectores con diferentes dimensiones no sea valida
  cout << "Actividad de Polimorfismo [Clase Fraccion y ClaseVector]" << endl;
  cout << "==============================================" << endl;

  // Fracciones para vectores

  /*Fraccion f1a(1,2);
  Fraccion f2a(2,5);
  Fraccion f3a(5,9);
  Fraccion f4a(7,9);
  Fraccion f1b(1,2);
  Fraccion f2b(3,4);
  Fraccion f3b(15,28);
  Fraccion f4b(1,3);*/
  Fraccion fracA(1,2);
  Fraccion fracB(1,3);
  Fraccion fracC(2,6);
  Fraccion fracD(1,5);
  Fraccion fracE(2,3);
  Fraccion fracF(1,7);
  Fraccion fracG(1,7);
  Fraccion fracH(1,10);

  cout << "Definicion de Vectores" << endl;
  cout << "Vector A (vecA): "; // 4 dimensiones
  Fraccion ftestA[4] = {fracA, fracB, fracC, fracD};
  Vector vecA(4, ftestA);
  vecA.imprimir(false);
  float magA; 
  magA = vecA.magnitud();
  cout << "Magnitud de Vector A: " << magA << endl << endl;
  cout << "Vector B (vecB): "; // 4 dimensiones
  Fraccion ftestB[4] = {fracE,fracF,fracG, fracH};
  Vector vecB(4, ftestB);
  vecB.imprimir(false);
  float magB; 
  magB = vecB.magnitud();
  cout << "Magnitud de Vector B: " << magB << endl << endl;
  cout << "Vector C (vecC): "; // 3 dimensiones
  Fraccion ftestC[3] = {fracA,fracB,fracC};
  Vector vecC(3,ftestC);
  vecC.imprimir(false);
  float magC; 
  magC = vecC.magnitud();
  cout << "Magnitud de Vector C: " << magC << endl << endl;
  cout << "Vector D (vecD): "; // 3 dimensiones
  Fraccion ftestD[3] = {fracD,fracE,fracF};
  Vector vecD(3,ftestD);
  vecD.imprimir(false);
  float magD; 
  magD = vecD.magnitud();
  cout << "Magnitud de Vector D: " << magD << endl << endl;
  cout << endl << "==============================================" << endl;
  cout << "Operaciones con vectores de 4 dimensiones" << endl;
  cout << "==============================================" << endl;
  cout << "PRODUCTO PUNTO" << endl;
  cout << "vecAB = vecA * vecB" << endl;
  Vector vecAB;
  vecAB = vecA*vecB;
  vecAB.imprimir(false);
  cout << "RESTA" << endl;
  cout << "vecCD = vecA - vecB" << endl;
  vecAB = vecA-vecB;
  vecAB.imprimir(false);
  cout << "ESCALAMIENTO" << endl;
  cout << "2 * vecA" << endl;
  float e_1 = 2;
  Vector e_vecA;
  e_vecA = vecA.producto(e_1);
  e_vecA.imprimir(false);
  cout << "3 * vecB" << endl;
  float e_2 = 3;
  Vector e_vecB;
  e_vecB = vecB.producto(e_2);
  e_vecB.imprimir(false);
  cout << "SUMA" << endl;
  cout << "vecAB = vecA + vecDB" << endl;
  vecAB = vecA+vecB;
  vecAB.imprimir(false);
  

  cout << endl << "==============================================" << endl;
  cout << "Operaciones con vectores de 3 dimensiones" << endl;
  cout << "==============================================" << endl;
  cout << "PRODUCTO PUNTO" << endl;
  cout << "vecCD = vecC * vecD" << endl;
  Vector vecCD;
  vecCD = vecC*vecD;
  vecCD.imprimir(false);
  cout << "RESTA" << endl;
  cout << "vecCD = vecC - vecD" << endl;
  vecCD = vecC-vecD;
  vecCD.imprimir(false);
  cout << "ESCALAMIENTO" << endl;
  cout << "2 * vecC" << endl;
  float e_3 = 2;
  Vector e_vecC;
  e_vecC = vecC.producto(e_3);
  e_vecC.imprimir(false);
  cout << "3 * vecD" << endl;
  float e_4 = 3;
  Vector e_vecD;
  e_vecD = vecD.producto(e_4);
  e_vecD.imprimir(false);
  cout << "SUMA" << endl;
  cout << "vecCD = vecC + vecD" << endl;
  vecCD = vecC+vecD;
  vecCD.imprimir(false);


  cout << endl << "==============================================" << endl;
  cout << "Operaciones con vectores de diferentes dimensiones" << endl;
  cout << "==============================================" << endl;
  Vector vecAC;
  cout << "PRODUCTO PUNTO" << endl;
  cout << "vecAC = vecA * vecC" << endl;
  vecAC = vecA*vecC;
  vecAC.imprimir(false);
  cout << "RESTA" << endl;
  cout << "vecAC = vecA - vecC" << endl;
  vecAC = vecA-vecC;
  vecAC.imprimir(false);
  cout << "SUMA" << endl;
  cout << "vecAC = vecA + vecC" << endl;
  vecAC = vecA+vecC;
  vecAC.imprimir(false);
  cout << "==============================================" << endl;

  return 0;
}
