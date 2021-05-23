#include "../include/Menu.h"

Menu::Menu()
{
    //ctor
}

using namespace std;

void Menu::Boas_vindas(){

    printf("----------------------------------------------------------------------------------\n");
    printf("\t\t Boas vindas ao sistema de vacinacao\n");
    printf("-----------------------------------------------------------------------------------\n");
    printf("\n Aqui voce podera cadastrar e consultar as informacoes acerca das vacinas, medicamentos e EPI\n");
    printf("-----------------------------------------------------------------------------------\n");
    printf("\t Digite 1 para cadastrar os insumos\n\n");
    printf("\t Digite 2 para distribuir os insumos disponiveis no estoque\n\n");
    printf("\t Digite 3 para consultar os insumos disponiveis nos estoques\n\n");
    printf("\t Digite 4 para saber quantas unidades foram destribuidas para os Estados\n\n");
    printf("\t Digite 5 para consultar os insumos distribuidos por Estado\n\n");
    printf("Digite 0 para sair\n");
    printf("-----------------------------------------------------------------------------------\n");
}


void Menu::Cadastro(){

    printf("\n\n----------------------------------------------------------------------------------\n");
    printf("Como voce escolheu o item 1, qual tipo de insumo voce deseja cadastrar:\n\n");
    printf("----------------------------------------------------------------------------------\n");
    printf("Digite 1 caso queira cadastrar vacinas\n");
    printf("Digite 2 caso queira cadastrar medicamentos\n");
    printf("Digite 3 caso queira cadastrar EPIs\n");
    printf("Digite 0 para sair\n");
    printf("Digita aqui sua escolha:");

}


void Menu::Distribuir(){

    printf("\n\n----------------------------------------------------------------------------------\n");
    printf("Como voce escolheu o item 2, nos informe para qual voce deseja distribuir:\n\n");
    printf("----------------------------------------------------------------------------------\n");
    printf("Digite 1 para cadastrar a distribuicao para os Estados:\n");
    printf("Caso nao queira distribuir mais para nehum Estado, digite 0:\n");


}


void Menu::Distribuir_submenu_1(){

    printf("\n\n----------------------------------------------------------------------------------\n");
    printf("Como voce escolheu o item 1, qual tipo de insumo voce deseja distribuir para o Estado:\n\n");
    printf("----------------------------------------------------------------------------------\n");
    printf("Digite 1 caso queira distribuir vacinas\n");
    printf("Digite 2 caso queira distribuir medicamentos\n");
    printf("Digite 3 caso queira distribuir EPIs\n");
    printf("Digite 0 para sair\n");
    printf("Digita aqui sua escolha:");

}

void Menu::Consultar(){

    printf("\n\n----------------------------------------------------------------------------------\n");
    printf("Como voce escolheu o item 3, nos diga como voce quer receber a informa��o:\n\n");
    printf("----------------------------------------------------------------------------------\n");
    printf("Digite 1 caso queira receber a quantidade de itens disponiveis em estoque no geral\n");
    printf("Digite 2 caso queira receber a descricao dos itens disponiveis em estoque\n");
    printf("Digite 3 caso queira receber tanto a descricao e quantidade do tipo de insumo disponivel\n");
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

void Menu::Insumos_distribuidos()
{
    printf("\n\n----------------------------------------------------------------------------------\n");
    printf("Como voce escolheu o item 5, informe qual Unidade Federativa voce deseja obter as informacoes\n");
    printf("\n----------------------------------------------------------------------------------\n");
    printf("Digite 1 e logo em seguida informe a unidade federativa: \n");
    printf("Digite 0 para sair\n");
    printf("----------------------------------------------------------------------------------\n");
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
}

Menu::~Menu()
{
    //dtor
}


void Menu::exibir_formatado(std::vector<Insumos*> insumos) {
    int index = 1;
    cout << " 0 |";
    cout << setfill(' ') << setw(15) << "CODIGO" << setfill(' ') << setw(10) << "|";
    cout << setfill(' ') << setw(15) << "NOME" << setfill(' ') << setw(10) << "|";
    cout << setfill(' ') << setw(15) << "PREÇO (R$)" << setfill(' ') << setw(10) << "|";
    cout << setfill(' ') << setw(15) << "QUANTIDADE" << setfill(' ') << setw(9) << "|" << endl;


    for (auto insumo: insumos) {
        cout << " " << index << " |";
        cout << setfill(' ') << setw(15) << insumo->getCodigoUnico() << setfill(' ') << setw(10) << "|";
        cout << setfill(' ') << setw(15) << insumo->getNome() << setfill(' ') << setw(10) << "|";
        cout << setfill(' ') << setw(15) << insumo->get_valor() << setfill(' ') << setw(9) << "|";
        cout << setfill(' ') << setw(15) << insumo->get_quantidade() << setfill(' ') << setw(9) << "|" << endl;
        index++;
    }
}
