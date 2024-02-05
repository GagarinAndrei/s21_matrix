#include <math.h>

#include "s21_matrix.h"
#include "utils.h"

/**
 * Матрица алгебраических дополнений
 * @param A матрица
 * @param result указатель на итоговую матрицу
 * @return 0 - OK
 *         1 - Ошибка, некорректная матрица
 *         2 - Ошибка вычисления (несовпадающие размеры матриц; матрица, для
 *         которой нельзя провести вычисления и т.д.)
 */
int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int result_code = 0;

  if (is_structure_null(A) || !is_correct_matrix(*A) ||
      is_structure_null(result) ||
      s21_create_matrix(A->rows, A->columns, result))
    result_code = 1;
  else if (!is_square_matrix(A))
    result_code = 2;
  if (result_code == 0) {
    matrix_t minor;
    double determinant = 0;
    for (int i = 0; i < A->rows; i++) {
      for (int ii = 0; ii < A->columns; ii++) {
        minor_of_matrix(A, i, ii, &minor);
        s21_determinant(&minor, &determinant);
        result->matrix[i][ii] = pow(-1, i + ii) * determinant;
        s21_remove_matrix(&minor);
      }
    }
  }
  return result_code;
}

/**
 * Минор матрицы
 * @param A матрица
 * @param row строка искомого элемента
 * @param column ряд искомого элемента
 * @param result указатель на итоговую матрицу
 * @return 0 - OK
 *         1 - Ошибка, некорректная матрица
 *         2 - Ошибка вычисления (несовпадающие размеры матриц; матрица, для
 *         которой нельзя провести вычисления и т.д.)
 */
void minor_of_matrix(matrix_t *A, int row, int column, matrix_t *result) {
  int result_code = 0;
  int row_count = 0;
  int column_count = 0;
  if (A->rows == 1) {
    result_code = s21_create_matrix(A->rows, A->columns, result);
    if (0 == result_code) result->matrix[0][0] = A->matrix[0][0];
  } else {
    result_code = s21_create_matrix(A->rows - 1, A->columns - 1, result);
    if (0 == result_code) {
      for (int i = 0; i < A->rows; i++) {
        for (int ii = 0; ii < A->columns; ii++) {
          if (row != i && column != ii) {
            result->matrix[row_count][column_count] = A->matrix[i][ii];
            column_count++;
          }
        }
        if (row != i) {
          row_count++;
        }
        column_count = 0;
      }
    }
  }
  // return result_code;
}
