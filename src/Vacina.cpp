#include "../include/Vacina.h"
#include <iostream>
#include <iomanip>

using namespace std;

Vacina::Vacina(): Insumos()
{
    tipoInsumo = "vacina";

    tipo_vac = "Indefindo";
    quantidade_doses = 0;
    intervalo = 0;
}


Vacina::Vacina(std::string nome, int quantidade, int valor_unitario, std::string vencimento, std::string fabricante,
               std::string local, std::string codigo_unico, std::string tipo_vac, int quant_doses, int intervalo): Insumos() {
    set_nome(nome);
    set_quantidade(quantidade);
    set_valor_unitario(valor_unitario);
    set_vencimento(vencimento);
    set_fabricante(fabricante);
    set_local(local);
    set_codigo(codigo_unico);
    set_tipo_vac(tipo_vac);
    set_quant_doses(quant_doses);
    set_intervalo(intervalo);
    tipoInsumo = "vacina";
}

Vacina::~Vacina()
{
    //dtor
}


void Vacina::set_nome(std::string nome) {
    this->nome = nome;
}


void Vacina::set_quantidade(int q) {
    if (q < 0) {
        quantidade = 0;
    }
    else {
        quantidade = q;
    }
}


void Vacina::set_valor_unitario(int q) {
    if (q <= 0) {
        valor_unitario = 1;
    }
    else {
        valor_unitario = q;
    }
}


void Vacina::set_vencimento(std::string data) {
    data_vencimento = data;
}


void Vacina::set_fabricante(std::string fab) {
    nome_fab = fab;
}


void Vacina::set_codigo(std::string unico) {
    codigo_unico = unico;
}

void Vacina::set_tipo_vac(std::string t) {
    tipo_vac = t;
}

void Vacina::set_quant_doses(int qd) {
    if (qd < 0) {
        quantidade_doses = 0;
    }
    else {
        quantidade_doses = qd;
    }
}


void Vacina::set_intervalo(int it) {
    if (it < 0) {
        intervalo = 0;
    }
    else {
        intervalo = it;
    }
}

std::string Vacina::get_tipo_vac()
{
    return tipo_vac;
}

int Vacina::get_quant_doses()
{
    return quantidade_doses;
}

int Vacina::get_intervalo()
{
    return intervalo;
}
/*
int Vacina::get_quantidade() {
    return Insumos::get_quantidade();
}
*/
