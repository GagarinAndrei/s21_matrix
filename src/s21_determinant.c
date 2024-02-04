#include <stdio.h>

#include "s21_matrix.h"
#include "utils.h"

/**
 * Опредедлитель матрицы
 * @param A матрица
 * @param result определитель матрицы
 * @return 0 - OK
 *         1 - Ошибка, некорректная матрица
 *         2 - Ошибка вычисления (несовпадающие размеры матриц; матрица, для
 *         которой нельзя провести вычисления и т.д.)
 */
int s21_determinant(matrix_t *A, double *result) {
  if (is_structure_null(A) || !is_correct_matrix(*A) || result == NULL)
    return 1;
  else if (!is_square_matrix(A))
    return 2;
  int result_code = 0;
  double tmp_result = 0;
  double tmp_determenant;
  int sign = 1;

  if (A->rows == 1)
    tmp_result = A->matrix[0][0];
  else {
    matrix_t tmp_matrix = {0};
    for (int i = 0; i < A->columns; i++) {
      minor_of_matrix(A, 0, i, &tmp_matrix);
      s21_determinant(&tmp_matrix, &tmp_determenant);
      tmp_result += sign * A->matrix[0][i] * tmp_determenant;
      sign = -sign;
    }
    s21_remove_matrix(&tmp_matrix);
  }
  *result = tmp_result;
  return result_code;
}
