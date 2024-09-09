#include "spiral_path.hpp"

namespace spiral {

	sprial_path_clockwise::sprial_path_clockwise(size_t rows, size_t cols, conditional stop_cond, filling_strategy fill_strat) :
		corners_(std::make_shared<corners>(rows, cols)),
		stop_conditional_(stop_cond == nullptr ? std::make_unique<spiral_conditional_clockwise>(rows, cols, corners_) : std::move(stop_cond)),
		filling_strategy_(std::move(fill_strat)),
		matrix_(filling_strategy_->fill(rows, cols))
	{}

	std::vector<int> sprial_path_clockwise::make_path() {
		if (calculated_) {
			return path_;
		}

		if (matrix_.get_rows() == 1) {
			for (size_t j = 0; j < matrix_.get_cols(); j++) {
				path_.emplace_back(matrix_[0][j]);
			}
		} else if (matrix_.get_cols() == 1) {
			for (size_t i = 0; i < matrix_.get_rows(); i++) {
				path_.emplace_back(matrix_[i][0]);
			}
		}

		if (!path_.empty()) {
			return path_;
		}

		path_.emplace_back(matrix_[0][0]);

		while (!stop_conditional_->satisfied()) {
			right();
			down();
			left();
			up();
			pull_corner_points();
		}

		// exceptions of a rule when there is left elements that is not in the path
		if ((matrix_.get_rows() == matrix_.get_cols()) && matrix_.get_rows() % 2 != 0) {
			path_.emplace_back(matrix_[corners_->ul.row][corners_->ul.col]);
		} else if (matrix_.get_rows() == 3 && matrix_.get_cols() != 2) {
			right();
		} else if (matrix_.get_cols() == 3 && matrix_.get_rows() != 2) {
			cur_pos_.col++;
			path_.emplace_back(matrix_[cur_pos_.row][cur_pos_.col]);
			down();
		}

		calculated_ = true;
		return path_;
	}


	void sprial_path_clockwise::up() {
		for (size_t i = cur_pos_.row - 1; i >= corners_->ul.row + 1 && i < SIZE_T_MAX; i--) {
			path_.emplace_back(matrix_[i][corners_->ll.col]);
			cur_pos_ = { i, corners_->ll.col };
		}
	}

	void sprial_path_clockwise::down() {
		for (size_t i = cur_pos_.row + 1; i <= corners_->lr.row; i++) {
			path_.emplace_back(matrix_[i][corners_->ur.col]);
			cur_pos_ = { i, corners_->ur.col };
		}
	}

	void sprial_path_clockwise::left() {
		for (size_t j = cur_pos_.col - 1; j >= corners_->ll.col && j < SIZE_T_MAX; j--) {
			path_.emplace_back(matrix_[corners_->lr.row][j]);
			cur_pos_ = { corners_->lr.row, j };
		}
	}

	void sprial_path_clockwise::right() {
		for (size_t j = cur_pos_.col + 1; j <= corners_->ur.col; j++) {
			path_.emplace_back(matrix_[corners_->ul.row][j]);
			cur_pos_ = { corners_->ul.row, j };
		}
	}

	void sprial_path_clockwise::pull_corner_points() {
		corners_->ul.row++, corners_->ul.col++;
		corners_->ur.row++, corners_->ur.col--;
		corners_->ll.row--, corners_->ll.col++;
		corners_->lr.row--, corners_->lr.col--;
	}

}
