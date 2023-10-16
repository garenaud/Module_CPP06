#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& other) 
{
    *this = other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) 
{
    if (this != &other) 
    {
        *this = other;
    }
    return *this;
}

void ScalarConverter::convert(const std::string& literal) 
{
    double value;

    if (literal == "-inff" || literal == "-inf") 
    {
        value = -std::numeric_limits<float>::infinity();
    }
    else if (literal == "+inff" || literal == "+inf") 
    {
        value = std::numeric_limits<float>::infinity();
    }
    else if (literal == "nanf" || literal == "nan") 
    {
        value = std::numeric_limits<float>::quiet_NaN();
    }
    else 
    {
        std::istringstream iss(literal);
        if (!(iss >> value)) 
        {
            std::cout << "Invalid literal" << std::endl;
            return;
        }
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
        std::cout << "float: " << std::fixed << f << "f" << std::endl;
    }
}

void ScalarConverter::toDouble(double value) 
{
    std::cout << "double: " << std::fixed << value << std::endl;
}
