#include "application.hpp"
#include "spiral_path.hpp"

#include <span>
#include <iostream>
#include <sstream>

namespace spiral {

	std::string app::stringify_path(std::vector<int> path) {
		std::ostringstream oss;
		std::copy(path.begin(), path.end() - 1,
		std::ostream_iterator<int>(oss, ", "));
		oss << path.back();
		return oss.str();
	}


	int console_app::run() {
		auto args = std::span(argv_, static_cast<size_t>(argc_));
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

	void console_app::validate(ssize_t rows, ssize_t cols) {
		// works too slow and result will be also too much
		if (rows >= std::numeric_limits<int32_t>::max() || cols >= std::numeric_limits<int>::max()) {
			throw std::invalid_argument("too big number");
		}

		if (rows < 0 || cols < 0) {
			throw std::invalid_argument("negative row or column value");
		}
	}

	qt_app::qt_app(int argc, char** argv) : qapp_(argc, argv) {
		w_ = std::make_unique<ui::qt_window>([] (const std::string& rows, const std::string& cols) {
			return button_callback(rows, cols);
		}, "Matrix Spiral");
	}

	int qt_app::run() {
		w_->show();
		return QApplication::exec();
	}


	std::string qt_app::button_callback(const std::string& rows_str, const std::string& cols_str) {
		size_t rows {};
		size_t cols {};
		std::tie(rows, cols) = parse_input(rows_str, cols_str);
		std::unique_ptr<spiral::spiral_path> p (new spiral::sprial_path_clockwise(static_cast<size_t>(rows), static_cast<size_t>(cols)));
		auto path = p->make_path();
		return stringify_path(path);
	}

	std::pair<size_t, size_t> qt_app::parse_input(const std::string& rows_str, const std::string& cols_str) {
		const ssize_t rows = std::stoll(rows_str);
		const ssize_t cols = std::stoll(cols_str);

		// works too slow and result will be also too much
		if (rows >= std::numeric_limits<int32_t>::max() || cols >= std::numeric_limits<int>::max()) {
			throw std::invalid_argument("too big number");
		}

		if (rows < 0 || cols < 0) {
			throw std::invalid_argument("negative row or column value");
		}

		return { rows, cols };
	}

}
