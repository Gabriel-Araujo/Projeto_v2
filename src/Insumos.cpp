#include "Insumos.h"

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

Insumos::~Insumos()
{
    //dtor
}
