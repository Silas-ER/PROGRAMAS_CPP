#include <iostream>
using namespace std;

int aparicoes(int n, int escolhido, int apareceu, int divisor){
    if (divisor > n){
      return apareceu;
    }
    if(n%divisor == escolhido){
      apareceu++;
    }
    if(n/divisor == escolhido){
      apareceu++;
    }
  return aparicoes(n/10,escolhido,apareceu,divisor);
}

int main(){
    int numero, escolha, aparicao=0, div=10;
    cout << "Digite o numero : "; 
    cin >> numero;
    cout << "Qual numero deseja saber as aparicoes: ";
    cin >> escolha;
    cout << "O numero de aparicoes eh: " << aparicoes(numero, escolha, aparicao, div) << endl;
    return 0;
}