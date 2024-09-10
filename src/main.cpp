#include "application.hpp"

int main(int argc, char** argv)
{
	std::unique_ptr<spiral::IApp> app;
	if (argc > 1)
	{
		app = std::make_unique<spiral::ConsoleApp>(argc, argv);
	}
	else
	{
		app = std::make_unique<spiral::QtApp>(argc, argv);
	}

	return app->Run();
}
