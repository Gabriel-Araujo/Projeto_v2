/**
 * Integrantes :
 *      - DAVID WILSON MELO SANTOS
 *      - GABRIEL SOUZA CRUZ ARAUJO
 *      - LUCAS EDUARDO MELO ALVES
 *
 * Versão mínima do compilador C++: 17
 * Compilar para windows
 */


#include <iostream>
#include <string>

#include "include/Vacina.h"
#include "include/Controlador.h"

using namespace std;


int main()
{
    Controlador controlador;


    system("chcp 65001");


    controlador.iniciar_programa();


    cout << "Programa encerrou com sucesso." << endl;

    return 0;
}
