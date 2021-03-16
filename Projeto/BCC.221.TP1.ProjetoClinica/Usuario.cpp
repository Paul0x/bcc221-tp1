/***************************************************************************
 *  Trabalho Prático 1 - Programação Orientada a Objetos BCC 221 - 2020.1
 *  Paulo Felipe Possa Parreira - 12.2.1165
 *  paulof@ufop.edu.br
 *  02/2021
 ***************************************************************************/

#include "Usuario.h"
using namespace std;
Usuario::Usuario() {
}

Usuario::Usuario(const Usuario& orig) {
}

Usuario::~Usuario() {
}

void Usuario::setNome(string nome) {
    const char *tmpChar = nome.data();
    int length = nome.size();
    length = (length < 50 ? length : 49);
    strncpy(this->nome, tmpChar, length);
    this->nome[ length ] = '\0';
}

string Usuario::getNome() const {
    return nome;
}

void Usuario::setSenha(string senha) {
    const char *tmpChar = senha.data();
    int length = senha.size();
    length = (length < 50 ? length : 49);
    strncpy(this->senha, tmpChar, length);
    this->senha[ length ] = '\0';
}

string Usuario::getSenha() const {
    return senha;
}

void Usuario::setLogin(string login) {
    const char *tmpChar = login.data();
    int length = login.size();
    length = (length < 50 ? length : 49);
    strncpy(this->login, tmpChar, length);
    this->login[ length ] = '\0';
}

string Usuario::getLogin() const {
    return login;
}

void Usuario::setEmail(string email) {
    const char *tmpChar = email.data();
    int length = email.size();
    length = (length < 50 ? length : 49);
    strncpy(this->email, tmpChar, length);
    this->email[ length ] = '\0';
}

string Usuario::getEmail() const {
    return email;
}

void Usuario::setCpf(string cpf) {
    const char *tmpChar = cpf.data();
    int length = cpf.size();
    length = (length < 14 ? length : 13);
    strncpy(this->cpf, tmpChar, length);
    this->cpf[ length ] = '\0';
}

string Usuario::getCpf() const {
    return cpf;
}

void Usuario::setCodigo(int codigo) {
    this->codigo = codigo;
}

int Usuario::getCodigo() const {
    return codigo;
}

string Usuario::imprimirMenu() {
    cout << "=============================================" << endl;
    cout << "Bem vindo(a) ao sistema de gerenciamento da clinica odontologica" << endl;
    cout << "Usuário Logado: " << this->nome << " Tipo: Usuário Coum" << endl;
    cout << "=============================================" << endl;
    cout << "Digite:" << endl << "1 - Agenda" << endl << "2 - Sair" << endl;
    int opcao;
    cin >> opcao;
    switch(opcao) {
        case 1:
            return "ag";
            break;
        case 2:
            return "ex";
            break;
    }
}

void Usuario::buildFromUsuario(Usuario &usuario) {
    this->codigo = usuario.getCodigo();
    this->setCpf(usuario.getCpf());
    this->setEmail(usuario.getEmail());
    this->setLogin(usuario.getLogin());
    this->setNome(usuario.getNome());
    this->setSenha(usuario.getSenha());
}