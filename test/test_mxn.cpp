#include <gtest/gtest.h>

#include "spiral_path.hpp"

TEST(mxnMatrix, matrix3x2) {
	spiral::sprial_path_clockwise p(3, 2);
	auto path = p.make_path();
	const std::vector<int> expected {
		1, 2, 4, 6, 5, 3
	};

	ASSERT_EQ(path, expected);
}

TEST(mxnMatrix, matrix2x3) {
	spiral::sprial_path_clockwise p(2, 3);
	auto path = p.make_path();
	const std::vector<int> expected {
		1, 2, 3, 6, 5, 4
	};

	ASSERT_EQ(path, expected);
}

TEST(mxnMatrix, matrix3x4) {
	spiral::sprial_path_clockwise p(3, 4);
	auto path = p.make_path();
	const std::vector<int> expected {
		1, 2, 3, 4, 8, 12, 11, 10, 9, 5, 6, 7
	};

	ASSERT_EQ(path, expected);
}

TEST(mxnMatrix, matrix4x3) {
	spiral::sprial_path_clockwise p(4, 3);
	auto path = p.make_path();
	const std::vector<int> expected {
		1, 2, 3, 6, 9, 12, 11, 10, 7, 4, 5, 8
	};

	ASSERT_EQ(path, expected);
}

TEST(mxnMatrix, matrix4x5) {
	spiral::sprial_path_clockwise p(4, 5);
	auto path = p.make_path();
	const std::vector<int> expected {
		1, 2, 3, 4, 5, 10, 15, 20, 19, 18, 17, 16, 11, 6, 7, 8, 9, 14, 13, 12
	};

	ASSERT_EQ(path, expected);
}

TEST(mxnMatrix, matrix5x4) {
	spiral::sprial_path_clockwise p(5, 4);
	auto path = p.make_path();
	const std::vector<int> expected {
		1, 2, 3, 4, 8, 12, 16, 20, 19, 18, 17, 13, 9, 5, 6, 7, 11, 15, 14, 10
	};

	ASSERT_EQ(path, expected);
}

TEST(mxnMatrix, matrix1x4) {
	spiral::sprial_path_clockwise p(1, 4);
	auto path = p.make_path();
	const std::vector<int> expected {
		1, 2, 3, 4
	};

	ASSERT_EQ(path, expected);
}


TEST(mxnMatrix, matrix4x1) {
	spiral::sprial_path_clockwise p(4, 1);
	auto path = p.make_path();
	const std::vector<int> expected {
		1, 2, 3, 4
	};

	ASSERT_EQ(path, expected);
}

int main(int argc, char** argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}

