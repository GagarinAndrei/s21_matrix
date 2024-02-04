// #include <stdio.h>
// #include <stdlib.h>
// #include <time.h>

// #include "s21_matrix.h"
// #include "utils.h"

// int main() {
//   matrix_t A;
//   matrix_t result;
//   double det_result;

//   // srand(time(NULL));

//   s21_create_matrix(3, 3, &A);
//   // for (int i = 0; i < A.rows; i++) {
//   //   for (int ii = 0; ii < A.columns; ii++) {
//   //     A.matrix[i][ii] = rand() % 10;
//   //   }
//   // }
//   A.matrix[0][0] = 1;
//   A.matrix[1][0] = 4;
//   A.matrix[2][0] = 5;
//   A.matrix[0][1] = 2;
//   A.matrix[1][1] = 4;
//   A.matrix[2][1] = 2;
//   A.matrix[0][2] = 3;
//   A.matrix[1][2] = 2;
//   A.matrix[2][2] = 1;

//   print_matrix(A);
//   s21_determinant(&A, &det_result);
//   printf("DET = %f\n", det_result);

//   s21_calc_complements(&A, &result);
//   print_matrix(result);

//   s21_remove_matrix(&A);
//   s21_remove_matrix(&result);

//   return 0;
// }
