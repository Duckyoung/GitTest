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
		cout << value << "을(를) 삽입 했습니다." << endl;
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
		auto& entries = data[value % n];//리스트 인덱스 참조
		auto iter = std::find(entries.begin(), entries.end(), value); // 리스트 실제 값 참조

		if (iter != entries.end())//find 후 값이 존재 할때 실행
		{
			entries.erase(iter);
			cout << value << "을(를) 삭제 했습니다." << endl;
		}
	}
	void main()
	{
		Hash_map map(7);
		auto print = [&](int value)
		{
			if (map.find(value))
				cout << "해시 맵에서" << value << "을(를) 찾았습니다.";
			else
				cout << "해시 맵에서" << value << "을(를) 찾지 못습니다.";
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

