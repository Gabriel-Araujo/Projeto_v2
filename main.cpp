#include <iostream>
#include <string>

#include "include/Vacina.h"
#include "include/Controlador.h"
#include "include/Persistencia.h"

using namespace std;

#define CLEAR_DEFINE "cls"

int main()
{
    //Persistencia persistencia;
    system("chcp 65001");

    Controlador controlador;

    controlador.loop_hole();
    //teste 2
    //controlador.loop_hole();





    cout << "Hello world!" << endl;

    return 0;
}
