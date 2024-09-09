#include <iostream>
#include <sstream>
#include <span>

#include "spiral_path.hpp"

namespace {
	std::string stringify_path(std::vector<int> path) {
		std::ostringstream oss;
		std::copy(path.begin(), path.end() - 1,
		std::ostream_iterator<int>(oss, ", "));
		oss << path.back();
		return oss.str();
	}

	void validate(ssize_t rows, ssize_t cols) {
		// works too slow and result will be also too much
		if (rows >= std::numeric_limits<int32_t>::max() || cols >= std::numeric_limits<int>::max()) {
			throw std::invalid_argument("too big number");
		}

		if (rows < 0 || cols < 0) {
			throw std::invalid_argument("negative row or column value");
		}
	}
}

int main(int argc, char** argv) {

	if (argc < 3) {
		std::cerr << "usage: ./spiral rows cols" << std::endl;
		return 1;
	}

	auto args = std::span(argv, static_cast<size_t>(argc));
	try {
		const ssize_t rows = std::stoll(args[1]);
		const ssize_t cols = std::stoll(args[2]);
		validate(rows, cols);

		std::unique_ptr<spiral::spiral_path> p (new spiral::sprial_path_clockwise(static_cast<size_t>(rows), static_cast<size_t>(cols)));
		auto path = p->make_path();

		std::cout << stringify_path(path) << std::endl;
	} catch (const std::invalid_argument& e) {
		std::cerr << "Wrong rows or columns value passed: " << e.what() << std::endl;
		return 1;
	} catch (const std::out_of_range& e) {
		std::cerr << "Rows or columns number is out of range value: " << e.what() << std::endl;
		return 1;
	}

	return 0;
}
