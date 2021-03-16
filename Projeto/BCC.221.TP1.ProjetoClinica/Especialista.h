/***************************************************************************
 *  Trabalho Prático 1 - Programação Orientada a Objetos BCC 221 - 2020.1
 *  Paulo Felipe Possa Parreira - 12.2.1165
 *  paulof@ufop.edu.br
 *  02/2021
 ***************************************************************************/

#ifndef ESPECIALISTA_H
#define ESPECIALISTA_H

#include "Usuario.h"
#include "RegistroPonto.h"
#ifdef __cplusplus__
#include <cstdlib>
#else
#include <stdlib.h>
#endif
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <memory>
#include "RegistroAgenda.h"
#include "Funcionario.h"

class Especialista: public Funcionario{
public:
    Especialista();
    Especialista(const Especialista& orig);
    virtual ~Especialista();
    virtual string imprimirMenu();
    void setAgenda(vector<std::shared_ptr<RegistroAgenda> > agenda);
    vector<std::shared_ptr<RegistroAgenda> > getAgenda() const;
    void mostrarAgenda();
    void adicionarRegistroAgenda();
    void editarRegistroAgenda(int);
    void removerRegistroAgenda(int);
    void sortAgenda();
    const std::string& getNomeClasse() const override
    {
      static const std::string nome{"Especialista"};
      return nome;
    }
private:
    vector<std::shared_ptr<RegistroAgenda>> agenda;

};
#endif /* ESPECIALISTA_H */

