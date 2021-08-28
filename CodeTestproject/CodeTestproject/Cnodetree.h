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
		//재귀 함수 사용 왼쪽 노드 참조
		auto first = org_tree::find(root->first, value);
		if (first != nullptr)
			return first;
		//재귀함수 오른쪽 노드 참조
		return org_tree::find(root->second, value);
	}
	bool addSubordinate(const string & manager, const string & subordinate)
	{
		auto managerNode = org_tree::find(root, manager);
		if (!managerNode)//실행이 되나 모르겠음, 리턴 형태가 주소값임
		{
			cout << manager << endl;
			return false;
		}
		if (managerNode->first && managerNode->second)
		{
			cout << manager << "아래에" << subordinate << "을 추가할수 없습니다." << endl;
			return false;
		}
		if (!managerNode->first)
			managerNode->first = new node{ subordinate , NULL, NULL};
		else
			managerNode->second = new node{ subordinate , NULL, NULL };
		cout << manager << "아래에" << subordinate << "추가했습니다." << endl;
		return true;
	}
	static void maintest()
	{
		auto tree = org_tree::create_org_structure("CEO");
		tree.addSubordinate("CEO", "부사장");
		tree.addSubordinate("부사장", "IT부장");
		tree.addSubordinate("부사장", "마케팅부장");
		tree.addSubordinate("IT부장", "보안팀장");
		tree.addSubordinate("IT부장", "앱개발팀장");
		tree.addSubordinate("마케팅부장", "물류팀장");
		tree.addSubordinate("마케팅부장", "홍보팀장");
		tree.addSubordinate("부사장", "재무부장");

		cout << "nodetree 테스트" << endl;
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
//정적 함수로 생성자를 호출 시킨다.

class Cnodetree
{
};

