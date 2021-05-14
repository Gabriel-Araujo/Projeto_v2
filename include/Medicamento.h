#ifndef MEDICAMENTO_H
#define MEDICAMENTO_H
#include "Insumos.h"

class Medicamento : public Insumos
{
    public:
        Medicamento();
        virtual ~Medicamento();

    protected:

    private:
        std::string dosagem;
        std::string adm; // forma de adm da vacina(aplicacao no bra�o, oral, essas coisas)
        std::string disp; //Se � liquida, ou e uma capsula, ou sla, tem q ser dissolvida na agua(igual aqle remedio pra azia)

};

#endif // MEDICAMENTO_H
