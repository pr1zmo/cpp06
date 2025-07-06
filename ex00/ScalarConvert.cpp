#include "ScalarConvert.hpp"

ScalarConvert::ScalarConvert()
	{
	cout << "ScalarConvert: Default constructor called" << endl;
}

ScalarConvert::ScalarConvert(string x)
	{
	if (isInt(x))
		cout << "Integer" << endl;
	else if (isDouble(x))
		cout << "Double" << endl;	
	else if (isFloat(x))
		cout << "Float" << endl;
	else if (isChar(x))
		cout << "Char" << endl;
	else
		cout << "Impossible" << endl;
}

ScalarConvert::ScalarConvert(const ScalarConvert& other)
	{
	cout << "ScalarConvert: Copy constructor called" << endl;
	*this = other;
}

ScalarConvert& ScalarConvert::operator=(const ScalarConvert& other) {
	cout << "ScalarConvert: Copy assignment operator called" << endl;
	if (this != &other) {
		//
	}
	return *this;
}

ScalarConvert::~ScalarConvert() {
	cout << "ScalarConvert: Destructor called" << endl;
}

bool ScalarConvert::isInt(string x){
	try {
		size_t pos;
		int result = stoi(x, &pos);
		return pos == x.length();
	}
	catch (const invalid_argument&){
		return false;
	}
	catch (const out_of_range&){
		return false;
	}
}

bool ScalarConvert::isDouble(string x){
	try{
		size_t pos;
		int result = stod(x, &pos);
		return pos == x.length();
	}
	catch (const invalid_argument&){
		return false;
	}
	catch (const out_of_range&){
		return false;
	}
}

bool ScalarConvert::isFloat(string x){
	try {
		size_t pos;
		float result = stof(x, &pos);

		if (pos == x.length()) {
			return true;
		}
		if (pos == x.length() - 1 && (x[pos] == 'f' || x[pos] == 'F')) {
			return true;
		}
		return false;
	}
	catch (const invalid_argument&){
		return false;
	}
	catch (const out_of_range&){
		return false;
	}
}

bool ScalarConvert::isChar(string x){
	if (x.length() == 1 && isalpha(x[0]))
		return true;
	return false;
}