#pragma once

#include <vector>

namespace spiral {

	template<typename T>
	class matrix2D {
		using mat = std::vector<std::vector<T>>;

		public:
			matrix2D(size_t rows, size_t cols) : matrix_(rows, std::vector<T>(cols, 0)), rows_(rows), cols_(cols) {}

			std::vector<T>& operator[](size_t row) {
				return matrix_[row];
			}

			const std::vector<T>& operator[](size_t row) const {
				return matrix_[row];
			}

			[[nodiscard]] size_t get_rows() const {
				return rows_;
			}

			[[nodiscard]] size_t get_cols() const {
				return cols_;
			}

		private:
			mat matrix_;
			size_t rows_;
			size_t cols_;
	};

}
