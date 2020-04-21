#include "node.hpp"

void Node::RemoveHelper(Node* subtree)
{

}

Node::Node(std::string name, char type)
{
	this->type = type;
	this->name = name;
	//this->children.resize(0);
	this->parent = nullptr;
}

Node::Node()
{
	this->type = 'n';
	this->name = "NULL";
	//this->children.resize(0);
	this->parent = nullptr;
}

void Node::AddChild(Node* child)
{

}

void Node::AddChild(std::string name, char type)
{

}

bool Node::RemoveChild(std::string name)
{

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
