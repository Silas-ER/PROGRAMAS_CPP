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
    cout << "Qual digito deseja saber as aparicoes: ";
    cin >> escolha;
    cout << "O numero de aparicoes eh: " << aparicoes(numero, escolha, aparicao, div) << endl;
    return 0;
}

/*
  Na questão 4, recebemos um numero e o digito que deseja-se saber quantas vezes aparece e também passo um divisor que começa 
  igual a 10, dentro da recursiva ele conta o resto da divisão (que funciona na primeira vez) se é o numero escolhido, se sim
  aumenta o contador e nas outras ele vê se o resultado da divisão é o número escolhido, se sim conta mais, e outro detalhe
  e que em todas as recursividades ele retorna o número dividido por 10, já que o divisor na função se mantem no 10, no fim se 
  o divisor for maior que o número ele vai retornar o contador.
*/