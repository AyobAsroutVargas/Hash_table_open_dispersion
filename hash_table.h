#ifndef Hash_table_H_
#define Hash_table_H_

#include <iostream>
#include <vector>
#include "f_dispersion.h"
#include "lista.h"

template<class Clave>
class Hash_table {
 public:
  Hash_table(int cell_num, Funcion_dispersion<Clave> * fd);
  bool Buscar(const Clave& X);
  bool Insertar(const Clave& X);
  void mostrar();
 private:
  int nDatos_;
  int nCeldas_;
  std::vector<Lista<Clave> > vDatos_;
  Funcion_dispersion<Clave> * fd_;
};


template<class Clave>
bool Hash_table<Clave>::Buscar(const Clave& X){
  int pos = fd_->operator()(X);
  if(vDatos_[pos].Buscar(X)) return true;
  return false;
}

template<class Clave>
bool Hash_table<Clave>::Insertar(const Clave& X) {
  if(Buscar(X)) {
    return false;
  } else {
    int pos = fd_->operator()(X);
    vDatos_[pos].Insertar(X);
    return true;
  }
}

template<class Clave>
Hash_table<Clave>::Hash_table(int cell_num, Funcion_dispersion<Clave> * fd) {
  nDatos_= cell_num;
  fd_ = fd;
  vDatos_.resize(nDatos_);
}

template<class Clave>
void Hash_table<Clave>::mostrar() {
  for (int i = 0; i < vDatos_.size(); i++) {
    std::cout << "[" << i << "]: ";
    vDatos_[i].mostrar();
    std::cout << std::endl;
  }
}

#endif //Hash_table_H_