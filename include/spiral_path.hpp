#pragma once

#include "spiral_conditional.hpp"
#include "matrix.hpp"
#include "corner_points.hpp"
#include "matrix_filling.hpp"

namespace spiral {

	class spiral_path {
		public:
			virtual ~spiral_path() = default;

			virtual std::vector<int> make_path() = 0;

	};

	using conditional = std::unique_ptr<spiral_conditional>;
	using filling_strategy = std::unique_ptr<matrix_filling_strategy<int>>;

	// General idea of this solution is to set corner points in [0, 0], [0, cols - 1], [rows - 1, 0], [rows - 1, cols - 1]
	// and then to move them to center after each circle run and check stop condition.
	// As the name implies this is clockwise order path solution.
	class sprial_path_clockwise : public spiral_path {
		public:
			sprial_path_clockwise(size_t rows, size_t cols,
				conditional stop_cond  = nullptr, // stop_cond ctr depends on rows, cols and corners_ and is no way to default init here
				filling_strategy fill_strat = std::make_unique<matrix_filling_sequential<int>>());

			std::vector<int> make_path() override;

		private:
			std::vector<int> path_;
			bool calculated_ = false;
			matrix_pos<size_t> cur_pos_ { 0, 0 };
			std::shared_ptr<corners> corners_;
			std::unique_ptr<spiral_conditional> stop_conditional_;
			std::unique_ptr<matrix_filling_strategy<int>> filling_strategy_;
			matrix2D<int> matrix_;

			void up();
			void down();
			void left();
			void right();
			void pull_corner_points();
	};

}
