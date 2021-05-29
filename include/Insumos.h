#ifndef INSUMOS_H
#define INSUMOS_H
#include <string>
#include <algorithm>

class Insumos
{
    public:
        Insumos();
        virtual ~Insumos();


        std::string getNome();

        int get_valor();

        std::string getCodigoUnico();
        std::string getnome_fab();

        std::string getTipoInsumo();


        std::string get_tipo();
        std::string get_vencimento();
        std::string get_fabricante();
        std::string get_local();

        virtual int get_quantidade();





        void DescontaQuantidade(int quant);
        void acrescentar_quantidade(int quantidade);

        void setQuantidade(int quant);

        //virtual void get_exclusivo();


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
