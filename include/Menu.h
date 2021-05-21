#ifndef MENU_H
#define MENU_H
#include "Controlador.h"

class Menu
{
    public:
        Menu();
        virtual ~Menu();

        void Boas_vindas();
        void Cadastro();
        void Distribuir();
        void Distribuir_submenu_1();
        void Consultar();
        void Consultar_submenu_3();
        void Unidades_distribuidas();
        void Unidades_distribuidas_submenu_3();
        void Insumos_distribuidos();


    protected:

    private:
};

#endif // MENU_H
