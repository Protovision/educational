#ifndef PORTABLE_POPEN_H
#define PORTABLE_POPEN_H
#include <stdio.h>
#include <string>

inline FILE* portable_popen(const std::string& command,
					std::string mode)
{
#ifdef _WIN32
	if (mode.back() != 'b') mode.push_back('b');
	return _popen(command.c_str(), mode.c_str());
#else
	return popen(command.c_str(), mode.c_str());
#endif
}

inline void portable_pclose(FILE* ps)
{
#ifdef _WIN32
	_pclose(ps);
#else
	pclose(ps);
#endif
}

#endif
