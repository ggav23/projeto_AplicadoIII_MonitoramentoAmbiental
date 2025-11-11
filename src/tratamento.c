#include "tratamento.h"
#include <stdio.h>
#include <math.h> // Para isnan
#include "analise.h" // Para usar mediana

// Função auxiliar (não exportada no .h) para obter um vetor de uma coluna
void getColumn(double* dest, double DataRecord::* column, int n) {
    for (int i = 0; i < n; i++) {
        dest[i] = g_dados[i].*column;
    }
}

void tratarDadosAusentesNegativos() {
    // A IMPLEMENTAR
    // Iterar por g_num_registros
    // Exemplo simples (último valor válido):
    /*
    double ultimoValido = NAN;
    for (int i = 0; i < g_num_registros; i++) {
        if (isnan(g_dados[i].PM25_ugm3) || g_dados[i].PM25_ugm3 < 0) {
            g_dados[i].PM25_ugm3 = ultimoValido; // Pode continuar NAN se o primeiro for ausente
        } else {
            ultimoValido = g_dados[i].PM25_ugm3;
        }
    }
    // Repetir para todas as colunas necessárias...
    */
    printf(" (A implementar: tratamento de dados ausentes/negativos)\n");
}

void tratarOutliers() {
    // A IMPLEMENTAR
    // 1. Calcular Z-Score para PM2.5, NO2, O3, Ruido, Turbidez
    //    Para cada coluna:
    //    a. Pegar a coluna (ex: double pm25_data[g_num_registros])
    //    b. Calcular StatsResult stats = calcularEstatisticas(pm25_data, g_num_registros)
    //    c. Iterar de i = 0 a g_num_registros:
    //       double z = (g_dados[i].PM25_ugm3 - stats.media) / stats.std_dev;
    //       if (fabs(z) > 3.0) {
    //           // 2. Substituir por mediana da janela (±3 dias)
    //           // (Implementação da mediana da janela é complexa)
    //           // printf("Outlier encontrado em PM2.5 no dia %s (z=%.2f)\n", g_dados[i].data, z);
    //       }
    printf(" (A implementar: tratamento de outliers com Z-Score)\n");
}

void checarConsistencia() {
    // A IMPLEMENTAR
    // Iterar de i = 0 a g_num_registros
    // if (g_dados[i].OD_mgL < 3.5 || g_dados[i].OD_mgL > 12) { ... }
    // if (g_dados[i].pH < 6.6 || g_dados[i].pH > 8.3) { ... }
    // if (g_dados[i].AQI < 0 || g_dados[i].AQI > 500) { ... }
    printf(" (A implementar: checagem de consistência pH, OD, AQI)\n");
}
