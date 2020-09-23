#include "node.hpp"

//Used for removing subtrees of directories recursively
void Node::RemoveHelper(Node* subtree)
{
	if(subtree->GetChildren().size() == 0)
	{
		delete subtree;
	}
	else
	{
		RemoveHelper(subtree->GetChildren().at(0));
	}
}

//Constructor of a node
Node::Node(std::string name, char type)
{
	this->type = type;
	this->name = name;
	this->parent = nullptr;
}

//Base constructor of a node 
Node::Node()
{
	this->type = 'n';
	this->name = "NULL";
	this->parent = nullptr;
}

//Adding an existing child node to a vector held by a parent
void Node::AddChild(Node* child)
{
	this->children.push_back(child);
}

//Creating and adding a new child node to a parent's children vector
void Node::AddChild(std::string name, char type)
{
	Node* newChild = new Node(name, type);
	this->children.push_back(newChild);
}

//Removing a child and grandchildren of a node, and returning a T/F based on success
bool Node::RemoveChild(std::string name)
{
	Node* searchNode = GetChild(name);
	std::vector<Node*> searchNodeChildren = searchNode->GetChildren();

	if(GetChild(name)->GetChildren().size() == 0)
	{
		for(unsigned int i = 0; i < children.size(); ++i)
		{
			if(children.at(i)->GetName() == name)
			{
				children.erase(children.begin()+i);
			}
		}
		return true;
	}
	else
	{	
		RemoveHelper(GetChild(name));
		return true;
	}
	return false;
}

//Changing name of a node
void Node::SetName(std::string name)
{
	this->name = name;
}

//Setting a parent of a node
void Node::SetParent(Node* parent)
{
	this->parent = parent;
}

//Setting type of a node, directory or file (d/f)
void Node::SetType(char type)
{
	this->type = type;
}

//Getting child based on name
Node* Node::GetChild(std::string name)
{
	for(long unsigned int i = 0; i < children.size(); ++i)
	{
		if(children.at(i)->GetName() == name)
		{
			return children.at(i);
		}
	}
	return nullptr;
}

//Returns a node's children vector
std::vector<Node*> Node::GetChildren()
{
	return this->children;
}

//Returns a node's parent
Node* Node::GetParent()
{
	return this->parent;
}

//Returns the type of a node, (d/f)
char Node::GetType()
{
	return this->type;
}

//Returns name of current node
std::string Node::GetName()
{
	return this->name;
}
