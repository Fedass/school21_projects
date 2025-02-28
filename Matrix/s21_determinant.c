#include "s21_matrix.h"

int s21_determinant(matrix_t *A, double *result) {
  int status = OK;
  *result = 0.0;

  if (A == NULL || A->matrix == NULL || result == NULL) {
    status = MATRIX_INCORRECT;
  } else if (A->rows != A->columns) {
    status = CALCULATION_ERROR;
  } else {
    if (A->rows == 1) {
      *result = A->matrix[0][0];
    } else if (A->rows == 2) {
      *result =
          A->matrix[0][0] * A->matrix[1][1] - A->matrix[0][1] * A->matrix[1][0];
    } else {
      *result = 0.0;
      matrix_t minor_matrix;
      for (int j = 0; j < A->columns; j++) {
        int result_matrix =
            s21_create_matrix(A->rows - 1, A->columns - 1, &minor_matrix);

        if (result_matrix == OK) {
          for (int row = 1, minor_row = 0; row < A->rows; row++, minor_row++) {
            for (int col = 0, minor_col = 0; col < A->columns; col++) {
              if (col == j) continue;
              minor_matrix.matrix[minor_row][minor_col] = A->matrix[row][col];
              minor_col++;
            }
          }

          double minor_det = 0.0;
          int result_det = s21_determinant(&minor_matrix, &minor_det);
          if (result_det == OK) {
            *result += A->matrix[0][j] * minor_det * ((j % 2 == 0) ? 1 : -1);
          }

          s21_remove_matrix(&minor_matrix);
        }
      }
    }
  }

  return status;
}
