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
    std::string estado;
    getchar();
    getline(cin, estado);
    controlador.CadastroInsumosEst(tipoinsumo, "1011", estado, n);
    controlador.ConsultaInsumosMS(tipoinsumo,1);
    controlador.ConsultaInsumosEst(estado, "vacina", 1);




    controlador.exibir_insumos_ministerio();


    cout << "Hello world!" << endl;
    return 0;
}
