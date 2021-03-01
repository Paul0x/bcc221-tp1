/***************************************************************************
 *  Trabalho Prático 1 - Programação Orientada a Objetos BCC 221 - 2020.1
 *  Paulo Felipe Possa Parreira - 12.2.1165
 *  paulof@ufop.edu.br
 *  02/2021
 ***************************************************************************/

#ifndef ASSISTENTEADMINISTRATIVO_H
#define ASSISTENTEADMINISTRATIVO_H

#include "Usuario.h"

class AssistenteAdministrativo: public Usuario{
public:
    AssistenteAdministrativo();
    AssistenteAdministrativo(const AssistenteAdministrativo& orig);
    virtual ~AssistenteAdministrativo();
    virtual void imprimirMenu();
    void setFolhaPonto(vector<std::reference_wrapper<RegistroPonto> > folhaPonto);
    vector<std::reference_wrapper<RegistroPonto> > getFolhaPonto() const;
private:
    vector<std::reference_wrapper<RegistroPonto>> folhaPonto;

};

#endif /* ASSISTENTEADMINISTRATIVO_H */

