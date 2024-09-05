#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

typedef struct
{
    int Dia, Mes, Ano;
} DATA;

typedef struct pessoa
{
    char Nome[80];
    int Idade;
    float Salario;
    DATA Nasc;
} PESSOA;

void Mostrar(PESSOA x)
{
    printf("Nome : %s\n", x.Nome);
    printf("Idade : %d\n", x.Idade);
    printf("Salario : %.2f\n", x.Salario);
    printf("Dt.Nasc : %d/%d/%d\n", x.Nasc.Dia, x.Nasc.Mes, x.Nasc.Ano);
}

void PreencherPessoa(PESSOA *p)
{
    
    printf("Digite o nome: ");
    fgets(p->Nome, sizeof(p->Nome), stdin);

    
    p->Nome[strcspn(p->Nome, "\n")] = '\0';

    // Limpeza do buffer
    while (getchar() != '\n');

    // Leitura da idade
    printf("Digite a idade: ");
    scanf("%d", &p->Idade);

    // Limpeza do buffer
    while (getchar() != '\n');

    
    printf("Digite o salario: ");
    scanf("%f", &p->Salario);

    // Limpeza do buffer 
    while (getchar() != '\n');

    
    printf("Digite o dia de nascimento: ");
    scanf("%d", &p->Nasc.Dia);

    // Limpeza do buffer 
    while (getchar() != '\n');

    
    printf("Digite o mes de nascimento: ");
    scanf("%d", &p->Nasc.Mes);

    // Limpeza do buffer 
    while (getchar() != '\n');

    
    printf("Digite o ano de nascimento: ");
    scanf("%d", &p->Nasc.Ano);

    // Limpeza do buffer
    while (getchar() != '\n');
}

int main()
{
    PESSOA p;

    // estrutura PESSOA
    PreencherPessoa(&p);

    // informações do usuario
    Mostrar(p);

    return 0;
}

