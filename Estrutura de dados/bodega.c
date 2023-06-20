#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct Empresa
struct empresa
{
    char nome[20];
    char cnpj[15];
};
typedef struct empresa Empresa;

// Struct Bebidas
struct bebidas
{
    int cod;       // codigo
    char nome[20]; // nome
    int vol;       // volume Ml
    float val;     // valor R$
    int qnt;       // quantidade un
    int alcoolica; // 0 false _ 1 true
    struct bebidas *prev, *next;
};
typedef struct bebidas Bebida;

// Struct Clientes
struct clientes
{
    int cod;       // codigo
    char nome[20]; // nome
    char cpf[12];  // cpf
    int idade;     // idade
    int fiado;     // 0 false _ 1 true
    struct clientes *prev, *next;
};
typedef struct clientes Cliente;

// lista de bebidas
struct listaBebidas
{
    Bebida *first;
    Bebida *last;
};
typedef struct listaBebidas ListaBebidas;

// lista de clientes
struct listaClientes
{
    Cliente *first;
    Cliente *last;
};
typedef struct listaClientes ListaClientes;

void cadastraBebida(ListaBebidas *lb)
{
    Bebida *bebida = (Bebida *)malloc(sizeof(Bebida));
    printf("\nCódigo da bebida: ");
    scanf("%d", &bebida->cod); // codigo
    printf("\nNome da bebida: ");
    scanf("%s", bebida->nome); // nome
    printf("\nVolume em ml: ");
    scanf("%d", &bebida->vol); // volume Ml
    printf("\nValor da bebida: ");
    scanf("%f", &bebida->val); // valor R$
    printf("\nQuantidade em estoque: ");
    scanf("%d", &bebida->qnt); // quantidade un
    printf("\nAlcoólica? (1-sim) (0-não): ");
    scanf("%d", &bebida->alcoolica); // 0 false _ 1 true
    bebida->next = NULL;

    Bebida *aux;

    for (aux = lb->first; aux != NULL; aux = aux->next)
    {
        if (aux->cod == bebida->cod)
        { // procurar se bebida já existe
            printf("\nCódigo da bebida já cadastrado!");
            return;
        }
    };
    if (lb->first == NULL)
    {
        lb->first = bebida;
        lb->last = bebida;
    }
    else
    {
        lb->last->next = bebida;
        bebida->prev = lb->last;
        lb->last = bebida;
    }
    printf("\nBebida Cadastrada!\n");
}
/*
Ao escolher a Opção Cadastrar bebida: Leia os dados da bebida a ser cadastrada via teclado,
na sequência atualiza a lista encadeada criada. É necessário verificar se o código da bebida já existe.
*/

void mostraBebidas(ListaBebidas *lb)
{
    Bebida *aux = lb->first;
    if (lb->first == NULL)
    {
        printf("Sem bebidas aqui\n");
        return;
    }
    printf("\nCadastro de Bebidas: \n");
    while (aux)
    {
        printf("-- Bebida: %d\n", aux->cod);
        printf("-- Nome: %s\n", aux->nome);
        printf("-- Volume(ml):  %d\n", aux->vol);
        printf("-- Valor: R$%.2f\n", aux->val);
        printf("-- Quantidade em estoque: %d\n", aux->qnt);
        printf("-- Alcoólica? (1-sim) (0-não): %d\n", aux->alcoolica);
        printf("\n-----------------------------\n\n");
        aux = aux->next;
    }
}

void compraBebida(ListaBebidas *lb)
{
    Bebida *bebida = (Bebida *)malloc(sizeof(Bebida));
    Bebida *aux;
    printf("\nInforme o código da bebida: ");
    scanf("%d", &bebida->cod); // codigo

    for (aux = lb->first; aux != NULL; aux = aux->next)
    {
        if (aux->cod == bebida->cod)
        { // procurar se bebida já existe
            printf("\nInforme a quantidade comprada: ");
            scanf("%d", &bebida->qnt);
            aux->qnt += bebida->qnt;
            printf("\nQuantidade atualizada, total: %d\n", aux->qnt);
            return;
        }
        else
        {
            printf("\nCódigo da bebida não encontrado!");
            return;
        }
    };
}
/*
Peça um código de bebida para compra e a quantidade de unidades a serem compradas.
A função compraBebida  recebe os dados e atualiza o estoque da bebida comprada ou avisa que o código da bebida não existe na lista.
*/

void vendeBebida(ListaBebidas *lb, ListaClientes *lc)
{
    Bebida *bebida = (Bebida *)malloc(sizeof(Bebida));
    Cliente *cliente = (Cliente *)malloc(sizeof(Cliente));
    Bebida *aux;
    Cliente *auxCli;
    printf("\nInforme o CPF do cliente: ");
    scanf("%s", cliente->cpf);

    for (auxCli = lc->first;auxCli != NULL; auxCli = auxCli->next)
    {
        if (strcmp(auxCli->cpf, cliente->cpf) == 0){
            break;
        }
    };
    if (auxCli == NULL)
    {
        printf("Cliente não cadastrado!");
        return;
    }
    printf("\nInforme o código da bebida: ");
    scanf("%d", &bebida->cod); // codigo

    for (aux = lb->first; aux != NULL; aux = aux->next)
    {
        if (aux->cod == bebida->cod)
        {
            
            if (aux->alcoolica == 1 && auxCli->idade < 18)
            {
                printf("cliente:  %s, Idade %d", auxCli->nome, auxCli->idade); // sempre menor?
                printf("\nProibida a venda de bebida alcoólica para menor de idade!\n");
                return;
            }
            printf("\nInforme a quantidade: ");
            scanf("%d", &bebida->qnt);
            if (bebida->qnt > aux->qnt)
            {
                printf("\nVenda maior que estoque! A quantidade atual é: %d", aux->qnt);
                return;
            }
            aux->qnt = aux->qnt - bebida->qnt;
            printf("\nVenda autorizada, valor total: %f\n", bebida->qnt * aux->val);
            printf("\nQuantidade atualizada, total: %d\n", aux->qnt);
            return;
        }
        else
        {
            printf("\nCódigo da bebida não encontrado!");
            return;
        }
    };
}
/*
Peça o CPF do cliente, um código de bebida para venda e a quantidade de unidades a serem vendidas. Deve ser chamada a função vendeBebida (passando os dados informados). Durante a venda de uma bebida é necessário verificar se a bebida está disponível no estoque. Além disso, para bebidas alcoólicas, verifique se o cliente é maior de idade.
*/

