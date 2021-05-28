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

// Retorna 0 quando da algum erro, e 1 quando há sucesso.
int Controlador::distribuir_vacina_para(const std::string estado, std::string codigo, int quantidade){
    int index_estado = get_local(estado);
    int index_ministerio = get_local("MIN");
    std::string tipo_insumo = "vacina";

    if (locais.at(index_ministerio).insumo_existe(codigo)) {
        auto insumo_ministerio = locais.at(index_ministerio).get_vacina(codigo);
        if (quantidade > insumo_ministerio->get_quantidade()) {
            return 0;
        }
        else {
            if (locais.at(index_estado).insumo_existe(codigo)) {
                auto insumo_estado = locais.at(index_estado).get_vacina(codigo);
                if (!(insumo_estado->get_tipo() == tipo_insumo)) {return 0;}
                insumo_estado->acrescentar_quantidade(quantidade);
                insumo_ministerio->DescontaQuantidade(quantidade);
                return 1;
            }
            else {
                auto insumo_estado = new Vacina(*insumo_ministerio);
                if (!(insumo_estado->get_tipo() == tipo_insumo)) {return 0;}
                insumo_estado->setQuantidade(quantidade);
                insumo_estado->set_local(estado);
                insumo_ministerio->DescontaQuantidade(quantidade);
                locais.at(index_estado).adicionar_insumo(insumo_estado);
                return 1;
            }
        }
    }
    return 0;
}


// Retorna 0 quando da algum erro, e 1 quando há sucesso.
int Controlador::distribuir_medicamento_para(const std::string estado, std::string codigo, int quantidade){
    int index_estado = get_local(estado);
    int index_ministerio = get_local("MIN");
    std::string tipo_insumo = "medicamento";

    if (locais.at(index_ministerio).insumo_existe(codigo)) {
        auto insumo_ministerio = locais.at(index_ministerio).get_medicamento(codigo);
        if (quantidade > insumo_ministerio->get_quantidade()) {
            return 0;
        }
        else {
            if (locais.at(index_estado).insumo_existe(codigo)) {
                auto insumo_estado = locais.at(index_estado).get_medicamento(codigo);
                if (!(insumo_estado->get_tipo() == tipo_insumo)) {return 0;}
                insumo_estado->acrescentar_quantidade(quantidade);
                insumo_ministerio->DescontaQuantidade(quantidade);
                return 1;
            }
            else {
                auto insumo_estado = new Medicamento(*insumo_ministerio);
                if (!(insumo_estado->get_tipo() == tipo_insumo)) {return 0;}
                insumo_estado->setQuantidade(quantidade);
                insumo_estado->set_local(estado);
                insumo_ministerio->DescontaQuantidade(quantidade);
                locais.at(index_estado).adicionar_insumo(insumo_estado);
                return 1;
            }
        }
    }
    return 0;
}


// Retorna 0 quando da algum erro, e 1 quando há sucesso.
int Controlador::distribuir_epi_para(const std::string estado, std::string codigo, int quantidade){
    int index_estado = get_local(estado);
    int index_ministerio = get_local("MIN");
    std::string tipo_insumo = "epi";

    if (locais.at(index_ministerio).insumo_existe(codigo)) {
        auto insumo_ministerio = locais.at(index_ministerio).get_epi(codigo);
        if (quantidade > insumo_ministerio->get_quantidade()) {
            return 0;
        }
        else {
            if (locais.at(index_estado).insumo_existe(codigo)) {
                auto insumo_estado = locais.at(index_estado).get_epi(codigo);
                if (!(insumo_estado->get_tipo() == tipo_insumo)) {return 0;}
                insumo_estado->acrescentar_quantidade(quantidade);
                insumo_ministerio->DescontaQuantidade(quantidade);
                return 1;
            }
            else {
                auto insumo_estado = new EPI(*insumo_ministerio);
                if (!(insumo_estado->get_tipo() == tipo_insumo)) {return 0;}
                insumo_estado->setQuantidade(quantidade);
                insumo_estado->set_local(estado);
                insumo_ministerio->DescontaQuantidade(quantidade);
                locais.at(index_estado).adicionar_insumo(insumo_estado);
                return 1;
            }
        }
    }
    return 0;
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

    Insumos *insumo_do_ms = locais.at(index).get_insumo(codigo);

    Insumos *insumo_distribuido = new Insumos(*insumo_do_ms);
    insumo_do_ms->DescontaQuantidade(quantidade);

    insumo_distribuido->setQuantidade(quantidade);


    int estado_index = get_local(estado);
    locais.at(estado_index).adicionar_insumo(insumo_distribuido);
}



