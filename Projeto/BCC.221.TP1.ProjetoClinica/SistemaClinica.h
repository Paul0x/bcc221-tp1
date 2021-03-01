/***************************************************************************
 *  Trabalho Prático 1 - Programação Orientada a Objetos BCC 221 - 2020.1
 *  Paulo Felipe Possa Parreira - 12.2.1165
 *  paulof@ufop.edu.br
 *  02/2021
 ***************************************************************************/

#ifndef SISTEMACLINICA_H
#define SISTEMACLINICA_H

#include <iostream>
#include <vector>
#include <Usuario.h>
#include <Administrador.h>
#include <AssistenteAdministrativo.h>
#include <Especialista.h>

#include "RegistroPagamentoConta.h"
using namespace std;
class SistemaClinica {
public:
    SistemaClinica();
    SistemaClinica(const SistemaClinica& orig);
    virtual ~SistemaClinica();
private:
    vector<std::reference_wrapper<Usuario>> usuarios;
    vector<RegistroPagamentoConta> contas;
    Usuario* currentUsuario;
    void initUsuarios();
    void initTelaLogin();
    void initSistema();

};

#endif /* SISTEMACLINICA_H */

