/***************************************************************************
 *  Trabalho Prático 1 - Programação Orientada a Objetos BCC 221 - 2020.1
 *  Paulo Felipe Possa Parreira - 12.2.1165
 *  paulof@ufop.edu.br
 *  02/2021
 ***************************************************************************/


#include "RegistroAgenda.h"
#include "utils.h"

RegistroAgenda::RegistroAgenda() {
}

RegistroAgenda::RegistroAgenda(const RegistroAgenda& orig) {
}

RegistroAgenda::~RegistroAgenda() {
}

void RegistroAgenda::setObservacao(string observacao) {
    this->observacao = observacao;
}

string RegistroAgenda::getObservacao() const {
    return observacao;
}

void RegistroAgenda::setData(string data) {
    this->data = data;
}

string RegistroAgenda::getHora() const {
    return hora;
}

void RegistroAgenda::setHora(string hora) {
    this->hora = hora;
}

string RegistroAgenda::getData() const {
    return data;
}

time_t RegistroAgenda::getTimestamp() const {
    return timestamp;
}

void RegistroAgenda::setTimestamp() {
    this->timestamp = to_time_t(this->data + " " + this->hora + ":00", false, "%d/%m/%Y %H:%M:%S");
}

