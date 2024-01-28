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
  if (rows <= 0 || columns <= 0 || result == NULL) return 1;

  result->matrix = (double **)calloc(rows, sizeof(double *));
  if (result->matrix == NULL) result_code = 2;

  for (int i = 0; i < rows; i++) {
    result->matrix[i] = calloc(columns, sizeof(double));
    if (result->matrix == NULL) result_code = 2;
  }

  if (result_code == 2) {
    for (int i = 0; i < rows; i++) {
      free(result->matrix[i]);
    }
    result = NULL;
  }

  result->rows = rows;
  result->columns = columns;

  return result_code;
}
