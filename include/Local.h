#ifndef LOCAL_H
#define LOCAL_H
#include "Insumos.h"

class Local
{
    public:
        Local();
        virtual ~Local();

    protected:

    private:
        std::string nome;
        //int tipo;
        Insumos  insumos[100];
};

#endif // LOCAL_H
