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
		//세개의 반복자를 생성
		//피벗, 시작, 끝

		auto pivot_val = *begin;
		auto left_iter = begin + 1;
		auto right_iter = end;

		while (true)
		{
			//벡터의 첫 번째 원소부터 시작 해서 피벗보도 큰 원소를 찾는다.
			while (*left_iter <= pivot_val && distance(left_iter, right_iter) > 0)
				left_iter++;
			//벡터의 마지막 원소로 부터 시작하여 역순으로 피벗보다 작은 원소를 찾습니다.
			while (*right_iter > pivot_val && distance(left_iter, right_iter) > 0)
				right_iter--;

			//만약 left_iter와 right_iter가 같다면 교환할 원소가 없음을 의미 합니다.
			//그렇지 않으면 left_iter 와 right_iter가 가르키는 원소를 서로 교환 합니다.

			if (left_iter == right_iter)
				break;
			else
				iter_swap(left_iter, right_iter);
		}
		//가장 큰 값이 피벗 값으로 지정되서 자기 위치에 맞게 스왑 
		if (pivot_val > *right_iter)
			iter_swap(begin, right_iter);

		return right_iter;
	}
	template<typename T>
	void quick_sort(typename vector<T>::iterator begin,
		typename vector<T>::iterator last)
	{
		//한개 이상의 벡터가 들어 있을 경우
		if (distance(begin, last) > 1)
		{
			//분활 작업
			auto partition_iter = partition<T>(begin, last);
			//분할 작업에 의해 생성된 벡터를 재귀적으로 정렬
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

		cout << "정렬 되지 않은 입력 벡터" << endl;
		print_vector<int>(S1);
		print_vector<float>(S2);
		print_vector<double>(S3);
		print_vector<char>(C);
		cout << endl;

		//end는 마지막원소 다음을 가르키기 때문에 -1 
		quick_sort<int>(S1.begin(), S1.end()-1);
		quick_sort<float>(S2.begin(), S2.end() - 1);
		quick_sort<double>(S3.begin(), S3.end() - 1);
		quick_sort<char>(C.begin(), C.end() - 1);


		cout << "병렬 정렬에 의해 정렬된 벡터" << endl;
		print_vector<int>(S1);
		print_vector<float>(S2);
		print_vector<double>(S3);
		print_vector<char>(C);
	}
	void run_partial_sort()
	{
		//처음은 60
		vector<int> S1;
		S1.push_back(60);

		random_device rd;
		mt19937 rand(rd());
		int size = 100;
		//1, size 정수 난수 밥ㄹ생
		uniform_int_distribution<mt19937::result_type> unifrom_dist(1, size);

		//int 형 난수 추가
		for (auto i = 0; i < size; i++)
		{	
			S1.push_back(unifrom_dist(rand));
		}
		print_vector(S1);

		chrono::steady_clock::time_point begin = chrono::steady_clock::now();
		//부분 정렬 실행
		chrono::steady_clock::time_point end = chrono::steady_clock::now();

		auto diff = chrono::duration_cast<chrono::microseconds>(end - begin);
		cout << "" << diff.count() << endl;
		
		//그후 100이하의 난수로 채운다. 총 100개
		//부분 정렬 함수 생성 
		//전체 정렬에서 10프로만 하는게 가능한가 체크

	}
};


