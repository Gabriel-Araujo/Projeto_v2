#include "../include/Controlador.h"

Controlador::Controlador()
{
    //ctor
}

Controlador::~Controlador()
{
    //dtor
}
//Tem que ser temporaria
void Controlador::cadastrar_vacina() {
    std::string nome, vencimento, fabricante, local, codigo, tipo_vacina;
    int quantidade, valor_unitario, quant_doses, intervalo;


    std::cout << "Digite o codigo unico:" << std::endl;
    std::getline(std::cin, codigo);
    std::cout << "Digite o nome da vacina: " << std::endl;
    std::getline(std::cin, nome);

    std::cout << "Digite a quantidade a ser cadastrada:" << std::endl;
    std::cin >> quantidade;
    std::cout << "Digite o preço unitario:" << std::endl;
    std::cin >> valor_unitario;
    getchar();

    std::cout << "Digite a data de vencimento (DD/MM/AAAA):" << std::endl;
    std::getline(std::cin, vencimento);
    std::cout << "Digite o nome do fabricante:" << std::endl;
    std::getline(std::cin, fabricante);

    while (true) {
        std::cout << "Digite um estado valido (Sigla, tudo maiusculo): " << std::endl;
        std::getline(std::cin, local);
        if (estado_existe(local)) {
            break;
        }
    }

    std::cout << "Digite um tipo vacina:" << std::endl;
    std::getline(std::cin, tipo_vacina);

    std::cout << "Digite a quantidade de doses:" << std::endl;
    std::cin >> quant_doses;

    std::cout << "Digite o tempo entre doses:" << std::endl;
    std::cin >> intervalo;

    Vacina *vacina = new Vacina(nome, quantidade, valor_unitario, vencimento, fabricante, local, codigo, tipo_vacina, quant_doses, intervalo);

    insumos.push_back(vacina);
}


bool Controlador::estado_existe(std::string estado) {
    for (auto item: locais) {
        if (item == estado) {
            return true;
        }
    }
    return false;
}