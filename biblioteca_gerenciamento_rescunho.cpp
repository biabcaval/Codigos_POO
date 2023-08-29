#include <iostream>
#include <vector>
#include <string.h>

using std::string;
using std::cout;
using std::vector;
using std::cin;

class Autor{
private:
  string nome;
  string nacionalidade;
  int idade;
public:
// método construtor
  Autor(string n, string na, int i){
    nome = n;
    nacionalidade = na;
    idade = i;
  }
// método destrutor
  ~Autor(){}

  // gets

  string getNome(){return nome;}
  string getNacio(){return nacionalidade;}
  int getIdade(){return idade;}

  // sets

  void setNome(string n){nome = n;}
  void setNacio(string na){nacionalidade = na;}
  void setIdade(int i){idade = i;}

};


class Livro{
private:
  string nome;
  Autor* autor;
  int ano_lanc;
public:
  // método construtor
  Livro(string n, Autor* a, int l){
    nome = n;
    autor = a;
    ano_lanc = l;
  }
  // método destrutor

  ~Livro(){}

  // gets

  string getNome(){return nome;}
  Autor getAutor(){return *autor;}
  int getAno(){return ano_lanc;}

  // sets

  void setNome(string n){nome = n;}
  void setAutor(string a){autor = a;}
  void setAno(int l){ano_lanc = l;}

};

class Acervo{
private:
  vector <Livro> estoque_livros;
  int quant_livros = estoque_livros.size();


public:
    void add_estoque(Livro livro){
      estoque_livros.push_back(livro);
    }

  void Emprestimo(Livro livro){
    for(int i = 0; i < quant_livros; i++ ){
      if(estoque_livros[i].getNome() == livro.getNome()){
        
      }
    }
  } 

};

