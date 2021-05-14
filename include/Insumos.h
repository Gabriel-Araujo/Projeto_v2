#ifndef INSUMOS_H
#define INSUMOS_H
#include <string>

class Insumos
{
    public:
        Insumos();
        virtual ~Insumos();

    protected:

        std::string nome;
        float valor;
        int qnt_itens;
        std::string d_vencimento;
        std::string nome_fab;
        int tipoInsumo;

    private:

};

#endif // INSUMOS_H
