#ifndef Lista_H_
#define Lista_H_

#include <vector>
#include <cstdlib>
#include <iomanip>

template<class Clave>
class Lista {
 public:
  Lista();
  bool Buscar(const Clave&X);
  bool Insertar(const Clave& X);
  void mostrar();
 private:
  std::vector<Clave> list_vec_;
  int size_;
};

template<class Clave>
bool Lista<Clave>::Buscar(const Clave&X) {
  for(int i = 0; i < list_vec_.size(); i++) {
    if(list_vec_[i] == X) return true;
  }
  return false;
}

template<class Clave>
bool Lista<Clave>::Insertar(const Clave&X) {
  if(Buscar(X)) {
    return false;
  }
  list_vec_.push_back(X);
  return true;
}

template<class Clave>
Lista<Clave>::Lista() {
  size_ = 0;
}

template<class Clave>
void Lista<Clave>::mostrar() {
  for(int i = 0; i < list_vec_.size(); i++) {
    std::cout << std::fixed << std::setw(2) << list_vec_[i] << "  ";
  }
  std::cout << "\n";
}


#endif //Lista_H_
