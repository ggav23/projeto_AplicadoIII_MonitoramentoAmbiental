#ifndef DATA_H
#define DATA_H

// --- CONFIGURAÇÕES ---
#define MAX_DAYS 365
#define MAX_LINE_LEN 1024

// --- ESTRUTURA PRINCIPAL DE DADOS ---
// Estrutura atualizada para corresponder ao CSV de 365 dias
typedef struct {
    char data[11];
    
    // Poluentes e Ruído
    double PM25_ugm3;
    double NO2_ugm3;
    double O3_ugm3;
    double AQI;
    double Ruido_dBA;
    // Novas colunas do CSV
    double PM10_ugm3;
    double CO_mg_m3;
    double SO2_ugm3;
    
    // Qualidade da Água
    double Turbidez_NTU;
    double OD_mgL;
    double pH;
    
    // Meteorologia
    double Temp_C;
    double Umidade_pct; // Mapeado de Umidade_%
    double Chuva_mm;
    double Vento_mps;
    double Irradiancia_kWhm2;
    
    // Outros
    int DiaUtil; // 1 = Sim, 0 = Não
    int Feriado; // 1 = Sim, 0 = Não
    
    // Flag de controle interno
    int valido;  // 1 = ok, 0 = falha no parse
    
} DataRecord;

// Declaração do vetor global de dados
// (extern indica que será definido em outro arquivo, ex: main.c)
extern DataRecord g_dados[MAX_DAYS];
extern int g_num_registros;

#endif // DATA_H
