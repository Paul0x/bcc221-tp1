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
#include "RegistroPagamentoConsulta.h"
#include <functional>
#include <typeinfo>
#include <map>
#include <utils.h>
#ifdef __cplusplus__
#include <cstdlib>
#else
#include <stdlib.h>
#endif

using namespace std;
class SistemaClinica {
public:
    SistemaClinica();
    SistemaClinica(const SistemaClinica& orig);
    virtual ~SistemaClinica();
private:
    vector<std::reference_wrapper<Usuario>> usuarios;
    map<time_t, RegistroPagamentoConsulta*> consultas;
    vector<std::reference_wrapper<RegistroPagamentoConta>> contas;
    Usuario* currentUsuario;
    void initUsuarios();
    void initTelaLogin();
    void initSistema();
    void executarAcaoMenu(string);
    void initAgendaScreen();
    void initRecebimentoConsultasScreen();
    void initPagamentoCoontasScreen();
    void initFolhaPontoScreen();
    void initGerenciamentoUsuariosScreen();
    void inserirRecebimentoConsulta();
    void listaConsultasRecebidas();
    void inserirRecebimentoConta();
    void listaContasInseridas();
};

#endif /* SISTEMACLINICA_H */

