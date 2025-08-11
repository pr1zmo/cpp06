#ifndef CONVERT_HPP
#define CONVERT_HPP

#include <iostream>
#include <string>
#include <climits>
#include <limits>
#include <cerrno>
#include <iomanip>
#include <cstdlib>

typedef int c_type;

class ScalarConvert {
	private:
		std::string const _value;
	public:
		ScalarConvert();
		ScalarConvert(std::string x);
		ScalarConvert(const ScalarConvert& other);
		ScalarConvert& operator=(const ScalarConvert& other);
		~ScalarConvert();
		bool isInt(const std::string& x, int *res);
		bool isFloat(const std::string& x, float *res);
		bool isChar(const std::string& x, char *res);
		bool isDouble(const std::string& x, double *res);
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
		static bool isPseudoLiteral(const std::string& s);
		static double parsePseudoDouble(const std::string& s);
		static float parsePseudoFloat(const std::string& s);
		void _convert(const std::string& s);
		void printPseudo(const std::string x);
		void printError(void);
		void printAllConversions(double value);
		int precision;
};

// std::ostream& operator<<(std::ostream& o, ScalarConvert &conv);

#endif