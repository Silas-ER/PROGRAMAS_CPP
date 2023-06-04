#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <iomanip> 
using namespace std; 

//class de funcionario com seu private de variaveis
class Funcionario{
  private:
    string nDpt;
    string nome;
    string cod;
    double salario;

  public:
  //constructor da classe
  Funcionario(string nDpt, string nome, string cod, double salario){
    this -> nDpt = nDpt;
    this -> nome = nome;
    this -> cod = cod;
    this -> salario = salario;
  }

  /*
    funcao para impressao da folha de pagamento recebendo o tipo de folha de dpt que se deseja ser impressa, assim como seu layout usando o 
    a biblioteca iomanip para formatacao (setw) e tentativa de arredondamento (setprecision)
  */
  static void imprime_folha_pagamento(const vector<Funcionario>& funcionarios, string tipo_folha){
    double somasalario = 0;
    cout << "FOLHA DE PAGAMENTO DEPTO  " << tipo_folha << endl;
    cout << setw(6) << left << "FUNC" << setw(10) << left << "NOME" << setw(10) << left << "DEPTO" << setw(10) << left << "SALARIO" << endl;
    for (const auto& func : funcionarios) {
      if (tipo_folha == func.cod) {
        cout << setw(6) << left << func.nDpt << setw(10) << left << func.nome << setw(10) << left << func.cod << setw(10) << left << func.salario << fixed << setprecision(2) << endl;
        somasalario += func.salario;
      }
    }
    cout << "VALOR TOTAL: R$ " << somasalario << endl;
    cout << endl; 
  }

};

int main() {
  //abertura de arquivo e contador da linha para ignorar a primeira
  ifstream dados("funcionarios.txt");
  int linha_atual = 0;

  //verificacao de abertura
  if(dados.is_open()){
    cout << "Arquivo funcionarios.txt aberto" << endl;
  }else{
    cout << "funcionarios.txt não pode ser aberto" << endl;
  }

  //vetor para recebimento de dados dos funcionarios e linha para uso da func ss
  vector<Funcionario> funcionarios;
  string linha;

  /*
    laco para recebimento dos dados apos a primeira linha assim como a declaracao de variaveis
    para seguir o constuctor alem do incremento de linhas para o laco
  */
  while (getline(dados, linha)) {
    istringstream ss(linha);
    string nDpt, nome, cod;
    double salario;

    if (linha_atual > 0) {
      if (ss >> nDpt >> nome >> cod >> salario) {
        Funcionario novo(nDpt, nome, cod, salario);
        funcionarios.push_back(novo);
      }
    }

    linha_atual++;
  }

  //fechando arquivo e confirmacao
  dados.close();

  if(dados.is_open()){
    cout << "Arquivo funcionarios.txt não foi fechado" << endl;
  }else{
    cout << "funcionarios.txt foi fechado" << endl;
  }

  //impressao de dados por departamento
  Funcionario::imprime_folha_pagamento(funcionarios, "A");
  Funcionario::imprime_folha_pagamento(funcionarios, "B");
  Funcionario::imprime_folha_pagamento(funcionarios, "C");
}

