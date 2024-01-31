#include "s21_matrix.h"
#include "utils.h"

/**
 * Транспонирование матрицы matrix_t
 * @param A первая матрица
 * @param B вторая матрица
 * @param result указатель на итоговую матрицу
 * @return 0 - OK
 *         1 - Ошибка, некорректная матрица
 *         2 - Ошибка вычисления (несовпадающие размеры матриц; матрица, для
 *         которой нельзя провести вычисления и т.д.)
 */
int s21_transpose(matrix_t *A, matrix_t *result) {
  if (!is_correct_matrix(*A) || !is_correct_matrix(*result)) return 1;
  if (A->rows != result->columns || A->columns != result->rows) return 2;
  int return_code = 0;
  for (int i = 0; i < A->rows; i++) {
    for (int ii = 0; ii < A->columns; ii++) {
      result->matrix[ii][i] = A->matrix[i][ii];
    }
  }
  return return_code;
}
