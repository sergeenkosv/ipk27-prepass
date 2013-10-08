#include <iostream>
#include <string>
#include <locale>

std::locale loc;

bool is_name_valid(const std::string &name)
{
	typedef std::string::const_iterator const_iterator;
	for (const_iterator i = name.begin(); i != name.end(); ++i) {
		if (!std::isprint(*i, loc))
			return false;
	}
	return true;
}

int main(int argc, char **argv)
{
	std::cout << "Enter your name:";
	std::string name;
	std::getline(std::cin, name);
	if (name.empty()) {
		std::cout << "I can\'t great you if you don\'t say me your name" << std::endl;
		return 1;
	}
	if (!is_name_valid(name)) {
		std::cout << "Your name seems to be not name." << std::endl;
		std::cout << "I can\'t great you." << std::endl;
		return 1;
	}
	std::cout << "Hello, " << name << "!" << std::endl;
	return 0;
}
