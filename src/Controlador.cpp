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
{/*
    for (auto local: locais) {
        local.delete_all();
    }*/
}

void Controlador::CadastroInsumo(string tipo_ins) {
    transform(tipo_ins.begin(), tipo_ins.end(), tipo_ins.begin(), [](char c){ return tolower(c);});

    if(tipo_ins == "vacina"){
        locais.at(get_local_index("MIN")).cadastrar_vacina();

    }else if(tipo_ins == "medicamento"){
        locais.at(get_local_index("MIN")).cadastrar_medicamentos();

    }else if(tipo_ins == "epi"){
        locais.at(get_local_index("MIN")).cadastrar_epis();
    }

}


// Retorna 0 quando da algum erro, e 1 quando há sucesso.
int Controlador::distribuir_vacina_para(const std::string estado, std::string codigo, int quantidade){
    int index_estado = get_local_index(estado);
    int index_ministerio = get_local_index("MIN");
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
    int index_estado = get_local_index(estado);
    int index_ministerio = get_local_index("MIN");
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
    int index_estado = get_local_index(estado);
    int index_ministerio = get_local_index("MIN");
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


bool Controlador::local_existe(std::string &local) {
    bool test_sigla =  any_of(locais.begin(), locais.end(),[&local](Local &elem) {return elem.get_sigla() == local;});
    bool test_nome = any_of(locais.begin(), locais.end(),[&local](Local &elem) {return elem.get_nome_extenso() == local;});

    if (test_sigla || test_nome) { return true; }
    else {return false;}
}


int Controlador::get_local_index(const std::string local) {
    string local_mut = local;
    transform(local_mut.begin(), local_mut.end(), local_mut.begin(), [](char c){ return toupper(c);});

    for (unsigned int index = 0; index < locais.size(); index++) {
        if (locais.at(index).get_sigla() == local_mut || locais.at(index).get_nome_extenso() == local_mut) {return index; }
    }
    return -1;
}


bool Controlador::tipo_existe(std::string tipo) {
    transform(tipo.begin(), tipo.end(), tipo.begin(), [](char c) {return tolower(c);});

    return any_of(tipos_possiveis.begin(), tipos_possiveis.end(), [&tipo](std::string &item){return item == tipo;});
}


void Controlador::exibir_insumo_detalhado(Insumos &insumo) {
    if (insumo.getNome() == "NULL") {return;}
    std::string tipo_do_insumo = insumo.get_tipo();
    std::string codigo_do_insumo = insumo.getCodigoUnico();
    Local local = locais.at(get_local_index(insumo.get_local()));

    if(tipo_do_insumo == "vacina") {
        Vacina *vacina = local.get_vacina(codigo_do_insumo);
        vacina->exibir();
    }
    else if (tipo_do_insumo == "medicamento") {
        Medicamento *medicamento = local.get_medicamento(codigo_do_insumo);
        medicamento->exibir();
    }
    else if (tipo_do_insumo == "epi") {
        EPI *epi = local.get_epi(codigo_do_insumo);
        epi->exibir();
    }
}


int Controlador::loop_hole() {
    int escolha;

    // Mantem o programa rodando até chegar um break.
    while(true) {
        system(CLEAR_DEFINE);
        menus.Boas_vindas();

        cin >> escolha;
        getchar();

        if (escolha == 0) {return 0;}
        else exibir_menus(escolha);
    }
}


void Controlador::exibir_menus(int escolha) {

    switch (escolha) {
        case 0:
            break;
        case 1: // Cadastro
            exibir_menus_cadastro();
            break;
        case 2: // Distribuir
            exibir_menus_distribuir();
            break;
        case 3: // Consulta Ministerio
            exibir_menus_consultar_ms();
            break;
        case 4:
            exibir_menus_consulta_estados();
            break;
    }
}


void Controlador::exibir_menus_cadastro() {
    std::string tipo_para_cadastro;

    system(CLEAR_DEFINE);
    menus.Cadastro();
    getline(cin, tipo_para_cadastro);

    if (tipo_para_cadastro == "0" || tipo_para_cadastro == "voltar") {}
    else {
        CadastroInsumo(tipo_para_cadastro);
    }
}


void Controlador::exibir_menus_distribuir() {
    int quantidade_distribuir;
    std::string local, tipo_para_distribuir, codigo_distribuir;

    system(CLEAR_DEFINE);

    menus.exibir_estados();
    getline(cin, local);

    if (local == "0" || local == "voltar" || !local_existe(local)) {return;}
    menus.Distribuir_submenu_1();
    getline(cin, tipo_para_distribuir);

    if (tipo_para_distribuir == "0" || tipo_para_distribuir == "voltar") {return;}
    else if (!tipo_existe(tipo_para_distribuir)) {
        cout << "Tipo expecificado não existe. Tente novamente.\n";
    }
    else {
        menus.Distribuir_submenu_2();
        getline(cin, codigo_distribuir);
        if (codigo_distribuir == "voltar") {return;}

        menus.Distribuir_submenu_3();
        cin >> quantidade_distribuir;
        getchar();
        if (quantidade_distribuir == 0) {return;}

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
}


void Controlador::exibir_menus_consultar_ms() {
    int opcao_consultar, escolha_submenu_2;
    std::string codigo_consulta, tipo_consulta, escolha_submenu_3;
    Local &local = locais.at(get_local_index("MIN"));


    system(CLEAR_DEFINE);
    menus.ConsultarMs();
    cin >> opcao_consultar;
    getchar();

    system(CLEAR_DEFINE);
    if (opcao_consultar == 0) { return; }
    else if (opcao_consultar == 1) {
        cout << "Quantidade de insumos (Vacinas, Medicamentos e EPIs)." << endl;
        cout << "___________________________________________________________________________________________________________\n";
        cout << "Quantidade de vacinas (em unidades):" << local.get_vacina_quantidade() << endl;
        cout << "\nQuantidade de medicamentos (em unidades):" << local.get_medicamento_quantidade() << endl;
        cout << "\nQuantidade de EPIs (em unidades):" << local.get_epi_quantidade() << endl;

        cout << "\nQuantidade total (em unidades): " << local.get_insumos_quantidade() << endl;
        system(WAIT_DEFINE);
        return;
    }

    else if (opcao_consultar == 2) {
        menus.Consultar_submenu_2();
        cin >> escolha_submenu_2;
        getchar();

        switch (escolha_submenu_2) {
            case 1:
                cout << "\nQuantidade de vacinas: " << local.get_vacina_quantidade() <<
                     "\n_____________________________________________________________________________________________________\n"
                     << endl;
                local.exibir_insumos_por_tipo("vacina");
                system(WAIT_DEFINE);
                break;
            case 2:
                cout << "\nQuantidade de medicamentos: " << local.get_medicamento_quantidade() <<
                     "\n_____________________________________________________________________________________________________\n"
                     << endl;
                local.exibir_insumos_por_tipo("medicamento");
                system(WAIT_DEFINE);
                break;
            case 3:
                cout << "\nQuantiade de EPIs: " << local.get_epi_quantidade() <<
                     "\n______________________________________________________________________________________________________\n"
                     << endl;
                local.exibir_insumos_por_tipo("epi");
                system(WAIT_DEFINE);
                break;
            default:
                cout << "Entrada incorreta." << endl;
                system(WAIT_DEFINE);
        }
        return;
    }

    else if (opcao_consultar == 3) {
        cout << "\n\nVacinas:______________________________________________________________________________________________\n";
        local.exibir_insumos_por_tipo("vacina");

        cout << "\n\nmedicamentos:_________________________________________________________________________________________\n";
        local.exibir_insumos_por_tipo("medicamento");

        cout << "\n\nEPI:__________________________________________________________________________________________________\n";
        local.exibir_insumos_por_tipo("epi");

        cout << "Digite o codigo unico do insumo: ";
        getline(cin, escolha_submenu_3);
        system(CLEAR_DEFINE);


        local.exibir_insumo_detalhado(escolha_submenu_3);

        system(WAIT_DEFINE);
        return;
    }
}


void Controlador::exibir_menus_consulta_estados(){
    int opcao_consultar, escolha_submenu_2;
    std::string lcl, codigo_consulta, tipo_consulta, escolha_submenu_3;

    system(CLEAR_DEFINE);
    menus.exibir_estados();
    getline(cin, lcl);
     if (lcl == "0" || lcl == "voltar" || !local_existe(lcl)) {return;}

    Local &local = locais.at(get_local_index(lcl));
    menus.Unidades_distribuidas();
    cin >> opcao_consultar;
    getchar();

    system(CLEAR_DEFINE);
    if (opcao_consultar == 0) { return; }
    else if (opcao_consultar == 1) {
        cout << "Quantidade de insumos (Vacinas, Medicamentos e EPIs)." << endl;
        cout << "___________________________________________________________________________________________________________\n";
        cout << "Quantidade de vacinas (em unidades):" << local.get_vacina_quantidade() << endl;
        cout << "\nQuantidade de medicamentos (em unidades):" << local.get_medicamento_quantidade() << endl;
        cout << "\nQuantidade de EPIs (em unidades):" << local.get_epi_quantidade() << endl;

        cout << "\nQuantidade total (em unidades): " << local.get_insumos_quantidade() << endl;
        system(WAIT_DEFINE);
        return;
    }

    else if (opcao_consultar == 2) {
        menus.Consultar_submenu_2();
        cin >> escolha_submenu_2;
        getchar();

        switch (escolha_submenu_2) {
            case 1:
                cout << "\nQuantidade de vacinas: " << local.get_vacina_quantidade() <<
                     "\n_____________________________________________________________________________________________________\n"
                     << endl;
                local.exibir_insumos_por_tipo("vacina");
                system(WAIT_DEFINE);
                break;
            case 2:
                cout << "\nQuantidade de medicamentos: " << local.get_medicamento_quantidade() <<
                     "\n_____________________________________________________________________________________________________\n"
                     << endl;
                local.exibir_insumos_por_tipo("medicamento");
                system(WAIT_DEFINE);
                break;
            case 3:
                cout << "\nQuantiade de EPIs: " << local.get_epi_quantidade() <<
                     "\n______________________________________________________________________________________________________\n"
                     << endl;
                local.exibir_insumos_por_tipo("epi");
                system(WAIT_DEFINE);
                break;
            default:
                cout << "Entrada incorreta." << endl;
                system(WAIT_DEFINE);
        }
        return;
    }
    else if (opcao_consultar == 3) {
        cout << "\n\nVacinas:______________________________________________________________________________________________\n";
        local.exibir_insumos_por_tipo("vacina");

        cout << "\n\nmedicamentos:_________________________________________________________________________________________\n";
        local.exibir_insumos_por_tipo("medicamento");

        cout << "\n\nEPI:__________________________________________________________________________________________________\n";
        local.exibir_insumos_por_tipo("epi");

        cout << "Digite o codigo unico do insumo: ";
        getline(cin, escolha_submenu_3);
        system(CLEAR_DEFINE);

        //Insumos *insumo = local.get_insumo(escolha_submenu_3);

        //exibir_insumo_detalhado(insumo);

        system(WAIT_DEFINE);
        return;
    }
}
