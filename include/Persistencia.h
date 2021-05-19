#ifndef PERSISTENCIA_H
#define PERSISTENCIA_H
#include "Controlador.h"

class Persistencia
{
    public:
        Persistencia();
        virtual ~Persistencia();
        void _create_empty_csv(std::string file_name);
        void _add_header_to_file(std::string a_header, std::string file_name);
        int _find_row(std::string word, std::string file_name);
        //void _criar_diretorios();
        void _criar_estoque(std::string nome_do_arquivo, int tipo);                                                                             // CREATE


        // Fun��es que podem ser usadas pelo programador:
        void criar_estoques();
        void show_file(std::string file_name);                                                                                       // READ
        std::string read_a_line_of_the_file(std::string name, std::string file_name);                                                          // READ
        void adicionar_item_ao_estoque(std::string item, std::string file_name);                                                          // UPDATE
        void atualizar_item_do_estoque(std::string atualizacao, std::string codigo_do_produto, std::string file_name);                         // UPDATE
        void deletar_item_do_estoque(std::string codigo_do_produto, std::string file_name);
        //std::string t_vac_para_string(t_insumos vacina);
        //t_insumos string_para_t_insumo(const string item, const int tipo_do_insumo);


    protected:

    private:
};

#endif // PERSISTENCIA_H
