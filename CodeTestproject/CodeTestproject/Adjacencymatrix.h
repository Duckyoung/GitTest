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
		os << "런던";
		break;

	case city::MOSCOW:
		os << "모스크바";
		break;

	case city::SEOUL:
		os << "서울";
		break;

	case city::SEATTLE:
		os << "시애틀";
		break;

	case city::DUBAL:
		os << "두바이";
		break;

	case city::SYDNEY:
		os << "시드니";
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

