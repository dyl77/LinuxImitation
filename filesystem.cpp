#include "filesystem.hpp"

void FileSystem::AddNode(Node* newNode)
{
	this->currentDirectory->AddChild(newNode);
}

Node* FileSystem::FindNode(std::string name)
{
	return this->currentDirectory->GetChild(name);	
}

FileSystem::FileSystem()
{
	Node* newRoot = new Node("root",'d');
	this->root = newRoot;
	this->currentDirectory = newRoot;
}

FileSystem::~FileSystem()
{

}

std::string FileSystem::mkdir(std::string name)
{
	std::string creationStatus;
	Node* newDir = new Node(name, 'd');

	if(currentDirectory->GetChild(name) == nullptr)
	{
		currentDirectory->AddChild(newDir);
		newDir->SetParent(currentDirectory);
		creationStatus = "directory " + newDir->GetName() + " created successfully";
	}
	else
	{
		creationStatus = "Error: " + newDir->GetName() + " exists";
	}
	return creationStatus;
}

std::string FileSystem::touch(std::string name)
{
	std::string creationStatus;
	Node* newFile = new Node(name, 'f');

	if(currentDirectory->GetChild(name) == nullptr)
	{
		currentDirectory->AddChild(newFile);
		newFile->SetParent(currentDirectory);
		creationStatus = "file " + newFile->GetName() + " created successfully";
	}
	else
	{
		creationStatus = "Error: " + newFile->GetName() + " exists";
	}
	return creationStatus;
}

std::string FileSystem::pwd()
{
	std::string workingDirectory = "";
	Node* tempNode = this->currentDirectory;

	while(tempNode != nullptr)
	{
		workingDirectory = "/" + tempNode->GetName() + workingDirectory;
		tempNode = tempNode->GetParent();
	}
	return workingDirectory;
}

std::string FileSystem::ls()
{
	std::vector<Node*> currentChildren = this->currentDirectory->GetChildren();
	std::string listDirectory = "";

	for(unsigned int i = 0; i < currentChildren.size(); ++i)
	{
		listDirectory = listDirectory + currentChildren.at(i)->GetType() + " " + currentChildren.at(i)->GetName() + "\n";
	}
	return listDirectory;
}

std::string FileSystem::rm(std::string name)
{
	if(FindNode(name) != nullptr)
	{
		currentDirectory = FindNode(name)->GetParent();
		currentDirectory->RemoveChild(name);
		return name + " removed successfully";
	}
	else
	{
		return "No such file or directory";
	}
}

std::string FileSystem::mv(std::string from, std::string to)
{
	if(FindNode(from) != nullptr)
	{
		FindNode(from)->SetName(to);
		return "file/dir renamed successfully";
	}
	else
	{
		return "file not found";
	}
}

std::string FileSystem::cd(std::string dirname)
{
	if(dirname == "..")
	{
		if(currentDirectory != this->root)
		{
			this->currentDirectory = this->currentDirectory->GetParent();
			return pwd();
		}
		else
		{
			return "can't change to directory " + dirname;
		}
	}

	if(FindNode(dirname) != nullptr)
	{
		if(FindNode(dirname)->GetType() == 'd')
		{
			this->currentDirectory = FindNode(dirname);
			return pwd();
		}
		else
		{
			return dirname + ": is not a directory";
		}
	}
	else
	{
		return dirname + ": no such directory";

	}
}
