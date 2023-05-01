#include <iostream>
#include "tribo.h"

int main() {
  int result = 0, n, a ;
  std::cout << "Insira o valor desejado: ";
  std::cin >> n;
   a = tribonacci(n,result);
  std::cout << "O resultado da sequencia tribonacci eh " << a ;
}
