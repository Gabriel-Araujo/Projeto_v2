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
