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
        void set_condigo(std::string unico);



    protected:


    public:
        Vacina();
        virtual ~Vacina();



};

#endif // VACINA_H
