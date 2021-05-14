#include "Menu.h"

Menu::Menu()
{
    //ctor
}


//funcao de inicio do programa para apresentação
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
    printf("\t Digite 5 para consultar os insumos distribuidos por Estado\n\n");// esse aqui eh mais especifico entao acho q cabe deixar ele
    printf("Digite 0 para sair\n");
    printf("-----------------------------------------------------------------------------------\n");
}


void Menu::Escolhaum(){

    printf("\n\n----------------------------------------------------------------------------------\n");
    printf("Como voce escolheu o item 1, qual tipo de insumo voce deseja cadastrar:\n\n");
    printf("----------------------------------------------------------------------------------\n");
    printf("Digite 1 caso queira cadastrar vacinas\n");
    printf("Digite 2 caso queira cadastrar medicamentos\n");
    printf("Digite 3 caso queira cadastrar EPIs\n");
    printf("Digite 0 para sair\n");
    printf("Digita aqui sua escolha:");

}


void Menu::Escolhadois(){

    printf("\n\n----------------------------------------------------------------------------------\n");
    printf("Como voce escolheu o item 2, nos informe para qual voce deseja destribuir:\n\n");
    printf("----------------------------------------------------------------------------------\n");
    printf("Digite 1 para cadastrar a distribuicao para os Estados:\n");
    printf("Caso nao queira distribuir mais para nehum Estado, digite 0:\n");


}


void Menu::subEscolhadois(){

    printf("\n\n----------------------------------------------------------------------------------\n");
    printf("Como voce escolheu o item 1, qual tipo de insumo voce deseja destribuir para o Estado:\n\n");
    printf("----------------------------------------------------------------------------------\n");
    printf("Digite 1 caso queira distribuir vacinas\n");
    printf("Digite 2 caso queira distribuir medicamentos\n");
    printf("Digite 3 caso queira distribuir EPIs\n");
    printf("Digite 0 para sair\n");
    printf("Digita aqui sua escolha:");

}
//funcao caso o usuario escolha o item 3 da funcao acima
void Menu::Escolhatres(){

    printf("\n\n----------------------------------------------------------------------------------\n");
    printf("Como voce escolheu o item 3, nos diga como voce quer receber a informação:\n\n");
    printf("----------------------------------------------------------------------------------\n");
    printf("Digite 1 caso queira receber a quantidade de itens disponiveis em estoque no geral\n");
    printf("Digite 2 caso queira receber a descricao dos itens disponiveis em estoque\n");
    printf("Digite 3 caso queira receber tanto a descricao e quantidade do tipo de insumo disponivel\n");
    printf("Digite 0 para sair\n");
    printf("Digita aqui sua escolha:");

}

//funcao caso o usuario escolher a opcao 3, escolha novamente a opcao 3, coloca dentro da funcao de insumos disponiveis se a funcao for necessaria
void Menu::subEscolhatres(){

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

//funcao caso o usario escolha o item 4
void Menu::Escolhaquatro(){

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
void Menu::subEscolhaquatro(){

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

void Menu::Escolhacinco()
{
    printf("\n\n----------------------------------------------------------------------------------\n");
    printf("Como voce escolheu o item 5, informe qual Unidade Federativa voce deseja obter as informacoes\n");
    printf("\n----------------------------------------------------------------------------------\n");
    printf("Digite 1 e logo em seguida informe a unidade federativa: \n");
    printf("Digite 0 para sair\n");
    printf("----------------------------------------------------------------------------------\n");
    printf("Digita aqui sua escolha:");

}

Menu::~Menu()
{
    //dtor
}
