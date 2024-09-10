#include "spiral_conditional.hpp"

namespace spiral {

	spiral_conditional_clockwise::spiral_conditional_clockwise(size_t rows, size_t cols, std::shared_ptr<corners> corners) :
		corners_(std::move(corners)), strategy_(choose_corner_strategy(rows, cols)) {}

	bool spiral_conditional_clockwise::satisfied() {
		return strategy_->met(*corners_);
	}

}
