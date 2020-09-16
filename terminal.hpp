#ifndef TERMINAL_HPP
#define TERMINAL_HPP

#include "filesystem.hpp"
#include <iostream>
#include <fstream>

class Terminal
{
	private:
		FileSystem* fs;
	public:
		Terminal();
		void Run();
};

#endif
