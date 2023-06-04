#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(){
  //criação de vetor de 4 strings e 
  string vetor[4];
  ifstream q1 ("entrada_q1.txt");

  //verificação de abertura de arquivo
  if(q1.is_open()){
    cout << "Arquivo entrada_q1.txt aberto" << endl;
    cout << endl;
  }else{
    cout << "entrada_q1.txt não pode ser aberto" << endl;
    cout << endl;
  }

  //armazenamento das strings no vetor
  for (int i=0; i<4; i++){
    getline(q1, vetor[i]);
  }

  //fechar arquivo
  q1.close();

  //impressão das strings armazenadas no terminal 
  for (int i=0; i<4; i++){
    cout << (vetor[i]) << endl;
  }
  
  return 0;
}
