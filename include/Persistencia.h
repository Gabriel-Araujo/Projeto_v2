#ifndef PERSISTENCIA_H
#define PERSISTENCIA_H


#include "Local.h"
#include "Insumos.h"
#include "Vacina.h"
#include "Medicamento.h"
#include "EPI.h"


#include <filesystem>
#include <fstream>
#include <vector>



class Persistencia
{
    public:
        Persistencia();
        virtual ~Persistencia();
        // IMPLEMENTADOS
        void add_header_to_file(std::string a_header, std::string endereco);
        void criar_estoques();
        void Salvar_Insumos(std::vector<Insumos*> insumos);

        // NÂO IMPLEMENTADOS
        int _find_row(std::string word, std::string file_name);                                                                           // CREATE
        //void show_file(std::string file_name);                                                                                       // READ
        std::string read_a_line_of_the_file(std::string name, std::string file_name);                                                          // READ
        void adicionar_item_ao_estoque(std::string item, std::string file_name);                                                          // UPDATE
        void atualizar_item_do_estoque(std::string atualizacao, std::string codigo_do_produto, std::string file_name);                         // UPDATE
        void deletar_item_do_estoque(std::string codigo_do_produto, std::string file_name);


    protected:

    private:

        std::string vacina_header = "codigo, nome, preço unitário, quantidade, vencimento, fabricante, tipo, local, tipo da vacina, doses, tempo entre doses\n";
        std::string medicamento_header = "codigo, nome, preço unitário, quantidade, vencimento, fabricante, tipo, local, dosagem, administração, disposição\n";
        std::string epi_header = "codigo, nome, preço unitário, quantidade, vencimento, fabricante, tipo, local, tipo do EPI, informações\n";

        std::string VACINA_ENDERECO = "database/vacinas.csv";
        std::string MEDICAMENTO_ENDERECO = "database/medicamentos.csv";
        std::string EPI_ENDERECO = "database/epis.csv";

        bool estoques_existem();
};



#endif // PERSISTENCIA_H
