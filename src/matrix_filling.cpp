#include "matrix_filling.hpp"

namespace spiral
{

	template class MatrixFillingSequential<int>;

	template <typename T>
	Matrix2D<T> MatrixFillingSequential<T>::Fill(size_t rows, size_t cols)
	{
		T           counter = 1;
		Matrix2D<T> m(rows, cols);
		for (size_t i = 0; i < m.GetRows(); i++)
		{
			for (size_t j = 0; j < m.GetCols(); j++)
			{
				m[i][j] = counter++;
			}
		}
		return m;
	}

} // namespace spiral
