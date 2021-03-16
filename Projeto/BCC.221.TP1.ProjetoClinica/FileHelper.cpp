/* 
 * File:   FileHelper.cpp
 * Author: paulo
 * 
 * Created on March 11, 2021, 8:22 AM
 */

/*
 * Classe responsável por manipular todos os arquivos do sistema
 * 
 */
#include <map>

#include "FileHelper.h"

FileHelper::FileHelper() {
}

FileHelper::FileHelper(const FileHelper& orig) {
}

FileHelper::~FileHelper() {
}

void FileHelper::registrarUsuarioArquivo(Usuario &usuario) {
    fstream usuariosFile;
    if (usuario.getNomeClasse() == "Especialista") {
        usuariosFile.open("especialistas.dat", ios::in | ios::out);
        if (!usuariosFile) {
            cerr << "File could not be opened." << endl;
            exit(1);
        }
        // Move o ponteiro para o final do arquivo
        usuariosFile.seekg(0, ios::end);
        // Grava novo usuário
        usuariosFile.write(reinterpret_cast<const char *> (&usuario),
                sizeof ( Especialista));
    } else if (usuario.getNomeClasse() == "AssistenteAdministrativo") {
        usuariosFile.open("assistentes.dat", ios::in | ios::out);
        if (!usuariosFile) {
            cerr << "File could not be opened." << endl;
            exit(1);
        }
        // Move o ponteiro para o final do arquivo
        usuariosFile.seekg(0, ios::end);
        // Grava novo usuário
        usuariosFile.write(reinterpret_cast<const char *> (&usuario),
                sizeof ( AssistenteAdministrativo));
    } else if (usuario.getNomeClasse() == "Administrador") {
        usuariosFile.open("administradores.dat", ios::in | ios::out);
        if (!usuariosFile) {
            cerr << "File could not be opened." << endl;
            exit(1);
        }
        // Move o ponteiro para o final do arquivo
        usuariosFile.seekg(0, ios::end);
        // Grava novo usuário
        usuariosFile.write(reinterpret_cast<const char *> (&usuario),
                sizeof ( Administrador));
    }

}

vector<std::shared_ptr<Usuario>> FileHelper::buscarUsuariosArquivo() {
    fstream usuariosFile;
    vector<std::shared_ptr < Usuario>> usuarios;
    usuariosFile.open("especialistas.dat", ios::in | ios::out);

    Especialista espObj;
    usuariosFile.seekg(0);
    usuariosFile.read(reinterpret_cast<char *> (&espObj),
            sizeof ( Especialista));

    while (!usuariosFile.eof()) {
        shared_ptr<Especialista> esp = make_shared<Especialista>();
        esp->buildFromUsuario(espObj);
        usuarios.push_back(esp);
        usuariosFile.read(reinterpret_cast<char *> (&espObj),
                sizeof ( Especialista));
    }
    usuariosFile.close();

    usuariosFile.open("assistentes.dat", ios::in | ios::out);
    AssistenteAdministrativo assistenteObj;
    usuariosFile.seekg(0);
    usuariosFile.read(reinterpret_cast<char *> (&assistenteObj),
            sizeof ( AssistenteAdministrativo));

    while (!usuariosFile.eof()) {

        shared_ptr<AssistenteAdministrativo> assistente = make_shared<AssistenteAdministrativo>();
        assistente->buildFromUsuario(espObj);
        usuarios.push_back(assistente);
        usuariosFile.read(reinterpret_cast<char *> (&assistenteObj),
                sizeof ( AssistenteAdministrativo));
    }
    usuariosFile.close();

    usuariosFile.open("administradores.dat", ios::in | ios::out);
    Administrador admObj;
    usuariosFile.seekg(0);
    usuariosFile.read(reinterpret_cast<char *> (&admObj),
            sizeof ( Administrador));


    while (!usuariosFile.eof()) {
        shared_ptr<Administrador> admin = make_shared<Administrador>();
        admin->buildFromUsuario(admObj);
        usuarios.push_back(admin);
        usuariosFile.read(reinterpret_cast<char *> (&admObj),
                sizeof ( Administrador));
    }
    usuariosFile.close();
    return usuarios;

}

