#pragma once

#include "window.hpp"

namespace spiral {

	class app {
		public:
			virtual ~app() = default;

			virtual int run() = 0;

			static std::string stringify_path(std::vector<int> path);
	};

	class console_app : public app {
		public:
			console_app(int argc, char** argv) : argc_(argc), argv_(argv) {}

			int run() override;

		private:
			int argc_;
			char** argv_;

			static void validate(ssize_t rows, ssize_t cols);
	};

	class qt_app : public app {
		public:
			qt_app(int argc, char** argv);

			int run() override;

		private:
			QApplication qapp_;
			std::unique_ptr<ui::qt_window> w_;

			static std::string button_callback(const std::string& rows_str, const std::string& cols_str);
			static std::pair<size_t, size_t> parse_input(const std::string& rows_str, const std::string& cols_str);
	};
}
