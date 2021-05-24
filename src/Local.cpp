#include "../include/Local.h"
#include <algorithm>
#include <iostream>
#include <utility>

Local::Local()
{
    nome_extenso = "NULL";
    sigla = "NULL";
}

Local::Local(std::string nome, std::string sigla) {
    nome_extenso = std::move(nome);
    this->sigla = std::move(sigla);
}

Local::~Local(){
    for (auto item: insumos) {
        delete item;
    }
}

Insumos* Local::getInsumosVerify(const std::string& codigo) {
    for (auto item: insumos) {
        if (item->getCodigoUnico() == codigo) {
            std::cout << "Vai passar..." << std::endl;
            return item;
        }
    }
    return new Insumos();
}

Insumos* Local::getInsumos(const std::string& tipoInsumo)
{
    for (auto item: insumos) {
        if (item->getTipoInsumo() == tipoInsumo) {
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


void Local::exibir_insumos() {
    menus.exibir_formatado(insumos);
}


void Local::exibir_insumos_por_tipo(const std::string& tipo) {
    std::vector<Insumos*> generico;

    for (auto item: insumos) {
        if (item->getTipoInsumo() == tipo) {
            auto a = new Insumos(*item);
            generico.push_back(a);
        }
    }
    menus.exibir_formatado(generico);

    for (auto item: generico) {
        delete item;
    }
}


/* TODO
 * Implementar uma função pra verificar se um insumo existe
 *
 * Implementar uma função pra retornar a posição do insumo no array
 *
 */
