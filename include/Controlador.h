#ifndef CONTROLER_H
#define CONTROLER_H

#include "Insumos.h"
#include "Vacina.h"
#include "Medicamento.h"
#include "EPI.h"

#include <vector>
#include <iostream>

class Controlador
{
    private:
        std::vector<Insumos*> insumos;
        std::string locais[29] = {"AC", "AL", "AP", "AM", "BA", "BA", "CE", "ES", "GO", "MA", "MT", "MS",
                                   "MG", "PA", "PB", "PR", "PE", "PI", "RJ", "RN", "RS", "RO", "RR", "SC",
                                   "SP", "SE", "TO", "DF", "Ministerio"};
        bool estado_existe(std::string estado);

    protected:

    public:
        Controlador();
        virtual ~Controlador();
        void CadastroInsumosMs(std::string tipoInsumo);
        void CadastroInsumosEst(std::string tipoInsumo, std::string cdg, std:string estado);
        //void cadastrar_vacina();
        //void Cadastro_Est(t_est *est, int escolha, std::string estado);
        /*
        void cadastrar_medicamentos(const t_insumos medicamentos, const string local);
        void cadastrar_epis(const t_insumos medicamentos, const string local);
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
