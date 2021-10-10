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
		//ó������ ���� ���ö� Ǫ��
		if (maxHeap.size() == 0)
		{
			maxHeap.push(data);
			return;
		}
		//�߾Ӱ��� ���� �߰��ϴ� �ִ� �ּ� ���� ��� �߰�
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
			//���� �ȵ�, �߾Ӱ� ���� ũ�� min���� max�� �ȱ��.
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
		cout << "�߾� �� : " << med.get() << endl;

		med.insert(5);
		cout << "�߾� �� : " << med.get() << endl;

		med.insert(2);
		cout << "�߾� �� : " << med.get() << endl;

		med.insert(10);
		cout << "�߾� �� : " << med.get() << endl;

		med.insert(40);
		cout << "�߾� �� : " << med.get() << endl;
	}
};
class Priority_queue
{
};

