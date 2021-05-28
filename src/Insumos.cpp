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

<<<<<<< HEAD
std::string Insumos::getnome_fab()
{
    return nome_fab;
}
=======
>>>>>>> d2a1bd5d650c003d404bf9697d01d82bb13fdb65

void Insumos::DescontaQuantidade(int quantidade)
{
    if(quantidade < this->quantidade){
        this->quantidade -= quantidade;
    }
}


<<<<<<< HEAD
=======
void Insumos::acrescentar_quantidade(int quantidade) {
    this->quantidade += quantidade;
}

>>>>>>> d2a1bd5d650c003d404bf9697d01d82bb13fdb65
Insumos::~Insumos()
{
    //dtor
}

std::string Insumos::get_tipo() {
    return tipoInsumo;
}


void Insumos::set_local(std::string estado) {
    transform(estado.begin(), estado.end(), estado.begin(), [](char c) { return toupper(c);});
    local = estado;
}


std::string Insumos::get_vencimento() {
    return data_vencimento;
}


std::string Insumos::get_fabricante() {
    return nome_fab;
}


std::string Insumos::get_local() {
    return local;
}