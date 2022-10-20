<<<<<<< HEAD
#ifndef BANCO_H
#define BANCO_H

#include "conta.h"

#define NUMCONTAS 100 //Define que a palavar NUMCONTAS passa a valer como escrever 100

class Banco
{
private:
    Conta contas[NUMCONTAS];//Cria um vetor de objetos do tipo Conta que pode armazenar até 100 contas
public:
    Banco();
    ~Banco();
    Conta* buscaConta(int numero); //Metodo que retorna o endereço do objeto conta que possui o mesmo numero informado
    void atendimento();
    void criadorConta(int& senhain, int& i);
    void atendCliente();
    void atendGerente(int& i);
};


#endif
=======
#ifndef BANCO_H
#define BANCO_H

#include "conta.h"

#define NUMCONTAS 100 //Define que a palavar NUMCONTAS passa a valer como escrever 100

class Banco
{
private:
    Conta contas[NUMCONTAS];//Cria um vetor de objetos do tipo Conta que pode armazenar até 100 contas
public:
    Banco();
    ~Banco();
    Conta* buscaConta(int numero); //Metodo que retorna o endereço do objeto conta que possui o mesmo numero informado
    void atendimento();
    void criadorConta(int& senhain, int& i);
    void atendCliente();
    void atendGerente(int& i);
};


#endif
>>>>>>> 3c52623146a509838666001f3ddebe16d7c4d824
