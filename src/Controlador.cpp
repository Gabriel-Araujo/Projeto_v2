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
    int quantidade, valor_unitario, quant_doses, intervalo, local_index;


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

    local = "MINISTÉRIO DA SAÚDE";

    cout << "Digite um tipo vacina: " << endl;
    getline(cin, tipo_vacina);

    cout << "Digite a quantidade de doses: " << endl;
    cin >> quant_doses;

    cout << "Digite o tempo entre doses: " << endl;
    cin >> intervalo;

    auto vacina = new Vacina(nome, quantidade, valor_unitario, vencimento, fabricante, local, codigo, tipo_vacina, quant_doses, intervalo);

    local_index = get_local(local);
    locais.at(local_index).adicionar_insumo(vacina);
}


void Controlador::cadastrar_medicamentos() {
    string nome, vencimento, fabricante, local, codigo, tipo_vacina, dosagem, disposicao, administracao;
    int quantidade, valor_unitario, local_index;

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

    local = "MINISTÉRIO DA SAÚDE";

    cout << "Informe a dosagem do Medicamento: " << endl;
    getline(cin, dosagem);

    cout << "Informe a administracao do Medicamento: " << endl;
    getline(cin, administracao);

    cout << "Informe a disposicao do Medicamento: " << endl;
    getline(cin, disposicao);

    auto medicamento = new Medicamento(nome, quantidade, valor_unitario, vencimento, fabricante, local, codigo, dosagem, administracao, disposicao);

    local_index = get_local(local);
    locais.at(local_index).adicionar_insumo(medicamento);
}


void Controlador::cadastrar_epis() {
    string nome, vencimento, fabricante, local, codigo, tipo_epi, descricao;
    int quantidade, valor_unitario, local_index;

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

    local = "MINISTÉRIO DA SAÚDE";

    cout << "Informe o tipo da epi: " << endl;
    getline(cin, tipo_epi);
    cout << "Informe a descricap do EPI: " << endl;
    getline(cin, descricao);

    auto epi = new EPI(nome, quantidade, valor_unitario, vencimento, fabricante, local, codigo, tipo_epi, descricao);

    local_index = get_local(local);
    locais.at(local_index).adicionar_insumo(epi);
}


void Controlador::CadastroInsumosEst(std::string tipoInsumo, std::string codigo, std::string estado, int quantidade)
{
    int index = get_local("MINISTÉRIO DA SAÚDE");
    int insumo_index = locais.at(index).get_insumo_index(codigo);

    Insumos *insumo_do_ms = locais.at(index).getInsumosVerify(codigo);

    Insumos *insumo_distribuido = new Insumos(*insumo_do_ms);
    insumo_do_ms->DescontaQuantidade(quantidade);

    insumo_distribuido->setQuantidade(quantidade);


    int estado_index = get_local(estado);
    locais.at(estado_index).adicionar_insumo(insumo_distribuido);
}



bool Controlador::local_existe(std::string local) {
    bool test_sigla =  any_of(locais.begin(), locais.end(),[local](Local elem) {return elem.get_sigla() == local;});
    bool test_nome = any_of(locais.begin(), locais.end(),[local](Local elem) {return elem.get_nome_extenso() == local;});

    if (test_sigla || test_nome) { return true; }
    else {return false;}
}


int Controlador::get_local(const std::string local) {
    for (unsigned int index = 0; index < locais.size(); index++) {
        if (locais.at(index).get_sigla() == local || locais.at(index).get_nome_extenso() == local) {return index; }
    }
    return -1;
}


// Só para ser usada no main. ( Não é pra existir quando o projeto terminar)
void Controlador::exibir_insumos_quantidade(std::string local) {
    locais.at(get_local(local)).exibir_insumos_quantidade();
}

//Sla, vey, to seguindo o fluxo
void Controlador::exibir_insumos_descricao(std::string local) {
    locais.at(get_local(local)).exibir_insumos_descricao();
}

void Controlador::exibir_insumos_total(std::string local)
{
    locais.at(get_local(local)).exibir_insumos_total();
}
// Só para ser usada no main. ( Não é pra existir quando o projeto terminar)
void Controlador::exibir_insumos_por_tipo(std::string local, std::string tipo) {
    int local_index = get_local(local);
    locais.at(local_index).exibir_insumos_por_tipo(tipo);
}


// Talvez temporario.
void Controlador::insumo_existe_no_local(const std::string local, const std::string codigo) {
    if (locais.at(get_local(local)).insumo_existe(codigo)) {
        cout <<"SIM";
    }
}

void Controlador::Exibe_menu()
{
    int opcao, quantidade;
    string opcao_string, estado, codigo;
    while(1){
    menus.Boas_vindas();

    cin >> opcao;
    getchar();
    if(opcao == 0){
        break;
    }
        switch (opcao){
        case 1:
            menus.Cadastro();
            getline(cin, opcao_string);
            CadastroInsumosMs(opcao_string);
            break;
        case 2:
            menus.Distribuir();
            cin >> opcao;
            getchar();
            if(opcao == 1){
                menus.exibir_estados();
                getline(cin, estado);
                if(estado == "voltar"){
                    break;
                }

                menus.Distribuir_submenu_1();
                getline(cin, opcao_string);
                if(opcao_string == "voltar"){
                    break;
                }

                menus.Distribuir_submenu_2();
                getline(cin, codigo);
                if(opcao_string == "voltar"){
                    break;
                }

                menus.Distribuir_submenu_3();
                cin.ignore() >> quantidade;

                CadastroInsumosEst(opcao_string, codigo, estado, quantidade);

            }else{
                break;
            }
            break;
        case 3:
            menus.ConsultarMs();
            cin >> opcao;
            getchar();
            if(opcao == 1){
                exibir_insumos_quantidade("MINISTÉRIO DA SAÚDE");
            }else if(opcao == 2){
                exibir_insumos_descricao("MINISTÉRIO DA SAÚDE");
            }else if(opcao == 3)
        default:
            break;

        }
    }
}
