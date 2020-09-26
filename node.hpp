#ifndef NODE_HPP
#define NODE_HPP

#include <vector>
#include <string>
#include <algorithm>

class Node
{
	private:
		char type;
		std::string name;
		std::vector<Node*> children;
		Node* parent;
	public:
		void RemoveHelper(Node* subtree);
		Node(std::string name, char type);
		Node();
		void SortChildren();
		void AddChild(Node* child);
		void AddChild(std::string name, char type);
		bool RemoveChild(std::string name);
		void SetName(std::string name);
		void SetParent(Node* parent);
		void SetType(char type);
		Node* GetChild(std::string name);
		std::vector<Node*> GetChildren();
		Node* GetParent();
		char GetType();
		std::string GetName();
};

#endif
