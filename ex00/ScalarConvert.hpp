#ifndef CONVERT_HPP
#define CONVERT_HPP

#include <iostream>
#include <string>
#include <limits>
#include <iomanip>

using namespace std;
typedef int c_type;

class ScalarConvert {
	private:
		string const _value;
	public:
		ScalarConvert();
		ScalarConvert(string x);
		ScalarConvert(const ScalarConvert& other);
		ScalarConvert& operator=(const ScalarConvert& other);
		~ScalarConvert();
		bool isInt(string x, int *res);
		bool isFloat(string x, float *res);
		bool isChar(string x, char *res);
		bool isDouble(string x, double *res);
		enum c_type{
			INT,
			CHAR,
			DOUBLE,
			FLOAT,
			PSEUDO,
			OTHER
		};
		typedef struct types{
			int i_res;
			float f_res;
			char c_res;
			double d_res;
			std::string p_res;
			std::string o_res;
		}	s_types;
		static bool isPseudoLiteral(const string& s);
		static double parsePseudoDouble (const string& s);
		static float parsePseudoFloat  (const string& s);
		int getType(const string& s);
		void _convert(const string& s);
		void printInt(const int x);
		void printChar(const char x);
		void printDouble(const double x);
		void printFloat(const float x);
		void printPseudo(const std::string x);
		void printError(void);
		void printAllConversions(double value);
		int precision;
};

ostream& operator<<(ostream& o, ScalarConvert &conv);

#endif