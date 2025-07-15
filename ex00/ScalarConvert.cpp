#include "ScalarConvert.hpp"

ScalarConvert::ScalarConvert()
	: _value("0") {
}

ScalarConvert::ScalarConvert(string x)
	: _value(x) {
	this->_convert(x);
}

ScalarConvert::ScalarConvert(const ScalarConvert& other)
	: _value(other._value) {
	*this = other;
}

ScalarConvert& ScalarConvert::operator=(const ScalarConvert& other){
	return *this;
}

ScalarConvert::~ScalarConvert() {
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

int ScalarConvert::getType(string x){
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
}

void	ScalarConvert::printChar() {
	
}

#include <limits>

bool ScalarConvert::isPseudoLiteral(const std::string& s) {
	return s == "nan"  || s == "nanf" ||
			s == "+inf" || s == "+inff"||
			s == "-inf" || s == "-inff";
}

double ScalarConvert::parsePseudoDouble(const std::string& s) {
	if (s == "-inf"  || s == "-inff") return -std::numeric_limits<double>::infinity();
	if (s == "+inf"  || s == "+inff") return  std::numeric_limits<double>::infinity();
	return                                       std::numeric_limits<double>::quiet_NaN();
}

float ScalarConvert::parsePseudoFloat(const std::string& s) {
	if (s == "-inf"  || s == "-inff") return -std::numeric_limits<float>::infinity();
	if (s == "+inf"  || s == "+inff") return  std::numeric_limits<float>::infinity();
	return                                       std::numeric_limits<float>::quiet_NaN();
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