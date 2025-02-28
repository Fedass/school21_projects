#include "s21_matrix.h"

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int status = OK;

  if (A == NULL || A->matrix == NULL || result == NULL) {
    status = MATRIX_INCORRECT;
  } else if (A->rows != A->columns) {
    status = CALCULATION_ERROR;
  } else {
    int result_matrix = s21_create_matrix(A->rows, A->columns, result);
    if (result_matrix == OK) {
      matrix_t minor_matrix;

      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
          result_matrix =
              s21_create_matrix(A->rows - 1, A->columns - 1, &minor_matrix);

          if (result_matrix == OK) {
            int minor_row = 0, minor_col;
            for (int row = 0; row < A->rows; row++) {
              if (row == i) continue;
              minor_col = 0;
              for (int col = 0; col < A->columns; col++) {
                if (col == j) continue;
                minor_matrix.matrix[minor_row][minor_col] = A->matrix[row][col];
                minor_col++;
              }
              minor_row++;
            }

            double determinant = 0.0;
            int result_det = s21_determinant(&minor_matrix, &determinant);
            if (result_det == OK) {
              result->matrix[i][j] = determinant * ((i + j) % 2 == 0 ? 1 : -1);
            }
          }
          s21_remove_matrix(&minor_matrix);
        }
      }
    }
  }

  return status;
}
