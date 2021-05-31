#ifndef CONTROLER_H
#define CONTROLER_H

#include "Insumos.h"
#include "Vacina.h"
#include "Medicamento.h"
#include "EPI.h"
#include "Local.h"
#include "Menu.h"

#include <vector>
#include <array>
#include <algorithm>
#include <iostream>
#include <iterator>


class Controlador
{
    private:
        std::array<Local, 29> locais;
        std::array<std::string, 3> tipos_possiveis = {"vacina", "medicamento", "epi"};
        void cadastrar_vacina();
        void cadastrar_medicamentos();
        void cadastrar_epis();
        Menu menus;

    protected:
        bool local_existe(std::string &local);
        int get_local_index(const std::string local);

    public:
        Controlador();
        virtual ~Controlador();
        //Funcoes de cadastro
        void CadastroInsumo(std::string tipoInsumo);


        int distribuir_vacina_para(const std::string estado, const std::string codigo, const int quantidade);
        int distribuir_medicamento_para(const std::string estado, const std::string codigo, const int quantidade);
        int distribuir_epi_para(const std::string estado, std::string codigo, int quantidade);

        void insumo_existe_no_local(const std::string local, const std::string codigo);

        void exibir_insumos_quantidade(std::string local);
        void exibir_insumos_descricao(std::string local);
        void exibir_insumos_total(std::string local);
        void exibir_insumos_por_tipo(std::string local, std::string tipo);


        void exibir_insumo_detalhado(Insumos *insumo);

        void exibir_menus(int escolha);
        void exibir_menus_cadastro();
        void exibir_menus_distribuir();
        void exibir_menus_consultar_ms();
        void exibir_menus_consulta_estados();

        bool tipo_existe(std::string tipo);

        int loop_hole();

        // Funções de consulta:
        /*
        void Consultar_estoque_local(const string local, int choice); // testar
        void Consult(t_insumos *ins, int escolha);
        void Consult_est(t_est *est, int escolha);
        void consult_est_especifico(t_est *est, std::string busca);
        */


    void exibir_insumo_detalhado(Insumos &insumo);
};

#endif // CONTROLER_H
