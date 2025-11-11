#include "linalg.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h> // Para fabs

double** criarMatriz(int linhas, int colunas) {
    double** matriz = (double**)malloc(linhas * sizeof(double*));
    if (matriz == NULL) return NULL;
    for (int i = 0; i < linhas; i++) {
        matriz[i] = (double*)calloc(colunas, sizeof(double)); // calloc zera a memória
        if (matriz[i] == NULL) {
            // Se falhar, libera o que já foi alocado
            for (int j = 0; j < i; j++) free(matriz[j]);
            free(matriz);
            return NULL;
        }
    }
    return matriz;
}

void liberarMatriz(double** matriz, int linhas) {
    if (matriz == NULL) return;
    for (int i = 0; i < linhas; i++) {
        free(matriz[i]);
    }
    free(matriz);
}

void imprimirMatriz(double** matriz, int linhas, int colunas) {
    if (matriz == NULL) return;
    for (int i = 0; i < linhas; i++) {
        printf(" [");
        for (int j = 0; j < colunas; j++) {
            printf("%8.3f ", matriz[i][j]);
        }
        printf("]\n");
    }
}

double** transporMatriz(double** A, int A_linhas, int A_colunas) {
    double** T = criarMatriz(A_colunas, A_linhas);
    if (T == NULL) return NULL;
    // A IMPLEMENTAR
    // Iterar i, j -> T[j][i] = A[i][j]
    printf(" (A implementar: transporMatriz)\n");
    return T;
}

double** multiplicarMatrizes(double** A, double** B, int A_linhas, int A_colunas, int B_colunas) {
    double** C = criarMatriz(A_linhas, B_colunas);
    if (C == NULL) return NULL;
    // A IMPLEMENTAR
    // Iterar i (0..A_linhas), j (0..B_colunas), k (0..A_colunas)
    // C[i][j] += A[i][k] * B[k][j]
    printf(" (A implementar: multiplicarMatrizes)\n");
    return C;
}

double** inverterMatriz(double** A, int n) {
    // A IMPLEMENTAR
    // Esta é a função mais difícil.
    // Para n=3 ou n=4 (regressão com 3 variáveis + intercepto = 4x4)
    // Pode ser feito com o método da Adjunta/Cofatores.
    // 1. Calcular a matriz de cofatores
    // 2. Calcular a matriz adjunta (transposta dos cofatores)
    // 3. Calcular o determinante
    // 4. Inversa = (1.0 / determinante) * Adjunta
    
    // Se o professor permitir, uma implementação "hardcoded" para 3x3 ou 4x4 é
    // muito mais fácil do que uma genérica (ex: Eliminação de Gauss-Jordan).
    printf(" (A implementar: inverterMatriz)\n");
    return NULL; // Retorna NULL por enquanto
}
