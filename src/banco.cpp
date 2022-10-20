#include "..\inc\banco.h"
#include <iostream>
#include <cstdlib>

using namespace std;

Banco::Banco() //O construtor criara 4 contas
{
    this->contas[0] = Conta(5555, 0, "Funcionario", "Adm", 0);
    this->contas[1] = {1234, 1, "Joao", "Corrente", 300};
    this->contas[2] = {4567, 2, "Jose", "Poupanca", 800};
    this->contas[3] = {7890, 3, "Maria", "Corrente", 1000};
    this->contas[4] = {8956, 4, "Madalena", "Poupanca", 2000};
}

Banco::~Banco()
{
}


void Banco::atendimento() //Realiza o atendimento ao cliente(Função chamada na main)
{   
    int i=5;
    int atendimento=1;
    
    while(atendimento==1)
    {
        cout << "\n\t\t\tBem vindo ao sistema de atendimento do banco!\n\n" << endl;
        cout << "Voce e cliente ou gerente? (0 - Gerente | 1 - Cliente): ";
        cin >> atendimento;

        switch (atendimento)
        {
        case 0:
            atendGerente(i);
            break;
        case 1:
            atendCliente();
            break;
        default:
            cout << "\n\n\t\t\t\tEntrada invalida!"<<endl<<endl;
            system("pause");
            system("cls");
            break;
        }
        cout << "\n\nDeseja entrar em alguma conta? (0 - Nao | 1 - Sim): ";
        cin >> atendimento;
        system("cls");
        switch (atendimento)
        {
        case 0:
            break;
        case 1:
            break;
        default:
            cout << "\n\n\t\t\t\tEntrada invalida!"<<endl<<endl;
            cout << "\n\t\t\tO programa sera encerrado!"<<endl<<endl;
            system("pause");
            system("cls");
            atendimento = 0;
            break;
        cout <<endl<<endl;
        }
    }
}

Conta *Banco::buscaConta(int numero)//Retorna o endereço da conta que possuir o mesmo numero informado
{
    for (int i = 0; i < NUMCONTAS; i++)
    {
        if (numero == this->contas[i].numero)
        {
            return &this->contas[i];
        }
    }

    return nullptr;
}

void Banco::atendCliente()
{
    int senhain; 
    int numC; 
    Conta* contaCliente; // ponteiro do tipo Conta
    Conta* cDest;

    cout << "\n\nDigite o numero da sua conta: ";
    cin >> numC;
    contaCliente = this->buscaConta(numC); //Chama o Metodo buscaConta() do banco para achar o objeto conta que possui o numero numC contaCliente será o endereço de memória da conta[i] ou nullptr

    if (contaCliente == nullptr)           //Se não achar nenhuma conta que corresponda entra nesse if
    {
        cout << "\n\n\t\t\t\tConta invalida!" << endl <<endl;
    }
    else
    {
        cout << "\nDigite a sua senha: ";
        cin >> senhain;
        system("cls");
        if (contaCliente->validaSenha(senhain))
        {
            int op;
            double valor;
            bool atendimento;
            cout << "\n\n\t\t\t\t\t\tOla "<< contaCliente->titular<< "!" <<endl;
            cout << "\n\nConta " << contaCliente->tipo;
            while (atendimento) //Realiza o atendimento
            {   
                cout << "\n\nQual operacao deseja fazer? (1 - Saque | 2 - Deposito | 3 - Ver Saldo | 4 - Transferencia | 5 - Sair): ";
                cin >> op;
                cout << endl;
                switch (op)
                {
                case 1:
                    cout << "Digite o valor: ";
                    cin>>valor;
                    if(contaCliente->saque(senhain,valor))
                    {
                        cout<<"\n\n\t\t\t\tSaque de R$"<<valor<<" realizado com sucesso."<<endl;
                    }
                    break;

                case 2:
                    cout << "Digite o valor: ";
                    cin>>valor;
                    contaCliente->deposito(valor);
                    cout << "\n\n\t\t\t\tDeposito realizado com sucesso!\n";
                    break;

                case 3:
                    cout << "Saldo: R$ "<<contaCliente->getSaldo(senhain)<<endl;
                    break;

                case 4:
                    cout << "Valor a ser transferido: ";
                    cin >> valor;

                    cout << "\nConta para qual tranferir: ";
                    cin >> numC; 
                    cDest = this->buscaConta(numC);
                    if (cDest == nullptr || cDest == contaCliente)
                    {
                        cout << "\n\n\t\t\t\tConta invalida!" << endl;
                        cout << "\n\n\t\t\t\tA tranferencia nao foi concluida!";
                        break;
                    }
                    else
                    {
                        contaCliente->transferencia(senhain, valor, cDest);
                    }
                    break;
                    
                case 5:
                    atendimento = false;
                    break; 
                }
                cout << endl;
                system("pause");
                system("cls");
            }
        }
        else
        {
            cout << "\nSenha invalida!" << endl;
        }
    }
}

void Banco::atendGerente(int& i)
{   
    bool op;
    bool atendimento;
    int senhain;
    Conta* gerente = &contas[0];

    cout << "\nDigite a sua senha: ";
    cin >> senhain;
    system("cls");
    if (gerente->validaSenha(senhain))
    {
        while (atendimento)
        {   
            cout << "\n\n\t\t\t\t\t\tOla gerente!" <<endl<<endl;
            cout << "\nO que deseja fazer? (0 - Sair/Entrar em outra conta | 1 - Criar nova conta): ";
            cin >> op;
            switch (op)
            {
            case true:
                criadorConta(senhain, i);
                cout <<endl;
                system("pause");
                system("cls"); 
                cout <<endl;
                break;
            case false:
                atendimento = false;
                break;
            }
        }
    }
    else
    {
        cout << "\n\n\t\t\t\tSenha invalida!" << endl;
    }    
}

void Banco::criadorConta(int& senhain, int& i)
{
    double saldo;
    bool tipo;
    cout << "\n\nInsira o nome do titular: ";
    cin >> this->contas[i].titular;
    cout << "Insira a senha: ";
    cin >> senhain;
    this->contas[i].setSenha(senhain);
    cout << "Insira o tipo da conta (0 - Corrente | 1 - Poupanca): ";
    cin >> tipo;
    if(tipo)
    {
        this->contas[i].tipo = "Poupaca";
    }
    else
    {
        this->contas[i].tipo = "Corrente";
    }
    cout << "Insira o saldo inicial: ";
    cin >> saldo;
    this->contas[i].setSaldo(saldo);
    this->contas[i].numero = i;
    cout << "\n\t\t\tConta numero "<< i << " cadastrada com sucesso!" <<endl<<endl;
    i++;
}
