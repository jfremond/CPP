#include <iostream>
#include <cstdlib>	//atof
#include <limits>	//numeric_limits
#include <iomanip>	//precision

//TODO	identify type
//!		Possible return values
//!		2 : int
//!		3 : float
//!		4 : double
int		identify(std::string arg)
{
	//? Cas des char
	if (arg.length() == 1 && !isdigit(arg.at(0)))
		return (1);
	//? Cas des inf et tout ca
	else if (arg.length() > 1 && !isdigit(arg.at(1)) && arg.at(1) != '.'
			&& arg != "-inf" && arg != "inf" && arg != "+inf" && arg != "nan"
			&& arg != "-inff" && arg != "inff" && arg != "+inff" && arg != "nanf")
		return (0);
	else if (arg.length() > 1
			&& (arg == "-inf" || arg == "inf" || arg == "+inf" || arg == "nan"))
		return (4);
	else if (arg.length() > 1
			&& (arg == "-inff" || arg == "inff" || arg == "+inff" || arg == "nanf"))
		return (3);
	//? Différentiation des float et des double
	else
	{
		int dot;
		int dot2;
		for (size_t i = 0; i < arg.length(); i++)
		{
			dot = arg.find('.');
			if (dot != -1)
			{
				dot2 = arg.find_last_of('.');
				if (dot2 != dot)
					return (0);
				if (arg.at(arg.length() - 1) == 'f')
					return (3);
				else
					return (4);
			}
			return (2);
		}
	}
	return (0);
}

//TODO	printing types
void	print_char(double value)
{
	if (value < 0 || value > 255)
		std::cout << "char: impossible" << std::endl;
	else
	{
		char c = static_cast<char>(value);
		if (!isprint(c))
			std::cout << "char: non displayable" << std::endl;
		else
			std::cout << "char: '" << c << "'" << std::endl;
	}

}

void	print_int(double value, std::string arg)
{
	(void)arg;
	if (value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max()
		|| arg == "nan" || arg == "nanf") //! displays INT_MIN if no check on arg
		std::cout << "int: imposible" << std::endl;
	else
	{
		int num = static_cast<int>(value);
		std::cout << "int: " << num << std::endl;
	}
}

void	print_float(double value, int precision)
{
	double	fnum = static_cast<float>(value);
	std::cout << "float: " << std::fixed << std::setprecision(precision) << fnum << "f" << std::endl;
}

void	print_double(double value, int precision)
{
	double	dnum = static_cast<double>(value);
	std::cout << "double: " << std::fixed << std::setprecision(precision) << dnum << std::endl;
}

int	set_precision(std::string arg)
{
	int	precision;

	int dot = arg.find('.');
	if (dot == -1)
		return (arg.length());
	else
	{
		precision = arg.length() - dot - 1;
		if (arg.at(arg.length() - 1) == 'f')
			precision--;
	}
	return (precision);
}

int	impossible(void)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: impossible" << std::endl;
	std::cout << "double: impossible" << std::endl;
	return (1);
}

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Usage: ./Convert [argument]" << std::endl;
		return (1);
	}
	std::string arg = argv[1];
	int		type = identify(arg);
	double	value;
	int		precision;
	switch(type)
	{
		case (1):
			std::cout << "char" << std::endl;
			value = arg[0];
			precision = 1;
			break;
		case (2):
			std::cout << "int" << std::endl;
			value = atof(arg.c_str());
			precision = set_precision(arg);
			break;
		case (3):
			std::cout << "float" << std::endl;
			precision = set_precision(arg);
			value = atof(arg.c_str());
			break;
		case (4):
			std::cout << "double" << std::endl;
			value = atof(arg.c_str());
			precision = set_precision(arg);
			break;
		default:
			std::cout << "Not a valid entry" << std::endl;
			return (impossible());
	}
	print_char(value);
	print_int(value, arg);
	print_float(value, precision);
	print_double(value, precision);
	return (0);
}