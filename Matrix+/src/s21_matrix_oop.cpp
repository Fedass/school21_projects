#include "s21_matrix_oop.h"

using namespace std;

S21Matrix::S21Matrix() {
  rows_ = 3;
  cols_ = 3;
  matrix_ = new double*[rows_];

  for (int i = 0; i < rows_; i++) {
    matrix_[i] = new double[cols_]();
  }
}

S21Matrix::S21Matrix(int rows, int cols) : rows_(rows), cols_(cols) {
  if (rows_ <= 0 || cols <= 0) {
    throw invalid_argument("CreationError: Matrix sizes should be more than 0");
  }
  matrix_ = new double*[rows_];

  for (int i = 0; i < rows_; i++) {
    matrix_[i] = new double[cols_]();
  }
}

S21Matrix::S21Matrix(const S21Matrix& other)
    : S21Matrix(other.rows_, other.cols_) {
  for (int i = 0; i < other.rows_; ++i) {
    for (int j = 0; j < other.cols_; j++) {
      matrix_[i][j] = other.matrix_[i][j];
    }
  }
}

S21Matrix::S21Matrix(S21Matrix&& other) noexcept {
  rows_ = other.rows_;
  cols_ = other.cols_;
  matrix_ = other.matrix_;

  other.rows_ = 0;
  other.cols_ = 0;
  other.matrix_ = nullptr;
}

S21Matrix::~S21Matrix() {
  if (matrix_) {
    for (int i = 0; i < rows_; i++) {
      delete[] matrix_[i];
    }
    delete[] matrix_;
  }
  matrix_ = nullptr;
}

int S21Matrix::GetRows() const { return rows_; }

int S21Matrix::GetCols() const { return cols_; }

void S21Matrix::SetRows(int new_rows) {
  if (new_rows <= 0) {
    throw out_of_range("RoWs of matrix should be more than 0");
  } else if (new_rows != rows_) {
    S21Matrix new_matrix(new_rows, cols_);

    for (int i = 0; i < std::min(rows_, new_rows); i++) {
      for (int j = 0; j < cols_; j++) {
        new_matrix.matrix_[i][j] = matrix_[i][j];
      }
    }

    *this = std::move(new_matrix);
  }
}

void S21Matrix::SetCols(int new_cols) {
  if (new_cols <= 0) {
    throw out_of_range("Cols of matrix should be more than 0");
  } else if (new_cols != cols_) {
    S21Matrix new_matrix(rows_, new_cols);

    for (int i = 0; i < rows_; i++) {
      for (int j = 0; j < std::min(cols_, new_cols); j++) {
        new_matrix.matrix_[i][j] = matrix_[i][j];
      }
    }

    *this = std::move(new_matrix);
  }
}

double& S21Matrix::operator()(int i, int j) {
  if (i < 0 || i >= rows_ || j < 0 || j >= cols_) {
    throw out_of_range(
        "Arguments should be more or equal then 0 and less then"
        "rows_(cols_)");
  } else {
    return matrix_[i][j];
  }
}

S21Matrix& S21Matrix::operator=(const S21Matrix& other) {
  if (this != &other) {
    for (int i = 0; i < rows_; i++) {
      delete[] matrix_[i];
    }
    delete[] matrix_;

    rows_ = other.rows_;
    cols_ = other.cols_;

    matrix_ = new double*[rows_];

    for (int i = 0; i < rows_; i++) {
      matrix_[i] = new double[cols_];
      memcpy(matrix_[i], other.matrix_[i], cols_ * sizeof(double));
    }
  }
  return *this;
}

S21Matrix S21Matrix::operator+(S21Matrix& other) {
  S21Matrix res(*this);
  res.SumMatrix(other);
  return res;
}

S21Matrix S21Matrix::operator-(S21Matrix& other) {
  S21Matrix res(*this);
  res.SubMatrix(other);
  return res;
}

S21Matrix S21Matrix::operator*(S21Matrix& other) {
  S21Matrix res(*this);
  res.MulMatrix(other);
  return res;
}

S21Matrix S21Matrix::operator*(const double num) {
  S21Matrix res(*this);
  res.MulNumber(num);
  return res;
}

bool S21Matrix::operator==(const S21Matrix& other) const {
  return EqMatrix(other);
}

S21Matrix& S21Matrix::operator+=(const S21Matrix& other) {
  this->SumMatrix(other);
  return *this;
}

S21Matrix& S21Matrix::operator-=(const S21Matrix& other) {
  this->SubMatrix(other);
  return *this;
}

