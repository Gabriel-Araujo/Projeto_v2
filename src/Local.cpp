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


bool Local::local_existe(std::string local) {
    transform(local.begin(), local.end(),local.begin(), [](char c){ return toupper(c);});
    return any_of(locais_possiveis.begin(), locais_possiveis.end(),[local](const std::string& elem) {return elem == local;});
}