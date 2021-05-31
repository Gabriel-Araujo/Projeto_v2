#ifndef MENU_H
#define MENU_H


#include <iomanip>
#include <iostream>
#include <vector>
#include <map>
#include <cstdlib>
#include "Insumos.h"

#define CLEAR_DEFINE "cls"
#define WAIT_DEFINE "pause"


class Insumos;

class Menu
{
    public:
        Menu();
        virtual ~Menu();

        void Boas_vindas();
        void Cadastro();

        void Distribuir();
        void Distribuir_submenu_1();
        void Distribuir_submenu_2();
        void Distribuir_submenu_3();

        void ConsultarMs();
        void Consultar_submenu_2();

        void Unidades_distribuidas();
        void Unidades_distribuidas_submenu_3();
        void Insumos_distribuidos();

        void exibir_estados();
        static void exibir_vacina(std::string codigo, std::string nome, int quantidade, int valor, std::string vencimento, std::string fabricante, int doses, int intervalo, std::string tipo_vac);
        static void exibir_medicamento(std::string codigo, std::string nome, int quantidade, int valor, std::string vencimento, std::string fabricante, std::string dosagem, std::string administracao, std::string disposicao);
        static void exibir_EPI(std::string codigo, std::string nome, int quantidade, int valor, std::string vencimento, std::string fabricante, std::string tipo_api, std::string descricao);

        void exibir_quantidades(std::vector<Insumos*> &Insumos);
        void exibir_formatado(std::vector<Insumos*> &insumos);

        void exibir_total(std::vector<Insumos*> &Insumos);

            //void exibir_EPI(EPI *epi);



    protected:

    private:
};

#endif // MENU_H
