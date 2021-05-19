#ifndef VACINA_H
#define VACINA_H
#include "Insumos.h"

class Vacina : public Insumos
{
    public:
        Vacina();
        virtual ~Vacina();

    protected:

    private:
        std::string tipo_vac;
        int quantidade_doses;
        int intervalo; //intervalo entre as doses

};

#endif // VACINA_H
