#include "s21_matrix.h"

/**
 * Обратная матрица
 * @param A исходная матрица
 * @param result указатель на итоговую матрицу
 * @return 0 - OK
 *         1 - Ошибка, некорректная матрица
 *         2 - Ошибка вычисления (несовпадающие размеры матриц; матрица, для
 *         которой нельзя провести вычисления и т.д.)
 */
int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  int result_code = 0;

  if (is_structure_null(A) || !is_correct_matrix(*A) ||
      is_structure_null(result) ||
      s21_create_matrix(A->rows, A->columns, result))
    result_code = 1;
  else if (!is_square_matrix(*A))
    result_code = 2;
  if (result_code == 0) {
    double determinant;
    matrix_t calc_complements_matrix, transpose_matrix;
    s21_determinant(A, &determinant);
    s21_calc_complements(A, &calc_complements_matrix);
    s21_transpose(&calc_complements_matrix, &transpose_matrix);
    s21_mult_number(&transpose_matrix, 1 / determinant, result);
  }

  return result_code;
}
