#include <iostream>
#include <string>

int main(int argc, char **argv)
{
	std::cout << "Enter your name:";
	std::string name;
	std::cin >> name;
	std::cout << "Hello, " << name << "!" << std::endl;
	return 0;
}
