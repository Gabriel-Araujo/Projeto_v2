#ifndef LOCAL_H
#define LOCAL_H
#include "Insumos.h"

#include <vector>
#include <array>

class Local
{
private:
    std::string nome_extenso;
    std::string sigla;
    std::vector<Insumos> insumos;

protected:
    std::array<std::string, 29> locais_possiveis =
            {
            "AC", "AL", "AP", "AM", "BA", "BA", "CE", "ES", "GO", "MA", "MT", "MS",
            "MG", "PA", "PB", "PR", "PE", "PI", "RJ", "RN", "RS", "RO", "RR", "SC",
            "SP", "SE", "TO", "DF", "MINISTERIO"
            };

public:
    Local();
    Local(std::string nome, std::string sigla);
    virtual ~Local();

    bool local_existe();
};

#endif // LOCAL_H
