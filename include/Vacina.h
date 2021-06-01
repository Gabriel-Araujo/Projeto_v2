#ifndef VACINA_H
#define VACINA_H
#include "Insumos.h"

class Vacina : public Insumos
{
    private:
        std::string tipo_vac;
        int quantidade_doses;
        int intervalo;

        void set_nome(std::string n);
        void set_quantidade(int q);
        void set_valor_unitario(int q);
        void set_vencimento(std::string data);
        void set_fabricante(std::string fab);
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


        std::string get_tipo_vac();
        int get_quant_doses();
        int get_intervalo();

        //void get_exclusivo();
        void exibir() override;




};

#endif // VACINA_H
