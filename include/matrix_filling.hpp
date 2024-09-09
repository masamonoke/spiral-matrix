#pragma once

#include <matrix.hpp>

namespace spiral {

	template<typename T>
	class matrix_filling_strategy {
		public:
			virtual ~matrix_filling_strategy() = default;

			virtual matrix2D<T> fill(size_t rows, size_t cols) = 0;
	};

	template<typename T>
	class matrix_filling_sequential : public matrix_filling_strategy<T> {
		public:
			matrix2D<T> fill(size_t rows, size_t cols) override;
	};

}
