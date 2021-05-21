#include "../include/Controlador.h"

 using namespace std;

Controlador::Controlador()
{
    locais[0] = {"Acre", "AC"};
    locais[1] = {"Alagoas", "AL"};
    locais[2] = {"Amapá", "AP"};
    locais[3] = {"Amazonas", "AM"};
    locais[4] = {"Bahia", "BA"};
    locais[5] = {"Ceará", "CE"};
    locais[6] = {"Espírito Santo", "ES"};
    locais[7] = {"Goiás", "GO"};
    locais[8] = {"Maranhão", "MA"};
    locais[9] = {"Mato Grosso", "MT"};
    locais[10] = {"Mato Grosso do Sul", "MS"};
    locais[11] = {"Minas Gerais", "MG"};
    locais[12] = {"Pará", "PA"};
    locais[13] = {"Paraíba", "PB"};
    locais[14] = {"Paraná", "PR"};
    locais[15] = {"Pernambuco", "PE"};
    locais[16] = {"Piauí", "PI"};
    locais[17] = {"Rio de Janeiro", "RJ"};
    locais[18] = {"Rio Grande do Norte", "RN"};
    locais[19] = {"Rio Grande do Sul", "RS"};
    locais[20] = {"Rondônia", "RO"};
    locais[21] = {"Roraima", "RR"};
    locais[22] = {"Santa Catarina", "SC"};
    locais[23] = {"São Paulo", "SP"};
    locais[24] = {"Sergipe", "SE"};
    locais[25] = {"Tocantins", "TO"};
    locais[26] = {"Distrito Federal", "DF"};
    locais[27] = {"MINISTÉRIO DA SAÚDE", "MIN"};
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

    local = "MINISTERIO";

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

    local = "MINISTERIO";

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

    local = "MINISTERIO";

    cout << "Informe a dosagem do Medicamento: " << endl;
    getline(cin, tipo_epi);
    cout << "Informe a descricap do EPI: " << endl;
    getline(cin, descricao);

    EPI *epi = new EPI(nome, quantidade, valor_unitario, vencimento, fabricante, local, codigo, tipo_epi, descricao);

    insumos.push_back(epi);
}

bool Controlador::local_existe(std::string local) {
    bool test_sigla =  any_of(locais.begin(), locais.end(),[local](Local elem) {return elem.get_sigla() == local;});
    bool test_nome = any_of(locais.begin(), locais.end(),[local](Local elem) {return elem.get_nome_extenso() == local;});

    if (test_sigla || test_nome) { return true; }
    else {return false;}
}