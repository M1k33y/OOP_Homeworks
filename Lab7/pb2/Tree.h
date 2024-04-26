#pragma once
#include <iostream>
using namespace std;

template <typename T>
int compara(T firstValue, T secondValue)
{
	if (firstValue < secondValue)
		return -1;
	else if (firstValue > secondValue)
		return 1;
	else
		return 0;
}

template <typename T>
int compara2(T firstValue, T secondValue)
{
	if (firstValue < secondValue)
		return -1;
	else if (firstValue > secondValue)
		return 1;
	else
		return 0;
}

template <typename T>


struct Node
{
	T value;
	Node** children;
	unsigned int nrChildren;

};

template <class T>
class Tree
{
	public:
		Node<T>* root;
		unsigned int maxNrChildrenPerNode;
	
		Tree(unsigned int nrChildren)
		{
			this->maxNrChildrenPerNode = nrChildren;
			root = nullptr;
		}
		void add_node(Node<T>* parent,T value)
		{
			if (parent == nullptr)
			{
				root = new Node<T>;
				root->value = value;
				root->nrChildren = 0;
				root->children = new Node<T> *[maxNrChildrenPerNode]; //se initializeaza automat cu nullptr
			}
			else
			{
				parent->children[parent->nrChildren] = new Node<T>;
				parent->children[parent->nrChildren]->value = value;
				parent->children[parent->nrChildren]->nrChildren = 0;
				parent->children[parent->nrChildren]->children = new Node<T> *[maxNrChildrenPerNode];
				parent->nrChildren++;
			}
		}
		void get_node(Node<T>* parent, int index)
		{
			if (index<0 || index> parent->nrChildren)
				return root->value;
			return parent->children[index]->value;
		}
		void delete_rec(Node<T>* parent)
		{
			for (int i = 0; i < parent->nrChildren; i++)
				delete_rec(parent->children[i]);
			delete parent;
		}
		void delete_node(Node<T>* parent)
		{
			delete_rec(parent);
		}
		T find_rec(Node<T>* parent, T value)
		{
			if (parent->value == value)
				return value;
			for (int i = 0; i < parent->nrChildren; i++)
			{
				T gasit = find_rec(parent->children[i], value);
				if (gasit != nullptr)
					return gasit;
			}
			return nullptr;
		}
		T find(T value)
		{
			return find_rec(root, value);
		}
	/*	void insert(Node<T>* parent, int index, T value)
		{
			parent->nrChildren++;
			for (int i = parent->nrChildren - 1; i > index; i--)
				parent->children[i] = parent->children[i - 1];
			parent->children[index]->value = value;
		}*/

		void insert(Node<T>* parent, int index, Node<T>* newNode)
		{
			parent->nrChildren++;
			for (int i = parent->nrChildren - 1; i > index; i--)
				parent->children[i] = parent->children[i - 1];
			parent->children[index] = newNode;
		}
		void printChildren(Node<T>* parent)
		{
			unsigned int i;	
			for (i = 0; i < parent->nrChildren; i++)
				cout << parent->children[i]->value;
		}

		void sort(Node<T>* parent,int (*compara)(T,T))
		{
			unsigned int i, j;
			for(i=0;i<parent->nrChildren-1;i++)
				for (j = i + 1; j < parent->nrChildren; j++)
				{
					if (compara(parent->children[i]->value, parent->children[j]->value) > 0)
					{
						T aux;
						aux = parent->children[i]->value;
						parent->children[i]->value = parent->children[j]->value;
						parent->children[j]->value = aux;
					}
				}
		}
		int count_rec(Node<T>* parent)
		{
			int cnt = 0;
			for (int i = 0; i < parent->nrChildren; i++)
				cnt = cnt + count_rec(parent->children[i]);
			return cnt + 1;
		}
		int count(Node<T>* parent)
		{
			return count_rec(parent);
		}
};

template <>
class Tree <char*>
{
	public:
		Node<char*>* root;
		unsigned int maxNrChildrenPerNode;

		Tree(unsigned int nrChildren)
		{
			this->maxNrChildrenPerNode = nrChildren;
			root = nullptr;
		}
		void add_node(Node<char*>* parent, char* value)
		{
			if (parent == nullptr)
			{
				root = new Node<char*>;
				root->value = new char[100];
				strcpy(root->value, value);
				root->nrChildren = 0;
				root->children = new Node<char*> *[maxNrChildrenPerNode]; //se initializeaza automat cu nullptr
			}
			else
			{
				parent->children[parent->nrChildren] = new Node<char*>;
				parent->children[parent->nrChildren]->value = value;
				parent->children[parent->nrChildren]->nrChildren = 0;
				parent->children[parent->nrChildren]->children = new Node<char*> *[maxNrChildrenPerNode];
				parent->nrChildren++;
			}
		}
		void printChildren(Node<char*>* parent)
		{
			unsigned int i;
			for (i = 0; i < parent->nrChildren; i++)
				cout << parent->children[i]->value;
		}

		void sort(Node<char*>* parent, int (*compara)(char*, char*))
		{
			unsigned int i, j;
			for (i = 0; i < parent->nrChildren - 1; i++)
				for (j = i + 1; j < parent->nrChildren; j++)
				{
					if (compara(parent->children[i]->value, parent->children[j]->value) > 0)
					{
						char* aux;
						aux = parent->children[i]->value;
						parent->children[i]->value = parent->children[j]->value;
						parent->children[j]->value = aux;
					}
				}
		}
};