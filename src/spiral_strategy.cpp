#include "spiral_strategy.hpp"

#include <memory>
#include <map>
#include <cassert>

namespace spiral {

	bool matrix_corner_strategy_nxn::met(const corners& corners) {
		if (rows() % 2 != 0) {
			return corners.ul == corners.ur && corners.ll == corners.lr;
		}
		return corners.ul.col > corners.ur.col;
	}

	bool matrix_corner_strategy_3xn_or_nx3::met(const corners& corners) {
			if (rows() == 3) {
				return corners.ul == corners.ll;
			}
			return corners.ul == corners.ur;
	}

	bool matrix_corner_strategy_mxn::met(const corners& corners) {
		if (rows() < cols()) {
			return corners.ll.row < corners.ul.row;
		}
		return corners.ul.col > corners.ur.col;
	}

	using predicate = std::function<bool(size_t, size_t)>;
	using strategy = std::function<std::unique_ptr<matrix_corner_strategy>(size_t, size_t)>;
	using pairs = std::vector<std::pair<predicate, strategy>>;

	std::unique_ptr<matrix_corner_strategy> choose_corner_strategy(size_t rows, size_t cols) {
		std::unique_ptr<matrix_corner_strategy> strategy;

		if (rows == cols) {
			strategy = std::make_unique<matrix_corner_strategy_nxn>(rows, cols);
		} else if (rows == 3 || cols == 3) {
			strategy = std::make_unique<matrix_corner_strategy_3xn_or_nx3>(rows, cols);
		} else {
			strategy = std::make_unique<matrix_corner_strategy_mxn>(rows, cols);
		}

		return strategy;
	}

}
