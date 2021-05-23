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

std::string Insumos::getTipoInsumo()
{
    return tipoInsumo;
}

int Insumos::getquantidade()
{
    return quantidade;
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
