#ifndef EPI_H
#define EPI_H
#include "Insumos.h"

class EPI : public Insumos
{
    public:
        EPI();
        virtual ~EPI();

    protected:

    private:
        std::string tipo_epi;
        std::string descricao;
};

#endif // EPI_H
