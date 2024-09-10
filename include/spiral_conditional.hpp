#pragma once

#include <functional>

#include "corner_points.hpp"
#include "spiral_strategy.hpp"

namespace spiral
{

	class ISpiralConditional
	{
		public:
			virtual ~ISpiralConditional() = default;

			virtual bool Satisfied() = 0;
	};

	class SpiralConditionalClockwise : public ISpiralConditional
	{
		public:
			SpiralConditionalClockwise(size_t rows, size_t cols, std::shared_ptr<corners> Corners);

			bool Satisfied() override;

		private:
			std::shared_ptr<const corners>        m_Corners;
			std::unique_ptr<MatrixCornerStrategy> m_Strategy;
	};

} // namespace spiral
