#include "Vacina.h"

Vacina::Vacina(): Insumos()
{
    tipoInsumo = "vacina";

    tipo_vac = "Indefindo";
    quantidade_doses = 0;
    intervalo = 0;
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
