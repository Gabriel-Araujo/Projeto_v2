#include <iostream>
#include <string>

#include "include/Vacina.h"
#include "include/Controlador.h"
#include "include/Persistencia.h"

using namespace std;

#define CLEAR_DEFINE "cls"

int main()
{
    Controlador controlador;


    system("chcp 65001");


    controlador.iniciar_programa();


    cout << "Programa encerrou com sucesso." << endl;

    return 0;
}
