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
    const char *tmpChar = dtPagamento.data();
    int length = dtPagamento.size();
    length = (length < 11 ? length : 10);
    strncpy(this->dtPagamento, tmpChar, length);
    this->dtPagamento[ length ] = '\0';
}

string RegistroPagamentoConta::getDtPagamento() const {
    return dtPagamento;
}

void RegistroPagamentoConta::setDtVencimento(string dtVencimento) {
    const char *tmpChar = dtVencimento.data();
    int length = dtVencimento.size();
    length = (length < 11 ? length : 10);
    strncpy(this->dtVencimento, tmpChar, length);
    this->dtVencimento[ length ] = '\0';
}

string RegistroPagamentoConta::getDtVencimento() const {
    return dtVencimento;
}

void RegistroPagamentoConta::setDescricao(string descricao) {
    const char *tmpChar = descricao.data();
    int length = descricao.size();
    length = (length < 100 ? length : 99);
    strncpy(this->descricao, tmpChar, length);
    this->descricao[ length ] = '\0';
}

string RegistroPagamentoConta::getDescricao() const {
    return descricao;
}

