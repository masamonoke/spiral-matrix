#include "matrix_test.hpp"

namespace {
	class MxNMatrixTest : public MatrixTest {
	};
}

TEST_F(MxNMatrixTest, matrix3x2)
{
	SetUp(3, 2);
	Test({1, 2, 4, 6, 5, 3});
}

TEST_F(MxNMatrixTest, matrix2x3)
{
	SetUp(2, 3);
	Test({ 1, 2, 3, 6, 5, 4 });
}

TEST_F(MxNMatrixTest, matrix3x4)
{
	SetUp(3, 4);
	Test({ 1, 2, 3, 4, 8, 12, 11, 10, 9, 5, 6, 7 });
}

TEST_F(MxNMatrixTest, matrix4x3)
{
	SetUp(4, 3);
	Test({ 1, 2, 3, 6, 9, 12, 11, 10, 7, 4, 5, 8 });
}

TEST_F(MxNMatrixTest, matrix4x5)
{
	SetUp(4, 5);
	Test({ 1, 2, 3, 4, 5, 10, 15, 20, 19, 18, 17, 16, 11, 6, 7, 8, 9, 14, 13, 12 });
}

TEST_F(MxNMatrixTest, matrix5x4)
{
	SetUp(5, 4);
	Test({ 1, 2, 3, 4, 8, 12, 16, 20, 19, 18, 17, 13, 9, 5, 6, 7, 11, 15, 14, 10 });
}

TEST_F(MxNMatrixTest, matrix1x4)
{
	SetUp(1, 4);
	Test({ 1, 2, 3, 4 });
}

TEST_F(MxNMatrixTest, matrix4x1)
{
	SetUp(4, 1);
	Test({ 1, 2, 3, 4 });
}

TEST_F(MxNMatrixTest, matrix0x5)
{
	SetUp(0, 5);
	Test({});
}

TEST_F(MxNMatrixTest, matrix5x0)
{
	SetUp(5, 0);
	Test({});
}

TEST_F(MxNMatrixTest, matrix0x0)
{
	SetUp(0, 0);
	Test({});
}

int main(int argc, char** argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
