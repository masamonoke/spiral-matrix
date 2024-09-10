#pragma once

#include "window.hpp"

namespace spiral
{

	class IApp
	{
		public:
			virtual ~IApp() = default;

			virtual int Run() = 0;

			static std::string StringifyPath(std::vector<int> path);
	};

	class ConsoleApp : public IApp
	{
		public:
			ConsoleApp(int argc, char** argv) : m_argc(argc), m_argv(argv) {}

			int Run() override;

		private:
			int    m_argc;
			char** m_argv;

			static void Validate(ssize_t rows, ssize_t cols);
	};

	class QtApp : public IApp
	{
		public:
			QtApp(int argc, char** argv);

			int Run() override;

		private:
			QApplication                  m_QtApp;
			std::unique_ptr<ui::QtWindow> m_Window;

			static std::string ButtonCallback(const std::string& rowsStr, const std::string& colsStr);
			static std::pair<size_t, size_t> ParseInput(const std::string& rowsStr,
			                                            const std::string& colsStr);
	};
} // namespace spiral
