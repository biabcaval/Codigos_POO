#include <iostream>
#include <vector>

using std::cout;
using std::cin;
using std::string;
using std::endl;
using std::vector;

class Cliente{
private:
    string Nome;
    string Cpf;
    string Endereco;

public:

    Cliente(string nome = "", string cpf = "", string endereco = ""){
        Nome = nome;
        Cpf = cpf;
        Endereco = endereco;
    }

    // sets 
    void setName(string n){Nome = n;}

    void setCpf(string c){Cpf = c;}

    void setEnde(string e){Endereco = e;}

    // gets

    string getName(){return Nome;}

    string getCpf(){return Cpf;}

    string getEnde(){return Endereco;}

    // print info 

    void print_info(){
        cout<<"Nome: "<< Nome <<endl;
        cout<<"Cpf: "<< Cpf <<endl;
        cout<<"Endereco: "<< Endereco <<endl;
    }

};

class Operacoes{
private:
    char tipo_op; // C ou D
    float Valor;

public:
    // lista de operações
    Operacoes(char t, float v){
        tipo_op = t;
        Valor = v;
    }

    // sets

    void setOp(char op){tipo_op = op;}

    void setValor(float v){Valor = v;}

    // gets

    char getOp(){return tipo_op;}

    float getValor(){return Valor;}

    // print info

    void print_info(){
        cout<<"Tipo: "<< tipo_op <<endl;
        cout<<"Valor: "<< Valor <<endl;
    }

    
};

class Conta{
private:
    int id;
    float saldo;
    Cliente* Cliente_associado;
    vector <Operacoes> Lista_op;


public:
    // método construtor que atribui os valores a uma conta
    Conta(int i, float s, Cliente* c){
        id = i;
        saldo = s;
        Cliente_associado = c;
    }

    // sets
    void setId(int i){id = i;}

    void setSaldo(float s){saldo = s;}

    void setCliente(Cliente* c){Cliente_associado = c;}

    // gets

    int getId(){return id;}

    float getSaldo(){return saldo;}

    Cliente* getCliente(){return Cliente_associado;}
    
    // método destrutor, porque criamos um array dinâmico
    ~Conta(){Lista_op.clear();}
     
     void add_op(Operacoes o){ // Aplica a operação na conta do cliente
        Lista_op.push_back(o);

        if(o.getOp() == 'C'){
            saldo += o.getValor();
        }
        else if (o.getOp() == 'D'){
            saldo -= o.getValor();
        }
     }

    // exibe as informações das operações realizadas pela conta
     void print_info(){
        cout<<"ID: "<<id<<endl;
        cout<<"Nome: "<< Cliente_associado->getName()<<endl;
        cout<<"Saldo: "<<saldo<<endl;
        cout<<"Operações realizadas: "<<endl;

        for(int i = 0; i < Lista_op.size(); i++){
            Lista_op[i].print_info();
        }
        cout<<"Fim da lista de operações da conta de id "<<id<<"\n"<<endl;       
     }





};

class Banco{
private:
    vector <Conta> lista_contas;

public:
    int id;

    Banco(int c){id = c;} // método construtor
    ~Banco(){lista_contas.clear();} // método destrutor

    void addConta(Conta conta){
        lista_contas.push_back(conta);     // adiciona uma conta a lista
    }

    void remvConta(Conta conta){ // remove uma conta da lista
        for(int i = 0; i < lista_contas.size(); i++){
            if(lista_contas[i].getId() == conta.getId())
                lista_contas.erase(lista_contas.begin() + i);
        }
    }

    // gets

    int getId(){return id;} // retorna o id da conta

    Conta* getConta(int id){   // retorna uma conta baseado em um id dado
        for(int i = 0; i < lista_contas.size(); i++){
            if(lista_contas[i].getId() == id){
                return &lista_contas[i];
            }
        }
        return NULL;
    }

    void transfere(Conta* c1, Conta* c2, float valor){
        Operacoes o1('C', valor);
        Operacoes o2('D', valor);

        c1->add_op(o1);
        c2->add_op(o2);
    }

    void print_info(){
        cout<<"Contas: "<<endl;

        for(int i= 0; i < lista_contas.size(); i++){
            lista_contas[i].print_info();
        }
    }

};




int main(void){
    Cliente *c1 = new Cliente("Bia", "118.661.84-09", "av cairu");
    Cliente *c2 = new Cliente("Jessica", "111.222.33-44", "manaíra");

    Conta *conta1 = new Conta(1, 100.00, c1);
    Conta *conta2 = new Conta(2, 100.00, c2);

    Banco *banco1 = new Banco(1);

    banco1->addConta(*conta1);
    banco1->addConta(*conta2);

    banco1->transfere(banco1->getConta(1), banco1->getConta(2), 100); 
    /* operações realizadas dentro da classe devem usar as variáveis localizadas dentro da classe, 
    se nesse caso eu colocasse (conta1, conta2, 100), ele até alteraria o valor mas não dentro de banco
    banco1->transfere(conta1,conta2, 100);
    banco1->print_info();
    */

    banco1->print_info();

}

