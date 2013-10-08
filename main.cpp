#include <iostream>
#include <string>
#include <locale>

std::locale loc;

bool is_name_valid(const std::string &name)
{
	typedef std::string::const_iterator const_iterator;
	enum { whitespace, alpha, number, punct } whatread = whitespace;
	for (const_iterator i = name.begin(); i != name.end(); ++i) {
		switch (whatread) {
		case whitespace:
			if (std::isalpha(*i, loc)) {
				whatread = alpha;
			} else if (std::isdigit(*i,loc)) {
				whatread = number;
			} else if (!std::isspace(*i, loc)) {
				return false;
			}
			break;
		case alpha:
			if (std::ispunct(*i, loc)) {
				whatread = punct;
			} else if (std::isspace(*i, loc)) {
				whatread = whitespace;
			} else if (!std::isalpha(*i, loc)) {
				return false;
			}
			break;
		case number:
			if (std::ispunct(*i, loc)) {
				whatread = punct;
			} else if (std::isspace(*i, loc)) {
				whatread = whitespace;
			} else if (!std::isxdigit(*i, loc)) {
				return false;
			}
			break;
		case punct:
			if (std::isspace(*i, loc)) {
				whatread = whitespace;
			} else {
				return false;
			}
			break;
		}
	}
	return true;
}

bool is_name_multyword(const std::string &name)
{
	return name.find_first_of(" \t") != std::string::npos;
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
	std::string greating = is_name_multyword(name) ? "Hello, " : "Hi, ";
	std::cout << greating << name << "!" << std::endl;
	return 0;
}
