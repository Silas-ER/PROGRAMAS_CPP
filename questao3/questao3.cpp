#include <iostream>
using namespace std;

double serie_harmonica(double n, double soma){
    if(n == 0){
        return soma;
    }else{
        soma += 1/n;
        n--;
        return serie_harmonica(n,soma);
    }
}

int main(){
    double num, sum = 0; 
    cout << "Insira o valor que deseja saber a serie harmonica: ";
    cin >> num;
    cout << fixed;
    cout.precision(2); 
    cout << "O valor da serie harmonica eh de " << serie_harmonica(num, sum);
    return 0;
}

/*
    A questão 3 recebe o valor que se deseja saber da serie harmônica, e retorna com a precisão de dois dígitos
    a soma dos valores da série harmônica através da função recursiva começando do numero escolhido e diminuindo 
    o valor a cada chamada e quando o valor chega a zero retorna a soma total.  
*/