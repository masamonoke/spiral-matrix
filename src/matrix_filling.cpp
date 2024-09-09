#include "matrix_filling.hpp"

namespace spiral {

	template class matrix_filling_sequential<int>;

	template<typename T>
	matrix2D<T> matrix_filling_sequential<T>::fill(size_t rows, size_t cols) {
		T counter = 1;
		matrix2D<T> m(rows, cols);
		for (size_t i = 0; i < m.get_rows(); i++) {
			for (size_t j = 0; j < m.get_cols(); j++) {
				m[i][j] = counter++;
			}
		}
		return m;
	}

}
