#pragma once

#include <cstddef>

namespace spiral
{

	template <typename T>
	struct matrix_pos
	{
		T row;
		T col;

		bool operator==(const matrix_pos<T>& other) const
		{
			return (row == other.row) && (col == other.col);
		}
	};

	struct corners
	{
		corners(size_t rows, size_t cols)
			: ul{ 0, 0 },
			  ur{ 0, cols - 1 },
			  ll{ rows - 1, 0 },
			  lr{ rows - 1, cols - 1 }
		{
		}

		matrix_pos<size_t> ul; // upper left
		matrix_pos<size_t> ur; // upper right
		matrix_pos<size_t> ll; // lower left
		matrix_pos<size_t> lr; // lower right
	};

} // namespace spiral
