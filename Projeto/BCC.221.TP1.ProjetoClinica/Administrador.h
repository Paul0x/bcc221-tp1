/***************************************************************************
 *  Trabalho Prático 1 - Programação Orientada a Objetos BCC 221 - 2020.1
 *  Paulo Felipe Possa Parreira - 12.2.1165
 *  paulof@ufop.edu.br
 *  02/2021
 ***************************************************************************/


#ifndef ADMINISTRADOR_H
#define ADMINISTRADOR_H
#include<Usuario.h>
class Administrador: public Usuario{ 
public:
    Administrador();
    Administrador(const Administrador& orig);
    virtual ~Administrador();
    virtual void imprimirMenu();
private:

};

#endif /* ADMINISTRADOR_H */

