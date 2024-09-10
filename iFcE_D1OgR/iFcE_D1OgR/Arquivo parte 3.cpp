#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *pont_arq;
    char texto_str[256]; // Aumentando o buffer para ler linhas maiores
    
    // Abrindo o arquivo em modo "somente leitura"
    pont_arq = fopen("arquivo.txt", "r");
    if (pont_arq == NULL) {
        // Se não conseguir abrir o arquivo, exibe uma mensagem de erro e encerra
        perror("Erro ao abrir o arquivo");
        return 1; // Retorna um código de erro
    }
    
    // Lendo o arquivo linha por linha e exibindo o texto
    while (fgets(texto_str, sizeof(texto_str), pont_arq) != NULL) {
        printf("%s", texto_str);
    }
    
    // Fechando o arquivo
    fclose(pont_arq);
    
    return 0; // Retorna 0 para indicar que o programa terminou com sucesso
}

