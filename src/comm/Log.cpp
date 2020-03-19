/**
 * Lunar Knights
 *
 * Sachin Shah
 * February 08, 2020
 *
 *
 */

#include <cstdlib>
#include <iostream>
#include <string>

#include "LK/comm/Log.h"
#include "LK/comm/Color.h"

void debug(std::string label, double data)
{
	std::cout << label << ": " << data << "\n";
}

void info(std::string msg)
{
	std::cout << msg << "\n";
}

void error(std::string msg)
{
	std::cerr << ESC_COLOR << BOLD_RED << msg << ESC_COLOR << RESET_COLOR << "\n";
}

void fatal(std::string msg)
{
	error(msg);
	exit(1);
}
