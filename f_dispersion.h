#ifndef Funcion_dispersion_H_
#define Funcion_dispersion_H_

#include <cstdlib>

template<class Clave>
class Funcion_dispersion {
 public:
  virtual int operator()(const Clave& k) const = 0;
};

template<class Clave>
class fdModulo: public Funcion_dispersion<Clave>{
 public:
  fdModulo(const int n): nDatos_(n){}
  int operator()(const Clave& k) const {return k % nDatos_;}
 private:
  int nDatos_;
};

template<class Clave>
class fdAleatoria: public Funcion_dispersion<Clave>{
 public:
  fdAleatoria(const int n): nDatos_(n){}
  int operator()(const Clave& k) const;
 private:
  int nDatos_;
};

template<class Clave>
int fdAleatoria<Clave>::operator()(const Clave& k) const {
  srand(k);
  return (rand() % nDatos_);
}

#endif //Funcion_dispersion_H_