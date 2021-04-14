#include "hash_table.h"

int main () {
  Funcion_dispersion<int> * fd;
  int num_celdas, tipo_dispersion, menu_option, valor;
  std::cout << "Introduzca el numero de celdas de la tabla:";
  std::cin >> num_celdas;
  std::cout << "Introduzca el tipo de dispersion a aplicar(0 modulo, 1 pseudo-aleatoria):";
  std::cin >> tipo_dispersion;
  switch (tipo_dispersion) {
   case 0:
    fd = new fdModulo<int>(num_celdas);
    break;
  
   case 1:
    fd = new fdAleatoria<int>(num_celdas);
    break;
  }
  Hash_table<int> hash_table(num_celdas, fd);
  do {
    std::cout << "\n0. Finalizar programa\n1. Insertar valor\n2. Buscar valor\n3. Mostrar lista\nIntroduzca la operación a realizar:";
    std::cin >> menu_option;
    switch (menu_option)
    {
     case 1:
      std::cout << "Introduzca el valor a insertar:";
      std::cin >> valor;
      if(!hash_table.Insertar(valor)) {
        std::cout << "El valor " << valor << "ya se encuentra en la tabla.\n";
      }
      break;
    
     case 2:
      std::cout << "Introduzca el valor a buscar:";
      std::cin >> valor;
      if(hash_table.Buscar(valor)) {
        std::cout << "El valor " << valor << " se encuentra en la tabla.\n";
      } else {
        std::cout << "El valor " << valor << " no se encuentra en la tabla.\n";
      }
      break;

     case 3:
      hash_table.mostrar();
      break;

     case 0:
      break;
    }
  } while (menu_option!=0);
  return 0;
}