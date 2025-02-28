#include "s21_matrix.h"

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  int status = OK;

  if (A == NULL || A->matrix == NULL || result == NULL) {
    status = MATRIX_INCORRECT;
  } else if (A->rows != A->columns) {
    status = CALCULATION_ERROR;
  } else {
    double determinant = 0.0;

    if (s21_determinant(A, &determinant) != OK || determinant == 0) {
      status = CALCULATION_ERROR;
    } else {
      matrix_t complements;
      matrix_t transposed;
      if (s21_calc_complements(A, &complements) == OK &&
          s21_transpose(&complements, &transposed) == OK &&
          s21_create_matrix(A->rows, A->columns, result) == OK) {
        for (int i = 0; i < transposed.rows; i++) {
          for (int j = 0; j < transposed.columns; j++) {
            result->matrix[i][j] = transposed.matrix[i][j] / determinant;
          }
        }
      }

      s21_remove_matrix(&complements);
      s21_remove_matrix(&transposed);
    }
  }

  return status;
}
