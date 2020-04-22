#include "filesystem.hpp"

void FileSystem::AddNode(Node* newNode)
{
	this->currentDirectory->AddChild(newNode);
}

Node* FileSystem::FindNode(std::string name)
{
	this->currentDirectory->GetChild(name);	
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

}

std::string FileSystem::mv(std::string from, std::string to)
{

}

std::string FileSystem::cd(std::string dirname)
{

}
