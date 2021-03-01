/***************************************************************************
 *  Trabalho Prático 1 - Programação Orientada a Objetos BCC 221 - 2020.1
 *  Paulo Felipe Possa Parreira - 12.2.1165
 *  paulof@ufop.edu.br
 *  02/2021
 ***************************************************************************/

#include "Especialista.h"

Especialista::Especialista() {
}

Especialista::Especialista(const Especialista& orig) {
}

Especialista::~Especialista() {
}

void Especialista::imprimirMenu() {
    cout << "=============================================" << endl;
    cout << "Bem vindo(a) ao sistema de gerenciamento da clinica odontologica" << endl;
    cout << "Usuário Logado: " << this->nome << " Tipo: Especialista" << endl;
    cout << "=============================================" << endl;
    cout << "Digite:" << endl << "1 - Agenda" << endl << "2 - Folha de Ponto" << endl;
    cout << "3 - Sair" << endl;
}

void Especialista::setAgenda(vector<std::reference_wrapper<RegistroAgenda> > agenda) {
    this->agenda = agenda;
}

vector<std::reference_wrapper<RegistroAgenda> > Especialista::getAgenda() const {
    return agenda;
}

void Especialista::setFolhaPonto(vector<std::reference_wrapper<RegistroPonto> > folhaPonto) {
    this->folhaPonto = folhaPonto;
}

vector<std::reference_wrapper<RegistroPonto> > Especialista::getFolhaPonto() const {
    return folhaPonto;
}