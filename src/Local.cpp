#include "Local.h"
#include <algorithm>

Local::Local()
{
    nome_extenso = "NULL";
    sigla = "NULL";
}

Local::Local(std::string nome, std::string sigla) {
    nome_extenso = nome;
    this->sigla = sigla;
}

Local::~Local()
{
    //dtor
}




std::string Local::get_sigla() {
    return sigla;
}


std::string Local::get_nome_extenso() {
    return nome_extenso;
}