S21Matrix& S21Matrix::operator*=(const S21Matrix& other) {
  this->MulMatrix(other);
  return *this;
}

S21Matrix& S21Matrix::operator*=(const double num) {
  this->MulNumber(num);
  return *this;
}

bool S21Matrix::EqMatrix(const S21Matrix& other) const {
  int result = OK;

  if (rows_ <= 0 || cols_ <= 0 || rows_ <= 0 || cols_ <= 0) {
    result = ERROR;
  } else if (rows_ != other.rows_ || cols_ != other.cols_) {
    result = ERROR;
  } else {
    for (int i = 0; i < rows_; i++) {
      for (int j = 0; j < cols_; j++) {
        if (abs(matrix_[i][j] - other.matrix_[i][j]) >= 1e-7) {
          result = ERROR;
        }
      }
    }
  }

  return result;
}

void S21Matrix::SumMatrix(const S21Matrix& other) {
  if (rows_ != other.rows_ || cols_ != other.cols_) {
    throw out_of_range("Incorrect input, matrices should have the same size");
  } else {
    for (int i = 0; i < rows_; i++) {
      for (int j = 0; j < cols_; j++) {
        matrix_[i][j] += other.matrix_[i][j];
      }
    }
  }
}

void S21Matrix::SubMatrix(const S21Matrix& other) {
  if (rows_ != other.rows_ || cols_ != other.cols_) {
    throw out_of_range("Incorrect input, matrices should have the same size");
  } else {
    for (int i = 0; i < rows_; i++) {
      for (int j = 0; j < cols_; j++) {
        matrix_[i][j] -= other.matrix_[i][j];
      }
    }
  }
}

void S21Matrix::MulNumber(const double num) {
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] *= num;
    }
  }
}

void S21Matrix::MulMatrix(const S21Matrix& other) {
  if (cols_ != other.rows_) {
    throw out_of_range("Matrix multiplication error: A.cols must match B.rows");
  }

  S21Matrix temp(rows_, other.cols_);
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < other.cols_; j++) {
      for (int k = 0; k < cols_; k++) {
        temp.matrix_[i][j] += matrix_[i][k] * other.matrix_[k][j];
      }
    }
  }
  *this = move(temp);
}

S21Matrix S21Matrix::Transpose() {
  S21Matrix trans(cols_, rows_);

  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      trans.matrix_[j][i] = matrix_[i][j];
    }
  }

  return trans;
}

S21Matrix S21Matrix::CalcComplements() {
  if (rows_ != cols_) {
    throw std::out_of_range(
        "Matrix determinant error: Matrix should be square");
  }

  S21Matrix res(rows_, cols_);

  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      S21Matrix minor = minor_matrix(i, j);
      double det = minor.Determinant();
      res.matrix_[i][j] = det * ((i + j) % 2 == 0 ? 1 : -1);
    }
  }

  return res;
}

double S21Matrix::Determinant() {
  double result = 0.0;

  if (rows_ != cols_) {
    throw std::out_of_range(
        "Matrix determinant error: Matrix should be square");
  }

  if (rows_ == 1) {
    result = matrix_[0][0];
  } else if (rows_ == 2) {
    result = matrix_[0][0] * matrix_[1][1] - matrix_[0][1] * matrix_[1][0];
  } else {
    for (int j = 0; j < cols_; j++) {
      S21Matrix minor = minor_matrix(0, j);
      double minor_det = minor.Determinant();
      result += matrix_[0][j] * minor_det * ((j % 2 == 0) ? 1 : -1);
    }
  }

  return result;
}

S21Matrix S21Matrix::minor_matrix(int excluded_row, int excluded_col) {
  S21Matrix mat(rows_ - 1, cols_ - 1);

  for (int row = 0, minor_row = 0; row < rows_; row++) {
    if (row == excluded_row) continue;

    for (int col = 0, minor_col = 0; col < cols_; col++) {
      if (col == excluded_col) continue;

      mat.matrix_[minor_row][minor_col] = matrix_[row][col];
      minor_col++;
    }
    minor_row++;
  }

  return mat;
}

S21Matrix S21Matrix::InverseMatrix() {
  if (Determinant() == 0) {
    throw std::out_of_range("Matrix determinant can`t be a zero");
  }

  S21Matrix complements = CalcComplements();
  S21Matrix transpose = complements.Transpose();
  transpose.MulNumber(1 / Determinant());

  return transpose;
}