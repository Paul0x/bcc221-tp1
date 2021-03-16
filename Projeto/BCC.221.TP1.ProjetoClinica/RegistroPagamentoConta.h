/***************************************************************************
 *  Trabalho Prático 1 - Programação Orientada a Objetos BCC 221 - 2020.1
 *  Paulo Felipe Possa Parreira - 12.2.1165
 *  paulof@ufop.edu.br
 *  02/2021
 ***************************************************************************/

#ifndef REGISTROPAGAMENTOCONTA_H
#define REGISTROPAGAMENTOCONTA_H
#include <string>
#include <iostream>
#include <string.h>

using namespace std;
class RegistroPagamentoConta {
public:
    RegistroPagamentoConta();
    RegistroPagamentoConta(const RegistroPagamentoConta& orig);
    virtual ~RegistroPagamentoConta();
    void setDtPagamento(string dtPagamento);
    string getDtPagamento() const;
    void setDtVencimento(string dtVencimento);
    string getDtVencimento() const;
    void setDescricao(string descricao);
    string getDescricao() const;
private:
    char descricao[100];
    char dtVencimento[11];
    char dtPagamento[11];

};

#endif /* REGISTROPAGAMENTOCONTA_H */

