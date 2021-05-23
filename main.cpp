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

    int n;
    cout << "Digite a quantidade que quer distribuir: ";
    cin >> n;
    controlador.CadastroInsumosEst(tipoinsumo, "1011", "Paraíba", n);
    controlador.ConsultaInsumosMS(tipoinsumo,1);
    controlador.ConsultaInsumosEst("Paraíba", "vacina", 1);




    cout << "Hello world!" << endl;
    return 0;
}
