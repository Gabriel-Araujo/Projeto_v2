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
    for (auto item: insumos) {
        delete item;
    }
}




std::string Local::get_sigla() {
    return sigla;
}


std::string Local::get_nome_extenso() {
    return nome_extenso;
}


void Local::adicionar_insumo(Insumos *insumo) {
    insumos.push_back(insumo);
}


/* TODO
 * Implementar uma função pra verificar se um insumo existe
 *
 * Implementar uma função pra retornar a posição do insumo no array
 *
 */