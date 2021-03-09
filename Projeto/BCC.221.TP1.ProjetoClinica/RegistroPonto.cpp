/***************************************************************************
 *  Trabalho Prático 1 - Programação Orientada a Objetos BCC 221 - 2020.1
 *  Paulo Felipe Possa Parreira - 12.2.1165
 *  paulof@ufop.edu.br
 *  02/2021
 ***************************************************************************/

#include "RegistroPonto.h"

RegistroPonto::RegistroPonto() {
}

RegistroPonto::RegistroPonto(const RegistroPonto& orig) {
}

RegistroPonto::~RegistroPonto() {
}

void RegistroPonto::setObservacao(string observacao) {
    this->observacao = observacao;
}

string RegistroPonto::getObservacao() const {
    return observacao;
}

void RegistroPonto::setTimestamp() {
    this->timestamp = to_time_t(this->dtRegistro + " 07:00:00", false, "%d/%m/%Y %H:%M:%S");
}

time_t RegistroPonto::getTimestamp() const {
    return timestamp;
}

void RegistroPonto::setDtRegistro(string dtRegistro) {
    this->dtRegistro = dtRegistro;
}

string RegistroPonto::getDtRegistro() const {
    return dtRegistro;
}

