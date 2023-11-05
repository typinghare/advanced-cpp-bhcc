#ifndef ADVANCED_CPP_BHCC_MATRIX_H
#define ADVANCED_CPP_BHCC_MATRIX_H

/**
 * @brief Dynamic 2D double array.
 */
class Matrix {
public:
    /**
     * @brief Creates a matrix.
     * @param nRows The number of rows.
     * @param nCols The number of columns.
     */
    Matrix(int nRows, int nCols);

    /**
     * @brief Destructor.
     */
    ~Matrix();

    /**
     * @brief Copy constructor.
     * @param other Other matrix to copy.
     */
    Matrix(const Matrix &other);

    /**
     * @brief Move constructor.
     */
    Matrix(Matrix &&other) noexcept;

    /**
     * @brief Copy assignment operator.
     * @param other The other matrix to copy.
     * @return
     */
    Matrix &operator=(const Matrix &other);

    /**
     * @brief Move assignment operator.
     * @param other The other matrix to move.
     */
    Matrix &operator=(Matrix &&other) noexcept;

private:
    int row;
    int col;
    double **matrix;
};

#endif
