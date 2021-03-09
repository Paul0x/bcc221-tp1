/***************************************************************************
 *  Trabalho Prático 1 - Programação Orientada a Objetos BCC 221 - 2020.1
 *  Paulo Felipe Possa Parreira - 12.2.1165
 *  paulof@ufop.edu.br
 *  02/2021
 ***************************************************************************/

#ifndef REGISTROPONTO_H
#define REGISTROPONTO_H

#include <iostream>
#include <string>
#include <utils.h>
using namespace std;
class RegistroPonto {
public:
    RegistroPonto();
    RegistroPonto(const RegistroPonto& orig);
    virtual ~RegistroPonto();
    void setObservacao(string observacao);
    string getObservacao() const;
    void setTimestamp();
    time_t getTimestamp() const;
    void setDtRegistro(string dtRegistro);
    string getDtRegistro() const;
private:
    string dtRegistro;
    time_t timestamp;
    string observacao;

};

#endif /* REGISTROPONTO_H */

