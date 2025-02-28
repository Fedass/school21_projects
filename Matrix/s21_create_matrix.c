#include "s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  int status = OK;

  if (rows <= 0 || columns <= 0 || result == NULL) {
    status = MATRIX_INCORRECT;
  } else {
    result->rows = rows;
    result->columns = columns;
    result->matrix = NULL;

    result->matrix = (double **)calloc(rows, sizeof(double *));
    if (result->matrix == NULL) {
      result->rows = 0;
      result->columns = 0;
      status = MATRIX_INCORRECT;
    } else {
      for (int i = 0; i < rows; i++) {
        result->matrix[i] = (double *)calloc(columns, sizeof(double));
      }
    }
  }

  return status;
}