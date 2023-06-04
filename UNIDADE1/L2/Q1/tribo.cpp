#include <iostream>
#include "tribo.h"

int tribonacci(int n, int result){
  if (n == 0){
    return n;
  }
  else if (n == 1 or n == 2 ){
    result = 1;
    return result;
  }
  else{
    int n1 = 0 , n2 = 1, n3 = 1, c = 2;
    result = tribonacci_rec(n1, n2, n3, n, result, c);
    return result;
  }
}

int tribonacci_rec(int num, int num2, int num3, int n, int resultado, int cont){
  if(cont == n){
    return resultado;
  }else{
    resultado = num + num2 + num3;
    num = num2;
    num2 = num3;
    num3 = resultado;
    cont += 1;
    return tribonacci_rec(num, num2, num3, n, resultado, cont); 
  }
}
