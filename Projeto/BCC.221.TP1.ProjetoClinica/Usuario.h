/***************************************************************************
 *  Trabalho Prático 1 - Programação Orientada a Objetos BCC 221 - 2020.1
 *  Paulo Felipe Possa Parreira - 12.2.1165
 *  paulof@ufop.edu.br
 *  02/2021
 ***************************************************************************/

using namespace std;
#ifndef USUARIO_H
#define USUARIO_H
#include<string>
#include<string.h>
#include<iostream>

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
    void setCodigo(int codigo);
    int getCodigo() const;
    void buildFromUsuario(Usuario &usuario);
    virtual string imprimirMenu();
    virtual const std::string& getNomeClasse() const {        
      static const std::string nome{"Usuario"};
      return nome;
    }
protected:
    char nome[50];
    char cpf[14];
    char email[50];
    char login[50];
    char senha[50];
    int codigo;
    
};

#endif /* USUARIO_H */

