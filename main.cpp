#include <iostream>
#include <string>

#include "include/Vacina.h"
#include "include/Controlador.h"

using namespace std;

int main()
{
    Controlador controlador;

    string tipoinsumo;
    cout << "Digite o tipo do insumo:" << endl;
    cout << "| vacina | medicamento | epi |" << endl;
    cin >> tipoinsumo;
    getchar();
    controlador.CadastroInsumosMs(tipoinsumo);

    controlador.exibir_insumos_ministerio();

    cout << "Hello world!" << endl;
    return 0;
}
