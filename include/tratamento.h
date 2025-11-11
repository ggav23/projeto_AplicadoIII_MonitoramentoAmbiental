#ifndef TRATAMENTO_H
#define TRATAMENTO_H

#include "data.h"

/**
 * @brief Processa todo o vetor g_dados para tratar dados ausentes (NAN) e negativos.
 * Usa a estratégia de "último valor válido" ou "média dos vizinhos".
 */
void tratarDadosAusentesNegativos();

/**
 * @brief Calcula e substitui outliers usando o método Z-Score.
 * Aplica a regra |z| > 3 e substitui pela mediana da janela (±3 dias).
 */
void tratarOutliers();

/**
 * @brief Verifica inconsistências nos dados (pH, OD, AQI) e imprime alertas.
 */
void checarConsistencia();

#endif // TRATAMENTO_H
