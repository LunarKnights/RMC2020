#ifndef _LK_LOG_H
#define _LK_LOG_H

#include <string>

void debug(std::string label, double data);
void info(std::string msg);
void error(std::string msg);
void fatal(std::string msg);

#endif