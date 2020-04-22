#ifndef FILESYSTEM_HPP
#define FILESYSTEM_HPP

#include "node.hpp"
#include <iostream>

class FileSystem
{
	private:
		Node* root;
		Node* currentDirectory;
		void AddNode(Node* newNode);
		Node* FindNode(std::string name);
	public:
		FileSystem();
		~FileSystem();
		std::string mkdir(std::string name);
		std::string touch(std::string name);
		std::string pwd();
		std::string ls();
		std::string rm(std::string name);
		std::string mv(std::string from, std::string to);
		std::string cd(std::string dirname);

};

#endif
