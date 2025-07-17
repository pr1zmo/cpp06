#include "ScalarConvert.hpp"

int main(int ac, char **av){
	if (ac != 2)
		return (0);
	std::string value = av[1];
	ScalarConvert c1(value);
	// c1.getType(value);
	return (0);
}