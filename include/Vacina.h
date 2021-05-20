#ifndef VACINA_H
#define VACINA_H
#include "Insumos.h"

class Vacina : public Insumos
{
    private:
        std::string tipo_vac;
        int quantidade_doses;
        int intervalo; //intervalo entre as doses

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
        virtual ~Vacina();



};

#endif // VACINA_H
