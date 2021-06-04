#include <iostream>
#include "Fraccion.h"

using namespace std;

Fraccion::Fraccion(){
  numerador = 0;
  denominador = 1;
}


Fraccion::Fraccion(int num, int den){
  if(den == 0){
    den = 1;
  }
  if(den < 0){
    num = -num;
    den = -den;
  }
  reduccion(num,den);
  numerador = num;
  denominador = den;
}

void Fraccion::reduccion(int &num, int &den){
  // Auxiliares
  int limit = 0;
  int signo1 = 1;
  int signo2 = 1;
  // Guardar el signo en la variables [signoX] y dejar
  // num y den sin signo (para que la operaciones modulo
  // y limite esten correctas logicamente)
  if(num < 0){
    signo1 = -1;
    num = num*signo1;
  }
  if(den < 0){
    signo2 = -1;
    den = den*signo2;
  }
  if(num >= den){
    limit = den;
  }else{
    limit = num;
  }
  int it = 2;
  while(it <= limit){
    if(num % it == 0 && den % it == 0){
      num = num/it;
      den = den/it;
    }else{
      it++;
    }
  }
  num = num*signo1;
  den = den*signo2;
}

Fraccion Fraccion::suma(Fraccion farg){
  int num = numerador * farg.getDenominador() + denominador * farg.getNumerador();
  int den = denominador * farg.getDenominador();
  this->numerador = num;
  this->denominador = den;
  Fraccion fresultado(num,den);
  return fresultado;
}

Fraccion Fraccion::resta(Fraccion farg){
  int num = numerador * farg.getDenominador() - denominador * farg.getNumerador();
  int den = denominador * farg.getDenominador();
  Fraccion fresultado(num,den);
  return fresultado;
}

Fraccion Fraccion::multiplicacion(Fraccion farg){
  int num = numerador * farg.getNumerador();
  int den = denominador * farg.getDenominador();
  Fraccion fresultado(num,den);
  return fresultado;
}

void Fraccion::imprimir(){
  cout << numerador << "/" << denominador << endl;
}

int Fraccion::getNumerador(){
  return numerador;
}

int Fraccion::getDenominador(){
  return denominador;
}

void Fraccion::setNumerador(int num){
  this->numerador = num;
}

void Fraccion::setDenominador(int den){
  this->denominador = den;
}