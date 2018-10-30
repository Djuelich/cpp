#include "SparseMatrix.hpp"


SparseMatrix::SparseMatrix(int rows, int columns)
{
    m_rows = new SparseVector* [rows];
	for(int i = 0; i < rows; i++)
	{
		m_rows[i] = new SparseVector(columns);
	}
}

SparseVector& SparseMatrix::operator[](int row)
{
   return *m_rows[row]; 
}

void SparseMatrix::insert(const int& row, const int& column, const int& value)
{
    m_rows[row]->setElem(column, value);
}

SparseMatrix::~SparseMatrix()
{
   delete m_rows;
}

SparseMatrix& operator=(const SparseMatrix& other)
{
    if (this == &other) 
    {
    return *this;
    }

    m_rows = other.m_rows;
    
    return *this;
}
