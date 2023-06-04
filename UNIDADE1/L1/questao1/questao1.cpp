#include <iostream>
#include <math.h>
using namespace std;

int soma_cubos(int soma, int n){
    if(n == 0){
        return soma; 
    }else{
        soma += pow(n,3);
        return soma_cubos(soma,n-1);
    }
}
int main (){
    int num, s = 0;
    cout << "Insira o numero que deseja saber a soma: ";
    cin >> num;
    cout << "A soma dos cubos sequenciais eh " << soma_cubos(s,num) << "!" << endl;
    return 0;
}

/*
    A primeira questão foi feita utilizando um input que recolhe o número que se deseja calcular, e
    em seguida uma função recursiva que vai somando o valor da potência do numero escolhido e diminuindo o valor do 
    mesmo a cada vez que é chamada, e quando chega a zero ela retorna o valor da soma total.
*/