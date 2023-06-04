#include <iostream>
#include <fstream>
using namespace std;

int main(){
  //criação de vetor e variaveis para soma e abertura dos arquivos de entrada e saida
  int vetor[10];
  double soma=0;
  ifstream numeros ("entrada_q2.txt");
  ofstream resultados ("saidas_q2.txt", ios::out);

  //verificação de estado de abertura do arquivo de entrada
  if(numeros.is_open()){
    cout << "Arquivo entradas_q2.txt aberto" << endl;
  }else{
    cout << "entradas_q2.txt não pode ser aberto" << endl;
  }

  //armazenamento de dados no vetor
  for(int i=0; i<10; i++){
    numeros >> vetor[i];
  }

  //fechamento de entradas
  numeros.close();

  //variaveis para descobrir o menor e maior valor
  int menor=vetor[0], maior=vetor[0];

  //laço para soma de dados do vetor e definicao do maior e menor
  for(int i=0; i<10; i++){
    soma += vetor[i];
    if(vetor[i] > maior){
      maior = vetor[i];
    }
    if(vetor[i] < menor){
      menor = vetor[i];
    }
  }

  //passando dados para o arquivo de saida
  resultados << "Menor elemento: " << menor << endl;
  resultados << "Maior elemento: " << maior << endl;
  resultados << "Média dos elementos: " << (soma/10) << endl;

  //fechamento de arquivo e confirmação 
  resultados.close();
  cout << "saidas_q2.txt gerado" << endl;
  
  return 0;
}