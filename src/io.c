#include "io.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h> // Para NAN

// Função auxiliar para converter string para double (tratando vírgula e NAN)
double robust_atof(char* str) {
    if (str == NULL || strlen(str) == 0) {
        return NAN; // Dado ausente
    }
    char* p = str;
    while (*p) {
        if (*p == ',') {
            *p = '.'; // Troca vírgula por ponto
        }
        p++;
    }
    double val = atof(str);
    // Tratamento de negativos será feito na ETAPA 2 (tratamento.c)
    return val;
}

int lerCSV(const char* filename) {
    FILE* fp = fopen(filename, "r");
    if (!fp) {
        // Tenta adicionar "data/" se não encontrar
        char path[512];
        snprintf(path, sizeof(path), "data/%s", filename);
        fp = fopen(path, "r");
        if (!fp) {
            perror("Erro ao abrir arquivo");
            fprintf(stderr, "Verifique se o arquivo '%s' está na pasta 'data/'\n", filename);
            return 0;
        }
    }

    char buffer[MAX_LINE_LEN];
    int count = 0;

    // 1. Pular o cabeçalho
    if (fgets(buffer, MAX_LINE_LEN, fp) == NULL) {
        fprintf(stderr, "Erro: Arquivo CSV vazio ou cabeçalho inválido.\n");
        fclose(fp);
        return 0;
    }

    // 2. Ler os dados (linha por linha)
    // Esta seção foi reescrita para bater EXATAMENTE com as 20 colunas do CSV
    while (fgets(buffer, MAX_LINE_LEN, fp) && count < MAX_DAYS) {
        g_dados[count].valido = 0; // Assume inválido até o parse
        
        char* token;
        
        // Col 1: Dia (Ignorado)
        token = strtok(buffer, ",");
        
        // Col 2: Data
        token = strtok(NULL, ",");
        if (token) strncpy(g_dados[count].data, token, 10);
        g_dados[count].data[10] = '\0';
        
        // Col 3: DiaUtil
        token = strtok(NULL, ",");
        g_dados[count].DiaUtil = (token) ? atoi(token) : 0;
        
        // Col 4: Feriado
        token = strtok(NULL, ",");
        g_dados[count].Feriado = (token) ? atoi(token) : 0;
        
        // Col 5: Temp_C
        g_dados[count].Temp_C = robust_atof(strtok(NULL, ","));
        
        // Col 6: Umidade_% (Mapeado para Umidade_pct)
        g_dados[count].Umidade_pct = robust_atof(strtok(NULL, ","));
        
        // Col 7: Vento_mps
        g_dados[count].Vento_mps = robust_atof(strtok(NULL, ","));
        
        // Col 8: Chuva_mm
        g_dados[count].Chuva_mm = robust_atof(strtok(NULL, ","));
        
        // Col 9: Irradiancia_kWhm2
        g_dados[count].Irradiancia_kWhm2 = robust_atof(strtok(NULL, ","));
        
        // Col 10: PM25_ugm3
        g_dados[count].PM25_ugm3 = robust_atof(strtok(NULL, ","));
        
        // Col 11: PM10_ugm3
        g_dados[count].PM10_ugm3 = robust_atof(strtok(NULL, ","));
        
        // Col 12: NO2_ugm3
        g_dados[count].NO2_ugm3 = robust_atof(strtok(NULL, ","));
        
        // Col 13: O3_ugm3
        g_dados[count].O3_ugm3 = robust_atof(strtok(NULL, ","));
        
        // Col 14: CO_mg_m3
        g_dados[count].CO_mg_m3 = robust_atof(strtok(NULL, ","));
        
        // Col 15: SO2_ugm3
        g_dados[count].SO2_ugm3 = robust_atof(strtok(NULL, ","));
        
        // Col 16: AQI
        g_dados[count].AQI = robust_atof(strtok(NULL, ","));
        
        // Col 17: Ruido_dBA
        g_dados[count].Ruido_dBA = robust_atof(strtok(NULL, ","));
        
        // Col 18: pH
        g_dados[count].pH = robust_atof(strtok(NULL, ","));
        
        // Col 19: Turbidez_NTU
        g_dados[count].Turbidez_NTU = robust_atof(strtok(NULL, ","));
        
        // Col 20: OD_mgL
        token = strtok(NULL, ",\n\r"); // Pega o último token
        g_dados[count].OD_mgL = robust_atof(token);
        
        g_dados[count].valido = 1;
        count++;
    }

    fclose(fp);
    return count;
}


void gerarRelatorio() {
    printf("--- Relatório Final (A IMPLEMENTAR) ---\n\n");
    
    printf("1. Estatísticas Descritivas (PM2.5):\n");
    printf("   Média: ...\n");
    printf("   Mediana: ...\n");
    printf("   Min/Max: ...\n");
    printf("   StdDev: ...\n");
    
    printf("\n2. Correlações:\n");
    printf("   PM2.5 vs. Chuva: r = ...\n");
    printf("   O3 vs. Irradiância: r = ...\n");

    printf("\n3. Comparativos:\n");
    printf("   Média PM2.5 (Dia Útil): ...\n");
    printf("   Média PM2.5 (Fim de Semana): ...\n");

    printf("\n4. Previsão para D+1 (PM2.5):\n");
    printf("   Média Móvel (MM7): ...\n");
    printf("   Regressão Linear: ...\n");

    printf("\n5. Validação (RMSE últimos 60 dias):\n");
    printf("   RMSE MM7 (PM2.5): ...\n");
    printf("   RMSE Regressão (PM2.5): ...\n");
    printf("   Modelo Vencedor (PM2.5): ...\n");
}


void exportarResultados(const char* filename) {
    // (A IMPLEMENTAR)
    // Abre o arquivo, escreve o cabeçalho
    // Itera pelos últimos 60 dias e escreve as previsões
}
