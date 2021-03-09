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
    string descricao;
    string dtVencimento;
    string dtPagamento;

};

#endif /* REGISTROPAGAMENTOCONTA_H */