vector<std::shared_ptr<RegistroAgenda>> FileHelper::buscarAgendaEspecialista(int codUsuario) {
    vector<std::shared_ptr < RegistroAgenda>> agenda;

    fstream agendaFile;
    string fileName = "agenda_" + to_string(codUsuario) + ".dat";
    agendaFile.open(fileName, ios::in | ios::out);
    if (!agendaFile) {
        agendaFile.open(fileName, ios::out);
        agendaFile.close();
        agendaFile.open(fileName, ios::in | ios::out);
    }
    RegistroAgenda agendaObj;
    agendaFile.seekg(0);
    agendaFile.read(reinterpret_cast<char *> (&agendaObj),
            sizeof ( RegistroAgenda));
    while (!agendaFile.eof()) {
        shared_ptr<RegistroAgenda> reg = make_shared<RegistroAgenda>();
        reg->setData(agendaObj.getData());
        reg->setHora(agendaObj.getHora());
        reg->setObservacao(agendaObj.getObservacao());
        reg->setTimestamp();

        agenda.push_back(reg);
        agendaFile.read(reinterpret_cast<char *> (&agendaObj),
                sizeof ( RegistroAgenda));
    }
    agendaFile.close();
    return agenda;

}

void FileHelper::salvarAgendaEspecialista(vector<std::shared_ptr<RegistroAgenda>> agendaEspecialista, int codUsuario) {

    fstream agendaFile;
    string fileName = "agenda_" + to_string(codUsuario) + ".dat";
    agendaFile.open(fileName, std::ofstream::out | std::ofstream::trunc);
    agendaFile.seekg(0, ios::end);
    // Grava novo usuário
    for (int i = 0; i < agendaEspecialista.size(); i++) {
        RegistroAgenda reg;
        reg.setData(agendaEspecialista[i]->getData());
        reg.setHora(agendaEspecialista[i]->getHora());
        reg.setObservacao(agendaEspecialista[i]->getObservacao());
        reg.setTimestamp();
        agendaFile.write(reinterpret_cast<const char *> (&reg),
                sizeof ( RegistroAgenda));
    }
    agendaFile.close();

}

vector<std::shared_ptr<RegistroPonto>> FileHelper::buscarPontoFuncionario(int codUsuario) {
    vector<std::shared_ptr < RegistroPonto>> folhaPonto;

    fstream pontoFile;
    string fileName = "ponto_" + to_string(codUsuario) + ".dat";
    pontoFile.open(fileName, ios::in | ios::out);
    if (!pontoFile) {
        pontoFile.open(fileName, ios::out);
        pontoFile.close();
        pontoFile.open(fileName, ios::in | ios::out);
    }
    RegistroPonto pontoObj;
    pontoFile.seekg(0);
    pontoFile.read(reinterpret_cast<char *> (&pontoObj),
            sizeof ( RegistroPonto));
    while (!pontoFile.eof()) {
        shared_ptr<RegistroPonto> reg = make_shared<RegistroPonto>();
        reg->setDtRegistro(pontoObj.getDtRegistro());
        reg->setObservacao(pontoObj.getObservacao());
        reg->setTimestamp();

        folhaPonto.push_back(reg);
        pontoFile.read(reinterpret_cast<char *> (&pontoObj),
                sizeof ( RegistroPonto));
    }
    pontoFile.close();
    return folhaPonto;

}

void FileHelper::salvarPontoFuncionario(vector<std::shared_ptr<RegistroPonto>> folhaPonto, int codUsuario) {
    fstream pontoFile;
    string fileName = "ponto_" + to_string(codUsuario) + ".dat";
    pontoFile.open(fileName, std::ofstream::out | std::ofstream::trunc);
    pontoFile.seekg(0, ios::end);
    // Grava novo usuário
    for (int i = 0; i < folhaPonto.size(); i++) {
        RegistroPonto reg;
        reg.setDtRegistro(folhaPonto[i]->getDtRegistro());
        reg.setObservacao(folhaPonto[i]->getObservacao());
        reg.setTimestamp();
        pontoFile.write(reinterpret_cast<const char *> (&reg),
                sizeof ( RegistroPonto));
    }
    pontoFile.close();

}

