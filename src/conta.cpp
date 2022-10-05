#include "..\inc\conta.h"
#include <iostream>

Conta::Conta()
{
    this->numero = 0;
    this->senha = 1111;
    this->titular = "Nenhum";
    this->saldo = 0;
}

Conta::Conta(int senha, int numero, std::string titular, std::string tipo, double saldo)
{
    this->senha = senha;
    this->numero = numero;
    this->titular = titular;
    this->tipo = tipo;
    if(saldo>0)
    {
        this->saldo = saldo;
    }
    else
    {
        std::cout<<"Saldo inicial invalido"<<std::endl;
    }    
}

Conta::~Conta()
{
}

void Conta::exibeDados()
{
    std::cout<< "Titular: "<<this->titular<<std::endl;
    std::cout<< "Numero: "<<this->numero<<std::endl;
    std::cout<< "Tipo: "<<this->tipo<<std::endl;
}

double Conta::getSaldo(int senha)
{
   /* if(senha==this->senha)
    {   */
        return this->saldo;
    //}
    /*else
    {
        std::cout<<"Senha inválida"<<std::endl;
        return -10000000;
    }    */

}

void Conta::setSaldo(double valor)
{
    this->saldo = valor;
}

void Conta::setSenha(int novaSenha)
{
    this->senha = novaSenha;
}

void Conta::deposito(double valor)
{
    if(valor>0)
    {
        this->saldo+=valor;
    }
    else
    {
        std::cout<<"\n\t\t\tValor invalido"<<std::endl;
    }
    
}

void Conta::saque(int senha, double valor)
{
    //if(senha==this->senha)
    //{
        if(this->saldo>valor)
        {
            this->saldo-=valor;
            std::cout<<"\n\n\t\t\tSaque de R$"<<valor<<" realizado com sucesso."<<std::endl;
        }
        else
        {
            std::cout<<"\n\t\t\tSaldo insuficiente"<<std::endl;
        }    
    /*}
    else
    {
        std::cout<<"Senha invalida"<<std::endl;
    }*/
    
}

bool Conta::validaSenha(int senha)
{
    if(this->senha == senha)
    {
        return true;
    }
    else
    {
        return false;
    }
    
}

void Conta::transferenciaPasso1(double valor)
{
    if(this->saldo>valor)
    {
        this->saldo -= valor;
    }
    else
    {
        std::cout<<"\n\t\t\tSaldo insuficiente"<<std::endl;
    }    
}

void Conta::transferenciaPasso2(double valor)
{
    this->saldo+=valor;
    std::cout << "\n\n\t\t\tTransferencia de R$ " << valor << " concluida com sucesso!"<<std::endl;
}
