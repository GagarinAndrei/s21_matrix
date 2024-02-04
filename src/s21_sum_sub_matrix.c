#include "s21_matrix.h"
// #include "utils.h"

#define PLUS 0
#define MINUS 1

/**
 * Суммирование или разность матриц matrix_t
 * @param A первая матрица
 * @param B вторая матрица
 * @param result указатель на итоговую матрицу
 * @param operation знак операции: 0 - "+", 1 - "-"
 * @return 0 - OK
 *         1 - Ошибка, некорректная матрица
 *         2 - Ошибка вычисления (несовпадающие размеры матриц; матрица, для
 *         которой нельзя провести вычисления и т.д.)
 */
int sum_or_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result,
                      int operation) {
  int result_code = 0;
  if (!is_correct_matrix(*A) || !is_correct_matrix(*B) ||
      is_structure_null(result) ||
      s21_create_matrix(A->rows, A->columns, result))
    result_code = 1;
  if (!is_eq_matrix_sizes(A, B)) result_code = 2;
  if (result_code == 0) {
    for (int i = 0; i < A->rows; i++) {
      for (int ii = 0; ii < A->columns; ii++) {
        result->matrix[i][ii] = (operation)
                                    ? A->matrix[i][ii] - B->matrix[i][ii]
                                    : A->matrix[i][ii] + B->matrix[i][ii];
      }
    }
  }

  return result_code;
}

/**
 * Суммирование матриц matrix_t
 * @param A первая матрица
 * @param B вторая матрица
 * @param result указатель на итоговую матрицу
 * @return 0 - OK
 *         1 - Ошибка, некорректная матрица
 *         2 - Ошибка вычисления (несовпадающие размеры матриц; матрица, для
 *         которой нельзя провести вычисления и т.д.)
 */
int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  return sum_or_sum_matrix(A, B, result, PLUS);
}

/**
 * Разность матриц matrix_t
 * @param A первая матрица
 * @param B вторая матрица
 * @param result указатель на итоговую матрицу
 * @return 0 - OK
 *         1 - Ошибка, некорректная матрица
 *         2 - Ошибка вычисления (несовпадающие размеры матриц; матрица, для
 *         которой нельзя провести вычисления и т.д.)
 */
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  return sum_or_sum_matrix(A, B, result, MINUS);
}
