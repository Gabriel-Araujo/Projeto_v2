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
    return codigo_unico;
}


std::string Insumos::getNome() {
    return nome;
}


int Insumos::get_valor() {
    return valor_unitario;
}


int Insumos::get_quantidade() {
    return quantidade;
}

std::string Insumos::getTipoInsumo()
{
    return tipoInsumo;
}

void Insumos::DescontaQuantidade(int quantidade)
{
    if(quantidade < this->quantidade){
        this->quantidade -= quantidade;
    }
}

Insumos::~Insumos()
{
    //dtor
}
