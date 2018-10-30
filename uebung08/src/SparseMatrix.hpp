#ifndef SRC_SPARSEMATRIX_HPP_
#define SRC_SPARSEMATRIX_HPP_

#include "SparseVector.hh"


class SparseMatrix
{
    SparseVector** m_rows;

    public:

    /// Builds a sparse rows x columns matrix
    SparseMatrix(int rows, int columns);

    /// Returns the sparse vector at the given row
    SparseVector& operator[](int row);

    /// Inserts the value at given row and column into the matrix
    void insert(const int& row, const int& column, const int& value);

    /// Destructor
    ~SparseMatrix();
    
    SparseMatrix& operator=(const SparseMatrix &b); 

};

#endif
