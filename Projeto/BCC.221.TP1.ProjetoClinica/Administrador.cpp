/***************************************************************************
 *  Trabalho Prático 1 - Programação Orientada a Objetos BCC 221 - 2020.1
 *  Paulo Felipe Possa Parreira - 12.2.1165
 *  paulof@ufop.edu.br
 *  02/2021
 ***************************************************************************/

#include "Administrador.h"

Administrador::Administrador() {
}

Administrador::Administrador(const Administrador& orig) {
}

Administrador::~Administrador() {
}

string Administrador::imprimirMenu() {
    cout << "=============================================" << endl;
    cout << "Bem vindo(a) ao sistema de gerenciamento da clinica odontologica" << endl;
    cout << "Usuário Logado: " << this->nome << " Tipo: Administrador" << endl;
    cout << "=============================================" << endl;
    cout << "Digite:" << endl << "1 - Agenda" << endl << "2 - Receber Consulta" << endl;
    cout << "3 - Pagamento de Contas" << endl << "4 - Folha de Ponto" << endl;
    cout << "5 - Gerenciar Usuários" << endl << "6 - Sair" << endl;
    int opcao;
    cin >> opcao;
    switch(opcao) {
        case 1:
            return "ag";
            break;
        case 2:
            return "rc";
            break;
        case 3:
            return "pc";
            break;
        case 4:
            return "fp";
            break;
        case 5:
            return "gu";
        case 6:
            exit(0);
            break;
    }
}