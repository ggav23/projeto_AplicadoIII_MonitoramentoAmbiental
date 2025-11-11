#include <stdio.h>
#include <stdlib.h>
#include "data.h"
#include "io.h"
#include "tratamento.h"
#include "analise.h"
#include "previsao.h"
#include "linalg.h"

// Definição das variáveis globais
DataRecord g_dados[MAX_DAYS];
int g_num_registros = 0;


int main() {
    printf("--- Iniciando Projeto de Análise Ambiental em C ---\n");

    // --- 1. Entrada (CSV -> Memória) ---
    printf("\n[ETAPA 1: LEITURA]\n");
    // Atualizado para carregar o nome do arquivo correto
    g_num_registros = lerCSV("data/Monitoramento Ambiental - Avaliação V.xlsx - Sheet1.csv");
    if (g_num_registros <= 0) {
        fprintf(stderr, "Erro: Não foi possível ler o arquivo CSV ou o arquivo está vazio.\n");
        return 1;
    }
    printf("Sucesso: %d registros lidos.\n", g_num_registros);

    // --- 2. Tratamento de Dados ---
    printf("\n[ETAPA 2: TRATAMENTO DE DADOS]\n");
    printf("Verificando consistência...\n");
    checarConsistencia();
    
    printf("Tratando dados ausentes/negativos...\n");
    tratarDadosAusentesNegativos();
    
    printf("Tratando outliers (Z-Score > 3)...\n");
    tratarOutliers();
    printf("Tratamento concluído.\n");

    // --- 3. Análises (KPIs) ---
    printf("\n[ETAPA 3: ANÁLISE ESTATÍSTICA]\n");
    // (Chamar aqui as funções de analise.c)
    // Ex: calcularEstatisticas(...) para cada coluna
    // Ex: calcularCorrelacaoPearson(...)
    // Ex: compararMediasDiaUtil()
    printf("Análises estatísticas... (A IMPLEMENTAR)\n");


    // --- 4. Previsão ---
    printf("\n[ETAPA 4: PREVISÃO E VALIDAÇÃO]\n");
    // (Chamar aqui as funções de previsao.c)
    // Ex: preverMediaMovel(...)
    // Ex: calcularRegressaoPM25() e calcularRegressaoO3()
    // Ex: calcularRMSE() nos últimos 60 dias
    printf("Cálculo de previsões... (A IMPLEMENTAR)\n");


    // --- 5. Saída / Relatório ---
    printf("\n[ETAPA 5: RELATÓRIO FINAL]\n");
    // (Gerar o relatório com os resultados das etapas 3 e 4)
    gerarRelatorio();
    
    // (Bônus)
    // exportarResultados("resultados.csv");
    // printf("Arquivo 'resultados.csv' gerado.\n");

    printf("\n--- Análise concluída com sucesso. ---\n");
    return 0;
}
