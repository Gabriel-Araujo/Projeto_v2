#include "../include/Local.h"
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

Insumos* Local::getInsumos(std::string codigo) {
    for (auto item: insumos) {
        if (item->getCodigoUnico() == codigo) {
            return item;
        }
    }
    return new Insumos();
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
