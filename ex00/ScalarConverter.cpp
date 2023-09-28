#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

void ScalarConverter::convert(const std::string& literal) 
{
    std::istringstream iss(literal);
    double value;

    if (!(iss >> value)) 
    {
        std::cout << "Invalid literal" << std::endl;
        return;
    }

    toChar(value);
    toInt(value);
    toFloat(value);
    toDouble(value);
}

void ScalarConverter::toChar(double value) 
{
    if (value != value || value == std::numeric_limits<double>::infinity() || value == -std::numeric_limits<double>::infinity()) 
    {
        std::cout << "char: impossible" << std::endl;
    } 
    else 
    {
        char c = static_cast<char>(value);
        if (c >= 32 && c <= 126)
        {
            std::cout << "char: '" << c << "'" << std::endl;
        }
        else
        {
            std::cout << "char: Non displayable" << std::endl;
        }
    }
}

void ScalarConverter::toInt(double value) 
{
    if (value != value || value == std::numeric_limits<double>::infinity() || value == -std::numeric_limits<double>::infinity()) 
    {
        std::cout << "int: impossible" << std::endl;
    } 
    else 
    {
        int i = static_cast<int>(value);
        std::cout << "int: " << i << std::endl;
    }
}

void ScalarConverter::toFloat(double value) 
{
    if (value != value) 
    {
        std::cout << "float: nanf" << std::endl;
    } 
    else if (value == std::numeric_limits<double>::infinity() || value == -std::numeric_limits<double>::infinity()) 
    {
        std::cout << "float: " << (value < 0 ? "-inff" : "inff") << std::endl;
    } 
    else 
    {
        float f = static_cast<float>(value);
        std::cout << "float: " << f << "f" << std::endl;
    }
}

void ScalarConverter::toDouble(double value) 
{
    std::cout << "double: " << value << std::endl;
}
