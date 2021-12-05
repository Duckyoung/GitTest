#include <iostream>
#include <vector>
#include<list>
#include <algorithm>

using namespace std;
using uint = unsigned int;

#pragma once
class Hash_map
{
	
	vector<list<int>> data;

public:
	Hash_map(size_t n)
	{
		data.resize(n);
	}

	void insert(int value)
	{
		int n = data.size();
		data[value % n].push_back(value);
		cout << value << "��(��) ���� �߽��ϴ�." << endl;
	}

	bool find(int value)
	{
		int n = data.size();
		auto& entries = data[value % n];
		return std::find(entries.begin(), entries.end(), value) != entries.end();
	}

	void erase(int value)
	{
		int n = data.size();
		auto& entries = data[value % n];//����Ʈ �ε��� ����
		auto iter = std::find(entries.begin(), entries.end(), value); // ����Ʈ ���� �� ����

		if (iter != entries.end())//find �� ���� ���� �Ҷ� ����
		{
			entries.erase(iter);
			cout << value << "��(��) ���� �߽��ϴ�." << endl;
		}
	}
	void main()
	{
		Hash_map map(7);
		auto print = [&](int value)
		{
			if (map.find(value))
				cout << "�ؽ� �ʿ���" << value << "��(��) ã�ҽ��ϴ�.";
			else
				cout << "�ؽ� �ʿ���" << value << "��(��) ã�� �����ϴ�.";
			cout << endl;

		};
		map.insert(2);
		map.insert(25);
		map.insert(10);
		print(25);

		map.insert(100);
		print(100);
		print(2);

		map.erase(25);


	}
};

