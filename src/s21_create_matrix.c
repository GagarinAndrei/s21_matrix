#include "s21_matrix.h"
#include "utils.h"

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
  if (is_structure_null(result)) {
    return 1;
  }
  if (rows <= 0 || columns <= 0) {
    result->rows = 0;
    result->columns = 0;
    result->matrix = NULL;
    return 1;
  }

  int result_code = 0;
  int calloc_success_count = 0;

  result->matrix = (double **)calloc(rows, sizeof(double *));
  if (result->matrix == NULL) result_code = 2;

  if (!result_code) {
    for (int i = 0; i < rows; i++) {
      result->matrix[i] = calloc(columns, sizeof(double));
      if (result->matrix[i] == NULL) {
        result_code = 2;
        calloc_success_count = i;
      }
    }

    if (result_code) {
      for (int i = 0; i < calloc_success_count; i++) {
        free(result->matrix[i]);
      }
      free(result->matrix);
    } else {
      result->rows = rows;
      result->columns = columns;
    }
  }
  return result_code;
}
