#pragma once
#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>

using namespace std;

class Quicksort
{
	template<typename T>
	auto partition(typename vector<T>::iterator begin,
		typename vector<T>::iterator end)
	{
		//������ �ݺ��ڸ� ����
		//�ǹ�, ����, ��

		auto pivot_val = *begin;
		auto left_iter = begin + 1;
		auto right_iter = end;

		while (true)
		{
			//������ ù ��° ���Һ��� ���� �ؼ� �ǹ����� ū ���Ҹ� ã�´�.
			while (*left_iter <= pivot_val && distance(left_iter, right_iter) > 0)
				left_iter++;
			//������ ������ ���ҷ� ���� �����Ͽ� �������� �ǹ����� ���� ���Ҹ� ã���ϴ�.
			while (*right_iter > pivot_val && distance(left_iter, right_iter) > 0)
				right_iter--;

			//���� left_iter�� right_iter�� ���ٸ� ��ȯ�� ���Ұ� ������ �ǹ� �մϴ�.
			//�׷��� ������ left_iter �� right_iter�� ����Ű�� ���Ҹ� ���� ��ȯ �մϴ�.

			if (left_iter == right_iter)
				break;
			else
				iter_swap(left_iter, right_iter);
		}
		//���� ū ���� �ǹ� ������ �����Ǽ� �ڱ� ��ġ�� �°� ���� 
		if (pivot_val > *right_iter)
			iter_swap(begin, right_iter);

		return right_iter;
	}
	template<typename T>
	void quick_sort(typename vector<T>::iterator begin,
		typename vector<T>::iterator last)
	{
		//�Ѱ� �̻��� ���Ͱ� ��� ���� ���
		if (distance(begin, last) > 1)
		{
			//��Ȱ �۾�
			auto partition_iter = partition<T>(begin, last);
			//���� �۾��� ���� ������ ���͸� ��������� ����
			quick_sort<T>(begin, partition_iter - 1);
			quick_sort<T>(partition_iter, last);

		}
	}

	template<typename T>
	void print_vector(vector<T> arr)
	{
		for (auto i : arr)
			cout << i << " ";
		cout << endl;

	}

public:
	void run_quick_sort_test()
	{
		vector<int> S1{ 45,1,3,1,2,3,45,5,1,2,44,5,7 };
		vector<float> S2{ 45.6f, 1.0f, 3.8f, 1.01f, 2.2f, 3.9f, 45.3f, 5.5f,
		1.0f, 2.0f, 44.0f, 5.0f, 7.0f };
		vector<double> S3{ 45.6, 1.0, 3.8, 1.01, 2.2, 3.9, 45.3, 5.5, 1.0, 2.0, 44.0, 5.0, 7.0 };
		vector<char> C{ 'b', 'z', 'a', 'e', 'f', 't', 'q', 'u', 'y' };

		cout << "���� ���� ���� �Է� ����" << endl;
		print_vector<int>(S1);
		print_vector<float>(S2);
		print_vector<double>(S3);
		print_vector<char>(C);
		cout << endl;

		//end�� ���������� ������ ����Ű�� ������ -1 
		quick_sort<int>(S1.begin(), S1.end()-1);
		quick_sort<float>(S2.begin(), S2.end() - 1);
		quick_sort<double>(S3.begin(), S3.end() - 1);
		quick_sort<char>(C.begin(), C.end() - 1);


		cout << "���� ���Ŀ� ���� ���ĵ� ����" << endl;
		print_vector<int>(S1);
		print_vector<float>(S2);
		print_vector<double>(S3);
		print_vector<char>(C);
	}
	void run_partial_sort()
	{
		//ó���� 60
		vector<int> S1;
		S1.push_back(60);

		random_device rd;
		mt19937 rand(rd());
		int size = 100;
		//1, size ���� ���� �䤩��
		uniform_int_distribution<mt19937::result_type> unifrom_dist(1, size);

		//int �� ���� �߰�
		for (auto i = 0; i < size; i++)
		{	
			S1.push_back(unifrom_dist(rand));
		}
		print_vector(S1);

		chrono::steady_clock::time_point begin = chrono::steady_clock::now();
		//�κ� ���� ����
		chrono::steady_clock::time_point end = chrono::steady_clock::now();

		auto diff = chrono::duration_cast<chrono::microseconds>(end - begin);
		cout << "" << diff.count() << endl;
		
		//���� 100������ ������ ä���. �� 100��
		//�κ� ���� �Լ� ���� 
		//��ü ���Ŀ��� 10���θ� �ϴ°� �����Ѱ� üũ

	}
};


