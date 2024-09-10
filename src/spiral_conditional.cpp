#include "spiral_conditional.hpp"

namespace spiral
{

	SpiralConditionalClockwise::SpiralConditionalClockwise(size_t rows, size_t cols,
	                                                       std::shared_ptr<corners> Corners)
	    : m_Corners(std::move(Corners)),
	      m_Strategy(choose_corner_strategy(rows, cols))
	{
	}

	bool SpiralConditionalClockwise::Satisfied()
	{
		return m_Strategy->IsMet(*m_Corners);
	}

} // namespace spiral
