#include "ScalarConvert.hpp"

ScalarConvert::ScalarConvert()
	: _value("0") , precision(1) {
}

ScalarConvert::ScalarConvert(std::string x)
	: _value(x) , precision(1) {
	int prec;
	for (int i = 0; i < x.size(); i++){
		if (x[i] == '.')
			prec++;
	}
	prec > 0 ? this->precision *= prec : this->precision;
	this->_convert(x);
}

ScalarConvert::ScalarConvert(const ScalarConvert& other)
	: _value(other._value), precision(other.precision) {
	*this = other;
}

ScalarConvert& ScalarConvert::operator=(const ScalarConvert& other){
	if (this != &other)
		this->precision = other.precision;
	return *this;
}

ScalarConvert::~ScalarConvert() {
}

bool ScalarConvert::isInt(std::string x, int *res){
	try {
		size_t pos;
		*res = stoi(x, &pos);
		return pos == x.length();
	}
	catch (const std::invalid_argument&){
		return false;
	}
	catch (const std::out_of_range&){
		return false;
	}
}

bool ScalarConvert::isDouble(std::string x, double *res){
	try{
		size_t pos;
		*res = stod(x, &pos);
		return pos == x.length();
	}
	catch (const std::invalid_argument&){
		return false;
	}
	catch (const std::out_of_range&){
		return false;
	}
}

bool ScalarConvert::isFloat(std::string x, float *res){
	try {
		size_t pos;
		*res = stof(x, &pos);

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

bool ScalarConvert::isChar(std::string x, char *c){
	if (x.length() == 1 && isalpha(x[0])){
		*c = x[0];
		return true;
	}
	return false;
}

bool ScalarConvert::isPseudoLiteral(const std::string& s) {
	return s == "nan"  || s == "nanf" ||
			s == "+inf" || s == "+inff"||
			s == "-inf" || s == "-inff";
}

double ScalarConvert::parsePseudoDouble(const std::string& s) {
	if (s == "-inf"  || s == "-inff") return -std::numeric_limits<double>::infinity();
	if (s == "+inf"  || s == "+inff") return  std::numeric_limits<double>::infinity();
	return std::numeric_limits<double>::quiet_NaN();
}

float ScalarConvert::parsePseudoFloat(const std::string& s) {
	if (s == "-inf"  || s == "-inff") return -std::numeric_limits<float>::infinity();
	if (s == "+inf"  || s == "+inff") return  std::numeric_limits<float>::infinity();
	return std::numeric_limits<float>::quiet_NaN();
}

void ScalarConvert::printAllConversions(double value) {
	if (value >= 32 && value <= 126 && value == static_cast<int>(value))
		std::cout << "Char: '" << static_cast<char>(value) << "'\n";
	else
		std::cout << "Char: Non displayable\n";
	std::cout << "int: " << static_cast<int>(value) << std::endl;
	std::cout << "float: "<< std::fixed 
		<< std::setprecision(this->precision) 
		<< static_cast<float>(value) 
		<< "f" << std::endl;
	std::cout << "double: "<< std::fixed 
		<< std::setprecision(this->precision) 
		<< value << std::endl;
}

void ScalarConvert::printError(){
	std::cout << "Error: invalid input" << std::endl;
}

void ScalarConvert::printPseudo(const std::string s){
	std::cout << "Char: impossible" << std::endl;
	std::cout << "Int: impossible" << std::endl;
	std::cout << "Float: " << parsePseudoFloat(s) << "f" << std::endl;
	std::cout << "Double: " << parsePseudoDouble(s) << std::endl;
}

void ScalarConvert::_convert(const std::string &s){
	types res;
	if (isChar(this->_value, &res.c_res)){
		std::cout << "Type detected: CHAR\n";
		printAllConversions(static_cast<double>(res.c_res));
	}
	else if (isInt(this->_value, &res.i_res)){
		std::cout << "Type detected: INT\n";
		printAllConversions(static_cast<double>(res.i_res));
	}
	else if (isPseudoLiteral(this->_value)){
		std::cout << "Type detected: PSEUDO LITERAL\n";
		printPseudo(this->_value);
	}
	else if (isDouble(this->_value, &res.d_res)){
		std::cout << "Type detected: DOUBLE\n";
		printAllConversions(res.d_res);
	}
	else if (isFloat(this->_value, &res.f_res)){
		std::cout << "Type detected: FLOAT\n";
		printAllConversions(static_cast<double>(res.f_res));
	}
	else {
		std::cout << "Type detected: OTHER\n";
		printError();
	}
}
