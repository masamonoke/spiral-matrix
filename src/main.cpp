#include "application.hpp"

int main(int argc, char** argv) {
	std::unique_ptr<spiral::app> app;
	if (argc > 1) {
		app = std::make_unique<spiral::console_app>(argc, argv);
	} else {
		app = std::make_unique<spiral::qt_app>(argc, argv);
	}

	return app->run();
}
