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
#include "Funcionario.h"
#include <Usuario.h>
#include <Administrador.h>
#include <AssistenteAdministrativo.h>
#include <Especialista.h>
#include "RegistroPagamentoConta.h"
#include "RegistroPagamentoConsulta.h"
#include "FileHelper.h"
#include <functional>
#include <typeinfo>
#include <map>
#include <utils.h>
#ifdef __cplusplus__
#include <cstdlib>
#else
#include <stdlib.h>
#endif
#include <memory>

using namespace std;
class SistemaClinica {
public:
    SistemaClinica();
    SistemaClinica(const SistemaClinica& orig);
    virtual ~SistemaClinica();
    FileHelper fileHelper;
    void initUsuarios();
    void initTelaLogin();
    void initSistema();
    void executarAcaoMenu(string);
    void initAgendaScreen();
    void initRecebimentoConsultasScreen();
    void initPagamentoContasScreen();
    void initFolhaPontoScreen();
    void initGerenciamentoUsuariosScreen();
    void inserirRecebimentoConsulta();
    void listaConsultasRecebidas();
    void inserirRecebimentoConta();
    void listaContasInseridas();
    void cadastrarUsuario();
    void removerUsuario();
private:
    vector<std::shared_ptr<Usuario>> usuarios;
    map<time_t, RegistroPagamentoConsulta*> consultas;
    vector<std::shared_ptr<RegistroPagamentoConta>> contas;
    std::shared_ptr<Usuario> currentUsuario;
};

#endif /* SISTEMACLINICA_H */

