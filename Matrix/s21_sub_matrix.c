#include "s21_matrix.h"

int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int status = OK;

  if (A == NULL || B == NULL || result == NULL || A->matrix == NULL ||
      B->matrix == NULL) {
    status = MATRIX_INCORRECT;
  } else if (A->rows != B->rows || A->columns != B->columns) {
    status = CALCULATION_ERROR;
  } else {
    int result_matrix = s21_create_matrix(A->rows, A->columns, result);
    if (result_matrix == OK) {
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
          result->matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
        }
      }
    }
  }

  return status;
}