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
  int result_code = 0;
  struct coordinates_struct index = {0};
  if (is_structure_null(A) || !is_correct_matrix(*A) || result == NULL)
    result_code = 1;
  else if (!is_square_matrix(*A))
    result_code = 2;
  if (A->rows == 2) *result = second_order_determinant(A);
  if (A->rows == 3) {
    for (int i = 0; i < A->columns; i++) {
      index{ 0 , i} ;
    *result += A->matrix[0][i] * minor_of_third_order_matrix(A, index)
      
    }
  }

  return result_code;
}

double second_order_determinant(matrix_t *A) {
  return A->matrix[0][0] * A->matrix[1][1] - A->matrix[0][1] * A->matrix[1][0];
}