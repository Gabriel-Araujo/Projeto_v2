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
        void cadastrar_vacina();
        void cadastrar_medicamentos();
        void cadastrar_epis();
        Menu menus;

    protected:
        bool local_existe(std::string local);
        int get_local(std::string local);

    public:
        Controlador();
        virtual ~Controlador();
        void CadastroInsumosMs(std::string tipoInsumo);
        void exibir_insumos(std::string local);
        void exibir_insumos_por_tipo(std::string local, std::string tipo);

        void CadastroInsumosEst(std::string tipoInsumo, std::string cdg, std::string estado, int quant);
        //void cadastrar_vacina();
        void DistribuirInsumosEstados(std::string tipoInsumo);

        //void Cadastro_Est(t_est *est, int escolha, std::string estado);
        /*
        */
        void ConsultaInsumosMS(std::string tipoInsumo, int n);
        void ConsultaInsumosEst(std::string estado, std::string tipoInsumo, int n);

        // Funções de consulta:
        /*
        void Consultar_estoque_local(const string local, int choice); // testar
        void Consult(t_insumos *ins, int escolha);
        void Consult_est(t_est *est, int escolha);
        void consult_est_especifico(t_est *est, std::string busca);
        */


};

#endif // CONTROLER_H
