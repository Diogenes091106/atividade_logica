#include <stdio.h>
main()
{
// criando a vari�vel ponteiro para o arquivo
FILE *pont_arq;
//abrindo o arquivo
pont_arq = fopen("arquivo.txt", "a");
// fechando arquivo
fclose(pont_arq);
//mensagem para o usu�rio
printf("O arquivo foi criado com sucesso!");
}
