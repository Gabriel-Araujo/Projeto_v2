#ifndef VACINA_H
#define VACINA_H
#include "Insumos.h"

class Vacina : public Insumos
{
    private:
        std::string tipo_vac;
        int quantidade_doses;
        int intervalo; //intervalo entre as doses


    protected:


    public:
        Vacina();
        virtual ~Vacina();



};

#endif // VACINA_H
