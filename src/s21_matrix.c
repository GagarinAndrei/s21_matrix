#include "s21_matrix.h"

#include <stdlib.h>

/**
 * Создаёт структуру matrix_t
 * @param rows число рядов
 * @param columns число столбцов
 * @param result указатель на матрицу
 * @return 0 - OK
 *				 1 - Ошибка, некорректная матрица
 *   			 2 - Ошибка вычисления (несовпадающие размеры матриц;
 *				 матрица, для которой нельзя провести вычисления
 *и т.д.)
 */
int s21_create_matrix(int rows, int columns, matrix_t *result) {
  int result_code = 0;
  int calloc_success_count = 0;
  if (rows <= 0 || columns <= 0 || result == NULL)
    return 1;

  result->matrix = (double **)calloc(rows, sizeof(double *));
  if (result->matrix == NULL)
    result_code = 2;

  for (int i = 0; i < rows; i++) {
    result->matrix[i] = calloc(columns, sizeof(double));
    if (result->matrix == NULL)
      result_code = 2;
    calloc_success_count++;
  }

  if (result_code == 2) {
    for (int i = 0; i < calloc_success_count; i++) {
      free(result->matrix[i]);
    }
    free(result->matrix);
    result->matrix = NULL;
  } else {
    result->rows = rows;
    result->columns = columns;
  }
  return result_code;
}

/**
 * Удаляет структуру matrix_t
 * @param A указатель на матрицу
 */
void s21_remove_matrix(matrix_t *A) {
  if (A && A->matrix)  {
    for (int i = 0; i < A->rows; i++) {
      if (A->matrix[i] != NULL) free(A->matrix[i]);
		}
    free(A->matrix);
    A->matrix = NULL;
    A->rows = 0;
    A->columns = 0;
  }
    A->matrix = NULL;
}
