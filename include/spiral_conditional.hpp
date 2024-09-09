#pragma once

#include <functional>

#include "corner_points.hpp"
#include "spiral_strategy.hpp"

namespace spiral {

	struct spiral_conditional {
		virtual ~spiral_conditional() = default;

		virtual bool satisfied() = 0;
	};

	class spiral_conditional_clockwise : public spiral_conditional {
		public:
			spiral_conditional_clockwise(size_t rows, size_t cols, std::shared_ptr<corners> corners);

			bool satisfied() override;

		private:
			std::shared_ptr<const corners> corners_;
			std::unique_ptr<matrix_corner_strategy> strategy_;
	};

}
