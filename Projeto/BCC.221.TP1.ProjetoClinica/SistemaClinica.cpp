/***************************************************************************
 *  Trabalho Prático 1 - Programação Orientada a Objetos BCC 221 - 2020.1
 *  Paulo Felipe Possa Parreira - 12.2.1165
 *  paulof@ufop.edu.br
 *  02/2021
 ***************************************************************************/

#include <functional>
#include <typeinfo>
#ifdef __cplusplus__
#include <cstdlib>
#else
#include <stdlib.h>
#endif

#include "SistemaClinica.h"
using namespace std;

SistemaClinica::SistemaClinica() {
    this->initUsuarios();


}

SistemaClinica::SistemaClinica(const SistemaClinica& orig) {
}

SistemaClinica::~SistemaClinica() {
}

void SistemaClinica::initSistema() {
    int opcaoInicio;
    system("clear");
    cout << "=============================================" << endl;
    cout << "Bem vindo(a) ao sistema de gerenciamento da clinica odontologica" << endl;
    cout << "=============================================" << endl;
    cout << "Digite:" << endl << "1 - Fazer Login" << endl << "2 - Sair" << endl;
    cin >> opcaoInicio;
    switch (opcaoInicio) {
        case 1:
            this->initTelaLogin();
            break;
        case 2:
            exit(0);
            break;
        default:
            cout << "Opção inválida";
            this->initSistema();
    }

}

void SistemaClinica::initUsuarios() {

    Administrador admin = Administrador();
    admin.setCpf("000.000.000-99");
    admin.setEmail("admin@clinica.com");
    admin.setLogin("admin");
    admin.setSenha("admin");
    admin.setNome("Administrador");
    this->usuarios.push_back(admin);

    Especialista esp1 = Especialista();
    esp1.setCpf("000.000.000-98");
    esp1.setEmail("admin@clinica.com");
    esp1.setLogin("admin1");
    esp1.setSenha("admin1");
    esp1.setNome("Especialista 1");
    this->usuarios.push_back(esp1);

    Especialista esp2 = Especialista();
    esp2.setCpf("000.000.000-97");
    esp2.setEmail("admin@clinica.com");
    esp2.setLogin("admin2");
    esp2.setSenha("admin3");
    esp2.setNome("Especialista 2");
    this->usuarios.push_back(esp2);

    Especialista esp3 = Especialista();
    esp3.setCpf("000.000.000-96");
    esp3.setEmail("admin@clinica.com");
    esp3.setLogin("admin2");
    esp3.setSenha("admin3");
    esp3.setNome("Especialista 3");
    this->usuarios.push_back(esp3);

    cout << "Usuários inicializados com sucesso" << endl;
    for (int i = 0; i < this->usuarios.size(); i++) {
        Usuario* us = &this->usuarios[i].get();
        std::cout << typeid (us).name() << " - " << us->getNome() << endl;
    }
    this->initSistema();

}

void SistemaClinica::initTelaLogin() {
    system("clear");
    string usuario;
    string senha;
    cout << "=============================================" << endl;
    cout << "Bem vindo(a) ao sistema de gerenciamento da clinica odontologica" << endl;
    cout << "=============================================" << endl;
    cout << "Digite o login: ";
    cin >> usuario;
    system("clear");
    cout << "=============================================" << endl;
    cout << "Bem vindo(a) ao sistema de gerenciamento da clinica odontologica" << endl;
    cout << "=============================================" << endl;
    cout << "Digite a senha: ";
    cin >> senha;

    int loginFlag = 0;
    for (int i = 0; i < this->usuarios.size(); i++) {
        if (this->usuarios[i].get().getLogin() == usuario) {
            if (this->usuarios[i].get().getSenha() == senha) {
                loginFlag = 1;
                this->currentUsuario = &this->usuarios[i].get();
            }
        }
    }

    if (loginFlag == 1) {
        cout << "Login realizado com sucesso." << endl;
        system("clear");
        this->currentUsuario->imprimirMenu();
    } else {
        cout << "Não foi possível fazer o login, usuario ou senha incorretos." << endl;
        cout << "Aperte enter para retornar.";
        int w;
        cin >> w;
        this->initSistema();
    }

}