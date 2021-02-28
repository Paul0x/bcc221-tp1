/***************************************************************************
 *  Trabalho Prático 1 - Programação Orientada a Objetos BCC 221 - 2020.1
 *  Paulo Felipe Possa Parreira - 12.2.1165
 *  paulof@ufop.edu.br
 *  02/2021
 ***************************************************************************/
#include<string>
#include<iostream>

using namespace std;
#ifndef USUARIO_H
#define USUARIO_H

class Usuario {
public:
    Usuario();
    Usuario(const Usuario& orig);
    virtual ~Usuario();
    void setNome(string nome);
    string getNome() const;
    void setSenha(string senha);
    string getSenha() const;
    void setLogin(string login);
    string getLogin() const;
    void setEmail(string email);
    string getEmail() const;
    void setCpf(string cpf);
    string getCpf() const;
    void imprimirMenu();
    
private:
    string nome;
    string cpf;
    string email;
    string login;
    string senha;
    
};

#endif /* USUARIO_H */

