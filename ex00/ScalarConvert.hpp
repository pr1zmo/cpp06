#ifndef CONVERT_HPP
#define CONVERT_HPP

#include <iostream>
#include <string>

using namespace std;

class ScalarConvert {
	private:
		void _convert();
		enum type{
			INT,
			CHAR,
			DOUBLE,
			FLOAT,
		};
		bool isInt(std::string x);
		bool isFloat(std::string x);
		bool isChar(std::string x);
		bool isDouble(std::string x);

	public:
		ScalarConvert();
		ScalarConvert(std::string x);
		ScalarConvert(const ScalarConvert& other);
		ScalarConvert& operator=(const ScalarConvert& other);
		~ScalarConvert();
};

#endif