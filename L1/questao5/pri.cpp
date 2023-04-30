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

/*
    a função recusiva dos primos começa com o contador igual a 0, e o numero recebido,
    com duas condições, se o n for igual a 2 ,
    ele vai retorna 2 já que é o primo minimo, senão ele vai rodar um laço para para saber se aquele numero é primo ou não
    caso seja ele já retorna em seguida, caso não seja o número diminui um e retorna para função
*/