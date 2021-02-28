/***************************************************************************
 *  Trabalho Prático 1 - Programação Orientada a Objetos BCC 221 - 2020.1
 *  Paulo Felipe Possa Parreira - 12.2.1165
 *  paulof@ufop.edu.br
 *  02/2021
 ***************************************************************************/

#ifndef ESPECIALISTA_H
#define ESPECIALISTA_H

#include "Usuario.h"


class Especialista: public Usuario{
public:
    Especialista();
    Especialista(const Especialista& orig);
    virtual ~Especialista();
private:

};

#endif /* ESPECIALISTA_H */

