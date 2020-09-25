#include "filesystem.hpp"

//For inserting node within current directory
void FileSystem::AddNode(Node* newNode)
{
	this->currentDirectory->AddChild(newNode);
}

//Helper for finding node by name within current directory
Node* FileSystem::FindNode(std::string name)
{
	return this->currentDirectory->GetChild(name);	
}

//Constructor for filesystem
FileSystem::FileSystem()
{
	//Each filesystem MUST start with a root directory
	Node* newRoot = new Node("root",'d');
	this->root = newRoot;
	this->currentDirectory = newRoot;
}

//Filesystem destructor
FileSystem::~FileSystem()
{

}

//Returns current directory
Node* FileSystem::getCurrentDirectory()
{
	return this->currentDirectory;
}

//Creates directory of chosen name in current directory
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

//Creates file of chosen name in current directory
std::string FileSystem::addf(std::string name)
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

//Prints the path of current directory
std::string FileSystem::pwd(Node* currentNode)
{
	std::string workingDirectory = "";
	Node* tempNode = currentNode;//this->currentDirectory;

	while(tempNode != nullptr)
	{
		workingDirectory = "/" + tempNode->GetName() + workingDirectory;
		tempNode = tempNode->GetParent();
	}
	return "/morris" + workingDirectory;
}

//Lists all current children of the current directory
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

//Roemoves node and its children from tree
std::string FileSystem::rm(std::string name)
{
	if(FindNode(name) != nullptr)
	{
		currentDirectory->RemoveChild(name);
		return name + " removed successfully";
	}
	else
	{
		return "No such file or directory";
	}
}

//Changes node name to new chosen name
std::string FileSystem::mv(std::string from, std::string to)
{
	if(FindNode(from) != nullptr)
	{
		if(currentDirectory->GetChild(to) == nullptr)
		{
			FindNode(from)->SetName(to);
			return "file/dir renamed successfully";
		}
		else
		{
			return to + " already exists in " + currentDirectory->GetName() + ".";
		}
	}
	else
	{
		return "file not found";
	}
}

//Changes current directory to the chosen directory
std::string FileSystem::cd(std::string dirname)
{
	if(dirname == "..")
	{
		if(currentDirectory != this->root)
		{
			this->currentDirectory = this->currentDirectory->GetParent();
			return pwd(this->currentDirectory);
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
			return pwd(this->currentDirectory);
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

//Copies node information and children to new node with chosen name
std::string FileSystem::cp(std::string originalNodeName, std::string copyNodeName)
{
	if(currentDirectory->GetChild(copyNodeName) == nullptr)
	{
		if(FindNode(originalNodeName) != nullptr)
		{

			Node* copiedNode = new Node(copyNodeName, FindNode(originalNodeName)->GetType());
	       		copiedNode->SetParent(FindNode(originalNodeName)->GetParent());	
			copiedNode->GetParent()->AddChild(copiedNode);
			std::vector<Node*> originalNodeChildren = FindNode(originalNodeName)->GetChildren();	

			if(originalNodeChildren.size() != 0)
			{
				for(unsigned int i = 0; i < originalNodeChildren.size(); ++i)
				{
					copiedNode->AddChild(originalNodeChildren[i]);
				}
			}
			return copyNodeName + " " + copiedNode->GetType() + ": created sucessfully";
		}
		else
		{
			return originalNodeName + ": no such directory or file";
		}
	}
	else
	{
		return copyNodeName + " already exists in " + currentDirectory->GetName() + ".";
	}
}

//Recursive helper method that searches subtrees for a node
Node* FileSystem::SearchHelper(Node* subtree, std::string key)
{

	if(subtree->GetChildren().size() == 0)
	{
		if(subtree->GetName() == key)
			return subtree;
		else
			return nullptr;
	}
	else
	{

		return nullptr;
		//for(unsigned int i = 0; i < subtree->GetChildren().size(); ++i)
		//{
			//SearchHelper(subtree->GetChildren().at(0), key);
		//}
	}
}

//Finds node anywhere in system, prints it's path
std::string FileSystem::whereis(std::string key)
{
	
	std::string path = "";

	Node* foundNode = SearchHelper(this->root, key);

	if(foundNode == nullptr)
	{
		return key + ": cannot be found.";
	}
	else
	{
		return key + ": " + pwd(foundNode);
	}
	
	//return "Work in progress";
}
