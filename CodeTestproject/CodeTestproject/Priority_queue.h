#pragma once
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct median
{
	std::priority_queue<int> maxHeap;
	std::priority_queue<int, std::vector<int>, std::greater<int>> minheap;
	
	void insert(int data)
	{
		//처음으로 값이 들어올때 푸시
		if (maxHeap.size() == 0)
		{
			maxHeap.push(data);
			return;
		}
		//중앙값을 보고 추가하는 최대 최소 힙에 노드 추가
		if (maxHeap.size() == minheap.size())
		{
			if (data <= get())
				maxHeap.push(data);
			else
				minheap.push(data);

			return;
		}
		if (maxHeap.size() < minheap.size())
		{
			//이해 안됨, 중앙값 보다 크면 min값을 max로 옴긴다.
			if (data > get())
			{
				maxHeap.push(minheap.top());
				minheap.pop();
				minheap.push(data);
			}
			else
				maxHeap.push(data);

			return;
		}
		if (data < get())
		{
			minheap.push(maxHeap.top());
			maxHeap.pop();
			maxHeap.push(data);
		}
		else
			minheap.push(data);
	}
	double get()
	{
		if (maxHeap.size() == minheap.size())
		{
			return (maxHeap.top() + minheap.top()) / 2.0;
		}
		if (maxHeap.size() < minheap.size())
			return minheap.top();

		return maxHeap.top();
	}
	void Main()
	{
		median med;
		med.insert(1);
		cout << "중앙 값 : " << med.get() << endl;

		med.insert(5);
		cout << "중앙 값 : " << med.get() << endl;

		med.insert(2);
		cout << "중앙 값 : " << med.get() << endl;

		med.insert(10);
		cout << "중앙 값 : " << med.get() << endl;

		med.insert(40);
		cout << "중앙 값 : " << med.get() << endl;
	}
};
class Priority_queue
{
};

