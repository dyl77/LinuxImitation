#include "terminal.hpp"

Terminal::Terminal()
{

}

void Terminal::Run()
{
	std::string command;
	std::string modifier1;
	std::string modifier2;

	do
	{
		std::cout << "$ ";
		std::cin >> command >> modifier1 >> modifier2;

		if(command == "mkdir")
		{
			std::cout << this->fs->mkdir(modifier1) << std::endl;
		}
		if(command == "touch")
		{
			std::cout << this->fs->touch(modifier1) << std::endl;
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
	}while(command != "exit");
}
