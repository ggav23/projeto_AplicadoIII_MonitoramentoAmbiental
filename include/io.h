#ifndef IO_H
#define IO_H

#include "data.h"

/**
 * @brief Lê o arquivo CSV principal e preenche o vetor global g_dados.
 * @param filename O nome do arquivo CSV a ser lido (ex: "data/monitoramento_365_dias.csv").
 * @return O número de registros lidos com sucesso.
 */
int lerCSV(const char* filename);

/**
 * @brief Imprime o relatório final de KPIs e previsões no console (stdout).
 */
void gerarRelatorio();

/**
 * @brief (Bônus) Exporta os resultados das previsões para um arquivo CSV.
 * @param filename O nome do arquivo de saída (ex: "resultados.csv").
 */
void exportarResultados(const char* filename);

#endif // IO_H
