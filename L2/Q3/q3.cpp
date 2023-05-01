#include <iostream>
#include <vector>

using namespace std;

class Aluno{
  private:
    int matricula;
    string nome;
    float nota1;
    float nota2;
    float nota3;
  public:
    //constructor
    Aluno(int m, string na, float n1, float n2, float n3){
      this -> matricula = m;
      this -> nome = na;
      this -> nota1 = n1;
      this -> nota2 = n2;
      this -> nota3 = n3; 
    }
    //destructor
    ~Aluno(){
      cout << "Objeto descartado";
    }
    //getters
    int getMatricula(){
      return matricula;
    }
    string getNome(){
      return nome;
    }
    float getNota1(){
      return nota1;
    }
    float getNota2(){
      return nota2;
    }
    float getNota3(){
      return nota3;
    }
    //seterrs
    void setMatricula(int m){
      this -> matricula = m;
    }
    void setNome(string na){
      this -> nome = na;
    }
    void setNota1(float n1){
      this -> nota1 = n1;
    }
    void setNota2(float n2){
      this -> nota2 = n2;
    }
    void setNota3(float n3){
      this -> nota3 = n3;
    }
    //media
    float media(){
      return (nota1 + nota2 + nota3)/3.0;
    }
};

class Turma {
  private:
    int capacidade;
    int vagas;
    vector<Aluno*> alunos;
    string campoOrdenacao;

  public:
    // Constructor
    Turma(int cap) {
      this->capacidade = cap;
      this->vagas = cap;
    }

    // Destructor
    ~Turma() {}

    // Getters
    int getCapacidade() {
      return capacidade;
    } 
    int getVagas() {
      return vagas;
    }

    // Setters 
    void setCapacidade(int cap) {
      this->capacidade = cap;
    }
    void setVagas(int cap) {
      this->vagas = cap;
    }
    void setCampoOrdenacao(string campo) {
      campoOrdenacao = campo;
    }

    // Adicionar alunos
    bool addAluno(Aluno* aluno) {
      if (vagas == 0) {
        return false;
      }

      alunos.push_back(aluno);
      vagas--;

      return true;
    }

    // Selection Sort por nome
    void selectionSortNome(vector<Aluno*>& alunos) {
      int n = alunos.size();
      for (int i = 0; i < n-1; i++) {
        int minIndex = i;
        for (int j = i+1; j < n; j++) {
          if (alunos[j]->getNome() < alunos[minIndex]->getNome()) {
            minIndex = j;
          }
        }
        swap(alunos[minIndex], alunos[i]);
      }
    }

    // Selection Sort por matrícula
    void selectionSortMatricula(vector<Aluno*>& alunos) {
      int n = alunos.size();
      for (int i = 0; i < n-1; i++) {
        int minIndex = i;
        for (int j = i+1; j < n; j++) {
          if (alunos[j]->getMatricula() < alunos[minIndex]->getMatricula()) {
            minIndex = j;
          }
        }
        swap(alunos[minIndex], alunos[i]);
      }
    }

    // Selection Sort por média
    void selectionSortNota(vector<Aluno*>& alunos) {
      int n = alunos.size();
      for (int i = 0; i < n-1; i++) {
        int minIndex = i;
        for (int j = i+1; j < n; j++) {
          if (alunos[j]->media() < alunos[minIndex]->media()) {
            minIndex = j;
          }
        }
        swap(alunos[minIndex], alunos[i]);
      }
    }

    // Imprimir alunos ordenados
    void imprimeAlunos() {
      if (campoOrdenacao == "nome") {
        selectionSortNome(alunos);
      } else if (campoOrdenacao == "matricula") {
        selectionSortMatricula(alunos);
      } else if (campoOrdenacao == "nota") {
        selectionSortNota(alunos);
      }

        for (int i = 0; i < capacidade; i++) {
            if (alunos[i] != nullptr) {
                cout << "Matrícula: " << alunos[i]->getMatricula() << endl;
                cout << "Nome: " << alunos[i]->getNome() << endl;
                cout << "Nota 1: " << alunos[i]->getNota1() << ", Nota 2: " << alunos[i]->getNota2() << ", Nota 3: " << alunos[i]->getNota3() << endl;
                cout << "Média: " << alunos[i]->media() << endl;
                cout << endl; 
            }
        }
    }
};


int main(){
  string escolha; 
  
  //criação dos alunos
  Aluno* Silas = new Aluno(01, "Silas", 7.6, 9.0, 6.0);
  Aluno* Eduardo = new Aluno(05, "Eduardo", 5.0, 7.0, 6.0); 
  Aluno* Rodrigues = new Aluno(90, "Rodrigues", 9.0, 5.5, 6.0);
  Aluno* Dos = new Aluno(17, "Dos", 9.5, 6.0, 5.0);
  Aluno* Santos = new Aluno(7, "Santos", 8.5, 6.6, 8.9);
  
  //tamanho da turma
  Turma lp1(60);

  //adicionar alunos a turma
  lp1.addAluno(Silas);
  lp1.addAluno(Eduardo);
  lp1.addAluno(Rodrigues);
  lp1.addAluno(Dos);
  lp1.addAluno(Santos);

  //escolha de ordenação 
  lp1.setCampoOrdenacao("nome");
  
  //imprimir alunos na sequencia de entrada
  lp1.imprimeAlunos();
  
}
