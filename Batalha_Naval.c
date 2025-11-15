#include <stdio.h> 

#define TAM 10
#define NAVIO 3
#define TAM_NAVIO 3
#define AFETADO 5

int main() {
    int i, j;
    int tabuleiro[TAM][TAM] = {0};

// Coordenadas dos navios
    int linhahorizontal = 2;
    int colunahorizontal = 4;
    
    int linhavertical = 5;
    int colunavertical = 7;

    int linhaD1 = 2; 
    int colunaD1 = 2;

    int linhaD2 = 5; 
    int colunaD2 = 2;

// Horizontal
    for (j = 0; j < TAM_NAVIO; j++)
        tabuleiro[linhahorizontal][colunahorizontal + j] = NAVIO;

// Vertical
    for (i = 0; i < TAM_NAVIO; i++)
        tabuleiro[linhavertical + i][colunavertical] = NAVIO;

 // Diagonal 1
    for (i = 0; i < TAM_NAVIO; i++)
        tabuleiro[linhaD1 + i][colunaD1 + i] = NAVIO;

// Diagonal 2
    for (i = 0; i < TAM_NAVIO; i++)
        tabuleiro[linhaD2 + i][colunaD2 - i] = NAVIO;

// Centro das habilidades

    int CruzX = 2, CruzY = 7;   
    int OctX  = 5, OctY  = 4;   
    int ConeX = 9, ConeY = 2; 

// Cruz

    for (i = -2; i <= 2; i++)
    {
        for (j = -2; j <= 2; j++)
        {
            int linha = CruzX + i;
            int coluna = CruzY + j;

            if (linha < 0 || linha >= TAM || coluna < 0 || coluna >= TAM)
            continue;
            
            if (i == 0 || j == 0)  
                tabuleiro[linha][coluna] = AFETADO;
        }   
    }
    
// Octaedro

    for (i = -2; i <= 2; i++) {
        for (j = -2; j <= 2; j++) {

            int linha = OctX + i;
            int coluna = OctY + j;

            if (linha < 0 || linha >= TAM || coluna < 0 || coluna >= TAM)
                continue;

           
            if (i + j <= 2 && i + j >= -2 &&
                i - j <= 2 && i - j >= -2)
                tabuleiro[linha][coluna] = AFETADO;
        }
    }

// Cone

    for (i = -2; i <= 2; i++) {

        int linhaReal = ConeX + i;

        if (linhaReal < 0 || linhaReal >= TAM)
            continue;

        int inicio, fim;

        if (i == -2) { inicio = 0;  fim = 0;  }     
        if (i == -1) { inicio = -1; fim = 1; }      
        if (i >= 0)  { inicio = -2; fim = 2; }      

        for (j = inicio; j <= fim; j++) {

            int colunaReal = ConeY + j;

            if (colunaReal < 0 || colunaReal >= TAM)
                continue;

            tabuleiro[linhaReal][colunaReal] = AFETADO;
        }
    }

// Exibir tabuleiro
  
    printf("\n*TABULEIRO DE BATALHA NAVAL*\n");

    for (i = 0; i < TAM; i++) {
        for (j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
