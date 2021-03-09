/***************************************************************************
 *  Trabalho Prático 1 - Programação Orientada a Objetos BCC 221 - 2020.1
 *  Paulo Felipe Possa Parreira - 12.2.1165
 *  paulof@ufop.edu.br
 *  02/2021
 ***************************************************************************/

#ifndef ASSISTENTEADMINISTRATIVO_H
#define ASSISTENTEADMINISTRATIVO_H

#include <iostream>
#include <vector>
#include "RegistroPonto.h"
#ifdef __cplusplus__
#include <cstdlib>
#else
#include <stdlib.h>
#endif
#include "Usuario.h"
#include <functional>

class AssistenteAdministrativo: public Usuario{
public:
    AssistenteAdministrativo();
    AssistenteAdministrativo(const AssistenteAdministrativo& orig);
    virtual ~AssistenteAdministrativo();
    virtual string imprimirMenu();
    void setFolhaPonto(vector<std::reference_wrapper<RegistroPonto> > folhaPonto);
    vector<std::reference_wrapper<RegistroPonto> > getFolhaPonto() const;
    
    const std::string& getNomeClasse() const override
    {
      static const std::string nome{"AssistenteAdministrativo"};
      return nome;
    }
private:
    vector<std::reference_wrapper<RegistroPonto>> folhaPonto;

};

#endif /* ASSISTENTEADMINISTRATIVO_H */

