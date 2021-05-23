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

<<<<<<< HEAD
    int n;
    cout << "Digite a quantidade que quer distribuir: ";
    cin >> n;
    controlador.CadastroInsumosEst(tipoinsumo, "1011", "Paraíba", n);
    controlador.ConsultaInsumosMS(tipoinsumo,1);
    controlador.ConsultaInsumosEst("Paraíba", "vacina", 1);



=======
    controlador.exibir_insumos_ministerio();
>>>>>>> ff8b3fbc8c0f5b71e65735d1e768d70a86e04cf0

    cout << "Hello world!" << endl;
    return 0;
}
