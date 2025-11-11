#include "analise.h"
#include <stdlib.h> // Para malloc, qsort
#include <math.h>   // Para sqrt, isnan
#include <stdio.h>

// Função de comparação para qsort (necessária para mediana)
static int compare_doubles(const void* a, const void* b) {
    double da = *(const double*)a;
    double db = *(const double*)b;
    if (isnan(da)) return 1;  // Trata NaNs (coloca no final)
    if (isnan(db)) return -1;
    if (da < db) return -1;
    if (da > db) return 1;
    return 0;
}

StatsResult calcularEstatisticas(double* data, int n) {
    StatsResult result = {NAN, NAN, NAN, NAN, NAN};
    
    // A IMPLEMENTAR
    // 1. Alocar memória para cópia (para mediana)
    // 2. Iterar uma vez para calcular Média, Min, Max e contar não-NANs (count)
    // 3. Calcular StdDev (requer uma segunda iteração ou guardar soma dos quadrados)
    // 4. Ordenar a cópia (qsort)
    // 5. Achar a Mediana (elemento do meio em [count-1]/2)
    // 6. Liberar memória
    
    // printf(" (A implementar: calcularEstatisticas)\n");
    return result;
}

double calcularCorrelacaoPearson(double* dataX, double* dataY, int n) {
    // A IMPLEMENTAR
    // 1. Calcular média de X (meanX) e Y (meanY)
    // 2. Calcular StdDev de X (stdDevX) e Y (stdDevY)
    // 3. Calcular Covariância:
    //    sum = 0
    //    Iterar i = 0 a n:
    //      sum += (dataX[i] - meanX) * (dataY[i] - meanY)
    //    cov = sum / (n-1)
    // 4. r = cov / (stdDevX * stdDevY)
    
    // printf(" (A implementar: calcularCorrelacaoPearson)\n");
    return NAN;
}

void compararMediasDiaUtil() {
    // A IMPLEMENTAR
    // 1. Iterar g_dados:
    //    Acumular soma e contagem para (DiaUtil == 1)
    //    Acumular soma e contagem para (DiaUtil == 0)
    // 2. Calcular as duas médias
    // 3. Imprimir
    // printf(" (A implementar: compararMediasDiaUtil)\n");
}
