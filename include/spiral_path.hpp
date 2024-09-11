#pragma once

#include "corner_points.hpp"
#include "matrix.hpp"
#include "matrix_filling.hpp"
#include "spiral_conditional.hpp"

namespace spiral
{

	class ISpiralPath
	{
		public:
			virtual ~ISpiralPath() = default;

			virtual std::vector<int> MakePath() = 0;
	};

	using Conditional     = std::unique_ptr<ISpiralConditional>;
	using FillingStrategy = std::unique_ptr<IMatrixFillingStrategy<int>>;

	// General idea of this solution is to set corner points in [0, 0], [0, cols - 1], [rows - 1, 0], [rows - 1,
	// cols - 1] and then to move them to center after each circle run and check stop condition. As the name implies
	// this is clockwise order path solution.
	class SpiralPathClockwise : public ISpiralPath
	{
		public:
			SpiralPathClockwise(size_t rows, size_t cols, Conditional StopCond = nullptr,
			                    FillingStrategy FillStrat = std::make_unique<MatrixFillingSequential<int>>());

			std::vector<int> MakePath() override;

		private:
			std::vector<int>                             m_Path;
			bool                                         m_isCalculated = false;
			matrix_pos<size_t>                           m_CurPos{ 0, 0 };
			std::shared_ptr<corners>                     m_Corners;
			std::unique_ptr<ISpiralConditional>          m_StopConditional;
			std::unique_ptr<IMatrixFillingStrategy<int>> m_FillingStrategy;
			Matrix2D<int>                                m_Matrix;

			void Up();
			void Down();
			void Left();
			void Right();
			void PullCornerPoints();

			void Prelude();
			void Traverse();
			void Aftermath();
	};

} // namespace spiral
