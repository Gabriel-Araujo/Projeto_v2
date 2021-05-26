#ifndef INSUMOS_H
#define INSUMOS_H
#include <string>

class Insumos
{
    public:
        Insumos();
        virtual ~Insumos();

        std::string getTipoInsumo();
        std::string getCodigoUnico();


        std::string getNome();
        int get_valor();

        virtual int get_quantidade();
        std::string get_tipo();

        void DescontaQuantidade(int quant);
        void acrescentar_quantidade(int quantidade);

        void setQuantidade(int quant);
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
