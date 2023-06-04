#include <iostream>
#include "fat.h"

int fatorial(int n, int fat){
    if(n == 1){
        return fat;
    }else{
        fat *= n;
        return fatorial(n-1,fat);
    }
}

/*
    a recursiva funciona com o n, acrescentando ao valor fat a multiplicação por n e retornando ao 
    recursivo o valor de n - 1, até que n se torne 1 e se retorne a soma fatorial!
*/
