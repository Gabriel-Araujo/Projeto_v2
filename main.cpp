#include <iostream>
#include <string>

#include "include/Vacina.h"
#include "include/Controlador.h"

using namespace std;

#define CLEAR_DEFINE "cls"

int main()
{
    system("chcp 65001");

    Controlador controlador;
    //string tipoinsumo;
    /*cout << "Digite o tipo do insumo:" << endl;
    cout << "| vacina | medicamento | epi |" << endl;
    cin >> tipoinsumo;
    getchar();
    controlador.CadastroInsumosMs(tipoinsumo);


    controlador.exibir_insumos_por_tipo("MIN", "vacina");*/


    controlador.loop_hole();





    cout << "Hello world!" << endl;
    return 0;
}
