#pragma once
#include <iostream>
#include <vector>

using namespace std;

class CuckooHash_map
{
	vector<int> data1;
	vector<int> data2;
	int size;

	int hash1(int key) const
	{
		return key % size;
	}
	int hash2(int key)const
	{
		return (key / size) % size;
	}

public:
	CuckooHash_map(int n) :size(n)
	{
		data1 = vector<int>(size, -1);
		data2 = vector<int>(size, -1);
	}

	vector<int>::iterator lookup(int key)
	{
		int hash_value1 = hash1(key);
		if (data1[hash_value1] == key)
		{
			cout << "1�� ���̺�����" << key << "��(��) ã�ҽ��ϴ�." << endl;
			return data1.begin() + hash_value1;
		}
		int hash_value2 = hash2(key);
		if (data2[hash_value2] == key)
		{
			cout << "2�� ���̺�����" << key << "��(��) ã�ҽ��ϴ�." << endl;
			return data2.begin() + hash_value1;
		}

		return data2.end();
	}
	void erase(int key)
	{
		auto position = lookup(key);
		if (position != data2.end())
		{
			*position = -1;
			cout << key << "�� �ش��ϴ� ���Ҹ� ���� �߽��ϴ�." << endl;
		}
		else
		{
			cout << key << "Ű�� ã�� ���߽��ϴ�." << endl;
		}
	}
	void insert(int key)
	{
		insert_impl(key, 0, 1);
	}
	void insert_impl(int key, int cnt, int table)
	{
		if (cnt >= size)
		{
			cout << key << "���� �� ��ȯ �߻�! ���ؽ��� �ʿ� �մϴ�." << endl;
			return;
		}
		if (table == 1)
		{
			int hash = hash1(key);
			if (data1[hash] == -1)
			{
				cout << table << "�� ���̺��� " << key << "����" << endl;
				data1[hash] = key;
			}
			else
			{
				int old = data1[hash];
				data1[hash] = key;
				cout << table << "�� ���̺���" << key << "����: ������" << old << "�̵� ->" << endl;
				insert_impl(old, cnt + 1, 2);

			}
		}
		else
		{
			int hash = hash2(key);
			if (data2[hash] == -1)
			{
				cout << table << "�� ���̺��� " << key << "����" << endl;
				data2[hash] = key;
			}
			else
			{
				int old = data2[hash];
				data2[hash] = key;
				cout << table << "�� ���̺���" << key << "����: ������" << old << "�̵� ->" << endl;
				insert_impl(old, cnt + 1, 1);
			}
		}
	}
	void print()
	{
		cout << "Index: ";
		for (int i = 0; i < size; i++)
			cout << i << '\t';	
		cout << endl;

		cout << "Data1: ";
		for (auto i : data1)
			cout << i << '\t';
		cout << endl;

		cout << "Data2: ";
		for (auto i : data2)
			cout << i << '\t';
		cout << endl;
	}
	void main()
	{
		CuckooHash_map map(7);
		map.print();
		cout << endl;

		map.insert(10);
		map.insert(20);
		map.insert(30);
		cout << endl;

		map.insert(104);
		map.insert(2);
		map.insert(70);
		map.insert(9);
		map.insert(90);
		map.insert(2);
		map.insert(7);
		cout << endl;

		map.print();
		cout << endl;

		map.insert(14); // ��ȯ �߻�!
	}
};
