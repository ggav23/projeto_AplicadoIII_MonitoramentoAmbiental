Especificação do Projeto


Contexto

A cidade opera uma rede de sensores ambientais (estações de qualidade do ar, pluviômetros, estações meteorológicas, fonometria e pontos de qualidade da água). Você recebeu um dataset com 365 dias contendo meteorologia, poluentes do ar, ruído e qualidade da água. Sua missão: ler, tratar, analisar e prever indicadores-chave usando linguagem C.

Objetivos de Aprendizagem

Ler e parsear CSV para estruturas (struct/vetores) em C.

Tratar dados: ausentes, negativos e outliers (z-score > 3).

Calcular estatísticas descritivas e correlações.

Construir previsões (média móvel e regressão simples) para AQI e PM2.5 do dia seguinte.

Gerar relatório tabulado (stdout) e CSV com métricas e previsões.

O que o programa em C deve fazer

1. Entrada (CSV → memória)

Ler o arquivo CSV (link acima) em um vetor de struct.

Use fgets + strtok (ou sscanf) e converta ,/. conforme necessário.

2. Tratamento de Dados

Ausentes/negativos: imputar com média dos vizinhos ou último valor válido.

Outliers: calcular z-score em PM25_ugm3, NO2_ugm3, O3_ugm3, Ruido_dBA e Turbidez_NTU; se |z|>3, substituir por mediana da janela ±3 dias.

Consistências a checar (só alertar, não reprovar):

OD_mgL entre 3.5 e 12

pH entre 6.6 e 8.3

AQI ∈ [0, 500]

3. Análises (KPIs)

Estatísticas (média, mediana, min, max, desvio-padrão) de: PM25_ugm3, NO2_ugm3, O3_ugm3, AQI, Ruido_dBA, Turbidez_NTU.

Correlação de Pearson de PM25_ugm3 com Chuva_mm, Vento_mps, DiaUtil, e de O3_ugm3 com Irradiancia_kWhm2 e Temp_C.

Comparar médias de PM25_ugm3 entre dias úteis vs. fds/feriados.

4. Previsão (obrigatória)

Média móvel (MM7) para PM2.5 e AQI: previsão do dia D+1 = média dos últimos 7 dias.

Regressão linear simples:

PM25 ~ a + b1*DiaUtil + b2*Chuva_mm + b3*Vento_mps

O3 ~ a + c1*Irradiancia_kWhm2 + c2*Temp_C + c3*Umidade_%

Resolver por equações normais: β = (XᵀX)^(-1) Xᵀy (implemente você mesmo).

Compare RMSE entre MM7 e regressão nos últimos 60 dias e indique o modelo vencedor por variável.

5. Saída / Relatório

Imprimir: estatísticas, correlações, previsão do próximo dia (PM2.5 e AQI) por MM7 e regressão, e RMSE de validação.

(Bônus) Exportar resultados.csv com colunas: Prev_PM25_MM7, Prev_PM25_Reg, Prev_AQI_MM7, Prev_O3_Reg, Erro_*.
