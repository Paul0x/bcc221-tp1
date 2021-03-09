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

void Funcionario::setFolhaPonto(vector<std::reference_wrapper<RegistroPonto> > folhaPonto) {
    this->folhaPonto = folhaPonto;
}

vector<std::reference_wrapper<RegistroPonto> > Funcionario::getFolhaPonto() const {
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
            cout << this->folhaPonto[i].get().getDtRegistro()
                    << " | " << this->folhaPonto[i].get().getObservacao() << endl;
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
    sort(this->folhaPonto.begin(), this->folhaPonto.end(), [](const std::reference_wrapper<RegistroPonto>& lhs, const std::reference_wrapper<RegistroPonto>& rhs) {
      return lhs.get().getTimestamp() < rhs.get().getTimestamp();
   });
}


void Funcionario::adicionarRegistroPonto() {
    string dtRegistro;
    string observacao;
    RegistroPonto registro = RegistroPonto();
    system("clear");
    cout << "Adicionar novo registro na folha de ponto do funcionário: " << this->getNome() << endl;
    cout << "=============================================" << endl;
    cout << "Insira a data do registro: ";
    cin >> dtRegistro;
    cout << endl << "Insira uma observação do registro: ";
    cin >> observacao;
    registro.setDtRegistro(dtRegistro);
    registro.setObservacao(observacao);
    registro.setTimestamp();
    this->folhaPonto.push_back(registro);
    this->mostrarFolhaPonto();
}