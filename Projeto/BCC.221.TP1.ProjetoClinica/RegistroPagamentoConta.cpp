/***************************************************************************
 *  Trabalho Prático 1 - Programação Orientada a Objetos BCC 221 - 2020.1
 *  Paulo Felipe Possa Parreira - 12.2.1165
 *  paulof@ufop.edu.br
 *  02/2021
 ***************************************************************************/

#include "RegistroPagamentoConta.h"

RegistroPagamentoConta::RegistroPagamentoConta() {
}

RegistroPagamentoConta::RegistroPagamentoConta(const RegistroPagamentoConta& orig) {
}

RegistroPagamentoConta::~RegistroPagamentoConta() {
}

void RegistroPagamentoConta::setDtPagamento(string dtPagamento) {
    this->dtPagamento = dtPagamento;
}

string RegistroPagamentoConta::getDtPagamento() const {
    return dtPagamento;
}

void RegistroPagamentoConta::setDtVencimento(string dtVencimento) {
    this->dtVencimento = dtVencimento;
}

string RegistroPagamentoConta::getDtVencimento() const {
    return dtVencimento;
}

void RegistroPagamentoConta::setDescricao(string descricao) {
    this->descricao = descricao;
}

string RegistroPagamentoConta::getDescricao() const {
    return descricao;
}

