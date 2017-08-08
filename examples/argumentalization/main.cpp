#include "application\application.hpp"
#include "log\service_logger.hpp"
#include "log\logger.hpp"
#include "argument\string_option_value.hpp"
#include "argument\integer_option_value.hpp"

int main(int argc, char * argv[])
{
	try {
		std::string name = "";
		int count = 0;

		ece::Application app(argc, argv);

		app.getArgumentAnalyzer().addOption(ece::Option("name",
			std::shared_ptr<ece::OptionValue>(new ece::StringOptionValue()),
			[&name](const std::string & value) {
				name = value;
			}
		));
		app.getArgumentAnalyzer().addOption(ece::Option("c",
			std::shared_ptr<ece::OptionValue>(new ece::IntegerOptionValue()),
			[&count, &name](const std::string & value) {
				count = std::stoi(value);
				for (int i = 0; i < count; ++i) {
					std::cout << "Good morning " << name << "!" << std::endl;
				}
			}
		));

		app.run();
	}
	catch (std::exception & e) {
		ece::ServiceLoggerLocator::getService().logError("Uncaught exception: " + std::string(e.what()));
	}

	return EXIT_SUCCESS;
}