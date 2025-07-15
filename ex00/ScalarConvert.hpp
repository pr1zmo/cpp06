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
		enum c_type{
			INT,
			CHAR,
			DOUBLE,
			FLOAT,
			PSEUDO,
			OTHER
		};
		static bool isPseudoLiteral(const std::string& s);
		static double  parsePseudoDouble (const std::string& s);
		static float   parsePseudoFloat  (const std::string& s);
		void printChar();
		void printInt();
		void printFLoat();
		void printDouble();
		string _convert(string x);
		string getString();
		ScalarConvert();
		ScalarConvert(string x);
		ScalarConvert(const ScalarConvert& other);
		ScalarConvert& operator=(const ScalarConvert& other);
		~ScalarConvert();
};

ostream& operator<<(ostream& o, ScalarConvert &conv);

#endif