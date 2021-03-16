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
#include <string>
#include <string.h>
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
    char data[11];
    char hora[6];
    char observacao[100];
    time_t timestamp;
};

#endif /* REGISTROAGENDA_H */

