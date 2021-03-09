/***************************************************************************
 *  Trabalho Prático 1 - Programação Orientada a Objetos BCC 221 - 2020.1
 *  Paulo Felipe Possa Parreira - 12.2.1165
 *  paulof@ufop.edu.br
 *  02/2021
 ***************************************************************************/

#ifndef REGISTROPAGAMENTOCONSULTA_H
#define REGISTROPAGAMENTOCONSULTA_H

#include <iostream>
#include <string>
#include <ctime>

using namespace std;
class RegistroPagamentoConsulta {
public:
    RegistroPagamentoConsulta();
    RegistroPagamentoConsulta(const RegistroPagamentoConsulta& orig);
    virtual ~RegistroPagamentoConsulta();
    void setDataTimestamp(time_t dataTimestamp);
    time_t getDataTimestamp() const;
    void setData(string data);
    string getData() const;
    void setNomeCliente(string nomeCliente);
    string getNomeCliente() const;
    void setValor(double valor);
    double getValor() const;
private:
    double valor;
    string nomeCliente;
    string data;
    time_t dataTimestamp;
};

#endif /* REGISTROPAGAMENTOCONSULTA_H */

