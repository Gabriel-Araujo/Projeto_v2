#include "../include/Insumos.h"

Insumos::Insumos()
{
    nome = "NULL";
    quantidade = 0;
    valor_unitario = 0;
    data_vencimento = "00/00/0000";
    nome_fab = "NULL";
    tipoInsumo = "INDEFINIDO";
    local = "INDEFINIDO";
    codigo_unico = "NULL";
}

void Insumos::setQuantidade(int quantidade)
{
    this->quantidade = quantidade;
}

std::string Insumos::getCodigoUnico()
{
    return this->codigo_unico;
}


std::string Insumos::getNome() {
    return this->nome;
}


int Insumos::get_valor() {
    return this->valor_unitario;
}


int Insumos::get_quantidade() {
    return this->quantidade;
}

std::string Insumos::getTipoInsumo()
{
    return this->tipoInsumo;
}


void Insumos::DescontaQuantidade(int quantidade)
{
    if(quantidade < this->quantidade){
        this->quantidade -= quantidade;
    }
}


void Insumos::acrescentar_quantidade(int quantidade) {
    this->quantidade += quantidade;
}

Insumos::~Insumos()
{
    //dtor
}

std::string Insumos::get_tipo() {
    return tipoInsumo;
}


void Insumos::set_local(std::string estado) {
    local = estado;
}