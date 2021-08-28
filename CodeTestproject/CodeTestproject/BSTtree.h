#pragma once
#include <iostream>

using namespace std;

struct bstnode
{
	int data;
	bstnode* left;
	bstnode* right;
};

struct BST
{
	bstnode* root = nullptr;

	bstnode* find(int value)
	{
		return find_impl(root, value);
	}

private:
	bstnode* find_impl(bstnode* current, int value)
	{
		if (!current)
		{
			cout << endl;
			return NULL;
		}
		if (current->data == value)
		{
			cout << value << "��(��) ã�ҽ��ϴ�." << endl;
			return current;
		}

		if (value < current->data)
		{
			//go left
			cout << current->data << "���� �������� �̵�" << endl;
			return find_impl(current->left, value);
		}
		if (value > current->data)
		{
			
			cout << current->data << "���� ���������� �̵�" << endl;
			return find_impl(current->right, value);
		}
		

	}

public :
	void insert(int value)
	{
		if (!root)
			root = new bstnode{ value, NULL, NULL };
		else
			insert_impl(root, value);
	}
private :
	void insert_impl(bstnode* current, int value)
	{
		if (value < current->data)
		{
			if (!current->left)
				current->left = new bstnode{ value, NULL, NULL };
			else
				insert_impl(current->left, value);
		}
		else
		{
			if (!current->right)
				current->right = new bstnode{ value, NULL, NULL };
			else 
				insert_impl(current->right, value);
		}
	}
public:
	void inorder()
	{
		inorder_impl(root);
	}
private:
	void inorder_impl(bstnode* start)
	{
		if (!start)
			return;

	}
};

class BSTtree
{
};

