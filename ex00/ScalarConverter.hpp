#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>
#include <iostream>
#include <sstream>
#include <limits>
#include <cmath>

class ScalarConverter 
{
    public:
        static void convert(const std::string& literal);
        ScalarConverter(const ScalarConverter& other);
        ScalarConverter& operator=(const ScalarConverter& other);

    private:
        ScalarConverter();
        static void toChar(double value);
        static void toInt(double value);
        static void toFloat(double value);
        static void toDouble(double value);
};

#endif
