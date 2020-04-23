#include "node.hpp"

void Node::RemoveHelper(Node* subtree)
{
	/*
	if(subtree->GetChildren().size() == 0)
	{
		delete subtree;
	}
	else
	{
		for(unsigned int i = 0; i < subtree->GetChildren().size(); ++i)
		{
			RemoveHelper(subtree->GetChildren().at(i));
		}
		delete subtree;
	}
*/
	//RemoveHelper(children.at(0));
	if(children.size() == 0)
	{
		delete subtree;
	}

	RemoveHelper(children.at(0));
}

Node::Node(std::string name, char type)
{
	this->type = type;
	this->name = name;
	this->parent = nullptr;
}

Node::Node()
{
	this->type = 'n';
	this->name = "NULL";
	this->parent = nullptr;
}

void Node::AddChild(Node* child)
{
	this->children.push_back(child);
}

void Node::AddChild(std::string name, char type)
{
	Node* newChild = new Node(name, type);
	this->children.push_back(newChild);
}

bool Node::RemoveChild(std::string name)
{
	Node* searchNode = GetChild(name);
	std::vector<Node*> searchNodeChildren = searchNode->GetChildren();

	if(searchNodeChildren.size() == 0)
	{
		//delete this->GetChild(name);
		//for(unsigned int i = 0; i < this->children.size()
		//this->children.pop_back();
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
		RemoveHelper(searchNode);
		return true;
	}
	return false;
}

void Node::SetName(std::string name)
{
	this->name = name;
}

void Node::SetParent(Node* parent)
{
	this->parent = parent;
}

void Node::SetType(char type)
{
	this->type = type;
}

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

std::vector<Node*> Node::GetChildren()
{
	return this->children;
}

Node* Node::GetParent()
{
	return this->parent;
}

char Node::GetType()
{
	return this->type;
}

std::string Node::GetName()
{
	return this->name;
}
