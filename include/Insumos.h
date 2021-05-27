#ifndef INSUMOS_H
#define INSUMOS_H
#include <string>

class Insumos
{
    public:
        Insumos();
        virtual ~Insumos();

        std::string getNome();
        int get_quantidade();
        int get_valor();
        std::string getTipoInsumo();
        std::string getCodigoUnico();
        std::string getnome_fab();

        void DescontaQuantidade(int quant);

        void setQuantidade(int quant);

        //virtual void get_exclusivo();

    protected:

        std::string nome;
        int quantidade;
        int valor_unitario;
        std::string data_vencimento;
        std::string nome_fab;
        std::string tipoInsumo;
        std::string local;
        std::string codigo_unico;


    private:

};

#endif // INSUMOS_H