void cadastraCliente(ListaClientes *lc)
{
    Cliente *cliente = (Cliente *)malloc(sizeof(Cliente));
    printf("\nCódigo do cliente: ");
    scanf("%d", &cliente->cod); // codigo
    printf("\nNome do cliente: ");
    scanf("%s", cliente->nome); // nome
    printf("\nCPF do cliente: ");
    scanf("%s", cliente->cpf); // cpf
    printf("\nIdade do cliente: ");
    scanf("%d", &cliente->idade); // idade
    printf("\nFiado? (1-sim) (0-não): ");
    scanf("%d", &cliente->fiado); // 0 false _ 1 true

    Cliente *aux;

    for (aux = lc->first; aux != NULL; aux = aux->next)
    {
        if (aux->cod == cliente->cod || strcmp(aux->cpf, cliente->cpf) == 0)
        { // procurar se cliente já existe
            printf("\nCliente já cadastrado!");
            return;
        }
    };
    if (lc->first == NULL)
    {
        lc->first = cliente;
        lc->last = cliente;
    }
    else
    {
        for (aux = lc->first; cliente->idade < aux->idade && aux != NULL; aux = aux->next)
        {
            cliente->next = aux;
            cliente->prev = aux->prev;
            if (aux->prev != NULL){
                aux->prev->next = cliente;
            }else{
                lc->first = cliente;
            }
            aux->prev = cliente;
            printf("\nCliente Cadastrado!\n");
            return;
        }
        lc->last->next = cliente;
        cliente->prev = lc->last;
        lc->last = cliente;
        lc->last->next = NULL;
    }
    printf("\nCliente Cadastrado!\n");
}
/*
    Leia os dados via teclado e adicione na lista. A inserção deve ser feita na ordem da idade, ou seja,
    insira o cliente antes do elemento cuja a idade for maior que a do cliente sendo cadastrado.
*/

void mostraClientes(ListaClientes *lc)
{
    Cliente *aux = lc->first;
    if (lc->first == NULL)
    {
        printf("Sem cliente aqui\n");
        return;
    }
    printf("\nCadastro de Clientes: \n");
    while (aux)
    {
        printf("-- Cliente: %d\n", aux->cod);
        printf("-- Nome: %s\n", aux->nome);
        printf("-- CPF:  %s\n", aux->cpf);
        printf("-- Idade: %d\n", aux->idade);
        printf("-- Fiado? (1-sim) (0-não): %d\n", aux->fiado);
        printf("\n-----------------------------\n\n");
        aux = aux->next;
    }
}

void zeraListas(ListaBebidas *lb, ListaClientes *lc)
{
    int cont = 0;
    Bebida *aux2;
    Cliente *aux;
    Cliente *auxCli = lc->first;
    Bebida *auxBeb = lb->first;
    while (auxCli != NULL)
    {
        aux = auxCli;
        auxCli = auxCli->next;
        free(aux);
        cont ++;
    }
    while (auxBeb != NULL)
    {
        aux2 = auxBeb;
        auxBeb = auxBeb->next;
        free(aux2);
        cont ++;
    }
    printf("\nA quantidade de elementos liberados foi: %d\n", cont);
    return;
}

void initStacks(ListaBebidas *lb, ListaClientes *lc)
{
    lb->first = NULL;
    lb->last = NULL;
    lc->first = NULL;
    lc->last = NULL;
}

int main()
{
    ListaBebidas *listaBebidas = (ListaBebidas *)malloc(sizeof(ListaBebidas));
    ListaClientes *listaClientes = (ListaClientes *)malloc(sizeof(ListaClientes));
    initStacks(listaBebidas, listaClientes);

    int menu;
    printf("Bodega do Joãozin\n");
    while (1)
    {
        printf("\nEscolha uma opção:\n 1 - Cadastrar bebida;\n 2 - Mostrar bebidas cadastradas;\n 3 - Comprar bebidas; \n 4 - Vender Bebidas; \n 5 - Cadastrar Cliente; \n 6 - Mostrar Clientes; \n 7 - Sair do programa;\n\n ");
        scanf("%d", &menu);
        switch (menu)
        {
        case 1: // Cadastrar bebida
            cadastraBebida(listaBebidas);
            break;

        case 2: // Mostrar bebidas;
            mostraBebidas(listaBebidas);
            break;

        case 3: // Comprar bebida;
            compraBebida(listaBebidas);
            break;

        case 4: // Vender bebida;
            vendeBebida(listaBebidas, listaClientes);
            break;

        case 5: // Cadastrar cliente;
            cadastraCliente(listaClientes);
            break;

        case 6: // Mostrar clientes;
            mostraClientes(listaClientes);
            break;

        case 7: // Sair do sistema;
            zeraListas(listaBebidas, listaClientes);
            return 0;
        }
    };

    return 0;
}