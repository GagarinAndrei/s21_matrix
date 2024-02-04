#include "s21_matrix.h"
#include "utils.h"

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
  if (is_structure_null(A) || is_structure_null(result)) return 1;
  if (!is_correct_matrix(*A)) return 1;
  if (!is_square_matrix(A)) return 2;

  int result_code = 0;
  double determinant;
  result_code = s21_determinant(A, &determinant);
  if (result_code || 0 == determinant) {
    result_code = 2;
  } else {
    matrix_t calc_complements_matrix, transpose_matrix;
    result_code = s21_calc_complements(A, &calc_complements_matrix);
    if (0 == result_code)
      result_code = s21_transpose(&calc_complements_matrix, &transpose_matrix);
    if (0 == result_code)
      result_code = s21_mult_number(&transpose_matrix, 1 / determinant, result);

    s21_remove_matrix(&calc_complements_matrix);
    s21_remove_matrix(&transpose_matrix);
  }
  return result_code;
}
