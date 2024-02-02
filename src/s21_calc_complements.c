
#include <stdio.h>

#include "s21_matrix.h"
#include "utils.h"

/**
 * Матрица алгебоаических дополнений
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
      is_structure_null(result))
    result_code = 1;
  else if (is_square_matrix(*A) || !is_eq_matrix_sizes(result, A))
    result_code = 2;
  
  

  return result_code;
}

/**
 * Минор матрицы
 * @param A матрица
 * @param result указатель на итоговую матрицу
 * @return 0 - OK
 *         1 - Ошибка, некорректная матрица
 *         2 - Ошибка вычисления (несовпадающие размеры матриц; матрица, для
 *         которой нельзя провести вычисления и т.д.)
 */
double matrix_minor(matrix_t *A, element_index index) {
  return (A->rows)? minor_of_second_order_matrix(A) : minor_of_third_order_matrix(A, index);
}

double minor_of_third_order_matrix(matrix_t *A, element_index index) {
  double minor;

  int row_count = 0;
  int column_count = 0;
  matrix_t tmp_matrix;
  s21_create_matrix(A->rows - 1, A->columns - 1, &tmp_matrix);

  for (int i = 0; i < A->rows; i++) {
    for (int ii = 0; ii < A->columns; ii++) {
      if (index.row != i && index.column != ii) {
        tmp_matrix.matrix[row_count][column_count] = A->matrix[i][ii];
        column_count++;
      }
    }
    if (index.row != i) {
      row_count++;
    }
    column_count = 0;
  }

  minor = minor_of_second_order_matrix(&tmp_matrix);
  s21_remove_matrix(&tmp_matrix);

  return minor;
}

double minor_of_second_order_matrix(matrix_t *A) {
  double minor;
  minor = A->matrix[0][0] * A->matrix[1][1] - A->matrix[0][1] * A->matrix[1][0];
  return minor;
}

// void gauss_method(matrix_t *A) {}