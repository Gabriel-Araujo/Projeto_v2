#ifndef INSUMOS_H
#define INSUMOS_H
#include <string>
#include <algorithm>

class Insumos
{
    public:
        Insumos();
        virtual ~Insumos();

        std::string getTipoInsumo();
        std::string getCodigoUnico();
        std::string getNome();
        std::string get_tipo();
        std::string get_vencimento();
        std::string get_fabricante();
        std::string get_local();
        int get_valor();
        int get_quantidade();




        void DescontaQuantidade(int quant);
        void acrescentar_quantidade(int quantidade);

        void setQuantidade(int quant);
        void set_local(std::string estado);
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
