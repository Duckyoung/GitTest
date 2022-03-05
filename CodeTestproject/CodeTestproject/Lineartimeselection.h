#pragma once
#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>
using namespace std;

class Lineartimeselection
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
		//�� �ǹ����� ū ������ �ݺ��ڸ� ã�Ƽ� �ٲ��ִ��� �߸𸣰ڴ�.
		//�ǽ� �Ǵ� �κ��� 
		if (pivot_val > *right_iter)
			iter_swap(begin, right_iter);

		return right_iter;
	}
	template<typename T>
	void quick_sort(typename vector<T>::iterator begin,
		typename vector<T>::iterator last)
	{
		//�Ѱ� �̻��� ���Ͱ� ��� ���� ���
		if (distance(begin, last) >= 1)
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

	//�� �ݺ��� ������ �߰� ���� ã�� �Լ�
	template<typename T>
	auto find_median(typename vector<T>::iterator begin,
		typename vector<T>::iterator last)
	{
		quick_sort<T>(begin, last);

		return begin + (distance(begin, last) / 2);
	}

	//���� �Լ� 
	template<typename T>
	auto partition_using_given_pivot(typename vector<T>::iterator begin,
		typename vector<T>::iterator end,
		typename vector<T>::iterator pivot)
	{
		//�ǹ� ��ġ�� �Լ� ���ڷ� ����
		//������ ���� �� ���� ����
		auto left_iter = begin;
		auto right_iter = end;
		while (true)
		{
			//left ���� �ǹ� ���� ū�� 
			while (*left_iter < *pivot && left_iter != right_iter)
				left_iter++;
			//right ���� �ǹ� ���� ���ų� ���� ��
			while (*right_iter >= *pivot && left_iter != right_iter)
				right_iter--;

			//���� ���Ҹ� break;
			if (left_iter == right_iter)
				break;
			else
				iter_swap(left_iter, right_iter);

		}
		//�ǹ��� ���� ū ���� �϶� ��
		if (*pivot > *right_iter)
			iter_swap(pivot, right_iter);

		return right_iter;
	}
	
	//���� �ð� �˻� �˰��� 
	template<typename T>
	typename vector<T>::iterator linear_time_select
	(typename vector<T>::iterator begin,
		typename vector<T>::iterator last,
		size_t i)
	{
		auto size = distance(begin, last);
		if (size > 0 && i < size)
		{
			//�ټ� �� ���ҷ� ���� �Ͽ� ���� �κ� ���� vi ���� ���
			auto num_Vi = (size + 4) / 5;
			size_t j = 0;
			//������ Vi �߾Ӱ��� ã�� ���� M �� ����
			vector<T> M;
			
			for (; j < size / 5; j++)
			{
				auto b = begin + (j * 5);//0,5,10
				auto l = begin + (j * 5) + 4;//5,10,15
				M.push_back(*find_median<T>(b, l));
			}

			if (j * 5 < size)
			{
				auto b = begin + (j * 5);
				auto l = begin + (j * 5) + (size %5);
				M.push_back(*find_median<T>(b, l));
			}

			//vi �� �߾Ӱ����� ������ ���� M���� �ٽ� �߾Ӱ� q�� ã��
			auto median_of_medians = (M.size() == 1) ? M.begin() :
				linear_time_select<T>(M.begin(), M.end() - 1, M.size() / 2);//size ���� 0�� ����

			//�ݺ��ڷ� ���;� �ϴµ� ����� ���ͼ� �����Ͽ� ������ �����.
			//
			//��Ȱ ������ ����, �ǹ� q�� ��ġ K�� ã��
			auto partition_iter = partition_using_given_pivot<T>(begin, last, median_of_medians);

			auto k = distance(begin, partition_iter);
			if (i == k)
				return partition_iter;
			else if (i < k)
				return linear_time_select<T>(begin, partition_iter - 1, i-1);
			else if (i > k)
				return linear_time_select<T>(partition_iter + 1, last, i - (k+1));//�̺κ� ���� �߻��ϳ�
		}
		else
		{
			return begin;
		}
	}
	template<typename T>
	vector<T> merge(vector<T>& arr1, vector<T>& arr2)
	{
		vector<T> merged;
		auto iter1 = arr1.begin();
		auto iter2 = arr2.begin();

		while (iter1 != arr1.end() && iter2 != arr2.end())
		{
			if (*iter1 < *iter2)
			{
				merged.emplace_back(*iter1);
				iter1++;
			}
			else
			{
				merged.emplace_back(*iter2);
				iter2++;
			}
		}

		if (iter1 != arr1.end())
		{
			for (; iter1 != arr1.end(); iter1++)
				merged.emplace_back(*iter1);
		}
		else
		{
			for (; iter2 != arr2.end(); iter2++)
				merged.emplace_back(*iter2);
		}
		return merged;
	}
	template<typename T>
	vector<T>merge_sort(vector<T> arr)
	{
		if (arr.size() > 1)
		{
			auto mid = size_t(arr.size()/2);
			auto left_half = merge_sort(vector<T>(arr.begin(), arr.begin() + mid));
			auto right_half = merge_sort(vector<T>(arr.begin() + mid, arr.end()));

			return merge<T>(left_half, right_half);

		}
		return arr;
	}
	public:
	void run_linear_select_test()
	{
		vector<int>S1{ 45,1, 3,1,2,3,45,5,1,2,44,5,7 };
		cout << "�Է� ����" << endl;
		print_vector<int>(S1);

		cout << "���ĵ� ����: " << endl;
		print_vector<int>(merge_sort<int>(S1));
		//�� 11��° ���� �ϰ� ���Ŀ��ٽ� ���� �ؼ� �����͸� ã���� �� ���������� ���� �Ѵ�.
		chrono::steady_clock::time_point begin = chrono::steady_clock::now();
		cout << "5��° ���� : " << *linear_time_select<int>(S1.begin(), S1.end() - 1, 4) << endl;
		//�κ� ���� ����
		chrono::steady_clock::time_point end = chrono::steady_clock::now();

		auto diff = chrono::duration_cast<chrono::microseconds>(end - begin);
		cout << "" << diff.count() << endl;

		int size = 100;
		random_device rd;
		mt19937 rand(rd());

		uniform_int_distribution<mt19937::result_type> unifrom_dist(1, size);
	
		////int �� ���� �߰�
		for (auto i = 0; i < size; i++)
		{
			S1.push_back(unifrom_dist(rand));
		}
		 begin = chrono::steady_clock::now();
		cout << "5��° ���� : " << *linear_time_select<int>(S1.begin(), S1.end() - 1, 4) << endl;
		//�κ� ���� ����
		 end = chrono::steady_clock::now();

		 diff = chrono::duration_cast<chrono::microseconds>(end - begin);
		cout << "" << diff.count() << endl;

		begin = chrono::steady_clock::now();
		cout << "11��° ���� : " << *linear_time_select<int>(S1.begin(), S1.end() - 1, 50) << endl;
		//�κ� ���� ����
		end = chrono::steady_clock::now();

		 diff = chrono::duration_cast<chrono::microseconds>(end - begin);
		cout << "" << diff.count() << endl;
	
		
		cout << "10��° ���� : " << *linear_time_select<int>(S1.begin(), S1.end() - 1, 10) << endl;

		cout << "test" << endl;
	}
};

