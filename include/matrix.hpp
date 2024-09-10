#pragma once

#include <vector>

namespace spiral
{

	template <typename T>
	class Matrix2D
	{
		using mat = std::vector<std::vector<T>>;

		public:
			Matrix2D(size_t rows, size_t cols)
			    : m_Matrix(rows, std::vector<T>(cols, 0)),
			      m_rows(rows),
			      m_cols(cols)
			{
			}

			std::vector<T>& operator[](size_t row)
			{
				return m_Matrix[row];
			}

			const std::vector<T>& operator[](size_t row) const
			{
				return m_Matrix[row];
			}

			[[nodiscard]] size_t GetRows() const
			{
				return m_rows;
			}

			[[nodiscard]] size_t GetCols() const
			{
				return m_cols;
			}

		private:
			mat    m_Matrix;
			size_t m_rows;
			size_t m_cols;
	};

} // namespace spiral
