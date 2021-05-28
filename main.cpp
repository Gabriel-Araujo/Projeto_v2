#include <iostream>
#include <string>

#include "include/Vacina.h"
#include "include/Controlador.h"
#include "include/Persistencia.h"

using namespace std;

#define CLEAR_DEFINE "cls"

int main()
{
    Persistencia persistencia;
    system("chcp 65001");

    Controlador controlador;
    //string tipoinsumo;
    /*cout << "Digite o tipo do insumo:" << endl;
    cout << "| vacina | medicamento | epi |" << endl;
    cin >> tipoinsumo;
    getchar();
    controlador.CadastroInsumosMs(tipoinsumo);


    controlador.exibir_insumos_por_tipo("MIN", "vacina");*/

<<<<<<< HEAD
    controlador.Exibe_menu();

=======

    controlador.loop_hole();





    cout << "Hello world!" << endl;
>>>>>>> d2a1bd5d650c003d404bf9697d01d82bb13fdb65
    return 0;
}
