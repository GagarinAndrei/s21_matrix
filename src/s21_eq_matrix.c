#include <math.h>

#include "s21_matrix.h"
#include "utils.h"

/**
 * Сравнивает структуры matrix_t
 * @param A первая структура
 * @param B вторая структура
 * @return 0 - не равны
 *				 1 - равны
 *и т.д.)
 */
int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  int result_code = SUCCESS;
  if (is_structure_null(A) || is_structure_null(B) || !is_correct_matrix(*A) ||
      !is_correct_matrix(*B) ||
      !(A->columns == B->columns && A->rows == B->rows)) {
    result_code = FAILURE;
  } else {
    for (int i = 0; i < A->rows; i++) {
      for (int ii = 0; ii < A->columns; ii++) {
        if (fabs(A->matrix[i][ii] - B->matrix[i][ii]) > ACCURACY) {
          result_code = FAILURE;
          break;
        }
      }
    }
  }
  return result_code;
}