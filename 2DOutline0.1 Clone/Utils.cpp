#include "Utils.h"
#include <fstream>
#include <string>

std::string Utils::loadFileAsString(std::string path)
{
	std::string br{};
	std::string line{};
	std::ifstream file{ path };
	if (file.is_open()) {
		while (std::getline(file, line)) {
			br.append(line + "\n");
		}
		file.close();
	}
	else {
		printf("Unable to open file. Path: %s\n", path.c_str());
	}
	return br;
}

int Utils::parseInt(std::string number)
{
	try {
		return std::stoi(number);
	}
	catch (std::invalid_argument) {
		printf("Invalid input. Cannot convert %s to number.\n", number.c_str());
		return -1;
	}
}
