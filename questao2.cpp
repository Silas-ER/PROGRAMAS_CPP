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
    int num = 5, men = 1000, vet_n[5] = {95,20,38,21,55};
    cout << "O menor valor do vetor é "<< menor_vetor(num, men, vet_n) << endl;
    return 0;
}