bool Controlador::local_existe(std::string &local) {
    bool test_sigla =  any_of(locais.begin(), locais.end(),[&local](Local &elem) {return elem.get_sigla() == local;});
    bool test_nome = any_of(locais.begin(), locais.end(),[&local](Local &elem) {return elem.get_nome_extenso() == local;});

    if (test_sigla || test_nome) { return true; }
    else {return false;}
}


int Controlador::get_local(const std::string local) {
    string local_mut = local;
    transform(local_mut.begin(), local_mut.end(), local_mut.begin(), [](char c){ return toupper(c);});

    for (unsigned int index = 0; index < locais.size(); index++) {
        if (locais.at(index).get_sigla() == local_mut || locais.at(index).get_nome_extenso() == local_mut) {return index; }
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

// Só para ser usada no main. ( Não é pra existir quando o projeto terminar)
void Controlador::exibir_insumos_por_tipo(std::string local, std::string tipo) {
    int local_index = get_local(local);

    cout << tipo << "disponíveis no estoque de " << local << "." << endl;
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
                exibir_vacina("1000", "MIN");
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
                while (true) {
                    getline(cin, opcao_string);
                    if(opcao_string == "voltar" || tipo_existe(opcao_string)){
                        break;
                    }
                }

                system(CLEAR_DEFINE);
                exibir_insumos_por_tipo("MINISTÉRIO DA SAÚDE", opcao_string);
                menus.Distribuir_submenu_2();
                getline(cin, codigo);
                if(opcao_string == "voltar"){
                    break;
                }

                menus.Distribuir_submenu_3();
                cin >> quantidade;

                //CadastroInsumosEst(opcao_string, codigo, estado, quantidade);
                if (opcao_string == "vacina") {
                    if (!distribuir_vacina_para(estado, codigo, quantidade)) { cout << "não foi possível distribuir vacina.";}
                }
                else if (opcao_string == "medicamento") {
                    if (!distribuir_medicamento_para(estado, codigo, quantidade)) { cout << "não foi possível distribuir medicamento.";}
                }
                else if (opcao_string == "epi") {
                    if (!distribuir_epi_para(estado, codigo, quantidade)) { cout << "não foi possível distribuir epi.";}
                }

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
            }
        default:
            break;

        }
    }
}



bool Controlador::tipo_existe(std::string tipo) {
    transform(tipo.begin(), tipo.end(), tipo.begin(), [](char c) {return tolower(c);});

    return any_of(tipos_possiveis.begin(), tipos_possiveis.end(), [&tipo](std::string &item){return item == tipo;});
}



void Controlador::exibir_vacina(std::string codigo, std::string local) {
    Vacina *vacina = locais.at(get_local(local)).get_vacina(codigo);

    menus.exibir_vacina(*vacina);
}


void Controlador::exibir_medicamento(std::string codigo, std::string local) {
    Medicamento *medicamento = locais.at(get_local(local)).get_medicamento(codigo);

    menus.exibir_medicamento(*medicamento);
}


void Controlador::exibir_epi(std::string codigo, std::string local) {
    EPI *epi = locais.at(get_local(local)).get_epi(codigo);

    menus.exibir_EPI(*epi);
}


