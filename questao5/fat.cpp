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
