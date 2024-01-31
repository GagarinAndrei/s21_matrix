#include "s21_matrix.h"
#include "utils.h"

/**
 * Умножение матрицы на число matrix_t
 * @param A матрица
 * @param number число
 * @param result указатель на итоговую матрицу
 * @return 0 - OK
 *         1 - Ошибка, некорректная матрица
 *         2 - Ошибка вычисления (несовпадающие размеры матриц; матрица, для
 *         которой нельзя провести вычисления и т.д.)
 */
int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  int result_code = 0;
  if (is_structure_null(A) || !is_correct_matrix(*A) ||
      is_structure_null(result))
    result_code = 1;
  else if (!is_eq_matrix_sizes(result, A))
    result_code = 2;
  else {
    for (int i = 0; i < A->rows; i++) {
      for (int ii = 0; ii < A->columns; ii++) {
        result->matrix[i][ii] = A->matrix[i][ii] * number;
      }
    }
  }

  return result_code;
}

/**
 * Умножение матрицы matrix_t
 * @param A первая матрица
 * @param B вторая матрица
 * @param result указатель на итоговую матрицу
 * @return 0 - OK
 *         1 - Ошибка, некорректная матрица
 *         2 - Ошибка вычисления (несовпадающие размеры матриц; матрица, для
 *         которой нельзя провести вычисления и т.д.)
 */
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int result_code = 0;
  if (!is_correct_matrix(*A) || !is_correct_matrix(*B) ||
      is_structure_null(result))
    result_code = 1;
  else if (A->columns != B->rows || A->rows != B->columns ||
           result->rows != A->rows || result->columns != B->columns)
    result_code = 2;
  else {
    for (int i = 0; i < A->rows; i++) {
      for (int ii = 0; ii < B->columns; ii++) {
        result->matrix[i][ii] = 0;
        for (int iii = 0; iii < B->rows; iii++)
          result->matrix[i][ii] += A->matrix[i][iii] * B->matrix[iii][ii];
      }
    }
  }
  return result_code;
}