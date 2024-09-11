#include "application.hpp"
#include "spiral_path.hpp"

#include <iostream>
#include <span>
#include <sstream>

namespace spiral
{

	std::string IApp::StringifyPath(std::vector<int> path)
	{
		if (path.empty())
		{
			return "";
		}

		std::ostringstream oss;
		std::copy(path.begin(), path.end() - 1, std::ostream_iterator<int>(oss, ", "));
		oss << path.back();

		return oss.str();
	}

	int ConsoleApp::Run()
	{
		auto args = std::span(m_argv, static_cast<size_t>(m_argc));
		try
		{
			const ssize_t rows = std::stoll(args[1]);
			const ssize_t cols = std::stoll(args[2]);
			Validate(rows, cols);

			std::unique_ptr<spiral::ISpiralPath> SpiralPath(
			    new spiral::SpiralPathClockwise(static_cast<size_t>(rows), static_cast<size_t>(cols)));
			auto path = SpiralPath->MakePath();

			std::cout << StringifyPath(path) << '\n';
		}
		catch (const std::invalid_argument& e)
		{
			std::cerr << "Wrong rows or columns value passed: " << e.what() << '\n';
			return 1;
		}
		catch (const std::out_of_range& e)
		{
			std::cerr << "Rows or columns number is out of range value: " << e.what() << '\n';
			return 1;
		}

		return 0;
	}

	void ConsoleApp::Validate(ssize_t rows, ssize_t cols)
	{
		// works too slow and result will be also too much
		if (rows >= std::numeric_limits<int32_t>::max() || cols >= std::numeric_limits<int32_t>::max())
		{
			throw std::invalid_argument("too big number");
		}

		if (rows < 0 || cols < 0)
		{
			throw std::invalid_argument("negative row or column value");
		}
	}

	QtApp::QtApp(int argc, char** argv) : m_QtApp(argc, argv)
	{
		auto Callback = [](const std::string& rows, const std::string& cols) { return ButtonCallback(rows, cols); };
		m_Window      = std::make_unique<ui::QtWindow>(Callback, "Matrix Spiral");
	}

	int QtApp::Run()
	{
		m_Window->show();
		return QApplication::exec();
	}

	std::string QtApp::ButtonCallback(const std::string& rowsStr, const std::string& colsStr)
	{
		size_t rows{};
		size_t cols{};
		std::tie(rows, cols) = ParseInput(rowsStr, colsStr);
		std::unique_ptr<spiral::ISpiralPath> SpiralPath(new spiral::SpiralPathClockwise(rows, cols));
		auto                                 path = SpiralPath->MakePath();
		return StringifyPath(path);
	}

	std::pair<size_t, size_t> QtApp::ParseInput(const std::string& rowsStr, const std::string& colsStr)
	{
		const ssize_t rows = std::stoll(rowsStr);
		const ssize_t cols = std::stoll(colsStr);

		// works too slow and result will be also too much
		if (rows >= std::numeric_limits<int32_t>::max() || cols >= std::numeric_limits<int32_t>::max())
		{
			throw std::invalid_argument("too big number");
		}

		if (rows < 0 || cols < 0)
		{
			throw std::invalid_argument("negative row or column value");
		}

		return { rows, cols };
	}

} // namespace spiral
