#include "Matrix.h"
#include <iostream>
#include <array>

Matrix::Matrix(int nRows, int nCols) : row(nRows), col(nCols) {
    matrix = new double *[row];
    for (int i = 0; i < row; i++) {
        matrix[i] = new double[col];
        for (int j = 0; j < col; j++) {
            matrix[i][j] = 0.0;
        }
    }
}

Matrix::~Matrix() {
    delete matrix;
}

Matrix::Matrix(const Matrix &other) : row(other.row), col(other.col) {
    std::cout << "[Copy Constructor]" << std::endl;
    matrix = new double *[row];
    for (int i = 0; i < row; i++) {
        matrix[i] = new double[col];
        for (int j = 0; j < col; j++) {
            matrix[i][j] = other.matrix[i][j];
        }
    }
}

Matrix::Matrix(Matrix &&other) noexcept: row(other.row), col(other.col), matrix(other.matrix) {
    std::cout << "[Move Constructor]" << std::endl;
    other.row = 0;
    other.col = 0;
    other.matrix = nullptr;
}

Matrix &Matrix::operator=(const Matrix &other) {
    std::cout << "[Copy Assignment]" << std::endl;
    if (this != &other) {
        row = other.row;
        col = other.col;
        matrix = new double *[row];
        for (int i = 0; i < row; ++i) {
            matrix[i] = new double[col];
            for (int j = 0; j < col; ++j) {
                matrix[i][j] = other.matrix[i][j];
            }
        }
    }

    return *this;
}

Matrix &Matrix::operator=(Matrix &&other) noexcept {
    std::cout << "[Move Assignment]" << std::endl;
    if (this != &other) {
        row = other.row;
        col = other.col;
        matrix = other.matrix;
    }

    return *this;
}