#pragma once

#include "corner_points.hpp"

#include <memory>

namespace spiral {

	class matrix_corner_strategy {
		public:
			matrix_corner_strategy(size_t rows, size_t cols) : rows_(rows), cols_(cols) {}
			virtual ~matrix_corner_strategy() = default;

			virtual bool met(const corners& corners) = 0;

			[[nodiscard]] size_t rows() const {
				return rows_;
			}

			[[nodiscard]] size_t cols() const {
				return cols_;
			}

		private:
			size_t rows_;
			size_t cols_;
	};

	class matrix_corner_strategy_nxn : public matrix_corner_strategy {
		public:
			matrix_corner_strategy_nxn(size_t rows, size_t cols) : matrix_corner_strategy(rows, cols) {}

			bool met(const corners& corners) override;
	};

	class matrix_corner_strategy_3xn_or_nx3: public matrix_corner_strategy {
		public:
			matrix_corner_strategy_3xn_or_nx3(size_t rows, size_t cols) : matrix_corner_strategy(rows, cols) {}

			bool met(const corners& corners) override;
	};

	class matrix_corner_strategy_mxn: public matrix_corner_strategy {
		public:
			matrix_corner_strategy_mxn(size_t rows, size_t cols) : matrix_corner_strategy(rows, cols) {}

			bool met(const corners& corners) override;
	};

	std::unique_ptr<matrix_corner_strategy> choose_strategy(size_t rows, size_t cols);

}
