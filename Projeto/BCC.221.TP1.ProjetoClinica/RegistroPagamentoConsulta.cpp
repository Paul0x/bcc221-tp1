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
    string tmp = ctime(&dataTimestamp);
    const char *tmpChar = tmp.data();
    int length = tmp.size();
    length = (length < 11 ? length : 10);
    strncpy(this->data, tmpChar, length);
    this->data[ length ] = '\0';
    
}

time_t RegistroPagamentoConsulta::getDataTimestamp() const {
    return dataTimestamp;
}

void RegistroPagamentoConsulta::setData(string data) {

    const char *tmpChar = data.data();
    int length = data.size();
    length = (length < 11 ? length : 10);
    strncpy(this->data, tmpChar, length);
    this->data[ length ] = '\0';
}

string RegistroPagamentoConsulta::getData() const {
    return data;
}

void RegistroPagamentoConsulta::setNomeCliente(string nomeCliente) {
    const char *tmpChar = nomeCliente.data();
    int length = nomeCliente.size();
    length = (length < 60 ? length : 59);
    strncpy(this->nomeCliente, tmpChar, length);
    this->nomeCliente[ length ] = '\0';
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

