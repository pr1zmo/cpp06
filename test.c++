#include <iostream>
#include <string>

bool isFloat(std::string x){
	try {
		size_t pos;
		float result = std::stof(x, &pos);

		if (pos == x.length()) {
			return true;
		}

		if (pos == x.length() - 1 && (x[pos] == 'f' || x[pos] == 'F')) {
			return true;
		}

		return false;
	}
	catch (const std::invalid_argument&){
		return false;
	}
	catch (const std::out_of_range&){
		return false;
	}
}

int main(int ac, char **av){
	std::cout << isFloat(av[1]) << std::endl;
	return (0);
}