#include "previsao.h"
#include "linalg.h"
#include <stdio.h>
#include <stdlib.h> // Para malloc/free
#include <math.h> // Para NAN

double preverMediaMovel(double* dados, int n_registros) {
    // A IMPLEMENTAR
    // 1. Definir o tamanho da janela (ex: 7)
    // 2. Iterar de i = (n_registros - 7) até (n_registros - 1)
    // 3. Somar os valores (cuidado com NANs)
    // 4. Retornar soma / 7
    printf(" (A implementar: preverMediaMovel)\n");
    return NAN;
}

RegCoefs calcularRegressaoPM25() {
    RegCoefs coefs = {NAN, NAN, NAN, NAN};
    
    // A IMPLEMENTAR
    // 1. Definir N (número de dias) e K (número de previsores + 1)
    //    K = 4 (a, b1, b2, b3)
    
    // 2. Criar matriz X (N x K) e vetor Y (N x 1)
    //    double** X = criarMatriz(g_num_registros, K);
    //    double** Y = criarMatriz(g_num_registros, 1);
    
    // 3. Popular X e Y
    //    Iterar i = 0 a N:
    //      Y[i][0] = g_dados[i].PM25_ugm3;
    //      X[i][0] = 1.0; // Intercepto 'a'
    //      X[i][1] = (double)g_dados[i].DiaUtil;
    //      X[i][2] = g_dados[i].Chuva_mm;
    //      X[i][3] = g_dados[i].Vento_mps;
    //    (Cuidado com dados NAN! A regressão deve usar apenas linhas completas)

    // 4. Calcular β = (XᵀX)^(-1) Xᵀy
    //    double** Xt = transporMatriz(X, N, K);
    //    double** XtX = multiplicarMatrizes(Xt, X, K, N, K);
    //    double** XtX_inv = inverterMatriz(XtX, K);
    //    double** XtY = multiplicarMatrizes(Xt, Y, K, N, 1);
    //    double** B = multiplicarMatrizes(XtX_inv, XtY, K, K, 1);
    
    // 5. Extrair coeficientes de B (que é uma matriz K x 1)
    //    coefs.a = B[0][0];
    //    coefs.b1 = B[1][0];
    //    ...

    // 6. Liberar todas as matrizes intermediárias (Xt, XtX, XtX_inv, XtY, B, X, Y)
    
    printf(" (A implementar: calcularRegressaoPM25)\n");
    return coefs;
}

RegCoefs calcularRegressaoO3() {
    // A IMPLEMENTAR (lógica similar a PM25, mas com colunas diferentes)
    printf(" (A implementar: calcularRegressaoO3)\n");
    RegCoefs coefs = {NAN, NAN, NAN, NAN};
    return coefs;
}

double calcularRMSE(double* dados_reais, double* dados_previstos, int n) {
    // A IMPLEMENTAR
    // 1. Iterar i = 0 a n:
    //    sum_sq_err += pow(dados_reais[i] - dados_previstos[i], 2);
    // 2. mse = sum_sq_err / n;
    // 3. return sqrt(mse);
    printf(" (A implementar: calcularRMSE)\n");
    return NAN;
}
