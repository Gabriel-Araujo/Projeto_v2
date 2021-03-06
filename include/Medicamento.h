#ifndef MEDICAMENTO_H
#define MEDICAMENTO_H
#include "Insumos.h"
#include <fstream>

class Medicamento : public Insumos
{
    public:
        Medicamento();
        virtual ~Medicamento();
        Medicamento(std::string nome, int quantidade, int valor_unitario, std::string vencimento, std::string fabricante,
               std::string local, std::string codigo_unico, std::string dsg, std::string adm, std::string disp);


        virtual void get_especifico(std::ofstream &fp);
        virtual std::string para_string();

        std::string get_dosagem();
        std::string get_administracao();
        std::string get_disposicao();

        void exibir() override;

    protected:

    private:
        void set_nome(std::string n);
        void set_quantidade(int q);
        void set_valor_unitario(int q);
        void set_vencimento(std::string data);
        void set_fabricante(std::string fab);
        void set_codigo(std::string unico);
        void set_dosagem(std::string dsg);
        void set_administracao(std::string adm);
        void set_disposicao(std::string disp);

        std::string dosagem;
        std::string administracao; // forma de adm da vacina(aplicacao no bra?o, oral, essas coisas)
        std::string disposicao; //Se ? liquida, ou e uma capsula, ou sla, tem q ser dissolvida na agua(igual aqle remedio pra azia)

};

#endif // MEDICAMENTO_H
