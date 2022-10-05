#include "..\inc\banco.h"
#include <iostream>
#include <cstdlib>

using namespace std;

Banco::Banco() //O construtor criara 4 contas
{
    this->contas[0] = Conta(1234, 1, "Joao", "Corrente", 300);
    this->contas[1] = {4567, 2, "Jose", "Poupanca", 800};
    this->contas[2] = {7890, 3, "Maria", "Corrente", 1000};
    this->contas[3] = {8956, 4, "Madalena", "Poupanca", 2000};
}

Banco::~Banco()
{
}


void Banco::atendimento() //Realiza o atendimento ao cliente(Função chamada na main)
{   
    Conta *contaCliente; //ponteiro do tipo conta
    int numC = 0;
    int senhain;
    bool atendimento1 = true;
    bool atendimento2 = true;

    while(atendimento1)
    {
        cout << "\n\t\t\tBem vindo ao sistema de atendimento do banco" << endl;
        cout << "\n\nDigite o numero da sua conta: ";
        cin >> numC;
        atendimento2 = true;
        contaCliente = this->buscaConta(numC); //Chama o Metodo buscaConta() do banco para achar o objeto conta que possui o numero numC
        //contaCliente será o endereço de memória da conta[i] ou nullptr

        if (contaCliente == nullptr)//Se não achar nenhuma conta que corresponda entra nesse if
        {
            cout << "\n\n\t\t\tConta invalida!" << endl <<endl;
        }
        else
        {
            cout << "\nDigite a sua senha: ";
            cin >> senhain;

            if (contaCliente->validaSenha(senhain))
            {
                cout << "\n\n\t\t\t\t\t\tOla " << contaCliente->titular << "!" <<endl;
                while (atendimento2) //Realiza o atendimento
                {
                    int op;
                    double valor;
                    cout << "\n\nQual operacao deseja fazer? (1 - Saque, 2 - Deposito, 3 - Ver Saldo, 4 - Transferencia, 5 - Sair): ";
                    cin >> op;
                    cout << endl;
                    switch (op)
                    {
                    case 1:
                        cout << "Digite o valor: ";
                        cin>>valor;
                        contaCliente->saque(senhain,valor);
                        break;

                    case 2:
                        cout << "Digite o valor: ";
                        cin>>valor;
                        contaCliente->deposito(valor);
                        cout << "\n\n\t\t\tDeposito realizado com sucesso!\n";
                        break;

                    case 3:
                        cout << "Saldo: R$ "<<contaCliente->getSaldo(senhain)<<endl;
                        break;

                    case 4:
                        cout << "Valor a ser transferido: ";
                        cin >> valor;
                        contaCliente->transferenciaPasso1(valor);

                        cout << "\nConta para qual tranferir: ";
                        cin >> numC; 
                        Conta *contaCliente2;
                        contaCliente2 = this->buscaConta(numC);
                        if (contaCliente2 == nullptr)
                        {
                            cout << "\n\t\t\tConta invalida!" << endl;
                            break;
                        }
                        else
                        {
                            contaCliente2->transferenciaPasso2(valor);
                        }
                        break;
                        
                    case 5:
                        atendimento2 = false;
                        break; 
                    }
                    cout << endl;
                    system("pause");
                }
            }
            else
            {
                cout << "\nSenha invalida" << endl;
            }
        }
        
        cout << "\nDeseja entrar em outra conta? (1 - Sim, 0 - Nao): ";
        cin >> atendimento1;
        cout <<endl<<endl; 
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
