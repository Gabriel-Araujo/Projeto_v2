#ifndef MEDICAMENTO_H
#define MEDICAMENTO_H
#include "Insumos.h"

class Medicamento : public Insumos
{
    public:
        Medicamento();
        virtual ~Medicamento();
        Medicamento(std::string nome, int quantidade, int valor_unitario, std::string vencimento, std::string fabricante,
               std::string local, std::string codigo_unico, std::string dsg, std::string adm, std::string disp);

    protected:

    private:
        void set_nome(std::string n);
        void set_quantidade(int q);
        void set_valor_unitario(int q);
        void set_vencimento(std::string data);
        void set_fabricante(std::string fab);
        void set_local(std::string l);
        void set_codigo(std::string unico);
        void set_dosagem(std::string dsg);
        void set_administracao(std::string adm);
        void set_disposicao(std::string disp);

        std::string dosagem;
        std::string administracao; // forma de adm da vacina(aplicacao no braço, oral, essas coisas)
        std::string disposicao; //Se é liquida, ou e uma capsula, ou sla, tem q ser dissolvida na agua(igual aqle remedio pra azia)

};

#endif // MEDICAMENTO_H
