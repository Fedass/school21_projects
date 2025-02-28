#include "s21_matrix.h"

int s21_transpose(matrix_t *A, matrix_t *result) {
  int status = OK;

  if (A == NULL || A->matrix == NULL || result == NULL) {
    status = MATRIX_INCORRECT;
  } else {
    int result_matrix = s21_create_matrix(A->columns, A->rows, result);
    if (result_matrix == OK) {
      for (int i = 0; i < A->columns; i++) {
        for (int j = 0; j < A->rows; j++) {
          result->matrix[i][j] = A->matrix[j][i];
        }
      }
    }
  }

  return status;
}