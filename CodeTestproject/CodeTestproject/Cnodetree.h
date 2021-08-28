#pragma once
#include <iostream>
#include <queue>

using namespace std;

struct node
{
	string posision;
	node* first;
	node* second;

};

struct org_tree
{
	node* root;
	static org_tree create_org_structure(const string& pos)
	{
		org_tree tree;
		tree.root = new node{ pos, NULL, NULL };
		return tree;
	}
	static node* find(node* root, const string& value)
	{
		if (root == nullptr)
			return NULL;

		if (root->posision == value)
			return root;
		//��� �Լ� ��� ���� ��� ����
		auto first = org_tree::find(root->first, value);
		if (first != nullptr)
			return first;
		//����Լ� ������ ��� ����
		return org_tree::find(root->second, value);
	}
	bool addSubordinate(const string & manager, const string & subordinate)
	{
		auto managerNode = org_tree::find(root, manager);
		if (!managerNode)//������ �ǳ� �𸣰���, ���� ���°� �ּҰ���
		{
			cout << manager << endl;
			return false;
		}
		if (managerNode->first && managerNode->second)
		{
			cout << manager << "�Ʒ���" << subordinate << "�� �߰��Ҽ� �����ϴ�." << endl;
			return false;
		}
		if (!managerNode->first)
			managerNode->first = new node{ subordinate , NULL, NULL};
		else
			managerNode->second = new node{ subordinate , NULL, NULL };
		cout << manager << "�Ʒ���" << subordinate << "�߰��߽��ϴ�." << endl;
		return true;
	}
	static void maintest()
	{
		auto tree = org_tree::create_org_structure("CEO");
		tree.addSubordinate("CEO", "�λ���");
		tree.addSubordinate("�λ���", "IT����");
		tree.addSubordinate("�λ���", "�����ú���");
		tree.addSubordinate("IT����", "��������");
		tree.addSubordinate("IT����", "�۰�������");
		tree.addSubordinate("�����ú���", "��������");
		tree.addSubordinate("�����ú���", "ȫ������");
		tree.addSubordinate("�λ���", "�繫����");

		cout << "nodetree �׽�Ʈ" << endl;
		preorder(tree.root);
		inorder(tree.root);
		posorder(tree.root);
		levelOrder(tree.root);


	}
	static void preorder(node* start)
	{
		if (!start)
			return;

		cout << start->posision << ",";
		preorder(start->first);
		preorder(start->second);
	}
	static void inorder(node* start)
	{
		if (!start)
			return;

		preorder(start->first);
		cout << start->posision << ",";
		preorder(start->second);
	}

	static void posorder(node* start)
	{
		if (!start)
			return;

		preorder(start->first);
		preorder(start->second);
		cout << start->posision << ",";
		
	}
	static void levelOrder(node* start)
	{
		if (!start)
			return;
		queue<node*> q;
		q.push(start);

		while (!q.empty())
		{
			int size = q.size();
			for (int i = 0; i < size; i++)
			{
				auto current = q.front();
				q.pop();
				cout << current->posision << endl;
				if (current->first)
					q.push(current->first);
				if (current->second)
					q.push(current->second);
			}
			cout << endl;
		}
	}
};
//���� �Լ��� �����ڸ� ȣ�� ��Ų��.

class Cnodetree
{
};

