/***************************************************************************
 *  Trabalho Prático 1 - Programação Orientada a Objetos BCC 221 - 2020.1
 *  Paulo Felipe Possa Parreira - 12.2.1165
 *  paulof@ufop.edu.br
 *  02/2021
 ***************************************************************************/

#include "RegistroPagamentoConsulta.h"

RegistroPagamentoConsulta::RegistroPagamentoConsulta() {
}

RegistroPagamentoConsulta::RegistroPagamentoConsulta(const RegistroPagamentoConsulta& orig) {
}

RegistroPagamentoConsulta::~RegistroPagamentoConsulta() {
}

void RegistroPagamentoConsulta::setDataTimestamp(time_t dataTimestamp) {
    this->dataTimestamp = dataTimestamp;
    this->data = ctime(&dataTimestamp);
}

time_t RegistroPagamentoConsulta::getDataTimestamp() const {
    return dataTimestamp;
}

void RegistroPagamentoConsulta::setData(string data) {
    this->data = data;
}

string RegistroPagamentoConsulta::getData() const {
    return data;
}

void RegistroPagamentoConsulta::setNomeCliente(string nomeCliente) {
    this->nomeCliente = nomeCliente;
}

string RegistroPagamentoConsulta::getNomeCliente() const {
    return nomeCliente;
}

void RegistroPagamentoConsulta::setValor(double valor) {
    this->valor = valor;
}

double RegistroPagamentoConsulta::getValor() const {
    return valor;
}

