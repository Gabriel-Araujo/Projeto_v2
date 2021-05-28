#include "../include/EPI.h"

EPI::EPI()
{
    tipoInsumo = "epi";

    tipo_epi = "NULL";
    descricao = "NULL";
}

EPI::EPI(std::string nome, int quantidade, int valor_unitario, std::string vencimento, std::string fabricante,
               std::string local, std::string codigo_unico, std::string tipo_epi, std::string descricao): Insumos() {

    set_nome(nome);
    set_quantidade(quantidade);
    set_valor_unitario(valor_unitario);
    set_vencimento(vencimento);
    set_fabricante(fabricante);
    set_local(local);
    set_codigo(codigo_unico);
    set_tipo_epi(tipo_epi);
    set_descricao(descricao);

    tipoInsumo = "epi";
}

void EPI::set_nome(std::string nome)
{
    this->nome = nome;
}

void EPI::set_quantidade(int quantidade)
{
    if (quantidade < 0) {
        this->quantidade = 0;
    }
    else {
        this->quantidade = quantidade;
    }
}

void EPI::set_valor_unitario(int valor_unitario)
{
    if (valor_unitario < 0) {
        this->valor_unitario = 0;
    }
    else {
        this->valor_unitario = valor_unitario;
    }
}

void EPI::set_vencimento(std::string data_vencimento)
{
    this->data_vencimento = data_vencimento;
}

void EPI::set_fabricante(std::string nome_fab)
{
    this->nome_fab = nome_fab;
}


void EPI::set_codigo(std::string codigo_unico)
{
    this->codigo_unico = codigo_unico;
}

void EPI::set_tipo_epi(std::string tipo_epi)
{
    this->tipo_epi = tipo_epi;
}

void EPI::set_descricao(std::string descricao)
{
    this->descricao = descricao;
}

EPI::~EPI()
{
    //dtor
}

int EPI::get_quantidade() {
    return Insumos::get_quantidade();
}

std::string EPI::get_tipo_epi() {
    return tipo_epi;
}


std::string EPI::get_descricao() {
    return descricao;
}