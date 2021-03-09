/***************************************************************************
 *  Trabalho Prático 1 - Programação Orientada a Objetos BCC 221 - 2020.1
 *  Paulo Felipe Possa Parreira - 12.2.1165
 *  paulof@ufop.edu.br
 *  02/2021
 ***************************************************************************/

#ifndef REGISTROAGENDA_H
#define REGISTROAGENDA_H

#include <iostream>
#include <vector>
#include <functional>
#include <typeinfo>
#ifdef __cplusplus__
#include <cstdlib>
#else
#include <stdlib.h>
#endif

using namespace std;
class RegistroAgenda {
public:
    RegistroAgenda();
    RegistroAgenda(const RegistroAgenda& orig);
    virtual ~RegistroAgenda();
    void setObservacao(string observacao);
    string getObservacao() const;
    void setData(string data);
    string getData() const;
    void setHora(string data);
    string getHora() const;
    time_t getTimestamp() const;
    void setTimestamp();
private:
    string data;
    string hora;
    string observacao;
    time_t timestamp;
};

#endif /* REGISTROAGENDA_H */

