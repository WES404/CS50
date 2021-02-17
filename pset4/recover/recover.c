#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./recover image");
        return 1;
    }

    FILE *arquivo = fopen(argv[1], "r"); // Abre o arquivo 'card.raw' na modalidade 'read'

    if (arquivo == NULL)
    {
        printf("Unable to open: %s\n", argv[1]);
        return 1;
    }

    unsigned char buffer[512];
    int jpeg_count = 0; //Contagem de imagens começando do 0
    int jpeg_encontrado = 0; // Se for a primeira imagem encontrada será 0
    FILE *arqv_saida = NULL; // Arquivo em que as imagens serão escritas

    while (fread(&buffer, 512, 1, arquivo) == 1)
    {
        if(buffer[0] == 0xff && buffer[1] == 0xd8 &&
           buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
           {
                if (jpeg_encontrado == 1)
                { // se for a segunda ou mais imagem o arquivo anterior é fechado
                    fclose(arqv_saida);
                }

                else
                {
                    jpeg_encontrado = 1;
                }

                char filename[8];
                sprintf(filename, "%03i.jpg", jpeg_count); // cria arquivo com nome
                arqv_saida = fopen(filename, "w"); // abre arqivo para escreve
                jpeg_count++;
            }


        if (jpeg_encontrado == 1)
        {
            fwrite(&buffer, 512, 1, arqv_saida); // escreve o buffer no arquivo
        }
    }

    if (arqv_saida == NULL)
    {
        fclose(arqv_saida);
    }

    if (arquivo == NULL)
    {
        fclose(arquivo);
    }
    return 0;
}
