#ifndef LINALG_H
#define LINALG_H

// --- Funções de Matriz ---
// Estas funções são a base para resolver a regressão linear.

/**
 * @brief Aloca dinamicamente uma matriz (vetor de ponteiros para vetores).
 */
double** criarMatriz(int linhas, int colunas);

/**
 * @brief Libera a memória de uma matriz alocada dinamicamente.
 */
void liberarMatriz(double** matriz, int linhas);

/**
 * @brief Imprime uma matriz no console (para debug).
 */
void imprimirMatriz(double** matriz, int linhas, int colunas);

/**
 * @brief Calcula a transposta de uma matriz.
 * @param A Matriz original.
 * @param A_linhas Número de linhas de A.
 * @param A_colunas Número de colunas de A.
 * @return Uma nova matriz (A_colunas x A_linhas) que é a transposta de A.
 */
double** transporMatriz(double** A, int A_linhas, int A_colunas);

/**
 * @brief Multiplica duas matrizes (A * B).
 * @param A Matriz A (m x n).
 * @param B Matriz B (n x p).
 * @param A_linhas Linhas de A (m).
 * @param A_colunas Colunas de A (n).
 * @param B_colunas Colunas de B (p).
 * @return Uma nova matriz (m x p) resultado de A * B.
 */
double** multiplicarMatrizes(double** A, double** B, int A_linhas, int A_colunas, int B_colunas);

/**
 * @brief Calcula o determinante de uma matriz (ex: 3x3 ou 4x4).
 * Necessário para a inversão.
 */
double calcularDeterminante(double** A, int n);

/**
 * @brief Calcula a inversa de uma matriz (ex: 3x3 ou 4x4) usando a adjunta.
 * Necessário para (XᵀX)^-1.
 * @param A Matriz quadrada (n x n).
 * @param n Ordem da matriz.
 * @return Uma nova matriz (n x n) que é a inversa de A.
 */
double** inverterMatriz(double** A, int n);


#endif // LINALG_H
