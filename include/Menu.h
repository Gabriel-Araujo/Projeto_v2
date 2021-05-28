#ifndef MENU_H
#define MENU_H


#include <iomanip>
#include <iostream>
#include <vector>
#include "Insumos.h"
#include "Vacina.h"
#include "Medicamento.h"
#include "EPI.h"
#include <cstdlib>

#define CLEAR_DEFINE "cls"


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
        void Consultar_submenu_3();

        void Unidades_distribuidas();
        void Unidades_distribuidas_submenu_3();
        void Insumos_distribuidos();
        void exibir_estados();

        void exibir_quantidades(std::vector<Insumos*> &Insumos);
        void exibir_formatado(std::vector<Insumos*> &insumos);
        void exibir_vacina(Vacina &vacina);


    protected:

    private:
};

#endif // MENU_H
