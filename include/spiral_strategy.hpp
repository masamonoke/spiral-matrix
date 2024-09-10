#pragma once

#include "corner_points.hpp"

#include <memory>

namespace spiral
{

	class MatrixCornerStrategy
	{
		public:
			MatrixCornerStrategy(size_t rows, size_t cols);
			virtual ~MatrixCornerStrategy() = default;

			virtual bool IsMet(const corners& Corners) = 0;

			[[nodiscard]] size_t Rows() const
			{
				return m_rows;
			}

			[[nodiscard]] size_t Cols() const
			{
				return m_cols;
			}

		private:
			size_t m_rows;
			size_t m_cols;
	};

	class MatrixCornerStrategyNxN : public MatrixCornerStrategy
	{
		public:
			MatrixCornerStrategyNxN(size_t rows, size_t cols);

			bool IsMet(const corners& Corners) override;
	};

	class MatrixCornerStrategy3xNOrNx3 : public MatrixCornerStrategy
	{
		public:
			MatrixCornerStrategy3xNOrNx3(size_t rows, size_t cols);

			bool IsMet(const corners& Corners) override;
	};

	class MatrixCornerStrategyMxN : public MatrixCornerStrategy
	{
		public:
			MatrixCornerStrategyMxN(size_t rows, size_t cols);

			bool IsMet(const corners& Corners) override;
	};

	std::unique_ptr<MatrixCornerStrategy> choose_corner_strategy(size_t rows, size_t cols);

} // namespace spiral
