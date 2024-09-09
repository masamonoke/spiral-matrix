#include <gtest/gtest.h>

#include "spiral_path.hpp"

TEST(squareMatrix, matrix3x3) {
	spiral::sprial_path_clockwise p(3, 3);
	auto path = p.make_path();
	const std::vector<int> expected {
		1, 2, 3, 6, 9, 8, 7, 4, 5
	};

	ASSERT_EQ(path, expected);
}

TEST(squareMatrix, matrix4x4) {
	spiral::sprial_path_clockwise p(4, 4);
	auto path = p.make_path();
	const std::vector<int> expected {
		1, 2, 3, 4, 8, 12, 16, 15, 14, 13, 9, 5, 6, 7, 11, 10
	};

	ASSERT_EQ(path, expected);
}

TEST(squareMatrix, matrix10x10) {
	spiral::sprial_path_clockwise p(10, 10);
	auto path = p.make_path();
	const std::vector<int> expected {
		1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
		20, 30, 40, 50, 60, 70, 80, 90, 100,
		99, 98, 97, 96, 95, 94, 93, 92, 91,
		81, 71, 61, 51, 41, 31, 21, 11,
		12, 13, 14, 15, 16, 17, 18, 19,
		29, 39, 49, 59, 69, 79, 89,
		88, 87, 86, 85, 84, 83, 82,
		72, 62, 52, 42, 32, 22,
		23, 24, 25, 26, 27, 28,
		38, 48, 58, 68, 78,
		77, 76, 75, 74, 73,
		63, 53, 43, 33,
		34, 35, 36, 37,
		47, 57, 67,
		66, 65, 64,
		54, 44,
		45, 46,
		56,
		55
	};

	ASSERT_EQ(path, expected);
}

TEST(squareMatrix, matrix9x9) {
	spiral::sprial_path_clockwise p(9, 9);
	auto path = p.make_path();
	const std::vector<int> expected {
		1, 2, 3, 4, 5, 6, 7, 8, 9,
		18, 27, 36, 45, 54, 63, 72, 81,
		80, 79, 78, 77, 76, 75, 74, 73,
		64, 55, 46, 37, 28, 19, 10,
		11, 12, 13, 14, 15, 16, 17,
		26, 35, 44, 53, 62, 71,
		70, 69, 68, 67, 66, 65,
		56, 47, 38, 29,
		20, 21, 22, 23, 24, 25,
		34, 43, 52, 61,
		60, 59, 58, 57,
		48, 39, 30,
		31, 32, 33,
		42, 51,
		50, 49,
		40,
		41
	};

	ASSERT_EQ(path, expected);
}

TEST(squareMatrix, matrix2x2) {
	spiral::sprial_path_clockwise p(2, 2);
	auto path = p.make_path();
	const std::vector<int> expected {
		1, 2, 4, 3
	};

	ASSERT_EQ(path, expected);
}

int main(int argc, char** argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
