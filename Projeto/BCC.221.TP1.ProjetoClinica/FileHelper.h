/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FileHelper.h
 * Author: paulo
 *
 * Created on March 11, 2021, 8:22 AM
 */

#ifndef FILEHELPER_H
#define FILEHELPER_H
#include <iostream>
#include <vector>
#include <Usuario.h>
#include <Administrador.h>
#include <AssistenteAdministrativo.h>
#include "RegistroAgenda.h"
#include "RegistroPagamentoConta.h"
#include "RegistroPagamentoConsulta.h"
#include "RegistroPonto.h"
#include "Especialista.h"
#include <functional>
#include <typeinfo>
#include <utils.h>
#include <iomanip>
#include <fstream>
#ifdef __cplusplus__
#include <cstdlib>
#else
#include <stdlib.h>
#endif
#include <memory>

using namespace std;
class FileHelper {
public:
    FileHelper();
    FileHelper(const FileHelper& orig);
    virtual ~FileHelper();
    void registrarUsuarioArquivo(Usuario &usuarios);
    vector<std::shared_ptr<Usuario>> buscarUsuariosArquivo();
    vector<std::shared_ptr<RegistroAgenda>> buscarAgendaEspecialista(int codUsuario);
    void salvarAgendaEspecialista(vector<std::shared_ptr<RegistroAgenda>> agendaEspecialista, int codUsuario);
    vector<std::shared_ptr<RegistroPonto>> buscarPontoFuncionario(int codUsuario);
    void salvarPontoFuncionario(vector<std::shared_ptr<RegistroPonto>> folhaPonto, int codUsuario);
    vector<std::shared_ptr<RegistroPagamentoConta>> buscarPagamentoConta();
    void salvarPagamentoConta(vector<std::shared_ptr<RegistroPagamentoConta>> contas);
    
private:
};

#endif /* FILEHELPER_H */

