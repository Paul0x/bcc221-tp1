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
   const char *tmpChar = observacao.data();
   int length = observacao.size();
   length = ( length < 100? length : 99 );
   strncpy( this->observacao, tmpChar, length );
   this->observacao[ length ] = '\0';
}

string RegistroAgenda::getObservacao() const {
    return observacao;
}

void RegistroAgenda::setData(string data) {
   const char *tmpChar = data.data();
   int length = data.size();
   length = ( length < 11 ? length : 10 );
   strncpy( this->data, tmpChar, length );
   this->data[ length ] = '\0';
}

string RegistroAgenda::getHora() const {
    return hora;
}

void RegistroAgenda::setHora(string hora) {
   const char *tmpChar = hora.data();
   int length = hora.size();
   length = ( length < 6 ? length : 5 );
   strncpy( this->hora, tmpChar, length );
   this->hora[ length ] = '\0';
}

string RegistroAgenda::getData() const {
    return data;
}

time_t RegistroAgenda::getTimestamp() const {
    return timestamp;
}

void RegistroAgenda::setTimestamp() {
    this->timestamp = to_time_t(string(this->data) + " " + string(this->hora) + ":00", false, "%d/%m/%Y %H:%M:%S");
}

