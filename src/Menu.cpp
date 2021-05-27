#include "../include/Menu.h"

Menu::Menu()
{
    //ctor
}

using namespace std;

void Menu::Boas_vindas(){
    std::system(CLEAR_DEFINE);
    printf("----------------------------------------------------------------------------------\n");
    printf("\t\t Boas vindas ao sistema de vacinacao\n");
    printf("-----------------------------------------------------------------------------------\n");
    printf("\n Aqui voce podera cadastrar e consultar as informacoes acerca das vacinas, medicamentos e EPI\n");
    printf("-----------------------------------------------------------------------------------\n");
    printf("\t Digite 1 para cadastrar os insumos\n\n");
    printf("\t Digite 2 para distribuir os insumos disponiveis no estoque para os Estados\n\n");
    printf("\t Digite 3 para consultar os insumos disponiveis nos estoques do MS\n\n");
    printf("\t Digite 4 para consultar os insumos distribuidos para os Estados\n\n");
    printf("Digite 0 para sair\n");
    printf("-----------------------------------------------------------------------------------\n");
    printf("Digita aqui sua escolha:");
}


void Menu::Cadastro(){
    std::system(CLEAR_DEFINE);
    printf("\n\n----------------------------------------------------------------------------------\n");
    printf("Como voce escolheu o item 1, qual tipo de insumo voce deseja cadastrar:\n\n");
    printf("----------------------------------------------------------------------------------\n");
    printf("Digite \"vacina\" caso queira cadastrar vacinas\n");
    printf("Digite \"medicamento\" caso queira cadastrar medicamentos\n");
    printf("Digite  \"EPI\" caso queira cadastrar EPIs\n");
    printf("Digite \"voltar\" para sair\n");
    printf("Digita aqui sua escolha:");

}


void Menu::Distribuir(){
    std::system(CLEAR_DEFINE);
    printf("\n\n----------------------------------------------------------------------------------\n");
    printf("Como voce escolheu o item 2, nos informe para qual Estado voce deseja distribuir:\n\n");
    printf("----------------------------------------------------------------------------------\n");
    printf("Digite 1 para confirmar a distribuicao para os Estados:\n");
    printf("Caso nao queira distribuir mais para nehum Estado, digite 0:\n");


}


void Menu::Distribuir_submenu_1(){
    printf("\n\n----------------------------------------------------------------------------------\n");
    printf("Como voce escolheu o item 1, qual tipo de insumo voce deseja distribuir para o Estado:\n\n");
    printf("----------------------------------------------------------------------------------\n");
    printf("Digite \"vacina\" caso queira distribuir vacinas\n");
    printf("Digite \"medicamento\" caso queira distribuir medicamentos\n");
    printf("Digite  \"EPI\" caso queira distribuir EPIs\n");
    printf("Digite \"voltar\" para sair\n");
    printf("Digita aqui sua escolha:");

}

void Menu::Distribuir_submenu_2(){
    printf("\n\n----------------------------------------------------------------------------------\n");
    printf("Informe-nos o codigo do produto desejado a distribuicao: ");
    printf("----------------------------------------------------------------------------------\n");
    printf("Digite \"voltar\" para sair\n");

}

void Menu::Distribuir_submenu_3(){
    printf("\n\n----------------------------------------------------------------------------------\n");
    printf("Informe-nos a quantidade do produto desejado a distribuicao: ");
    printf("----------------------------------------------------------------------------------\n");
    printf("Digite \"voltar\" para sair\n");

}

void Menu::ConsultarMs(){
    printf("\n\n----------------------------------------------------------------------------------\n");
    printf("Como voce escolheu o item 3, nos diga como voce quer receber a informacao:\n\n");
    printf("----------------------------------------------------------------------------------\n");
    printf("Digite 1 caso queira receber a quantidade de itens disponiveis em estoque do MS no geral\n");
    printf("Digite 2 caso queira receber a descricao e quantidade dos itens disponiveis em estoque do MS\n");
    printf("Digite 3 caso queira receber tanto a descricao, quantidade e informacoes exclusivas do tipo de insumo disponivel no estoque do MS\n");
    printf("Digite 0 para sair\n");
    printf("Digita aqui sua escolha:");

}

//funcao caso o usuario escolher a opcao 3, escolha novamente a opcao 3, coloca dentro da funcao de insumos disponiveis se a funcao for necessaria
void Menu::Consultar_submenu_3(){
    printf("\n\n----------------------------------------------------------------------------------\n");
    printf("Como voce escolheu o item 3, nos diga como voce quer receber a informa��o:\n\n");
    printf("\n\n----------------------------------------------------------------------------------\n");
    printf("Digite 1 caso queira receber a descricao e quantidade das vacinas\n ");
    printf("Digite 2 caso queira receber a descricao e quantidade dos medicamentos\n ");
    printf("Digite 3 caso queira receber a descricao e quantidade das EPIs\n ");
    printf("----------------------------------------------------------------------------------\n");
    printf("Digite 0 para sair\n");
    printf("Digita aqui sua escolha:");
}


