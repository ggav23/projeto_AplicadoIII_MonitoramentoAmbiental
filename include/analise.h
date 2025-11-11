#ifndef ANALISE_H
#define ANALISE_H

#include "data.h"

// Estrutura para armazenar resultados estatísticos
typedef struct {
    double media;
    double mediana;
    double min;
    double max;
    double std_dev;
} StatsResult;

/**
 * @brief Calcula estatísticas descritivas (média, mediana, etc.) para um vetor de dados.
 * @param data Ponteiro para o primeiro elemento do vetor de doubles.
 * @param n O número de elementos no vetor.
 * @return Uma struct StatsResult com todos os valores calculados.
 */
StatsResult calcularEstatisticas(double* data, int n);

/**
 * @brief Calcula o coeficiente de correlação de Pearson entre dois vetores de dados.
 * @param dataX Ponteiro para o vetor da variável X.
 * @param dataY Ponteiro para o vetor da variável Y.
 * @param n O número de elementos em ambos os vetores.
 * @return O coeficiente de correlação (r).
 */
double calcularCorrelacaoPearson(double* dataX, double* dataY, int n);

/**
 * @brief Compara a média de PM2.5 entre dias úteis (DiaUtil=1) e não úteis (DiaUtil=0).
 */
void compararMediasDiaUtil();

#endif // ANALISE_H
