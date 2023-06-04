#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

struct Dados_Alunos{
  private:
    string nome;
    double nota1; 
    double nota2;
    double nota3;
    double media;
    string status;

  public:
    //constructor
    Dados_Alunos(string nome, double nota1, double nota2, double nota3, double media, string status){
      this -> nome = nome;
      this -> nota1 = nota1;
      this -> nota2 = nota2;
      this -> nota3 = nota3;
      this -> media = media;
      this -> status = status;
    }

    //getters
    string getNome() const{
      return nome;
    }

    double getMedia() const{
      return media;
    }

    string getStatus() const{
      return status;
    }

};

int main() {
  //declaracao e abertura de arquivo 
  ifstream dados ("entrada_q3.txt");

  //verificacao de arquivo
  if(dados.is_open()){
    cout << "Arquivo entrada_q3.txt aberto" << endl;
  }else{
    cout << "entrada_q3.txt não pode ser aberto" << endl;
  }

  //criacao de vetor para entrada dos dados e string de linha para uso da função ss
  vector<Dados_Alunos> aluno;
  string linha;
  
  //laco para captura de dados e definicao de status
  while(getline(dados, linha)){
    istringstream ss(linha);
    string nome, status;
    double n1, n2, n3, media;
    
    if(ss >> nome >> n1 >> n2 >> n3){
      media = ((n1 + n2 + n3)/3.0);
      if(media >= 7.0){
        status = "Aprovado";
      }else{
        status = "Reprovado";
      }
      Dados_Alunos entradas(nome, n1, n2, n3, media, status);
      aluno.push_back(entradas);
    }
    
  }

  //fechar arquivo
  dados.close();

  //gerar arquivo de saida
  ofstream dados_saida ("saida_q3.txt");

  //conferindo se está aberto
  if(dados_saida.is_open()){
    cout << "Arquivo saida_q3.txt aberto" << endl;
  }else{
    cout << "saida_q3.txt não pode ser aberto" << endl;
  }

  //laço para armazenamento de dados no arquivo
  for(const auto& saida : aluno) {
    dados_saida << saida.getNome() << "  " << saida.getMedia() << fixed << setprecision(1) << "  " << saida.getStatus() << endl;
  }

  //fechamento de arquivo
  dados_saida.close();

  return 0;
}