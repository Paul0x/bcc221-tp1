/***************************************************************************
 *  Trabalho Prático 1 - Programação Orientada a Objetos BCC 221 - 2020.1
 *  Paulo Felipe Possa Parreira - 12.2.1165
 *  paulof@ufop.edu.br
 *  02/2021
 ***************************************************************************/

#include <functional>

#include "SistemaClinica.h"
using namespace std;

SistemaClinica::SistemaClinica() {
    this->initUsuarios();
    
    
    
}

SistemaClinica::SistemaClinica(const SistemaClinica& orig) {
}

SistemaClinica::~SistemaClinica() {
}

void SistemaClinica::initUsuarios() {
    
    Administrador admin = Administrador();
    admin.setCpf("000.000.000-99");
    admin.setEmail("admin@clinica.com");
    admin.setLogin("admin");
    admin.setSenha("admin");
    admin.setNome("Administrador");
    this->usuarios.push_front(&admin);
    
    Especialista esp1 = Especialista();
    esp1.setCpf("000.000.000-98");
    esp1.setEmail("admin@clinica.com");
    esp1.setLogin("admin1");
    esp1.setSenha("admin1");
    esp1.setNome("Especialista 1");
    this->usuarios.push_front(&esp1);
    
    Especialista esp2 = Especialista();
    esp2.setCpf("000.000.000-97");
    esp2.setEmail("admin@clinica.com");
    esp2.setLogin("admin2");
    esp2.setSenha("admin3");
    esp2.setNome("Especialista 2");
    this->usuarios.push_front(&esp2);
    
    Especialista esp3 = Especialista();
    esp3.setCpf("000.000.000-96");
    esp3.setEmail("admin@clinica.com");
    esp3.setLogin("admin2");
    esp3.setSenha("admin3");
    esp3.setNome("Especialista 3");
    this->usuarios.push_front(&esp3);
    
    cout << "Usuários inicializados com sucesso" << endl;
    list<Usuario*>::iterator iterator;
    for (iterator = this->usuarios.begin(); iterator != this->usuarios.end(); ++iterator){
        Usuario &us = **iterator;
        std::cout << typeid(iterator).name() << " - " << us.getNome() << endl;
    }
    
}