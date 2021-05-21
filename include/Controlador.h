#ifndef CONTROLER_H
#define CONTROLER_H

#include "Insumos.h"
#include "Vacina.h"
#include "Medicamento.h"
#include "EPI.h"

#include <vector>
#include <array>
#include <algorithm>
#include <iostream>

class Controlador
{
    private:
        std::vector<Insumos*> insumos;
        std::array<std::string, 29> locais = {"AC", "AL", "AP", "AM", "BA", "BA", "CE", "ES", "GO", "MA", "MT", "MS",
                                   "MG", "PA", "PB", "PR", "PE", "PI", "RJ", "RN", "RS", "RO", "RR", "SC",
                                   "SP", "SE", "TO", "DF", "Ministerio"};
        bool estado_existe(const std::string& estado);

    protected:

    public:
        Controlador();
        virtual ~Controlador();
        void CadastroInsumosMs(std::string tipoInsumo);
        void DistribuirInsumosEstados(std::string tipoInsumo);
        void cadastrar_vacina();
        void cadastrar_medicamentos();
        void cadastrar_epis();


        //void Cadastro_Est(t_est *est, int escolha, std::string estado);
        /*
        */
        void ConsultaInsumos(Insumos insumo);

        // Funções de consulta:
        /*
        void Consultar_estoque_local(const string local, int choice); // testar
        void Consult(t_insumos *ins, int escolha);
        void Consult_est(t_est *est, int escolha);
        void consult_est_especifico(t_est *est, std::string busca);
        */


};

#endif // CONTROLER_H
