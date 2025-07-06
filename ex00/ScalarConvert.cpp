#include "ScalarConvert.hpp"

ScalarConvert::ScalarConvert()
	: _value("0") {
	cout << "ScalarConvert: Default constructor called" << endl;
}

ScalarConvert::ScalarConvert(string x)
	: _value(x) {
	this->_convert(x);
}

ScalarConvert::ScalarConvert(const ScalarConvert& other)
	: _value(other._value) {
	cout << "ScalarConvert: Copy constructor called" << endl;
	*this = other;
}

ScalarConvert& ScalarConvert::operator=(const ScalarConvert& other){
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

c_type ScalarConvert::getType(string x){
	if (isInt(x))
		return (INT);
	else if (isDouble(x))
		return (DOUBLE);
	else if (isFloat(x))
		return (FLOAT);
	else if (isChar(x))
		return (CHAR);
	return (OTHER);
}

string ScalarConvert::getValue(string x, int type){
	string result;
	switch(type){
		case INT: {

		}
		case FLOAT: {

		}
		case DOUBLE: {

		}
		case CHAR: {

		}
	}
	return NULL;
}

void ScalarConvert::convertInt(string x){
	cout << "Int: " << getValue(x, INT) << endl;
}

string ScalarConvert::getString(){
	return this->_value;
}

ostream& operator<<(ostream& o, ScalarConvert conv){
	o << conv.getString() << endl;
	return o;
}

string ScalarConvert::_convert(string x){
	int type = getType(x);
	if (type == INT)
		convertInt(x);
	return ("Hallo\n");
}

void	ScalarConvert::printChar() {
	
}

ostream& operator<<(ostream& o, ScalarConvert &conv){
	o << "char: "; 
	conv.printChar();
	o << "int: ";
	conv.printInt();
	o << "float: ";
	conv.printFLoat();
	o << "double: ";
	conv.printDouble();
	return o;
}