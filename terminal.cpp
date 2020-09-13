#include "terminal.hpp"

Terminal::Terminal()
{
	this->fs = new FileSystem();
}

void Terminal::Run()
{
	std::string command;
	std::string modifier1;
	std::string modifier2;
	std::string tempstring;


	do
	{	
		std::cout << "$ ";
		std::getline(std::cin, tempstring);

		std::size_t position = tempstring.find(' ');
		command = tempstring.substr(0,position);
		tempstring.erase(0,position+1);

		if(tempstring.size() != 0)
		{
			position = tempstring.find(' ');
			modifier1 = tempstring.substr(0,position);
			tempstring.erase(0,position+1);
		}

		if(tempstring.size() != 0)
		{
			modifier2 = tempstring;
		}
	
		if(command == "mkdir")
		{
			std::cout << this->fs->mkdir(modifier1) << std::endl;
		}
		if(command == "addf")
		{
			std::cout << this->fs->addf(modifier1) << std::endl;
		}
		if(command == "pwd")
		{
			std::cout << this->fs->pwd() << std::endl;
		}
		if(command == "ls")
		{
			std::cout << this->fs->ls() << std::endl;
		}
		if(command == "rm")
		{
			std::cout << this->fs->rm(modifier1) << std::endl;
		}
		if(command == "mv")
		{
			std::cout << this->fs->mv(modifier1, modifier2) << std::endl;
		}
		if(command == "cd")
		{
			std::cout << this->fs->cd(modifier1) << std::endl;
		}
		if(command == "cp")
		{
			std::cout << this->fs->cp(modifier1, modifier2) << std::endl;
		}
	}while(command != "bye");
}
