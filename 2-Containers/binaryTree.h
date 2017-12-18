#pragma once
#include "tvector.h"
#include "intvector.h"


struct node
{
	int key_value;
	node *left;
	node *right;
};


template <typename T>
class btree
{
public:
	btree()
	{
		root = NULL;
	}

	~btree()
	{
		destroyTree();
	}

	void insert(T key)
	{
		if (root != NULL)
		{
			insert(key, root);
		}
		else
		{
			root = new node;
			root->key_value = key;
			root->left = NULL;
			root->right = NULL;
		}
	}

	node *search(T key)
	{
		return search(key, root);
	}

	void destroyTree()
	{
		destroyTree(root);
	}

private:
	void destroyTree(node * leaf)
	{
		if (leaf != NULL)
		{
			destroyTree(leaf->left);
			destroyTree(leaf->right);
			delete leaf;
		}
	}

	void insert(T key, node *leaf)
	{
		if (key < leaf->key_value)
		{
			if (leaf->left != NULL)
			{
				insert(key, leaf->left);
			}
			else
			{
				leaf->left = new node;
				leaf->left->key_value = key;
				leaf->left->left = NULL; // sets the left child node to Null
				leaf->left->right = NULL;// sets the right child node to Null
			}
		}
		else if (key >= leaf->key_value)
		{
			if (leaf->right != NULL)
			{
				insert(key, leaf->right);
			}
			else
			{
				leaf->right = new node;
				leaf->right->key_value = key;
				leaf->right->left = NULL;  // sets left child node to NULL
				leaf->right->right = NULL; // sets right child nod to NULL
			}
		}
	}

	node *search(T key, node *leaf)
	{
		if (leaf != NULL)
		{
			if (key == leaf->key_value)
			{
				return leaf;
			}
			if (key < leaf->key_value)
			{
				return search(key, leaf->left);
			}
			else
			{
				return search(key, leaf->right);
			}
		}
		else
		{
			return NULL;
		}
	}

	node *root;
};