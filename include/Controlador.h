#ifndef CONTROLER_H
#define CONTROLER_H

#include "Insumos.h"
#include <vector>

class Controlador
{
    public:
        Controlador();
        virtual ~Controlador();
        void CadastroInsumosMs();
        //void Cadastro_Est(t_est *est, int escolha, std::string estado);
        /*
        void cadastrar_vacina(const t_insumos vacina, const string local);
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

    protected:

    private:
        std::vector<Insumos*> insumos;
};

#endif // CONTROLER_H
