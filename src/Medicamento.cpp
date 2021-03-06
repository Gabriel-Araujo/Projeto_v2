#include "../include/Medicamento.h"


Medicamento::~Medicamento()
{
    //dtor
}


Medicamento::Medicamento()
{
    tipoInsumo = "medicamento";

    dosagem = "NULL";
    administracao = "NULL";
    disposicao = "NULL";
}

Medicamento::Medicamento(std::string nome, int quantidade, int valor_unitario, std::string vencimento, std::string fabricante,
               std::string local, std::string codigo_unico, std::string dsg, std::string adm, std::string disp): Insumos() {
    set_nome(nome);
    set_quantidade(quantidade);
    set_valor_unitario(valor_unitario);
    set_vencimento(vencimento);
    set_fabricante(fabricante);
    set_local(local);
    set_codigo(codigo_unico);
    set_dosagem(dsg);
    set_administracao(adm);
    set_disposicao(disp);
    tipoInsumo = "medicamento";
}

void Medicamento::set_nome(std::string nome)
{
    this->nome = nome;
}

void Medicamento::set_quantidade(int quantidade)
{
    if (quantidade < 0) {
        this->quantidade = 0;
    }
    else {
        this->quantidade = quantidade;
    }
}

void Medicamento::set_valor_unitario(int valor_unitario)
{
    if (valor_unitario < 0) {
        this->valor_unitario = 1;
    }
    else {
        this->valor_unitario = valor_unitario;
    }
}

void Medicamento::set_vencimento(std::string data_vencimento)
{
    this->data_vencimento = data_vencimento;
}

void Medicamento::set_fabricante(std::string nome_fab)
{
    this->nome_fab = nome_fab;
}


void Medicamento::set_codigo(std::string codigo_unico)
{
    this->codigo_unico = codigo_unico;
}

void Medicamento::set_dosagem(std::string dosagem)
{
    this->dosagem = dosagem;
}

void Medicamento::set_administracao(std::string administracao)
{
    this->administracao = administracao;
}

void Medicamento::set_disposicao(std::string disposicao)
{
    this->disposicao = disposicao;
}


std::string Medicamento::get_dosagem() {
    return dosagem;
}


std::string Medicamento::get_administracao() {
    return administracao;
}


std::string Medicamento::get_disposicao() {
    return disposicao;
}

void Medicamento::get_especifico(std::ofstream &fp)
{
     fp << ", " << dosagem << ", " <<  administracao <<", " << disposicao << std::endl;
}

void Medicamento::exibir() {
    Menu::exibir_medicamento(this->codigo_unico, this->nome, this->quantidade, this->valor_unitario, this->data_vencimento, this->nome_fab, this->dosagem, this->administracao, this->disposicao);

}


std::string Medicamento::para_string() {
    std::string saida;

    saida.append( codigo_unico + ", ");
    saida.append(nome + ", ");
    saida.append(std::to_string(valor_unitario) + ", ");
    saida.append(std::to_string(quantidade) + ", ");
    saida.append(data_vencimento + ", ");
    saida.append(nome_fab + ", ");
    saida.append(tipoInsumo + ", ");
    saida.append(local + ", ");

    saida.append(dosagem + ", ");
    saida.append(administracao + ", ");
    saida.append(disposicao + "\n");

    return saida;
}