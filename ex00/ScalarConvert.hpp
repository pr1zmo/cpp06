#ifndef CONVERT_HPP
#define CONVERT_HPP

#include <iostream>
#include <string>

using namespace std;
typedef int c_type;

class ScalarConvert {
	private:
		string const _value;
		bool isInt(string x);
		bool isFloat(string x);
		bool isChar(string x);
		bool isDouble(string x);
		c_type getType(string x);
		string getValue(string x, int type);
		void convertInt(string x);
	public:
		void printChar();
		void printInt();
		void printFLoat();
		void printDouble();
		string _convert(string x);
		string getString();
		enum c_type{
			INT,
			CHAR,
			DOUBLE,
			FLOAT,
			OTHER
		};
		ScalarConvert();
		ScalarConvert(string x);
		ScalarConvert(const ScalarConvert& other);
		ScalarConvert& operator=(const ScalarConvert& other);
		~ScalarConvert();
};

ostream& operator<<(ostream& o, ScalarConvert &conv);

#endif