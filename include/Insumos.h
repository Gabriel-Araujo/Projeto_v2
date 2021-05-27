#ifndef INSUMOS_H
#define INSUMOS_H
#include <string>

class Insumos
{
    public:
        Insumos();
        virtual ~Insumos();

<<<<<<< HEAD
        std::string getNome();
        int get_quantidade();
        int get_valor();
        std::string getTipoInsumo();
        std::string getCodigoUnico();
        std::string getnome_fab();
=======
        std::string getTipoInsumo();
        std::string getCodigoUnico();
        std::string getNome();
        std::string get_tipo();
        std::string get_vencimento();
        std::string get_fabricante();
        int get_valor();
        virtual int get_quantidade();



>>>>>>> d2a1bd5d650c003d404bf9697d01d82bb13fdb65

        void DescontaQuantidade(int quant);
        void acrescentar_quantidade(int quantidade);

        void setQuantidade(int quant);
<<<<<<< HEAD

        //virtual void get_exclusivo();

=======
        void set_local(std::string estado);
>>>>>>> d2a1bd5d650c003d404bf9697d01d82bb13fdb65
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
