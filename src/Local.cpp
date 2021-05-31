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
}


void Local::delete_all() {
    for (auto item: insumos) {
        delete item;
    }
}

Insumos* Local::get_insumo(const std::string& codigo) {
    for (auto item: insumos) {
        if (item->getCodigoUnico() == codigo) {
            //std::cout << "Vai passar..." << std::endl;
            return item;
        }
    }
    return new Insumos();
}


Vacina* Local::get_vacina(const std::string& codigo) {
    for (auto item: insumos) {
        if (item->getCodigoUnico() == codigo && item->getTipoInsumo() == "vacina") {
            return dynamic_cast<Vacina *>(item);
        }
    }
    return new Vacina();
}


Medicamento* Local::get_medicamento(const std::string& codigo) {
    for (auto item: insumos) {
        if (item->getCodigoUnico() == codigo && item->getTipoInsumo() == "medicamento") {
            return dynamic_cast<Medicamento *>(item);
        }
    }
    return new Medicamento();
}



EPI *Local::get_epi(const std::string &codigo) {
    for (auto item: insumos) {
        if (item->getCodigoUnico() == codigo && item->getTipoInsumo() == "epi") {
            return dynamic_cast<EPI *>(item);
        }
    }
    return new EPI();
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

void Local::exibir_insumos_quantidade()
{
    menus.exibir_quantidades(insumos);
}

void Local::exibir_insumos_descricao()
{
    menus.exibir_formatado(insumos);
}

void Local::exibir_insumos_total()
{
    menus.exibir_total(insumos);
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
    menus.exibir_total(generico);

    for (auto item: generico) {
        delete item;
    }
}



bool Local::insumo_existe(const std::string codigo) {
    return std::any_of(insumos.begin(), insumos.end(), [&codigo](Insumos *item){return item->getCodigoUnico() == codigo;});
}


int Local::get_insumo_index(const std::string codigo) {
    for (unsigned int index = 0; index < insumos.size(); index++) {
        if (insumos.at(index)->getCodigoUnico() == codigo) {return index;}
    }
    return -1;
}


std::string Local::get_insumo_tipo(const std::string codigo) {
    Insumos *insumo = get_insumo(codigo);
    return insumo->get_tipo();
}


int Local::get_vacina_quantidade() {
    int quantidade = 0;
    for (const auto &item: insumos) {
        if(item->getTipoInsumo() == "vacina"){
        quantidade += item->get_quantidade();
        }
    }
    return quantidade;
}


int Local::get_medicamento_quantidade() {
    int quantidade = 0;
    for (auto item: insumos) {
        if (item->getTipoInsumo() == "medicamento"){
            quantidade += item->get_quantidade();
        }
    }
    return quantidade;
}


int Local::get_epi_quantidade() {
    int quantidade = 0;
    for (auto item: insumos) {
        if (item->getTipoInsumo() == "epi"){
            quantidade += item->get_quantidade();
        }
    }
    return quantidade;
}


int Local::get_insumos_quantidade() {
    int quantidade = 0;
    for (auto item: insumos) {
        quantidade += item->get_quantidade();
    }
    return quantidade;
}
