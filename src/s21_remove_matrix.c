#include "s21_matrix.h"

/**
 * Удаляет структуру matrix_t
 * @param A указатель на матрицу
 */
void s21_remove_matrix(matrix_t *A) {
  if (A && A->matrix) {
    for (int i = 0; i < A->rows; i++) {
      if (A->matrix[i] != NULL) free(A->matrix[i]);
    }
    free(A->matrix);
    A->matrix = NULL;
    A->rows = 0;
    A->columns = 0;
  }
  A->matrix = NULL;
}
