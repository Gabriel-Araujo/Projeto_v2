#include "../include/Controlador.h"

 using namespace std;

Controlador::Controlador()
{
    //ctor
}

Controlador::~Controlador()
{
    //dtor
}

//Tem que ser temporaria
void Controlador::CadastroInsumosMs(std::string tipo_ins)
{

    string nome, vencimento, fabricante, local, codigo, tipo_vacina, dosagem, disposicao, administracao, tipo_epi, descricao;
    int quantidade, valor_unitario, quant_doses, intervalo;

    if(tipo_ins == "Vacina"){

    cout << "Digite o codigo unico:" << endl;
    getline(cin, codigo);
    cout << "Digite o nome da vacina: " << endl;
    getline(cin, nome);

    cout << "Digite a quantidade a ser cadastrada: " << endl;
    cin >> quantidade;
    cout << "Digite o preço unitario: " << std::endl;
    cin >> valor_unitario;
    getchar();

    cout << "Digite a data de vencimento (DD/MM/AAAA): " << endl;
    getline(cin, vencimento);
    cout << "Digite o nome do fabricante: " << endl;
    getline(cin, fabricante);

    local = "Ministerio";
    cout << "Digite um tipo de vacina: " << endl;
    getline(cin, tipo_vacina);

    cout << "Digite a quantidade de doses: " << endl;
    cin >> quant_doses;

    cout << "Digite o tempo entre doses: " << endl;
    cin >> intervalo;

    Vacina *vacina = new Vacina(nome, quantidade, valor_unitario, vencimento, fabricante, local, codigo, tipo_vacina, quant_doses, intervalo);

    insumos.push_back(vacina);

    }else if(tipo_ins == "Medicamento"){

    cout << "Digite o codigo unico:" << endl;
    getline(cin, codigo);
    cout << "Digite o nome do Medicamento: " << endl;
    getline(cin, nome);

    cout << "Digite a quantidade a ser cadastrada: " << endl;
    cin >> quantidade;
    cout << "Digite o preço unitario: " << std::endl;
    cin >> valor_unitario;
    getchar();

    cout << "Digite a data de vencimento (DD/MM/AAAA): " << endl;
    getline(cin, vencimento);
    cout << "Digite o nome do fabricante: " << endl;
    getline(cin, fabricante);

    local = "Ministerio";
    cout << "Informe a dosagem do Medicamento: " << endl;
    getline(cin, dosagem);

    cout << "Informe a administracao do Medicamento: " << endl;
    getline(cin, administracao);

    cout << "Informe a disposicao do Medicamento: " << endl;
    getline(cin, disposicao);

    Medicamento *medicamento = new Medicamento(nome, quantidade, valor_unitario, vencimento, fabricante, local, codigo, dosagem, administracao, disposicao);

    insumos.push_back(medicamento);

    }else if(tipo_ins == "EPI"){

    cout << "Digite o codigo unico:" << endl;
    getline(cin, codigo);
    cout << "Digite o nome do EPI: " << endl;
    getline(cin, nome);

    cout << "Digite a quantidade a ser cadastrada: " << endl;
    cin >> quantidade;
    cout << "Digite o preço unitario: " << std::endl;
    cin >> valor_unitario;
    getchar();

    cout << "Digite a data de vencimento (DD/MM/AAAA): " << endl;
    getline(cin, vencimento);
    cout << "Digite o nome do fabricante: " << endl;
    getline(cin, fabricante);

    local = "Ministerio";
    cout << "Informe a dosagem do Medicamento: " << endl;
    getline(cin, tipo_epi);
    cout << "Informe a descricap do EPI: " << endl;
    getline(cin, descricao);

    EPI *epi = new EPI(nome, quantidade, valor_unitario, vencimento, fabricante, local, codigo, tipo_epi, descricao);

    insumos.push_back(epi);

    }
}

void Controlador::CadastroInsumosEst(std::string tipoInsumo)
{
    //Aqui falta pensar no jeito de manipular o vector para gente nao ter que cadastrar dnv
}

/*
void Controlador::CadastroInsumosMs() {
    string nome, vencimento, fabricante, local, codigo, tipo_vacina;
    int quantidade, valor_unitario, quant_doses, intervalo;


    cout << "Digite o codigo unico:" << endl;
    getline(cin, codigo);
    cout << "Digite o nome da vacina: " << endl;
    getline(cin, nome);

    cout << "Digite a quantidade a ser cadastrada: " << endl;
    cin >> quantidade;
    cout << "Digite o preço unitario: " << std::endl;
    cin >> valor_unitario;
    getchar();

    cout << "Digite a data de vencimento (DD/MM/AAAA): " << endl;
    getline(cin, vencimento);
    cout << "Digite o nome do fabricante: " << endl;
    getline(cin, fabricante);

    while (true) {
        cout << "Digite um estado valido (Sigla, tudo maiusculo): " << endl;
        getline(cin, local);
        if (estado_existe(local)) {
            break;
        }
    }

    cout << "Digite um tipo vacina: " << endl;
    getline(cin, tipo_vacina);

    cout << "Digite a quantidade de doses: " << endl;
    cin >> quant_doses;

    cout << "Digite o tempo entre doses: " << endl;
    cin >> intervalo;

    Vacina *vacina = new Vacina(nome, quantidade, valor_unitario, vencimento, fabricante, local, codigo, tipo_vacina, quant_doses, intervalo);

    insumos.push_back(vacina);
}*/

bool Controlador::estado_existe(string estado) {
    for (auto item: locais) {
        if (item == estado) {
            return true;
        }
    }
    return false;
}
