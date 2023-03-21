#include <iostream>
#include "pri.h"

int primo_anterior(int n, int primo){
    int cont=0;
    if(n == 2){
        primo = n;
        return primo;
    }else{
        for(int i=n;i>0;i--){
            if(n%i == 0){
                cont++;
            }
        }
        if(cont == 2){
            primo = n;
            return primo;
        }else{
            return primo_anterior(n-1, primo);
        }
    }
}