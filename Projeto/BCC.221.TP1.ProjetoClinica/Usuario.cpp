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
    this->nome = nome;
}

string Usuario::getNome() const {
    return nome;
}

void Usuario::setSenha(string senha) {
    this->senha = senha;
}

string Usuario::getSenha() const {
    return senha;
}

void Usuario::setLogin(string login) {
    this->login = login;
}

string Usuario::getLogin() const {
    return login;
}

void Usuario::setEmail(string email) {
    this->email = email;
}

string Usuario::getEmail() const {
    return email;
}

void Usuario::setCpf(string cpf) {
    this->cpf = cpf;
}

string Usuario::getCpf() const {
    return cpf;
}