void Menu::Unidades_distribuidas(){
    printf("\n\n----------------------------------------------------------------------------------\n");
    printf("Como voce escolheu o item 4, nos diga como voce quer receber a informação:\n\n");
    printf("----------------------------------------------------------------------------------\n");
    printf("Digite 1 caso queira receber a quantidade de itens distribuidos para os Estados no geral\n");
    printf("Digite 2 caso queira receber a descricao dos itens distribuidos para os Estados\n");
    printf("Digite 3 caso queira receber tanto a descricao e quantidade do tipo de insumo distribuido\n");
    printf("Digite 0 para sair\n");
    printf("Digita aqui sua escolha:");


}
//funcao caso o usuario escolher a opcao 4, escolha a opcao 3, coloca dentro da funcao de insumos distribuidos se a funcao for necessaria
void Menu::Unidades_distribuidas_submenu_3(){
    printf("\n\n----------------------------------------------------------------------------------\n");
    printf("Como voce escolheu o item 3, nos diga como voce quer receber a informação:\n\n");
    printf("\n\n----------------------------------------------------------------------------------\n");
    printf("Digite 1 caso queira receber a descricao e quantidade das vacinas\n ");
    printf("Digite 2 caso queira receber a descricao e quantidade dos medicamentos\n ");
    printf("Digite 3 caso queira receber a descricao e quantidade das EPIs\n ");
    printf("----------------------------------------------------------------------------------\n");
    printf("Digite 0 para sair\n");
    printf("Digita aqui sua escolha:");

}


void Menu::exibir_estados() {
    cout << "| AC - Acre      | AL - Alagoas        | AP - Amapá               | AM - Amazonas          |\n";
    cout << "| BA - Bahia     | CE - Ceará          | ES - Espírito santo      | GO - Goiás             |\n";
    cout << "| MA - Maranhão  | MT - Mato Grosso    | MS - Mato Grosso do Sul  | MG - Minas Gerais      |\n";
    cout << "| PA - Pará      | PB - Paraíba        | PR - Paraná              | PE - Pernambuco        |\n";
    cout << "| PI - Piauí     | RJ - Rio de Janeiro | RN - Rio Grande do Norte | RS - Rio Grande do Sul |\n";
    cout << "| RO - Rondônia  | RR - Roraima        | SC - Santa Catarina      | SP - São Paulo         |\n";
    cout << "| SE - Sergipe   | TO - Tocantins      | DF - Distrito Federal    |                        |\n";
    cout << "Digite o Estado ou \"voltar\" para sair: ";

}

Menu::~Menu()
{
    //dtor
}

void Menu::exibir_quantidades(std::vector<Insumos*> &insumos)
{
    int soma = 0;
    cout << setfill(' ') << setw(15) << "QUANTIDADE" << setfill(' ') << setw(9) << "|" << endl;

    for(auto &insumo: insumos){
        soma += insumo->get_quantidade();
    }
    cout << "Quantidade Total de Insumos: " << soma << endl;

}

void Menu::exibir_formatado(std::vector<Insumos*> &insumos) {
    int index = 1;
    cout << " 0 |";
    cout << setfill(' ') << setw(15) << "CODIGO" << setfill(' ') << setw(10) << "|";
    cout << setfill(' ') << setw(15) << "NOME" << setfill(' ') << setw(10) << "|";
    cout << setfill(' ') << setw(15) << "PREÇO (R$)" << setfill(' ') << setw(10) << "|";
    cout << setfill(' ') << setw(15) << "TIPO" << setfill(' ') << setw(9) << "|";
    cout << setfill(' ') << setw(15) << "QUANTIDADE" << setfill(' ') << setw(9) << "|" << endl;


    for (auto &insumo: insumos) {
        cout << " " << index << " |";
        cout << setfill(' ') << setw(15) << insumo->getCodigoUnico() << setfill(' ') << setw(10) << "|";
        cout << setfill(' ') << setw(15) << insumo->getNome() << setfill(' ') << setw(10) << "|";
        cout << setfill(' ') << setw(15) << insumo->get_valor() << setfill(' ') << setw(9) << "|";
        cout << setfill(' ') << setw(15) << insumo->getTipoInsumo() << setfill(' ') << setw(9) << "|";
        cout << setfill(' ') << setw(15) << insumo->get_quantidade() << setfill(' ') << setw(9) << "|" << endl;
        index++;
    }
}


void Menu::exibir_vacina(Vacina &vacina) {

    cout << "\t\tInformações da vacina escolhida:" << endl;
    cout << "codigo do insumo: " << vacina.getCodigoUnico() << endl;
    cout << "nome da vacina: " << vacina.getNome() << endl;
    cout << "Preço: R$ " << vacina.get_valor() << endl;
    cout << "data de vencimento: " << vacina.get_vencimento() << endl;
    cout << "fabricante: " << vacina.get_fabricante() << endl;
    cout << "quantidade de doses: " << vacina.get_quant_doses() << endl;
    cout << "tempo entre doses: " << vacina.get_intervalo() << endl;
    cout << "tipo de tecnologia: " << vacina.get_tipo_vac() << endl;

}
