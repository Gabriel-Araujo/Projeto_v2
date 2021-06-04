#include "../include/Persistencia.h"


using namespace std;
Persistencia::Persistencia()
{
    filesystem::create_directory("database");
    criar_estoques();
}

Persistencia::~Persistencia()
{
    //dtor
}

void Persistencia::criar_estoques() {
    if (!filesystem::exists(VACINA_ENDERECO)) {
        ofstream createfile(VACINA_ENDERECO);
        createfile.close();
        add_header_to_file(vacina_header, VACINA_ENDERECO);
    }
    if (!filesystem::exists(MEDICAMENTO_ENDERECO)) {
        ofstream createfile(MEDICAMENTO_ENDERECO);
        createfile.close();
        add_header_to_file(medicamento_header, MEDICAMENTO_ENDERECO);
    }
    if (!filesystem::exists(EPI_ENDERECO)) {
        ofstream createfile(EPI_ENDERECO);
        createfile.close();
        add_header_to_file(epi_header, EPI_ENDERECO);
    }
}


void Persistencia::add_header_to_file(string a_header, string endereco) {
    /**
     * Os itens do header devem ser separados por virgula, e no final deve ter um \n.
     *
     * Primeiro verifica se o arquivo existe.
     * Se n�o existir, exibi mensagem de erro.
     * Se existir adiciona o header no arquivo.
     **/

    fstream file(endereco);

    if (file.fail()) {
        cout << "Arquivo nao existe." << endl;
    }
    else {
        file << a_header;
    }
    file.close();
}


void Persistencia::Salvar_Insumos(std::vector<Insumos*> ins)
{
    ofstream vacina_database, medicamento_database, epi_database;
    vacina_database.open(VACINA_ENDERECO, fstream::app);
    medicamento_database.open(MEDICAMENTO_ENDERECO, fstream::app);
    epi_database.open(EPI_ENDERECO, fstream::app);

    if (vacina_database.fail() || medicamento_database.fail() || epi_database.fail()) {
        cout << "não foi possível abrir um dos arquivos." << endl;
        return;
    }

    vacina_database.clear();
    medicamento_database.clear();
    epi_database.clear();

    for (auto &item: ins) {
        if (item->get_tipo() == "vacina") {
            vacina_database << item->para_string();
        }
        else if (item->get_tipo() == "medicamento") {
            medicamento_database << item->para_string();
        }
        else if (item->get_tipo() == "epi") {
            epi_database << item->para_string();
        }
    }

    vacina_database.close();
    medicamento_database.close();
    epi_database.close();
}
