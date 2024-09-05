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
    char status[10]; 
} PESSOA;

void Mostrar_Pessoa(PESSOA p)
{
    printf("Nome: %s\n", p.Nome);
    printf("Idade: %d\n", p.Idade);
    printf("Salario: %.2f\n", p.Salario);
    printf("Data de Nascimento: %02d/%02d/%04d\n", p.Nasc.Dia, p.Nasc.Mes, p.Nasc.Ano);
    printf("Status: %s\n", p.status);
}

void Ler_Pessoa(PESSOA *p)
{
   
    printf("Nome: ");
    fgets(p->Nome, sizeof(p->Nome), stdin);
    p->Nome[strcspn(p->Nome, "\n")] = '\0';  

    
    printf("Idade: ");
    scanf("%d", &p->Idade);

  
    printf("Salario: ");
    scanf("%f", &p->Salario);

    
    while (getchar() != '\n');

    
    printf("Status: ");
    fgets(p->status, sizeof(p->status), stdin);
    p->status[strcspn(p->status, "\n")] = '\0';  

   
    printf("Dia de nascimento: ");
    scanf("%d", &p->Nasc.Dia);

    printf("Mes de nascimento: ");
    scanf("%d", &p->Nasc.Mes);

    printf("Ano de nascimento: ");
    scanf("%d", &p->Nasc.Ano);

    
    while (getchar() != '\n');
}

int main()
{
    PESSOA p;

    // Preencher a estrutura PESSOA
    Ler_Pessoa(&p);

    // Exibição das informações do usuario
    Mostrar_Pessoa(p);

    return 0;
}

