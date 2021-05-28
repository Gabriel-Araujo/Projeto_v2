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
#define WAIT_DEFINE "pause"


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
<<<<<<< HEAD
<<<<<<< HEAD
        void exibir_total(std::vector<Insumos*> &Insumos);
=======
        void exibir_vacina(Vacina &vacina);
>>>>>>> d2a1bd5d650c003d404bf9697d01d82bb13fdb65
=======
        void exibir_vacina(Vacina *vacina);
        void exibir_medicamento(Medicamento *medicamento);
        void exibir_EPI(EPI *epi);
>>>>>>> 59331ace5537441b3cae1095f8c3d92edee2ac61


    protected:

    private:
};

#endif // MENU_H
