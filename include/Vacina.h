#ifndef VACINA_H
#define VACINA_H
#include "Insumos.h"

class Vacina : public Insumos
{
    private:
        std::string tipo_vac;
        int quantidade_doses;
        int intervalo;

        void set_nome(std::string n);
        void set_quantidade(int q);
        void set_valor_unitario(int q);
        void set_vencimento(std::string data);
        void set_fabricante(std::string fab);
        void set_local(std::string l);
        void set_codigo(std::string unico);
        void set_tipo_vac(std::string t);
        void set_quant_doses(int qd);
        void set_intervalo(int it);



    protected:


    public:
        Vacina();
        Vacina(std::string nome, int quantidade, int valor_unitario, std::string vencimento, std::string fabricante,
               std::string local, std::string codigo_unico, std::string tipo_vac, int quant_doses, int intervalo);
               std::string get_nome();

        int get_quantidade();
        int set_valor_unitario();
        std::string get_vencimento();
        std::string get_fabricante();
        std::string get_local();
        std::string get_codigo();
        std::string get_tipo_vac();
        std::string get_quant_doses();
        std::string get_intervalo();

        virtual ~Vacina();



};

#endif // VACINA_H
