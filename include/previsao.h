#ifndef PREVISAO_H
#define PREVISAO_H

#include "data.h"

// Estrutura para armazenar os coeficientes da regressão (beta)
typedef struct {
    double a;  // Intercepto (b0)
    double b1; // Coeficiente 1
    double b2; // Coeficiente 2
    double b3; // Coeficiente 3
} RegCoefs;

/**
 * @brief Calcula a Média Móvel de 7 dias (MM7) para o último dia disponível.
 * @param dados Ponteiro para o vetor de dados (ex: g_dados[i].PM25_ugm3).
 * @param n_registros O número total de registros.
 * @return O valor da previsão para D+1.
 */
double preverMediaMovel(double* dados, int n_registros);

/**
 * @brief Resolve a regressão linear PM25 ~ a + b1*DiaUtil + b2*Chuva_mm + b3*Vento_mps.
 * Usa as funções de linalg.h para calcular β = (XᵀX)^(-1) Xᵀy.
 * @return Uma struct RegCoefs com os coeficientes (a, b1, b2, b3).
 */
RegCoefs calcularRegressaoPM25();

/**
 * @brief Resolve a regressão linear O3 ~ a + c1*Irradiancia_kWhm2 + c2*Temp_C + c3*Umidade_%.
 * @return Uma struct RegCoefs com os coeficientes (a, c1, c2, c3).
 */
RegCoefs calcularRegressaoO3();

/**
 * @brief Calcula o Root Mean Squared Error (RMSE) para validar um modelo.
 * @param dados_reais Ponteiro para os valores reais (ex: PM2.5).
 * @param dados_previstos Ponteiro para os valores previstos pelo modelo.
 * @param n O número de registros para validar (ex: 60 dias).
 * @return O valor do RMSE.
 */
double calcularRMSE(double* dados_reais, double* dados_previstos, int n);

#endif // PREVISAO_H
