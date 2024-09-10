#pragma once

#include <gtest/gtest.h>

#include "spiral_path.hpp"

class MatrixTest : public ::testing::Test{
	protected:
		void SetUp(size_t rows, size_t cols) {
			spiral::SpiralPathClockwise SpiralPath(rows, cols);
			m_Path = SpiralPath.MakePath();
		}

		void Test(const std::vector<int>& expected) const {
			ASSERT_EQ(m_Path, expected);
		}

	private:
		std::vector<int> m_Path;
};
