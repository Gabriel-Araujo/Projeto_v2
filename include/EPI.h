#ifndef EPI_H
#define EPI_H
#include "Insumos.h"

class EPI : public Insumos
{
    public:
        EPI();
        virtual ~EPI();
         EPI(std::string nome, int quantidade, int valor_unitario, std::string vencimento, std::string fabricante,
               std::string local, std::string codigo_unico, std::string tipo_epi, std::string descricao);


        int get_quantidade()override;

        std::string get_tipo_epi();
        std::string get_descricao();


    protected:

    private:
        void set_nome(std::string n);
        void set_quantidade(int q);
        void set_valor_unitario(int q);
        void set_vencimento(std::string data);
        void set_fabricante(std::string fab);
        void set_codigo(std::string unico);
        void set_tipo_epi(std::string tp);
        void set_descricao(std::string desc);

        std::string tipo_epi;
        std::string descricao;
};

#endif // EPI_H