[[noreturn]] void Controlador::loop_hole() {
    int escolha, quantidade_distribuir, opcao_consultar, consulta_submenu_3;
    std::string tipo_para_cadastro, local, tipo_para_distribuir, codigo_distribuir, codigo_consulta, tipo_consulta;
    // Mantem o programa rodando até chegar um break.
    while(true) {
        system(CLEAR_DEFINE);
        menus.Boas_vindas();

        cout << "Digite a sua escolha : ";
        cin >> escolha;
        getchar();

        switch (escolha) {
            case 0:
                break;
            case 1: // Cadastro
                system(CLEAR_DEFINE);
                menus.Cadastro();
                getline(cin, tipo_para_cadastro);

                if (tipo_para_cadastro == "0" || tipo_para_cadastro == "voltar") {break;}
                else {
                    CadastroInsumosMs(tipo_para_cadastro);
                }
                break;
            case 2: // Distribuir
                system(CLEAR_DEFINE);
                menus.Distribuir();
                menus.exibir_estados();
                getline(cin, local);
                menus.Distribuir_submenu_1();
                getline(cin, tipo_para_distribuir);
                if (tipo_para_distribuir == "0" || tipo_para_distribuir == "voltar") {break;}
                else if (tipo_existe(tipo_para_distribuir)) {
                    cout << "Tipo expecificado não existe. Tente novamente.";
                    break;
                }
                else {
                    menus.Distribuir_submenu_2();
                    getline(cin, codigo_distribuir);
                    menus.Distribuir_submenu_3();
                    cin >> quantidade_distribuir;
                    getchar();

                    if (tipo_para_distribuir == "vacina") {
                        distribuir_vacina_para(local, codigo_distribuir, quantidade_distribuir);
                    }
                    else if (tipo_para_distribuir == "medicamento") {
                        distribuir_medicamento_para(local, codigo_distribuir, quantidade_distribuir);
                    }
                    else if (tipo_para_distribuir == "epi") {
                        distribuir_epi_para(local, codigo_distribuir, quantidade_distribuir);
                    }
                }
                break;
            case 3: // Exibir
                system(CLEAR_DEFINE);
                menus.ConsultarMs();
                cin >> opcao_consultar;
                getchar();

                system(CLEAR_DEFINE);
                switch (opcao_consultar) {
                    case 0:
                        break;
                    case 1:
                        exibir_insumos_quantidade("MIN");
                        break;
                    case 2:
                        exibir_insumos_descricao("MIN");
                        cout << "Digite o insumo que você quer ver detalhado: ";
                        getline(cin, codigo_consulta);
                        tipo_consulta = locais.at(get_local("MIN")).get_insumo_tipo(codigo_consulta);

                        if (tipo_consulta == "vacina") { exibir_vacina(codigo_consulta, "MIN");}
                        else if (tipo_consulta == "medicamento") { exibir_medicamento(codigo_consulta, "MIN");}
                        else if (tipo_consulta == "epi") { exibir_epi(codigo_consulta, "MIN");}
                        else {cout << "Tipo inválido ou digitado errado. Tente novamente"; system(WAIT_DEFINE); break;}
                        break;

                    case 3:
                        menus.Consultar_submenu_3();
                        cin >> consulta_submenu_3;
                        getchar();
                        switch (consulta_submenu_3) {
                            case 1:
                                cout << "\nQuantidade de vacinas: " << locais.at(get_local("MIN")).get_vacina_quantidade() <<
                                     "\n_____________________________________________________________________________________________________\n" << endl;
                                exibir_insumos_por_tipo("MIN", "vacina");
                                break;
                            case 2:
                                cout << "\nQuantidade de medicamentos: " << locais.at(get_local("MIN")).get_vacina_quantidade() <<
                                     "\n_____________________________________________________________________________________________________\n" << endl;
                                exibir_insumos_por_tipo("MIN", "vacina");
                                break;
                            case 3:
                                cout << "\nQuantiade de EPIs: " << locais.at(get_local("MIN")).get_vacina_quantidade() <<
                                     "\n______________________________________________________________________________________________________\n" << endl;
                                exibir_insumos_por_tipo("MIN", "vacina");
                                break;
                            default:
                                cout << "Entrada incorreta." << endl;
                            }
                        system("pause");
                        break;
                    case 4: ;

                }
        }
    }
}