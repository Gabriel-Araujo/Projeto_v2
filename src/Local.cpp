#include "../include/Local.h"


Local::Local()
{
    nome_extenso = "NULL";
    sigla = "NULL";
}

Local::Local(std::string nome, std::string sigla) {
    nome_extenso = std::move(nome);
    this->sigla = std::move(sigla);
}

Local::~Local(){
    for (auto item: insumos) {
        delete item;
    }
}


Insumos* Local::get_insumo(const std::string& codigo) {
    for (auto item: insumos) {
        if (item->getCodigoUnico() == codigo) {
            return item;
        }
    }
    return new Insumos();
}


Vacina* Local::get_vacina(const std::string& codigo) {
    for (auto item: insumos) {
        if (item->getCodigoUnico() == codigo && item->getTipoInsumo() == "vacina") {
            return dynamic_cast<Vacina *>(item);
        }
    }
    return new Vacina();
}


Medicamento* Local::get_medicamento(const std::string& codigo) {
    for (auto item: insumos) {
        if (item->getCodigoUnico() == codigo && item->getTipoInsumo() == "medicamento") {
            return dynamic_cast<Medicamento *>(item);
        }
    }
    return new Medicamento();
}



EPI *Local::get_epi(const std::string &codigo) {
    for (auto item: insumos) {
        if (item->getCodigoUnico() == codigo && item->getTipoInsumo() == "epi") {
            return dynamic_cast<EPI *>(item);
        }
    }
    return new EPI();
}


std::vector<Insumos *> Local::getInsumos()
{
    return insumos;
}

std::string Local::get_sigla() {
    return sigla;
}


std::string Local::get_nome_extenso() {
    return nome_extenso;
}


void Local::adicionar_insumo(Insumos *insumo) {
    insumos.push_back(insumo);
    //persiste.Salvar_Insumos(insumos, local);

}

void Local::exibir_insumos_por_tipo(const std::string& tipo) {
    std::vector<Insumos*> generico;

    std::cout << tipo << " disponíveis no estoque de " << nome_extenso << "." << std::endl;

    for (auto item: insumos) {
        if (item->getTipoInsumo() == tipo) {
            auto a = new Insumos(*item);
            generico.push_back(a);
        }
    }
    menus.exibir_formatado(generico);

    for (auto item: generico) {
        delete item;
    }
}


bool Local::insumo_existe(const std::string codigo) {
    return std::any_of(insumos.begin(), insumos.end(), [&codigo](Insumos *item){return item->getCodigoUnico() == codigo;});
}


int Local::get_insumo_index(const std::string codigo) {
    for (unsigned int index = 0; index < insumos.size(); index++) {
        if (insumos.at(index)->getCodigoUnico() == codigo) {return index;}
    }
    return -1;
}


std::string Local::get_insumo_tipo(const std::string codigo) {
    Insumos *insumo = get_insumo(codigo);
    return insumo->get_tipo();
}


int Local::get_vacina_quantidade() {
    int quantidade = 0;
    for (const auto &item: insumos) {
        if(item->getTipoInsumo() == "vacina"){
        quantidade += item->get_quantidade();
        }
    }
    return quantidade;
}


int Local::get_medicamento_quantidade() {
    int quantidade = 0;
    for (auto item: insumos) {
        if (item->getTipoInsumo() == "medicamento"){
            quantidade += item->get_quantidade();
        }
    }
    return quantidade;
}


int Local::get_epi_quantidade() {
    int quantidade = 0;
    for (auto item: insumos) {
        if (item->getTipoInsumo() == "epi"){
            quantidade += item->get_quantidade();
        }
    }
    return quantidade;
}


int Local::get_insumos_quantidade() {
    int quantidade = 0;
    for (auto item: insumos) {
        quantidade += item->get_quantidade();
    }
    return quantidade;
}

void Local::cadastrar_insumo(std::string tipoInsumo) {
    std::string nome, vencimento, fabricante, local, codigo, tipo_epi, descricao, tipo_vacina, dosagem, administracao, disposicao, _quantidade, _valor_unitario, _quant_doses, _intervalo;
    int quantidade, valor_unitario, quant_doses, intervalo;

    std::cout << "Digite o codigo unico:" << std::endl;
    getline(std::cin, codigo);

    if (insumo_existe(codigo)) {
        throw std::runtime_error("Código já existe");
    }

    std::cout << "Digite o nome do produto: " << std::endl;
    getline(std::cin, nome);

    std::cout << "Digite a quantidade a ser cadastrada: " << std::endl;
    getline(std::cin, _quantidade);

    try {
    quantidade = stoi(_quantidade);
    }
    catch (std::invalid_argument& err) {
        throw std::runtime_error("Não foi passado um número inteiro em:\n quantidade.");
    }

    std::cout << "Digite o preço unitario: " << std::endl;
    std::getline(std::cin, _valor_unitario);

    try {
        valor_unitario = stoi(_valor_unitario);
    }
    catch (std::invalid_argument& err) {
        throw std::runtime_error("Não foi passado um número inteiro em:\n preço unitario.");
    }

    std::cout << "Digite a data de vencimento (DD/MM/AAAA): " << std::endl;
    getline(std::cin, vencimento);
    std::cout << "Digite o nome do fabricante: " << std::endl;
    getline(std::cin, fabricante);

    local = "MINISTÉRIO DA SAÚDE";

    if(tipoInsumo == "vacina"){
        std::cout << "Digite um tipo vacina: " << std::endl;
        getline(std::cin, tipo_vacina);

        std::cout << "Digite a quantidade de doses: " << std::endl;
        std::getline(std::cin, _quant_doses);

        try {
            quant_doses = stoi(_quant_doses);
        }
        catch (std::invalid_argument& err) {
            throw std::runtime_error("Não foi passado um número inteiro em:\n quantidade de doses.");
        }

        std::cout << "Digite o tempo entre doses: " << std::endl;
        std::getline(std::cin, _intervalo);

        try {
            intervalo = stoi(_intervalo);
        }
        catch (std::invalid_argument& err) {
            throw std::runtime_error("Não foi passado um número inteiro em:\n intervalo.");
        }

        auto insumo = new Vacina(nome, quantidade, valor_unitario, vencimento, fabricante, local, codigo, tipo_vacina, quant_doses, intervalo);
        insumos.push_back(insumo);

    }else if(tipoInsumo == "medicamento"){
        std::cout << "Informe a dosagem do Medicamento: " << std::endl;
        getline(std::cin, dosagem);

        std::cout << "Informe a administracao do Medicamento: " << std::endl;
        getline(std::cin, administracao);

        std::cout << "Informe a disposicao do Medicamento: " << std::endl;
        getline(std::cin, disposicao);

        auto insumo = new Medicamento(nome, quantidade, valor_unitario, vencimento, fabricante, local, codigo, dosagem, administracao, disposicao);
        insumos.push_back(insumo);

    }else if(tipoInsumo == "epi"){
        std::cout << "Informe o tipo da epi: " << std::endl;
        getline(std::cin, tipo_epi);
        std::cout << "Informe a descricap do EPI: " << std::endl;
        getline(std::cin, descricao);

        auto insumo = new EPI(nome, quantidade, valor_unitario, vencimento, fabricante, local, codigo, tipo_epi, descricao);
        insumos.push_back(insumo);

    }

}

void Local::exibir_insumo_detalhado(std::string codigo) {
    int insumo_index = get_insumo_index(codigo);
    if (insumo_index == -1) {return;}
    if (insumos[insumo_index]->getNome() == "NULL") {return;}

    insumos[insumo_index]->exibir();
}
