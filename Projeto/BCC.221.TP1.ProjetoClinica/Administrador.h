/***************************************************************************
 *  Trabalho Prático 1 - Programação Orientada a Objetos BCC 221 - 2020.1
 *  Paulo Felipe Possa Parreira - 12.2.1165
 *  paulof@ufop.edu.br
 *  02/2021
 ***************************************************************************/


#ifndef ADMINISTRADOR_H
#define ADMINISTRADOR_H
#include <Usuario.h>
#include "RegistroPonto.h"
#ifdef __cplusplus__
#include <cstdlib>
#else
#include <stdlib.h>
#endif
#include <iostream>
#include <vector>
#include <functional>


class Administrador : public Usuario {
public:
    Administrador();
    Administrador(const Administrador& orig);
    virtual ~Administrador();
    virtual string imprimirMenu();
    
    const std::string& getNomeClasse() const override
    {
      static const std::string nome{"Administrador"};
      return nome;
    }
private:

};

#endif /* ADMINISTRADOR_H */

