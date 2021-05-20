#include <iostream>
#include <string>

#include "include/Vacina.h"
#include "include/Controlador.h"

using namespace std;

int main()
{
    Controlador controlador;

    controlador.cadastrar_vacina();

    string nome = "Gabriel";
    cout << "Hello world!" << nome << endl;
    return 0;
}
