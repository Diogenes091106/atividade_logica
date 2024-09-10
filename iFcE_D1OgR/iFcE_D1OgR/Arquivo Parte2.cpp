#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *pont_arq;
    
    char buffer[256];
    
    pont_arq = fopen("arquivo.txt", "a");
    
    if (pont_arq == NULL) {
        perror("Erro ao abrir o arquivo");
        return 1;
    }
    
    printf("Digite o texto para salvar no arquivo (pressione Enter para finalizar):\n");
    
    if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
        perror("Erro ao ler a entrada");
        fclose(pont_arq);
        return 1;
    }
    
    fprintf(pont_arq, "%s", buffer);
    
    fclose(pont_arq);
    
    printf("O texto foi salvo com sucesso!\n");
    
    return 0;
}

