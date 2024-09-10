#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *pont_arq;
    char *buffer = NULL;  // Ponteiro para o buffer que armazenará o conteúdo do arquivo
    size_t buffer_size = 256; // Tamanho inicial do buffer
    size_t content_size = 0;  // Tamanho do conteúdo lido
    size_t read_size;         // Tamanho da leitura atual
    size_t new_size;          // Novo tamanho do buffer
    char temp_buffer[256];   // Buffer temporário para leitura
    char modify_choice;      // Opção para modificar o arquivo

    // Abrindo o arquivo em modo "somente leitura"
    pont_arq = fopen("arquivo.txt", "r");
    if (pont_arq == NULL) {
        perror("Erro ao abrir o arquivo");
        return 1; // Retorna um código de erro
    }

    // Alocando memória inicial para o buffer
    buffer = malloc(buffer_size);
    if (buffer == NULL) {
        perror("Erro ao alocar memória");
        fclose(pont_arq);
        return 1; // Retorna um código de erro
    }

    // Lendo o arquivo em blocos e ajustando o tamanho do buffer conforme necessário
    while (fgets(temp_buffer, sizeof(temp_buffer), pont_arq) != NULL) {
        read_size = strlen(temp_buffer);
        if (content_size + read_size >= buffer_size) {
            // Ajustando o tamanho do buffer
            new_size = buffer_size * 2;
            while (content_size + read_size >= new_size) {
                new_size *= 2;
            }
            buffer = realloc(buffer, new_size);
            if (buffer == NULL) {
                perror("Erro ao realocar memória");
                fclose(pont_arq);
                return 1; // Retorna um código de erro
            }
            buffer_size = new_size;
        }
        // Copiando o conteúdo do buffer temporário para o buffer principal
        strcpy(buffer + content_size, temp_buffer);
        content_size += read_size;
    }
    
    // Fechando o arquivo
    fclose(pont_arq);

    // Exibindo o conteúdo atual do arquivo
    printf("Conteúdo atual do arquivo:\n%s", buffer);

    // Perguntando se o usuário deseja modificar o arquivo
    printf("Deseja modificar o arquivo? (s/n): ");
    scanf(" %c", &modify_choice);
    getchar(); // Limpar o buffer do newline

    if (modify_choice == 's' || modify_choice == 'S') {
        // Solicitando ao usuário a nova entrada
        printf("Digite o novo conteúdo (pressione Ctrl+D para finalizar):\n");

        // Limpando o buffer para a nova entrada
        memset(buffer, 0, buffer_size);

        // Lendo o novo conteúdo
        size_t new_content_size = 0;
        while (fgets(temp_buffer, sizeof(temp_buffer), stdin) != NULL) {
            read_size = strlen(temp_buffer);
            if (new_content_size + read_size >= buffer_size) {
                // Ajustando o tamanho do buffer
                new_size = buffer_size * 2;
                while (new_content_size + read_size >= new_size) {
                    new_size *= 2;
                }
                buffer = realloc(buffer, new_size);
                if (buffer == NULL) {
                    perror("Erro ao realocar memória");
                    return 1; // Retorna um código de erro
                }
                buffer_size = new_size;
            }
            strcpy(buffer + new_content_size, temp_buffer);
            new_content_size += read_size;
        }

        // Reabrindo o arquivo em modo "escrita"
        pont_arq = fopen("arquivo.txt", "w");
        if (pont_arq == NULL) {
            perror("Erro ao abrir o arquivo para escrita");
            free(buffer);
            return 1; // Retorna um código de erro
        }

        // Escrevendo o novo conteúdo no arquivo
        fwrite(buffer, 1, new_content_size, pont_arq);
        fclose(pont_arq);

        printf("O arquivo foi modificado com sucesso!\n");
    }

    // Liberando a memória alocada
    free(buffer);

    return 0; // Retorna 0 para indicar que o programa terminou com sucesso
}

