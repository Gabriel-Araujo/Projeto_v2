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
        std::string tp_vac;
        int qnt_doses;
        int intervalo;//intervalo entre as doses

};

#endif // VACINA_H
