#pragma once
#include <iostream>
#include <vector>

using namespace std;

class Bloomfilter
{
	vector<bool> data;
	int nBits;
	//해쉬 함수 
	int hash(int num, int key)
	{
		switch (num)
		{
		case 0: return key % nBits;
		case 1: return (key / 7 ) % nBits;
		case 2: return (key / 11) % nBits;
		default:
			break;
		}
		return 0;
	}
public:
	Bloomfilter(int n) : nBits(n)
	{
		data = vector<bool>(nBits, false);//1바이트 bool자료형
	}
	void lookup(int key)
	{
		bool result = data[hash(0, key)] & data[hash(1, key)] & data[hash(2, key)];
		if (result)
		{
			cout << key << ": 있을수 있음" << endl;
		}
		else
		{
			cout << key << ": 절대 없음" << endl;
		}
	}
	void insert(int key)
	{
		data[hash(0, key)] = true;
		data[hash(1, key)] = true;
		data[hash(2, key)] = true;

		cout << key << "을(를) 삽입: ";
		for (auto a : data)
		{
			cout << a << " ";
		}
		cout << endl;
	}
	void main()
	{
		Bloomfilter bf(7);
		bf.insert(100);
		bf.insert(54);
		bf.insert(82);

		bf.lookup(5);
		bf.lookup(50);
		bf.lookup(20);
		bf.lookup(54);
	}
};

