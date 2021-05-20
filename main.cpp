#include <iostream>
#include <string>

#include "include/Vacina.h"
#include "include/Controlador.h"

using namespace std;

int main()
{
    Controlador controlador;

    string tipoinsumo;
    cin >> tipoinsumo;
    getchar();
    controlador.CadastroInsumosMs(tipoinsumo);

    string nome = "Gabriel";
    cout << "Hello world!" << nome << endl;
    return 0;
}
