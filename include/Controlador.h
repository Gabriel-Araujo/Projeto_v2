#ifndef CONTROLER_H
#define CONTROLER_H

#include "Insumos.h"
#include "Vacina.h"
#include "Medicamento.h"
#include "EPI.h"
#include "Local.h"
#include "Menu.h"
#include "Persistencia.h"

#include <vector>
#include <array>
#include <algorithm>
#include <iostream>
#include <iterator>
#include <exception>

class Controlador: public std::exception
{
    private:
        std::array<Local, 29> locais;
        std::array<std::string, 3> tipos_possiveis = {"vacina", "medicamento", "epi"};

        Menu menus;
        Persistencia persistencia;

    protected:
        bool local_existe(std::string &local);
        int get_local_index(const std::string local);

    public:
        Controlador();
        virtual ~Controlador();

        //Funcoes de cadastro
        void CadastroInsumo(std::string tipoInsumo);

        //Funções de distribuição
        int distribuir_vacina_para(const std::string estado, const std::string codigo, const int quantidade);
        int distribuir_medicamento_para(const std::string estado, const std::string codigo, const int quantidade);
        int distribuir_epi_para(const std::string estado, std::string codigo, int quantidade);

        //Funções de menus
        void exibir_menus(int escolha);
        void exibir_menus_cadastro();
        void exibir_menus_distribuir();
        void exibir_menus_consultar_ms();
        void exibir_menus_consulta_estados();

        bool tipo_existe(std::string tipo);

        int iniciar_programa();
};

#endif // CONTROLER_H
