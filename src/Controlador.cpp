#include "../include/Controlador.h"

 using namespace std;

Controlador::Controlador()
{
    //ctor
}

Controlador::~Controlador()
{
    for (auto item: insumos) {
        delete item;
    }
}

//Tem que ser temporaria
void Controlador::CadastroInsumosMs(string tipo_ins)
{
    transform(tipo_ins.begin(), tipo_ins.end(), tipo_ins.begin(), [](char c){ return tolower(c);});

    if(tipo_ins == "vacina"){
        cadastrar_vacina();

    }else if(tipo_ins == "medicamento"){
        cadastrar_medicamentos();

    }else if(tipo_ins == "epi"){
        cadastrar_epis();
    }
}

void Controlador::DistribuirInsumosEstados(std::string tipoInsumo)
{
    //Aqui falta pensar no jeito de manipular o vector para gente nao ter que cadastrar dnv
}


void Controlador::cadastrar_vacina() {
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

    local = "Ministerio";

    cout << "Digite um tipo vacina: " << endl;
    getline(cin, tipo_vacina);

    cout << "Digite a quantidade de doses: " << endl;
    cin >> quant_doses;

    cout << "Digite o tempo entre doses: " << endl;
    cin >> intervalo;

    Vacina *vacina = new Vacina(nome, quantidade, valor_unitario, vencimento, fabricante, local, codigo, tipo_vacina, quant_doses, intervalo);

    insumos.push_back(vacina);
}


void Controlador::cadastrar_medicamentos() {
    string nome, vencimento, fabricante, local, codigo, tipo_vacina, dosagem, disposicao, administracao;
    int quantidade, valor_unitario;

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
}


void Controlador::cadastrar_epis() {
    string nome, vencimento, fabricante, local, codigo, tipo_epi, descricao;
    int quantidade, valor_unitario;

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


bool Controlador::estado_existe(string& estado) {
    transform(estado.begin(), estado.end(),estado.begin(), [](char c){ return tolower(c);});
    return any_of(locais.begin(), locais.end(),[estado](const string& elem) {return elem == estado;});
}
