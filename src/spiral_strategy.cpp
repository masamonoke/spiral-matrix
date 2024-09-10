#include "spiral_strategy.hpp"

#include <cassert>
#include <map>
#include <memory>

namespace spiral
{

	MatrixCornerStrategy::MatrixCornerStrategy(size_t rows, size_t cols) : m_rows(rows), m_cols(cols) {}

	MatrixCornerStrategyNxN::MatrixCornerStrategyNxN(size_t rows, size_t cols) : MatrixCornerStrategy(rows, cols) {}

	MatrixCornerStrategy3xNOrNx3::MatrixCornerStrategy3xNOrNx3(size_t rows, size_t cols)
	    : MatrixCornerStrategy(rows, cols)
	{
	}

	MatrixCornerStrategyMxN::MatrixCornerStrategyMxN(size_t rows, size_t cols) : MatrixCornerStrategy(rows, cols) {}

	bool MatrixCornerStrategyNxN::IsMet(const corners& Corners)
	{
		if (Rows() % 2 != 0)
		{
			return Corners.ul == Corners.ur && Corners.ll == Corners.lr;
		}
		return Corners.ul.col > Corners.ur.col;
	}

	bool MatrixCornerStrategy3xNOrNx3::IsMet(const corners& Corners)
	{
		if (Rows() == 3)
		{
			return Corners.ul == Corners.ll;
		}
		return Corners.ul == Corners.ur;
	}

	bool MatrixCornerStrategyMxN::IsMet(const corners& Corners)
	{
		if (Rows() < Cols())
		{
			return Corners.ll.row < Corners.ul.row;
		}
		return Corners.ul.col > Corners.ur.col;
	}

	std::unique_ptr<MatrixCornerStrategy> choose_corner_strategy(size_t rows, size_t cols)
	{
		std::unique_ptr<MatrixCornerStrategy> Strategy;

		if (rows == cols)
		{
			Strategy = std::make_unique<MatrixCornerStrategyNxN>(rows, cols);
		}
		else if (rows == 3 || cols == 3)
		{
			Strategy = std::make_unique<MatrixCornerStrategy3xNOrNx3>(rows, cols);
		}
		else
		{
			Strategy = std::make_unique<MatrixCornerStrategyMxN>(rows, cols);
		}

		return Strategy;
	}

} // namespace spiral
