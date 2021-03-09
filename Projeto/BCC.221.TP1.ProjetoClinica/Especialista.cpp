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

string Especialista::imprimirMenu() {
    cout << "=============================================" << endl;
    cout << "Bem vindo(a) ao sistema de gerenciamento da clinica odontologica" << endl;
    cout << "Usuário Logado: " << this->nome << " Tipo: Especialista" << endl;
    cout << "=============================================" << endl;
    cout << "Digite:" << endl << "1 - Agenda" << endl << "2 - Folha de Ponto" << endl;
    cout << "3 - Sair" << endl;
    int opcao;
    cin >> opcao;
    switch (opcao) {
        case 1:
            return "ag";
            break;
        case 2:
            return "fp";
            break;
        case 3:
            exit(0);
            break;
    }
}

void Especialista::setAgenda(vector<std::reference_wrapper<RegistroAgenda> > agenda) {
    this->agenda = agenda;
}

vector<std::reference_wrapper<RegistroAgenda> > Especialista::getAgenda() const {
    return agenda;
}

void Especialista::mostrarAgenda() {
    this->sortAgenda();
    system("clear");
    cout << "Mostrando agenda do especialista: " << this->getNome() << endl;
    cout << "=============================================" << endl;
    if (this->getAgenda().size() == 0) {
        cout << "Não existem registros na agenda." << endl;;
    } else {
        for (int i = 0; i < this->getAgenda().size(); i++) {
            cout << i << " - " << this->agenda[i].get().getData() << " às " << this->agenda[i].get().getHora() << " | " << this->agenda[i].get().getObservacao() << endl;
        }
    }
    cout << "=============================================" << endl;
    cout << "Opções: " << endl;
    cout << "1 - Editar Registro | 2 - Adicionar Registro | 3 - Remover Registro | 4 - Voltar" << endl;
    int opcao;
    int index;
    cin >> opcao;
    switch (opcao) {
        case 1:
            cout << "Selecione o registro que você deseja editar (utilize o índice da tabela): ";
            cin >> index;
            this->editarRegistroAgenda(index);
            break;
        case 2:
            this->adicionarRegistroAgenda();
            break;
        case 3:
            cout << "Selecione o registro que você deseja remover (utilize o índice da tabela): ";
            cin >> index;
            this->removerRegistroAgenda(index);
            break;
        case 4:
            return;
            break;

    }
}

void Especialista::adicionarRegistroAgenda() {
    string data;
    string hora;
    string observacao;
    RegistroAgenda registro = RegistroAgenda();
    system("clear");
    cout << "Adicionar novo registro da agenda do especialista: " << this->getNome() << endl;
    cout << "=============================================" << endl;
    cout << "Insira a data do registro: ";
    cin >> data;
    cout << endl << "Insira a hora do registro: ";
    cin >> hora;
    cout << endl << "Insira uma observação do registro: ";
    cin >> observacao;
    registro.setData(data);
    registro.setHora(hora);
    registro.setObservacao(observacao);
    registro.setTimestamp();
    this->agenda.push_back(registro);
    this->mostrarAgenda();
}

void Especialista::editarRegistroAgenda(int index) {
    string data;
    string hora;
    string observacao;
    RegistroAgenda registro = RegistroAgenda();
    system("clear");
    cout << "Editar o registro da agenda do especialista: " << this->getNome() << endl;
    cout << "Informações atuais: " << endl;
    cout << "Data e Hora: " << this->agenda[index].get().getData() << " às " << this->agenda[index].get().getHora() << endl;
    cout << "Observação: " << this->agenda[index].get().getObservacao() << endl;
    cout << "=============================================" << endl;
    cout << "Insira a nova data do registro: ";
    cin >> data;
    cout << endl << "Insira a nova hora do registro: ";
    cin >> hora;
    cout << endl << "Insira uma nova observação do registro: ";
    cin >> observacao;
    registro.setData(data);
    registro.setHora(hora);
    registro.setObservacao(observacao);
    registro.setTimestamp();
    this->agenda[index] = registro;
    //this->agenda.insert(this->agenda.begin() + index, registro);
    this->mostrarAgenda();
}

void Especialista::removerRegistroAgenda(int index) {
    system("clear");
    this->agenda.erase(this->agenda.begin() + index);
    cout << "Elemento removido com sucesso, aperte qualquer tecla para continuar.";
    cin;
    this->mostrarAgenda();

}

void Especialista::sortAgenda() {
    sort(this->agenda.begin(), this->agenda.end(), [](const std::reference_wrapper<RegistroAgenda>& lhs, const std::reference_wrapper<RegistroAgenda>& rhs) {
      return lhs.get().getTimestamp() < rhs.get().getTimestamp();
   });
}