vector<std::shared_ptr<RegistroPagamentoConta>> FileHelper::buscarPagamentoConta() {
    vector<std::shared_ptr < RegistroPagamentoConta>> contas;

    fstream contasFile;
    string fileName = "contas.dat";
    contasFile.open(fileName, ios::in | ios::out);
    if (!contasFile) {
        contasFile.open(fileName, ios::out);
        contasFile.close();
        contasFile.open(fileName, ios::in | ios::out);
    }
    RegistroPagamentoConta contaObj;
    contasFile.seekg(0);
    contasFile.read(reinterpret_cast<char *> (&contaObj),
            sizeof ( RegistroPagamentoConta));
    while (!contasFile.eof()) {
        shared_ptr<RegistroPagamentoConta> reg = make_shared<RegistroPagamentoConta>();
        reg->setDescricao(contaObj.getDescricao());
        reg->setDtPagamento(contaObj.getDtPagamento());
        reg->setDtVencimento(contaObj.getDtVencimento());

        contas.push_back(reg);
        contasFile.read(reinterpret_cast<char *> (&contaObj),
                sizeof ( RegistroPagamentoConta));
    }
    contasFile.close();
    return contas;

}

void FileHelper::salvarPagamentoConta(vector<std::shared_ptr<RegistroPagamentoConta>> contas) {

    fstream contasFile;
    string fileName = "contas.dat";
    contasFile.open(fileName, std::ofstream::out | std::ofstream::trunc);
    contasFile.seekg(0, ios::end);
    // Grava novo usuário
    for (int i = 0; i < contas.size(); i++) {
        RegistroPagamentoConta reg;
        reg.setDescricao(contas[i]->getDescricao());
        reg.setDtPagamento(contas[i]->getDtPagamento());
        reg.setDtVencimento(contas[i]->getDtVencimento());
        contasFile.write(reinterpret_cast<const char *> (&reg),
                sizeof ( RegistroPagamentoConta));
    }
    contasFile.close();

}

map<time_t, RegistroPagamentoConsulta*> FileHelper::buscarPagamentoConsulta() {
    map<time_t, RegistroPagamentoConsulta*> consultas;

    fstream consultasFile;
    string fileName = "consultas.dat";
    consultasFile.open(fileName, ios::in | ios::out);
    if (!consultasFile) {
        consultasFile.open(fileName, ios::out);
        consultasFile.close();
        consultasFile.open(fileName, ios::in | ios::out);
    }
    RegistroPagamentoConsulta consultaObj;
    consultasFile.seekg(0);
    consultasFile.read(reinterpret_cast<char *> (&consultaObj),
            sizeof ( RegistroPagamentoConsulta));
    while (!consultasFile.eof()) {
        RegistroPagamentoConsulta reg;
        reg.setData(consultaObj.getData());
        reg.setNomeCliente(consultaObj.getNomeCliente());
        reg.setDataTimestamp(consultaObj.getDataTimestamp());
        reg.setValor(consultaObj.getValor());
        consultas.insert(make_pair(reg.getDataTimestamp(), &reg));
        consultasFile.read(reinterpret_cast<char *> (&consultaObj),
                sizeof ( RegistroPagamentoConsulta));
    }
    consultasFile.close();
    return consultas;

}

void FileHelper::salvarPagamentoConsulta(map<time_t, RegistroPagamentoConsulta*> consultas) {
    fstream consultasFile;
    string fileName = "consultas.dat";
    consultasFile.open(fileName, std::ofstream::out | std::ofstream::trunc);
    consultasFile.seekg(0, ios::end);
    // Grava novo usuário
    for (auto const& consulta : consultas) {

        RegistroPagamentoConsulta reg;
        reg.setData(consulta.second->getData());
        reg.setDataTimestamp(consulta.second->getDataTimestamp());
        reg.setNomeCliente(consulta.second->getNomeCliente());
        reg.setValor(consulta.second->getValor());
        consultasFile.write(reinterpret_cast<const char *> (&reg),
                sizeof ( RegistroPagamentoConsulta));
    }

    consultasFile.close();
}