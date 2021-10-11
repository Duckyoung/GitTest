#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

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
	switch (c)
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
		//메모리 n 개의 할당를 한다, 배열의 사이즈를 미리 지정 해줌으로서 
		//push_back 할 떄 마다 메모리 연산하는 부분을 하지 않는다. 
		vector<int> row(n);
		fill(row.begin(), row.end(), -1);

		for (int i = 0; i < n; i++)
		{
			data.push_back(row);
		}
	}
	void addEdge(const city c1, const city c2, int dis)
	{
		cout << "에지 추가: " << c1 << "-" << c2 << "=" << dis << endl;
		auto n1 = static_cast<int>(c1);
		auto n2 = static_cast<int>(c2);
		data[n1][n2] = dis;
		data[n2][n1] = dis;
	}
	void removeEdage(const city c1, const city c2)
	{
		cout << "에지 삭제: " << c1 << "-" << c2 << endl;
		auto n1 = static_cast<int>(c1);
		auto n2 = static_cast<int>(c2);
		data[n1][n2] = -1;
		data[n2][n1] = -1;
	}
	void main()
	{
		graph g(6);
		g.addEdge(city::LONDON, city::MOSCOW, 2500);
		g.addEdge(city::LONDON, city::SEOUL, 9000);
		g.addEdge(city::LONDON, city::DUBAL, 5500);
		g.addEdge(city::SEOUL, city::MOSCOW, 6600);
		g.addEdge(city::SEOUL, city::SEATTLE, 8000);

		g.addEdge(city::SEOUL, city::DUBAL, 7000);
		g.addEdge(city::SEOUL, city::SYDNEY, 8000);

		g.addEdge(city::SEATTLE, city::MOSCOW, 8400);
		g.addEdge(city::SEATTLE, city::SYDNEY, 12000);
		g.addEdge(city::DUBAL, city::SYDNEY, 1200);

		g.addEdge(city::SEATTLE, city::LONDON, 8000);
		g.removeEdage(city::SEATTLE, city::LONDON);
			
	}
};

struct graph_list
{
	vector<vector<pair<int, int>>> data;
	graph_list(int n)
	{
		data = vector<vector<pair<int, int >>>(n, vector<pair<int, int>>());
	}
	void addEdge(const city c1, const city c2, int dis)
	{
		cout << "에지 추가: " << c1 << "-" << c2 << "=" << dis << endl;
		auto n1 = static_cast<int>(c1);
		auto n2 = static_cast<int>(c2);
		data[n1].push_back({n2, dis});
		data[n2].push_back({n1, dis});
	}
	void removeEdage(const city c1, const city c2)
	{
		cout << "에지 삭제: " << c1 << "-" << c2 << endl;
		auto n1 = static_cast<int>(c1);
		auto n2 = static_cast<int>(c2);
		remove_if(data[n1].begin(), data[n1].end(), [n2](const auto& pair) { return pair.first == n2; });
		remove_if(data[n2].begin(), data[n2].end(), [n1](const auto& pair) { return pair.first == n1; });

	}
	void main()
	{
		graph_list g(6);
		g.addEdge(city::LONDON, city::MOSCOW, 2500);
		g.addEdge(city::LONDON, city::SEOUL, 9000);
		g.addEdge(city::LONDON, city::DUBAL, 5500);
		g.addEdge(city::SEOUL, city::MOSCOW, 6600);
		g.addEdge(city::SEOUL, city::SEATTLE, 8000);

		g.addEdge(city::SEOUL, city::DUBAL, 7000);
		g.addEdge(city::SEOUL, city::SYDNEY, 8000);

		g.addEdge(city::SEATTLE, city::MOSCOW, 8400);
		g.addEdge(city::SEATTLE, city::SYDNEY, 12000);
		g.addEdge(city::DUBAL, city::SYDNEY, 1200);

		g.addEdge(city::SEATTLE, city::LONDON, 8000);
		g.removeEdage(city::SEATTLE, city::LONDON);

	}
};

