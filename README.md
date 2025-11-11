# projeto_AplicadoIII_MonitoramentoAmbiental
Projeto de Análise Ambiental em C

Repositório para o projeto da disciplina de Projeto Aplicado III, focado na leitura, tratamento, análise e previsão de dados ambientais de 365 dias utilizando a linguagem C.

Membros do Grupo

Guilherme Vieira

Igor Marqaues Santos Magalhaes

Kaua Maciel Veit

Lucas Rocha de Santana

Elvis Miranda Teixeira



Estrutura do Repositório

analise-ambiental-c/
├── .gitignore
├── Makefile
├── README.md
├── data/
│   └── Monitoramento Ambiental - Avaliação V.csv  
├── docs/
│   └── especificacao.md            (A especificação completa do projeto)
├── include/
│   ├── analise.h                   (Cabeçalhos para estatística e correlação)
│   ├── data.h                      (Definição da struct principal)
│   ├── io.h                        (Cabeçalhos para leitura do CSV e escrita de relatórios)
│   ├── linalg.h                    (Cabeçalhos para álgebra linear)
│   ├── previsao.h                  (Cabeçalhos para média móvel e regressão)
│   └── tratamento.h                (Cabeçalhos para tratar outliers e dados ausentes)
└── src/
    ├── analise.c
    ├── io.c
    ├── linalg.c
    ├── main.c
    ├── previsao.c
    └── tratamento.c


Como Compilar e Executar

Este projeto usa make para compilação.

1. Compilar o projeto:

make


(Isso irá compilar todos os arquivos .c da pasta src/ e criar um executável na pasta raiz)

2. Executar o programa:

./analise_ambiental


3. Limpar os arquivos compilados:

make clean
