#include "spiral_path.hpp"

namespace spiral
{

	SpiralPathClockwise::SpiralPathClockwise(size_t rows, size_t cols, Conditional StopCond,
	                                         FillingStrategy FillStrat)
	    : m_Corners(std::make_shared<corners>(rows, cols)),
	      m_StopConditional(StopCond == nullptr
	                            ? std::make_unique<SpiralConditionalClockwise>(rows, cols, m_Corners)
	                            : std::move(StopCond)),
	      m_FillingStrategy(FillStrat == nullptr ? std::make_unique<MatrixFillingSequential<int>>()
	                                             : std::move(FillStrat)),
	      m_Matrix(m_FillingStrategy->Fill(rows, cols))
	{
	}

	std::vector<int> SpiralPathClockwise::MakePath()
	{
		Prelude();

		if (m_isCalculated)
		{
			return m_Path;
		}

		Traverse();
		Aftermath();

		m_isCalculated = true;
		return m_Path;
	}

	void SpiralPathClockwise::Prelude()
	{
		if (m_isCalculated)
		{
			return;
		}

		if (m_Matrix.GetRows() == 0 || m_Matrix.GetCols() == 0)
		{
			m_isCalculated = true;
			return;
		}

		if (m_Matrix.GetRows() == 1)
		{
			for (size_t j = 0; j < m_Matrix.GetCols(); j++)
			{
				m_Path.emplace_back(m_Matrix[0][j]);
			}
		}
		else if (m_Matrix.GetCols() == 1)
		{
			for (size_t i = 0; i < m_Matrix.GetRows(); i++)
			{
				m_Path.emplace_back(m_Matrix[i][0]);
			}
		}

		if (!m_Path.empty())
		{
			m_isCalculated = true;
		}
	}

	void SpiralPathClockwise::Traverse()
	{
		m_Path.emplace_back(m_Matrix[0][0]);

		while (!m_StopConditional->Satisfied())
		{
			Right();
			Down();
			Left();
			Up();
			PullCornerPoints();
		}
	}

	void SpiralPathClockwise::Aftermath()
	{
		// exceptions to a rule when there is left elements that is not appended to the path
		if ((m_Matrix.GetRows() == m_Matrix.GetCols()) && m_Matrix.GetRows() % 2 != 0)
		{
			m_Path.emplace_back(m_Matrix[m_Corners->ul.row][m_Corners->ul.col]);
		}
		else if (m_Matrix.GetRows() == 3 && m_Matrix.GetCols() != 2)
		{
			Right();
		}
		else if (m_Matrix.GetCols() == 3 && m_Matrix.GetRows() != 2)
		{
			m_CurPos.col++;
			m_Path.emplace_back(m_Matrix[m_CurPos.row][m_CurPos.col]);
			Down();
		}
	}

	void SpiralPathClockwise::Up()
	{
		for (size_t i = m_CurPos.row - 1; i >= m_Corners->ul.row + 1 && i < SIZE_T_MAX; i--)
		{
			m_Path.emplace_back(m_Matrix[i][m_Corners->ll.col]);
			m_CurPos = { i, m_Corners->ll.col };
		}
	}

	void SpiralPathClockwise::Down()
	{
		for (size_t i = m_CurPos.row + 1; i <= m_Corners->lr.row; i++)
		{
			m_Path.emplace_back(m_Matrix[i][m_Corners->ur.col]);
			m_CurPos = { i, m_Corners->ur.col };
		}
	}

	void SpiralPathClockwise::Left()
	{
		for (size_t j = m_CurPos.col - 1; j >= m_Corners->ll.col && j < SIZE_T_MAX; j--)
		{
			m_Path.emplace_back(m_Matrix[m_Corners->lr.row][j]);
			m_CurPos = { m_Corners->lr.row, j };
		}
	}

	void SpiralPathClockwise::Right()
	{
		for (size_t j = m_CurPos.col + 1; j <= m_Corners->ur.col; j++)
		{
			m_Path.emplace_back(m_Matrix[m_Corners->ul.row][j]);
			m_CurPos = { m_Corners->ul.row, j };
		}
	}

	void SpiralPathClockwise::PullCornerPoints()
	{
		m_Corners->ul.row++, m_Corners->ul.col++;
		m_Corners->ur.row++, m_Corners->ur.col--;
		m_Corners->ll.row--, m_Corners->ll.col++;
		m_Corners->lr.row--, m_Corners->lr.col--;
	}

} // namespace spiral
