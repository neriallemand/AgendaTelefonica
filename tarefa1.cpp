#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Contato{
    private:
        string n;
        long long int t;
        string e;
        string r;
    public:
        Contato(string nome, long long int telefone, string endereco = " ", string relacao = " "){
            this->n = nome;
            this->t = telefone;
            this->e = endereco;
            this->r = relacao;
        }
        void ToString(){ cout << "NOME: " << this->n << "\nTELEFONE: " << this->t << "\nENDERECO: " << this->e << "\nRELACAO: " << this->r << "\n\n"; }
        /*Nao usei*/ void SetNome(string nome){ this->n = nome; }
        void SetTelefone(long long int telefone){ this->t = telefone; }
        void SetEndereco(string endereco){ this->e = endereco; }
        void SetRelacao(string relacao){ this->r = relacao; }
        string GetNome(){ return this->n; }
        /*Nao usei*/ long long int GetTelefone(){ return this->t; }
        /*Nao usei*/ string GetEndereco(){ return this->e; }
        /*Nao usei*/ string GetRelacao(){ return this->r; }

};

class Agenda{
    private:
        Contato *contatos[1000];
        int ultimo;
    public:
        Agenda(){
            int i;
            for(i=0; i<1000; i++){ this->contatos[i] = NULL; }
            this->ultimo = -1;
        }
        void Listar(){
            int i;
            for(i=0; i<=this->ultimo; i++){ this->contatos[i]->ToString(); }
        }
        void Inserir(string nome, long long int telefone, string endereco = " ", string relacao = " "){
            int i, flag=-1;
            for(i=0; i<=this->ultimo; i++){
                string n = this->contatos[i]->GetNome();
                if(nome == n){
                    flag = i;
                    break;
                }
            }
            if(flag == -1){
                this->ultimo++;
                this->contatos[ultimo] = new Contato(nome, telefone, endereco, relacao);
            }
            else{
                this->contatos[flag]->SetTelefone(telefone);
                this->contatos[flag]->SetEndereco(endereco);
                this->contatos[flag]->SetRelacao(relacao);
            }
        }
        void Remover(string nome){
            int i;
            for(i=0; i<=this->ultimo; i++){
                string n = this->contatos[i]->GetNome();
                if(nome == n){
                    system("cls");
                    int c;
                    this->contatos[i]->ToString();
                    cout << "Tem certeza de que deseja remover o contato?" << "\n" << "1- Sim" << "\n" << "2- Nao" << "\n" << "OP: ";
                    cin >> c;
                    if(c == 1){
                        delete this->contatos[i];
                        this->contatos[i] = this->contatos[this->ultimo];
                        this->contatos[this->ultimo] = NULL;
                        this->ultimo--;
                    }
                    break;
                }
            }
        }
        void Alterar(string nome, long long int telefone, string endereco, string relacao = " "){
            int i;
            for(i=0; i<=this->ultimo; i++){
                string n = this->contatos[i]->GetNome();
                if(nome == n){
                    this->contatos[i]->SetTelefone(telefone);
                    this->contatos[i]->SetEndereco(endereco);
                    this->contatos[i]->SetRelacao(relacao);
                    break;
                }
            }
        }
        Contato *Buscar(string nome){
            int i;
            for(i=0; i<=this->ultimo; i++){
                string n = this->contatos[i]->GetNome();
                if(nome == n){ return this->contatos[i]; }
            }
            for(i=0; i<=this->ultimo; i++){
                string n = this->contatos[i]->GetNome();
                int j, flag = 0;
                for(j=0; j<nome.size(); j++){
                    if(nome[j] != n[j]){ flag = 1; }
                }
                if(flag == 0){ return this->contatos[i]; }
            }
            return NULL;
        }
        void Salvar(){

        }
        void Carregar(){

        }
};

int main(){
    Agenda a;

    /*
    a.Inserir("Fulano", 99999999, "Rua A");
    a.Inserir("Ciclano", 88888888, "Rua B");
    a.Inserir("Beltrano", 88889999, "Rua C");
    a.Inserir("Fulano", 77777777, "Rua D");
    a.Remover("Ciclano");
    a.Listar();
    */

    int op = 0;
    while(op != 6){
        system("cls");
        cout << "1- Inserir\n" << "2- Remover\n" << "3- Alterar\n" << "4- Buscar\n" << "5- Listar\n" << "6- Sair\n";
        cin >> op;
        system("cls");
        if(op == 1){
            string nome;
            long long int telefone;
            string endereco;
            string relacao;
            cout << "NOME: ";
            fflush(stdin);
            getline(cin, nome);
            cout << "TELEFONE: ";
            cin >> telefone;
            cout << "ENDERECO: ";
            fflush(stdin);
            getline(cin, endereco);
            cout << "RELACAO: ";
            fflush(stdin);
            getline(cin, relacao);
            a.Inserir(nome, telefone, endereco, relacao);
        }
        else if(op == 2){
            string nome;
            cout << "NOME: ";
            fflush(stdin);
            getline(cin, nome);
            a.Remover(nome);
        }
        else if(op == 3){
            string nome;
            long long int telefone;
            string endereco;
            string relacao;
            cout << "NOME: ";
            fflush(stdin);
            getline(cin, nome);
            cout << "TELEFONE: ";
            cin >> telefone;
            cout << "ENDERECO: ";
            fflush(stdin);
            getline(cin, endereco);
            cout << "RELACAO: ";
            fflush(stdin);
            getline(cin, relacao);
            a.Alterar(nome, telefone, endereco, relacao);
        }
        else if(op == 4){
            string nome;
            Contato *t = NULL;
            cout << "NOME: ";
            fflush(stdin);
            getline(cin, nome);
            t = a.Buscar(nome);
            system("cls");
            if(t != NULL) t->ToString();
            else cout << "Contato inexistente";
            system("pause");
        }
        else if(op == 5){
            a.Listar();
            system("pause");
        }
        else if(op == 6){ }
    }
return 0;
}
