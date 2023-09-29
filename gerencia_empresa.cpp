#include <iostream>
#include <string.h>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::ostream;
using std::string;
using std::vector;

class Funcionario {
protected:
  string nome;
  int idade;
public:
  // método construtor
  Funcionario(string n, int i) : nome(n), idade(i) {}
  virtual ~Funcionario() {}

  virtual void exibir_detalhes() {
    cout << "Nome: " << this->nome << "\nIdade: " << this->idade << endl;
  }

  friend ostream &operator<<(ostream &os, const Funcionario &f) {
    os << "Nome: " << f.nome << "\nIdade: " << f.idade;
    return os;
  }

string const getNome(){return nome;}

int const getIdade(){return idade;}
};


class Gerente : public Funcionario {
  string departamento;
  string nivel_acesso;

public:
  Gerente(string n, int i, string d, string ni)
      : Funcionario(n, i), departamento(d), nivel_acesso(ni) {}
  ~Gerente() {}

  void exibir_detalhes() override {
    cout << "Departamento: " << departamento
         << "\n Nivel acesso: " << nivel_acesso << endl;
  }

  // método que atualiza o nivel de acesso
  void definir_nivel_acesso(string nivel) { nivel_acesso = nivel; }
};

class Dev : protected Funcionario {
  string ling;

public:
  // método construtor
  Dev(string n, int i, string l) : Funcionario(n, i), ling(l) {}

  void exibir_detalhes() override {
    cout << "Nome: " << this->nome << endl;
    cout << "Idade: "<< this->idade << endl;
    cout << "Linguagem de programação: " << ling << endl;
    
  }
};


class Analista : private Funcionario {
  string projeto_atual;

public:
  Analista(string n, int i, string p) : Funcionario(n, i) { projeto_atual = p; }

  void exibir_detalhes() override {
    cout << "Nome: "<< this->getNome()<<endl;
    cout << "Idade: "<< this->getIdade()<<endl;
    cout << "Projeto atual: " << projeto_atual << endl;
  }

  void altera_projeto(string p) { this->projeto_atual = p; }

  string getProjeto(){return projeto_atual;}
};

class func_estag : Dev, Analista {
  int duracao_estagio; // em anos

public:
  func_estag(string n, int i, string l, string p, int d)
      : Dev(n, i, l), Analista(n, i, p), duracao_estagio(d) {}

  void exibir_detalhes() override {
    Dev::exibir_detalhes();
    cout << "Projeto atual: "<< this->getProjeto()<<endl;
    cout << "Tempo estágio: " << duracao_estagio << endl;
  }
};

int main() {
  Dev *dev1 = new Dev("Bia", 19, "python");

  Analista *ana1 = new Analista("Paloma", 19, "Dicionário nordestês");

  func_estag *est1 = new func_estag("Lucas", 19, "RUST", "Lucasflix", 5);

  Gerente *ger1 = new Gerente("Kamily", 19, "supremo", "Bls");
  
  cout << *ger1 << endl;
  dev1->exibir_detalhes();
  ana1->exibir_detalhes();
  est1->exibir_detalhes();
  

  return 0;
}
