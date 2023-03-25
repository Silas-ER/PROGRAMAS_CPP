#include <iostream>
using namespace std;

int menor_vetor(int n, int menor, int vet_n[n]){
  if(n-1 == -1){
    return menor;
  }else{
    n--;
    if(vet_n[n] < menor){
      menor = vet_n[n];
    }
    return menor_vetor(n, menor, vet_n);
  }
}

int main(){
    int num = 5, vet_n[5] = {95,2,38,21,55}, men = vet_n[num-1];
    cout << "O menor valor do vetor é "<< menor_vetor(num, men, vet_n) << endl;
    return 0;
}

/*
  A segunda questão recebe um vetor de tamanho 5 e através da função recursiva que começa com o menor valor sendo o
  quinto elemento do vetor ela compara com o elemento anterior e se esse for menor então o valor do menor muda, assim quando 
  chega a posição -1 na recursividade ele retorna o menor valor.
*/