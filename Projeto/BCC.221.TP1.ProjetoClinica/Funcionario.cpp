/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Funcionario.cpp
 * Author: paulo
 * 
 * Created on March 9, 2021, 7:55 AM
 */

#include "Funcionario.h"

Funcionario::Funcionario() {
}

Funcionario::Funcionario(const Funcionario& orig) {
}

Funcionario::~Funcionario() {
}

void Funcionario::setFolhaPonto(vector<std::shared_ptr<RegistroPonto> > folhaPonto) {
    this->folhaPonto = folhaPonto;
}

vector<std::shared_ptr<RegistroPonto> > Funcionario::getFolhaPonto() const {
    return folhaPonto;
}

void Funcionario::mostrarFolhaPonto() {
    this->sortFolhaPonto();
    system("clear");
    cout << "Mostrando a folha de ponto do funcionário: " << this->getNome() << endl;
    cout << "=============================================" << endl;
    if (this->getFolhaPonto().size() == 0) {
        cout << "Não existem registros na folha de ponto." << endl;;
    } else {
        for (int i = 0; i < this->getFolhaPonto().size(); i++) {
            cout << this->folhaPonto[i]->getDtRegistro()
                    << " | " << this->folhaPonto[i]->getObservacao() << endl;
        }
    }
    cout << "=============================================" << endl;
    cout << "Opções: " << endl;
    cout << "1 - Adicionar Registro | 2 - Voltar" << endl;
    int opcao;
    cin >> opcao;
    switch (opcao) {
        case 1:
            this->adicionarRegistroPonto();
            break;
        case 2:
            return;
            break;

    }
}

void Funcionario::sortFolhaPonto() {
    sort(this->folhaPonto.begin(), this->folhaPonto.end(), [](const std::shared_ptr<RegistroPonto>& lhs, const std::shared_ptr<RegistroPonto>& rhs) {
      return lhs->getTimestamp() < rhs->getTimestamp();
   });
}


void Funcionario::adicionarRegistroPonto() {
    string dtRegistro;
    string observacao;
    shared_ptr<RegistroPonto> registro = make_shared<RegistroPonto>();
    system("clear");
    cout << "Adicionar novo registro na folha de ponto do funcionário: " << this->getNome() << endl;
    cout << "=============================================" << endl;
    cout << "Insira a data do registro: ";
    cin >> dtRegistro;
    cout << endl << "Insira uma observação do registro: ";
    cin >> observacao;
    registro->setDtRegistro(dtRegistro);
    registro->setObservacao(observacao);
    registro->setTimestamp();
    this->folhaPonto.push_back(registro);
    this->mostrarFolhaPonto();
}