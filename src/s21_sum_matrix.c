#include "s21_matrix.h"
#include "utils.h"

/**
 * Сравнивает структуры matrix_t
 * @param A первая матрица
 * @param B вторая матрица
 * @param result указатель на итоговую матрицу
 * @return 0 - OK
 *         1 - Ошибка, некорректная матрица
 *         2 - Ошибка вычисления (несовпадающие размеры матриц; матрица, для
 *         которой нельзя провести вычисления и т.д.)
 */
int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int result_code = 0;
  if (!is_correct_matrix(*A) || !is_correct_matrix(*B) ||
      is_structure_null(result))
    result_code = 1;
  else if (!is_eq_matrix_sizes(A, B) && !is_eq_matrix_sizes(result, A))
    result_code = 2;
  else {
    for (int i = 0; i < A->rows; i++) {
      for (int ii = 0; ii < A->columns; ii++) {
        result->matrix[i][ii] = A->matrix[i][ii] + B->matrix[i][ii];
      }
    }
  }

  return result_code;
}