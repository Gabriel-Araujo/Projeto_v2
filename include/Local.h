#ifndef LOCAL_H
#define LOCAL_H
#include "Insumos.h"
#include "Menu.h"

#include <vector>
#include <array>

class Local
{
private:
    std::string nome_extenso;
    std::string sigla;
    std::vector<Insumos*> insumos;
    Menu menus;

protected:
    std::array<std::string, 29> locais_possiveis =
            {
            "AC", "AL", "AP", "AM", "BA", "CE", "ES", "GO", "MA", "MT", "MS",
            "MG", "PA", "PB", "PR", "PE", "PI", "RJ", "RN", "RS", "RO", "RR", "SC",
            "SP", "SE", "TO", "DF", "MINISTÉRIO DA SAÚDE", "MIN"
            };

public:
    Local();
    Local(std::string nome, std::string sigla);
    virtual ~Local();

    Insumos* getInsumosVerify(std::string cdg);
    Insumos* getInsumos(std::string tipoInsumo);

    std::string get_sigla();
    std::string get_nome_extenso();
    void adicionar_insumo(Insumos *insumo);
    void exibir_insumos();
    void exibir_insumos_por_tipo(std::string tipo);
};

#endif // LOCAL_H
