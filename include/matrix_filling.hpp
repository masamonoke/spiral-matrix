#pragma once

#include <matrix.hpp>

namespace spiral
{

	template <typename T>
	class IMatrixFillingStrategy
	{
		public:
			virtual ~IMatrixFillingStrategy() = default;

			virtual Matrix2D<T> Fill(size_t rows, size_t cols) = 0;
	};

	template <typename T>
	class MatrixFillingSequential : public IMatrixFillingStrategy<T>
	{
		public:
			Matrix2D<T> Fill(size_t rows, size_t cols) override;
	};

} // namespace spiral
