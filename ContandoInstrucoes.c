#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

#define TamanhoMaximo 7 

#define TamanhoAleatorio 100 

void Iniciador(const int linhas, const int colunas, int Matriz[linhas][colunas]);

void ImprimirMatriz(const int linhas, const int colunas, int Matriz[linhas][colunas]);

int Caminho(const int linhas, const int colunas, int Matriz[linhas][colunas]);

void Iniciador(const int linhas, const int colunas, int Matriz[linhas][colunas]){

    for (int i = 0; i < linhas; i++){

        for (int j = 0; j < colunas; j++){
            {
                Matriz[i][j] = rand() % TamanhoAleatorio;
            }
        }
    }
}

void ImprimirMatriz(const int linhas, const int colunas, int Matriz[linhas][colunas]){

    for (int i = 0; i < linhas; i++){

        for (int j = 0; j < colunas; j++){
            

            printf("|%i||%i| -> %i\t", i, j, Matriz[i][j]);
        }
        printf("\n");
    }
}

int Caminho(const int linhas, const int colunas, int Matriz[linhas][colunas]){

    int aux = 0;

    int i = 0; 

    int j = 0;

    aux += Matriz[i][j];

    Matriz[i][j] = 0;

    while (i != linhas && j != colunas){

        if (i < linhas - 1 && j == 0){

            if(Matriz[i][j + 1] >= Matriz[i + 1][j] && Matriz[i][j + 1] != 0){

                aux += Matriz[i][j + 1];

                Matriz[i][j + 1] = 0;

                j++;
            }
            else
            {
                aux += Matriz[i + 1][j];

                Matriz[i + 1][j] = 0;

                i++;
            }
        }
        else if (i < linhas - 1 && j == colunas - 1){

            if(Matriz[i][j - 1] >= Matriz[i + 1][j] && Matriz[i][j - 1] != 0){

                aux += Matriz[i][j - 1];

                Matriz[i][j - 1] = 0;

                j--;
            }
            else
            {
                aux += Matriz[i + 1][j];

                Matriz[i + 1][j] = 0;

                i++;
            }
        }
        else if(i == linhas - 1 && j < colunas - 1){

            aux += Matriz[i][j+1];

            Matriz[i][j+1] = 0;

            j++;
        }
        else if(i == linhas - 1 && j == colunas - 1){

            j++;
        }
        else if(i != linhas - 1 && j != colunas - 1){

            if(Matriz[i][j - 1] > Matriz[i + 1][j] && Matriz[i][j - 1] > Matriz[i][j + 1]){

                aux += Matriz[i][j - 1];

                Matriz[i][j - 1] = 0;

                j--;
            }
            else if(Matriz[i + 1][j] > Matriz[i][j - 1] && Matriz[i + 1][j] > Matriz[i][j + 1]){

                aux += Matriz[i + 1][j];

                Matriz[i + 1][j] = 0;

                i++;
            }
            else
            {
                aux += Matriz[i][j + 1];

                Matriz[i][j + 1] = 0;

                j++;
            }
        }
    }
    return aux;
}

int main(void)
{
    int Matriz[TamanhoMaximo][TamanhoMaximo];

    int aux;

    srand(time(NULL));

    printf("\n");

    Iniciador(TamanhoMaximo, TamanhoMaximo, Matriz);

    printf("Matriz Aleatoria->\n\n");

    ImprimirMatriz(TamanhoMaximo, TamanhoMaximo, Matriz);

    aux = Caminho(TamanhoMaximo, TamanhoMaximo, Matriz); 

    printf("\n");

    printf("Trilhando o caminho de valor máximo-> (0)\n\n");

    ImprimirMatriz(TamanhoMaximo, TamanhoMaximo, Matriz);

    printf("\n");

    printf("Caminho de valor máximo = %i\n", aux);

    return 0;
}