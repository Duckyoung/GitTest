#pragma once
#include <iostream>
#include <vector>

using namespace std;

enum class city :int
{
	MOSCOW,
	LONDON,
	SEOUL,
	SEATTLE,
	DUBAL,
	SYDNEY
};

ostream& operator<< (ostream& os, const city c)
{
	switch (C)
	{
	case city::LONDON:
		os << "����";
		break;

	case city::MOSCOW:
		os << "��ũ��";
		break;

	case city::SEOUL:
		os << "����";
		break;

	case city::SEATTLE:
		os << "�þ�Ʋ";
		break;

	case city::DUBAL:
		os << "�ι���";
		break;

	case city::SYDNEY:
		os << "�õ��";
		break;

	default:
		return os;
	}
}
struct graph
{
	vector<vector<int>> data;
	graph(int n)
	{
		data.reserve(n);
		vector<int> row(n);
		fill(row.begin(), row.end(), -1);

		for (int i = 0; i < n; i++)
		{
			data.push_back(row);
		}
	}
};

