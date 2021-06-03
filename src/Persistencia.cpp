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
/*
void criar_estoques() {
    _criar_estoque(".\\database\\vacina_MIN", 1);
    _criar_estoque(".\\database\\medicamento_MIN", 2);
    _criar_estoque(".\\database\\EPI_MIN", 3);
    _criar_estoque(".\\database\\vacina_AC", 1);
    _criar_estoque(".\\database\\medicamento_AC", 2);
    _criar_estoque(".\\database\\EPI_AC", 3);
    _criar_estoque(".\\database\\vacina_AL", 1);
    _criar_estoque(".\\database\\medicamento_AL", 2);
    _criar_estoque(".\\database\\EPI_AL", 3);
    _criar_estoque(".\\database\\vacina_AP", 1);
    _criar_estoque(".\\database\\medicamento_AP", 2);
    _criar_estoque(".\\database\\EPI_AP", 3);
    _criar_estoque(".\\database\\vacina_AM", 1);
    _criar_estoque(".\\database\\medicamento_AM", 2);
    _criar_estoque(".\\database\\EPI_AM", 3);
    _criar_estoque(".\\database\\vacina_BA", 1);
    _criar_estoque(".\\database\\medicamento_BA", 2);
    _criar_estoque(".\\database\\EPI_BA", 3);
    _criar_estoque(".\\database\\vacina_CE", 1);
    _criar_estoque(".\\database\\medicamento_CE", 2);
    _criar_estoque(".\\database\\EPI_CE", 3);
    _criar_estoque(".\\database\\vacina_ES", 1);
    _criar_estoque(".\\database\\medicamento_ES", 2);
    _criar_estoque(".\\database\\EPI_ES", 3);
    _criar_estoque(".\\database\\vacina_GO", 1);
    _criar_estoque(".\\database\\medicamento_GO", 2);
    _criar_estoque(".\\database\\EPI_GO", 3);
    _criar_estoque(".\\database\\vacina_MA", 1);
    _criar_estoque(".\\database\\medicamento_MA", 2);
    _criar_estoque(".\\database\\EPI_MA", 3);
    _criar_estoque(".\\database\\vacina_MT", 1);
    _criar_estoque(".\\database\\medicamento_MT", 2);
    _criar_estoque(".\\database\\EPI_MT", 3);
    _criar_estoque(".\\database\\vacina_MS", 1);
    _criar_estoque(".\\database\\medicamento_MS", 2);
    _criar_estoque(".\\database\\EPI_MS", 3);
    _criar_estoque(".\\database\\vacina_MG", 1);
    _criar_estoque(".\\database\\medicamento_MG", 2);
    _criar_estoque(".\\database\\EPI_MG", 3);
    _criar_estoque(".\\database\\vacina_PA", 1);
    _criar_estoque(".\\database\\medicamento_PA", 2);
    _criar_estoque(".\\database\\EPI_PA", 3);
    _criar_estoque(".\\database\\vacina_PB", 1);
    _criar_estoque(".\\database\\medicamento_PB", 2);
    _criar_estoque(".\\database\\EPI_PB", 3);
    _criar_estoque(".\\database\\vacina_PR", 1);
    _criar_estoque(".\\database\\medicamento_PR", 2);
    _criar_estoque(".\\database\\EPI_PR", 3);
    _criar_estoque(".\\database\\vacina_PE", 1);
    _criar_estoque(".\\database\\medicamento_PE", 2);
    _criar_estoque(".\\database\\EPI_PE", 3);
    _criar_estoque(".\\database\\vacina_PI", 1);
    _criar_estoque(".\\database\\medicamento_PI", 2);
    _criar_estoque(".\\database\\EPI_PI", 3);
    _criar_estoque(".\\database\\vacina_RJ", 1);
    _criar_estoque(".\\database\\medicamento_RJ", 2);
    _criar_estoque(".\\database\\EPI_RJ", 3);
    _criar_estoque(".\\database\\vacina_RN", 1);
    _criar_estoque(".\\database\\medicamento_RN", 2);
    _criar_estoque(".\\database\\EPI_RN", 3);
    _criar_estoque(".\\database\\vacina_RS", 1);
    _criar_estoque(".\\database\\medicamento_RS", 2);
    _criar_estoque(".\\database\\EPI_RS", 3);
    _criar_estoque(".\\database\\vacina_RO", 1);
    _criar_estoque(".\\database\\medicamento_RO", 2);
    _criar_estoque(".\\database\\EPI_RO", 3);
    _criar_estoque(".\\database\\vacina_RR", 1);
    _criar_estoque(".\\database\\medicamento_RR", 2);
    _criar_estoque(".\\database\\EPI_RR", 3);
    _criar_estoque(".\\database\\vacina_SC", 1);
    _criar_estoque(".\\database\\medicamento_SC", 2);
    _criar_estoque(".\\database\\EPI_SC", 3);
    _criar_estoque(".\\database\\vacina_SP", 1);
    _criar_estoque(".\\database\\medicamento_SP" ,2);
    _criar_estoque(".\\database\\EPI_SP", 3);
    _criar_estoque(".\\database\\vacina_SE", 1);
    _criar_estoque(".\\database\\medicamento_SE", 2);
    _criar_estoque(".\\database\\EPI_SE", 3);
    _criar_estoque(".\\database\\vacina_TO", 1);
    _criar_estoque(".\\database\\medicamento_TO", 2);
    _criar_estoque(".\\database\\EPI_TO", 3);
    _criar_estoque(".\\database\\vacina_DF", 1);
    _criar_estoque(".\\database\\medicamento_DF", 2);
    _criar_estoque(".\\database\\EPI_DF", 3);
}
*/

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
     * O nome do arquivo deve ser passado sem .csv.
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

void Persistencia::Salvar_Insumos(std::vector<Insumos*> ins, std::string local)
{
    ofstream fp;
    string filename;

    for(auto *item : ins){
        if(item->getTipoInsumo() == "vacina"){
            filename = "database/vacina_" + local + ".csv";
            fp.open(filename, fstream::out);

        }else if(item->getTipoInsumo() == "medicamento"){
            filename = "database/medicamento_" + local + ".csv";
            fp.open(filename, fstream::out);

        }else{
            filename = "database/EPI_" + local + ".csv";
            fp.open(filename, fstream::out);
        }
    }

    if(fp.is_open()){
        for(auto *item : ins){
            if(item->getTipoInsumo() == "vacina"){
                fp << vacina_header;
                fp << item->getCodigoUnico() << ", " << item->getNome() << ", " << item->get_valor() << ", " << item->get_quantidade() <<
                        ", " << item->get_vencimento() << ", " << item->getnome_fab() << ", " << item->get_tipo() << ", " << item->get_local();
                 Vacina *v = (Vacina *) item;
                 v->get_especifico(fp);

            }
        }
    }

    fp.close();
}
