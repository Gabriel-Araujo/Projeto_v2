#ifndef LOCAL_H
#define LOCAL_H
#include "Insumos.h"
#include "Menu.h"
#include "Vacina.h"
#include "Medicamento.h"
#include "EPI.h"

#include <vector>
#include <array>
#include <exception>
#include <algorithm>
#include <iostream>
#include <utility>
#include <type_traits>

class Local: private std::exception
{
private:
    std::string nome_extenso;
    std::string sigla;
    std::vector<Insumos*> insumos;
    std::array<std::string, 3> tipos_possiveis = {"vacina", "medicamento", "epi"};
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

    Insumos* get_insumo(const std::string& codigo);
    Vacina* get_vacina(const std::string& codigo);
    Medicamento* get_medicamento(const std::string& codigo);
    EPI* get_epi(const std::string& codigo);

    std::vector<Insumos *> getInsumos();
    int get_insumo_index(const std::string codigo);
    std::string get_insumo_tipo(const std::string codigo);
    std::string get_sigla();
    std::string get_nome_extenso();

    int get_vacina_quantidade();
    int get_medicamento_quantidade();
    int get_epi_quantidade();
    int get_insumos_quantidade();


    void adicionar_insumo(Insumos *insumo);

    void exibir_insumos_por_tipo(const std::string& tipo);
    void exibir_insumo_detalhado(std::string codigo);

    bool insumo_existe(const std::string codigo);
    bool tipo_existe(std::string tipo);
    void cadastrar_insumo(std::string tipoInsumo);


};

#endif // LOCAL_H
