#ifndef INSUMOS_H
#define INSUMOS_H
#include <string>

class Insumos
{
    public:
        Insumos();
        virtual void get_insumo_infos() = 0;
        virtual ~Insumos();

    protected:

        std::string nome;
        float valor;
        int qnt_itens;
        std::string d_vencimento;
        std::string nome_fab;
        std::string tipoInsumo;
        std::string local;
        int codigo_unico;


    private:

};

#endif // INSUMOS_H
